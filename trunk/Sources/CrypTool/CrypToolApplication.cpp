// CrypToolApplication.cpp

#include <CrypTool/CrypToolApplication.h>

namespace QCrypTool {
    namespace CrypTool {

        Application::Application(int &_argc, char **_argv, const QVector<QString> &_vectorLanguages) :
            Core::Application(_argc, _argv, _vectorLanguages) {

        }

        Application::~Application() {

        }

    }
}
