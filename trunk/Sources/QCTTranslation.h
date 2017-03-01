// QCTTranslation.h

#ifndef _QCT_QCTTRANSLATION_H_
#define _QCT_QCTTRANSLATION_H_

#include <QCT.h>

namespace QCT {

    class Translation : public QObject {
        Q_OBJECT
    protected:
        Translation(QObject *_parent = 0);
        virtual ~Translation();
    public:
        static Translation &instance();
    public:
        void initializeLanguages();
        // If this function is invoked without a parameter, the function
        // tries to adhere to the system locale when setting the language.
        void setLanguage(const QString &_language = QString::null);
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

    // QCrypTool main window translations
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKI;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIMENUPKI;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIMENUPKIACTIONCREATEIMPORTKEYS;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIMENUPKIACTIONDISPLAYEXPORTKEYS;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONCREATESIGNATURE;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONVERIFYSIGNATURE;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONEXTRACTSIGNATURE;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONSIGNATUREDEMONSTRATION;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUHELP;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONSTARTINGPAGE;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONINDEX;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONSCENARIOSTUTORIALS;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONREADME;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONCTBOOK;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONPRESENTATION;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONABOUTQCRYPTOOL;

    // QCrypTool dialog translations
    extern const char *I18N_QCRYPTOOL_DIALOGABOUT_TITLE;
    extern const char *I18N_QCRYPTOOL_DIALOGABOUT_PROJECTINFORMATION;
    extern const char *I18N_QCRYPTOOL_DIALOGABOUT_PROJECTLICENSINGINFORMATION;
    extern const char *I18N_QCRYPTOOL_DIALOGLANGUAGE_TITLE;
    extern const char *I18N_QCRYPTOOL_DIALOGLANGUAGE_LABELDESCRIPTION;

}

#endif