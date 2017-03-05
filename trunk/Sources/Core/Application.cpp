// Application.cpp

#include <Core/Application.h>

namespace QCT {
    namespace Core {

        Application::Application(int &_argc, char **_argv, const QString &_pathIconSvg, const QSize &_sizeIconSvg) :
            QApplication(_argc, _argv),
            m_databaseSystem(DatabaseSystem::instance()),
            m_helpSystem(HelpSystem::instance()),
            m_scalingSystem(ScalingSystem::instance()),
            m_translationSystem(TranslationSystem::instance()) {
            setWindowIcon(Core::Utilities::Graphics::getIconFromSvg(_pathIconSvg, _sizeIconSvg));
        }

        Application::~Application() {

        }

        int Application::exec() {
            m_databaseSystem.initializeDatabase();
            m_scalingSystem.initialize();
            m_translationSystem.initialize();
            return QApplication::exec();
        }

    }
}
