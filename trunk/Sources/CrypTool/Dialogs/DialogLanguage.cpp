// DialogLanguage.cpp

#include <CrypTool/Dialogs/DialogLanguage.h>
#include <ui_DialogLanguage.h>

namespace QCrypTool {
    namespace CrypTool {
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
                connect(m_ui->DialogLanguagePushButtonCancel, SIGNAL(clicked(bool)), this, SLOT(slotClickedDialogLanguagePushButtonCancel(bool)));
                connect(m_ui->DialogLanguagePushButtonOK, SIGNAL(clicked(bool)), this, SLOT(slotClickedDialogLanguagePushButtonOK(bool)));
            }

            void DialogLanguage::initializeData() {
                setWindowTitle(m_translator.getString(I18N_STRING_DIALOG_LANGUAGE_TITLE));
                m_ui->DialogLanguageLabelDescription->setText(m_translator.getString(I18N_STRING_DIALOG_LANGUAGE_LABEL_DESCRIPTION));
                m_ui->DialogLanguageComboxBoxLanguage->clear();
                const QVector<QString> languages = m_translator.getLanguages();
                foreach(const QString language, languages) {
                    m_ui->DialogLanguageComboxBoxLanguage->addItem(language);
                }
                m_ui->DialogLanguageComboxBoxLanguage->setCurrentText(m_translator.getLanguage());
                m_ui->DialogLanguagePushButtonCancel->setText(m_translator.getString(I18N_STRING_CANCEL));
                m_ui->DialogLanguagePushButtonOK->setText(m_translator.getString(I18N_STRING_OK));
            }

            void DialogLanguage::slotClickedDialogLanguagePushButtonCancel(const bool _checked) {
                Q_UNUSED(_checked);
                done(QDialog::Rejected);
            }

            void DialogLanguage::slotClickedDialogLanguagePushButtonOK(const bool _checked) {
                Q_UNUSED(_checked);
                m_translator.setLanguage("CrypTool", m_ui->DialogLanguageComboxBoxLanguage->currentText());
                done(QDialog::Accepted);
            }

        }
    }
}
