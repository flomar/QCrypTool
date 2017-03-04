// QCrypToolMainWindow.cpp

#include <QCrypTool/QCrypToolMainWindow.h>
#include <ui_QCrypToolMainWindow.h>

#include <QCrypTool/Dialogs/DialogCertificateStore.h>
#include <QCrypTool/Dialogs/DialogLanguage.h>
#include <QCrypTool/Dialogs/DialogScaling.h>
#include <QCrypTool/Dialogs/DialogAboutQCrypTool.h>

namespace QCT {
    namespace QCrypTool {

        MainWindow::MainWindow(QWidget *_parent, const Qt::WindowFlags _flags) :
            Core::MainWindow(_parent, _flags),
            m_ui(new Ui::QCrypToolMainWindow) {
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
            connect(m_ui->MenuOptionsActionScaling, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuOptionsActionScaling()));
            connect(m_ui->MenuHelpActionAboutQCrypTool, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuHelpActionAboutQCrypTool()));
        }

        void MainWindow::slotChangedLanguage() {
            setWindowTitle(QString("%1 %2").arg(getProjectName()).arg(getProjectVersion()));
            // TODO/FIXME: add more translations
            m_ui->MenuDigitalSignaturesPKI->setTitle(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKI));
            m_ui->MenuDigitalSignaturesPKIMenuPKI->setTitle(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIMENUPKI));
            m_ui->MenuDigitalSignaturesPKIMenuPKIActionCreateImportKeys->setText(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIMENUPKIACTIONCREATEIMPORTKEYS));
            m_ui->MenuDigitalSignaturesPKIMenuPKIActionDisplayExportKeys->setText(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIMENUPKIACTIONDISPLAYEXPORTKEYS));
            m_ui->MenuDigitalSignaturesPKIActionCreateSignature->setText(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONCREATESIGNATURE));
            m_ui->MenuDigitalSignaturesPKIActionVerifySignature->setText(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONVERIFYSIGNATURE));
            m_ui->MenuDigitalSignaturesPKIActionExtractSignature->setText(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONEXTRACTSIGNATURE));
            m_ui->MenuDigitalSignaturesPKIActionSignatureDemonstration->setText(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONSIGNATUREDEMONSTRATION));
            m_ui->MenuOptions->setTitle(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUOPTIONS));
            m_ui->MenuOptionsActionLanguage->setText(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUOPTIONSACTIONLANGUAGE));
            m_ui->MenuOptionsActionScaling->setText(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUOPTIONSACTIONSCALING));
            m_ui->MenuHelp->setTitle(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUHELP));
            m_ui->MenuHelpActionStartingPage->setText(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONSTARTINGPAGE));
            m_ui->MenuHelpActionIndex->setText(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONINDEX));
            m_ui->MenuHelpActionScenariosTutorials->setText(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONSCENARIOSTUTORIALS));
            m_ui->MenuHelpActionReadme->setText(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONREADME));
            m_ui->MenuHelpActionCTBook->setText(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONCTBOOK));
            m_ui->MenuHelpActionPresentation->setText(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONPRESENTATION));
            m_ui->MenuHelpActionAboutQCrypTool->setText(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONABOUTQCRYPTOOL));
        }

        void MainWindow::slotChangedScaling() {
            if(menuBar()) {
                m_scalingSystem.setFont(menuBar(), ScalingSystem::FONT_TYPE_NORMAL_M);
                QList<QMenu*> menus = menuBar()->findChildren<QMenu*>();
                foreach(QMenu *menu, menus) {
                    m_scalingSystem.setFont(menu, ScalingSystem::FONT_TYPE_NORMAL_M);
                    QList<QAction*> actions = menu->actions();
                    foreach(QAction *action, actions) {
                        m_scalingSystem.setFont(action, ScalingSystem::FONT_TYPE_NORMAL_M);
                    }
                }
            }
        }

        void MainWindow::slotTriggeredMenuDigitalSignaturesPKIActionCertificateStore() {
            Dialogs::DialogCertificateStore dialogCertificateStore;
            dialogCertificateStore.exec();
        }

        void MainWindow::slotTriggeredMenuDigitalSignaturesPKIActionCreateSignature() {
            Core::Utilities::MessageBoxes::execMessageBoxInformation("TODO/FIXME: MainWindow::slotTriggeredMenuDigitalSignaturesPKIActionCreateSignature()");
        }

        void MainWindow::slotTriggeredMenuDigitalSignaturesPKIActionVerifySignature() {
            Core::Utilities::MessageBoxes::execMessageBoxInformation("TODO/FIXME: MainWindow::slotTriggeredMenuDigitalSignaturesPKIActionVerifySignature()");
        }

        void MainWindow::slotTriggeredMenuDigitalSignaturesPKIActionExtractSignature() {
            Core::Utilities::MessageBoxes::execMessageBoxInformation("TODO/FIXME: MainWindow::slotTriggeredMenuDigitalSignaturesPKIActionExtractSignature()");
        }

        void MainWindow::slotTriggeredMenuDigitalSignaturesPKIActionSignatureDemonstration() {
            Core::Utilities::MessageBoxes::execMessageBoxInformation("TODO/FIXME: MainWindow::slotTriggeredMenuDigitalSignaturesPKIActionSignatureDemonstration()");
        }

        void MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionMD4() {
            Core::Utilities::MessageBoxes::execMessageBoxInformation("TODO/FIXME: MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionMD4()");
        }

        void MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionMD5() {
            Core::Utilities::MessageBoxes::execMessageBoxInformation("TODO/FIXME: MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionMD5()");
        }

        void MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionSHA() {
            Core::Utilities::MessageBoxes::execMessageBoxInformation("TODO/FIXME: MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionSHA()");
        }

        void MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionSHA1() {
            Core::Utilities::MessageBoxes::execMessageBoxInformation("TODO/FIXME: MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionSHA1()");
        }

        void MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionSHA256() {
            Core::Utilities::MessageBoxes::execMessageBoxInformation("TODO/FIXME: MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionSHA256()");
        }

        void MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionSHA512() {
            Core::Utilities::MessageBoxes::execMessageBoxInformation("TODO/FIXME: MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionSHA512()");
        }

        void MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionRIPEMD160() {
            Core::Utilities::MessageBoxes::execMessageBoxInformation("TODO/FIXME: MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionRIPEMD160()");
        }

        void MainWindow::slotTriggeredMenuOptionsActionLanguage() {
            Dialogs::DialogLanguage dialogLanguage;
            dialogLanguage.exec();
        }

        void MainWindow::slotTriggeredMenuOptionsActionScaling() {
            Dialogs::DialogScaling dialogScaling;
            dialogScaling.exec();
        }

        void MainWindow::slotTriggeredMenuHelpActionAboutQCrypTool() {
            Dialogs::DialogAboutQCrypTool dialogAboutQCrypTool;
            dialogAboutQCrypTool.exec();
        }

    }
}
