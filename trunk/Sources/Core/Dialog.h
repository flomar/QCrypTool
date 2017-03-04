// Dialog.h

#ifndef _QCT_CORE_DIALOG_H_
#define _QCT_CORE_DIALOG_H_

#include <QCT.h>

#include <QCTDatabaseSystem.h>
#include <QCTHelpSystem.h>
#include <QCTScalingSystem.h>
#include <QCTTranslationSystem.h>

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
            virtual void initializeSignalsAndSlots() = 0;
            virtual void initializeVisuals() = 0;
            virtual void initializeData() = 0;
        protected:
            bool eventFilter(QObject *_object, QEvent *_event);
        signals:
            void signalRequestContextHelp(const QString &_identifierContextHelp);
        protected:
            DatabaseSystem &m_databaseSystem;
            HelpSystem &m_helpSystem;
            ScalingSystem &m_scalingSystem;
            TranslationSystem &m_translationSystem;
        };

    }
}

#endif
