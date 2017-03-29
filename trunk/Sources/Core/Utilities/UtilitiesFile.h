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
                QString createTempFileName(const QString &_extension = "tmp");

                // This function is based on the "createTempFileName" function
                // above. Instead of simply returning the created file name,
                // this function creates the file and then returns its name.
                // If it fails, an empty string is returned.
                QString createTempFile(const QString &_extension = "tmp");

            }
        }
    }
}

#endif
