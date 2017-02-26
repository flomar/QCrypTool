// QCrypToolTranslation.h

#ifndef _QCRYPTOOL_QCRYPTOOLTRANSLATION_H_
#define _QCRYPTOOL_QCRYPTOOLTRANSLATION_H_

#include <QCrypTool.h>

namespace QCrypTool {

    class Translation : public QObject {
        Q_OBJECT
    protected:
        Translation(QObject *_parent = 0);
        virtual ~Translation();
    public:
        static Translation &instance();
    public:
        void initializeLanguages();
    public:
        void setLanguage(const QString &_language);
    public:
        const QVector<QString> &getLanguages() const { return m_vectorLanguages; }
        const QString &getLanguage() const { return m_language; }
    public:
        QString getLanguageTranslated(const QString &_languageUntranslated) const;
        QString getLanguageUntranslated(const QString &_languageTranslated) const;
    public:
        QString getString(const QString &_identifier) const;
    signals:
        void signalChangedLanguage();
    private:
        QVector<QString> getVectorAvailableQmFileNames() const;
        void updateLanguageTranslations();
    private:
        QTranslator m_translator;
        QVector<QString> m_vectorLanguages;
        QMap<QString, QString> m_mapLanguageTranslations;
        QString m_language;
    };

    #define trStrQuoted(ID) #ID
    #define trStr(ID) Translation::instance().getString(trStrQuoted(ID))

    // generic translations
    extern const char *I18N_GENERIC_YES;
    extern const char *I18N_GENERIC_NO;
    extern const char *I18N_GENERIC_OK;
    extern const char *I18N_GENERIC_CANCEL;
    extern const char *I18N_GENERIC_CLOSE;
    extern const char *I18N_GENERIC_LANGUAGE_MISSING;
    extern const char *I18N_GENERIC_LANGUAGE_NOT_INTEGRATED;
    extern const char *I18N_GENERIC_ENGLISH;
    extern const char *I18N_GENERIC_GERMAN;

    // CrypTool main window translations
    extern const char *I18N_CRYPTOOL_MAIN_WINDOW_MENU_HELP;

    // CrypTool dialog translations
    extern const char *I18N_CRYPTOOL_DIALOG_ABOUT_TITLE;
    extern const char *I18N_CRYPTOOL_DIALOG_LANGUAGE_TITLE;
    extern const char *I18N_CRYPTOOL_DIALOG_LANGUAGE_LABEL_DESCRIPTION;

}

#endif
