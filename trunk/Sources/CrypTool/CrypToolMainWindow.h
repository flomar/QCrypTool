// CrypToolMainWindow.h

#ifndef _QCRYPTOOL_CRYPTOOL_CRYPTOOLMAINWINDOW_H_
#define _QCRYPTOOL_CRYPTOOL_CRYPTOOLMAINWINDOW_H_

#include <CrypTool/CrypTool.h>
#include <Core/MainWindow.h>

namespace Ui {
    class CrypToolMainWindow;
}

namespace QCrypTool {
    namespace CrypTool {

        class MainWindow : public Core::MainWindow {
            Q_OBJECT
        public:
            MainWindow(QWidget *_parent = 0, const Qt::WindowFlags _flags = Qt::WindowFlags());
            virtual ~MainWindow();
        protected:
            virtual void initializeSignalsAndSlots();
        protected slots:
            virtual void slotChangedLanguage();
        private slots:
            void slotTriggeredMenuDigitalSignaturesPKIMenuPKIActionCreateImportKeys();
            void slotTriggeredMenuDigitalSignaturesPKIMenuPKIActionDisplayExportKeys();
            void slotTriggeredMenuDigitalSignaturesPKIActionCreateSignature();
            void slotTriggeredMenuDigitalSignaturesPKIActionVerifySignature();
            void slotTriggeredMenuDigitalSignaturesPKIActionExtractSignature();
            void slotTriggeredMenuDigitalSignaturesPKIActionSignatureDemonstration();
        private slots:
            void slotTriggeredMenuIndividualProceduresMenuHashActionMD4();
            void slotTriggeredMenuIndividualProceduresMenuHashActionMD5();
            void slotTriggeredMenuIndividualProceduresMenuHashActionSHA();
            void slotTriggeredMenuIndividualProceduresMenuHashActionSHA1();
            void slotTriggeredMenuIndividualProceduresMenuHashActionSHA256();
            void slotTriggeredMenuIndividualProceduresMenuHashActionSHA512();
            void slotTriggeredMenuIndividualProceduresMenuHashActionRIPEMD160();
        private slots:
            void slotTriggeredMenuOptionsActionLanguage();
        private slots:
            void slotTriggeredMenuHelpActionAboutQCrypTool();
        private:
            Ui::CrypToolMainWindow *m_ui;
        };

    }
}

#endif
