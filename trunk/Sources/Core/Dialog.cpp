// Dialog.cpp

#include <Core/Dialog.h>

namespace QCT {
    namespace Core {

        Dialog::Dialog(QWidget *_parent, const Qt::WindowFlags _flags) :
            QDialog(_parent, _flags),
            m_databaseSystem(DatabaseSystem::instance()),
            m_optionsSystem(OptionsSystem::instance()),
            m_translationSystem(TranslationSystem::instance()),
            m_scalingSystem(ScalingSystem::instance()),
            m_helpSystem(HelpSystem::instance()) {
            installEventFilter(this);
            connect(this, SIGNAL(signalRequestContextHelp(QString)), &m_helpSystem, SLOT(slotRequestContextHelp(QString)));
            connect(&m_translationSystem, SIGNAL(signalChangedLanguage()), this, SLOT(slotInitializeLanguage()));
            connect(&m_scalingSystem, SIGNAL(signalChangedScaling()), this, SLOT(slotInitializeScaling()));
        }

        Dialog::~Dialog() {
            disconnect(this, SIGNAL(signalRequestContextHelp(QString)), &m_helpSystem, SLOT(slotRequestContextHelp(QString)));
            disconnect(&m_translationSystem, SIGNAL(signalChangedLanguage()), this, SLOT(slotInitializeLanguage()));
            disconnect(&m_scalingSystem, SIGNAL(signalChangedScaling()), this, SLOT(slotInitializeScaling()));
        }

        int Dialog::exec() {
            // make dialogs adhere to the application-wide scaling factor
            setFixedSize(baseSize() * m_scalingSystem.getScaling() / 100);
            // initialize derived class
            slotInitializeSignalsAndSlots();
            slotInitializeLanguage();
            slotInitializeScaling();
            // invoke base class implementation
            return QDialog::exec();
        }

        bool Dialog::eventFilter(QObject *_object, QEvent *_event) {
            // signal key presses of F1 to the help system
            if(_event->type() == QEvent::KeyPress) {
                QKeyEvent *keyEvent = static_cast<QKeyEvent*>(_event);
                if(keyEvent) {
                    if(keyEvent->key() == Qt::Key_F1) {
                        emit signalRequestContextHelp(objectName());
                        return true;
                    }
                }
            }
            // signal mouse clicks on "?" to the help system
            if(_event->type() == QEvent::EnterWhatsThisMode) {
                QWhatsThis::leaveWhatsThisMode();
                emit signalRequestContextHelp(objectName());
                return true;
            }
            return QObject::eventFilter(_object, _event);
        }

    }
}
