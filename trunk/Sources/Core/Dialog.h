// Dialog.h

#ifndef _QCT_CORE_DIALOG_H_
#define _QCT_CORE_DIALOG_H_

#include <QCT.h>

#include <QCTDatabaseSystem.h>
#include <QCTOptionsSystem.h>
#include <QCTTranslationSystem.h>
#include <QCTScalingSystem.h>
#include <QCTHelpSystem.h>

#include <Core/Utilities.h>

namespace QCT {
    namespace Core {

        class Dialog : public QDialog {
            Q_OBJECT
        protected:
            Dialog(QWidget *_parent = 0, const Qt::WindowFlags _flags = Qt::WindowFlags());
            virtual ~Dialog();
        public slots:
            virtual int exec();
        protected slots:
            virtual void slotInitializeSignalsAndSlots() = 0;
            virtual void slotInitializeLanguage() = 0;
            virtual void slotInitializeScaling() = 0;
        protected:
            bool eventFilter(QObject *_object, QEvent *_event);
        signals:
            void signalRequestContextHelp(const QString &_identifierContextHelp);
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
