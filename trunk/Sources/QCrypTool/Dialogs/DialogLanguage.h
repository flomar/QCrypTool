// DialogLanguage.h

#ifndef _QCT_QCRYPTOOL_DIALOGS_DIALOGLANGUAGE_H_
#define _QCT_QCRYPTOOL_DIALOGS_DIALOGLANGUAGE_H_

#include <QCrypTool/QCrypTool.h>
#include <Core/Dialog.h>

namespace Ui {
    class DialogLanguage;
}

namespace QCT {
    namespace QCrypTool {
        namespace Dialogs {

            class DialogLanguage : public Core::Dialog {
                Q_OBJECT
            public:
                DialogLanguage(QWidget *_parent = 0, Qt::WindowFlags _flags = Qt::WindowFlags());
                virtual ~DialogLanguage();
            protected slots:
                virtual void slotInitializeSignalsAndSlots();
                virtual void slotInitializeLanguage();
                virtual void slotInitializeScaling();
            private:
                Ui::DialogLanguage *m_ui;
            private slots:
                void slotClickedDialogLanguagePushButtonCancel();
                void slotClickedDialogLanguagePushButtonOK();
            };

        }
    }
}

#endif
