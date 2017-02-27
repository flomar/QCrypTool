// Application.cpp

#include <Core/Application.h>

namespace QCrypTool {
    namespace Core {

        Application::Application(int &_argc, char **_argv) :
            QApplication(_argc, _argv) {

        }

        Application::~Application() {

        }

        int Application::exec() {
            QCrypTool::Translation::instance().initializeLanguages();
            return QApplication::exec();
        }

    }
}
