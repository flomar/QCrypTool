# UpdateBuildInformation.py
#
# This script is invoked during the build process. It updates the build
# information embedded in the resulting executables. The build information
# consists of the application name, the application version, the application
# git revision, and the application copyright (see variables below). The
# values for name, version and copyright are static, the value for the
# git revision is obtained automatically.

import os
import sys
import shutil
import subprocess
import re

APPLICATION_NAME = "QCrypTool"
APPLICATION_VERSION = "0.1"
APPLICATION_REVISION = "0"
APPLICATION_COPYRIGHT = "(C) 2017 CrypTool Team"

def main():
	print("TODO/FIXME: UpdateBuildInformation.py")

main()
