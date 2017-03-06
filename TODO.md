# QCrypTool TODOs

This document contains the most important TODOs for the project.

## Overall Status (March 2017)

- QCrypTool can be built and installed under Linux and Windows.
- QCrypTool supports an application-wide and platform-independent scaling system.
- QCrypTool context help is based on QtAssistant.
- QCrypTool internationalization is based on QtLinguist.
- QCrypTool stores its application data (such as settings, certificates, etc.) in a SQLITE database located in "$HOME/QCrypToolDatabase.sqlite".
- The platform-dependent code has been abstracted into one single file in the Utilities module.

## Urgent Issues

- Draft the DEVELOPERS.md document including all relevant information: How to set up the build environment, how to build the translation files, how to build the help files, and how to build an installer executable.
- ~~Add default database to the installer~~ and implement a backup system: During installation the existing database should be backed up (i.e. "QCrypToolDatabase.sqlite.backup[TIMESTAMP]") and then the user should be asked how to proceed with the changed data when he first runs the newly installed version.
- Implement "CertificateStore" functionality. This way we'll have a vertical prototype to test the OpenSSL abstraction layer.

## Known Bugs

- None. Well, none that I'm aware of.

## Short-Term Roadmap

- Make QCrypTool run on all platforms (TODO: MacOS).
- [WIP]: Find a platform-independent solution for the installer (TODO: MacOS)
- [WIP]: Integrate an up-to-date OpenSSL library required for the OpenSSL-based crypto layer (TODO: MacOS)
- [WIP]: Apply existing scaling system to all future dialogs.
- [WIP] Extend QtAssistant-based context help.
- Add a DEVELOPERS.md document to guide contributors through the build process on all supported platforms.
- Develop a QTextEdit-derived ASCII editor and a custom HEX editor, both preferably with support for files larger than 2GB.
- Decide on a technology for the tutorials/demonstrations: Qt or QML.

## Build Requirements

- Qt 5.8+ including QtInstallerFramework 2.0+
- Python 2.7+ (needs to be in PATH)
- Git (needs to be in PATH)
- To successfully build and later on deploy "CrypTool.pro" (which is only one of the future sub projects of QCrypTool, think AESTool and NumberShark), developers need to create a "build" directory parallel to the "trunk" directory. In this "build" directory, QCrypTool expects a "CrypTool/debug" and a "CrypTool/release" folder for the debug and the release builds (TODO: provide a tutorial).
- To automate "UpdateBuildInformation.py" PREBUILD and POSTBUILD, developers need to add custom build steps to the QtCreator project (TODO: provide a tutorial).
