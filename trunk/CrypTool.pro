# CrypTool.pro

QT += core gui widgets

CONFIG += c++11

TEMPLATE = app

INCLUDEPATH += Sources $$OUT_PWD

TARGET = CrypTool

HEADERS += \
Sources/QCrypTool.h \
Sources/Core/MainWindow.h \
Sources/Core/Dialog.h \
Sources/Core/HelpSystem.h \
Sources/Core/Cryptography.h \
Sources/Core/Utilities.h \
Sources/CrypTool/CrypTool.h \
Sources/CrypTool/CrypToolApplication.h \
Sources/CrypTool/CrypToolMainWindow.h \
Sources/CrypTool/Dialogs/DialogAbout.h \
Sources/CrypTool/Dialogs/DialogLanguage.h

SOURCES += \
Sources/QCrypTool.cpp \
Sources/Core/MainWindow.cpp \
Sources/Core/Dialog.cpp \
Sources/Core/HelpSystem.cpp \
Sources/Core/Cryptography.cpp \
Sources/Core/Utilities.cpp \
Sources/CrypTool/CrypTool.cpp \
Sources/CrypTool/CrypToolApplication.cpp \
Sources/CrypTool/CrypToolMainWindow.cpp \
Sources/CrypTool/Dialogs/DialogAbout.cpp \
Sources/CrypTool/Dialogs/DialogLanguage.cpp

RESOURCES += \
Resources/QCrypTool.qrc \
Resources/CrypTool.qrc

FORMS += \
Resources/CrypTool/CrypToolMainWindow.ui \
Resources/CrypTool/Dialogs/DialogAbout.ui \
Resources/CrypTool/Dialogs/DialogLanguage.ui

# Linux-specific
unix:!macx {

}
# Mac-specific
macx: {

}
# Win-specific
win32: {

}
