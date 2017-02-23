// CryptographyHash.h

#ifndef _QCRYPTOOL_CORE_CRYPTOGRAPHY_CRYPTOGRAPHYHASH_H_
#define _QCRYPTOOL_CORE_CRYPTOGRAPHY_CRYPTOGRAPHYHASH_H_

#include <QCrypTool.h>

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

                const QMap<HashAlgorithmType, QString> mapHashAlgorithmNames = {
                    { HASH_ALGORITHM_TYPE_MD4, "MD4" },
                    { HASH_ALGORITHM_TYPE_MD5, "MD5" },
                    { HASH_ALGORITHM_TYPE_SHA, "SHA" },
                    { HASH_ALGORITHM_TYPE_SHA1, "SHA1" },
                    { HASH_ALGORITHM_TYPE_SHA256, "SHA256" },
                    { HASH_ALGORITHM_TYPE_SHA512, "SHA512" },
                    { HASH_ALGORITHM_TYPE_RIPEMD160, "RIPEMD160" }
                };

                QString getHashAlgorithmName(const HashAlgorithmType _hashAlgorithmType);
                HashAlgorithmType getHashAlgorithmType(const QString &_hashAlgorithmName);

            }
        }
    }
}

#endif
