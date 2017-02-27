// controlscript.qs

function Controller() {
    installer.setDefaultPageVisible(QInstaller.ComponentSelection, false);
}

Controller.prototype.LicenseAgreementPageCallback = function() {
    var widget = gui.currentPageWidget();
    if(widget != null) {
        widget.AcceptLicenseRadioButton.checked = true;
    }
}
