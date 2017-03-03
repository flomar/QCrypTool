// Dialog.h

#ifndef _QCT_CORE_DIALOG_H_
#define _QCT_CORE_DIALOG_H_

#include <QCT.h>
#include <QCTTranslation.h>

#include <Core/HelpSystem.h>
#include <Core/ScalingSystem.h>
#include <Core/Utilities.h>

namespace QCT {
    namespace Core {

        // This is the base class for all dialogs used throughout QCrypTool.
        // Each dialog implicitly registers/unregisters itself with the
        // help system. Note that, for the context help to work properly,
        // each dialog resource needs to have a unique object name.
        class Dialog : public QDialog {
            Q_OBJECT
        protected:
            Dialog(QWidget *_parent = 0, const Qt::WindowFlags _flags = Qt::WindowFlags());
            virtual ~Dialog();
        public slots:
            virtual int exec();
        protected slots:
            virtual void initializeSignalsAndSlots() = 0;
            virtual void initializeScaling() = 0;
            virtual void initializeData() = 0;
        protected:
            bool eventFilter(QObject *_object, QEvent *_event);
        signals:
            void signalRequestContextHelp(const QString &_identifierContextHelp);
        };

    }
}

#endif
