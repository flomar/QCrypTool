// DialogCertificateStore.cpp

#include <QCrypTool/Dialogs/DialogCertificateStore.h>
#include <ui_DialogCertificateStore.h>

namespace QCT {
    namespace QCrypTool {
        namespace Dialogs {

            DialogCertificateStore::DialogCertificateStore(QWidget *_parent, Qt::WindowFlags _flags) :
                Core::Dialog(_parent, _flags),
                m_ui(new Ui::DialogCertificateStore) {
                m_ui->setupUi(this);
            }

            DialogCertificateStore::~DialogCertificateStore() {
                delete m_ui;
            }

            void DialogCertificateStore::initializeSignalsAndSlots() {
                connect(m_ui->DialogCertificateStorePushButtonClose, SIGNAL(clicked()), this, SLOT(slotClickedDialogCertificateStorePushButtonClose()));
            }

            void DialogCertificateStore::initializeVisuals() {
                m_scalingSystem.setFont(m_ui->DialogCertificateStoreTableViewCertificates, ScalingSystem::FONT_TYPE_NORMAL_M);
                m_scalingSystem.setFont(m_ui->DialogCertificateStoreCheckBoxShowRSACertificates, ScalingSystem::FONT_TYPE_NORMAL_M);
                m_scalingSystem.setFont(m_ui->DialogCertificateStoreCheckBoxShowDSACertificates, ScalingSystem::FONT_TYPE_NORMAL_M);
                m_scalingSystem.setFont(m_ui->DialogCertificateStoreCheckBoxShowECCCertificates, ScalingSystem::FONT_TYPE_NORMAL_M);
                m_scalingSystem.setFont(m_ui->DialogCertificateStorePushButtonCreateCertificate, ScalingSystem::FONT_TYPE_NORMAL_M);
                m_scalingSystem.setFixedHeight(m_ui->DialogCertificateStorePushButtonCreateCertificate);
                m_scalingSystem.setFont(m_ui->DialogCertificateStorePushButtonImportCertificate, ScalingSystem::FONT_TYPE_NORMAL_M);
                m_scalingSystem.setFixedHeight(m_ui->DialogCertificateStorePushButtonImportCertificate);
                m_scalingSystem.setFont(m_ui->DialogCertificateStorePushButtonDisplayCertificate, ScalingSystem::FONT_TYPE_NORMAL_M);
                m_scalingSystem.setFixedHeight(m_ui->DialogCertificateStorePushButtonDisplayCertificate);
                m_scalingSystem.setFont(m_ui->DialogCertificateStorePushButtonExportCertificate, ScalingSystem::FONT_TYPE_NORMAL_M);
                m_scalingSystem.setFixedHeight(m_ui->DialogCertificateStorePushButtonExportCertificate);
                m_scalingSystem.setFont(m_ui->DialogCertificateStorePushButtonDeleteCertificate, ScalingSystem::FONT_TYPE_NORMAL_M);
                m_scalingSystem.setFixedHeight(m_ui->DialogCertificateStorePushButtonDeleteCertificate);
                m_scalingSystem.setFont(m_ui->DialogCertificateStorePushButtonClose, ScalingSystem::FONT_TYPE_NORMAL_M);
                m_scalingSystem.setFixedHeight(m_ui->DialogCertificateStorePushButtonClose);
            }

            void DialogCertificateStore::initializeData() {
                setWindowTitle(trStr(I18N_QCRYPTOOL_DIALOGCERTIFICATESTORE_TITLE));
                m_ui->DialogCertificateStoreCheckBoxShowRSACertificates->setText(trStr(I18N_QCRYPTOOL_DIALOGCERTIFICATESTORE_CHECKBOXSHOWRSACERTIFICATES));
                m_ui->DialogCertificateStoreCheckBoxShowDSACertificates->setText(trStr(I18N_QCRYPTOOL_DIALOGCERTIFICATESTORE_CHECKBOXSHOWDSACERTIFICATES));
                m_ui->DialogCertificateStoreCheckBoxShowECCCertificates->setText(trStr(I18N_QCRYPTOOL_DIALOGCERTIFICATESTORE_CHECKBOXSHOWECCCERTIFICATES));
                m_ui->DialogCertificateStorePushButtonCreateCertificate->setText(trStr(I18N_QCRYPTOOL_DIALOGCERTIFICATESTORE_PUSHBUTTONCREATECERTIFICATE));
                m_ui->DialogCertificateStorePushButtonImportCertificate->setText(trStr(I18N_QCRYPTOOL_DIALOGCERTIFICATESTORE_PUSHBUTTONIMPORTCERTIFICATE));
                m_ui->DialogCertificateStorePushButtonDisplayCertificate->setText(trStr(I18N_QCRYPTOOL_DIALOGCERTIFICATESTORE_PUSHBUTTONDISPLAYCERTIFICATE));
                m_ui->DialogCertificateStorePushButtonExportCertificate->setText(trStr(I18N_QCRYPTOOL_DIALOGCERTIFICATESTORE_PUSHBUTTONEXPORTCERTIFICATE));
                m_ui->DialogCertificateStorePushButtonDeleteCertificate->setText(trStr(I18N_QCRYPTOOL_DIALOGCERTIFICATESTORE_PUSHBUTTONDELETECERTIFICATE));
                m_ui->DialogCertificateStorePushButtonClose->setText(trStr(I18N_GENERIC_CLOSE));
            }

            void DialogCertificateStore::slotClickedDialogCertificateStorePushButtonClose() {
                done(QDialog::Accepted);
            }

        }
    }
}
