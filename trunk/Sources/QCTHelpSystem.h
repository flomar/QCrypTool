// QCTHelpSystem.h

#ifndef _QCT_HELPSYSTEM_H_
#define _QCT_HELPSYSTEM_H_

#include <QCT.h>

#include <Core/Utilities.h>

namespace QCT {

    // This singleton class implements the context-sensitive help system
    // of QCrypTool. All MainWindow- and Dialog-derived classes register
    // themselves with the help system and emit a signal whenever the F1
    // key is pressed. These signals are collected in this class.
    class HelpSystem : public QObject {
        Q_OBJECT
    protected:
        HelpSystem(QObject *_parent = 0);
        virtual ~HelpSystem();
    public:
        static HelpSystem &instance();
    private slots:
        void slotRequestContextHelp(const QString &_identifierContextHelp);
    private slots:
        void slotProcessAssistantFinished(const int _exitCode, const QProcess::ExitStatus _exitStatus);
    private:
        QString getHelpLanguage() const;
        bool doesCollectionFileExist(const QString &_language) const;
        bool startProcessAssistant(const QString &_language);
    private:
        QSharedPointer<QProcess> m_processAssistant;
    };

}

#endif
