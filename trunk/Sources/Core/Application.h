// Application.h

#ifndef _QCRYPTOOL_CORE_APPLICATION_H_
#define _QCRYPTOOL_CORE_APPLICATION_H_

#include <QCrypTool.h>
#include <QCrypToolTranslation.h>

#include <Core/Utilities.h>

namespace QCrypTool {
    namespace Core {

        class Application : public QApplication {
            Q_OBJECT
        public:
            Application(int &_argc, char **_argv, const QString &_pathIconSvg, const QSize &_sizeIconSvg);
            virtual ~Application();
        public:
            int exec();
        };

    }
}


#endif
