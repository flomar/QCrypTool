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
            installEventFilter(this);
            connect(this, SIGNAL(signalRequestScalingIncrease()), &m_scalingSystem, SLOT(slotRequestScalingIncrease()));
            connect(this, SIGNAL(signalRequestScalingDecrease()), &m_scalingSystem, SLOT(slotRequestScalingDecrease()));
        }

        Application::~Application() {
            disconnect(this, SIGNAL(signalRequestScalingIncrease()), &m_scalingSystem, SLOT(slotRequestScalingIncrease()));
            disconnect(this, SIGNAL(signalRequestScalingDecrease()), &m_scalingSystem, SLOT(slotRequestScalingDecrease()));
        }

        bool Application::initialize() {
            // ATTENTION: Before we actually execute the application, we need
            // to initialize the individual systems. Order of execution is
            // very important here because systems depend on each other.
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

        bool Application::eventFilter(QObject *_object, QEvent *_event) {
            // signal key presses of Alt+/Alt- to the scaling system
            if(_event->type() == QEvent::KeyPress) {
                QKeyEvent *keyEvent = dynamic_cast<QKeyEvent*>(_event);
                if(keyEvent) {
                    if(keyEvent->key() == Qt::Key_Plus && (keyEvent->modifiers().testFlag(Qt::AltModifier) || keyEvent->modifiers().testFlag(Qt::ControlModifier))) {
                        emit signalRequestScalingIncrease();
                        return true;
                    }
                    if(keyEvent->key() == Qt::Key_Minus && (keyEvent->modifiers().testFlag(Qt::AltModifier) || keyEvent->modifiers().testFlag(Qt::ControlModifier))) {
                        emit signalRequestScalingDecrease();
                        return true;
                    }
                }
            }
            return QObject::eventFilter(_object, _event);
        }

    }
}
