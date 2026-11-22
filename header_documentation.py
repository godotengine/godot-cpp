import json
import re
import textwrap
import xml.etree.ElementTree as ET
from pathlib import Path
from zipfile import ZipFile

HEADER_DOCUMENTATION_DIR = Path(__file__).resolve().parent / "gdextension" / "header_docs"


def get_header_documentation_directory(api_header):
    version = ".".join(str(api_header[f"version_{part}"]) for part in ("major", "minor", "patch"))
    if api_header["version_status"] != "stable":
        version += f"-{api_header['version_status']}"
    return HEADER_DOCUMENTATION_DIR / version


def get_header_documentation_paths(api_header):
    """Find reviewed inputs for the exact API version selected by the binding generator."""
    directory = get_header_documentation_directory(api_header)
    names = {
        path.stem
        for path in directory.glob("*")
        if path.suffix in (".json", ".xml") and path.stem != "native_structures"
    }
    return {name: directory / f"{name}.json" for name in sorted(names)}


def load_class_reference(api_header):
    """Read the locally saved upstream XML for this API version."""
    path = get_header_documentation_directory(api_header) / "class_reference.zip"
    if not path.is_file():
        return {}
    with ZipFile(path) as archive:
        return {Path(name).stem: ET.fromstring(archive.read(name)) for name in archive.namelist() if name.endswith(".xml")}


def load_native_structure_notes(api_header):
    """Read notes verified against the matching Godot engine structures."""
    path = get_header_documentation_directory(api_header) / "native_structures.json"
    return json.loads(path.read_text(encoding="utf-8")) if path.is_file() else {}


def append_markdown_comment(lines, declaration, description, example=()):
    if not description:
        return
    content = description.strip().splitlines()
    if example:
        content += ["", "```cpp", *example, "```"]
    indent = declaration[: len(declaration) - len(declaration.lstrip())]
    lines.append(indent + "/**")
    lines.extend(indent + " *" + (" " + line if line else "") for line in content)
    lines.append(indent + " */")


def describe_parameters(description, parameters):
    """Attach verified parameter roles to a documented declaration."""
    if not description or not parameters:
        return description
    entries = "\n".join(f"- `{name}` — {role}" for name, role in parameters)
    return f"{description}\n\n{entries}"


_CODE_BLOCK = re.compile(r"\[(codeblocks|codeblock|gdscript|csharp|cpp)(?:[^\]]*)\].*?\[/\1\]", re.DOTALL)
_EXAMPLE_LABEL = re.compile(r"(?im)^[ \t]*(?:example|examples|prints|output):[ \t]*(?=\n\s*\[(?:codeblocks|codeblock|gdscript|csharp|cpp)\b)")
_BBCODE = re.compile(r"\[(/?)([\w@]+)(?:[ =]([^\]]*))?\]")
_LINK = re.compile(r'\[url(?:=([^\]]*))?\](.*?)\[/url\]', re.DOTALL)
_PARAMETER_STATEMENT = re.compile(
    r"\[param (\w+)\] (is|are|must|should|sets|specifies|determines|controls|defines) (.+[.!?])",
    re.IGNORECASE,
)
_SENTENCE_BOUNDARY = re.compile(r"(?<=[.!?])\s+(?=[A-Z]|\[param )")


def _cpp_reference(target, owner, kind):
    if "." in target:
        owner, target = target.rsplit(".", 1)
    if owner == "@GlobalScope":
        return f"godot::{target}" if kind in ("constant", "enum") else target + "()"
    if owner.startswith("@"):
        return target
    owner = owner.replace(".", "::")
    if kind == "method":
        return f"godot::{owner}::{target}()"
    return f"godot::{owner}::{target}"


