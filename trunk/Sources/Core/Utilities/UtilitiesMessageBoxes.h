// UtilitiesMessageBoxes.h

#ifndef _QCT_CORE_UTILITIES_UTILITIESMESSAGEBOXES_H_
#define _QCT_CORE_UTILITIES_UTILITIESMESSAGEBOXES_H_

#include <QCT.h>

namespace QCT {
    namespace Core {
        namespace Utilities {
            namespace MessageBoxes {

                int execMessageBoxInformation(const QString &_message);
                int execMessageBoxWarning(const QString &_message);
                int execMessageBoxCritical(const QString &_message);

            }
        }
    }
}

#endif
