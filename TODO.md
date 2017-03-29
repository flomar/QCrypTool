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

- Extend the Editor implementation: Right now there's a lot of functionality missing, and the "Edit" menu has no effect whatsoever yet.
- ~~Add default database to the installer~~ and implement a backup system: During installation the existing database should be backed up (i.e. "QCrypToolDatabase.sqlite.backup[TIMESTAMP]") and then the user should be asked how to proceed with the changed data when he first runs the newly installed version.
- Implement "CertificateStore" functionality. This way we'll have a vertical prototype to test the OpenSSL abstraction layer.

## Known Bugs

- Executing QCrypTool outside of an installed environment (as in: created through a self-extracting installer executable) can be tricky as all the files required for running QCrypTool which have been assembled during the release process don't exist where the QCrypTool executable expects them to be. FIX THIS ASAP!!!

## Short-Term Roadmap

- Integrate OpenSSL on all platforms (TODO: MacOS).
- Make QCrypTool run on all platforms (TODO: MacOS).
- Make QCrypTool installable on all platforms (TODO: MacOS).
- [WIP]: Apply existing scaling system to all future dialogs.
- [WIP] Extend QtAssistant-based context help.
- [WIP] Extend the DEVELOPERS.md document.
- Decide on a technology for the tutorials/demonstrations: Qt or QML.

## Long-Term Roadmap

- Implement 64bit Editor: Due to limitations in Qt's QTextEdit and QAbstractScrollArea classes, the current Editor supports 32bit only for now (files up to 2GB). A 64bit-capable Editor implementation should feature the same back-end for text and hex, and it should implement a caching mechanism by operating on blocks/chunks of the underlying file.
