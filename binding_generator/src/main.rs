extern crate serde_json;
#[macro_use]
extern crate serde_derive;


use serde_json::*;
use std::fs::File;
use std::iter::Iterator;
use std::io::prelude::*;

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
	let base_dir = "/home/karroffel/Gamedev/dlscript_cpp_example/src/include/godot_cpp/";

	let mut file = File::open("/home/karroffel/Development/api.json").unwrap();

	let mut file_contents = String::new();

	file.read_to_string(&mut file_contents);

	let json: Vec<GodotClass> = serde_json::from_str::<Vec<GodotClass>>(&file_contents).unwrap();

	for class in json {
		generate_class_binding((base_dir.to_string() + strip_name(&class.name) + ".h").as_str(), &class);
	}
}

fn generate_class_binding(filename: &str, class: &GodotClass) {
	let mut file = File::create(filename).unwrap();

	file.write_all(generate_class_content(class).as_bytes());
}

fn generate_class_content(class: &GodotClass) -> String {
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

	contents = contents + "class " + strip_name(&class.name);

	if class.base_class != "" {
		contents = contents + " : public " + strip_name(&class.base_class);
	}

	contents = contents + " {\n";

	if class.base_class == "" {
		contents = contents + "protected:\n\tgodot_object *__core_object;\n\n";
	}

	contents = contents + "public:\n\n";

	// default constructor

	{
		contents = contents + "\t" + strip_name(&class.name) + "() {\n";
		contents = contents + "\t\t\n";
		contents = contents + "\t}\n";
	}


	// pointer constructor
	{
		contents = contents + "\t" + strip_name(&class.name) + "(godot_object *ptr) {\n";
		contents = contents + "\t\t__core_object = ptr;\n";
		contents = contents + "\t}\n\n\n";
	}

	for (name, value) in &class.constants {
		contents = contents + "\tconst static int " + name.as_str() + " = " + value.as_i64().unwrap().to_string().as_str() + ";\n";
	}

	contents += "\n\n";

	for method in &class.methods {
		contents = contents + "\t" + method.return_type.as_str() + " " + method.name.as_str() + "(";

		for (i, argument) in (&method.arguments).iter().enumerate() {
			if !is_primitive(&argument._type) {
				contents += "const "
			}
			contents = contents + argument._type.as_str();
			if !is_primitive(&argument._type) {
				contents += "&";
			}
			contents = contents + " " + argument.name.as_str();
			if i != method.arguments.len() - 1 {
				contents += ", ";
			}
		}

		contents = contents + ") {\n";

		contents = contents + "\t\tstatic godot_method_bind *mb = NULL;\n"
		                    + "\t\tif (mb == NULL) {\n"
		                    + "\t\t\tmb = godot_method_bind_get_method(\"" + class.name.as_str() + "\", \"" + method.name.as_str() + "\");\n"
		                    + "\t\t}\n";

		if method.return_type != "void" {
			contents = contents + "\t\t" + method.return_type.as_str() + " ret;" + "\n";
		}

		contents = contents + "\t\tconst void *args[] = {\n";

		for argument in &method.arguments {
			contents = contents + "\t\t\t";
			if is_primitive(&argument._type) {
				contents = contents + "&" + argument.name.as_str();
			} else {
				contents = contents + "(void *) &" + argument.name.as_str();
			}
			contents = contents + ",\n";
		}

		contents = contents + "\t\t};\n";

		contents = contents + "\t\tgodot_method_bind_ptrcall(mb, __core_object, args, " + if method.return_type == "void" { "NULL" } else { "&ret" } + ");\n";

		if method.return_type != "void" {
			contents = contents + "\t\treturn ret;\n";
		}

		contents = contents + "\t}\n\n";
	}

	contents = contents + "};\n\n";

	contents = contents + "}\n";

	contents = contents + "#endif\n";

	contents
}


fn is_core_type(name: &String) -> bool {
	let core_types = vec!("Vector2", "Vector3", "String", "Variant");
	core_types.contains(&name.as_str())
}

fn is_primitive(name: &String) -> bool {
	let core_types = vec!("int", "bool", "real", "float");
	core_types.contains(&name.as_str())
}