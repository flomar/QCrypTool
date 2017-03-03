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

            void DialogScaling::initializeVisuals() {
                m_scalingSystem.setFont(m_ui->DialogScalingLabelDescription, ScalingSystem::FONT_TYPE_NORMAL_M);
                m_scalingSystem.setFont(m_ui->DialogScalingDoubleSpinBoxScaling, ScalingSystem::FONT_TYPE_NORMAL_M);
                m_scalingSystem.setFont(m_ui->DialogScalingPushButtonCancel, ScalingSystem::FONT_TYPE_NORMAL_M);
                m_scalingSystem.setFont(m_ui->DialogScalingPushButtonOK, ScalingSystem::FONT_TYPE_NORMAL_M);
            }

            void DialogScaling::initializeData() {
                setWindowTitle(trStr(I18N_QCRYPTOOL_DIALOGSCALING_TITLE));
                m_ui->DialogScalingLabelDescription->setText(trStr(I18N_QCRYPTOOL_DIALOGSCALING_LABELDESCRIPTION));
                m_ui->DialogScalingDoubleSpinBoxScaling->setMinimum(m_scalingSystem.getScalingMinimum());
                m_ui->DialogScalingDoubleSpinBoxScaling->setMaximum(m_scalingSystem.getScalingMaximum());
                m_ui->DialogScalingDoubleSpinBoxScaling->setValue((double)(m_scalingSystem.getScaling()));
                m_ui->DialogScalingDoubleSpinBoxScaling->setSingleStep(0.05);
                m_ui->DialogScalingPushButtonCancel->setText(trStr(I18N_GENERIC_CANCEL));
                m_ui->DialogScalingPushButtonOK->setText(trStr(I18N_GENERIC_OK));
            }

            void DialogScaling::slotClickedDialogScalingPushButtonCancel() {
                done(QDialog::Rejected);
            }

            void DialogScaling::slotClickedDialogScalingPushButtonOK() {
                m_scalingSystem.setScaling((float)(m_ui->DialogScalingDoubleSpinBoxScaling->value()));
                done(QDialog::Accepted);
            }

        }
    }
}
