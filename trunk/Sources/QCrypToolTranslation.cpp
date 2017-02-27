// QCrypToolTranslation.cpp

#include <QCrypToolTranslation.h>

// ATTENTION: If we're using only the "<file.h>" pattern above, for some reason
// the "lupdate" command complains about unknown classes/namespaces.
#include "QCrypToolTranslation.h"

namespace QCrypTool {

    Translation::Translation(QObject *_parent) :
        QObject(_parent) {

    }

    Translation::~Translation() {

    }

    Translation &Translation::instance() {
        static Translation translation;
        return translation;
    }

    void Translation::initializeLanguages() {
        // ATTENTION: Here we make sure all languages are mapped to their
        // proper translations. This is required for the langauge selection
        // dialog to work as intended. Whenever a non-standard language
        // (i.e. other languages than English and German) are added, this
        // code section needs to be adapted accordingly.
        m_mapLanguageTranslations.clear();
        m_mapLanguageTranslations.insert("English", trStr(I18N_GENERIC_ENGLISH));
        m_mapLanguageTranslations.insert("German", trStr(I18N_GENERIC_GERMAN));
    }

    void Translation::setLanguage(const QString &_language) {
        initializeLanguages();
        if(m_mapLanguageTranslations.contains(_language)) {
            if(m_translator.load(QString(":/QCrypTool/Translations/QCrypTool%1.qm").arg(_language))) {
                m_language = _language;
                initializeLanguages();
                emit signalChangedLanguage();
            }
        }
    }

    QVector<QString> Translation::getLanguages() const {
        return m_mapLanguageTranslations.keys().toVector();
    }

    QString Translation::getLanguage() const {
        return m_language;
    }

    QString Translation::getLanguageTranslated(const QString &_languageUntranslated) const {
        return m_mapLanguageTranslations.value(_languageUntranslated, "[LANGUAGE]");
    }

    QString Translation::getLanguageUntranslated(const QString &_languageTranslated) const {
        QString languageUntranslated = "[LANGUAGE]";
        foreach(const QString language, m_mapLanguageTranslations.keys()) {
            const QString languageTranslated = m_mapLanguageTranslations.value(language);
            if(languageTranslated == _languageTranslated) {
                languageUntranslated = language;
            }
        }
        return languageUntranslated;
    }

    QString Translation::getString(const QString &_identifier) const {
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
    const char *I18N_CRYPTOOL_MAINWINDOW_MENUHELP = QT_TRANSLATE_NOOP("I18N_CRYPTOOL_MAINWINDOW_MENUHELP", "I18N_CRYPTOOL_MAINWINDOW_MENUHELP");
    const char *I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONSTARTINGPAGE = QT_TRANSLATE_NOOP("I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONSTARTINGPAGE", "I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONSTARTINGPAGE");
    const char *I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONINDEX = QT_TRANSLATE_NOOP("I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONINDEX", "I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONINDEX");
    const char *I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONSCENARIOSTUTORIALS = QT_TRANSLATE_NOOP("I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONSCENARIOSTUTORIALS", "I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONSCENARIOSTUTORIALS");
    const char *I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONREADME = QT_TRANSLATE_NOOP("I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONREADME", "I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONREADME");
    const char *I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONCTBOOK = QT_TRANSLATE_NOOP("I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONCTBOOK", "I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONCTBOOK");
    const char *I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONPRESENTATION = QT_TRANSLATE_NOOP("I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONPRESENTATION", "I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONPRESENTATION");
    const char *I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONABOUTQCRYPTOOL = QT_TRANSLATE_NOOP("I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONABOUTQCRYPTOOL", "I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONABOUTQCRYPTOOL");

    // CrypTool dialog translations
    const char *I18N_CRYPTOOL_DIALOGABOUT_TITLE = QT_TRANSLATE_NOOP("I18N_CRYPTOOL_DIALOGABOUT_TITLE", "I18N_CRYPTOOL_DIALOGABOUT_TITLE");
    const char *I18N_CRYPTOOL_DIALOGABOUT_APPLICATIONINFORMATION = QT_TRANSLATE_NOOP("I18N_CRYPTOOL_DIALOGABOUT_APPLICATIONINFORMATION", "I18N_CRYPTOOL_DIALOGABOUT_APPLICATIONINFORMATION");
    const char *I18N_CRYPTOOL_DIALOGABOUT_APPLICATIONLICENSINGINFORMATION = QT_TRANSLATE_NOOP("I18N_CRYPTOOL_DIALOGABOUT_APPLICATIONLICENSINGINFORMATION", "I18N_CRYPTOOL_DIALOGABOUT_APPLICATIONLICENSINGINFORMATION");
    const char *I18N_CRYPTOOL_DIALOGLANGUAGE_TITLE = QT_TRANSLATE_NOOP("I18N_CRYPTOOL_DIALOGLANGUAGE_TITLE", "I18N_CRYPTOOL_DIALOGLANGUAGE_TITLE");
    const char *I18N_CRYPTOOL_DIALOGLANGUAGE_LABELDESCRIPTION = QT_TRANSLATE_NOOP("I18N_CRYPTOOL_DIALOGLANGUAGE_LABELDESCRIPTION", "I18N_CRYPTOOL_DIALOGLANGUAGE_LABELDESCRIPTION");

}
