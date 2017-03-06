// installscript.qs

function Component() {
    installer.installationFinished.connect(this, Component.prototype.installationFinishedPageIsShown);
    installer.finishButtonClicked.connect(this, Component.prototype.installationFinished);
}

Component.prototype.createOperations = function() {
    component.createOperations();
    try {
        if(installer.isInstaller()) {
            if(systemInfo.kernelType === "linux") {

            }
            if(systemInfo.productType === "macos") {

            }
            if(systemInfo.productType === "windows") {
                component.addOperation("CreateShortcut", "@TargetDir@/QCrypTool.exe", "@StartMenuDir@/QCrypTool.lnk", "workingDirectory=@TargetDir@");
            }
        }
    }
    catch(e) {
        console.log(e);
    }
}

Component.prototype.installationFinishedPageIsShown = function() {
    try {
        if(installer.isInstaller() && installer.status == QInstaller.Success) {
            installer.addWizardPageItem(component, "LaunchQCrypToolForm", QInstaller.InstallationFinished);
            installer.performOperation("Move", ["@TargetDir@/QCrypToolDatabase.sqlite", "@HomeDir@/QCrypToolDatabase.sqlite"]);
        }
    }
    catch(e) {
        console.log(e);
    }
}

Component.prototype.installationFinished = function() {
    try {
        if(installer.isInstaller() && installer.status == QInstaller.Success) {
            var isLaunchQCrypToolCheckBoxChecked = component.userInterface("LaunchQCrypToolForm").LaunchQCrypToolCheckBox.checked;
            if(isLaunchQCrypToolCheckBoxChecked) {
                if(systemInfo.kernelType === "linux") {
                    installer.executeDetached("bash", ["@TargetDir@/QCrypTool.sh"]);
                }
                if(systemInfo.productType === "macos") {

                }
                if(systemInfo.productType === "windows") {
                    QDesktopServices.openUrl("file:///" + installer.value("TargetDir") + "/QCrypTool.exe");
                }
            }
        }
    }
    catch(e) {
        console.log(e);
    }
}
