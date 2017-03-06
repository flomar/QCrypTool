// QCTDatabaseSystem.h

#ifndef _QCT_DATABASESYSTEM_H_
#define _QCT_DATABASESYSTEM_H_

#include <QCT.h>

#include <Core/Utilities.h>

namespace QCT {

    // This singleton class provides an interface to the underlying
    // QCrypTool SQLITE database. It offers a range of static functions
    // with generic functionality. NOTE: For this class to work properly,
    // all tables in the database must feature an "Identifier" field as
    // primary key. Furthermore, these methods mainly work on QVariantMap.
    // This is very slow data structure, but it's very easy to use.
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
        static bool checkTable(const QString &_table);
        static bool checkQuery(const QSqlQuery &_query);
        static QSet<qint64> getIdentifiers(const QString &_table);
        static qint64 getSmallestAvailableIdentifier(const QString &_table);
        static QVariantMap getRecord(const QString &_table, const QString &_what, const QString &_where);
        static QVector<QVariantMap> getRecords(const QString &_table, const QList<QString> &_listFields = QList<QString>());
        static QVector<QVariantMap> getRecords(const QString &_table, const QString &_what, const QString &_where);
        static qint64 insertRecord(const QString &_table, const QVariantMap &_record);
        static qint64 updateRecord(const QString &_table, const QVariantMap &_record);
        static qint64 removeRecord(const QString &_table, const QVariantMap &_record);
        static bool removeRecords(const QString &_table, const QString &_where);
    private:
        const QString m_pathDatabase;
        QSqlDatabase m_database;
    };

}

#endif
