extern crate serde_json;
#[macro_use]
extern crate serde_derive;


use serde_json::*;
use std::fs::File;
use std::iter::Iterator;
use std::io::prelude::*;

use std::collections::HashSet;

use std::env;

// use std::ascii::AsciiExt;

#[derive(Deserialize)]
struct GodotClass {
	name: String,
	base_class: String,
	api_type: String,
	singleton: bool,
	instanciable: bool,
	is_reference: bool,
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
	has_varargs: bool,
	is_from_script: bool,
	arguments: Vec<GodotArgument>
}

#[derive(Deserialize)]
struct GodotArgument {
	name: String,
	#[serde(rename = "type")]
	_type: String,
	has_default_value: bool,
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

	let mut icalls: HashSet<(String, Vec<String>)> = HashSet::new();

	for class in &json {
		// make this toggleable with a command line switch
		// if class.api_type == "tools" {
		// 	println!("{}", class.name);
		// 	continue
		// }
		let used_classes = get_used_classes(&class);

		let mut header = File::create((base_dir.to_string() + strip_name(&class.name) + ".hpp").as_str()).unwrap();

		header.write_all(generate_class_header(&used_classes, &class).as_bytes());

		let mut implementation = File::create((base_dir.to_string() + "impl/" + strip_name(&class.name) + ".cpp").as_str()).unwrap();
		implementation.write_all(generate_class_implementation(&mut icalls, &used_classes, &class).as_bytes());
	}

	// generate icall files
	let mut icall_header = File::create((base_dir.to_string() + "__icalls.hpp").as_str()).unwrap();

	icall_header.write_all(generate_icall_header(&icalls).as_bytes());

	let mut icall_implmentation = File::create((base_dir.to_string() + "impl/__icalls.cpp").as_str()).unwrap();

	icall_implmentation.write_all(generate_icall_implementation(&json, &icalls).as_bytes());
}

fn get_used_classes(class: &GodotClass) -> HashSet<&String> {

	let mut classes = HashSet::new();

	// classes.insert(&class.base_class);

	for method in &class.methods {
		if !is_primitive(&method.return_type) &&!is_core_type(&method.return_type) && !classes.contains(&method.return_type) {
			classes.insert(&method.return_type);
		}

		for argument in &method.arguments {
			if !is_primitive(&argument._type) &&!is_core_type(&argument._type) && !classes.contains(&argument._type) {
				classes.insert(&argument._type);
			}
		}
	}

	return classes;
}

