// DialogAbout.cpp

#include <QCrypTool/Dialogs/DialogAbout.h>
#include <ui_DialogAbout.h>

namespace QCT {
    namespace QCrypTool {
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
                connect(m_ui->DialogAboutPushButtonClose, SIGNAL(clicked()), this, SLOT(slotClickedDialogAboutPushButtonClose()));
            }

            void DialogAbout::initializeScaling() {
                const float scaling = Core::ScalingSystem::instance().getScaling();
                setFixedSize(size() * scaling);
            }

            void DialogAbout::initializeData() {
                setWindowTitle(trStr(I18N_QCRYPTOOL_DIALOGABOUT_TITLE));
                m_ui->DialogAboutLabelProjectLogo->setPixmap(Core::Utilities::Graphics::getPixmapFromSvg(":/QCT/Images/QCTLogo.svg", m_ui->DialogAboutLabelProjectLogo->size()));
                m_ui->DialogAboutLabelProjectNameAndVersion->setText(QString("%1 %2").arg(getProjectName()).arg(getProjectVersion()));
                m_ui->DialogAboutLabelProjectInformation->setText(trStr(I18N_QCRYPTOOL_DIALOGABOUT_PROJECTINFORMATION));
                m_ui->DialogAboutLabelProjectLicensingInformation->setText(trStr(I18N_QCRYPTOOL_DIALOGABOUT_PROJECTLICENSINGINFORMATION));
                m_ui->DialogAboutLabelProjectCopyrightInformation->setText(QString("%1").arg(getProjectCopyright()));
                m_ui->DialogAboutPushButtonClose->setText(trStr(I18N_GENERIC_CLOSE));
            }

            void DialogAbout::slotClickedDialogAboutPushButtonClose() {
                done(QDialog::Accepted);
            }

        }
    }
}
