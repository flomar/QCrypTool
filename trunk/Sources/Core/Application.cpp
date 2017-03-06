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

        int Application::exec() {
            // ATTENTION: Before we actually execute the application, we need
            // to initialize the individual systems. Order of execution is
            // very important here because systems depend on each other.
            // This is certainly not the best design ever devised, but it
            // gets the job done.
            m_databaseSystem.initialize();
            m_optionsSystem.initialize();
            m_translationSystem.initialize();
            m_scalingSystem.initialize();
            m_helpSystem.initialize();
            return QApplication::exec();
        }

    }
}
