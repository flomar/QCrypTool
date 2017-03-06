// DialogAboutQCrypTool.h

#ifndef _QCT_QCRYPTOOL_DIALOGS_DIALOGABOUTQCRYPTOOL_H_
#define _QCT_QCRYPTOOL_DIALOGS_DIALOGABOUTQCRYPTOOL_H_

#include <QCrypTool/QCrypTool.h>
#include <Core/Dialog.h>

namespace Ui {
    class DialogAboutQCrypTool;
}

namespace QCT {
    namespace QCrypTool {
        namespace Dialogs {

            class DialogAboutQCrypTool : public Core::Dialog {
                Q_OBJECT
            public:
                DialogAboutQCrypTool(QWidget *_parent = 0, Qt::WindowFlags _flags = Qt::WindowFlags());
                virtual ~DialogAboutQCrypTool();
            protected slots:
                virtual void slotInitializeSignalsAndSlots();
                virtual void slotInitializeLanguage();
                virtual void slotInitializeScaling();
            private:
                Ui::DialogAboutQCrypTool *m_ui;
            private slots:
                void slotClickedDialogAboutQCrypToolPushButtonClose();
            };

        }
    }
}

#endif
