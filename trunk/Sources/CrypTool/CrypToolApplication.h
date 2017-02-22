// CrypToolApplication.h

#ifndef _QCRYPTOOL_CRYPTOOL_APPLICATION_H_
#define _QCRYPTOOL_CRYPTOOL_APPLICATION_H_

#include <CrypTool/CrypTool.h>

namespace QCrypTool {
    namespace CrypTool {

        class Application;
        class MainWindow;

        class Application : public QApplication {
            Q_OBJECT
        public:
            Application(int &_argc, char **_argv);
            virtual ~Application();
        private:
            QSharedPointer<MainWindow> m_mainWindow;
        };

    }
}

#endif
