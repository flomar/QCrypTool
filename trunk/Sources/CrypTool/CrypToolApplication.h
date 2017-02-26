// CrypToolApplication.h

#ifndef _QCRYPTOOL_CRYPTOOL_APPLICATION_H_
#define _QCRYPTOOL_CRYPTOOL_APPLICATION_H_

#include <CrypTool/CrypTool.h>
#include <Core/Application.h>

namespace QCrypTool {
    namespace CrypTool {

        class Application : public Core::Application {
            Q_OBJECT
        public:
            Application(int &_argc, char **_argv, const QVector<QString> &_vectorLanguages);
            virtual ~Application();
        };

    }
}

#endif