fn generate_class_header(used_classes: &HashSet<&String>, class: &GodotClass) -> String {
	let mut contents = String::new();

	contents = contents + "#ifndef ";
	contents = contents + strip_name(&class.name).to_string().to_uppercase().as_str() + "_H\n";

	contents = contents + "#define ";
	contents = contents + strip_name(&class.name).to_string().to_uppercase().as_str() + "_H\n\n";
	
	contents = contents + "#if defined(_WIN32) && defined(_GD_CPP_BINDING_IMPL)\n";
	contents = contents + "#  define GD_CPP_BINDING_API __declspec(dllexport)\n";
	contents = contents + "#elif defined(_WIN32)\n";
	contents = contents + "#  define GD_CPP_BINDING_API __declspec(dllimport)\n";
	contents = contents + "#else\n";
	contents = contents + "#  define GD_CPP_BINDING_API\n";
	contents = contents + "#endif\n\n";
	

	contents = contents + "\n#include \"core/CoreTypes.hpp\"\n";

	contents = contents + "\n#include <godot.h>\n\n\n";

	if class.base_class != "" {
		contents = contents + "\n#include \"" + strip_name(&class.base_class) + ".hpp\"\n\n\n";
	}

	contents = contents + "namespace godot {\n\n";

	// contents += forward_declares;

	for used_type in used_classes {
		contents = contents + "class " + strip_name(used_type) + ";\n"
	}

	contents = contents + "\n\n";

	let core_obj_name = {
		let mut name = String::new();
		if class.singleton {
			name = name + "___static_object_" + strip_name(&class.name);
		} else {
			name = name + "this";
		};
		name
	};

	contents = contents + "class GD_CPP_BINDING_API " + strip_name(&class.name);

	if class.base_class != "" {
		contents = contents + " : public " + strip_name(&class.base_class);
	}

	contents = contents + " {\n";

	// if class.base_class == "" {
	//	contents = contents + "public:\n\tgodot_object *__core_object = 0;\n\n";
	// }

	if class.singleton {
		contents = contents + "private:\n";
		contents = contents + "\tstatic void ___singleton_init();\n";
	}

	contents = contents + "public:\n\n";

	// default constructor

	{
		contents = contents + "\tstatic " + strip_name(&class.name) + "* _new();\n\n";
	}


	// pointer constructor
	// {
	// 	contents = contents + "\t" + strip_name(&class.name) + "(godot_object *ptr);\n\n";
	// }

	// object constructor
	// if !class.singleton {
	// 	contents = contents + "\t" + strip_name(&class.name) + "(const Object *ptr);\n\n";
	// 	contents = contents + "\t" + strip_name(&class.name) + "(const Variant& obj);\n\n";
	// }

	if class.name != "Object" {
		contents = contents + "\tvoid _init();\n\n";
	}

	// if class.instanciable {
	// 	contents = contents + "\tstatic " + strip_name(&class.name) + " __new();\n";
	// 	contents = contents + "\tvoid __destroy();\n\n";
	// }

	for (name, value) in &class.constants {
		contents = contents + "\tconst static int " + name.as_str() + " = " + value.as_i64().unwrap().to_string().as_str() + ";\n";
	}

	contents += "\n\n";

	fn escape_default_arg(type_: &String, arg: &String) -> String {
		match type_.as_str() {
			"Color" => {
				String::from("Color(") + arg.as_str() + ")"
			},
			"bool" | "int" => {
				String::from(arg.as_str()).as_str().to_lowercase()
			},
			"Array" => {
				String::from("Array()")
			},
			"PoolVector2Array" | "PoolStringArray" | "PoolColorArray" | "PoolVector3Array" => {
				type_.clone() + "()" // String::from("PoolVector2Array()")
			}
			"Vector2" => {
				String::from("Vector2") + arg.as_str()
			}
			"Vector3" => {
				String::from("Vector3") + arg.as_str()
			}
			"Transform" => {
				String::from("Transform()")// + arg.as_str() + ")"
			}
			"Transform2D" => {
				String::from("Transform2D()")
			}
			"Rect2" => {
				String::from("Rect2") + arg.as_str()
			}
			"Variant" => {
				if arg == "Null" {
					String::from("Variant()")
				} else {
					arg.clone()
				}
			}
			"String" => {
				String::from("\"") + arg.as_str() + "\""
			}
			"RID" => {
				String::from("RID()")
			}
			_ => {
				match arg.as_str() {
					"Null" => String::from("nullptr"),
					"[Object:null]" => String::from("nullptr"),
					a      => String::from(a)
				}
			}
		}
	}

	for method in &class.methods {
		contents = contents + "\t" + (if class.singleton { "static " } else { "" }) + strip_name(&method.return_type) + (if !is_core_type(&method.return_type) && !is_primitive(&method.return_type) { " *" } else { " " }) + escape_cpp(&method.name) + "(";

		let mut has_default = false;

		for (i, argument) in (&method.arguments).iter().enumerate() {
			if !is_primitive(&argument._type) && !is_core_type(&argument._type) {
				contents = contents + "const " + argument._type.as_str() + " *";
			} else {
				contents = contents + "const " + argument._type.as_str() + " ";
			}

			contents = contents + escape_cpp(&argument.name);

			if argument.has_default_value || has_default {
				contents = contents + " = " + escape_default_arg(&argument._type, &argument.default_value).as_str();
				has_default = true;
			}// else if has_default {
			//	contents = contents + " = \"\"";
			//}

			if i != method.arguments.len() - 1 {
				contents += ", ";
			}
		}

		if method.has_varargs {
			if method.arguments.len() > 0 {
				contents += ", ";
			}
			contents = contents + "const Array& __var_args = Array()";
		}

		contents = contents + ")" + if method.is_const && !class.singleton { " const" } else { "" } + ";\n";
		// contents = contents + ")" + if method.is_const { " const" } else { "" } + ";\n";
	}

	contents = contents + "};\n\n";

	// if class.base_class == "" {
	// 	// Object
	// 	contents = contents + "\ninline\n#if defined(_WIN32)\n#  ifdef _GD_CPP_BINDING_IMPL\n      __declspec(dllexport)\n#  else\n      __declspec(dllimport)\n#  endif\n#endif\nVariant::operator Object() const\n{\n\n";

	//	contents = contents + "\treturn Object(godot_variant_as_object(&_godot_variant));\n\n";

	//	contents = contents + "\n}\n\n";
	// }

	contents = contents + "}\n";

	contents = contents + "#endif\n";

	contents
}


