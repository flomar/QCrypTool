// QCTTranslationSystem.cpp

#include <QCTTranslationSystem.h>

// ATTENTION: If we're using only the "<file.h>" pattern above, for some reason
// the "lupdate" command complains about unknown classes/namespaces.
#include "QCTTranslationSystem.h"

namespace QCT {

    TranslationSystem::TranslationSystem(QObject *_parent) :
        QObject(_parent) {

    }

    TranslationSystem::~TranslationSystem() {

    }

    TranslationSystem &TranslationSystem::instance() {
        static TranslationSystem translationSystem;
        return translationSystem;
    }

    void TranslationSystem::initializeLanguages() {
        // ATTENTION: Here we make sure all languages are mapped to their
        // proper translations. This is required for the langauge selection
        // dialog to work as intended. Whenever a non-standard language
        // (i.e. other languages than English and German) are added, this
        // function as well as the "setLanguage" function below needs
        // to be adapted accordingly
        m_mapLanguageTranslations.clear();
        m_mapLanguageTranslations.insert("English", trStr(I18N_GENERIC_ENGLISH));
        m_mapLanguageTranslations.insert("German", trStr(I18N_GENERIC_GERMAN));
    }

    void TranslationSystem::setLanguage(const QString &_language) {
        initializeLanguages();
        const QString locale = QLocale::system().name();
        QString language = _language;
        if(language.isEmpty()) {
            if(locale.startsWith("en")) {
                language = "English";
            }
            else if(locale.startsWith("de")) {
                language = "German";
            }
        }
        if(m_mapLanguageTranslations.contains(language)) {
            if(m_translator.load(QString(":/QCT/Translations/QCT%1.qm").arg(language))) {
                m_language = language;
                initializeLanguages();
                emit signalChangedLanguage();
            }
        }
    }

    QVector<QString> TranslationSystem::getLanguages() const {
        return m_mapLanguageTranslations.keys().toVector();
    }

    QString TranslationSystem::getLanguage() const {
        return m_language;
    }

    QString TranslationSystem::getLanguageTranslated(const QString &_languageUntranslated) const {
        return m_mapLanguageTranslations.value(_languageUntranslated, "[LANGUAGE]");
    }

    QString TranslationSystem::getLanguageUntranslated(const QString &_languageTranslated) const {
        QString languageUntranslated = "[LANGUAGE]";
        foreach(const QString language, m_mapLanguageTranslations.keys()) {
            const QString languageTranslated = m_mapLanguageTranslations.value(language);
            if(languageTranslated == _languageTranslated) {
                languageUntranslated = language;
            }
        }
        return languageUntranslated;
    }

    QString TranslationSystem::getString(const QString &_identifier) const {
        return m_translator.translate(_identifier.toLatin1(), _identifier.toLatin1());
    }

    // generic translations
    const char *I18N_GENERIC_YES = QT_TRANSLATE_NOOP("I18N_GENERIC_YES", "I18N_GENERIC_YES");
    const char *I18N_GENERIC_NO = QT_TRANSLATE_NOOP("I18N_GENERIC_NO", "I18N_GENERIC_NO");
    const char *I18N_GENERIC_OK = QT_TRANSLATE_NOOP("I18N_GENERIC_OK", "I18N_GENERIC_OK");
    const char *I18N_GENERIC_CANCEL = QT_TRANSLATE_NOOP("I18N_GENERIC_CANCEL", "I18N_GENERIC_CANCEL");
    const char *I18N_GENERIC_CLOSE = QT_TRANSLATE_NOOP("I18N_GENERIC_CLOSE", "I18N_GENERIC_CLOSE");
    const char *I18N_GENERIC_ENGLISH = QT_TRANSLATE_NOOP("I18N_GENERIC_ENGLISH", "I18N_GENERIC_ENGLISH");
    const char *I18N_GENERIC_GERMAN = QT_TRANSLATE_NOOP("I18N_GENERIC_GERMAN", "I18N_GENERIC_GERMAN");

