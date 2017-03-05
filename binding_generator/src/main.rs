extern crate serde_json;
#[macro_use]
extern crate serde_derive;


use serde_json::*;
use std::fs::File;
use std::iter::Iterator;
use std::io::prelude::*;

use std::env;

#[derive(Deserialize)]
struct GodotClass {
	name: String,
	base_class: String,
	api_type: String,
	singleton: bool,
	instanciable: bool,
	constants: Map<String, Value>,
	methods: Vec<GodotMethod>
}

#[derive(Deserialize)]
struct GodotMethod {
	name: String,
	return_type: String,
	is_editor: bool,
	is_noscript: bool,
	is_const: bool,
	is_virtual: bool,
	is_from_script: bool,
	arguments: Vec<GodotArgument>
}

#[derive(Deserialize)]
struct GodotArgument {
	name: String,
	#[serde(rename = "type")]
	_type: String,
	default_value: String
}

fn strip_name(s: &String) -> &str {
	if s.starts_with("_") {
		unsafe { s.slice_unchecked(1, s.len()) }
	} else {
		s.as_str()
	}
}

fn main() {
	let base_dir = match env::args().nth(2) {
		Some(x) => x,
		None    => return
	};

	let mut file = match env::args().nth(1) {
		Some(x) => File::open(x).unwrap(),
		None    => return
	};

	let mut file_contents = String::new();

	file.read_to_string(&mut file_contents);

	let json: Vec<GodotClass> = serde_json::from_str::<Vec<GodotClass>>(&file_contents).unwrap();

	let mut forward_declares = String::new();
	{
		for class in &json {
			forward_declares = forward_declares + "class " + strip_name(&class.name) + ";\n";
		}
	}

	for class in json {
		generate_class_binding(&forward_declares, (base_dir.to_string() + strip_name(&class.name) + ".h").as_str(), &class);
	}
}

fn generate_class_binding(forward_declares: &String, filename: &str, class: &GodotClass) {
	let mut file = File::create(filename).unwrap();

	file.write_all(generate_class_content(forward_declares, class).as_bytes());
}

