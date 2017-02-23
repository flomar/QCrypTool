// CryptographySymmetric.h

#ifndef _QCRYPTOOL_CORE_CRYPTOGRAPHY_CRYPTOGRAPHYSYMMETRIC_H_
#define _QCRYPTOOL_CORE_CRYPTOGRAPHY_CRYPTOGRAPHYSYMMETRIC_H_

#include <QCrypTool.h>

namespace QCrypTool {
    namespace Core {
        namespace Cryptography {
            namespace Symmetric {

                enum SymmetricAlgorithmType {
                    SYMMETRIC_ALGORITHM_TYPE_NULL,
                    SYMMETRIC_ALGORITHM_TYPE_IDEA,
                    SYMMETRIC_ALGORITHM_TYPE_RC2,
                    SYMMETRIC_ALGORITHM_TYPE_RC4,
                    SYMMETRIC_ALGORITHM_TYPE_DES_ECB,
                    SYMMETRIC_ALGORITHM_TYPE_DES_CBC,
                    SYMMETRIC_ALGORITHM_TYPE_TRIPLE_DES_ECB,
                    SYMMETRIC_ALGORITHM_TYPE_TRIPLE_DES_CBC,
                    SYMMETRIC_ALGORITHM_TYPE_AES
                };

                const QMap<SymmetricAlgorithmType, QString> mapSymmetricAlgorithmNames = {
                    { SYMMETRIC_ALGORITHM_TYPE_IDEA, "IDEA" },
                    { SYMMETRIC_ALGORITHM_TYPE_RC2, "RC2" },
                    { SYMMETRIC_ALGORITHM_TYPE_RC4, "RC4" },
                    { SYMMETRIC_ALGORITHM_TYPE_DES_ECB, "DES (ECB)" },
                    { SYMMETRIC_ALGORITHM_TYPE_DES_CBC, "DES (CBC)" },
                    { SYMMETRIC_ALGORITHM_TYPE_TRIPLE_DES_ECB, "3DES (ECB)" },
                    { SYMMETRIC_ALGORITHM_TYPE_TRIPLE_DES_CBC, "3DES (CBC)" },
                    { SYMMETRIC_ALGORITHM_TYPE_AES, "AES" }
                };

                QString getSymmetricAlgorithmName(const SymmetricAlgorithmType _symmetricAlgorithmType);
                SymmetricAlgorithmType getSymmetricAlgorithmType(const QString &_symmetricAlgorithmName);

            }
        }
    }
}

#endif
