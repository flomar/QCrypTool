// CrypTool.cpp

#include <CrypTool/CrypToolApplication.h>
#include <CrypTool/CrypToolMainWindow.h>

namespace QCrypTool {
    namespace CrypTool {

    }
}

int main(int _argc, char **_argv) {
    QCrypTool::CrypTool::Application application(_argc, _argv);
    QCrypTool::CrypTool::MainWindow mainWindow;
    mainWindow.show();
    return application.exec();
}
