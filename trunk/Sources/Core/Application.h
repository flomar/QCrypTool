// Application.h

#ifndef _QCT_CORE_APPLICATION_H_
#define _QCT_CORE_APPLICATION_H_

#include <QCT.h>

#include <QCTDatabaseSystem.h>
#include <QCTOptionsSystem.h>
#include <QCTTranslationSystem.h>
#include <QCTScalingSystem.h>
#include <QCTHelpSystem.h>

#include <Core/Utilities.h>

namespace QCT {
    namespace Core {

        class Application : public QApplication {
            Q_OBJECT
        public:
            Application(int &_argc, char **_argv, const QString &_pathIconSvg, const QSize &_sizeIconSvg);
            virtual ~Application();
        public:
            bool initialize();
        protected:
            DatabaseSystem &m_databaseSystem;
            OptionsSystem &m_optionsSystem;
            TranslationSystem &m_translationSystem;
            ScalingSystem &m_scalingSystem;
            HelpSystem &m_helpSystem;
        };

    }
}


#endif
