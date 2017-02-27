# CreateInstaller.py
#
# This script is invoked to create the QCrypTool installer using the 
# QtInstallerFramework. It populates the installer's data directory with 
# all files which are to be rolled out with the installer, and it updates 
# the relevant meta data.

import os
import sys
import shutil
import subprocess
import re
import time

import ModuleVersionInformation

SCRIPTDIR = os.path.dirname(os.path.realpath(__file__))

QTINSTALLERFRAMEWORKDIR = os.environ.get("QTINSTALLERFRAMEWORKDIR")
QTINSTALLATIONDIR = os.environ.get("QTINSTALLATIONDIR")
BUILDDIR = os.environ.get("BUILDDIR")

applicationName, applicationVersion, applicationCopyright = ModuleVersionInformation.getApplicationNameAndVersionAndCopyright()

DATE = time.strftime("%Y-%m-%d")

installerPackageName = "com.CrypToolTeam.QCrypTool"

installerConfigFileOriginal = SCRIPTDIR + "/../Installer/config/config.xml"
installerConfigFileBackup = installerConfigFileOriginal + ".backup"
installerConfigFileTemp = installerConfigFileOriginal + ".temp"

installerPackageFileOriginal = SCRIPTDIR + "/../Installer/packages/" + installerPackageName + "/meta/package.xml"
installerPackageFileBackup = installerPackageFileOriginal + ".backup"
installerPackageFileTemp = installerPackageFileOriginal + ".temp"

installerPackageDataDir = SCRIPTDIR + "/../Installer/packages/" + installerPackageName + "/data"

def checkEnvironment():
    if QTINSTALLERFRAMEWORKDIR == None:
        return False
    if QTINSTALLATIONDIR == None:
        return False
    if BUILDDIR == None:
        return False
    return True
	
def pushInstallerEnvironment():
    shutil.copyfile(installerConfigFileOriginal, installerConfigFileBackup)
    shutil.copyfile(installerPackageFileOriginal, installerPackageFileBackup)

def popInstallerEnvironment():
    shutil.copyfile(installerConfigFileBackup, installerConfigFileOriginal)
    shutil.copyfile(installerPackageFileBackup, installerPackageFileOriginal)
    os.remove(installerConfigFileBackup)
    os.remove(installerPackageFileBackup)

def updateInstallerConfigFile():
    with open(installerConfigFileOriginal, "rt") as fin:
        with open(installerConfigFileTemp, "wt") as fout:
            for line in fin:
                line = line.replace("<Name>QCrypTool</Name>", "<Name>" + applicationName + " " + applicationVersion + "</Name>")
                line = line.replace("<Version>0.0.0</Version>", "<Version>" + applicationVersion + "</Version>")
                line = line.replace("<Title>QCrypTool</Name>", "<Name>" + applicationName + " " + applicationVersion + "</Title>")
                line = line.replace("<StartMenuDir>QCrypTool</StartMenuDir>", "<StartMenuDir>" + applicationName + "-" + applicationVersion + "</StartMenuDir>")
                line = line.replace("<TargetDir>@HomeDir@/QCrypTool</TargetDir>", "<TargetDir>@HomeDir@/" + applicationName + "-" + applicationVersion + "</TargetDir>")
                fout.write(line)
    shutil.move(installerConfigFileTemp, installerConfigFileOriginal)
	
def updateInstallerPackageFile():
    with open(installerPackageFileOriginal, "rt") as fin:
        with open(installerPackageFileTemp, "wt") as fout:
            for line in fin:
                line = line.replace("<Version>0.0.0</Version>", "<Version>" + applicationVersion + "</Version>")
                line = line.replace("<ReleaseDate>0000-00-00</ReleaseDate>", "<ReleaseDate>" + DATE + "</ReleaseDate>")
                fout.write(line)
    shutil.move(installerPackageFileTemp, installerPackageFileOriginal)

def createInstaller():
    if os.path.isdir(installerPackageDataDir):
        shutil.rmtree(installerPackageDataDir)
    os.makedirs(installerPackageDataDir)
    platform = sys.platform
    # Linux-specific
    if platform == "linux" or platform == "linux2":
        print("TODO/FIXME: createInstaller for Linux")
    # MacOS-specific
    if platform == "darwin":
        print("TODO/FIXME: createInstaller for MacOS")
    # Windows-specific
    if platform == "win32":
        shutil.copyfile(BUILDDIR + "/CrypTool/release/CrypTool.exe", installerPackageDataDir + "/CrypTool.exe")
        shutil.copyfile(SCRIPTDIR + "/../External/Windows/OpenSSL/bin/libcrypto-1_1-x64.dll", installerPackageDataDir + "/libcrypto-1_1-x64.dll")
        shutil.copyfile(SCRIPTDIR + "/../External/Windows/OpenSSL/bin/libssl-1_1-x64.dll", installerPackageDataDir + "/libssl-1_1-x64.dll")
        command = QTINSTALLATIONDIR + "/bin/windeployqt.exe" + " " + installerPackageDataDir + "/CrypTool.exe"
        os.system(command)
        command = QTINSTALLERFRAMEWORKDIR + "/bin/binarycreator.exe -c " + installerConfigFileOriginal + " -p " + SCRIPTDIR + "/../Installer/packages " + SCRIPTDIR + "/../Installer/SetupQCrypTool-" + applicationVersion + ".exe"
        os.system(command)
    # clean up
    if os.path.isdir(installerPackageDataDir):
        shutil.rmtree(installerPackageDataDir)
    os.makedirs(installerPackageDataDir)

def main():
    if not checkEnvironment():
        print("ERROR: The environment is invalid. Please make sure the following environment variables are properly set:")
        print("ERROR: - QTINSTALLERFRAMEWORKDIR")
        print("ERROR: - QTINSTALLATIONDIR")
        print("ERROR: - BUILDDIR")
        return -1
    pushInstallerEnvironment()
    updateInstallerConfigFile()
    updateInstallerPackageFile()
    createInstaller()
    popInstallerEnvironment()
    return 0

main()
