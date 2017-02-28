// CryptographyOpenSSL.h

#ifndef _QCT_CORE_CRYPTOGRAPHY_CRYPTOGRAPHYOPENSSL_H_
#define _QCT_CORE_CRYPTOGRAPHY_CRYPTOGRAPHYOPENSSL_H_

#include <QCT.h>

namespace QCT {
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
