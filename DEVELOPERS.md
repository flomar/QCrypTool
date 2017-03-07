# QCrypTool Developers

This file is the starting point for all developers interested in contributing to the project.

## Overview

QCrypTool is a Qt-based cross-platform application with support for Linux, MacOS, and Windows. As of March 2017, QCrypTool has been built and tested under Linux and Windows. Although QCrypTool hasn't been tested under MacOS yet, I don't see any reason why it shouldn't work.

## Build Requirements

The following is **REQUIRED** to build QCrypTool:

- **Qt**: Qt is required. No way around it. Any **Qt 5.8+** version should do. If you intend to build self-extracting installer executables, don't forget to include the **Qt Installer Framework 2.0+** when installing Qt.

- **Git**: Git is required for organizing your code and submitting pull requests against this repository, also Git is used during the build process to dynamically determine the current version of your build. Amy **Git 1.8+** version should do. But please note that Git needs to be in your **PATH** variable. You can build QCrypTool without Git by downloading a ZIP archive of this repository, but for most developers it makes things more complicated than they need to be.

- **Python**: Python is required for executing a bunch of helper scripts during the build process. Any **Python 2.7+** distribution should do. But please note that Python needs to be in your **PATH** variable. You can build QCrypTool without Python by calling the necessary commands yourself, but this is neither very efficient nor officially supported.

- **Compiler**: Any 64bit and C++11-capable compiler should do. On Linux QCrypTool has been compiled using gcc64, on Windows CrypTool has been compiled using MSVC2015.

## Build Instructions

TODO

## Coding Guidelines

TODO

## Extending QCrypTool

TODO
