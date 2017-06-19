#!python

import json

# comment.

def generate_bindings(path):
    
    classes = json.load(open(path))
    
    icalls = set()
    
    for c in classes:
        # print c['name']
        used_classes = get_used_classes(c)
        
        header = generate_class_header(used_classes, c)
        
        impl = generate_class_implementation(icalls, used_classes, c)
        
        header_file = open("include/" + strip_name(c["name"]) + ".hpp", "w+")
        header_file.write(header)
        
        source_file = open("src/" + strip_name(c["name"]) + ".cpp", "w+")
        source_file.write(impl)
    
    
    icall_header_file = open("src/__icalls.hpp", "w+")
    icall_header_file.write(generate_icall_header(icalls))
    
    icall_source_file = open("src/__icalls.cpp", "w+")
    icall_source_file.write(generate_icall_implementation(icalls))

        
        

def generate_class_header(used_classes, c):

    source = []
    source.append("#ifndef GODOT_CPP_" + strip_name(c["name"]).upper() + "_HPP")
    source.append("#define GODOT_CPP_" + strip_name(c["name"]).upper() + "_HPP")
    source.append("")
    
    
    source.append("#if defined(_WIN32) && defined(_GD_CPP_BINDING_IMPL)")
    source.append("#  define GD_CPP_BINDING_API __declspec(dllexport)")
    source.append("#elif defined(_WIN32)")
    source.append("#  define GD_CPP_BINDING_API __declspec(dllimport)")
    source.append("#else")
    source.append("#  define GD_CPP_BINDING_API")
    source.append("#endif");
    source.append("")
    source.append("")
    source.append("")
    source.append("")
    
    source.append("#include <godot.h>")
    source.append("")
    
    
    source.append("#include <CoreTypes.hpp>")
    
    if c["base_class"] != "":
        source.append("#include <" + strip_name(c["base_class"]) + ".hpp>")
        
        
    
    source.append("namespace godot {")
    source.append("")
    
    
    for used_type in used_classes:
        source.append("class " + strip_name(used_type) + ";")
    
    
    source.append("")
    
    
    # generate the class definition here
    source.append("class GD_CPP_BINDING_API " + strip_name(c["name"]) + ("" if c["base_class"] == "" else (" : public " + strip_name(c["base_class"])) ) + " {")
    
    source.append("public:")
    source.append("")
    
    # ___get_class_name
    source.append("\tstatic inline char *___get_class_name() { return (char *) \"" + strip_name(c["name"]) + "\"; }")
    
    source.append("\t// constants")
    
    for name in c["constants"]:
        source.append("\tconst static int " + name + " = " + str(c["constants"][name]) + ";")

    
    if c["instanciable"]:
        source.append("\tstatic void *operator new(size_t);")
        
        source.append("\tstatic void operator delete(void *);")
    
    source.append("")
    source.append("\n\t// methods")
    
    for method in c["methods"]:
        
        method_signature = ""
        
        method_signature += "static " if c["singleton"] else ""
        method_signature += strip_name(method["return_type"])
        method_signature += " *" if is_class_type(method["return_type"]) else " "
        method_signature += escape_cpp(method["name"]) + "("
        
        
        has_default_argument = False
        
        for i, argument in enumerate(method["arguments"]):
            method_signature += "const " + argument["type"] + (" *" if is_class_type(argument["type"]) else " ")
            method_signature += escape_cpp(argument["name"])
            
            
            # default arguments
            def escape_default_arg(_type, default_value):
                if _type == "Color":
                    return "Color(" + default_value + ")"
                if _type == "bool" or _type == "int":
                    return default_value.lower()
                if _type == "Array":
                    return "Array()"
                if _type in ["PoolVector2Array", "PoolStringArray", "PoolVector3Array", "PoolColorArray"]:
                    return _type + "()"
                if _type == "Vector2":
                    return "Vector2" + default_value
                if _type == "Vector3":
                    return "Vector3" + default_value
                if _type == "Transform":
                    return "Transform()"
                if _type == "Transform2D":
                    return "Transform2D()"
                if _type == "Rect2":
                    return "Rect2" + default_value
                if _type == "Variant":
                    return "Variant()" if default_value == "Null" else default_value
                if _type == "String":
                    return "\"" + default_value + "\""
                if _type == "RID":
                    return "RID()"
                
                if default_value == "Null" or default_value == "[Object:null]":
                    return "nullptr"
                    
                return default_value
                    
            
            
            
            if argument["has_default_value"] or has_default_argument:
                method_signature += " = " + escape_default_arg(argument["type"], argument["default_value"])
                has_default_argument = True
            
            
            
            if i != len(method["arguments"]) - 1:
                method_signature += ", "
                
        if method["has_varargs"]:
            if len(method["arguments"]) > 0:
                method_signature += ", "
            method_signature += "const Array& __var_args = Array()"
            
        method_signature += ")" + (" const" if method["is_const"] and not c["singleton"] else "")
            

        source.append("\t" + method_signature + ";")
    
    
    source.append("};")
    source.append("")
    
    
    source.append("}")
    source.append("")
    
    
    
    source.append("#endif")
    
    
    return "\n".join(source)
 




