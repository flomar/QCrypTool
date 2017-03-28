// QCT.cpp

#include <QCT.h>

#define QCT_PROJECT_NAME "QCrypTool"
#define QCT_PROJECT_VERSION "0.1.101"
#define QCT_PROJECT_COPYRIGHT "(C) 2017 CrypTool Team"

namespace QCT {

    QString getProjectName() {
        return QString(QCT_PROJECT_NAME);
    }

    QString getProjectVersion() {
        return QString(QCT_PROJECT_VERSION);
    }

    QString getProjectCopyright() {
        return QString(QCT_PROJECT_COPYRIGHT);
    }

}
