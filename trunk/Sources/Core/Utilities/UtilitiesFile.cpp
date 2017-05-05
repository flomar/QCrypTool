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

                qint64 getFileSize(const QString &_fileName) {
                    QFile file(_fileName);
                    if(!file.open(QFile::ReadOnly)) {
                        return -1;
                    }
                    const qint64 fileSize = file.size();
                    return fileSize;
                }

                qint64 calculateNonPrintableCharactersInFile(const QString &_fileName, const QString &_charactersTreatedAsPrintable) {
                    const qint64 chunkSize = 32768;
                    qint64 nonPrintableCharacters = 0;
                    QFile file(_fileName);
                    if(!file.open(QFile::ReadOnly)) {
                        return -1;
                    }
                    const qint64 fileSize = file.size();
                    for(qint64 offset=0; offset<fileSize; offset+=chunkSize) {
                        const QByteArray data = file.read(chunkSize);
                        for(int indexByte=0; indexByte<data.length(); indexByte++) {
                            const char byte = data.at(indexByte);
                            if(!isprint(byte) && !_charactersTreatedAsPrintable.contains(byte)) {
                                nonPrintableCharacters++;
                            }
                        }
                    }
                    return nonPrintableCharacters;
                }

            }
        }
    }
}
