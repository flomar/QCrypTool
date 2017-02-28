// Dialog.cpp

#include <Core/Dialog.h>
#include <Core/HelpSystem.h>

namespace QCT {
    namespace Core {

        Dialog::Dialog(QWidget *_parent, const Qt::WindowFlags _flags) :
            QDialog(_parent, _flags) {
            // install event filter
            installEventFilter(this);
            // register with help system
            connect(this, SIGNAL(signalRequestContextHelp(QString)), &HelpSystem::instance(), SLOT(slotRequestContextHelp(QString)));
        }

        Dialog::~Dialog() {
            // unregister with help system
            disconnect(this, SIGNAL(signalRequestContextHelp(QString)), &HelpSystem::instance(), SLOT(slotRequestContextHelp(QString)));
        }

        int Dialog::exec() {
            // make dialogs non-resizable
            setFixedSize(size());
            // initialize signals and slots in derived class
            initializeSignalsAndSlots();
            // initialize data in derived class
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
                emit signalRequestContextHelp(objectName());
                return true;
            }
            return QObject::eventFilter(_object, _event);
        }

    }
}
