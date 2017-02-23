// CryptographyAsymmetric.h

#ifndef _QCRYPTOOL_CORE_CRYPTOGRAPHY_CRYPTOGRAPHYASYMMETRIC_H_
#define _QCRYPTOOL_CORE_CRYPTOGRAPHY_CRYPTOGRAPHYASYMMETRIC_H_

#include <QCrypTool.h>

namespace QCrypTool {
    namespace Core {
        namespace Cryptography {
            namespace Asymmetric {

                enum AsymmetricAlgorithmType {
                    ASYMMETRIC_ALGORITHM_TYPE_NULL,
                    ASYMMETRIC_ALGORITHM_TYPE_RSA,
                    ASYMMETRIC_ALGORITHM_TYPE_DSA,
                    ASYMMETRIC_ALGORITHM_TYPE_ECC
                };

                const QMap<AsymmetricAlgorithmType, QString> mapAsymmetricAlgorithmNames = {
                    { ASYMMETRIC_ALGORITHM_TYPE_RSA, "RSA" },
                    { ASYMMETRIC_ALGORITHM_TYPE_DSA, "DSA" },
                    { ASYMMETRIC_ALGORITHM_TYPE_ECC, "ECC" }
                };

                QString getAsymmetricAlgorithmName(const AsymmetricAlgorithmType _asymmetricAlgorithmType);
                AsymmetricAlgorithmType getAsymmetricAlgorithmType(const QString &_asymmetricAlgorithmName);

            }
        }
    }
}

#endif
