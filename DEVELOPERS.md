# QCrypTool Developers

This file is the starting point for all developers interested in contributing to the project.

## Overview

QCrypTool is a Qt-based cross-platform application with support for Linux, MacOS, and Windows. As of March 2017, QCrypTool has been built and tested under Linux and Windows. Although QCrypTool hasn't been tested under MacOS yet, I don't see any reason why it shouldn't work.

## Build Requirements

The following is **REQUIRED** to build QCrypTool:

- **Qt**: Qt is required. No way around it. Any **Qt 5.8+** version should do. If you intend to build self-extracting installer executables, don't forget to include the **Qt Installer Framework 2.0+** when installing Qt.

- **Git**: Git is required for organizing your code and submitting pull requests against this repository, also Git is used during the build process to dynamically determine the current version of your build. Amy **Git 1.8+** version should do. You can build QCrypTool without Git by downloading a ZIP archive of this repository, but for most developers it makes things more complicated than they need to be.

- **Python**: Python is required for executing a bunch of helper scripts during the build process. Any **Python 2.7+** distribution should do. You can build QCrypTool without Python by calling the necessary commands yourself, but this is neither very efficient nor officially supported.

- **Compiler**: Any 64bit and C++11-capable compiler should do. On Linux QCrypTool has been compiled using gcc64, on Windows CrypTool has been compiled using MSVC2015.

## Build Instructions

### Acquiring The Source Code

TODO

### Preparing The Environment

#### Creating The Build Folder

You have to create the folder **ROOT/build/QCrypTool** where ROOT is the root of the Git repository.

You can tell you've created the folder on the right level if the ROOT folder contains both a "build" and a "trunk" folder.

#### Making Git And Pythong Available

You have to put both Git and Python into your **PATH** variable.

If you fire up a terminal and typing "git" or "python" doesn't yield any errors, you know you're good to go.

#### Defining Additional Environment Variables

You have to define a few additional environment variables: **QTINSTALLERFRAMEWORKDIR**, **QTINSTALLATIONDIR**, and **BUILDDIR**.

The **QTINSTALLERFRAMEWORKDIR** variable must point to the Qt Installer Framework which you have installed with your Qt distribution.

The **QTINSTALLATIONDIR** variable must point to the Qt distribution you have installed.

The **BUILDDIR** must point to the build directory you have created earlier.

The following commands give you an idea of how this works under Windows. It is particularly important which level the environment variables point to:

- set QTINSTALLERFRAMEWORKDIR=C:\Qt\Tools\QtInstallerFramework\2.0
- set QTINSTALLATIONDIR=C:\Qt\5.8\msvc2015_64
- set BUILDDIR=C:\QCrypTool\build

#### Configuring Qt Creator

Fire up "QCrypTool.pro" using Qt Creator.

TODO: setting "Working Directory" and "Build Directory" for both "Debug" and "Release"

TODO: invoking "UpdateBuildInformation.py PREBUILD/POSTBUILD" for "Debug"

### Creating Translations

TODO

### Creating Help

TODO

### Building QCrypTool

TODO

## Coding Guidelines

TODO

## Extending QCrypTool

TODO