fn generate_class_implementation(icalls: &mut HashSet<(String, Vec<String>)>, used_classes: &HashSet<&String>, class: &GodotClass) -> String {
	let mut contents = String::new();

	contents = contents + "#include \"" + strip_name(&class.name) + ".hpp" + "\"\n";

	contents = contents + "\n#include \"core/CoreTypes.hpp\"\n";

	contents = contents + "\n#include \"Godot.hpp\"\n\n";

	if class.instanciable {
		contents = contents + "#include \"ClassDB.hpp\"\n";
	}

	contents = contents + "\n#include \"__icalls.hpp\"\n\n\n";

	for used_class in used_classes {
		contents = contents + "#include \"" + strip_name(used_class) + ".hpp\"\n";
	}

	contents = contents + "\n\n";

	contents = contents + "namespace godot {\n\n";

	let core_obj_name = {
		let mut name = String::new();
		if class.singleton {
			name = name + "___static_object_" + strip_name(&class.name);
		} else {
			name = name + "this";
		};
		name
	};

	contents = contents + "\n\n\n";

	if class.singleton {
		contents = contents + "static godot_object *" + core_obj_name.as_str() + ";\n\n\n\n\n";
	}


	if class.singleton {
		contents = contents + "void " + strip_name(&class.name) + "::___singleton_init()\n{\n\t"
			+ core_obj_name.as_str() + " = godot_global_get_singleton(\"" + strip_name(&class.name) + "\");\n}\n\n";
	}


	// default constructor

	{
		contents = contents + strip_name(&class.name) + " *" + strip_name(&class.name) + "::_new()\n{\n";
		contents = contents + "\tgodot_class_constructor constructor = godot_get_class_constructor(\"" + class.name.as_str() + "\");\n";
		contents = contents + "\tif (!constructor) { return nullptr; }\n";
		contents = contents + "\treturn (" + strip_name(&class.name) + " *) constructor();\n";
		contents = contents + "}\n\n";
	}


	// pointer constructor
	// {
	// 	contents = contents + "" + strip_name(&class.name) + "::" + strip_name(&class.name) + "(godot_object *ptr)\n{\n";
	// 	contents = contents + "\t__core_object = ptr;\n";
	// 	contents = contents + "}\n\n\n";
	// }

	// Object constructor
	// if !class.singleton {
	// 	contents = contents + "" + strip_name(&class.name) + "::" + strip_name(&class.name) + "(const Object *ptr)\n{\n";
	// 	contents = contents + "\t__core_object = ?;\n";
	// 	contents = contents + "}\n\n\n";
	//
	// 	contents = contents + "" + strip_name(&class.name) + "::" + strip_name(&class.name) + "(const Variant& obj)\n{\n";
	// 	contents = contents + "\t__core_object = ((Object) obj).__core_object;\n";
	// 	contents = contents + "}\n\n\n";
	// }

	if class.name != "Object" {
		contents = contents + "void " + strip_name(&class.name) + "::" + "_init()\n{\n";
		contents = contents + "\t\n";
		contents = contents + "}\n\n";
	}


	contents += "\n\n";

	for method in &class.methods {
		contents = contents + strip_name(&method.return_type) + (if !is_core_type(&method.return_type) && !is_primitive(&method.return_type) { " *" } else { " " }) + strip_name(&class.name) + "::" + escape_cpp(&method.name) + "(";

		for (i, argument) in (&method.arguments).iter().enumerate() {
			if !is_primitive(&argument._type) && !is_core_type(&argument._type) {
				contents = contents + "const " + argument._type.as_str() + " *";
			} else {
				contents = contents + "const " + argument._type.as_str() + " ";
			}

			contents = contents + escape_cpp(&argument.name);
			if i != method.arguments.len() - 1 {
				contents += ", ";
			}
		}

		if method.has_varargs {
			if method.arguments.len() > 0 {
				contents += ", ";
			}
			contents = contents + "const Array& __var_args";
		}

		contents = contents + ")" + if method.is_const && !class.singleton { " const" } else { "" } + "\n{\n";


		if class.singleton {
			contents = contents + "\tif (" + core_obj_name.as_str() + " == 0) {\n";
			contents = contents + "\t\t___singleton_init();\n";
			contents = contents + "\t}\n\n";
		}

		if method.is_virtual || method.has_varargs {

			contents = contents + "\tArray __args;\n";

			// fill in the args
			for arg in &method.arguments {
				contents = contents + "\t__args.append(" + escape_cpp(&arg.name) + ");\n";
			}

			if method.has_varargs {
				contents = contents + "\tfor (int i = 0; i < __var_args.size(); i++) {\n";
				contents = contents + "\t\t__args.append(__var_args[i]);\n";
				contents = contents + "\t}\n";
			}

			contents = contents + "\t";

			if method.return_type != "void" {
				contents = contents + "return ";

				if !is_primitive(&method.return_type) && !is_core_type(&method.return_type) {
					contents = contents + "(" + strip_name(&method.return_type) + " *) (Object *) ";
				}
			}

			contents = contents + "((Object *) " + core_obj_name.as_str() + ")->callv(\"" + method.name.as_str() + "\", __args);\n";
		} else {
			contents = contents + "\tstatic godot_method_bind *mb = NULL;\n"
				+ "\tif (mb == NULL) {\n"
				+ "\t\tmb = godot_method_bind_get_method(\"" + class.name.as_str() + "\", \"" + method.name.as_str() + "\");\n"
				+ "\t}\n\t";


			if method.return_type != "void" {
				contents = contents + "return ";
				if !is_primitive(&method.return_type) && !is_core_type(&method.return_type) {
					contents = contents + "(" + strip_name(&method.return_type) + " *) ";
				}
			}

			let mut args = Vec::new();

			fn get_icall_type_name(t: &String) -> String {
				if is_core_type(t) || is_primitive(t) {
					t.clone()
				} else {
					t.clone()
				}
			}

			for arg in &method.arguments {
				args.push(get_icall_type_name(&arg._type));
			}

			let icallsig = (get_icall_type_name(&method.return_type), args);

			let name = get_icall_name(&icallsig);

			icalls.insert(icallsig);


			contents = contents + name.as_str() + "(mb, (godot_object *) " + core_obj_name.as_str();

			for arg in &method.arguments {
				contents = contents + ", " + escape_cpp(&arg.name);
			}

			// if !is_primitive(&method.return_type) && !is_core_type(&method.return_type) {
			// 	contents = contents + ")";
			// }
			contents = contents + ");\n";
		}

		contents = contents + "}\n\n";
	}

	// if class.instanciable {

	// 	contents = contents + strip_name(&class.name) + " " + strip_name(&class.name) + "::__new() {\n";
	// 	contents = contents + "\tObject ptr = ClassDB::instance(\"" + class.name.as_str() + "\");\n";
	// 	contents = contents + "\treturn ptr;\n";
	// 	contents = contents + "}\n\n";

	// 	contents = contents + "void " + strip_name(&class.name) + "::__destroy() {\n";
	// 	contents = contents + "\tgodot_object_destroy(__core_object);\n";
	// 	contents = contents + "}\n\n\n";

		/* if class.base_class == "" {
			// Object
			contents = contents + "Variant::operator Object()const {\n\n";

			contents = contents + "\treturn Object(godot_variant_as_object(&_godot_variant));\n\n";

			contents = contents + "}\n\n";
		} */
	// }

	contents = contents + "}\n";

	contents
}

