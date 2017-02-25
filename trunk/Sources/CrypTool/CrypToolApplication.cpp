// CrypToolApplication.cpp

#include <CrypTool/CrypToolApplication.h>
#include <CrypTool/CrypToolMainWindow.h>

#include <Core/Translator.h>

namespace QCrypTool {
    namespace CrypTool {

        Application::Application(int &_argc, char **_argv) :
            QApplication(_argc, _argv),
            m_mainWindow(QSharedPointer<MainWindow>(new MainWindow())) {
            Core::Translator::instance().setLanguages(QVector<QString>() << "English" << "German");
            Core::Translator::instance().setLanguage("CrypTool", "English");
            m_mainWindow->show();
        }

        Application::~Application() {

        }

    }
}
