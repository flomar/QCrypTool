// DialogLanguage.cpp

#include <QCrypTool/Dialogs/DialogLanguage.h>
#include <ui_DialogLanguage.h>

namespace QCT {
    namespace QCrypTool {
        namespace Dialogs {

            DialogLanguage::DialogLanguage(QWidget *_parent, Qt::WindowFlags _flags) :
                Core::Dialog(_parent, _flags),
                m_ui(new Ui::DialogLanguage) {
                m_ui->setupUi(this);
            }

            DialogLanguage::~DialogLanguage() {
                delete m_ui;
            }

            void DialogLanguage::initializeSignalsAndSlots() {
                connect(m_ui->DialogLanguagePushButtonCancel, SIGNAL(clicked()), this, SLOT(slotClickedDialogLanguagePushButtonCancel()));
                connect(m_ui->DialogLanguagePushButtonOK, SIGNAL(clicked()), this, SLOT(slotClickedDialogLanguagePushButtonOK()));
            }

            void DialogLanguage::initializeVisuals() {

            }

            void DialogLanguage::initializeData() {
                setWindowTitle(trStr(I18N_QCRYPTOOL_DIALOGLANGUAGE_TITLE));
                m_ui->DialogLanguageLabelDescription->setText(trStr(I18N_QCRYPTOOL_DIALOGLANGUAGE_LABELDESCRIPTION));
                m_ui->DialogLanguageComboxBoxLanguage->clear();
                const QVector<QString> languages = m_translationSystem.getLanguages();
                foreach(const QString language, languages) {
                    const QString languageTranslated = m_translationSystem.getLanguageTranslated(language);
                    m_ui->DialogLanguageComboxBoxLanguage->addItem(languageTranslated);
                }
                m_ui->DialogLanguageComboxBoxLanguage->setCurrentText(m_translationSystem.getLanguageTranslated(m_translationSystem.getLanguage()));
                m_ui->DialogLanguagePushButtonCancel->setText(trStr(I18N_GENERIC_CANCEL));
                m_ui->DialogLanguagePushButtonOK->setText(trStr(I18N_GENERIC_OK));
            }

            void DialogLanguage::slotClickedDialogLanguagePushButtonCancel() {
                done(QDialog::Rejected);
            }

            void DialogLanguage::slotClickedDialogLanguagePushButtonOK() {
                m_translationSystem.setLanguage(m_translationSystem.getLanguageUntranslated(m_ui->DialogLanguageComboxBoxLanguage->currentText()));
                done(QDialog::Accepted);
            }

        }
    }
}
