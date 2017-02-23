// CryptographyOpenSSL.h

#ifndef _QCRYPTOOL_CORE_CRYPTOGRAPHY_CRYPTOGRAPHYOPENSSL_H_
#define _QCRYPTOOL_CORE_CRYPTOGRAPHY_CRYPTOGRAPHYOPENSSL_H_

#include <QCrypTool.h>

namespace QCrypTool {
    namespace Core {
        namespace Cryptography {
            namespace OpenSSL {

                #include <openssl/bio.h>
                #include <openssl/pem.h>
                #include <openssl/err.h>
                #include <openssl/rand.h>
                #include <openssl/md4.h>
                #include <openssl/md5.h>
                #include <openssl/ripemd.h>
                #include <openssl/sha.h>
                #include <openssl/evp.h>
                #include <openssl/x509v3.h>

            }
        }
    }
}

#endif
