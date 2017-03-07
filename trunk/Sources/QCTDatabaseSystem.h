// QCTDatabaseSystem.h

#ifndef _QCT_DATABASESYSTEM_H_
#define _QCT_DATABASESYSTEM_H_

#include <QCT.h>

#include <Core/Utilities.h>

namespace QCT {

    // This is the base class for all SQLITE databases. It offers functions
    // with generic functionality. NOTE: For this class to work properly, all
    // tables (except for "sqlite_master") must feature an "Identifier" field
    // as primary key. Furthermore, these methods mainly work on QVarianMap.
    // It's a very slow data structure, but it's very easy to use.
    class Database : public QObject {
        Q_OBJECT
    public:
        Database(const QString _pathDatabase, QObject *_parent = 0);
        virtual ~Database();
    public:
        QString getDatabaseName() const { return m_database.databaseName(); }
    public:
        bool checkTable(const QString &_table);
        bool checkQuery(const QSqlQuery &_query);
        QSet<qint64> getIdentifiers(const QString &_table);
        qint64 getSmallestAvailableIdentifier(const QString &_table);
        QVariantMap getRecord(const QString &_table, const QString &_what, const QString &_where);
        QVector<QVariantMap> getRecords(const QString &_table, const QList<QString> &_listFields = QList<QString>());
        QVector<QVariantMap> getRecords(const QString &_table, const QString &_what, const QString &_where);
        qint64 insertRecord(const QString &_table, const QVariantMap &_record);
        qint64 updateRecord(const QString &_table, const QVariantMap &_record);
        qint64 removeRecord(const QString &_table, const QVariantMap &_record);
        bool removeRecords(const QString &_table, const QString &_where);
    private:
        QSqlDatabase m_database;
    };

    // This singleton class is the QCrypTool database implementation.
    class DatabaseSystem : public QObject {
        Q_OBJECT
    protected:
        DatabaseSystem(QObject *_parent = 0);
        virtual ~DatabaseSystem();
    public:
        static DatabaseSystem &instance();
    public:
        bool initialize();
    public:
        QSharedPointer<Database> getDatabase() { return m_database; }
    private:
        void migrateDatabase(QSharedPointer<Database> _databaseSource, QSharedPointer<Database> _databaseTarget);
    private:
        QSharedPointer<Database> m_database;
        QSharedPointer<Database> m_databaseBackup;
    };

}

#endif
