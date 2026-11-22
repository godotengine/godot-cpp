# Generated C++ header documentation

Each version directory uses the exact Godot API version. Prerelease versions
also include their status, such as `4.7.0-beta`. The binding generator runs
offline with the inputs in the selected directory.

- `class_reference.zip` contains the upstream class-reference XML. The generator
  matches method signatures, property accessors, constructors, operators, and
  enum values before converting their descriptions to Markdown.
- `native_structures.json` contains notes verified against the matching engine
  source for native structures and their fields.
- A class-specific JSON file and XML file supply reviewed descriptions and C++
  examples. These take precedence over automatic text. The JSON records the
  source URL and the upstream Git blob.
- A class-specific JSON file with `"partial": true` can use the XML from the
  version archive and override individual declarations. Record reviewed engine
  sources and any differences from the XML in this file.

The `declarations` object maps an emitted C++ declaration, without indentation,
to an English `brief` and an `example` array of C++ lines. Use `register_virtuals`
for the protected registration template and `vararg:<internal signature>` for
the public variadic wrapper. The `xml` selector identifies the reviewed source.

The 4.7.0 archive contains unmodified XML from `doc/classes` and module
`doc_classes` directories in the [Godot 4.7-stable source archive](https://codeload.github.com/godotengine/godot/zip/refs/tags/4.7-stable).
The archive includes the Godot Engine MIT license. The upstream source ZIP
used for this snapshot has SHA-256
`c1a3329bd79c38fd2a65e261a6744f96914e5cc6ec3ff56c886a8c10656feb1b`.
