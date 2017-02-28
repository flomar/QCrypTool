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

pathQCTCppOriginal = SCRIPTDIR + "/../Sources/QCT.cpp"
pathQCTCppBackup = pathQCTCppOriginal +  ".backup"
pathQCTCppTemp = pathQCTCppOriginal + ".temp"

def getOperationMode():
    operationMode = None
    if len(sys.argv) > 1:
        operationMode = sys.argv[1]
    return operationMode

def executePREBUILD():
    projectName, projectVersion, projectCopyright = ModuleVersionInformation.getProjectNameAndVersionAndCopyright()
    shutil.copyfile(pathQCTCppOriginal, pathQCTCppBackup)
    with open(pathQCTCppOriginal, "rt") as fin:
        with open(pathQCTCppTemp, "wt") as fout:
            for line in fin:
                line = line.replace("[QCT_PROJECT_NAME]", projectName)
                line = line.replace("[QCT_PROJECT_VERSION]", projectVersion)
                line = line.replace("[QCT_PROJECT_COPYRIGHT]", projectCopyright)
                fout.write(line)
    shutil.move(pathQCTCppTemp, pathQCTCppOriginal)

def executePOSTBUILD():
    shutil.move(pathQCTCppBackup, pathQCTCppOriginal)

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
