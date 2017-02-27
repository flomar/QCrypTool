// CrypToolMainWindow.cpp

#include <CrypTool/CrypToolMainWindow.h>
#include <ui_CrypToolMainWindow.h>

#include <CrypTool/Dialogs/DialogLanguage.h>
#include <CrypTool/Dialogs/DialogAbout.h>

namespace QCrypTool {
    namespace CrypTool {

        MainWindow::MainWindow(QWidget *_parent, const Qt::WindowFlags _flags) :
            Core::MainWindow(_parent, _flags),
            m_ui(new Ui::CrypToolMainWindow) {
            m_ui->setupUi(this);
            m_ui->menuBar->setNativeMenuBar(false);
        }

        MainWindow::~MainWindow() {
            delete m_ui;
        }

        void MainWindow::initializeSignalsAndSlots() {
            connect(m_ui->MenuDigitalSignaturesPKIMenuPKIActionCreateImportKeys, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuDigitalSignaturesPKIMenuPKIActionCreateImportKeys()));
            connect(m_ui->MenuDigitalSignaturesPKIMenuPKIActionDisplayExportKeys, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuDigitalSignaturesPKIMenuPKIActionDisplayExportKeys()));
            connect(m_ui->MenuDigitalSignaturesPKIActionCreateSignature, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuDigitalSignaturesPKIActionCreateSignature()));
            connect(m_ui->MenuDigitalSignaturesPKIActionVerifySignature, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuDigitalSignaturesPKIActionVerifySignature()));
            connect(m_ui->MenuDigitalSignaturesPKIActionExtractSignature, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuDigitalSignaturesPKIActionExtractSignature()));
            connect(m_ui->MenuDigitalSignaturesPKIActionSignatureDemonstration, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuDigitalSignaturesPKIActionSignatureDemonstration()));
            connect(m_ui->MenuIndividualProceduresMenuHashActionMD4, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuIndividualProceduresMenuHashActionMD4()));
            connect(m_ui->MenuIndividualProceduresMenuHashActionMD5, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuIndividualProceduresMenuHashActionMD5()));
            connect(m_ui->MenuIndividualProceduresMenuHashActionSHA, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuIndividualProceduresMenuHashActionSHA()));
            connect(m_ui->MenuIndividualProceduresMenuHashActionSHA1, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuIndividualProceduresMenuHashActionSHA1()));
            connect(m_ui->MenuIndividualProceduresMenuHashActionSHA256, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuIndividualProceduresMenuHashActionSHA256()));
            connect(m_ui->MenuIndividualProceduresMenuHashActionSHA512, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuIndividualProceduresMenuHashActionSHA512()));
            connect(m_ui->MenuIndividualProceduresMenuHashActionRIPEMD160, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuIndividualProceduresMenuHashActionRIPEMD160()));
            connect(m_ui->MenuOptionsActionLanguage, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuOptionsActionLanguage()));
            connect(m_ui->MenuHelpActionAboutQCrypTool, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuHelpActionAboutQCrypTool()));
        }

        void MainWindow::slotChangedLanguage() {
            setWindowTitle(QString("%1 %2").arg(getApplicationName()).arg(getApplicationVersion()));
            // TODO/FIXME: add more translations
            m_ui->MenuDigitalSignaturesPKI->setTitle(trStr(I18N_CRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKI));
            m_ui->MenuDigitalSignaturesPKIMenuPKI->setTitle(trStr(I18N_CRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIMENUPKI));
            m_ui->MenuDigitalSignaturesPKIMenuPKIActionCreateImportKeys->setText(trStr(I18N_CRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIMENUPKIACTIONCREATEIMPORTKEYS));
            m_ui->MenuDigitalSignaturesPKIMenuPKIActionDisplayExportKeys->setText(trStr(I18N_CRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIMENUPKIACTIONDISPLAYEXPORTKEYS));
            m_ui->MenuDigitalSignaturesPKIActionCreateSignature->setText(trStr(I18N_CRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONCREATESIGNATURE));
            m_ui->MenuDigitalSignaturesPKIActionVerifySignature->setText(trStr(I18N_CRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONVERIFYSIGNATURE));
            m_ui->MenuDigitalSignaturesPKIActionExtractSignature->setText(trStr(I18N_CRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONEXTRACTSIGNATURE));
            m_ui->MenuDigitalSignaturesPKIActionSignatureDemonstration->setText(trStr(I18N_CRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONSIGNATUREDEMONSTRATION));
            m_ui->MenuHelp->setTitle(trStr(I18N_CRYPTOOL_MAINWINDOW_MENUHELP));
            m_ui->MenuHelpActionStartingPage->setText(trStr(I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONSTARTINGPAGE));
            m_ui->MenuHelpActionIndex->setText(trStr(I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONINDEX));
            m_ui->MenuHelpActionScenariosTutorials->setText(trStr(I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONSCENARIOSTUTORIALS));
            m_ui->MenuHelpActionReadme->setText(trStr(I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONREADME));
            m_ui->MenuHelpActionCTBook->setText(trStr(I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONCTBOOK));
            m_ui->MenuHelpActionPresentation->setText(trStr(I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONPRESENTATION));
            m_ui->MenuHelpActionAboutQCrypTool->setText(trStr(I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONABOUTQCRYPTOOL));
        }

        void MainWindow::slotTriggeredMenuDigitalSignaturesPKIMenuPKIActionCreateImportKeys() {
            QMessageBox messageBox(QMessageBox::Information, "TODO/FIXME", "MainWindow::slotTriggeredMenuDigitalSignaturesPKIMenuPKIActionCreateImportKeys()");
            messageBox.exec();
        }

        void MainWindow::slotTriggeredMenuDigitalSignaturesPKIMenuPKIActionDisplayExportKeys() {
            QMessageBox messageBox(QMessageBox::Information, "TODO/FIXME", "MainWindow::slotTriggeredMenuDigitalSignaturesPKIMenuPKIActionDisplayExportKeys()");
            messageBox.exec();
        }

        void MainWindow::slotTriggeredMenuDigitalSignaturesPKIActionCreateSignature() {
            QMessageBox messageBox(QMessageBox::Information, "TODO/FIXME", "MainWindow::slotTriggeredMenuDigitalSignaturesPKIActionCreateSignature()");
            messageBox.exec();
        }

        void MainWindow::slotTriggeredMenuDigitalSignaturesPKIActionVerifySignature() {
            QMessageBox messageBox(QMessageBox::Information, "TODO/FIXME", "MainWindow::slotTriggeredMenuDigitalSignaturesPKIActionVerifySignature()");
            messageBox.exec();
        }

        void MainWindow::slotTriggeredMenuDigitalSignaturesPKIActionExtractSignature() {
            QMessageBox messageBox(QMessageBox::Information, "TODO/FIXME", "MainWindow::slotTriggeredMenuDigitalSignaturesPKIActionExtractSignature()");
            messageBox.exec();
        }

        void MainWindow::slotTriggeredMenuDigitalSignaturesPKIActionSignatureDemonstration() {
            QMessageBox messageBox(QMessageBox::Information, "TODO/FIXME", "MainWindow::slotTriggeredMenuDigitalSignaturesPKIActionSignatureDemonstration()");
            messageBox.exec();
        }

        void MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionMD4() {
            QMessageBox messageBox(QMessageBox::Information, "TODO/FIXME", "MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionMD4()");
            messageBox.exec();
        }

        void MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionMD5() {
            QMessageBox messageBox(QMessageBox::Information, "TODO/FIXME", "MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionMD5()");
            messageBox.exec();
        }

        void MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionSHA() {
            QMessageBox messageBox(QMessageBox::Information, "TODO/FIXME", "MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionSHA()");
            messageBox.exec();
        }

        void MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionSHA1() {
            QMessageBox messageBox(QMessageBox::Information, "TODO/FIXME", "MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionSHA1()");
            messageBox.exec();
        }

        void MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionSHA256() {
            QMessageBox messageBox(QMessageBox::Information, "TODO/FIXME", "MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionSHA256()");
            messageBox.exec();
        }

        void MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionSHA512() {
            QMessageBox messageBox(QMessageBox::Information, "TODO/FIXME", "MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionSHA512()");
            messageBox.exec();
        }

        void MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionRIPEMD160() {
            QMessageBox messageBox(QMessageBox::Information, "TODO/FIXME", "MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionRIPEMD160()");
            messageBox.exec();
        }

        void MainWindow::slotTriggeredMenuOptionsActionLanguage() {
            Dialogs::DialogLanguage dialogLanguage;
            dialogLanguage.exec();
        }

        void MainWindow::slotTriggeredMenuHelpActionAboutQCrypTool() {
            Dialogs::DialogAbout dialogAbout;
            dialogAbout.exec();
        }

    }
}
