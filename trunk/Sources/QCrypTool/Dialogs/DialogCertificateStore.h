// DialogCertificateStore.h

#ifndef _QCT_QCRYPTOOL_DIALOGS_DIALOGCERTIFICATESTORE_H_
#define _QCT_QCRYPTOOL_DIALOGS_DIALOGCERTIFICATESTORE_H_

#include <QCrypTool/QCrypTool.h>
#include <Core/Dialog.h>

namespace Ui {
    class DialogCertificateStore;
}

namespace QCT {
    namespace QCrypTool {
        namespace Dialogs {

            class DialogCertificateStore : public Core::Dialog {
                Q_OBJECT
            public:
                DialogCertificateStore(QWidget *_parent = 0, Qt::WindowFlags _flags = Qt::WindowFlags());
                virtual ~DialogCertificateStore();
            protected slots:
                virtual void slotInitializeSignalsAndSlots();
                virtual void slotInitializeLanguage();
                virtual void slotInitializeScaling();
            private:
                Ui::DialogCertificateStore *m_ui;
            private slots:
                void slotClickedDialogCertificateStorePushButtonClose();
            };

        }
    }
}

#endif
