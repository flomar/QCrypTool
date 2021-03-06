// MainWindow.cpp

#include <Core/MainWindow.h>

namespace QCT {
    namespace Core {

        MainWindow::MainWindow(QWidget *_parent, const Qt::WindowFlags _flags) :
            QMainWindow(_parent, _flags),
            m_databaseSystem(DatabaseSystem::instance()),
            m_optionsSystem(OptionsSystem::instance()),
            m_translationSystem(TranslationSystem::instance()),
            m_scalingSystem(ScalingSystem::instance()),
            m_helpSystem(HelpSystem::instance()) {
            connect(this, SIGNAL(signalRequestContextHelp(QString)), &m_helpSystem, SLOT(slotRequestContextHelp(QString)));
            connect(&m_translationSystem, SIGNAL(signalChangedLanguage()), this, SLOT(slotInitializeLanguage()));
            connect(&m_scalingSystem, SIGNAL(signalChangedScaling()), this, SLOT(slotInitializeScaling()));
        }

        MainWindow::~MainWindow() {
            disconnect(this, SIGNAL(signalRequestContextHelp(QString)), &m_helpSystem, SLOT(slotRequestContextHelp(QString)));
            disconnect(&m_translationSystem, SIGNAL(signalChangedLanguage()), this, SLOT(slotInitializeLanguage()));
            disconnect(&m_scalingSystem, SIGNAL(signalChangedScaling()), this, SLOT(slotInitializeScaling()));
        }

        void MainWindow::show() {
            // install event filters for menus and actions
            installEventFilterForMenusAndActions();
            // initialize derived class
            slotInitializeSignalsAndSlots();
            slotInitializeLanguage();
            slotInitializeScaling();
            slotActivateAndDeactivateMenusAndActions();
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
