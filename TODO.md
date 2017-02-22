# QCrypTool TODOs

This document contains the most important TODOs for the project.

## Short-Term Roadmap

- Integrate an up-to-date OpenSSL library required for the OpenSSL-based crypto layer.
- Check out whether the I18N functionality built into Qt is able to provide performant on-the-fly translation of the user interface. Using the built-in solution (in particular: the QtLinguist) might make it easier for translators to contribute.
- Add a DEVELOPERS.md document to guide contributors through the build process on all supported platforms.
- Integrate an HTML browser for browsing the to-be-created content of the context-sensitive help system.
- Develop a QTextEdit-derived ASCII editor and a custom HEX editor, both preferably with support for files larger than 2GB.
- Decide on a technology for the tutorials/demonstrations: Qt or QML.
- Decide whether QCrypTool shall provide a fully-scalable user interface. The implementation itself should not be complicated, but it would make designing the dialogs a lot more tedious and time-consuming.
- Find a platform-independent solution for the installer.
