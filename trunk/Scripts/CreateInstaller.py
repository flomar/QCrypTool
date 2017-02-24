# CreateInstaller.py
#
# This script is invoked to create the QCrypTool installer using the 
# QtInstallerFramework. It populates the installer's data directory with 
# all files which are to be rolled out with the installer, and it updates 
# the relevant meta data. ATTENTION: For this script to work properly, 
# the environment variable QTROOT must point to the root of a valid Qt 5.8 
# or higher installation directory.

import os
import sys
import shutil
import subprocess
import re
import time

# TODO/FIXME: gather this info from some place else
QCRYPTOOL_VERSION = "0.1.0"

# the directory in which this script is located
SCRIPTDIR = os.path.dirname(os.path.realpath(__file__))
# the directory of the QCrypTool build
BUILDDIR = SCRIPTDIR + "/../../build"

# the current date
DATE = time.strftime("%Y-%m-%d")

# the name of the installer package
INSTALLERPACKAGENAME = "com.CrypToolTeam.QCrypTool"
# the path to the installer config file (original, temp, and backup)
INSTALLERCONFIGFILEPATHORIGINAL = SCRIPTDIR + "/../Installer/config/config.xml"
INSTALLERCONFIGFILEPATHTEMP = INSTALLERCONFIGFILEPATHORIGINAL + ".temp"
INSTALLERCONFIGFILEPATHBACKUP = INSTALLERCONFIGFILEPATHORIGINAL + ".backup"
# the path to the installer package file (original, temp, and backup)
INSTALLERPACKAGEFILEPATHORIGINAL = SCRIPTDIR + "/../Installer/packages/" + INSTALLERPACKAGENAME + "/meta/package.xml"
INSTALLERPACKAGEFILEPATHTEMP = INSTALLERPACKAGEFILEPATHORIGINAL + ".temp"
INSTALLERPACKAGEFILEPATHBACKUP = INSTALLERPACKAGEFILEPATHORIGINAL + ".backup"
# the directory of the installer payload
INSTALLERPACKAGEDATADIR = SCRIPTDIR + "/../Installer/packages/" + INSTALLERPACKAGENAME + "/data"

def checkQtEnvironment():
	QTROOT = os.environ.get('QTROOT')
	if QTROOT == None:
		return False
	QTINSTALLATION = os.environ.get('QTINSTALLATION')
	if QTINSTALLATION == None:
		return False
	return True

def checkBuildEnvironment():
	if not os.path.isdir(BUILDDIR):
		return False
	return True

def checkInstallerEnvironment():
	if not os.path.isfile(INSTALLERCONFIGFILEPATHORIGINAL):
		return False
	if not os.path.isfile(INSTALLERPACKAGEFILEPATHORIGINAL):
		return False
	return True
	
def pushInstallerEnvironment():
	shutil.copyfile(INSTALLERCONFIGFILEPATHORIGINAL, INSTALLERCONFIGFILEPATHBACKUP)
	shutil.copyfile(INSTALLERPACKAGEFILEPATHORIGINAL, INSTALLERPACKAGEFILEPATHBACKUP)

def popInstallerEnvironment():
	shutil.copyfile(INSTALLERCONFIGFILEPATHBACKUP, INSTALLERCONFIGFILEPATHORIGINAL)
	shutil.copyfile(INSTALLERPACKAGEFILEPATHBACKUP, INSTALLERPACKAGEFILEPATHORIGINAL)
	os.remove(INSTALLERCONFIGFILEPATHBACKUP)
	os.remove(INSTALLERPACKAGEFILEPATHBACKUP)

def updateInstallerConfigFile():
	with open(INSTALLERCONFIGFILEPATHORIGINAL, "rt") as fin:
		with open(INSTALLERCONFIGFILEPATHTEMP, "wt") as fout:
			for line in fin:
				line = line.replace("<Version>0.0.0</Version>", "<Version>" + QCRYPTOOL_VERSION + "</Version>")
				fout.write(line)
	shutil.move(INSTALLERCONFIGFILEPATHTEMP, INSTALLERCONFIGFILEPATHORIGINAL)
	
