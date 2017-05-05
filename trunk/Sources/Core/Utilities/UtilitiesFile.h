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

                // This function returns the size of the specified file.
                // In case of an error, -1 is returned.
                qint64 getFileSize(const QString &_fileName);

                // This function calculates the number of non-printable
                // characters in the specified file. If an error occurs,
                // the function returns -1. The additional parameter is
                // provided to supply characters to the function which
                // are treated as printable although they really aren't.
                qint64 calculateNonPrintableCharactersInFile(const QString &_fileName, const QString &_charactersTreatedAsPrintable = "\n");

            }
        }
    }
}

#endif
