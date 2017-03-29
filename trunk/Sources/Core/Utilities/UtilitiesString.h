// UtilitiesString.h

#ifndef _QCT_CORE_UTILITIES_UTILITIESSTRING_H_
#define _QCT_CORE_UTILITIES_UTILITIESSTRING_H_

#include <QCT.h>

namespace QCT {
    namespace Core {
        namespace Utilities {
            namespace String {

                // This function fills a string with the specified bytes
                // from the left until the desired length is reached.
                QString fillLeft(const QString &_string, const char _byte, const int _length);

                // This function fills a string with the specified bytes
                // from the right until the desired length is reached.
                QString fillRight(const QString &_string, const char _byte, const int _length);

                // This function converts a byte array to a text string
                // with the specified replacement for non-printable bytes.
                QString toText(const QByteArray &_byteArray, const QString &_replacement);

                // This function converts a byte array to a hexadecimal
                // string with the specified separator inbetween bytes.
                QString toHex(const QByteArray &_byteArray, const QString &_separator);

            }
        }
    }
}

#endif
