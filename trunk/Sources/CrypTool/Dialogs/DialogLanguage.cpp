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
                setWindowTitle(trStr(I18N_CRYPTOOL_DIALOG_LANGUAGE_TITLE));
                m_ui->DialogLanguageLabelDescription->setText(trStr(I18N_CRYPTOOL_DIALOG_LANGUAGE_LABEL_DESCRIPTION));
                m_ui->DialogLanguageComboxBoxLanguage->clear();
                const QVector<QString> languages = Translation::instance().getLanguages();
                foreach(const QString language, languages) {
                    const QString languageTranslated = Translation::instance().getLanguageTranslated(language);
                    m_ui->DialogLanguageComboxBoxLanguage->addItem(languageTranslated);
                }
                m_ui->DialogLanguageComboxBoxLanguage->setCurrentText(Translation::instance().getLanguageTranslated(Translation::instance().getLanguage()));
                m_ui->DialogLanguagePushButtonCancel->setText(trStr(I18N_GENERIC_CANCEL));
                m_ui->DialogLanguagePushButtonOK->setText(trStr(I18N_GENERIC_OK));
            }

            void DialogLanguage::slotClickedDialogLanguagePushButtonCancel(const bool _checked) {
                Q_UNUSED(_checked);
                done(QDialog::Rejected);
            }

            void DialogLanguage::slotClickedDialogLanguagePushButtonOK(const bool _checked) {
                Q_UNUSED(_checked);
                Translation::instance().setLanguage(Translation::instance().getLanguageUntranslated(m_ui->DialogLanguageComboxBoxLanguage->currentText()));
                done(QDialog::Accepted);
            }

        }
    }
}
