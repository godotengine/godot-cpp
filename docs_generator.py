import hashlib
import zlib


def make_doc(dst, source, compression_str="Z_BEST_COMPRESSION"):
    g = open(dst, "w", encoding="utf-8")
    buf = ""
    docbegin = ""
    docend = ""
    for src_path in source:
        if not src_path.endswith(".xml"):
            continue
        with open(src_path, "r", encoding="utf-8") as f:
            content = f.read()
        buf += content

    buf = (docbegin + buf + docend).encode("utf-8")
    decomp_size = len(buf)

    buf = zlib.compress(buf, getattr(zlib, compression_str))

    g.write("/* THIS FILE IS GENERATED DO NOT EDIT */\n")
    g.write("\n")
    g.write("#include <godot_cpp/godot.hpp>\n")
    g.write("\n")

    g.write('static const char *_doc_data_hash = "' + hashlib.md5(buf).hexdigest() + '";\n')
    g.write("static const int _doc_data_uncompressed_size = " + str(decomp_size) + ";\n")
    g.write("static const int _doc_data_compressed_size = " + str(len(buf)) + ";\n")
    g.write("static const unsigned char _doc_data_compressed[] = {\n")
    for i in range(len(buf)):
        g.write("\t" + str(buf[i]) + ",\n")
    g.write("};\n")
    g.write("\n")

    g.write(
        "static godot::internal::DocDataRegistration _doc_data_registration(_doc_data_hash, _doc_data_uncompressed_size, _doc_data_compressed_size, _doc_data_compressed);\n"
    )
    g.write("\n")

    g.close()


# if ran as a script, use input args as:
#    sys.argv[1]    compression method
#    sys.argv[2]    destination file
#    sys.argv[3:]   .xml sources
if __name__ == "__main__":
    import sys

    make_doc(sys.argv[2], sys.argv[3:], compression_str=sys.argv[1])
