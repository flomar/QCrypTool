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
language = None

def checkEnvironment():
    global qtInstallationDir
    if qtInstallationDir == None:
        return False
    return True

def checkArguments():
    global supportedLanguages
    if len(sys.argv) != 2:
        return False
    if not sys.argv[1] in supportedLanguages:
        return False
    return True

def createHelp():
    invokeHelpGenerator()
    invokeCollectionGenerator()

def invokeHelpGenerator():
    global qtInstallationDir
    global helpDir
    global language
    command = qtInstallationDir + "/bin/qhelpgenerator"
    arguments = helpDir + "/QCTHelp" + language + ".qhp"
    process = subprocess.Popen([command, arguments], cwd=helpDir, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = process.communicate()
    stdout = stdout.splitlines()
    stderr = stderr.splitlines()

def invokeCollectionGenerator():
    global qtInstallationDir
    global helpDir
    global language
    command = qtInstallationDir + "/bin/qcollectiongenerator"
    arguments = helpDir + "/QCTHelp" + language + ".qhcp"
    process = subprocess.Popen([command, arguments], cwd=helpDir, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = process.communicate()
    stdout = stdout.splitlines()
    stderr = stderr.splitlines()

def main():
    global supportedLanguages
    global language
    if not checkEnvironment():
        print("ERROR: The environment is invalid. Please make sure the following environment variables are properly set:")
        print("ERROR: - QTINSTALLATIONDIR")
        return -1
    if not checkArguments():
        print("ERROR: Please supply exactly one argument, the language you want to build the help for. The following languages are supported:")
        print("ERROR: " + str(supportedLanguages))
        return -1
    language = sys.argv[1]
    createHelp()
    return 0

main()
