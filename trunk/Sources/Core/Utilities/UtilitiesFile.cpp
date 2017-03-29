// UtilitiesFile.cpp

#include <Core/Utilities.h>

namespace QCT {
    namespace Core {
        namespace Utilities {
            namespace File {

                QString createTempFileName(const QString &_extension) {
                    const QString path = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
                    if(!path.isEmpty()) {
                        while(true) {
                            const qint64 time = Utilities::DateAndTime::getCurrentDateAndTime();
                            const QString tempFileName = QString("%1/%2.%3").arg(path).arg(time).arg(_extension);
                            QFileInfo tempFileInfo(tempFileName);
                            if(!tempFileInfo.exists()) {
                                return tempFileName;
                            }
                            else {
                                QThread::msleep(1);
                            }
                        }
                    }
                    return QString::null;
                }

                QString createTempFile(const QString &_extension) {
                    const QString tempFileName = createTempFileName(_extension);
                    if(!tempFileName.isEmpty()) {
                        QFile file(tempFileName);
                        if(file.open(QFile::ReadWrite | QFile::Truncate)) {
                            return tempFileName;
                        }
                    }
                    return QString::null;
                }

            }
        }
    }
}
