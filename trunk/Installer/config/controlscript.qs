// controlscript.qs

function Controller() {
    try {
        installer.setDefaultPageVisible(QInstaller.ComponentSelection, false);
    }
    catch(e) {
        console.log(e);
    }
}

Controller.prototype.LicenseAgreementPageCallback = function() {
    try {
        var widget = gui.currentPageWidget();
        if(widget != null) {
            widget.AcceptLicenseRadioButton.checked = true;
        }
    }
    catch(e) {
        console.log(e);
    }
}
