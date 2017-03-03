// MainWindow.h

#ifndef _QCT_CORE_MAINWINDOW_H_
#define _QCT_CORE_MAINWINDOW_H_

#include <QCT.h>
#include <QCTTranslation.h>

#include <Core/HelpSystem.h>
#include <Core/ScalingSystem.h>
#include <Core/Utilities.h>

namespace QCT {
    namespace Core {

        // This is the base class for all main windows used throughout
        // QCrypTool. Each main window implicitly registers/unregisters
        // itself with the help system. Note that, for the context help
        // to work properly, each menu and action within the main window
        // needs to have a unique object name.
        class MainWindow : public QMainWindow {
            Q_OBJECT
        protected:
            MainWindow(QWidget *_parent = 0, const Qt::WindowFlags _flags = Qt::WindowFlags());
            virtual ~MainWindow();
        public slots:
            void show();
        protected:
            virtual void initializeSignalsAndSlots() = 0;
        protected:
            bool eventFilter(QObject *_object, QEvent *_event);
        protected slots:
            virtual void slotChangedLanguage() = 0;
        signals:
            void signalRequestContextHelp(const QString &_identifierContextHelp);
        private:
            void installEventFilterForMenusAndActions();
        };

    }
}

#endif