def generate_class_implementation(icalls, used_classes, c):
    source = []
    source.append("#include <" + strip_name(c["name"]) + ".hpp>")
    source.append("")
    source.append("")
    
    source.append("#include <CoreTypes.hpp>")
    
    source.append("#include <Godot.hpp>")
    source.append("")
    
    
    source.append("#include \"__icalls.hpp\"")
    source.append("")
    source.append("")
    
    for used_class in used_classes:
        source.append("#include <" + strip_name(used_class) + ".hpp>")
    
    source.append("")
    source.append("")
    
    source.append("namespace godot {")
    
    
    core_object_name = ("___static_object_" + strip_name(c["name"])) if c["singleton"] else "this"
    
    
    source.append("")
    source.append("")
    
    if c["singleton"]:
        source.append("static godot_object *" + core_object_name + ";")
        source.append("")
        source.append("")
        
        # FIXME Test if inlining has a huge impact on binary size
        source.append("static inline void ___singleton_init()")
        source.append("{")
        source.append("\tif (" + core_object_name + " == nullptr) {")
        source.append("\t\t" + core_object_name + " = godot_global_get_singleton(\"" + c["name"] + "\");")
        source.append("\t}")
        source.append("}")
        
        source.append("")
        source.append("")
    
    
    
    if c["instanciable"]:
        source.append("void *" + strip_name(c["name"]) + "::operator new(size_t)")
        source.append("{")
        source.append("\treturn godot_get_class_constructor(\"" + c["name"] + "\")();")
        source.append("}")
        
        source.append("void " + strip_name(c["name"]) + "::operator delete(void *ptr)")
        source.append("{")
        source.append("\tgodot_object_destroy((godot_object *)ptr);")
        source.append("}")
    
    for method in c["methods"]:
        method_signature = ""
        
        method_signature += strip_name(method["return_type"])
        method_signature += " *" if is_class_type(method["return_type"]) else " "
        method_signature += strip_name(c["name"]) + "::" + escape_cpp(method["name"]) + "("
        
        for i, argument in enumerate(method["arguments"]):
            method_signature += "const " + argument["type"] + (" *" if is_class_type(argument["type"]) else " ")
            method_signature += escape_cpp(argument["name"])
            
            if i != len(method["arguments"]) - 1:
                method_signature += ", "
                
        if method["has_varargs"]:
            if len(method["arguments"]) > 0:
                method_signature += ", "
            method_signature += "const Array& __var_args"
            
        method_signature += ")" + (" const" if method["is_const"] and not c["singleton"] else "")
    
        source.append(method_signature + " {")
        
        
        
        if c["singleton"]:
            source.append("\t___singleton_init();")
        
        
        source.append("\tstatic godot_method_bind *mb = NULL;")
        source.append("\tif (mb == NULL) {")
        source.append("\t\tmb = godot_method_bind_get_method(\"" + c["name"] +"\", \"" + method["name"] + "\");")
        source.append("\t}")
        
        return_statement = ""
        
        if method["return_type"] != "void":
            return_statement += "return " + ("(" + strip_name(method["return_type"]) + " *) " if is_class_type(method["return_type"]) else "")
        
        def get_icall_type_name(name):
            if is_class_type(name):
                return "Object"
            return name
        
        
        
        if method["is_virtual"] or method["has_varargs"]:

            if len(method["arguments"]) != 0:
                source.append("\tVariant __given_args[" + str(len(method["arguments"])) + "];")
            
            for i, argument in enumerate(method["arguments"]):
                source.append("\tgodot_variant_new_nil((godot_variant *) &__given_args[" + str(i) + "]);")
                
            source.append("")
            
            
            for i, argument in enumerate(method["arguments"]):
                source.append("\t__given_args[" + str(i) + "] = " + escape_cpp(argument["name"]) + ";")
            
            source.append("")
            
            size = ""
            if method["has_varargs"]:
                size = "(__var_args.size() + " + str(len(method["arguments"])) + ")"
            else:
                size = "(" + str(len(method["arguments"])) + ")"
            
            source.append("\tgodot_variant **__args = (godot_variant **) alloca(sizeof(godot_variant *) * " + size + ");")
            
            source.append("")
            
            for i, argument in enumerate(method["arguments"]):
                source.append("\t__args[" + str(i) + "] = (godot_variant *) &__given_args[" + str(i) + "];")
                
            source.append("")
            
            if method["has_varargs"]:
                source.append("\tfor (int i = 0; i < __var_args.size(); i++) {")
                source.append("\t\t__args[i + " + str(len(method["arguments"])) + "] = (godot_variant *) &((Array &) __var_args)[i];")
                source.append("\t}")
           
            source.append("")
            
            source.append("\tVariant __result;")
            source.append("\t*(godot_variant *) &__result = godot_method_bind_call(mb, (godot_object *) " + core_object_name + ", (const godot_variant **) __args, " + size + ", nullptr);")
            
            source.append("")
            
            
            for i, argument in enumerate(method["arguments"]):
                source.append("\tgodot_variant_destroy((godot_variant *) &__given_args[" + str(i) + "]);")
                
            source.append("")
            
            if method["return_type"] != "void":
                cast = ""
                if is_class_type(method["return_type"]):
                    cast += "(" + strip_name(method["return_type"]) + " *) (Object *) "
                source.append("\treturn " + cast + "__result;")
            
            
            
        else:
        
            args = []
            for arg in method["arguments"]:
                args.append(get_icall_type_name(arg["type"]))
            
            icall_ret_type = get_icall_type_name(method["return_type"])
            
            icall_sig = tuple((icall_ret_type, tuple(args)))
            
            icalls.add(icall_sig)
            
            icall_name = get_icall_name(icall_sig)
            
            return_statement += icall_name + "(mb, (godot_object *) " + core_object_name
            
            for arg in method["arguments"]:
                return_statement += ", " + escape_cpp(arg["name"])
                
            return_statement += ")"
            
            source.append("\t" + return_statement + ";")
        
        source.append("}")
        source.append("")

    
    
    source.append("}")
    
    
    return "\n".join(source)





