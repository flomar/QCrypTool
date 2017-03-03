// QCrypToolMainWindow.h

#ifndef _QCT_QCRYPTOOL_QCRYPTOOLMAINWINDOW_H_
#define _QCT_QCRYPTOOL_QCRYPTOOLMAINWINDOW_H_

#include <QCrypTool/QCrypTool.h>
#include <Core/MainWindow.h>

namespace Ui {
    class QCrypToolMainWindow;
}

namespace QCT {
    namespace QCrypTool {

        class MainWindow : public Core::MainWindow {
            Q_OBJECT
        public:
            MainWindow(QWidget *_parent = 0, const Qt::WindowFlags _flags = Qt::WindowFlags());
            virtual ~MainWindow();
        protected:
            virtual void initializeSignalsAndSlots();
        protected slots:
            virtual void slotChangedLanguage();
            virtual void slotChangedScaling();
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
            void slotTriggeredMenuOptionsActionScaling();
        private slots:
            void slotTriggeredMenuHelpActionAboutQCrypTool();
        private:
            Ui::QCrypToolMainWindow *m_ui;
        };

    }
}

#endif
