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
            connect(m_ui->mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)), this, SLOT(slotMdiSubWindowActivated(QMdiSubWindow*)));
        }

        MainWindow::~MainWindow() {
            disconnect(m_ui->mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)), this, SLOT(slotMdiSubWindowActivated(QMdiSubWindow*)));
            delete m_ui;
        }

        void MainWindow::slotInitializeSignalsAndSlots() {
            connect(m_ui->MenuFileActionNew, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuFileActionNew()));
            connect(m_ui->MenuFileActionOpen, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuFileActionOpen()));
            connect(m_ui->MenuEditActionCut, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuEditActionCut()));
            connect(m_ui->MenuEditActionCopy, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuEditActionCopy()));
            connect(m_ui->MenuEditActionPaste, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuEditActionPaste()));
            connect(m_ui->MenuViewMenuFontActionNormalXS, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuViewMenuFontActionNormalXS()));
            connect(m_ui->MenuViewMenuFontActionNormalS, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuViewMenuFontActionNormalS()));
            connect(m_ui->MenuViewMenuFontActionNormalM, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuViewMenuFontActionNormalM()));
            connect(m_ui->MenuViewMenuFontActionNormalL, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuViewMenuFontActionNormalL()));
            connect(m_ui->MenuViewMenuFontActionNormalXL, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuViewMenuFontActionNormalXL()));
            connect(m_ui->MenuViewMenuFontActionMonospaceXS, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuViewMenuFontActionMonospaceXS()));
            connect(m_ui->MenuViewMenuFontActionMonospaceS, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuViewMenuFontActionMonospaceS()));
            connect(m_ui->MenuViewMenuFontActionMonospaceM, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuViewMenuFontActionMonospaceM()));
            connect(m_ui->MenuViewMenuFontActionMonospaceL, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuViewMenuFontActionMonospaceL()));
            connect(m_ui->MenuViewMenuFontActionMonospaceXL, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuViewMenuFontActionMonospaceXL()));
            connect(m_ui->MenuViewActionShowAsText, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuViewShowAsText()));
            connect(m_ui->MenuViewActionShowAsHex, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuViewShowAsHex()));
            connect(m_ui->MenuDigitalSignaturesPKIActionCertificateStore, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuDigitalSignaturesPKIActionCertificateStore()));
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

        void MainWindow::slotInitializeLanguage() {
            setWindowTitle(QString("%1 %2").arg(getProjectName()).arg(getProjectVersion()));
            // TODO/FIXME: add more translations
            m_ui->MenuFile->setTitle(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUFILE));
            m_ui->MenuFileActionNew->setText(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUFILEACTIONNEW));
            m_ui->MenuFileActionOpen->setText(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUFILEACTIONOPEN));
            m_ui->MenuEdit->setTitle(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUEDIT));
            m_ui->MenuEditActionCut->setText(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUEDITACTIONCUT));
            m_ui->MenuEditActionCopy->setText(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUEDITACTIONCOPY));
            m_ui->MenuEditActionPaste->setText(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUEDITACTIONPASTE));
            m_ui->MenuView->setTitle(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUVIEW));
            m_ui->MenuViewMenuFont->setTitle(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUVIEWMENUFONT));
            m_ui->MenuViewMenuFontActionNormalXS->setText(QString("%1 %2").arg(m_scalingSystem.getFontFamily(ScalingSystem::FONT_TYPE_NORMAL_XS)).arg(m_scalingSystem.getFontPixelSize(ScalingSystem::FONT_TYPE_NORMAL_XS)));
            m_ui->MenuViewMenuFontActionNormalS->setText(QString("%1 %2").arg(m_scalingSystem.getFontFamily(ScalingSystem::FONT_TYPE_NORMAL_S)).arg(m_scalingSystem.getFontPixelSize(ScalingSystem::FONT_TYPE_NORMAL_S)));
            m_ui->MenuViewMenuFontActionNormalM->setText(QString("%1 %2").arg(m_scalingSystem.getFontFamily(ScalingSystem::FONT_TYPE_NORMAL_M)).arg(m_scalingSystem.getFontPixelSize(ScalingSystem::FONT_TYPE_NORMAL_M)));
            m_ui->MenuViewMenuFontActionNormalL->setText(QString("%1 %2").arg(m_scalingSystem.getFontFamily(ScalingSystem::FONT_TYPE_NORMAL_L)).arg(m_scalingSystem.getFontPixelSize(ScalingSystem::FONT_TYPE_NORMAL_L)));
            m_ui->MenuViewMenuFontActionNormalXL->setText(QString("%1 %2").arg(m_scalingSystem.getFontFamily(ScalingSystem::FONT_TYPE_NORMAL_XL)).arg(m_scalingSystem.getFontPixelSize(ScalingSystem::FONT_TYPE_NORMAL_XL)));
            m_ui->MenuViewMenuFontActionMonospaceXS->setText(QString("%1 %2").arg(m_scalingSystem.getFontFamily(ScalingSystem::FONT_TYPE_MONOSPACE_XS)).arg(m_scalingSystem.getFontPixelSize(ScalingSystem::FONT_TYPE_MONOSPACE_XS)));
            m_ui->MenuViewMenuFontActionMonospaceS->setText(QString("%1 %2").arg(m_scalingSystem.getFontFamily(ScalingSystem::FONT_TYPE_MONOSPACE_S)).arg(m_scalingSystem.getFontPixelSize(ScalingSystem::FONT_TYPE_MONOSPACE_S)));
            m_ui->MenuViewMenuFontActionMonospaceM->setText(QString("%1 %2").arg(m_scalingSystem.getFontFamily(ScalingSystem::FONT_TYPE_MONOSPACE_M)).arg(m_scalingSystem.getFontPixelSize(ScalingSystem::FONT_TYPE_MONOSPACE_M)));
            m_ui->MenuViewMenuFontActionMonospaceL->setText(QString("%1 %2").arg(m_scalingSystem.getFontFamily(ScalingSystem::FONT_TYPE_MONOSPACE_L)).arg(m_scalingSystem.getFontPixelSize(ScalingSystem::FONT_TYPE_MONOSPACE_L)));
            m_ui->MenuViewMenuFontActionMonospaceXL->setText(QString("%1 %2").arg(m_scalingSystem.getFontFamily(ScalingSystem::FONT_TYPE_MONOSPACE_XL)).arg(m_scalingSystem.getFontPixelSize(ScalingSystem::FONT_TYPE_MONOSPACE_XL)));
            m_ui->MenuViewActionShowAsText->setText(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUVIEWSHOWASTEXT));
            m_ui->MenuViewActionShowAsHex->setText(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUVIEWSHOWASHEX));
            m_ui->MenuDigitalSignaturesPKI->setTitle(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKI));
            m_ui->MenuDigitalSignaturesPKIActionCertificateStore->setText(trStr(I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONCERTIFICATESTORE));
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

        void MainWindow::slotInitializeScaling() {
            slotInitializeLanguage();
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

        void MainWindow::slotMdiSubWindowActivated(QMdiSubWindow *_mdiSubWindow) {
            Q_UNUSED(_mdiSubWindow);
            slotActivateAndDeactivateMenusAndActions();
        }

        void MainWindow::slotActivateAndDeactivateMenusAndActions() {
            Core::EditorWidget *currentEditorWidget = getCurrentEditorWidget();
            if(currentEditorWidget) {
                m_ui->MenuViewMenuFontActionNormalXS->setEnabled(currentEditorWidget->getMode() == Core::EditorWidget::MODE_TEXT && currentEditorWidget->getFontType() != ScalingSystem::FONT_TYPE_NORMAL_XS);
                m_ui->MenuViewMenuFontActionNormalS->setEnabled(currentEditorWidget->getMode() == Core::EditorWidget::MODE_TEXT && currentEditorWidget->getFontType() != ScalingSystem::FONT_TYPE_NORMAL_S);
                m_ui->MenuViewMenuFontActionNormalM->setEnabled(currentEditorWidget->getMode() == Core::EditorWidget::MODE_TEXT && currentEditorWidget->getFontType() != ScalingSystem::FONT_TYPE_NORMAL_M);
                m_ui->MenuViewMenuFontActionNormalL->setEnabled(currentEditorWidget->getMode() == Core::EditorWidget::MODE_TEXT && currentEditorWidget->getFontType() != ScalingSystem::FONT_TYPE_NORMAL_L);
                m_ui->MenuViewMenuFontActionNormalXL->setEnabled(currentEditorWidget->getMode() == Core::EditorWidget::MODE_TEXT && currentEditorWidget->getFontType() != ScalingSystem::FONT_TYPE_NORMAL_XL);
                m_ui->MenuViewMenuFontActionMonospaceXS->setEnabled(currentEditorWidget->getFontType() != ScalingSystem::FONT_TYPE_MONOSPACE_XS);
                m_ui->MenuViewMenuFontActionMonospaceS->setEnabled(currentEditorWidget->getFontType() != ScalingSystem::FONT_TYPE_MONOSPACE_S);
                m_ui->MenuViewMenuFontActionMonospaceM->setEnabled(currentEditorWidget->getFontType() != ScalingSystem::FONT_TYPE_MONOSPACE_M);
                m_ui->MenuViewMenuFontActionMonospaceL->setEnabled(currentEditorWidget->getFontType() != ScalingSystem::FONT_TYPE_MONOSPACE_L);
                m_ui->MenuViewMenuFontActionMonospaceXL->setEnabled(currentEditorWidget->getFontType() != ScalingSystem::FONT_TYPE_MONOSPACE_XL);
                m_ui->MenuViewActionShowAsText->setEnabled(currentEditorWidget->getMode() == Core::EditorWidget::MODE_HEX);
                m_ui->MenuViewActionShowAsHex->setEnabled(currentEditorWidget->getMode() == Core::EditorWidget::MODE_TEXT);
            }
            else {
                m_ui->MenuViewMenuFontActionNormalXS->setEnabled(false);
                m_ui->MenuViewMenuFontActionNormalS->setEnabled(false);
                m_ui->MenuViewMenuFontActionNormalM->setEnabled(false);
                m_ui->MenuViewMenuFontActionNormalL->setEnabled(false);
                m_ui->MenuViewMenuFontActionNormalXL->setEnabled(false);
                m_ui->MenuViewMenuFontActionMonospaceXS->setEnabled(false);
                m_ui->MenuViewMenuFontActionMonospaceS->setEnabled(false);
                m_ui->MenuViewMenuFontActionMonospaceM->setEnabled(false);
                m_ui->MenuViewMenuFontActionMonospaceL->setEnabled(false);
                m_ui->MenuViewMenuFontActionMonospaceXL->setEnabled(false);
                m_ui->MenuViewActionShowAsText->setEnabled(false);
                m_ui->MenuViewActionShowAsHex->setEnabled(false);
            }
        }

        void MainWindow::slotTriggeredMenuFileActionNew() {
            Core::EditorWidget *editorWidget = new Core::EditorWidget();
            connect(editorWidget, SIGNAL(signalChangedMode()), this, SLOT(slotActivateAndDeactivateMenusAndActions()));
            connect(editorWidget, SIGNAL(signalChangedFontType()), this, SLOT(slotActivateAndDeactivateMenusAndActions()));
            m_ui->mdiArea->addSubWindow(editorWidget);
            editorWidget->show();
            slotActivateAndDeactivateMenusAndActions();
        }

        void MainWindow::slotTriggeredMenuFileActionOpen() {
            const QString fileName = Core::Utilities::Interaction::getSelectedFileName();
            if(fileName.isEmpty()) return;
            Core::EditorWidget *editorWidget = new Core::EditorWidget(fileName);
            connect(editorWidget, SIGNAL(signalChangedMode()), this, SLOT(slotActivateAndDeactivateMenusAndActions()));
            connect(editorWidget, SIGNAL(signalChangedFontType()), this, SLOT(slotActivateAndDeactivateMenusAndActions()));
            m_ui->mdiArea->addSubWindow(editorWidget);
            editorWidget->show();
            slotActivateAndDeactivateMenusAndActions();
        }

        void MainWindow::slotTriggeredMenuEditActionCut() {
            Core::EditorWidget *currentEditorWidget = getCurrentEditorWidget();
            if(currentEditorWidget) {
                currentEditorWidget->cut();
            }
        }

        void MainWindow::slotTriggeredMenuEditActionCopy() {
            Core::EditorWidget *currentEditorWidget = getCurrentEditorWidget();
            if(currentEditorWidget) {
                currentEditorWidget->copy();
            }
        }

        void MainWindow::slotTriggeredMenuEditActionPaste() {
            Core::EditorWidget *currentEditorWidget = getCurrentEditorWidget();
            if(currentEditorWidget) {
                currentEditorWidget->paste();
            }
        }

        void MainWindow::slotTriggeredMenuViewMenuFontActionNormalXS() {
            Core::EditorWidget *currentEditorWidget = getCurrentEditorWidget();
            if(currentEditorWidget) {
                currentEditorWidget->setFontType(ScalingSystem::FONT_TYPE_NORMAL_XS);
            }
        }

        void MainWindow::slotTriggeredMenuViewMenuFontActionNormalS() {
            Core::EditorWidget *currentEditorWidget = getCurrentEditorWidget();
            if(currentEditorWidget) {
                currentEditorWidget->setFontType(ScalingSystem::FONT_TYPE_NORMAL_S);
            }
        }

        void MainWindow::slotTriggeredMenuViewMenuFontActionNormalM() {
            Core::EditorWidget *currentEditorWidget = getCurrentEditorWidget();
            if(currentEditorWidget) {
                currentEditorWidget->setFontType(ScalingSystem::FONT_TYPE_NORMAL_M);
            }
        }

        void MainWindow::slotTriggeredMenuViewMenuFontActionNormalL() {
            Core::EditorWidget *currentEditorWidget = getCurrentEditorWidget();
            if(currentEditorWidget) {
                currentEditorWidget->setFontType(ScalingSystem::FONT_TYPE_NORMAL_L);
            }
        }

        void MainWindow::slotTriggeredMenuViewMenuFontActionNormalXL() {
            Core::EditorWidget *currentEditorWidget = getCurrentEditorWidget();
            if(currentEditorWidget) {
                currentEditorWidget->setFontType(ScalingSystem::FONT_TYPE_NORMAL_XL);
            }
        }

        void MainWindow::slotTriggeredMenuViewMenuFontActionMonospaceXS() {
            Core::EditorWidget *currentEditorWidget = getCurrentEditorWidget();
            if(currentEditorWidget) {
                currentEditorWidget->setFontType(ScalingSystem::FONT_TYPE_MONOSPACE_XS);
            }
        }

        void MainWindow::slotTriggeredMenuViewMenuFontActionMonospaceS() {
            Core::EditorWidget *currentEditorWidget = getCurrentEditorWidget();
            if(currentEditorWidget) {
                currentEditorWidget->setFontType(ScalingSystem::FONT_TYPE_MONOSPACE_S);
            }
        }

        void MainWindow::slotTriggeredMenuViewMenuFontActionMonospaceM() {
            Core::EditorWidget *currentEditorWidget = getCurrentEditorWidget();
            if(currentEditorWidget) {
                currentEditorWidget->setFontType(ScalingSystem::FONT_TYPE_MONOSPACE_M);
            }
        }

        void MainWindow::slotTriggeredMenuViewMenuFontActionMonospaceL() {
            Core::EditorWidget *currentEditorWidget = getCurrentEditorWidget();
            if(currentEditorWidget) {
                currentEditorWidget->setFontType(ScalingSystem::FONT_TYPE_MONOSPACE_L);
            }
        }

        void MainWindow::slotTriggeredMenuViewMenuFontActionMonospaceXL() {
            Core::EditorWidget *currentEditorWidget = getCurrentEditorWidget();
            if(currentEditorWidget) {
                currentEditorWidget->setFontType(ScalingSystem::FONT_TYPE_MONOSPACE_XL);
            }
        }

        void MainWindow::slotTriggeredMenuViewShowAsText() {
            Core::EditorWidget *currentEditorWidget = getCurrentEditorWidget();
            if(currentEditorWidget) {
                currentEditorWidget->setMode(Core::EditorWidget::MODE_TEXT);
            }
        }

        void MainWindow::slotTriggeredMenuViewShowAsHex() {
            Core::EditorWidget *currentEditorWidget = getCurrentEditorWidget();
            if(currentEditorWidget) {
                currentEditorWidget->setMode(Core::EditorWidget::MODE_HEX);
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

        Core::EditorWidget *MainWindow::getCurrentEditorWidget() {
            Core::EditorWidget *currentEditorWidget = 0;
            QMdiSubWindow *currentMdiSubWindow = m_ui->mdiArea->currentSubWindow();
            if(currentMdiSubWindow) {
                currentEditorWidget = static_cast<Core::EditorWidget*>(currentMdiSubWindow->widget());
            }
            return currentEditorWidget;
        }

    }
}
