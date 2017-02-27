// Application.cpp

#include <Core/Application.h>

namespace QCrypTool {
    namespace Core {

        Application::Application(int &_argc, char **_argv, const QIcon &_icon) :
            QApplication(_argc, _argv) {
            setWindowIcon(_icon);
        }

        Application::~Application() {

        }

        int Application::exec() {
            // TODO/FIXME: set language depending on locale
            QCrypTool::Translation::instance().setLanguage("English");
            return QApplication::exec();
        }

    }
}
