# QCrypTool.pro

QT += core gui svg widgets

CONFIG += c++11

TEMPLATE = app

INCLUDEPATH += Sources $$OUT_PWD

TARGET = QCrypTool

HEADERS += \
Sources/QCT.h \
Sources/QCTTranslation.h \
Sources/Core/Application.h \
Sources/Core/MainWindow.h \
Sources/Core/Dialog.h \
Sources/Core/HelpSystem.h \
Sources/Core/Utilities.h \
Sources/Core/Utilities/UtilitiesDateAndTime.h \
Sources/Core/Utilities/UtilitiesGraphics.h \
Sources/Core/Cryptography.h \
Sources/Core/Cryptography/CryptographyOpenSSL.h \
Sources/Core/Cryptography/CryptographyHash.h \
Sources/Core/Cryptography/CryptographySymmetric.h \
Sources/Core/Cryptography/CryptographyAsymmetric.h \
Sources/Core/Cryptography/CryptographyCertificates.h \
Sources/QCrypTool/QCrypTool.h \
Sources/QCrypTool/QCrypToolApplication.h \
Sources/QCrypTool/QCrypToolMainWindow.h \
Sources/QCrypTool/Dialogs/DialogAbout.h \
Sources/QCrypTool/Dialogs/DialogLanguage.h

SOURCES += \
Sources/QCT.cpp \
Sources/QCTTranslation.cpp \
Sources/Core/Application.cpp \
Sources/Core/MainWindow.cpp \
Sources/Core/Dialog.cpp \
Sources/Core/HelpSystem.cpp \
Sources/Core/Utilities.cpp \
Sources/Core/Utilities/UtilitiesDateAndTime.cpp \
Sources/Core/Utilities/UtilitiesGraphics.cpp \
Sources/Core/Cryptography.cpp \
Sources/Core/Cryptography/CryptographyOpenSSL.cpp \
Sources/Core/Cryptography/CryptographyHash.cpp \
Sources/Core/Cryptography/CryptographySymmetric.cpp \
Sources/Core/Cryptography/CryptographyAsymmetric.cpp \
Sources/Core/Cryptography/CryptographyCertificates.cpp \
Sources/QCrypTool/QCrypTool.cpp \
Sources/QCrypTool/QCrypToolApplication.cpp \
Sources/QCrypTool/QCrypToolMainWindow.cpp \
Sources/QCrypTool/Dialogs/DialogAbout.cpp \
Sources/QCrypTool/Dialogs/DialogLanguage.cpp

RESOURCES += \
Resources/QCT.qrc \
Resources/QCrypTool.qrc

FORMS += \
Resources/QCrypTool/QCrypToolMainWindow.ui \
Resources/QCrypTool/Dialogs/DialogAbout.ui \
Resources/QCrypTool/Dialogs/DialogLanguage.ui

# Linux-specific
unix:!macx {
# OpenSSL
# TODO/FIXME
# Linux Icon (KDE/GNOME)
# TODO/FIXME
}
# MacOS-specific
macx: {
# OpenSSL
# TODO/FIXME
# MacOS Icon
# TODO/FIXME
}
# Windows-specific
win32: {
# Windows
LIBS += -luser32
# OpenSSL
INCLUDEPATH += $$PWD/External/Windows/OpenSSL/include
LIBS += -L$$PWD/External/Windows/OpenSSL/lib -llibcrypto
LIBS += -L$$PWD/External/Windows/OpenSSL/lib -llibssl
# Windows Icon
RC_FILE = Resources/QCT/Icons/QCTLogo.rc
}
