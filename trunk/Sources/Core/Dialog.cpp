// Dialog.cpp

#include <Core/Dialog.h>

namespace QCT {
    namespace Core {

        Dialog::Dialog(QWidget *_parent, const Qt::WindowFlags _flags) :
            QDialog(_parent, _flags),
            m_databaseSystem(DatabaseSystem::instance()),
            m_helpSystem(HelpSystem::instance()),
            m_scalingSystem(ScalingSystem::instance()),
            m_settingsSystem(SettingsSystem::instance()),
            m_translationSystem(TranslationSystem::instance()) {
            installEventFilter(this);
            connect(this, SIGNAL(signalRequestContextHelp(QString)), &m_helpSystem, SLOT(slotRequestContextHelp(QString)));
        }

        Dialog::~Dialog() {
            disconnect(this, SIGNAL(signalRequestContextHelp(QString)), &m_helpSystem, SLOT(slotRequestContextHelp(QString)));
        }

        int Dialog::exec() {
            // make dialogs adhere to the application-wide scaling factor
            setFixedSize(size() * m_scalingSystem.getScaling());
            // initialize derived class
            initializeSignalsAndSlots();
            initializeVisuals();
            initializeData();
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
