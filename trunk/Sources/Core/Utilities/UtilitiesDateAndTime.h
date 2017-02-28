// UtilitiesDateAndTime.h

#ifndef _QCT_CORE_UTILITIES_UTILITIESDATEANDTIME_H_
#define _QCT_CORE_UTILITIES_UTILITIESDATEANDTIME_H_

#include <QCT.h>

namespace QCT {
    namespace Core {
        namespace Utilities {
            namespace DateAndTime {

                // Returns the current date and time since the Unix epoch
                // (1970-01-01 00:00:00.000) in milliseconds.
                qint64 getCurrentDateAndTime();

                // Converts the specified date and time to a human-readable
                // string in the format "yyyy-MM-dd hh:mm:ss.zzz".
                QString convertDateAndTimeToString(const qint64 _dateAndTime);

                // Converts the specified human-readable string in the format
                // "yyyy-MM-dd hh:mm:ss.zzz" to the number of milliseconds
                // since the Unix epoch (1970-01-01 00:00:00.000). If the
                // human-readable string cannot be interpreted, the function
                // returns -1.
                qint64 convertStringToDateAndTime(const QString &_dateAndTime);

            }
        }
    }
}

#endif
