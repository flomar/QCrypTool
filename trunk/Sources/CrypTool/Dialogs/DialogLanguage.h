// DialogLanguage.h

#ifndef _QCRYPTOOL_CRYPTOOL_DIALOGS_DIALOGLANGUAGE_H_
#define _QCRYPTOOL_CRYPTOOL_DIALOGS_DIALOGLANGUAGE_H_

#include <CrypTool/CrypTool.h>
#include <Core/Dialog.h>

namespace Ui {
    class DialogLanguage;
}

namespace QCrypTool {
    namespace CrypTool {
        namespace Dialogs {

            class DialogLanguage : public Core::Dialog {
                Q_OBJECT
            public:
                DialogLanguage(QWidget *_parent = 0, Qt::WindowFlags _flags = Qt::WindowFlags());
                virtual ~DialogLanguage();
            protected:
                virtual void initializeSignalsAndSlots();
                virtual void initializeData();
            private:
                Ui::DialogLanguage *m_ui;
            };

        }
    }
}

#endif
