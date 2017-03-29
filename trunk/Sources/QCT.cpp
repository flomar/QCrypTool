// QCT.cpp

#include <QCT.h>

#define QCT_PROJECT_NAME "[QCT_PROJECT_NAME]"
#define QCT_PROJECT_VERSION "[QCT_PROJECT_VERSION]"
#define QCT_PROJECT_COPYRIGHT "[QCT_PROJECT_COPYRIGHT]"

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
