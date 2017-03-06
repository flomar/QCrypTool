// Application.cpp

#include <Core/Application.h>

namespace QCT {
    namespace Core {

        Application::Application(int &_argc, char **_argv, const QString &_pathIconSvg, const QSize &_sizeIconSvg) :
            QApplication(_argc, _argv),
            m_databaseSystem(DatabaseSystem::instance()),
            m_optionsSystem(OptionsSystem::instance()),
            m_translationSystem(TranslationSystem::instance()),
            m_scalingSystem(ScalingSystem::instance()),
            m_helpSystem(HelpSystem::instance()) {
            setWindowIcon(Core::Utilities::Graphics::getIconFromSvg(_pathIconSvg, _sizeIconSvg));
        }

        Application::~Application() {

        }

        bool Application::initialize() {
            // ATTENTION: Before we actually execute the application, we need
            // to initialize the individual systems. Order of execution is
            // very important here because systems depend on each other.
            // This is certainly not the best design ever devised, but it
            // gets the job done.
            bool result = true;
            QString system = QString::null;
            if(!m_databaseSystem.initialize()) {
                result = false;
                system = "Database";
            }
            else if(!m_optionsSystem.initialize()) {
                result = false;
                system = "Options";
            }
            else if(!m_translationSystem.initialize()) {
                result = false;
                system = "Translation";
            }
            else if(!m_scalingSystem.initialize()) {
                result = false;
                system = "Scaling";
            }
            else if(!m_helpSystem.initialize()) {
                result = false;
                system = "Help";
            }
            if(!result) {
                Core::Utilities::MessageBoxes::execMessageBoxCritical(QString("The %1 System failed to launch.\n\nPlease reinstall the application to resolve this issue.").arg(system));
                return false;
            }
            return true;
        }

    }
}
