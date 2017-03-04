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
                m_scalingSystem.setFont(m_ui->DialogScalingSpinBoxScaling, ScalingSystem::FONT_TYPE_NORMAL_M);
                m_scalingSystem.setFont(m_ui->DialogScalingPushButtonCancel, ScalingSystem::FONT_TYPE_NORMAL_M);
                m_scalingSystem.setFont(m_ui->DialogScalingPushButtonOK, ScalingSystem::FONT_TYPE_NORMAL_M);
                m_scalingSystem.setFixedSize(m_ui->DialogScalingPushButtonCancel);
                m_scalingSystem.setFixedSize(m_ui->DialogScalingPushButtonOK);
            }

            void DialogScaling::initializeData() {
                setWindowTitle(trStr(I18N_QCRYPTOOL_DIALOGSCALING_TITLE));
                m_ui->DialogScalingLabelDescription->setText(trStr(I18N_QCRYPTOOL_DIALOGSCALING_LABELDESCRIPTION));
                m_ui->DialogScalingSpinBoxScaling->setMinimum(m_scalingSystem.getScalingPercentageMinimum());
                m_ui->DialogScalingSpinBoxScaling->setMaximum(m_scalingSystem.getScalingPercentageMaximum());
                m_ui->DialogScalingSpinBoxScaling->setValue((m_scalingSystem.getScalingPercentage()));
                m_ui->DialogScalingSpinBoxScaling->setSingleStep(5);
                m_ui->DialogScalingSpinBoxScaling->setSuffix("%");
                m_ui->DialogScalingPushButtonCancel->setText(trStr(I18N_GENERIC_CANCEL));
                m_ui->DialogScalingPushButtonOK->setText(trStr(I18N_GENERIC_OK));
            }

            void DialogScaling::slotClickedDialogScalingPushButtonCancel() {
                done(QDialog::Rejected);
            }

            void DialogScaling::slotClickedDialogScalingPushButtonOK() {
                m_scalingSystem.setScalingPercentage(m_ui->DialogScalingSpinBoxScaling->value());
                done(QDialog::Accepted);
            }

        }
    }
}
