// UtilitiesDateAndTime.cpp

#include <Core/Utilities.h>

namespace QCT {
    namespace Core {
        namespace Utilities {
            namespace DateAndTime {

                qint64 getCurrentDateAndTime() {
                    return QDateTime::currentMSecsSinceEpoch();
                }

                QString convertDateAndTimeToString(const qint64 _dateAndTime) {
                    QDateTime dateTime;
                    dateTime.setMSecsSinceEpoch(_dateAndTime);
                    return dateTime.toString("yyyy-MM-dd hh:mm:ss.zzz");
                }

                qint64 convertStringToDateAndTime(const QString &_dateAndTime) {
                    QRegExp regExp("^(\\d{4})\\-(\\d{2})\\-(\\d{2}) (\\d{2})\\:(\\d{2})\\:(\\d{2})\\.(\\d{3})$");
                    if(regExp.indexIn(_dateAndTime) != -1) {
                        const int yyyy = regExp.cap(1).toInt();
                        const int MM = regExp.cap(2).toInt();
                        const int dd = regExp.cap(3).toInt();
                        const int hh = regExp.cap(4).toInt();
                        const int mm = regExp.cap(5).toInt();
                        const int ss = regExp.cap(6).toInt();
                        const int zzz = regExp.cap(7).toInt();
                        QDateTime dateTime;
                        dateTime.setDate(QDate(yyyy, MM, dd));
                        dateTime.setTime(QTime(hh, mm, ss, zzz));
                        return dateTime.toMSecsSinceEpoch();
                    }
                    return -1;
                }

            }
        }
    }
}