fn get_icall_name(sig: &(String, Vec<String>)) -> String {

	let &(ref ret, ref args) = sig;

	let mut name = String::new();

	name = name + "___godot_icall_";

	name = name + strip_name(&ret);

	for arg in args {
		name = name + "_" + strip_name(&arg);
	}

	name
}

fn get_icall_name_ref(sig: (&String, &Vec<String>)) -> String {

	let (ref ret, args) = sig;

	let mut name = String::new();

	name = name + "___godot_icall_";

	name = name + strip_name(&ret);

	for arg in args {
		name = name + "_" + strip_name(&arg);
	}

	name
}

fn generate_icall_header(icalls: &HashSet<(String, Vec<String>)>) -> String {

	fn return_type(t: &String) -> String {
		if is_primitive(t) || is_core_type(t) {
			t.clone()
		} else {
			let s = String::new() + t.as_str() + " *";
			s
		}
	}


	let mut contents = String::new();

	contents = contents + "#ifndef __ICALLS_H\n";
	contents = contents + "#define __ICALLS_H\n\n\n";

	contents = contents + "#include <godot.h>\n\n\n";

	contents = contents + "#include \"core/CoreTypes.hpp\"\n";
	// contents = contents + "#include \"Object.hpp\"\n\n\n";

	let mut types_used = HashSet::new();

	for &(ref ret, ref args) in icalls {
		if !is_primitive(ret) && !is_core_type(ret) {
			types_used.insert(ret.clone());
		}
		for arg in args {
			if !is_core_type(&arg) && !is_primitive(&arg) {
				types_used.insert(arg.clone());
			}
		}
	}

	for ref type_ in types_used {
		contents = contents + "#include \"" + strip_name(type_) + ".hpp\"\n\n\n";
	}

	contents = contents + "using namespace godot;\n\n\n";

	for &(ref ret, ref args) in icalls {
		contents = contents + return_type(ret).as_str() + " " + get_icall_name_ref((ret, args)).as_str() + "(godot_method_bind *mb, godot_object *inst";
		for arg in args {
			contents = contents + ", ";
			if is_core_type(&arg) {
			// if !is_primitive(&arg) {
				contents = contents + "const " + arg.as_str() + "& ";
			} else if is_primitive(&arg) {
				contents = contents + "const " + arg.as_str() + " ";
			} else {
				contents = contents + "const " + arg.as_str() + " *";
			}
		}
		contents = contents + ");\n";
	}

	contents = contents + "#endif";

	contents
}

