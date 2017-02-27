// Application.h

#ifndef _QCRYPTOOL_CORE_APPLICATION_H_
#define _QCRYPTOOL_CORE_APPLICATION_H_

#include <QCrypTool.h>
#include <QCrypToolTranslation.h>

namespace QCrypTool {
    namespace Core {

        class Application : public QApplication {
            Q_OBJECT
        public:
            Application(int &_argc, char **_argv);
            virtual ~Application();
        public:
            int exec();
        };

    }
}


#endif
