// CryptographySymmetric.cpp

#include <Core/Cryptography/CryptographySymmetric.h>

namespace QCrypTool {
    namespace Core {
        namespace Cryptography {
            namespace Symmetric {

                QString getSymmetricAlgorithmName(const SymmetricAlgorithmType _symmetricAlgorithmType) {
                    foreach(const SymmetricAlgorithmType symmetricAlgorithmType, mapSymmetricAlgorithmNames.keys()) {
                        if(symmetricAlgorithmType == _symmetricAlgorithmType) {
                            return mapSymmetricAlgorithmNames.value(_symmetricAlgorithmType);
                        }
                    }
                    return QString::null;
                }

                SymmetricAlgorithmType getSymmetricAlgorithmType(const QString &_symmetricAlgorithmName) {
                    foreach(const SymmetricAlgorithmType symmetricAlgorithmType, mapSymmetricAlgorithmNames.keys()) {
                        if(mapSymmetricAlgorithmNames.value(symmetricAlgorithmType) == _symmetricAlgorithmName) {
                            return symmetricAlgorithmType;
                        }
                    }
                    return SYMMETRIC_ALGORITHM_TYPE_NULL;
                }

            }
        }
    }
}
