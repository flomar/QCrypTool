// Application.cpp

#include <Core/Application.h>

namespace QCT {
    namespace Core {

        Application::Application(int &_argc, char **_argv, const QString &_pathIconSvg, const QSize &_sizeIconSvg) :
            QApplication(_argc, _argv) {
            setWindowIcon(Core::Utilities::Graphics::getIconFromSvg(_pathIconSvg, _sizeIconSvg));
        }

        Application::~Application() {

        }

        int Application::exec() {
            QCT::Translation::instance().setLanguage();
            return QApplication::exec();
        }

    }
}
