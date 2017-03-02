# CreateHelp.py
#
# This script is invoked to create the QCrypTool help which can then be
# viewed using the QtAssistant.

import os
import sys
import subprocess

scriptDir = os.path.dirname(os.path.realpath(__file__))

qtInstallationDir = os.environ.get("QTINSTALLATIONDIR")

helpDir = scriptDir + "/../Resources/QCT/Help"

supportedLanguages = [ "English", "German" ]

commandQHelpGenerator = None
commandQCollectionGenerator = None

def checkEnvironment():
    global qtInstallationDir
    if qtInstallationDir == None:
        return False
    return True

def initializeGlobals():
    global commandQHelpGenerator
    global commandQCollectionGenerator
    # Linux-specific
    if sys.platform == "linux" or sys.platform == "linux2":
        commandQHelpGenerator = qtInstallationDir + "/bin/qhelpgenerator"
        commandQCollectionGenerator = qtInstallationDir + "/bin/qcollectiongenerator"
    # MacOS-specific
    if sys.platform == "darwin":
        print("TODO/FIXME: implement MacOS-specific code")
    # Windows-specific
    if sys.platform == "win32":
        commandQHelpGenerator = qtInstallationDir + "/bin/qhelpgenerator.exe"
        commandQCollectionGenerator = qtInstallationDir + "/bin/qcollectiongenerator.exe"
    if commandQHelpGenerator == None or not os.path.isfile(commandQHelpGenerator):
        return False
    if commandQCollectionGenerator == None or not os.path.isfile(commandQCollectionGenerator):
        return False
    return True

def createHelp():
    invokeHelpGenerator()
    invokeCollectionGenerator()

def invokeHelpGenerator():
    global qtInstallationDir
    global helpDir
    global commandQHelpGenerator
    for language in supportedLanguages:
        print("Generating help for " + language + "...")
        arguments = helpDir + "/QCTHelp" + language + ".qhp"
        process = subprocess.Popen([commandQHelpGenerator, arguments], cwd=helpDir, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout, stderr = process.communicate()
        stdout = stdout.splitlines()
        stderr = stderr.splitlines()

def invokeCollectionGenerator():
    global qtInstallationDir
    global helpDir
    global commandQCollectionGenerator
    for language in supportedLanguages:
        print("Generating collection for " + language + "...")
        arguments = helpDir + "/QCTHelp" + language + ".qhcp"
        process = subprocess.Popen([commandQCollectionGenerator, arguments], cwd=helpDir, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout, stderr = process.communicate()
        stdout = stdout.splitlines()
        stderr = stderr.splitlines()

def main():
    if not checkEnvironment():
        print("ERROR: The environment is invalid. Please make sure the following environment variables are properly set:")
        print("ERROR: - QTINSTALLATIONDIR")
        return -1
    if not initializeGlobals():
        print("ERROR: Required global variables invalid, contact the developer.")
        return -1
    createHelp()
    return 0

main()
