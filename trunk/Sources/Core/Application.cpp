// Application.cpp

#include <Core/Application.h>

namespace QCrypTool {
    namespace Core {

        Application::Application(int &_argc, char **_argv, const QString &_pathIconSvg, const QSize &_sizeIconSvg) :
            QApplication(_argc, _argv) {
            setWindowIcon(Core::Utilities::Graphics::getIconFromSvg(_pathIconSvg, _sizeIconSvg));
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
