// installscript.qs

function Component() {

}

Component.prototype.createOperations = function() {
    // call default implementation
    component.createOperations();
    // populate start menu on Windows
    if (systemInfo.productType === "windows") {
        component.addOperation("CreateShortcut", "@TargetDir@/CrypTool.exe", "@StartMenuDir@/CrypTool.lnk", "workingDirectory=@TargetDir@");
    }
}