fn generate_class_content(forward_declares: &String, class: &GodotClass) -> String {
	let mut contents = String::new();

	contents = contents + "#ifndef ";
	contents = contents + strip_name(&class.name).to_string().to_uppercase().as_str() + "_H\n";

	contents = contents + "#define ";
	contents = contents + strip_name(&class.name).to_string().to_uppercase().as_str() + "_H\n\n";

	contents = contents + "\n#include \"core/CoreTypes.h\"\n";

	contents = contents + "\n#include <godot.h>\n\n\n";

	if class.base_class != "" {
		contents = contents + "\n#include \"" + strip_name(&class.base_class) + ".h\"\n\n\n";
	}

	contents = contents + "namespace godot {\n\n";

	contents += forward_declares;

	let core_obj_name = {
		let mut name = String::new();
		if class.singleton {
			name = name + "___static_object_" + strip_name(&class.name);
		} else {
			name = name + "__core_object";
		};
		name
	};

	if class.singleton {
		contents = contents + "\n\nstatic godot_object *" + core_obj_name.as_str() + ";\n\n";
	}

	contents = contents + "\n\n\nclass " + strip_name(&class.name);

	if class.base_class != "" {
		contents = contents + " : public " + strip_name(&class.base_class);
	}

	contents = contents + " {\n";

	if class.base_class == "" {
		contents = contents + "protected:\n\tgodot_object *__core_object = 0;\n\n";
	}

	if class.singleton {
		contents = contents + "private:\n";
		contents = contents + "\tstatic void ___singleton_init() { "
			+ core_obj_name.as_str() + " = godot_global_get_singleton(\"" + strip_name(&class.name) + "\"); }\n\n";
	}

	contents = contents + "public:\n\n";

	// default constructor

	{
		contents = contents + "\t" + strip_name(&class.name) + "() {\n";
		contents = contents + "\t\t\n";
		contents = contents + "\t}\n\n";
	}


	// pointer constructor
	{
		contents = contents + "\t" + strip_name(&class.name) + "(godot_object *ptr) {\n";
		contents = contents + "\t\t__core_object = ptr;\n";
		contents = contents + "\t}\n\n\n";
	}

	if class.base_class != "" {
		contents = contents + "\tvoid _init() {\n";
		contents = contents + "\t\t\n";
		contents = contents + "\t}\n\n";
	}

	if class.instanciable {
		contents = contents + "\tstatic " + strip_name(&class.name) + "& _new();\n";
		contents = contents + "\tvoid _destroy();\n\n";
	}

	for (name, value) in &class.constants {
		contents = contents + "\tconst static int " + name.as_str() + " = " + value.as_i64().unwrap().to_string().as_str() + ";\n";
	}

	contents += "\n\n";

	for method in &class.methods {
		contents = contents + "\t" + (if class.singleton { "static " } else { "" }) + strip_name(&method.return_type) + (if !is_core_type(&method.return_type) && !is_primitive(&method.return_type) { " &" } else { " " }) + method.name.as_str() + "(";

		for (i, argument) in (&method.arguments).iter().enumerate() {
			if !is_primitive(&argument._type) {
				contents = contents + "const " + argument._type.as_str() + "&";
			} else {
				contents = contents + "const " + argument._type.as_str() + "";
			}

			contents = contents + " " + escape_cpp(&argument.name);
			if i != method.arguments.len() - 1 {
				contents += ", ";
			}
		}

		contents = contents + ") {\n";

		if class.singleton {
			contents = contents + "\t\tif (" + core_obj_name.as_str() + " == 0) {\n";
			contents = contents + "\t\t\t___singleton_init();\n";
			contents = contents + "\t\t}\n\n";
		}

		contents = contents + "\t\tstatic godot_method_bind *mb = NULL;\n"
		                    + "\t\tif (mb == NULL) {\n"
		                    + "\t\t\tmb = godot_method_bind_get_method(\"" + class.name.as_str() + "\", \"" + method.name.as_str() + "\");\n"
		                    + "\t\t}\n";

		if method.return_type != "void" {
			// contents = contents + "\t\t" + strip_name(&method.return_type) + (if !is_core_type(&method.return_type) && !is_primitive(&method.return_type) { "*" } else { "" }) + " ret;" + "\n";
			contents = contents + "\t\t" + if !is_core_type(&method.return_type) && !is_primitive(&method.return_type) { "godot_object*" } else { strip_name(&method.return_type) } + " ret;\n";
		}

		contents = contents + "\t\tconst void *args[] = {\n";

		for argument in &method.arguments {
			contents = contents + "\t\t\t";
			if is_primitive(&argument._type) {
				contents = contents + "&" + argument.name.as_str();
			} else if is_core_type(&argument._type) {
				contents = contents + "(void *) &" + escape_cpp(&argument.name);
			} else {
				contents = contents + "(void *) &" + escape_cpp(&argument.name);
			}
			contents = contents + ",\n";
		}

		contents = contents + "\t\t};\n";

		contents = contents + "\t\tgodot_method_bind_ptrcall(mb, " + core_obj_name.as_str() + ", args, " + if method.return_type == "void" { "NULL" } else { "&ret" } + ");\n";

		if !is_primitive(&method.return_type) && !is_core_type(&method.return_type) {
			contents = contents + "\t\treturn reinterpret_cast<" + strip_name(&method.return_type) + "&>(ret);\n";
		} else if method.return_type != "void" {
			contents = contents + "\t\treturn ret;\n";
		}

		contents = contents + "\t}\n\n";
	}

	contents = contents + "};\n\n";

	contents = contents + "}\n";



	if class.instanciable {

		contents = contents + "#include \"ClassDB.h\"\n";

		contents = contents + "namespace godot {\n\n";

		contents = contents + "" + strip_name(&class.name) + "& " + strip_name(&class.name) + "::_new() {\n";
		contents = contents + "\tObject ptr = ClassDB::instance(\"" + class.name.as_str() + "\");\n";
		contents = contents + "\treturn reinterpret_cast<" + strip_name(&class.name) + "&>(ptr);";
		contents = contents + "}\n\n";

		contents = contents + "void " + strip_name(&class.name) + "::_destroy() {\n";
		contents = contents + "\tgodot_object_destroy(__core_object);\n";
		contents = contents + "}\n\n\n";

		if class.base_class == "" {
			// Object
			contents = contents + "Variant::operator Object()const {\n\n";

			contents = contents + "\treturn Object(godot_variant_as_object(&_godot_variant));\n\n";

			contents = contents + "}\n\n";
		}

		contents = contents + "}\n";
	}



	contents = contents + "#endif\n";

	contents
}


fn is_core_type(name: &String) -> bool {
	let core_types = vec!["Array", "PoolStringArray", "Vector2", "Vector3", "String", "Variant"];
	core_types.contains(&name.as_str())
}

fn is_primitive(name: &String) -> bool {
	let core_types = vec!["int", "bool", "real", "float", "void"];
	core_types.contains(&name.as_str())
}

fn escape_cpp(name: &String) -> &str {
	match name.as_str() {
		"class" => "_class",
		"char"  => "_char",
		"short" => "_short",
		x       => x
	}
}