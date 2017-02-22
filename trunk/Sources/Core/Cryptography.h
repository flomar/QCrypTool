// Cryptography.h

#ifndef _QCRYPTOOL_CORE_CRYPTOGRAPHY_H_
#define _QCRYPTOOL_CORE_CRYPTOGRAPHY_H_

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
