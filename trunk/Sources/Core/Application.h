// Application.h

#ifndef _QCT_CORE_APPLICATION_H_
#define _QCT_CORE_APPLICATION_H_

#include <QCT.h>
#include <QCTTranslation.h>

#include <Core/HelpSystem.h>
#include <Core/ScalingSystem.h>
#include <Core/Utilities.h>

namespace QCT {
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
