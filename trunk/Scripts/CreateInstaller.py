# CreateInstaller.py
#
# This script is invoked to create the QCrypTool installer using the 
# QtInstallerFramework. It populates the installer's data directory with 
# all files which are to be rolled out with the installer, and it updates 
# the relevant meta data.

import os
import sys
import glob
import shutil
import time

import ModuleVersionInformation

scriptDir = os.path.dirname(os.path.realpath(__file__))

qtInstallerFrameworkDir = os.environ.get("QTINSTALLERFRAMEWORKDIR")
qtInstallationDir = os.environ.get("QTINSTALLATIONDIR")
buildDir = os.environ.get("BUILDDIR")

projectName, projectVersion, projectCopyright = ModuleVersionInformation.getProjectNameAndVersionAndCopyright()

installerPackageName = "com.CrypToolTeam.QCrypTool"

installerConfigFileOriginal = scriptDir + "/../Installer/config/config.xml"
installerConfigFileBackup = installerConfigFileOriginal + ".backup"
installerConfigFileTemp = installerConfigFileOriginal + ".temp"

installerPackageFileOriginal = scriptDir + "/../Installer/packages/" + installerPackageName + "/meta/package.xml"
installerPackageFileBackup = installerPackageFileOriginal + ".backup"
installerPackageFileTemp = installerPackageFileOriginal + ".temp"

installerPackageDataDir = scriptDir + "/../Installer/packages/" + installerPackageName + "/data"

def checkEnvironment():
    global qtInstallerFrameworkDir
    global qtInstallationDir
    global buildDir
    if qtInstallerFrameworkDir == None:
        return False
    if qtInstallationDir == None:
        return False
    if buildDir == None:
        return False
    return True
	
def pushInstallerEnvironment():
    global installerConfigFileOriginal
    global installerConfigFileBackup
    global installerPackageFileOriginal
    global installerPackageFileBackup
    shutil.copyfile(installerConfigFileOriginal, installerConfigFileBackup)
    shutil.copyfile(installerPackageFileOriginal, installerPackageFileBackup)

def popInstallerEnvironment():
    global installerConfigFileOriginal
    global installerConfigFileBackup
    global installerPackageFileOriginal
    global installerPackageFileBackup
    shutil.copyfile(installerConfigFileBackup, installerConfigFileOriginal)
    shutil.copyfile(installerPackageFileBackup, installerPackageFileOriginal)
    os.remove(installerConfigFileBackup)
    os.remove(installerPackageFileBackup)

def updateInstallerConfigFile():
    global projectName
    global projectVersion
    global projectCopyright
    global installerConfigFileOriginal
    global installerConfigFileTemp
    with open(installerConfigFileOriginal, "rt") as fin:
        with open(installerConfigFileTemp, "wt") as fout:
            for line in fin:
                line = line.replace("<Name>QCrypTool</Name>", "<Name>" + projectName + " " + projectVersion + "</Name>")
                line = line.replace("<Version>0.0.0</Version>", "<Version>" + projectVersion + "</Version>")
                line = line.replace("<Title>QCrypTool</Name>", "<Name>" + projectName + " " + projectVersion + "</Title>")
                line = line.replace("<StartMenuDir>QCrypTool</StartMenuDir>", "<StartMenuDir>" + projectName + "-" + projectVersion + "</StartMenuDir>")
                line = line.replace("<TargetDir>@HomeDir@/QCrypTool</TargetDir>", "<TargetDir>@HomeDir@/" + projectName + "-" + projectVersion + "</TargetDir>")
                fout.write(line)
    shutil.move(installerConfigFileTemp, installerConfigFileOriginal)
	
def updateInstallerPackageFile():
    global projectName
    global projectVersion
    global projectCopyright
    global installerPackageFileOriginal
    global installerPackageFileTemp
    with open(installerPackageFileOriginal, "rt") as fin:
        with open(installerPackageFileTemp, "wt") as fout:
            for line in fin:
                line = line.replace("<Version>0.0.0</Version>", "<Version>" + projectVersion + "</Version>")
                line = line.replace("<ReleaseDate>0000-00-00</ReleaseDate>", "<ReleaseDate>" + time.strftime("%Y-%m-%d") + "</ReleaseDate>")
                fout.write(line)
    shutil.move(installerPackageFileTemp, installerPackageFileOriginal)

def createInstaller():
    global scriptDir
    global projectName
    global projectVersion
    global projectCopyright
    global installerConfigFileOriginal
    global installerPackageDataDir
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
        shutil.copy(buildDir + "/QCrypTool/release/QCrypTool.exe", installerPackageDataDir)
        shutil.copy(qtInstallationDir + "/bin/assistant.exe", installerPackageDataDir)
        for file in glob.glob(scriptDir + "/../External/Windows/OpenSSL/bin/*.dll"):
            shutil.copy(file, installerPackageDataDir)
        for file in glob.glob(scriptDir + "/../Resources/QCT/Help/*.qhc"):
            shutil.copy(file, installerPackageDataDir)
        command = qtInstallationDir + "/bin/windeployqt.exe" + " " + installerPackageDataDir + "/QCrypTool.exe"
        os.system(command)
        command = qtInstallationDir + "/bin/windeployqt.exe" + " " + installerPackageDataDir + "/assistant.exe"
        os.system(command)
        command = qtInstallerFrameworkDir + "/bin/binarycreator.exe -c " + installerConfigFileOriginal + " -p " + scriptDir + "/../Installer/packages " + scriptDir + "/../Installer/SetupQCrypTool-" + projectVersion + ".exe"
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
