// installscript.qs

function Component() {
    installer.installationFinished.connect(this, Component.prototype.installationFinishedPageIsShown);
    installer.finishButtonClicked.connect(this, Component.prototype.installationFinished);
}

Component.prototype.createOperations = function() {
    component.createOperations();
    try {
        if(installer.isInstaller()) {
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
                QDesktopServices.openUrl("file:///" + installer.value("TargetDir") + "/QCrypTool.exe");
            }
        }
    }
    catch(e) {
        console.log(e);
    }
}
