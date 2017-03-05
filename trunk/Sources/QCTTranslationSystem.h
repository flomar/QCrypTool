// QCTTranslationSystem.h

#ifndef _QCT_QCTTRANSLATIONSYSTEM_H_
#define _QCT_QCTTRANSLATIONSYSTEM_H_

#include <QCT.h>

namespace QCT {

    // This singleton class provides run-time translation capabilities
    // and stores all I18N-related identifiers used throughout the
    // application in a single point of entry. In conjuction with
    // the "lupdate" and "lrelease" tools, this class enables
    // translators to use the "QtLinguist" tool to contribute to
    // the project with as little effort as possible.
    class TranslationSystem : public QObject {
        Q_OBJECT
    protected:
        TranslationSystem(QObject *_parent = 0);
        virtual ~TranslationSystem();
    public:
        static TranslationSystem &instance();
    public:
        void initialize();
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
        void signalChangedLanguage(const QString &_language);
    private:
        QTranslator m_translator;
        QMap<QString, QString> m_mapLanguageTranslations;
        QString m_language;
    };

    #define trStrQuoted(ID) #ID
    #define trStr(ID) TranslationSystem::instance().getString(trStrQuoted(ID))

    // generic translations
    extern const char *I18N_GENERIC_YES;
    extern const char *I18N_GENERIC_NO;
    extern const char *I18N_GENERIC_OK;
    extern const char *I18N_GENERIC_CANCEL;
    extern const char *I18N_GENERIC_CLOSE;
    extern const char *I18N_GENERIC_ENGLISH;
    extern const char *I18N_GENERIC_GERMAN;

    // QCrypTool message translations
    extern const char *I18N_QCRYPTOOL_MESSAGEDATABASESYSTEM_DATABASEFILECOULDNOTBEOPENED;
    extern const char *I18N_QCRYPTOOL_MESSAGEDATABASESYSTEM_DATABASETABLEFORMATINVALID;
    extern const char *I18N_QCRYPTOOL_MESSAGEDATABASESYSTEM_DATABASEQUERYFAILED;

    // QCrypTool main window translations
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUFILE;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUFILEACTIONNEW;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUEDIT;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUEDITACTIONCUT;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUEDITACTIONCOPY;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUEDITACTIONPASTE;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUVIEW;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUVIEWMENUFONT;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUVIEWSHOWASTEXT;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUVIEWSHOWASHEX;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKI;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONCERTIFICATESTORE;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONCREATESIGNATURE;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONVERIFYSIGNATURE;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONEXTRACTSIGNATURE;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUDIGITALSIGNATURESPKIACTIONSIGNATUREDEMONSTRATION;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUOPTIONS;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUOPTIONSACTIONLANGUAGE;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUOPTIONSACTIONSCALING;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUHELP;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONSTARTINGPAGE;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONINDEX;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONSCENARIOSTUTORIALS;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONREADME;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONCTBOOK;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONPRESENTATION;
    extern const char *I18N_QCRYPTOOL_MAINWINDOW_MENUHELPACTIONABOUTQCRYPTOOL;

    // QCrypTool dialog translations
    extern const char *I18N_QCRYPTOOL_DIALOGCERTIFICATESTORE_TITLE;
    extern const char *I18N_QCRYPTOOL_DIALOGCERTIFICATESTORE_CHECKBOXSHOWRSACERTIFICATES;
    extern const char *I18N_QCRYPTOOL_DIALOGCERTIFICATESTORE_CHECKBOXSHOWDSACERTIFICATES;
    extern const char *I18N_QCRYPTOOL_DIALOGCERTIFICATESTORE_CHECKBOXSHOWECCCERTIFICATES;
    extern const char *I18N_QCRYPTOOL_DIALOGCERTIFICATESTORE_PUSHBUTTONCREATECERTIFICATE;
    extern const char *I18N_QCRYPTOOL_DIALOGCERTIFICATESTORE_PUSHBUTTONIMPORTCERTIFICATE;
    extern const char *I18N_QCRYPTOOL_DIALOGCERTIFICATESTORE_PUSHBUTTONDISPLAYCERTIFICATE;
    extern const char *I18N_QCRYPTOOL_DIALOGCERTIFICATESTORE_PUSHBUTTONEXPORTCERTIFICATE;
    extern const char *I18N_QCRYPTOOL_DIALOGCERTIFICATESTORE_PUSHBUTTONDELETECERTIFICATE;
    extern const char *I18N_QCRYPTOOL_DIALOGLANGUAGE_TITLE;
    extern const char *I18N_QCRYPTOOL_DIALOGLANGUAGE_LABELDESCRIPTION;
    extern const char *I18N_QCRYPTOOL_DIALOGSCALING_TITLE;
    extern const char *I18N_QCRYPTOOL_DIALOGSCALING_LABELDESCRIPTION;
    extern const char *I18N_QCRYPTOOL_DIALOGABOUTQCRYPTOOL_TITLE;
    extern const char *I18N_QCRYPTOOL_DIALOGABOUTQCRYPTOOL_PROJECTINFORMATION;
    extern const char *I18N_QCRYPTOOL_DIALOGABOUTQCRYPTOOL_PROJECTLICENSINGINFORMATION;

}

#endif
