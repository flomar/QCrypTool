// CryptographyHash.cpp

#include <Core/Cryptography/CryptographyHash.h>

namespace QCrypTool {
    namespace Core {
        namespace Cryptography {
            namespace Hash {

                QString getHashAlgorithmName(const HashAlgorithmType _hashAlgorithmType) {
                    foreach(const HashAlgorithmType hashAlgorithmType, mapHashAlgorithmNames.keys()) {
                        if(hashAlgorithmType == _hashAlgorithmType) {
                            return mapHashAlgorithmNames.value(_hashAlgorithmType);
                        }
                    }
                    return QString::null;
                }

                HashAlgorithmType getHashAlgorithmType(const QString &_hashAlgorithmName) {
                    foreach(const HashAlgorithmType hashAlgorithmType, mapHashAlgorithmNames.keys()) {
                        if(mapHashAlgorithmNames.value(hashAlgorithmType) == _hashAlgorithmName) {
                            return hashAlgorithmType;
                        }
                    }
                    return HASH_ALGORITHM_TYPE_NULL;
                }

            }
        }
    }
}