def reference_text(text, owner, types):
    """Convert reference prose to Markdown, leaving language-specific examples in the XML."""
    if not text:
        return ""
    text = _CODE_BLOCK.sub("\n", _EXAMPLE_LABEL.sub("", text))
    inline_code = []

    def protect_code(match):
        code = " ".join(match[1].split())
        code = re.sub(r"\b([A-Z]\w*)\.([A-Z_][A-Z0-9_]*)\b",
                      lambda ref: f"godot::{ref[1]}::{ref[2]}" if ref[1] in types else ref[0], code)
        marker = f"\x00{len(inline_code)}\x00"
        fence = "`" * (1 + max((len(run) for run in re.findall(r"`+", code)), default=0))
        if code.startswith("`") or code.endswith("`"):
            code = f" {code} "
        inline_code.append(fence + code + fence)
        return marker

    def markdown_link(match):
        label = " ".join(match[2].split())
        url = match[1] or label
        if url.startswith(("https://", "http://")):
            return f"[{label}](<{url}>)"
        return label

    text = re.sub(r"\[code\](.*?)\[/code\]", protect_code, text, flags=re.DOTALL)
    links = []

    def protect_link(match):
        marker = f"\x01{len(links)}\x01"
        links.append(markdown_link(match))
        return marker

    text = _LINK.sub(protect_link, text)

    def replace(match):
        closing, tag, value = match.groups()
        if tag == "b":
            return "**"
        if tag == "i":
            return "*"
        if tag in ("lb", "rb"):
            return "[" if tag == "lb" else "]"
        if tag == "br":
            return "\n"
        if tag in ("u", "s", "color", "font", "center", "left", "right", "table", "cell"):
            return ""
        if not closing and tag in ("method", "constant", "enum") and value:
            return "`" + _cpp_reference(value, owner, tag) + "`"
        if not closing and tag == "member" and value:
            return "`" + value.rsplit(".", 1)[-1] + "`"
        if not closing and tag in ("param", "signal", "annotation", "constructor", "operator", "theme_item", "kbd") and value:
            return "`" + value + "`"
        if not closing and value is None:
            return "`" + ("godot::" + tag if tag in types and tag not in ("int", "float", "bool", "Nil") else tag) + "`"
        return match[0]

    paragraphs = []
    for paragraph in re.split(r"\n\s*\n", text):
        paragraph = " ".join(_BBCODE.sub(replace, paragraph).split())
        if not paragraph or paragraph.lower().startswith(("in gdscript", "in c#", "for c#")):
            continue
        paragraph = re.sub(r"\x00(\d+)\x00", lambda m: inline_code[int(m[1])], paragraph)
        paragraph = re.sub(r"\x01(\d+)\x01", lambda m: links[int(m[1])], paragraph)
        paragraphs.append(paragraph.replace("*/", "* /"))
    if not paragraphs:
        return ""
    selected = [paragraphs[0]]
    if len(paragraphs) > 1 and len(paragraphs[0]) + len(paragraphs[1]) <= 560:
        selected.append(paragraphs[1])
    return "\n\n".join(textwrap.fill(line, width=104, break_long_words=False, break_on_hyphens=False) for line in selected)


def _xml_type(node):
    if node is None:
        return "void"
    if node.get("enum"):
        prefix = "bitfield::" if node.get("is_bitfield") == "true" else "enum::"
        return prefix + node.get("enum")
    name = node.get("type", "void")
    if name.endswith("[]"):
        return "typedarray::" + name[:-2]
    if name.startswith("Dictionary[") and name.endswith("]"):
        return "typeddictionary::" + ";".join(part.strip() for part in name[11:-1].split(",", 1))
    return name


def _type_matches(api_type, xml_type):
    # The XML uses a single enum attribute for enum and bitfield types.
    if api_type.startswith("bitfield::"):
        api_type = "enum::" + api_type[len("bitfield::") :]
    if xml_type.startswith("bitfield::"):
        xml_type = "enum::" + xml_type[len("bitfield::") :]
    return api_type == xml_type


