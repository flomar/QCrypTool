// UtilitiesString.cpp

#include <Core/Utilities.h>

namespace QCT {
    namespace Core {
        namespace Utilities {
            namespace String {

                QString fillLeft(const QString &_string, const char _byte, const int _length) {
                    QString resultString = _string;
                    const int numberOfFillBytes = _length - resultString.length();
                    for(int indexByte=0; indexByte<numberOfFillBytes; indexByte++) {
                        resultString.prepend(_byte);
                    }
                    return resultString;
                }

                QString fillRight(const QString &_string, const char _byte, const int _length) {
                    QString resultString = _string;
                    const int numberOfFillBytes = _length - resultString.length();
                    for(int indexByte=0; indexByte<numberOfFillBytes; indexByte++) {
                        resultString.append(_byte);
                    }
                    return resultString;
                }

                QString toText(const QByteArray &_byteArray, const QString &_replacement) {
                    QString resultString;
                    for(int indexByte=0; indexByte<_byteArray.length(); indexByte++) {
                        const char byte = _byteArray.at(indexByte);
                        if(isprint(byte)) {
                            resultString.append(byte);
                        }
                        else {
                            resultString.append(_replacement);
                        }
                    }
                    return resultString;
                }

                QString toHex(const QByteArray &_byteArray, const QString &_separator) {
                    QString resultString = _byteArray.toHex().toUpper();
                    const int numberOfSeparators = resultString.length() / 2 - 1;
                    for(int indexSeparator=0; indexSeparator<numberOfSeparators; indexSeparator++) {
                        const int offset = (indexSeparator + 2) * _separator.length() + indexSeparator * 2;
                        resultString.insert(offset, _separator);
                    }
                    return resultString;
                }

            }
        }
    }
}
