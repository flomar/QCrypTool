// UtilitiesDateAndTime.h

#ifndef _QCRYPTOOL_CORE_UTILITIES_UTILITIESDATEANDTIME_H_
#define _QCRYPTOOL_CORE_UTILITIES_UTILITIESDATEANDTIME_H_

#include <QCrypTool.h>

namespace QCrypTool {
    namespace Core {
        namespace Utilities {
            namespace DateAndTime {

                // returns the current date and time since the Unix epoch
                // (1970-01-01 00:00:00.000) in milliseconds
                qint64 getCurrentDateAndTime();

                // converts the specified date and time to a human-readable
                // string in the format "yyyy-MM-dd hh:mm:ss.zzz"
                QString convertDateAndTimeToString(const qint64 _dateAndTime);

                // converts the specified human-readable string in the format
                // "yyyy-MM-dd hh:mm:ss.zzz" to the number of milliseconds
                // since the Unix epoch (1970-01-01 00:00:00.000); if the
                // human-readable string cannot be interpreted, the function
                // returns -1
                qint64 convertStringToDateAndTime(const QString &_dateAndTime);

            }
        }
    }
}

#endif
