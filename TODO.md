# QCrypTool TODOs

This document contains the most important TODOs for the project.

## Short-Term Roadmap

- [WIP]: Integrate an up-to-date OpenSSL library required for the OpenSSL-based crypto layer (TODO: Windows-only for now).
- [WIP]: I18N is based on the QtLinguist language files, working fine for English and German for now. However, the entries in the combo box of the language dialog need to be translated as well, so there needs to be a mapping of some sort.
- Add a DEVELOPERS.md document to guide contributors through the build process on all supported platforms.
- Integrate an HTML browser for browsing the to-be-created content of the context-sensitive help system.
- Develop a QTextEdit-derived ASCII editor and a custom HEX editor, both preferably with support for files larger than 2GB.
- Decide on a technology for the tutorials/demonstrations: Qt or QML.
- Decide whether QCrypTool shall provide a fully-scalable user interface. The implementation itself should not be complicated, but it would make designing the dialogs a lot more tedious and time-consuming.
- [WIP]: Find a platform-independent solution for the installer (TODO: Windows-only for now).

## Build Requirements

- Qt 5.8+ including QtInstallerFramework 2.0+
- Python 2.7+ (needs to be in PATH)
- Git (needs to be in PATH)
- In order to automate "UpdateBuildInformation.py" PREBUILD and POSTBUILD, developers need to add custom build steps to the QtCreator project (TODO: provide a tutorial).
