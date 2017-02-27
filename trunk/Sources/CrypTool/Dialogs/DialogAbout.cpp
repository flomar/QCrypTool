// DialogAbout.cpp

#include <CrypTool/Dialogs/DialogAbout.h>
#include <ui_DialogAbout.h>

namespace QCrypTool {
    namespace CrypTool {
        namespace Dialogs {

            DialogAbout::DialogAbout(QWidget *_parent, Qt::WindowFlags _flags) :
                Core::Dialog(_parent, _flags),
                m_ui(new Ui::DialogAbout) {
                m_ui->setupUi(this);
            }

            DialogAbout::~DialogAbout() {
                delete m_ui;
            }

            void DialogAbout::initializeSignalsAndSlots() {
                connect(m_ui->DialogAboutPushButtonClose, SIGNAL(clicked(bool)), this, SLOT(slotClickedDialogAboutPushButtonClose(bool)));
            }

            void DialogAbout::initializeData() {
                setWindowTitle(trStr(I18N_CRYPTOOL_DIALOGABOUT_TITLE));
                m_ui->DialogAboutLabelApplicationLogo->setPixmap(QIcon(":/QCrypTool/Images/QCrypToolLogo.svg").pixmap(m_ui->DialogAboutLabelApplicationLogo->size()));
                m_ui->DialogAboutLabelApplicationNameAndVersion->setText(QString("%1 %2").arg(getApplicationName()).arg(getApplicationVersion()));
                m_ui->DialogAboutLabelApplicationInformation->setText(trStr(I18N_CRYPTOOL_DIALOGABOUT_APPLICATIONINFORMATION));
                m_ui->DialogAboutLabelApplicationLicensingInformation->setText(trStr(I18N_CRYPTOOL_DIALOGABOUT_APPLICATIONLICENSINGINFORMATION));
                m_ui->DialogAboutLabelApplicationCopyrightInformation->setText(QString("%1").arg(getApplicationCopyright()));
                m_ui->DialogAboutPushButtonClose->setText(trStr(I18N_GENERIC_CLOSE));
            }

            void DialogAbout::slotClickedDialogAboutPushButtonClose(const bool _checked) {
                Q_UNUSED(_checked);
                done(QDialog::Accepted);
            }

        }
    }
}
