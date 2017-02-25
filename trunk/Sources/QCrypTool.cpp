// QCrypTool.cpp

#include <QCrypTool.h>

#define QCRYPTOOL_APPLICATION_NAME "QCrypTool"
#define QCRYPTOOL_APPLICATION_VERSION "0.1.17"
#define QCRYPTOOL_APPLICATION_COPYRIGHT "(C) 2017 CrypTool Team"

namespace QCrypTool {

    QString getApplicationName() {
        return QString(QCRYPTOOL_APPLICATION_NAME);
    }

    QString getApplicationVersion() {
        return QString(QCRYPTOOL_APPLICATION_VERSION);
    }

    QString getApplicationCopyright() {
        return QString(QCRYPTOOL_APPLICATION_COPYRIGHT);
    }

}
