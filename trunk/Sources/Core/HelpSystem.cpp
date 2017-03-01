// HelpSystem.cpp

#include <Core/HelpSystem.h>

#ifdef Q_OS_LINUX
// TODO/FIXME: insert Linux-specific callback function
#endif
#ifdef Q_OS_MAC
// TODO/FIXME: insert MacOS-specific callback function
#endif
#ifdef Q_OS_WIN
#include <Windows.h>
static BOOL CALLBACK bringChildProcessWindowToTop(HWND _hwnd, LPARAM _lparam) {
    DWORD processIdentifier = *(DWORD*)(_lparam);
    DWORD windowProcessIdentifier = NULL;
    GetWindowThreadProcessId(_hwnd, &windowProcessIdentifier);
    if(windowProcessIdentifier == processIdentifier) {
        SwitchToThisWindow(_hwnd, TRUE);
        SetForegroundWindow(_hwnd);
        return FALSE;
    }
    return TRUE;
}
#endif

namespace QCT {
    namespace Core {

        HelpSystem::HelpSystem(QObject *_parent) :
            QObject(_parent) {

        }

        HelpSystem::~HelpSystem() {

        }

        HelpSystem &HelpSystem::instance() {
            static HelpSystem helpSystem;
            return helpSystem;
        }

        void HelpSystem::slotRequestContextHelp(const QString &_identifierContextHelp) {
            if(m_processAssistant.isNull()) {
                m_processAssistant = QSharedPointer<QProcess>(new QProcess());
                connect(m_processAssistant.data(), SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(slotProcessAssistantFinished(int,QProcess::ExitStatus)));
                m_processAssistant->setWorkingDirectory(qApp->applicationDirPath());
                QList<QString> arguments;
                arguments << QString("-enableRemoteControl");
                arguments << QString("-collectionFile");
                arguments << QString("QCTHelpEnglish.qhc");
                m_processAssistant->start(QString("assistant"), arguments);
                if(!m_processAssistant->waitForStarted()) {
                    return;
                }
            }
            else {
#ifdef Q_OS_LINUX
                QMessageBox messageBox(QMessageBox::Information, "TODO/FIXME", "TODO/FIXME: implement Linux-specific code");
                messageBox.exec();
#endif
#ifdef Q_OS_MAC
                QMessageBox messageBox(QMessageBox::Information, "TODO/FIXME", "TODO/FIXME: implement Linux-specific code");
                messageBox.exec();
#endif
#ifdef Q_OS_WIN
                DWORD childProcessIdentifier = m_processAssistant->pid()->dwProcessId;
                EnumWindows(bringChildProcessWindowToTop, (LPARAM)(&childProcessIdentifier));
#endif
            }
            QByteArray byteArray;
            //TODO/FIXME: take the language into account here!
            //byteArray.append(QString("setSource qthelp://com.CrypToolTeam.QCrypTool/%1\n").arg(_identifierContextHelp));
            byteArray.append(QString("setSource qthelp://com.CrypToolTeam.QCrypTool/English/English/QCrypToolDevelopment.html"));
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

    }
}
