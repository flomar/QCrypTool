// DialogAbout.h

#ifndef _QCRYPTOOL_CRYPTOOL_DIALOGS_DIALOGABOUT_H_
#define _QCRYPTOOL_CRYPTOOL_DIALOGS_DIALOGABOUT_H_

#include <CrypTool/CrypTool.h>
#include <Core/Dialog.h>

namespace Ui {
    class DialogAbout;
}

namespace QCrypTool {
    namespace CrypTool {
        namespace Dialogs {

            class DialogAbout : public Core::Dialog {
                Q_OBJECT
            public:
                DialogAbout(QWidget *_parent = 0, Qt::WindowFlags _flags = Qt::WindowFlags());
                virtual ~DialogAbout();
            protected:
                virtual void initializeSignalsAndSlots();
                virtual void initializeData();
            private:
                Ui::DialogAbout *m_ui;
            private slots:
                void slotClickedDialogAboutPushButtonClose(const bool _checked);
            };

        }
    }
}

#endif
