// UtilitiesPlatformCode.cpp

#include <Core/Utilities/UtilitiesPlatformCode.h>
#include <Core/Utilities/UtilitiesMessageBoxes.h>

#ifdef Q_OS_WIN
#include <Windows.h>
#endif

namespace QCT {
    namespace Core {
        namespace Utilities {
            namespace PlatformCode {

                namespace Generic {

                    QString getAssistantExecutable() {
                        const QString applicationDirectoryPath = qApp->applicationDirPath();
#ifdef Q_OS_LINUX
                        return QString("%1/%2").arg(applicationDirectoryPath).arg("assistant");
#endif
#ifdef Q_OS_MAC
                        // TODO/FIXME
#endif
#ifdef Q_OS_WIN
                        return QString("%1/%2").arg(applicationDirectoryPath).arg("assistant.exe");
#endif
                        MessageBoxes::execMessageBoxWarning("TODO/FIXME: implement platform-specific code (getAssistantExecutable)");
                        return QString::null;
                    }

                }

                namespace Window {

#ifdef Q_OS_WIN
                    static bool resultBringChildProcessWindowToTop = false;

                    static BOOL CALLBACK bringChildProcessWindowToTop(HWND _hwnd, LPARAM _lparam) {
                        DWORD processIdentifier = *(DWORD*)(_lparam);
                        DWORD windowProcessIdentifier = NULL;
                        GetWindowThreadProcessId(_hwnd, &windowProcessIdentifier);
                        if(windowProcessIdentifier == processIdentifier) {
                            SwitchToThisWindow(_hwnd, TRUE);
                            SetForegroundWindow(_hwnd);
                            resultBringChildProcessWindowToTop = true;
                            return FALSE;
                        }
                        return TRUE;
                    }
#endif
                    bool bringWindowToFront(const qint64 _processIdentifier) {
#ifdef Q_OS_LINUX
                        // TODO/FIXME
#endif
#ifdef Q_OS_MAC
                        // TODO/FIXME
#endif
#ifdef Q_OS_WIN
                        resultBringChildProcessWindowToTop = false;
                        DWORD childProcessIdentifier = (DWORD)(_processIdentifier);
                        EnumWindows(bringChildProcessWindowToTop, (LPARAM)(&childProcessIdentifier));
                        return resultBringChildProcessWindowToTop;
#endif
                        MessageBoxes::execMessageBoxWarning("TODO/FIXME: implement platform-specific code (bringWindowToFront)");
                        return false;
                    }

                }

            }
        }
    }
}
