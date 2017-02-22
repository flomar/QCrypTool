// CrypToolApplication.cpp

#include <CrypTool/CrypToolApplication.h>
#include <CrypTool/CrypToolMainWindow.h>

namespace QCrypTool {
    namespace CrypTool {

        Application::Application(int &_argc, char **_argv) :
            QApplication(_argc, _argv),
            m_mainWindow(QSharedPointer<MainWindow>(new MainWindow())) {
            m_mainWindow->show();
        }

        Application::~Application() {

        }

    }
}
