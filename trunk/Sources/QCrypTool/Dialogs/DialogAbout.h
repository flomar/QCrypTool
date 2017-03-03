// DialogAbout.h

#ifndef _QCT_QCRYPTOOL_DIALOGS_DIALOGABOUT_H_
#define _QCT_QCRYPTOOL_DIALOGS_DIALOGABOUT_H_

#include <QCrypTool/QCrypTool.h>
#include <Core/Dialog.h>

namespace Ui {
    class DialogAbout;
}

namespace QCT {
    namespace QCrypTool {
        namespace Dialogs {

            class DialogAbout : public Core::Dialog {
                Q_OBJECT
            public:
                DialogAbout(QWidget *_parent = 0, Qt::WindowFlags _flags = Qt::WindowFlags());
                virtual ~DialogAbout();
            protected:
                virtual void initializeSignalsAndSlots();
                virtual void initializeScaling();
                virtual void initializeData();
            private:
                Ui::DialogAbout *m_ui;
            private slots:
                void slotClickedDialogAboutPushButtonClose();
            };

        }
    }
}

#endif
