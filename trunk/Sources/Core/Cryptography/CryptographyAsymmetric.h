// CryptographyAsymmetric.h

#ifndef _QCRYPTOOL_CORE_CRYPTOGRAPHY_CRYPTOGRAPHYASYMMETRIC_H_
#define _QCRYPTOOL_CORE_CRYPTOGRAPHY_CRYPTOGRAPHYASYMMETRIC_H_

#include <QCrypTool.h>

#include <Core/Cryptography/CryptographyOpenSSL.h>

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

            }
        }
    }
}

#endif
