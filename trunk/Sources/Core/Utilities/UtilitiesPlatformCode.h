// UtilitiesPlatformCode.h

#ifndef _QCT_CORE_UTILITIES_UTILITIESPLATFORMCODE_H_
#define _QCT_CORE_UTILITIES_UTILITIESPLATFORMCODE_H_

#include <QCT.h>

namespace QCT {
    namespace Core {
        namespace Utilities {
            namespace PlatformCode {

                namespace Generic {

                    QString getAssistantExecutable();

                }

                namespace Window {

                    bool bringWindowToFront(const qint64 _processIdentifier);

                }

            }
        }
    }
}

#endif
