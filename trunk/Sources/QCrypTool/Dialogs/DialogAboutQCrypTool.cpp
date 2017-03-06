// DialogAboutQCrypTool.cpp

#include <QCrypTool/Dialogs/DialogAboutQCrypTool.h>
#include <ui_DialogAboutQCrypTool.h>

namespace QCT {
    namespace QCrypTool {
        namespace Dialogs {

            DialogAboutQCrypTool::DialogAboutQCrypTool(QWidget *_parent, Qt::WindowFlags _flags) :
                Core::Dialog(_parent, _flags),
                m_ui(new Ui::DialogAboutQCrypTool) {
                m_ui->setupUi(this);
            }

            DialogAboutQCrypTool::~DialogAboutQCrypTool() {
                delete m_ui;
            }

            void DialogAboutQCrypTool::slotInitializeSignalsAndSlots() {
                connect(m_ui->DialogAboutQCrypToolPushButtonClose, SIGNAL(clicked()), this, SLOT(slotClickedDialogAboutQCrypToolPushButtonClose()));
            }

            void DialogAboutQCrypTool::slotInitializeLanguage() {
                setWindowTitle(trStr(I18N_QCRYPTOOL_DIALOGABOUTQCRYPTOOL_TITLE));
                m_ui->DialogAboutQCrypToolLabelProjectNameAndVersion->setText(QString("%1 %2").arg(getProjectName()).arg(getProjectVersion()));
                m_ui->DialogAboutQCrypToolLabelProjectInformation->setText(trStr(I18N_QCRYPTOOL_DIALOGABOUTQCRYPTOOL_PROJECTINFORMATION));
                m_ui->DialogAboutQCrypToolLabelProjectLicensingInformation->setText(trStr(I18N_QCRYPTOOL_DIALOGABOUTQCRYPTOOL_PROJECTLICENSINGINFORMATION));
                m_ui->DialogAboutQCrypToolLabelProjectCopyrightInformation->setText(QString("%1").arg(getProjectCopyright()));
                m_ui->DialogAboutQCrypToolPushButtonClose->setText(trStr(I18N_GENERIC_CLOSE));
            }

            void DialogAboutQCrypTool::slotInitializeScaling() {
                m_scalingSystem.setFixedSize(this);
                m_scalingSystem.setFixedSize(m_ui->DialogAboutQCrypToolLabelProjectLogo);
                m_ui->DialogAboutQCrypToolLabelProjectLogo->setPixmap(Core::Utilities::Graphics::getPixmapFromSvg(":/QCT/Images/QCTLogo.svg", m_ui->DialogAboutQCrypToolLabelProjectLogo->size()));
                m_scalingSystem.setFont(m_ui->DialogAboutQCrypToolLabelProjectNameAndVersion, ScalingSystem::FONT_TYPE_NORMAL_XL);
                m_scalingSystem.setBold(m_ui->DialogAboutQCrypToolLabelProjectNameAndVersion, true);
                m_scalingSystem.setFont(m_ui->DialogAboutQCrypToolLabelProjectInformation, ScalingSystem::FONT_TYPE_NORMAL_M);
                m_scalingSystem.setFont(m_ui->DialogAboutQCrypToolLabelProjectRepositoryInformation, ScalingSystem::FONT_TYPE_NORMAL_M);
                m_scalingSystem.setBold(m_ui->DialogAboutQCrypToolLabelProjectRepositoryInformation, true);
                m_scalingSystem.setFont(m_ui->DialogAboutQCrypToolLabelProjectLicensingInformation, ScalingSystem::FONT_TYPE_NORMAL_M);
                m_scalingSystem.setFont(m_ui->DialogAboutQCrypToolLabelProjectCopyrightInformation, ScalingSystem::FONT_TYPE_NORMAL_M);
                m_scalingSystem.setFont(m_ui->DialogAboutQCrypToolPushButtonClose, ScalingSystem::FONT_TYPE_NORMAL_M);
                m_scalingSystem.setFixedHeight(m_ui->DialogAboutQCrypToolPushButtonClose);
            }

            void DialogAboutQCrypTool::slotClickedDialogAboutQCrypToolPushButtonClose() {
                done(QDialog::Accepted);
            }

        }
    }
}
