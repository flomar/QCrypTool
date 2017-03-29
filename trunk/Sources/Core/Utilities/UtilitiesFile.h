// UtilitiesFile.h

#ifndef _QCT_CORE_UTILITIES_UTILITIESFILE_H_
#define _QCT_CORE_UTILITIES_UTILITIESFILE_H_

#include <QCT.h>

namespace QCT {
    namespace Core {
        namespace Utilities {
            namespace File {

                // This function creates an absolute path to a file in the
                // system's temporary folder. The resulting file name is
                // guaranteed to not point to an existing file. In case
                // something goes wrong, an empty string is returned.
                QString createTempFileName(const QString &_extension = ".tmp");

            }
        }
    }
}

#endif
