// QCrypTool.cpp

#include <QCrypTool.h>

#define QCRYPTOOL_APPLICATION_NAME "[QCRYPTOOL_APPLICATION_NAME]"
#define QCRYPTOOL_APPLICATION_VERSION "[QCRYPTOOL_APPLICATION_NAME]"
#define QCRYPTOOL_APPLICATION_COPYRIGHT "[QCRYPTOOL_APPLICATION_NAME]"

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
