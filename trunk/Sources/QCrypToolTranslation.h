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
        void setLanguage(const QString &_language);
    public:
        QVector<QString> getLanguages() const;
        QString getLanguage() const;
    public:
        QString getLanguageTranslated(const QString &_languageUntranslated) const;
        QString getLanguageUntranslated(const QString &_languageTranslated) const;
    public:
        QString getString(const QString &_identifier) const;
    signals:
        void signalChangedLanguage();
    private:
        QTranslator m_translator;
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
    extern const char *I18N_GENERIC_ENGLISH;
    extern const char *I18N_GENERIC_GERMAN;

    // CrypTool main window translations
    extern const char *I18N_CRYPTOOL_MAINWINDOW_MENUHELP;
    extern const char *I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONSTARTINGPAGE;
    extern const char *I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONINDEX;
    extern const char *I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONSCENARIOSTUTORIALS;
    extern const char *I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONREADME;
    extern const char *I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONCTBOOK;
    extern const char *I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONPRESENTATION;
    extern const char *I18N_CRYPTOOL_MAINWINDOW_MENUHELPACTIONABOUTQCRYPTOOL;

    // CrypTool dialog translations
    extern const char *I18N_CRYPTOOL_DIALOGABOUT_TITLE;
    extern const char *I18N_CRYPTOOL_DIALOGABOUT_APPLICATIONINFORMATION;
    extern const char *I18N_CRYPTOOL_DIALOGABOUT_APPLICATIONLICENSINGINFORMATION;
    extern const char *I18N_CRYPTOOL_DIALOGLANGUAGE_TITLE;
    extern const char *I18N_CRYPTOOL_DIALOGLANGUAGE_LABELDESCRIPTION;

}

#endif