fn generate_icall_implementation(class_api: &Vec<GodotClass>, icalls: &HashSet<(String, Vec<String>)>) -> String {

	fn return_type(t: &String) -> String {
		if is_primitive(t) || is_core_type(t) {
			t.clone()
		} else {
			let s = String::new() + t.as_str() + " *";
			s
		}
	}

	let is_reference = |name: &String| {
		for class in class_api {
			if class.name.as_str() == name.as_str() {
				return class.is_reference;
			}
		}
		false
	};

	let mut contents = String::new();

	contents = contents + "#include \"__icalls.hpp\"\n";

	contents = contents + "#include <godot.h>\n\n\n";

	contents = contents + "#include \"core/CoreTypes.hpp\"\n";
	contents = contents + "#include \"Object.hpp\"\n\n\n";

	contents = contents + "using namespace godot;\n\n\n";

	for &(ref ret, ref args) in icalls {
		contents = contents + return_type(ret).as_str() + " " + get_icall_name_ref((ret, args)).as_str() + "(godot_method_bind *mb, godot_object *inst";
		let mut i = 0;
		for arg in args {
			contents = contents + ", ";
			if is_core_type(&arg) {
				// if !is_primitive(&arg) {
				contents = contents + "const " + arg.as_str() + "& ";
			} else if is_primitive(&arg) {
				contents = contents + "const " + arg.as_str() + " ";
			} else {
				contents = contents + "const " + arg.as_str() + " *";
			}
			contents = contents + "arg" + i.to_string().as_str();
			i = i + 1;
		}
		contents = contents + ")\n";

		contents = contents + "{\n";

		if ret != "void" {
			contents = contents + "\t" + strip_name(ret) + if !is_core_type(ret) && !is_primitive(ret) { " *" } else { "" } + " ret;\n";
			if !is_core_type(ret) && !is_primitive(ret) && is_reference(ret) {
				println!("{} is ref", ret);
				contents = contents + "\t" + "ret = " + strip_name(ret) + "::_new();\n";
			}
		}

		contents = contents + "\tconst void *args[" + if args.len() == 0 { "1" } else { "" } + "] = {\n";

		let mut j = 0;
		for arg in args {
			contents = contents + "\t\t";
			if is_primitive(arg) {
				contents = contents + "&arg" + j.to_string().as_str();
			} else if is_core_type(arg) {
				contents = contents + "(void *) &arg" + j.to_string().as_str();
			} else {
				contents = contents + "(void *) arg" + j.to_string().as_str();
			}
			contents = contents + ",\n";
			j = j + 1;
		}

		contents = contents + "\t};\n";

		contents = contents + "\tgodot_method_bind_ptrcall(mb, inst, args, " + if ret == "void" { "NULL" } else { "&ret" } + ");\n";

		if !is_primitive(ret) && !is_core_type(ret) {
			contents = contents + "\treturn ret;\n";
		} else if ret != "void" {
			contents = contents + "\treturn ret;\n";
		}

		contents = contents + "}\n\n";
	}

	// contents = contents + "#endif";

	contents
}


fn is_core_type(name: &String) -> bool {
	let core_types = vec!["Array",
	                      "Basis",
	                      "Color",
	                      "Dictionary",
	                      "Error",
	                      "Image",
	                      "InputEvent",
	                      "NodePath",
	                      "Plane",
	                      "PoolByteArray",
	                      "PoolIntArray",
	                      "PoolRealArray",
	                      "PoolStringArray",
	                      "PoolVector2Array",
	                      "PoolVector3Array",
	                      "PoolColorArray",
	                      "Quat",
	                      "Rect2",
	                      "Rect3",
	                      "RID",
	                      "String",
	                      "Transform",
	                      "Transform2D",
	                      "Variant",
	                      "Vector2",
	                      "Vector3"];
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
		"bool"  => "_bool",
		"int"   => "_int",
		"default" => "_default",
		"case"  => "_case",
		"switch" => "_switch",
		"export" => "_export",
		"template" => "_template",
		"new"   => "new_",
		x       => x
	}
}