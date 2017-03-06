// QCrypTool.cpp

#include <QCrypTool/QCrypToolApplication.h>
#include <QCrypTool/QCrypToolMainWindow.h>

namespace QCT {
    namespace QCrypTool {

    }
}

int main(int _argc, char **_argv) {
    QCT::QCrypTool::Application application(_argc, _argv);
    QCT::QCrypTool::MainWindow mainWindow;
    if(!application.initialize()) {
        return -1;
    }
    mainWindow.show();
    return application.exec();
}
