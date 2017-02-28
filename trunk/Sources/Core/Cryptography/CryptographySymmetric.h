// CryptographySymmetric.h

#ifndef _QCT_CORE_CRYPTOGRAPHY_CRYPTOGRAPHYSYMMETRIC_H_
#define _QCT_CORE_CRYPTOGRAPHY_CRYPTOGRAPHYSYMMETRIC_H_

#include <QCT.h>

#include <Core/Cryptography/CryptographyOpenSSL.h>

namespace QCT {
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

            }
        }
    }
}

#endif
