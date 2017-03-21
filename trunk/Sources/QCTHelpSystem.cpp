// QCTHelpSystem.cpp

#include <QCTHelpSystem.h>

#include <QCTDatabaseSystem.h>
#include <QCTOptionsSystem.h>
#include <QCTTranslationSystem.h>
#include <QCTScalingSystem.h>
#include <QCTHelpSystem.h>

namespace QCT {

    HelpSystem::HelpSystem(QObject *_parent) :
        QObject(_parent) {

    }

    HelpSystem::~HelpSystem() {

    }

    HelpSystem &HelpSystem::instance() {
        static HelpSystem helpSystem;
        return helpSystem;
    }

    bool HelpSystem::initialize() {
        return true;
    }

    void HelpSystem::slotRequestContextHelp(const QString &_identifierContextHelp) {
        const QString language = getHelpLanguage();
        if(language.isNull()) {
            Core::Utilities::MessageBoxes::execMessageBoxWarning("TODO/FIXME: help language invalid");
            return;
        }
        if(m_processAssistant.isNull()) {
            if(!startProcessAssistant(language)) {
                Core::Utilities::MessageBoxes::execMessageBoxCritical("TODO/FIXME: cannot start assistant");
                return;
            }
        }
        else {
            if(!Core::Utilities::PlatformCode::Windowing::bringWindowToFront(m_processAssistant->pid())) {
                Core::Utilities::MessageBoxes::execMessageBoxWarning("TODO/FIXME: cannot bring assistant to front");
                return;
            }
        }
        QByteArray byteArray;
        byteArray.append(QString("setSource qthelp://com.CrypToolTeam.QCrypTool/%1/%1/%2.html\n").arg(language).arg(_identifierContextHelp));
        m_processAssistant->write(byteArray);
    }

    void HelpSystem::slotProcessAssistantFinished(const int _exitCode, const QProcess::ExitStatus _exitStatus) {
        Q_UNUSED(_exitCode);
        Q_UNUSED(_exitStatus);
        if(!m_processAssistant.isNull()) {
            disconnect(m_processAssistant.data(), SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(slotProcessAssistantFinished(int,QProcess::ExitStatus)));
            m_processAssistant.clear();
        }
    }

    QString HelpSystem::getHelpLanguage() const {
        // Here we try to determine the language for the to-be-displayed
        // assistant instance. We try to go with the current translation
        // language and fall back to English if the current translation
        // language is invalid.
        const QString translationLanguage = TranslationSystem::instance().getLanguage();
        if(doesCollectionFileExist(translationLanguage)) {
            return translationLanguage;
        }
        const QString defaultLanguage = QString("English");
        if(doesCollectionFileExist(defaultLanguage)) {
            return defaultLanguage;
        }
        return QString::null;
    }

    bool HelpSystem::doesCollectionFileExist(const QString &_language) const {
        QFileInfo fileInfo(QString("%1/QCTHelp%2.qhc").arg(qApp->applicationDirPath()).arg(_language));
        return fileInfo.exists() && fileInfo.isFile();
    }

    bool HelpSystem::startProcessAssistant(const QString &_language) {
        m_processAssistant = QSharedPointer<QProcess>(new QProcess());
        connect(m_processAssistant.data(), SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(slotProcessAssistantFinished(int,QProcess::ExitStatus)));
        m_processAssistant->setWorkingDirectory(qApp->applicationDirPath());
        QList<QString> arguments;
        arguments << QString("-collectionFile");
        arguments << QString("QCTHelp%1.qhc").arg(_language);
        arguments << QString("-enableRemoteControl");
        m_processAssistant->start(Core::Utilities::PlatformCode::Generic::getAssistantExecutable(), arguments);
        if(!m_processAssistant->waitForStarted()) {
            m_processAssistant.clear();
            return false;
        }
        return true;
    }

}