    // CrypTool main window translations
    const char *I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKI = QT_TRANSLATE_NOOP("I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKI", "I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKI");
    const char *I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONCERTIFICATESTORE = QT_TRANSLATE_NOOP("I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONCERTIFICATESTORE", "I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONCERTIFICATESTORE");
    const char *I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONCREATESIGNATURE = QT_TRANSLATE_NOOP("I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONCREATESIGNATURE", "I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONCREATESIGNATURE");
    const char *I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONVERIFYSIGNATURE = QT_TRANSLATE_NOOP("I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONVERIFYSIGNATURE", "I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONVERIFYSIGNATURE");
    const char *I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONEXTRACTSIGNATURE = QT_TRANSLATE_NOOP("I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONEXTRACTSIGNATURE", "I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONEXTRACTSIGNATURE");
    const char *I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONSIGNATUREDEMONSTRATION = QT_TRANSLATE_NOOP("I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONSIGNATUREDEMONSTRATION", "I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONSIGNATUREDEMONSTRATION");
    const char *I18N_QCRYPTOOL_MAINWINDOW_MENUOPTIONS = QT_TRANSLATE_NOOP("I18N_QCRYPTOOL_MAINWINDOW_MENUOPTIONS", "I18N_QCRYPTOOL_MAINWINDOW_MENUOPTIONS");
    const char *I18N_QCRYPTOOL_MAINWINDOW_MENUOPTIONSACTIONLANGUAGE = QT_TRANSLATE_NOOP("I18N_QCRYPTOOL_MAINWINDOW_MENUOPTIONSACTIONLANGUAGE", "I18N_QCRYPTOOL_MAINWINDOW_MENUOPTIONSACTIONLANGUAGE");
    const char *I18N_QCRYPTOOL_MAINWINDOW_MENUOPTIONSACTIONSCALING = QT_TRANSLATE_NOOP("I18N_QCRYPTOOL_MAINWINDOW_MENUOPTIONSACTIONSCALING", "I18N_QCRYPTOOL_MAINWINDOW_MENUOPTIONSACTIONSCALING");
    const char *I18N_QCRYPTOOL_MAINWINDOW_MENUHELP = QT_TRANSLATE_NOOP("I18N_QCRYPTOOL_MAINWINDOW_MENUHELP", "I18N_QCRYPTOOL_MAINWINDOW_MENUHELP");
    const char *I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONSTARTINGPAGE = QT_TRANSLATE_NOOP("I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONSTARTINGPAGE", "I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONSTARTINGPAGE");
    const char *I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONINDEX = QT_TRANSLATE_NOOP("I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONINDEX", "I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONINDEX");
    const char *I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONSCENARIOSTUTORIALS = QT_TRANSLATE_NOOP("I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONSCENARIOSTUTORIALS", "I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONSCENARIOSTUTORIALS");
    const char *I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONREADME = QT_TRANSLATE_NOOP("I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONREADME", "I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONREADME");
    const char *I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONCTBOOK = QT_TRANSLATE_NOOP("I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONCTBOOK", "I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONCTBOOK");
    const char *I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONPRESENTATION = QT_TRANSLATE_NOOP("I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONPRESENTATION", "I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONPRESENTATION");
    const char *I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONABOUTQCRYPTOOL = QT_TRANSLATE_NOOP("I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONABOUTQCRYPTOOL", "I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONABOUTQCRYPTOOL");

    // CrypTool dialog translations
    const char *I18N_QCRYPTOOL_DIALOGCERTIFICATESTORE_TITLE = QT_TRANSLATE_NOOP("I18N_QCRYPTOOL_DIALOGCERTIFICATESTORE_TITLE", "I18N_QCRYPTOOL_DIALOGCERTIFICATESTORE_TITLE");
    const char *I18N_QCRYPTOOL_DIALOGLANGUAGE_TITLE = QT_TRANSLATE_NOOP("I18N_QCRYPTOOL_DIALOGLANGUAGE_TITLE", "I18N_QCRYPTOOL_DIALOGLANGUAGE_TITLE");
    const char *I18N_QCRYPTOOL_DIALOGLANGUAGE_LABELDESCRIPTION = QT_TRANSLATE_NOOP("I18N_QCRYPTOOL_DIALOGLANGUAGE_LABELDESCRIPTION", "I18N_QCRYPTOOL_DIALOGLANGUAGE_LABELDESCRIPTION");
    const char *I18N_QCRYPTOOL_DIALOGSCALING_TITLE = QT_TRANSLATE_NOOP("I18N_QCRYPTOOL_DIALOGSCALING_TITLE", "I18N_QCRYPTOOL_DIALOGSCALING_TITLE");
    const char *I18N_QCRYPTOOL_DIALOGSCALING_LABELDESCRIPTION = QT_TRANSLATE_NOOP("I18N_QCRYPTOOL_DIALOGSCALING_LABELDESCRIPTION", "I18N_QCRYPTOOL_DIALOGSCALING_LABELDESCRIPTION");
    const char *I18N_QCRYPTOOL_DIALOGABOUTQCRYPTOOL_TITLE = QT_TRANSLATE_NOOP("I18N_QCRYPTOOL_DIALOGABOUTQCRYPTOOL_TITLE", "I18N_QCRYPTOOL_DIALOGABOUTQCRYPTOOL_TITLE");
    const char *I18N_QCRYPTOOL_DIALOGABOUTQCRYPTOOL_PROJECTINFORMATION = QT_TRANSLATE_NOOP("I18N_QCRYPTOOL_DIALOGABOUTQCRYPTOOL_PROJECTINFORMATION", "I18N_QCRYPTOOL_DIALOGABOUTQCRYPTOOL_PROJECTINFORMATION");
    const char *I18N_QCRYPTOOL_DIALOGABOUTQCRYPTOOL_PROJECTLICENSINGINFORMATION = QT_TRANSLATE_NOOP("I18N_QCRYPTOOL_DIALOGABOUTQCRYPTOOL_PROJECTLICENSINGINFORMATION", "I18N_QCRYPTOOL_DIALOGABOUTQCRYPTOOL_PROJECTLICENSINGINFORMATION");

}
