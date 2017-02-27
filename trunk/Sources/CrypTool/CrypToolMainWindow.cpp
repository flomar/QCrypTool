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
            connect(m_ui->MenuIndividualProceduresMenuHashActionMD4, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuIndividualProceduresMenuHashActionMD4()));
            connect(m_ui->MenuIndividualProceduresMenuHashActionMD5, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuIndividualProceduresMenuHashActionMD5()));
            connect(m_ui->MenuIndividualProceduresMenuHashActionSHA, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuIndividualProceduresMenuHashActionSHA()));
            connect(m_ui->MenuIndividualProceduresMenuHashActionSHA1, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuIndividualProceduresMenuHashActionSHA1()));
            connect(m_ui->MenuIndividualProceduresMenuHashActionSHA256, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuIndividualProceduresMenuHashActionSHA256()));
            connect(m_ui->MenuIndividualProceduresMenuHashActionSHA512, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuIndividualProceduresMenuHashActionSHA512()));
            connect(m_ui->MenuIndividualProceduresMenuHashActionRIPEMD160, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuIndividualProceduresMenuHashActionRIPEMD160()));
            connect(m_ui->MenuOptionsActionLanguage, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuOptionsActionLanguage()));
            connect(m_ui->MenuHelpActionAboutCrypTool, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuHelpActionAboutCrypTool()));
        }

        void MainWindow::slotChangedLanguage() {
            setWindowTitle(QString("%1 %2").arg(getApplicationName()).arg(getApplicationVersion()));
            // TODO/FIXME: add more translations
            m_ui->MenuHelp->setTitle(trStr(I18N_CRYPTOOL_MAINWINDOW_MENUHELP));
            m_ui->MenuHelpActionStartingPage->setText(trStr(I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONSTARTINGPAGE));
            m_ui->MenuHelpActionIndex->setText(trStr(I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONINDEX));
            m_ui->MenuHelpActionScenariosTutorials->setText(trStr(I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONSCENARIOSTUTORIALS));
            m_ui->MenuHelpActionReadme->setText(trStr(I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONREADME));
            m_ui->MenuHelpActionCTBook->setText(trStr(I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONCTBOOK));
            m_ui->MenuHelpActionPresentation->setText(trStr(I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONPRESENTATION));
            m_ui->MenuHelpActionAboutCrypTool->setText(trStr(I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONABOUTCRYPTOOL));
        }

        void MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionMD4() {
            qDebug() << QString("TODO/FIXME: MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionMD4");
        }

        void MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionMD5() {
            qDebug() << QString("TODO/FIXME: MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionMD5");
        }

        void MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionSHA() {
            qDebug() << QString("TODO/FIXME: MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionSHA");
        }

        void MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionSHA1() {
            qDebug() << QString("TODO/FIXME: MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionSHA1");
        }

        void MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionSHA256() {
            qDebug() << QString("TODO/FIXME: MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionSHA256");
        }

        void MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionSHA512() {
            qDebug() << QString("TODO/FIXME: MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionSHA512");
        }

        void MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionRIPEMD160() {
            qDebug() << QString("TODO/FIXME: MainWindow::slotTriggeredMenuIndividualProceduresMenuHashActionRIPEMD160");
        }

        void MainWindow::slotTriggeredMenuOptionsActionLanguage() {
            Dialogs::DialogLanguage dialogLanguage;
            dialogLanguage.exec();
        }

        void MainWindow::slotTriggeredMenuHelpActionAboutCrypTool() {
            Dialogs::DialogAbout dialogAbout;
            dialogAbout.exec();
        }

    }
}
