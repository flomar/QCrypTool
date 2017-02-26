// Application.cpp

#include <Core/Application.h>

namespace QCrypTool {
    namespace Core {

        Application::Application(int &_argc, char **_argv, const QVector<QString> &_vectorLanguages) :
            QApplication(_argc, _argv),
            m_vectorLanguages(_vectorLanguages) {

        }

        Application::~Application() {

        }

        int Application::exec() {
            QCrypTool::Translation::instance().initializeLanguages();
            return QApplication::exec();
        }

    }
}
