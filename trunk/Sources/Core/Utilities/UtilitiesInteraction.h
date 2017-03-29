// UtilitiesInteraction.h

#ifndef _QCT_CORE_UTILITIES_UTILITIESINTERACTION_H_
#define _QCT_CORE_UTILITIES_UTILITIESINTERACTION_H_

#include <QCT.h>

namespace QCT {
    namespace Core {
        namespace Utilities {
            namespace Interaction {

                // This function asks the user for a file name using the
                // standard Qt file dialog. If the dialog is rejected or
                // an error occurs, an empty string is returned.
                QString getSelectedFileName();

            }
        }
    }
}

#endif
