// QCTDatabaseSystem.h

#ifndef _QCT_DATABASESYSTEM_H_
#define _QCT_DATABASESYSTEM_H_

#include <QCT.h>

#include <Core/Utilities.h>

namespace QCT {

    // This singleton class provides an interface to the underlying
    // SQLITE databases for the QCrypTool settings and the QCrypTool
    // certificate store.
    class DatabaseSystem : public QObject {
        Q_OBJECT
    protected:
        DatabaseSystem(QObject *_parent = 0);
        virtual ~DatabaseSystem();
    public:
        static DatabaseSystem &instance();
    };

}

#endif
