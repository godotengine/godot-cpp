import copy
import json
import re
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

import binding_generator
from make_interface_header import generate_gdextension_interface_header
from header_documentation import (
    ClassHeaderDocumentation,
    ReferenceDocumentation,
    get_header_documentation_paths,
    load_class_reference,
)

ROOT = Path(__file__).resolve().parents[1]
DOXYGEN_BLOCK = re.compile(r"^[\t ]*/\*\*\n.*?^[\t ]* \*/\n", re.MULTILINE | re.DOTALL)
DECLARATIONS = {
    "class Mesh;",
    "class Texture2D;",
    "class MeshInstance2D : public Node2D {",
    "GDEXTENSION_CLASS(MeshInstance2D, Node2D)",
    "void set_mesh(const Ref<Mesh> &p_mesh);",
    "Ref<Mesh> get_mesh() const;",
    "void set_texture(const Ref<Texture2D> &p_texture);",
    "Ref<Texture2D> get_texture() const;",
    "template <typename T, typename B>",
}


class HeaderDocumentationTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        api_path = ROOT / "gdextension" / "extension_api-4-7.json"
        api = json.loads(api_path.read_text(encoding="utf-8"))
        cls.api_header = api["header"]
        cls.class_api = next(item for item in api["classes"] if item["name"] == "MeshInstance2D")
        cls.path = get_header_documentation_paths(cls.api_header)["MeshInstance2D"]
        cls.engine_classes = {item["name"]: item["is_refcounted"] for item in api["classes"]}
        cls.convex_api = next(item for item in api["classes"] if item["name"] == "MeshConvexDecompositionSettings")

    def generate_header(self, path=None, class_api=None):
        class_api = self.class_api if class_api is None else class_api
        documentation = ClassHeaderDocumentation(path, class_api) if path is not None else None
        with patch.dict(binding_generator.engine_classes, self.engine_classes, clear=True):
            return binding_generator.generate_engine_class_header(
                class_api, ["Mesh", "Texture2D"], ["Node2D", "Ref"], False, None, documentation
            )

    def test_coverage_and_reproducibility(self):
        header = self.generate_header(self.path)
        blocks = list(DOXYGEN_BLOCK.finditer(header))
        self.assertEqual(len(blocks), len(DECLARATIONS))
        self.assertEqual({header[block.end() :].splitlines()[0].strip() for block in blocks}, DECLARATIONS)
        for block in blocks:
            self.assertEqual(re.findall(r"^[\t ]* \* (```cpp|```)$", block[0], re.MULTILINE), ["```cpp", "```"])
            for tag in ("@brief", "@code", "@endcode", "@tparam"):
                self.assertNotIn(tag, block[0])
        self.assertEqual(DOXYGEN_BLOCK.sub("", header), self.generate_header())
        self.assertEqual(self.generate_header(self.path), header)

    def test_other_versions_do_not_reuse_documentation(self):
        for version in ({"version_minor": 6}, {"version_patch": 1}, {"version_status": "beta"}):
            header = {**self.api_header, **version}
            self.assertNotIn("MeshInstance2D", get_header_documentation_paths(header))
            self.assertEqual(load_class_reference(header), {})

    def test_reference_selection(self):
        reference = load_class_reference(self.api_header)
        self.assertEqual(reference["MeshInstance2D"].get("inherits"), "Node2D")
        docs = ReferenceDocumentation(reference, "MeshInstance2D", "Node2D")
        getter = next(method for method in self.class_api["methods"] if method["name"] == "get_texture")
        self.assertIn("`texture` property", docs.method(getter))
        self.assertEqual(docs.method({**getter, "return_value": {"type": "Mesh"}}), "")
        setter = next(method for method in self.class_api["methods"] if method["name"] == "set_texture")
        self.assertIn("- `p_texture` — New value for the `texture` property.", binding_generator.describe_method(docs, setter))
        self.assertEqual(docs.method_parameters({**setter, "arguments": [{"name": "texture", "type": "String"}]}), ())
        self.assertEqual(ReferenceDocumentation(reference, "MeshInstance2D", "Node3D").type_description(), "")

    def test_reviewed_accessors_override_only_matching_declarations(self):
        reference = load_class_reference(self.api_header)
        path = get_header_documentation_paths(self.api_header)["MeshConvexDecompositionSettings"]
        documentation = ClassHeaderDocumentation(path, self.convex_api, reference)
        with patch.dict(binding_generator.engine_classes, self.engine_classes, clear=True):
            header = binding_generator.generate_engine_class_header(
                self.convex_api, [], ["Resource"], False, None, documentation, reference
            )
            baseline = binding_generator.generate_engine_class_header(
                self.convex_api, [], ["Resource"], False, None, reference=reference
            )
        self.assertIn("vertex limit that V-HACD uses", header)
        self.assertNotIn("maximum number of triangles", header)
        self.assertIn("p_plane_downsampling` — Step between sampled planes.", header)
        self.assertIn("Returns the voxelization resolution passed to V-HACD.", header)
        self.assertIn("threshold, from `0.001` to `1.0`", header)
        blocks = list(DOXYGEN_BLOCK.finditer(header))
        self.assertEqual(len(blocks), 33)
        for block in blocks:
            self.assertEqual(block[0].count("**Used for** "), 1)
        self.assertEqual(
            len(re.findall(r"^\s*\* - `p_\w+` — ", header, re.MULTILINE)), 13
        )
        self.assertEqual(DOXYGEN_BLOCK.sub("", header), DOXYGEN_BLOCK.sub("", baseline))
        with self.assertRaisesRegex(ValueError, "reviewed declarations absent"):
            ClassHeaderDocumentation(path, self.convex_api, reference).check_matches()

    def test_generated_file_list_has_no_documentation_dependency(self):
        api = ROOT / "gdextension" / "extension_api-4-7.json"
        paths = binding_generator.get_file_list(api, ".", headers=True)
        self.assertIn("gen/include/godot_cpp/classes/mesh_instance2d.hpp", paths)
        self.assertIn("gen/include/godot_cpp/classes/glyph.hpp", paths)

    def test_generated_virtual_macros_document_the_exact_macro_parameters(self):
        for generate in (binding_generator.generate_mod_version, binding_generator.generate_virtual_version):
            for count in (0, 1, 12):
                for returns in (False, True):
                    with self.subTest(generator=generate.__name__, count=count, returns=returns):
                        options = {"const": True, "returns": returns}
                        if generate is binding_generator.generate_virtual_version:
                            options["required"] = True
                        header = generate(count, **options, documented=True)
                        comment = DOXYGEN_BLOCK.search(header)
                        self.assertIsNotNone(comment)
                        self.assertEqual(DOXYGEN_BLOCK.sub("", header), generate(count, **options))
                        self.assertEqual(comment[0].count("**Used for**"), 1)
                        names = re.findall(r"^ \* - `(\w+)`", comment[0], re.MULTILINE)
                        expected = ["m_ret"] if returns else []
                        expected += ["m_name", *(f"m_type{i}" for i in range(1, count + 1))]
                        self.assertEqual(names, expected)

    def test_reviewed_utility_vararg_comment_attaches_to_public_template(self):
        api = json.loads((ROOT / "gdextension" / "extension_api-4-7.json").read_text(encoding="utf-8"))
        api["utility_functions"] = [entry for entry in api["utility_functions"] if entry["name"] == "print"]
        reference = load_class_reference(api["header"])
        with tempfile.TemporaryDirectory() as directory:
            output = Path(directory)
            notes = output / "@GlobalScope.json"
            notes.write_text(
                json.dumps({
                    "partial": True,
                    "declarations": {
                        "vararg:static void print_internal(const Variant **p_args, GDExtensionInt p_arg_count);": {
                            "xml": "methods/method[@name='print']",
                            "brief": "Verified public template description.",
                        },
                    },
                }),
                encoding="utf-8",
            )
            binding_generator.generate_utility_functions(api, output, reference=reference, documentation_path=notes)
            header_path = output / "include/godot_cpp/variant/utility_functions.hpp"
            documented = header_path.read_text(encoding="utf-8")
            binding_generator.generate_utility_functions(api, output)
            plain = header_path.read_text(encoding="utf-8")

        self.assertEqual(DOXYGEN_BLOCK.sub("", documented), plain)
        self.assertRegex(documented, r"Verified public template description\.\n\t \*/\n\ttemplate <typename\.\.\. Args>")
        self.assertRegex(documented, r"`p_arg_count`[^\n]*\n\t \*/\n\tstatic void print_internal\(")

    def test_interface_header_uses_markdown_without_class_reference(self):
        with tempfile.TemporaryDirectory() as directory:
            header_path = Path(directory) / "gdextension_interface.h"
            generate_gdextension_interface_header(header_path, str(ROOT / "gdextension" / "gdextension_interface.json"))
            header = header_path.read_text(encoding="utf-8")
        self.assertIn("- `r_dest`:", header)
        self.assertNotRegex(header, r"(?m)^\s*\*\s+@\w+")

    def test_prose_and_markup(self):
        docs = ReferenceDocumentation(load_class_reference(self.api_header), "String")
        description = docs._text(
            "[b]Note:[/b] [code]values[0][/code] differs from [method length].\n\n"
            "Prints:\n[codeblocks][gdscript]print('script example')[/gdscript][/codeblocks]"
        )
        self.assertIn("**Note:** `values[0]`", description)
        self.assertIn("`godot::String::length()`", description)
        self.assertNotIn("script example", description)
        self.assertNotIn("Prints:", description)
        self.assertEqual(docs._text("Backtick ([code]`[/code]) key."), "Backtick (`` ` ``) key.")

    def test_explicit_parameter_requires_matching_signature(self):
        api = json.loads((ROOT / "gdextension" / "extension_api-4-7.json").read_text(encoding="utf-8"))
        node_api = next(item for item in api["classes"] if item["name"] == "Node")
        docs = ReferenceDocumentation(load_class_reference(self.api_header), "Node", "Object")
        method = next(method for method in node_api["methods"] if method["name"] == "_process")
        self.assertIn(
            "- `p_delta` — The time between frames in seconds.",
            binding_generator.describe_method(docs, method),
        )
        self.assertEqual(docs.method_parameters({**method, "arguments": [{"name": "delta", "type": "int"}]}), ())

    def test_changed_declaration_requires_review(self):
        class_api = copy.deepcopy(self.class_api)
        getter = next(method for method in class_api["methods"] if method["name"] == "get_texture")
        getter["is_const"] = False
        with self.assertRaisesRegex(ValueError, r"get_texture.*missing reviewed header documentation"):
            self.generate_header(self.path, class_api)

    def test_missing_input_is_reported(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / self.path.name
            with self.assertRaisesRegex(ValueError, r"MeshInstance2D\.json: unable to load"):
                self.generate_header(path)
            data = json.loads(self.path.read_text(encoding="utf-8"))
            entry = data["declarations"]["Ref<Mesh> get_mesh() const;"]
            path.write_text(json.dumps(data), encoding="utf-8")
            with self.assertRaisesRegex(ValueError, r"MeshInstance2D\.xml: unable to load"):
                self.generate_header(path)
            path.with_suffix(".xml").write_bytes(self.path.with_suffix(".xml").read_bytes())

            entry["xml"] = "members/member[@getter='get_texture']"
            path.write_text(json.dumps(data), encoding="utf-8")
            with self.assertRaisesRegex(ValueError, r"Godot XML does not describe 'get_mesh'"):
                self.generate_header(path)

            entry["xml"] = "members/member[@getter='get_mesh']"
            entry["example"] = []
            path.write_text(json.dumps(data), encoding="utf-8")
            header = self.generate_header(path)
            getter = next(block[0] for block in DOXYGEN_BLOCK.finditer(header) if header[block.end() :].startswith("\tRef<Mesh> get_mesh() const;"))
            self.assertIn("Returns the assigned", getter)
            self.assertNotIn("```cpp", getter)


if __name__ == "__main__":
    unittest.main()
