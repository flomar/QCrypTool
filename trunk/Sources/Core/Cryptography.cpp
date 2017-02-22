// Cryptography.cpp

#include <Core/Cryptography.h>

namespace QCrypTool {
    namespace Core {
        namespace Cryptography {

            namespace Hash {

                QString getHashAlgorithmName(const HashAlgorithmType _hashAlgorithmType) {
                    foreach(const HashAlgorithmType hashAlgorithmType, mapHashAlgorithmNames.keys()) {
                        if(hashAlgorithmType == _hashAlgorithmType) {
                            return mapHashAlgorithmNames.value(_hashAlgorithmType);
                        }
                    }
                    return QString::null;
                }

                HashAlgorithmType getHashAlgorithmType(const QString &_hashAlgorithmName) {
                    foreach(const HashAlgorithmType hashAlgorithmType, mapHashAlgorithmNames.keys()) {
                        if(mapHashAlgorithmNames.value(hashAlgorithmType) == _hashAlgorithmName) {
                            return hashAlgorithmType;
                        }
                    }
                    return HASH_ALGORITHM_TYPE_NULL;
                }

            }

            namespace Symmetric {

                QString getSymmetricAlgorithmName(const SymmetricAlgorithmType _symmetricAlgorithmType) {
                    foreach(const SymmetricAlgorithmType symmetricAlgorithmType, mapSymmetricAlgorithmNames.keys()) {
                        if(symmetricAlgorithmType == _symmetricAlgorithmType) {
                            return mapSymmetricAlgorithmNames.value(_symmetricAlgorithmType);
                        }
                    }
                    return QString::null;
                }

                SymmetricAlgorithmType getSymmetricAlgorithmType(const QString &_symmetricAlgorithmName) {
                    foreach(const SymmetricAlgorithmType symmetricAlgorithmType, mapSymmetricAlgorithmNames.keys()) {
                        if(mapSymmetricAlgorithmNames.value(symmetricAlgorithmType) == _symmetricAlgorithmName) {
                            return symmetricAlgorithmType;
                        }
                    }
                    return SYMMETRIC_ALGORITHM_TYPE_NULL;
                }

            }

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
