# godot-headers

This repository contains C headers for
[**Godot Engine**](https://github.com/godotengine/godot)'s *GDNative Extensions* API.

## Updating Headers

If the current branch is not up-to-date for your needs, or if you want to sync
the headers with your own modified version of Godot, here is the update
procedure used to sync this repository with upstream releases:

- Compile [Godot Engine](https://github.com/godotengine/godot) at the specific
  version/commit which you are using.
- Use the compiled executable to generate the `extension_api.json` file with:
  `godot --dump-extension-api extension_api.json`
- Copy the file `core/extension/gdnative_interface.h` to `godot`
