// QCrypToolApplication.cpp

#include <QCrypTool/QCrypToolApplication.h>

namespace QCT {
    namespace QCrypTool {

        Application::Application(int &_argc, char **_argv) :
            Core::Application(_argc, _argv, QString(":/QCT/Images/QCTLogo.svg"), QSize(512, 512)) {

        }

        Application::~Application() {

        }

    }
}
