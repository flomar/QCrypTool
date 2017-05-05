// MainWindow.h

#ifndef _QCT_CORE_MAINWINDOW_H_
#define _QCT_CORE_MAINWINDOW_H_

#include <QCT.h>

#include <QCTDatabaseSystem.h>
#include <QCTOptionsSystem.h>
#include <QCTTranslationSystem.h>
#include <QCTScalingSystem.h>
#include <QCTHelpSystem.h>

#include <Core/Utilities.h>

namespace QCT {
    namespace Core {

        class MainWindow : public QMainWindow {
            Q_OBJECT
        protected:
            MainWindow(QWidget *_parent = 0, const Qt::WindowFlags _flags = Qt::WindowFlags());
            virtual ~MainWindow();
        public slots:
            void show();
        protected slots:
            virtual void slotInitializeSignalsAndSlots() = 0;
            virtual void slotInitializeLanguage() = 0;
            virtual void slotInitializeScaling() = 0;
            virtual void slotActivateAndDeactivateMenusAndActions() = 0;
        protected:
            bool eventFilter(QObject *_object, QEvent *_event);
        signals:
            void signalRequestContextHelp(const QString &_identifierContextHelp);
        private:
            void installEventFilterForMenusAndActions();
        protected:
            DatabaseSystem &m_databaseSystem;
            OptionsSystem &m_optionsSystem;
            TranslationSystem &m_translationSystem;
            ScalingSystem &m_scalingSystem;
            HelpSystem &m_helpSystem;
        };

    }
}

#endif
