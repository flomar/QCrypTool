// CrypTool.cpp

#include <CrypTool/CrypToolApplication.h>
#include <CrypTool/CrypToolMainWindow.h>

namespace QCrypTool {
    namespace CrypTool {

    }
}

int main(int _argc, char **_argv) {
    const QVector<QString> vectorLanguages = QVector<QString>() << "English" << "German";
    QCrypTool::CrypTool::Application application(_argc, _argv, vectorLanguages);
    QCrypTool::CrypTool::MainWindow mainWindow;
    mainWindow.show();
    return application.exec();
}
