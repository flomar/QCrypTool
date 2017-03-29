// UtilitiesPlatformCode.cpp

#include <Core/Utilities.h>

#ifdef Q_OS_LINUX
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#endif
#ifdef Q_OS_MAC

#endif
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

                namespace Windowing {

#ifdef Q_OS_LINUX
                    Window findWindow(Display *_display, const Atom _atom, const Window _window, const qint64 _processIdentifier) {
                        Atom atom = 0;
                        int format = 0;
                        unsigned long items = 0;
                        unsigned long bytes = 0;
                        unsigned char *pid = 0;
                        XGetWindowProperty(_display, _window, _atom, 0, 1, 0, XA_CARDINAL, &atom, &format, &items, &bytes, &pid);
                        if(pid != 0) {
                            if(_processIdentifier == (qint64)(*((unsigned long*)(pid)))) {
                                XFree(pid);
                                return _window;
                            }
                            XFree(pid);
                        }
                        Window windowRoot;
                        Window windowParent;
                        Window *windowsChildren;
                        unsigned int children;
                        if(XQueryTree(_display, _window, &windowRoot, &windowParent, &windowsChildren, &children)) {
                            for(unsigned int i=0; i<children; i++) {
                                Window window = findWindow(_display, _atom, windowsChildren[i], _processIdentifier);
                                if(window) {
                                    return window;
                                }
                            }
                        }
                        return 0;
                    }

                    void raiseWindow(Display *_display, const Window _windowRoot, Window _window) {
                        XEvent event;
                        event.type = ClientMessage;
                        event.xclient.display = _display;
                        event.xclient.window = _window;
                        event.xclient.message_type = XInternAtom(_display, "_NET_ACTIVE_WINDOW", 0);
                        event.xclient.format = 32;
                        event.xclient.data.l[0] = 2L;
                        event.xclient.data.l[1] = CurrentTime;
                        XSendEvent(_display, _windowRoot, 0, SubstructureNotifyMask | SubstructureRedirectMask, &event);
                    }
#endif
#ifdef Q_OS_MAC

#endif
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
                        Display *display = XOpenDisplay(0);
                        if(!display) {
                            return false;
                        }
                        Atom atom = XInternAtom(display, "_NET_WM_PID", 1);
                        if(!atom) {
                            XCloseDisplay(display);
                            return false;
                        }
                        Window windowRoot = XDefaultRootWindow(display);
                        if(!windowRoot) {
                            XCloseDisplay(display);
                            return false;
                        }
                        Window window = findWindow(display, atom, windowRoot, _processIdentifier);
                        if(!window) {
                            XCloseDisplay(display);
                            return false;
                        }
                        raiseWindow(display, windowRoot, window);
                        XCloseDisplay(display);
                        return true;
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
