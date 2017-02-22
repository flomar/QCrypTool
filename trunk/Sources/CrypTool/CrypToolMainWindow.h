// CrypToolMainWindow.h

#ifndef _QCRYPTOOL_CRYPTOOL_CRYPTOOLMAINWINDOW_H_
#define _QCRYPTOOL_CRYPTOOL_CRYPTOOLMAINWINDOW_H_

#include <CrypTool/CrypTool.h>
#include <Core/MainWindow.h>

namespace QCrypTool {
    namespace CrypTool {

        class MainWindow : public Core::MainWindow {
            Q_OBJECT
        public:
            MainWindow(QWidget *_parent = 0, const Qt::WindowFlags _flags = Qt::WindowFlags());
            virtual ~MainWindow();
        };

    }
}

#endif
