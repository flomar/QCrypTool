# QCrypTool.pro

QT += core gui sql svg widgets

CONFIG += c++11

TEMPLATE = app

INCLUDEPATH += Sources $$OUT_PWD

TARGET = QCrypTool

HEADERS += \
Sources/QCT.h \
Sources/QCTDatabaseSystem.h \
Sources/QCTHelpSystem.h \
Sources/QCTScalingSystem.h \
Sources/QCTTranslationSystem.h \
Sources/Core/Application.h \
Sources/Core/MainWindow.h \
Sources/Core/Dialog.h \
Sources/Core/Utilities.h \
Sources/Core/Utilities/UtilitiesDateAndTime.h \
Sources/Core/Utilities/UtilitiesGraphics.h \
Sources/Core/Utilities/UtilitiesMessageBoxes.h \
Sources/Core/Utilities/UtilitiesPlatformCode.h \
Sources/Core/Cryptography.h \
Sources/Core/Cryptography/CryptographyOpenSSL.h \
Sources/Core/Cryptography/CryptographyHash.h \
Sources/Core/Cryptography/CryptographySymmetric.h \
Sources/Core/Cryptography/CryptographyAsymmetric.h \
Sources/Core/Cryptography/CryptographyCertificates.h \
Sources/QCrypTool/QCrypTool.h \
Sources/QCrypTool/QCrypToolApplication.h \
Sources/QCrypTool/QCrypToolMainWindow.h \
Sources/QCrypTool/Dialogs/DialogCertificateStore.h \
Sources/QCrypTool/Dialogs/DialogLanguage.h \
Sources/QCrypTool/Dialogs/DialogScaling.h \
Sources/QCrypTool/Dialogs/DialogAboutQCrypTool.h

SOURCES += \
Sources/QCT.cpp \
Sources/QCTDatabaseSystem.cpp \
Sources/QCTHelpSystem.cpp \
Sources/QCTScalingSystem.cpp \
Sources/QCTTranslationSystem.cpp \
Sources/Core/Application.cpp \
Sources/Core/MainWindow.cpp \
Sources/Core/Dialog.cpp \
Sources/Core/Utilities.cpp \
Sources/Core/Utilities/UtilitiesDateAndTime.cpp \
Sources/Core/Utilities/UtilitiesGraphics.cpp \
Sources/Core/Utilities/UtilitiesMessageBoxes.cpp \
Sources/Core/Utilities/UtilitiesPlatformCode.cpp \
Sources/Core/Cryptography.cpp \
Sources/Core/Cryptography/CryptographyOpenSSL.cpp \
Sources/Core/Cryptography/CryptographyHash.cpp \
Sources/Core/Cryptography/CryptographySymmetric.cpp \
Sources/Core/Cryptography/CryptographyAsymmetric.cpp \
Sources/Core/Cryptography/CryptographyCertificates.cpp \
Sources/QCrypTool/QCrypTool.cpp \
Sources/QCrypTool/QCrypToolApplication.cpp \
Sources/QCrypTool/QCrypToolMainWindow.cpp \
Sources/QCrypTool/Dialogs/DialogCertificateStore.cpp \
Sources/QCrypTool/Dialogs/DialogLanguage.cpp \
Sources/QCrypTool/Dialogs/DialogScaling.cpp \
Sources/QCrypTool/Dialogs/DialogAboutQCrypTool.cpp

RESOURCES += \
Resources/QCT.qrc \
Resources/QCrypTool.qrc

FORMS += \
Resources/QCrypTool/QCrypToolMainWindow.ui \
Resources/QCrypTool/Dialogs/DialogCertificateStore.ui \
Resources/QCrypTool/Dialogs/DialogLanguage.ui \
Resources/QCrypTool/Dialogs/DialogScaling.ui \
Resources/QCrypTool/Dialogs/DialogAboutQCrypTool.ui

# Linux-specific
unix:!macx {
# Linux
LIBS += -lX11
# OpenSSL
INCLUDEPATH += $$PWD/External/Linux/OpenSSL/include
LIBS += -L$$PWD/External/Linux/OpenSSL/lib -lcrypto
LIBS += -L$$PWD/External/Linux/OpenSSL/lib -lssl
# Linux Icon (KDE/GNOME)
# TODO/FIXME
}

# MacOS-specific
macx: {
# MacOS
# TODO/FIXME
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
