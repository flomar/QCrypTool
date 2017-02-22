// CrypTool.cpp

#include <CrypTool/CrypTool.h>
#include <CrypTool/CrypToolApplication.h>

namespace QCrypTool {
    namespace CrypTool {

    }
}

int main(int _argc, char **_argv) {
    QCrypTool::CrypTool::Application application(_argc, _argv);
    return application.exec();
}
