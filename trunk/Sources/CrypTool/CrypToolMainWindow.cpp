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
            connect(m_ui->MenuOptionsActionLanguage, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuOptionsActionLanguage()));
            connect(m_ui->MenuHelpActionAboutCrypTool, SIGNAL(triggered()), this, SLOT(slotTriggeredMenuHelpActionAboutCrypTool()));
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
