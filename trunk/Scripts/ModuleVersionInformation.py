# ModuleVersionInformation.py

# This module provides QCrypTool version information to the build and release
# processes based on the VERSION file located at the project root and the Git
# repository. The only public function in this module returns a tuple of
# three items: the project name, the project version, and the project
# copyright. NB: The project version consists of the version taken from
# the VERSION file and the Git revision suffix, so that the resulting
# value looks like "VERSION.GITREVISION", i.e. "0.1.1". If the Git
# revision cannot be obtained, it is set to zero (i.e. "0.1.0").

import os
import re
import subprocess

scriptDir = os.path.dirname(os.path.realpath(__file__))

pathVersionFile = scriptDir + "/../../VERSION"

def getProjectNameAndVersionAndCopyright():
    projectName, projectVersion, projectCopyright = _getProjectNameAndVersionAndCopyright()
    projectGitRevision = _getProjectGitRevision()
    if len(projectGitRevision) == 0:
        return projectName, projectVersion, projectCopyright
    else:
        return projectName, projectVersion + "." + projectGitRevision, projectCopyright

def _getProjectNameAndVersionAndCopyright():
    global pathVersionFile
    projectName = ""
    projectVersion = ""
    projectCopyright = ""
    with open(pathVersionFile, "r") as fin:
        versionFileData = fin.read()
        regExpProjectName = r"QCT_PROJECT_NAME\s+\"(.+)\""
        regExpProjectVersion = r"QCT_PROJECT_VERSION\s+\"(.+)\""
        regExpProjectCopyright = r"QCT_PROJECT_COPYRIGHT\s+\"(.+)\""
        if re.search(regExpProjectName, versionFileData):
            match = re.search(regExpProjectName, versionFileData)
            projectName = match.group(1)
        if re.search(regExpProjectVersion, versionFileData):
            match = re.search(regExpProjectVersion, versionFileData)
            projectVersion = match.group(1)
        if re.search(regExpProjectCopyright, versionFileData):
            match = re.search(regExpProjectCopyright, versionFileData)
            projectCopyright = match.group(1)
    return projectName, projectVersion, projectCopyright

def _getProjectGitRevision():
    global scriptDir
    projectGitRevision = ""
    process = subprocess.Popen(["git", "log"], cwd=scriptDir + "/..", stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = process.communicate()
    stdout = stdout.splitlines()
    stderr = stderr.splitlines()
    commitCounter = 0
    regExpCommit = r"^commit\s+[0-9a-f]{32}"
    for line in stdout:
        if re.search(regExpCommit, line):
            commitCounter = commitCounter + 1
    projectGitRevision = str(commitCounter)
    return projectGitRevision

version = "0.1"
