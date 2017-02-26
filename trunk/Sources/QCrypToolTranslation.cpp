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
        m_vectorLanguages.clear();
        QRegExp regExpAvailableQmFileName("^.*QCrypTool(.*)\\.qm$");
        QVector<QString> vectorAvailableQmFileNames = getVectorAvailableQmFileNames();
        foreach(const QString availableQmFileName, vectorAvailableQmFileNames) {
            if(regExpAvailableQmFileName.indexIn(availableQmFileName) != -1) {
                m_vectorLanguages.append(regExpAvailableQmFileName.cap(1));
            }
        }
        // ATTENTION: Here we make sure the languages provided to the
        // Translation module have been indeed properly integrated.
        // Whenever a non-standed language (i.e. not English or German)
        // is added, this code section needs to be adapted accordingly.
        // Also, don't forget to update the "updateLanguageTranslations"
        // function below.
        const QVector<QString> vectorLanguages = m_vectorLanguages;
        m_vectorLanguages.clear();
        foreach(const QString language, vectorLanguages) {
            if(language == "English") {
                m_vectorLanguages.append(language);
            }
            else if(language == "German") {
                m_vectorLanguages.append(language);
            }
            else {
                const QString message = QString(trStr(I18N_GENERIC_LANGUAGE_NOT_INTEGRATED)).arg(language);
                QMessageBox messageBox(QMessageBox::Warning, getApplicationName(), message);
                messageBox.exec();
            }
        }
        // check for default languages
        if(!m_vectorLanguages.contains("English") || !m_vectorLanguages.contains("German")) {
            const QString message = QString(trStr(I18N_GENERIC_LANGUAGE_MISSING));
            QMessageBox messageBox(QMessageBox::Warning, getApplicationName(), message);
            messageBox.exec();
        }
        // by default we always go with "English"
        setLanguage("English");
    }

    void Translation::setLanguage(const QString &_language) {
        if(m_vectorLanguages.contains(_language)) {
            const QString pathToQmFile = QString("translations/QCrypTool%1.qm").arg(_language);
            if(m_translator.load(pathToQmFile)) {
                m_language = _language;
                updateLanguageTranslations();
                emit signalChangedLanguage();
            }
        }
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

    QVector<QString> Translation::getVectorAvailableQmFileNames() const {
        QVector<QString> vectorAvailableQmFileNames;
        QDirIterator dirIterator("translations");
        while(dirIterator.hasNext()) {
            dirIterator.next();
            if(!QFileInfo(dirIterator.filePath()).isFile()) continue;
            if(QFileInfo(dirIterator.fileName()).suffix() != "qm") continue;
            if(!dirIterator.fileName().startsWith("QCrypTool")) continue;
            vectorAvailableQmFileNames.append(dirIterator.filePath());
        }
        return vectorAvailableQmFileNames;
    }

    void Translation::updateLanguageTranslations() {
        m_mapLanguageTranslations.clear();
        foreach(const QString language, m_vectorLanguages) {
            if(language == "English") {
                m_mapLanguageTranslations.insert(language, trStr(I18N_GENERIC_ENGLISH));
            }
            else if(language == "German") {
                m_mapLanguageTranslations.insert(language, trStr(I18N_GENERIC_GERMAN));
            }
            else {
                const QString message = QString(trStr(I18N_GENERIC_LANGUAGE_NOT_INTEGRATED)).arg(language);
                QMessageBox messageBox(QMessageBox::Warning, getApplicationName(), message);
                messageBox.exec();
            }
        }
    }

    // generic translations
    const char *I18N_GENERIC_YES = QT_TRANSLATE_NOOP("I18N_GENERIC_YES", "I18N_GENERIC_YES");
    const char *I18N_GENERIC_NO = QT_TRANSLATE_NOOP("I18N_GENERIC_NO", "I18N_GENERIC_NO");
    const char *I18N_GENERIC_OK = QT_TRANSLATE_NOOP("I18N_GENERIC_OK", "I18N_GENERIC_OK");
    const char *I18N_GENERIC_CANCEL = QT_TRANSLATE_NOOP("I18N_GENERIC_CANCEL", "I18N_GENERIC_CANCEL");
    const char *I18N_GENERIC_CLOSE = QT_TRANSLATE_NOOP("I18N_GENERIC_CLOSE", "I18N_GENERIC_CLOSE");
    const char *I18N_GENERIC_LANGUAGE_MISSING = QT_TRANSLATE_NOOP("I18N_GENERIC_LANGUAGE_MISSING", "I18N_GENERIC_LANGUAGE_MISSING");
    const char *I18N_GENERIC_LANGUAGE_NOT_INTEGRATED = QT_TRANSLATE_NOOP("I18N_GENERIC_LANGUAGE_NOT_INTEGRATED", "I18N_GENERIC_LANGUAGE_NOT_INTEGRATED");
    const char *I18N_GENERIC_ENGLISH = QT_TRANSLATE_NOOP("I18N_GENERIC_ENGLISH", "I18N_GENERIC_ENGLISH");
    const char *I18N_GENERIC_GERMAN = QT_TRANSLATE_NOOP("I18N_GENERIC_GERMAN", "I18N_GENERIC_GERMAN");

    // CrypTool main window translations
    const char *I18N_CRYPTOOL_MAIN_WINDOW_MENU_HELP = QT_TRANSLATE_NOOP("I18N_CRYPTOOL_MAIN_WINDOW_MENU_HELP", "I18N_CRYPTOOL_MAIN_WINDOW_MENU_HELP");

    // CrypTool dialog translations
    const char *I18N_CRYPTOOL_DIALOG_ABOUT_TITLE = QT_TRANSLATE_NOOP("I18N_CRYPTOOL_DIALOG_ABOUT_TITLE", "I18N_CRYPTOOL_DIALOG_ABOUT_TITLE");
    const char *I18N_CRYPTOOL_DIALOG_LANGUAGE_TITLE = QT_TRANSLATE_NOOP("I18N_CRYPTOOL_DIALOG_LANGUAGE_TITLE", "I18N_CRYPTOOL_DIALOG_LANGUAGE_TITLE");
    const char *I18N_CRYPTOOL_DIALOG_LANGUAGE_LABEL_DESCRIPTION = QT_TRANSLATE_NOOP("I18N_CRYPTOOL_DIALOG_LANGUAGE_LABEL_DESCRIPTION", "I18N_CRYPTOOL_DIALOG_LANGUAGE_LABEL_DESCRIPTION");

}
