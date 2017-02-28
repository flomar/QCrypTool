// QCrypToolApplication.h

#ifndef _QCT_QCRYPTOOL_QCRYPTOOLAPPLICATION_H_
#define _QCT_QCRYPTOOL_QCRYPTOOLAPPLICATION_H_

#include <QCrypTool/QCrypTool.h>
#include <Core/Application.h>

namespace QCT {
    namespace QCrypTool {

        class Application : public Core::Application {
            Q_OBJECT
        public:
            Application(int &_argc, char **_argv);
            virtual ~Application();
        };

    }
}

#endif
