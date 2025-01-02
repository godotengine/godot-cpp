import os
import pathlib


def exists(env):
    return True


def options(opts):
    pass


def generate(
    target,
    *,
    env,
    source,
    min_macos_version="10.12",
    min_ios_version="12.0",
    plist_entries=None,
):
    """
    Generates an Apple .framework folder, containing the binary and metadata.
    Framework structures are required to be able to sign binaries.
    Signing binaries is required to avoid the apple gatekeeper, and to be accepted into the App Store.
    See https://developer.apple.com/library/archive/documentation/MacOSX/Conceptual/BPFrameworks/Concepts/FrameworkAnatomy.html

    :param target: Folder name of the framework, usually ending in `.framework`.
    :param env: The environment.
    :param source: A list of binary sources to generate.
    :param min_macos_version: The minimum macOS version supported by the framework, if the platform is macos.
    :param min_ios_version: The minimum iOS version supported by the framework, if the platform is iOS.
    :param plist_entries: Additional keys to send to the plist generator.
    :return: Targets for framework creation, where the first item is the binary generator.
    """
    if env["platform"] == "macos":
        dt_platform_name = "macosx"
        min_os_part = f"LSMinimumSystemVersion={min_macos_version}"
    elif env["platform"] == "ios":
        dt_platform_name = "iphoneos"
        min_os_part = f"MinimumOSVersion={min_ios_version}"
    else:
        raise ValueError("Unsupported platform.")

    framework_path = pathlib.Path(target)
    assert framework_path.suffix == ".framework"
    framework_name = framework_path.name.removesuffix(".framework")

    parent_path = pathlib.Path(__file__).parent
    plist_creation_script_path = (parent_path / "create_apple_framework_plist.sh").relative_to(os.getcwd())
    plist_command = f"{plist_creation_script_path} $TARGET --entry CFBundleExecutable={framework_name} --entry DTPlatformName={dt_platform_name} --entry {min_os_part}"
    if plist_entries:
        for key, value in plist_entries.items():
            plist_command += f' --entry "{key}={value}"'

    return [
        # Create the binary itself.
        env.Command(
            str(framework_path / framework_name),
            source,
            action="lipo -create $SOURCE -output $TARGET",
        ),
        # Create the Info.plist.
        env.Command(
            str(framework_path / "Resources" / "Info.plist"),
            [str(plist_creation_script_path)],
            action=plist_command,
        ),
    ]
