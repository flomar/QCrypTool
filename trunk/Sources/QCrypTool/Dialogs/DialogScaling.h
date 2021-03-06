// DialogScaling.h

#ifndef _QCT_QCRYPTOOL_DIALOGS_DIALOGSCALING_H_
#define _QCT_QCRYPTOOL_DIALOGS_DIALOGSCALING_H_

#include <QCrypTool/QCrypTool.h>
#include <Core/Dialog.h>

namespace Ui {
    class DialogScaling;
}

namespace QCT {
    namespace QCrypTool {
        namespace Dialogs {

            class DialogScaling : public Core::Dialog {
                Q_OBJECT
            public:
                DialogScaling(QWidget *_parent = 0, Qt::WindowFlags _flags = Qt::WindowFlags());
                virtual ~DialogScaling();
            protected slots:
                virtual void slotInitializeSignalsAndSlots();
                virtual void slotInitializeLanguage();
                virtual void slotInitializeScaling();
            private:
                Ui::DialogScaling *m_ui;
            private slots:
                void slotClickedDialogScalingPushButtonCancel();
                void slotClickedDialogScalingPushButtonOK();
            };

        }
    }
}

#endif
