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
                m_scalingSystem.setFixedHeight(m_ui->DialogCertificateStorePushButtonClose);
            }

            void DialogCertificateStore::initializeData() {
                setWindowTitle(trStr(I18N_QCRYPTOOL_DIALOGCERTIFICATESTORE_TITLE));
                m_ui->DialogCertificateStorePushButtonClose->setText(trStr(I18N_GENERIC_CLOSE));
            }

            void DialogCertificateStore::slotClickedDialogCertificateStorePushButtonClose() {
                done(QDialog::Accepted);
            }

        }
    }
}