def generate_icall_header(icalls):
    
    source = []
    source.append("#ifndef GODOT_CPP__ICALLS_HPP")
    source.append("#define GODOT_CPP__ICALLS_HPP")
    
    source.append("")
    
    source.append("#include <godot.h>")
    source.append("")
    source.append("")
    
    source.append("#include <CoreTypes.hpp>")
    source.append("#include <Object.hpp>")
    source.append("")
    source.append("")
    
    source.append("namespace godot {")
    source.append("")
    
    for icall in icalls:
        ret_type = icall[0]
        args = icall[1]
        
        method_signature = ""
        
        method_signature += return_type(ret_type) + get_icall_name(icall) + "(godot_method_bind *mb, godot_object *inst"
        
        for arg in args:
            method_signature += ", const "
            
            if is_core_type(arg):
                method_signature += arg + "&"
            elif is_primitive(arg):
                method_signature += arg
            else:
                method_signature += "Object *"
        
        method_signature += ");"
        
        source.append(method_signature)
    
    source.append("")
    
    source.append("}")
    source.append("")
    
    source.append("#endif")
    
    return "\n".join(source)
    

def generate_icall_implementation(icalls):
    source = []
    source.append("#include \"__icalls.hpp\"")
    
    source.append("")
    
    source.append("#include <godot.h>")
    source.append("")
    source.append("")
    
    source.append("#include <CoreTypes.hpp>")
    source.append("#include <Object.hpp>")
    source.append("")
    source.append("")
    
    source.append("namespace godot {")
    source.append("")
    
    for icall in icalls:
        ret_type = icall[0]
        args = icall[1]
        
        method_signature = ""
        
        method_signature += return_type(ret_type) + get_icall_name(icall) + "(godot_method_bind *mb, godot_object *inst"
        
        for i, arg in enumerate(args):
            method_signature += ", const "
            
            if is_core_type(arg):
                method_signature += arg + "& "
            elif is_primitive(arg):
                method_signature += arg + " "
            else:
                method_signature += "Object *"
            
            method_signature += "arg" + str(i)
        
        method_signature += ")"
        
        source.append(method_signature + " {")
        
        if ret_type != "void":
            source.append("\t" + strip_name(ret_type) + (" *" if is_class_type(ret_type) else " ") + "ret;")
            if is_class_type(ret_type):
                source.append("\tret = nullptr;")
        
        
        source.append("\tconst void *args[" + ("1" if len(args) == 0 else "") + "] = {")
        
        for i, arg in enumerate(args):
            
            wrapped_argument = "\t\t"
            if is_primitive(arg) or is_core_type(arg):
                wrapped_argument += "(void *) &arg" + str(i)
            else:
                wrapped_argument += "(void *) arg" + str(i)
            
            wrapped_argument += ","
            source.append(wrapped_argument)
        
        source.append("\t};")
        source.append("")
        
        source.append("\tgodot_method_bind_ptrcall(mb, inst, args, " + ("nullptr" if ret_type == "void" else "&ret") + ");")
        
        if ret_type != "void":
            source.append("\treturn ret;")
        
        source.append("}")
    
    source.append("}")
    source.append("")
    
    return "\n".join(source)



















