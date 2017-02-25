// MainWindow.cpp

#include <Core/MainWindow.h>
#include <Core/HelpSystem.h>

namespace QCrypTool {
    namespace Core {

        MainWindow::MainWindow(QWidget *_parent, const Qt::WindowFlags _flags) :
            QMainWindow(_parent, _flags),
            m_translator(Translator::instance()) {
            // register with help system
            connect(this, SIGNAL(signalRequestContextHelp(QString)), &HelpSystem::instance(), SLOT(slotRequestContextHelp(QString)));
        }

        MainWindow::~MainWindow() {
            // unregister with help system
            disconnect(this, SIGNAL(signalRequestContextHelp(QString)), &HelpSystem::instance(), SLOT(slotRequestContextHelp(QString)));
        }

        void MainWindow::show() {
            // install event filters for menus and actions
            installEventFilterForMenusAndActions();
            // initialize signals and slots in derived class
            initializeSignalsAndSlots();
            // invoke base class implementation
            QMainWindow::show();
        }

        bool MainWindow::eventFilter(QObject *_object, QEvent *_event) {
            // signal key presses of F1 to the help system
            if(_event->type() == QEvent::KeyPress) {
                QKeyEvent *keyEvent = dynamic_cast<QKeyEvent*>(_event);
                if(keyEvent) {
                    if(keyEvent->key() == Qt::Key_F1) {
                        QMenu *menu = dynamic_cast<QMenu*>(_object);
                        if(menu) {
                            QAction *action = menu->actionAt(menu->mapFromGlobal(QCursor::pos()));
                            if(action) {
                                emit signalRequestContextHelp(action->objectName());
                                return true;
                            }
                            emit signalRequestContextHelp(menu->objectName());
                            return true;
                        }
                    }
                }
            }
            return QObject::eventFilter(_object, _event);
        }

        void MainWindow::installEventFilterForMenusAndActions() {
            if(menuBar()) {
                QList<QMenu*> menus = menuBar()->findChildren<QMenu*>();
                foreach(QMenu *menu, menus) {
                    menu->installEventFilter(this);
                    QList<QAction*> actions = menu->actions();
                    foreach(QAction *action, actions) {
                        action->installEventFilter(this);
                    }
                }
            }
        }

    }
}
