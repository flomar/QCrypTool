// MainWindow.h

#ifndef _QCT_CORE_MAINWINDOW_H_
#define _QCT_CORE_MAINWINDOW_H_

#include <QCT.h>

#include <QCTDatabaseSystem.h>
#include <QCTHelpSystem.h>
#include <QCTScalingSystem.h>
#include <QCTSettingsSystem.h>
#include <QCTTranslationSystem.h>

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
        protected:
            virtual void initializeSignalsAndSlots() = 0;
        protected:
            bool eventFilter(QObject *_object, QEvent *_event);
        protected slots:
            virtual void slotChangedLanguage() = 0;
            virtual void slotChangedScaling() = 0;
        signals:
            void signalRequestContextHelp(const QString &_identifierContextHelp);
        private:
            void installEventFilterForMenusAndActions();
        protected:
            DatabaseSystem &m_databaseSystem;
            HelpSystem &m_helpSystem;
            ScalingSystem &m_scalingSystem;
            SettingsSystem &m_settingsSystem;
            TranslationSystem &m_translationSystem;
        };

    }
}

#endif
