// DialogScaling.cpp

#include <QCrypTool/Dialogs/DialogScaling.h>
#include <ui_DialogScaling.h>

namespace QCT {
    namespace QCrypTool {
        namespace Dialogs {

            DialogScaling::DialogScaling(QWidget *_parent, Qt::WindowFlags _flags) :
                Core::Dialog(_parent, _flags),
                m_ui(new Ui::DialogScaling) {
                m_ui->setupUi(this);
            }

            DialogScaling::~DialogScaling() {
                delete m_ui;
            }

            void DialogScaling::initializeSignalsAndSlots() {
                connect(m_ui->DialogScalingPushButtonCancel, SIGNAL(clicked()), this, SLOT(slotClickedDialogScalingPushButtonCancel()));
                connect(m_ui->DialogScalingPushButtonOK, SIGNAL(clicked()), this, SLOT(slotClickedDialogScalingPushButtonOK()));
            }

            void DialogScaling::initializeScaling() {
                const float scaling = Core::ScalingSystem::instance().getScaling();
                setFixedSize(size() * scaling);
            }

            void DialogScaling::initializeData() {
                setWindowTitle(trStr(I18N_QCRYPTOOL_DIALOGSCALING_TITLE));
                m_ui->DialogScalingLabelDescription->setText(trStr(I18N_QCRYPTOOL_DIALOGSCALING_LABELDESCRIPTION).arg(Core::ScalingSystem::instance().getScalingMinimum()).arg(Core::ScalingSystem::instance().getScalingMaximum()));
                m_ui->DialogScalingDoubleSpinBoxScaling->setMinimum(Core::ScalingSystem::instance().getScalingMinimum());
                m_ui->DialogScalingDoubleSpinBoxScaling->setMaximum(Core::ScalingSystem::instance().getScalingMaximum());
                m_ui->DialogScalingDoubleSpinBoxScaling->setValue((double)(Core::ScalingSystem::instance().getScaling()));
                m_ui->DialogScalingDoubleSpinBoxScaling->setSingleStep(0.1);
                m_ui->DialogScalingPushButtonCancel->setText(trStr(I18N_GENERIC_CANCEL));
                m_ui->DialogScalingPushButtonOK->setText(trStr(I18N_GENERIC_OK));
            }

            void DialogScaling::slotClickedDialogScalingPushButtonCancel() {
                done(QDialog::Rejected);
            }

            void DialogScaling::slotClickedDialogScalingPushButtonOK() {
                Core::ScalingSystem::instance().setScaling((float)(m_ui->DialogScalingDoubleSpinBoxScaling->value()));
                done(QDialog::Accepted);
            }

        }
    }
}