def return_type(t):
    if is_class_type(t):
        return "Object *"
    return t + " "


def get_icall_name(sig):
    ret_type = sig[0]
    args = sig[1]
    
    name = "___godot_icall_"
    name += strip_name(ret_type)
    for arg in args:
        name += "_" + strip_name(arg)
    
    return name






def get_used_classes(c):
    classes = []
    for method in c["methods"]:
        if is_class_type(method["return_type"]) and not (method["return_type"] in classes):
            classes.append(method["return_type"])
        
        for arg in method["arguments"]:
            if is_class_type(arg["type"]) and not (arg["type"] in classes):
                classes.append(arg["type"])
    return classes








def strip_name(name):
    if name[0] == '_':
        return name[1:]
    return name


def is_class_type(name):
    return not is_core_type(name) and not is_primitive(name)

def is_core_type(name):
    core_types = ["Array",
                  "Basis",
                  "Color",
                  "Dictionary",
                  "Error",
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
                  "Vector3"]
    return name in core_types




def is_primitive(name):
    core_types = ["int", "bool", "real", "float", "void"]
    return name in core_types

def escape_cpp(name):
    escapes = {
        "class":    "_class",
        "char":     "_char",
        "short":    "_short",
        "bool":     "_bool",
        "int":      "_int",
        "default":  "_default",
        "case":     "_case",
        "switch":   "_switch",
        "export":   "_export",
        "template": "_template",
        "new":      "new_"
    }
    if name in escapes:
        return escapes[name]
    return name