class ReferenceDocumentation:
    """Match upstream prose to an emitted declaration using the exact API signature."""

    def __init__(self, roots, name, base=None):
        self.roots = roots
        self.name = name
        self.root = roots.get(name)
        if self.root is not None and (self.root.get("name") != name or (base is not None and self.root.get("inherits") != base)):
            self.root = None
        self.members = {}
        self.constants = {}
        self.methods = {}
        if self.root is not None:
            self.members = {node.get("name"): node for node in self.root.findall("members/member")}
            self.constants = {node.get("name"): node for node in self.root.findall("constants/constant")}
            for node in self.root.findall("methods/method"):
                self.methods.setdefault(node.get("name"), []).append(node)
        self.accessors = {}
        for member in self.members.values():
            for role in ("getter", "setter"):
                name = member.get(role)
                if name:
                    self.accessors.setdefault(name, []).append((role, member))

    def _text(self, text):
        return reference_text(text, self.name, self.roots)

    def type_description(self):
        if self.root is None:
            return ""
        return self._text(self.root.findtext("brief_description")) or self._text(self.root.findtext("description"))

    def member(self, name):
        node = self.members.get(name)
        return self._text(node.text) if node is not None else ""

    def constant(self, api_constant, enum_name=None):
        node = self.constants.get(api_constant["name"])
        if node is None or node.get("enum") != enum_name:
            return ""
        value = api_constant.get("value")
        if isinstance(value, int):
            try:
                if int(node.get("value", ""), 0) != value:
                    return ""
            except ValueError:
                return ""
        return self._text(node.text)

    def enum_description(self, enum_name, methods=()):
        """Use an official description or a verified relation to an API property."""
        if self.root is None:
            return ""
        explicit = self.root.findtext(f"enums/enum[@name='{enum_name}']/description")
        if explicit and explicit.strip():
            return self._text(explicit)
        qualified = enum_name if self.name == "@GlobalScope" else f"{self.name}.{enum_name}"
        for prop in self.members.values():
            setter = prop.get("setter")
            if prop.get("enum") == qualified and setter and (prop.text or "").strip():
                return f"Values accepted by `godot::{self.name}::{setter}()`."
        enum_type = "enum::" + qualified
        for method in methods:
            if any(_type_matches(arg["type"], enum_type) for arg in method.get("arguments", ())):
                return f"Values accepted by `godot::{self.name}::{method['name']}()`."
            if _type_matches(method.get("return_value", {}).get("type", "void"), enum_type):
                return f"Values returned by `godot::{self.name}::{method['name']}()`."
        return ""

    @staticmethod
    def _match(nodes, arguments, return_type=None, qualifiers=None):
        matches = []
        for node in nodes:
            params = node.findall("param")
            if len(arguments) != len(params) or any(
                not _type_matches(arg["type"], _xml_type(param)) for arg, param in zip(arguments, params)
            ):
                continue
            if return_type is not None and not _type_matches(return_type, _xml_type(node.find("return"))):
                continue
            if qualifiers is not None:
                actual = set(node.get("qualifiers", "").split()) & {"const", "static", "virtual", "vararg"}
                if qualifiers != actual:
                    continue
            matches.append(node)
        return matches[0] if len(matches) == 1 else None

    def _method_node(self, api_method, arguments, return_type):
        name = api_method["name"]
        qualifiers = {flag for flag in ("const", "static", "virtual", "vararg") if api_method.get(f"is_{flag}")}
        candidates = self.methods.get(name, ())
        node = self._match(candidates, arguments, return_type, qualifiers)
        # Global varargs may be documented without the required Variant prefix
        # used by the C++ wrappers.
        if (
            node is None
            and self.name == "@GlobalScope"
            and qualifiers == {"vararg"}
            and arguments
            and all(argument["type"] == "Variant" for argument in arguments)
        ):
            node = self._match(candidates, [], return_type, qualifiers)
        return node

    def method(self, api_method):
        name = api_method["name"]
        arguments = api_method.get("arguments", [])
        return_type = api_method.get("return_value", {}).get("type", api_method.get("return_type", "void"))
        node = self._method_node(api_method, arguments, return_type)
        if node is not None:
            description = self._text(node.findtext("description"))
            if description:
                return description

        # The class reference describes simple getters and setters on the property.
        accessors = self.accessors.get(name, ())
        if len(accessors) > 1 and node is not None:
            return self._indexed_accessor(accessors, arguments, return_type)
        if len(accessors) != 1:
            return ""
        role, prop = accessors[0]
        prop_type = _xml_type(prop)
        signature_matches = (
            not arguments and _type_matches(return_type, prop_type)
            if role == "getter"
            else len(arguments) == 1 and _type_matches(arguments[0]["type"], prop_type) and return_type == "void"
        )
        description = self._text(prop.text)
        if not signature_matches or not description:
            return ""
        verb = "Returns" if role == "getter" else "Sets"
        return f"{verb} the `{prop.get('name')}` property.\n\n{description}"

    def _explicit_parameters(self, node, arguments):
        """Read statements that directly describe a parameter of the matched signature."""
        if node is None:
            return ()
        names = {
            argument["name"]
            for argument, param in zip(arguments, node.findall("param"))
            if argument["name"] == param.get("name")
        }
        if not names:
            return ()
        prose = _CODE_BLOCK.sub("\n", node.findtext("description") or "")
        roles = {}
        for paragraph in prose.splitlines():
            for sentence in _SENTENCE_BOUNDARY.split(paragraph.strip()):
                statement = _PARAMETER_STATEMENT.fullmatch(sentence)
                if statement is None:
                    continue
                name, verb, detail = statement.groups()
                if name not in names or name in roles or re.search(r"\[param |GDScript|C#|\[url", detail, re.IGNORECASE):
                    continue
                if verb.lower() in ("is", "are"):
                    role = detail[0].upper() + detail[1:]
                else:
                    role = verb.capitalize() + " " + detail
                description = self._text(role)
                if description:
                    roles[name] = description
        return tuple((argument["name"], roles[argument["name"]]) for argument in arguments if argument["name"] in roles)

    def method_parameters(self, api_method):
        """Describe parameter roles established by the matched method or property."""
        arguments = api_method.get("arguments", [])
        if not arguments:
            return ()
        return_type = api_method.get("return_value", {}).get("type", api_method.get("return_type", "void"))
        node = self._method_node(api_method, arguments, return_type)
        explicit = dict(self._explicit_parameters(node, arguments))
        fallback = dict(self._property_parameters(api_method, arguments, return_type))
        return tuple(
            (name, explicit[name] if name in explicit else fallback[name])
            for argument in arguments
            if (name := argument["name"]) in explicit or name in fallback
        )

    def _property_parameters(self, api_method, arguments, return_type):
        accessors = self.accessors.get(api_method["name"], ())
        if not accessors or api_method.get("is_vararg"):
            return ()
        role = accessors[0][0]
        if role != "setter" or return_type != "void" or any(kind != role for kind, _ in accessors):
            return ()
        if any(
            not _type_matches(arguments[-1]["type"], _xml_type(prop)) or not self._text(prop.text)
            for _, prop in accessors
        ):
            return ()
        if len(accessors) == 1 and len(arguments) == 1:
            property_name = accessors[0][1].get("name")
            return ((arguments[0]["name"], f"New value for the `{property_name}` property."),)
        if len(accessors) > 1 and len(arguments) == 2 and arguments[0]["type"].startswith("enum::"):
            return (
                (arguments[0]["name"], "Selector for the property to update."),
                (arguments[1]["name"], "New value for the selected property."),
            )
        return ()

    @staticmethod
    def _indexed_accessor(accessors, arguments, return_type):
        if not arguments or not arguments[0]["type"].startswith("enum::"):
            return ""
        role = accessors[0][0]
        if any(candidate != role for candidate, _ in accessors):
            return ""
        if role == "getter" and len(arguments) == 1:
            value_type = return_type
            verb = "Returns"
        elif role == "setter" and len(arguments) == 2 and return_type == "void":
            value_type = arguments[1]["type"]
            verb = "Sets"
        else:
            return ""
        if any(not _type_matches(value_type, _xml_type(prop)) for _, prop in accessors):
            return ""
        examples = [f"`{prop.get('name')}`" for _, prop in accessors if (prop.text or "").strip()][:2]
        if not examples:
            return ""
        return (
            f"{verb} the property selected by `{arguments[0]['name']}`. "
            f"Properties using this accessor include {' and '.join(examples)}."
        )

    def constructor(self, api_constructor):
        if self.root is None:
            return ""
        node = self._match(self.root.findall("constructors/constructor"), api_constructor.get("arguments", []))
        return self._text(node.findtext("description")) if node is not None else ""

    def constructor_parameters(self, api_constructor):
        if self.root is None:
            return ()
        arguments = api_constructor.get("arguments", [])
        node = self._match(self.root.findall("constructors/constructor"), arguments)
        return self._explicit_parameters(node, arguments)

    def operator(self, api_operator):
        if self.root is None:
            return ""
        name = api_operator["name"]
        name = name[len("unary") :] if name.startswith("unary") else name
        right = api_operator.get("right_type")
        arguments = [{"type": right}] if right else []
        node = self._match(
            self.root.findall(f"operators/operator[@name='operator {name}']"), arguments, api_operator["return_type"]
        )
        return self._text(node.findtext("description")) if node is not None else ""


