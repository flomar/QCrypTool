// Application.h

#ifndef _QCT_CORE_APPLICATION_H_
#define _QCT_CORE_APPLICATION_H_

#include <QCT.h>

#include <QCTDatabaseSystem.h>
#include <QCTHelpSystem.h>
#include <QCTScalingSystem.h>
#include <QCTSettingsSystem.h>
#include <QCTTranslationSystem.h>

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
        protected:
            DatabaseSystem &m_databaseSystem;
            HelpSystem &m_helpSystem;
            ScalingSystem &m_scalingSystem;
            SettingsSystem &m_settingsSystem;
            TranslationSystem &m_translationSystem;
        };

    }
}


#endif
