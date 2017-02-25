# UpdateBuildInformation.py
#
# This script is invoked during the build process to update the version
# information embedded in the executable. There are two different operation
# modes: PREBUILD and POSTBUILD. One of them must be supplied to the script
# as argument. In PREBUILD mode the relevant C++ files are adapted, in
# POSTBUILD mode these changes are undone.

import os
import sys
import shutil
import re

import ModuleVersionInformation

SCRIPTDIR = os.path.dirname(os.path.realpath(__file__))

pathQCrypToolCppOriginal = SCRIPTDIR + "/../Sources/QCrypTool.cpp"
pathQCrypToolCppBackup = pathQCrypToolCppOriginal +  ".backup"
pathQCrypToolCppTemp = pathQCrypToolCppOriginal + ".temp"

def getOperationMode():
    operationMode = None
    if len(sys.argv) > 1:
        operationMode = sys.argv[1]
    return operationMode

def executePREBUILD():
    applicationName, applicationVersion, applicationCopyright = ModuleVersionInformation.getApplicationNameAndVersionAndCopyright()
    shutil.copyfile(pathQCrypToolCppOriginal, pathQCrypToolCppBackup)
    with open(pathQCrypToolCppOriginal, "rt") as fin:
        with open(pathQCrypToolCppTemp, "wt") as fout:
            for line in fin:
                line = line.replace("[QCRYPTOOL_APPLICATION_NAME]", applicationName)
                line = line.replace("[QCRYPTOOL_APPLICATION_VERSION]", applicationVersion)
                line = line.replace("[QCRYPTOOL_APPLICATION_COPYRIGHT]", applicationCopyright)
                fout.write(line)
    shutil.move(pathQCrypToolCppTemp, pathQCrypToolCppOriginal)

def executePOSTBUILD():
    shutil.move(pathQCrypToolCppBackup, pathQCrypToolCppOriginal)

def main():
    operationMode = getOperationMode()
    if operationMode != "PREBUILD" and operationMode != "POSTBUILD":
        print("ERROR: Please supply one of the following operation modes as argument:")
        print("ERROR: - PREBUILD")
        print("ERROR: - POSTBUILD")
        return -1
    if operationMode == "PREBUILD":
        executePREBUILD()
    if operationMode == "POSTBUILD":
        executePOSTBUILD()
    return 0

main()
