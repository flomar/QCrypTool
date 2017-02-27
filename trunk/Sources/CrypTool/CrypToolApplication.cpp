// CrypToolApplication.cpp

#include <CrypTool/CrypToolApplication.h>

namespace QCrypTool {
    namespace CrypTool {

        Application::Application(int &_argc, char **_argv) :
            Core::Application(_argc, _argv, QString(":/QCrypTool/Images/QCrypToolLogo.svg"), QSize(512, 512)) {

        }

        Application::~Application() {

        }

    }
}