class ClassHeaderDocumentation:
    """Emit reviewed C++ notes at the corresponding engine class declarations."""

    def __init__(self, path, class_api, reference=None):
        self.path = path
        try:
            data = json.loads(path.read_text(encoding="utf-8"))
            self.entries = data["declarations"]
        except (OSError, ValueError, TypeError, KeyError) as error:
            raise ValueError(f"{path}: unable to load reviewed header documentation: {error}") from error
        self.partial = data.get("partial", False)
        self.unmatched = set(self.entries)
        class_name = class_api.get("alias_for", class_api["name"])
        if self.partial:
            xml_path = path.parent / "class_reference.zip"
            self.xml = (reference or {}).get(class_name)
        else:
            xml_path = path.with_suffix(".xml")
            try:
                self.xml = ET.parse(xml_path).getroot()
            except (OSError, ET.ParseError) as error:
                raise ValueError(f"{xml_path}: unable to load Godot class documentation: {error}") from error
        if (
            self.xml is None
            or self.xml.tag != "class"
            or self.xml.get("name") != class_name
            or self.xml.get("inherits") != class_api.get("inherits")
        ):
            raise ValueError(f"{xml_path}: Godot class documentation does not match the API class or base class")

    def check_matches(self):
        if self.partial and self.unmatched:
            declarations = ", ".join(sorted(self.unmatched))
            raise ValueError(f"{self.path}: reviewed declarations absent from the selected API: {declarations}")

    def append_comment(self, lines, declaration, *, key=None, api_member=None):
        key = key or declaration.strip()
        where = f"{self.path}: {key}"
        entry = self.entries.get(key)
        if entry is None:
            if self.partial:
                return False
            raise ValueError(f"{where}: missing reviewed header documentation")

        selector = entry.get("xml")
        if api_member is not None and not selector:
            raise ValueError(f"{where}: missing Godot XML reference")
        if selector:
            source = self.xml.find(selector)
            if source is None or not "".join(source.itertext()).strip():
                raise ValueError(f"{where}: missing description in Godot XML for {selector!r}")
            if api_member and api_member not in (source.get("name"), source.get("getter"), source.get("setter")):
                raise ValueError(f"{where}: Godot XML does not describe {api_member!r}")

        brief = entry.get("brief")
        example = entry.get("example", [])
        if not isinstance(brief, str) or not brief.strip():
            raise ValueError(f"{where}: a verified description is required")
        if not isinstance(example, list):
            raise ValueError(f"{where}: the C++ example must be an array of lines")
        if any(not isinstance(line, str) or len(line.splitlines()) > 1 for line in example):
            raise ValueError(f"{where}: the C++ example must be an array of lines")
        if (example and not any(line.strip() for line in example)) or "*/" in brief or any("*/" in line for line in example):
            raise ValueError(f"{where}: invalid Markdown comment content")
        append_markdown_comment(lines, declaration, brief, example)
        self.unmatched.discard(key)
        return True
