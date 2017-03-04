# QCrypTool TODOs

This document contains the most important TODOs for the project.

## Overall Status (March 2017)

- QCrypTool can be built and installed under Linux and Windows (TODO: MacOS).
- QCrypTool supports application-wide and platform-independent scaling system.
- QCrypTool context help is based on QtAssistant.
- The platform-dependent code has been abstracted into one single file in the Utilities module.

## Known Bugs

- ~~The installer needs a lot of work (see BE 2017-02-27 1755): For example, the installer adheres to the OS system locale while QCrypTool itself doesn't, it always starts in English.~~
- ~~The "UpdateBuildInformation.py" script doesn't seem to do its job, just check out the main window title which should display the current version number. The "CreateInstaller.py" script does correctly process and display the current version though.~~

## Short-Term Roadmap

- [WIP]: Integrate an up-to-date OpenSSL library required for the OpenSSL-based crypto layer (TODO: MacOS)
- ~~I18N is based on QtLinguist language files. The solution is working fine for English and German, switching back and forth works seamlessly.~~
- Add a DEVELOPERS.md document to guide contributors through the build process on all supported platforms.
- [WIP] Extend QtAssistant-based context help. ~~Integrate an HTML browser for browsing the to-be-created content of the context-sensitive help system.~~
- Develop a QTextEdit-derived ASCII editor and a custom HEX editor, both preferably with support for files larger than 2GB.
- Decide on a technology for the tutorials/demonstrations: Qt or QML.
- [WIP]: Apply existing scaling system to all future dialogs. ~~Decide whether QCrypTool shall provide a fully-scalable user interface. The implementation itself should not be complicated, but it would make designing the dialogs a lot more tedious and time-consuming.~~
- [WIP]: Find a platform-independent solution for the installer (TODO: MacOS)

## Build Requirements

- Qt 5.8+ including QtInstallerFramework 2.0+
- Python 2.7+ (needs to be in PATH)
- Git (needs to be in PATH)
- To successfully build and later on deploy "CrypTool.pro" (which is only one of the future sub projects of QCrypTool, think AESTool and NumberShark), developers need to create a "build" directory parallel to the "trunk" directory. In this "build" directory, QCrypTool expects a "CrypTool/debug" and a "CrypTool/release" folder for the debug and the release builds (TODO: provide a tutorial).
- To automate "UpdateBuildInformation.py" PREBUILD and POSTBUILD, developers need to add custom build steps to the QtCreator project (TODO: provide a tutorial).