def updateInstallerPackageFile():
	with open(INSTALLERPACKAGEFILEPATHORIGINAL, "rt") as fin:
		with open(INSTALLERPACKAGEFILEPATHTEMP, "wt") as fout:
			for line in fin:
				line = line.replace("<Version>0.0.0</Version>", "<Version>" + QCRYPTOOL_VERSION + "</Version>")
				line = line.replace("<ReleaseDate>0000-00-00</ReleaseDate>", "<ReleaseDate>" + DATE + "</ReleaseDate>")
				fout.write(line)
	shutil.move(INSTALLERPACKAGEFILEPATHTEMP, INSTALLERPACKAGEFILEPATHORIGINAL)

def createInstaller():
	if os.path.isdir(INSTALLERPACKAGEDATADIR):
		shutil.rmtree(INSTALLERPACKAGEDATADIR)
	os.makedirs(INSTALLERPACKAGEDATADIR)
	platform = sys.platform
	# Linux-specific
	if platform == "linux" or platform == "linux2":
		print("TODO/FIXME: createInstaller for Linux")
	# MacOS-specific
	if platform == "darwin":
		print("TODO/FIXME: createInstaller for MacOS")
	# Windows-specific
	if platform == "win32":
		QTROOT = os.environ.get('QTROOT')
		QTINSTALLATION = os.environ.get('QTINSTALLATION')
		shutil.copyfile(BUILDDIR + "/CrypTool/release/CrypTool.exe", INSTALLERPACKAGEDATADIR + "/CrypTool.exe")
		shutil.copyfile(SCRIPTDIR + "/../External/Windows/OpenSSL/bin/libcrypto-1_1-x64.dll", INSTALLERPACKAGEDATADIR + "/libcrypto-1_1-x64.dll")
		shutil.copyfile(SCRIPTDIR + "/../External/Windows/OpenSSL/bin/libssl-1_1-x64.dll", INSTALLERPACKAGEDATADIR + "/libssl-1_1-x64.dll")
		command = QTINSTALLATION + "/bin/windeployqt.exe" + " " + INSTALLERPACKAGEDATADIR + "/CrypTool.exe"
		os.system(command)
		command = QTROOT + "/Tools/QtInstallerFramework/2.0/bin/binarycreator.exe -c " + INSTALLERCONFIGFILEPATHORIGINAL + " -p " + SCRIPTDIR + "/../Installer/packages " + SCRIPTDIR + "/../Installer/SetupQCrypTool-" + QCRYPTOOL_VERSION + ".exe"
		os.system(command)
		if os.path.isdir(INSTALLERPACKAGEDATADIR):
			shutil.rmtree(INSTALLERPACKAGEDATADIR)
		os.makedirs(INSTALLERPACKAGEDATADIR)

def main():
	if not checkQtEnvironment():
		print("ERROR: Qt environment invalid!")
		print("ERROR: Please make sure the 'QTROOT' environment variable points to a valid Qt installation directory containing a QtInstallerFramework component.")
		print("ERROR: Please make sure the 'QTINSTALLATION' environment variable points to a valid Qt 5.8 or higher installation directory")
		return -1
	if not checkBuildEnvironment():
		print("ERROR: Build environment invalid!")
		print("ERROR: Please make sure there is a 'build/release' directory in the root project directory.")
	if not checkInstallerEnvironment():
		print("ERROR: Installer environment invalid!")
		print("ERROR: Please make sure you acquire a clean project directory.")
		return -1
	pushInstallerEnvironment()
	updateInstallerConfigFile()
	updateInstallerPackageFile()
	createInstaller()
	popInstallerEnvironment()
	return 0

main()
