// CryptographySymmetric.h

#ifndef _QCRYPTOOL_CORE_CRYPTOGRAPHY_CRYPTOGRAPHYSYMMETRIC_H_
#define _QCRYPTOOL_CORE_CRYPTOGRAPHY_CRYPTOGRAPHYSYMMETRIC_H_

#include <QCrypTool.h>

#include <Core/Cryptography/CryptographyOpenSSL.h>

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

            }
        }
    }
}

#endif
