// CryptographyAsymmetric.h

#ifndef _QCT_CORE_CRYPTOGRAPHY_CRYPTOGRAPHYASYMMETRIC_H_
#define _QCT_CORE_CRYPTOGRAPHY_CRYPTOGRAPHYASYMMETRIC_H_

#include <QCT.h>

#include <Core/Cryptography/CryptographyOpenSSL.h>

namespace QCT {
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
