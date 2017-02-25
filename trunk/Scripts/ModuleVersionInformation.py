# ModuleVersionInformation.py

# This module provides QCrypTool version information to the build and release
# processes based on the VERSION file located at the project root and the Git
# repository. The only public function in this module returns a tuple of
# three items: the application name, the application version, and the
# application copyright. NB: The application version consists of the version
# taken from the VERSION file and the Git revision suffix, so that the
# resulting value looks like "VERSION.GITREVISION", i.e. "0.1.1"; if the
# Git revision cannot be obtained, it is set to zero (i.e. "0.1.0").

import os
import re
import subprocess

SCRIPTDIR = os.path.dirname(os.path.realpath(__file__))

pathVersionFile = SCRIPTDIR + "/../../VERSION"

def getApplicationNameAndVersionAndCopyright():
    applicationName, applicationVersion, applicationCopyright = _getApplicationNameAndVersionAndCopyright()
    applicationGitRevision = _getApplicationGitRevision()
    if len(applicationGitRevision) == 0:
        return applicationName, applicationVersion, applicationCopyright
    else:
        return applicationName, applicationVersion + "." + applicationGitRevision, applicationCopyright

def _getApplicationNameAndVersionAndCopyright():
    applicationName = ""
    applicationVersion = ""
    applicationCopyright = ""
    with open(pathVersionFile, "r") as fin:
        versionFileData = fin.read()
        regExpApplicationName = r"QCRYPTOOL_APPLICATION_NAME\s+\"(.+)\""
        regExpApplicationVersion = r"QCRYPTOOL_APPLICATION_VERSION\s+\"(.+)\""
        regExpApplicationCopyright = r"QCRYPTOOL_APPLICATION_COPYRIGHT\s+\"(.+)\""
        if re.search(regExpApplicationName, versionFileData):
            match = re.search(regExpApplicationName, versionFileData)
            applicationName = match.group(1)
        if re.search(regExpApplicationVersion, versionFileData):
            match = re.search(regExpApplicationVersion, versionFileData)
            applicationVersion = match.group(1)
        if re.search(regExpApplicationCopyright, versionFileData):
            match = re.search(regExpApplicationCopyright, versionFileData)
            applicationCopyright = match.group(1)
    return applicationName, applicationVersion, applicationCopyright

def _getApplicationGitRevision():
    applicationGitRevision = ""
    process = subprocess.Popen(["git", "log"], cwd=SCRIPTDIR + "/..", stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = process.communicate()
    stdout = stdout.splitlines()
    stderr = stderr.splitlines()
    commitCounter = 0
    regExpCommit = r"^commit\s+[0-9a-f]{32}"
    for line in stdout:
        if re.search(regExpCommit, line):
            commitCounter = commitCounter + 1
    applicationGitRevision = str(commitCounter)
    return applicationGitRevision

version = "0.1"
