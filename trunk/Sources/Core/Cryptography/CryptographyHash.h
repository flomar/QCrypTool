// CryptographyHash.h

#ifndef _QCRYPTOOL_CORE_CRYPTOGRAPHY_CRYPTOGRAPHYHASH_H_
#define _QCRYPTOOL_CORE_CRYPTOGRAPHY_CRYPTOGRAPHYHASH_H_

#include <QCrypTool.h>

#include <Core/Cryptography/CryptographyOpenSSL.h>

namespace QCrypTool {
    namespace Core {
        namespace Cryptography {
            namespace Hash {

                enum HashAlgorithmType {
                    HASH_ALGORITHM_TYPE_NULL,
                    HASH_ALGORITHM_TYPE_MD4,
                    HASH_ALGORITHM_TYPE_MD5,
                    HASH_ALGORITHM_TYPE_SHA,
                    HASH_ALGORITHM_TYPE_SHA1,
                    HASH_ALGORITHM_TYPE_SHA256,
                    HASH_ALGORITHM_TYPE_SHA512,
                    HASH_ALGORITHM_TYPE_RIPEMD160
                };

            }
        }
    }
}

#endif
