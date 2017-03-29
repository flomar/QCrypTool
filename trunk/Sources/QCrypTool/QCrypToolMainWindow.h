// QCrypToolMainWindow.h

#ifndef _QCT_QCRYPTOOL_QCRYPTOOLMAINWINDOW_H_
#define _QCT_QCRYPTOOL_QCRYPTOOLMAINWINDOW_H_

#include <QCrypTool/QCrypTool.h>

#include <Core/MainWindow.h>
#include <Core/Editor.h>

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
        protected slots:
            virtual void slotInitializeSignalsAndSlots();
            virtual void slotInitializeLanguage();
            virtual void slotInitializeScaling();
        private slots:
            void slotTriggeredMenuFileActionNew();
            void slotTriggeredMenuFileActionOpen();
        private slots:
            void slotTriggeredMenuEditActionCut();
            void slotTriggeredMenuEditActionCopy();
            void slotTriggeredMenuEditActionPaste();
        private slots:
            void slotTriggeredMenuViewMenuFontActionNormalXS();
            void slotTriggeredMenuViewMenuFontActionNormalS();
            void slotTriggeredMenuViewMenuFontActionNormalM();
            void slotTriggeredMenuViewMenuFontActionNormalL();
            void slotTriggeredMenuViewMenuFontActionNormalXL();
            void slotTriggeredMenuViewMenuFontActionMonospaceXS();
            void slotTriggeredMenuViewMenuFontActionMonospaceS();
            void slotTriggeredMenuViewMenuFontActionMonospaceM();
            void slotTriggeredMenuViewMenuFontActionMonospaceL();
            void slotTriggeredMenuViewMenuFontActionMonospaceXL();
            void slotTriggeredMenuViewShowAsText();
            void slotTriggeredMenuViewShowAsHex();
        private slots:
            void slotTriggeredMenuDigitalSignaturesPKIActionCertificateStore();
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
            Core::Editor *getCurrentEditor();
        private:
            Ui::QCrypToolMainWindow *m_ui;
        };

    }
}

#endif
