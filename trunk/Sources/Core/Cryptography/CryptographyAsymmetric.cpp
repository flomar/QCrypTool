// CryptographyAsymmetric.cpp

#include <Core/Cryptography/CryptographyAsymmetric.h>

namespace QCrypTool {
    namespace Core {
        namespace Cryptography {
            namespace Asymmetric {

                QString getAsymmetricAlgorithmName(const AsymmetricAlgorithmType _asymmetricAlgorithmType) {
                    foreach(const AsymmetricAlgorithmType asymmetricAlgorithmType, mapAsymmetricAlgorithmNames.keys()) {
                        if(asymmetricAlgorithmType == _asymmetricAlgorithmType) {
                            return mapAsymmetricAlgorithmNames.value(_asymmetricAlgorithmType);
                        }
                    }
                    return QString::null;
                }

                AsymmetricAlgorithmType getAsymmetricAlgorithmType(const QString &_asymmetricAlgorithmName) {
                    foreach(const AsymmetricAlgorithmType asymmetricAlgorithmType, mapAsymmetricAlgorithmNames.keys()) {
                        if(mapAsymmetricAlgorithmNames.value(asymmetricAlgorithmType) == _asymmetricAlgorithmName) {
                            return asymmetricAlgorithmType;
                        }
                    }
                    return ASYMMETRIC_ALGORITHM_TYPE_NULL;
                }

            }
        }
    }
}
