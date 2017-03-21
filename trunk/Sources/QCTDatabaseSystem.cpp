// QCTDatabaseSystem.cpp

#include <QCTDatabaseSystem.h>

#include <QCTDatabaseSystem.h>
#include <QCTOptionsSystem.h>
#include <QCTTranslationSystem.h>
#include <QCTScalingSystem.h>
#include <QCTHelpSystem.h>

namespace QCT {

    Database::Database(const QString _pathDatabase, QObject *_parent) :
        QObject(_parent) {
        m_database = QSqlDatabase::addDatabase("QSQLITE", _pathDatabase);
        m_database.setDatabaseName(_pathDatabase);
    }

    Database::~Database() {

    }

    bool Database::checkTable(const QString &_table) {
        if(!m_database.open()) {
            Core::Utilities::MessageBoxes::execMessageBoxCritical(trStr(I18N_QCRYPTOOL_MESSAGEDATABASESYSTEM_DATABASEFILECOULDNOTBEOPENED).arg(m_database.databaseName()));
            return false;
        }
        if(_table == "sqlite_master") {
            return true;
        }
        const QSqlIndex index = m_database.primaryIndex(_table);
        for(qint64 i=0; i<index.count(); i++) {
            if(index.fieldName(i) == "Identifier") {
                return true;
            }
        }
        Core::Utilities::MessageBoxes::execMessageBoxCritical(trStr(I18N_QCRYPTOOL_MESSAGEDATABASESYSTEM_DATABASETABLEFORMATINVALID).arg(_table).arg(m_database.databaseName()));
        return false;
    }

    bool Database::checkQuery(const QSqlQuery &_query) {
        if(!m_database.open()) {
            Core::Utilities::MessageBoxes::execMessageBoxCritical(trStr(I18N_QCRYPTOOL_MESSAGEDATABASESYSTEM_DATABASEFILECOULDNOTBEOPENED).arg(m_database.databaseName()));
            return false;
        }
        if(!_query.isActive()) {
            Core::Utilities::MessageBoxes::execMessageBoxCritical(trStr(I18N_QCRYPTOOL_MESSAGEDATABASESYSTEM_DATABASEQUERYFAILED).arg(m_database.databaseName()).arg(_query.lastError().text()));
            return false;
        }
        return true;
    }

    QSet<qint64> Database::getIdentifiers(const QString &_table) {
        QSet<qint64> identifiers;
        if(!checkTable(_table)) {
            return identifiers;
        }
        QSqlQuery query(m_database);
        const QString queryString = QString("SELECT Identifier FROM %1").arg(_table);
        query.exec(queryString);
        if(!checkQuery(query)) {
            return identifiers;
        }
        while(query.next()) {
            for(int index=0; index<query.record().count(); index++) {
                identifiers.insert(query.record().value("Identifier").toInt());
            }
        }
        return identifiers;
    }

    qint64 Database::getSmallestAvailableIdentifier(const QString &_table) {
        qint64 identifier = 0;
        const QSet<qint64> identifiers = getIdentifiers(_table);
        for(qint64 potentialIdentifier=1; potentialIdentifier<std::numeric_limits<qint64>::max(); potentialIdentifier++) {
            if(!identifiers.contains(potentialIdentifier)) {
                return potentialIdentifier;
            }
        }
        return identifier;
    }

    QVariantMap Database::getRecord(const QString &_table, const QString &_what, const QString &_where) {
        QVariantMap record;
        if(!checkTable(_table)) {
            return record;
        }
        QSqlQuery query(m_database);
        const QString queryString = QString("SELECT %1 FROM %2 WHERE %3").arg(_what).arg(_table).arg(_where);
        query.exec(queryString);
        if(!checkQuery(query)) {
            return record;
        }
        if(query.next()) {
            for(int index=0; index<query.record().count(); index++) {
                record.insert(query.record().fieldName(index), query.record().value(index));
            }
        }
        return record;
    }

    QVector<QVariantMap> Database::getRecords(const QString &_table, const QList<QString> &_listFields) {
        QVector<QVariantMap> records;
        if(!checkTable(_table)) {
            return records;
        }
        QSqlQuery query(m_database);
        QString queryString;
        if(_listFields.isEmpty()) {
            queryString = QString("SELECT * FROM %1").arg(_table);
        }
        else {
            queryString = QString("SELECT %1 FROM %2").arg(Core::Utilities::Conversion::convertListToString<QString>(_listFields).arg(_table));
        }
        query.exec(queryString);
        if(!checkQuery(query)) {
            return records;
        }
        while(query.next()) {
            QVariantMap record;
            for(int index=0; index<query.record().count(); index++) {
                record.insert(query.record().fieldName(index), query.record().value(index));
            }
            records.append(record);
        }
        return records;
    }

    QVector<QVariantMap> Database::getRecords(const QString &_table, const QString &_what, const QString &_where) {
        QVector<QVariantMap> records;
        if(!checkTable(_table)) {
            return records;
        }
        QSqlQuery query(m_database);
        const QString queryString = QString("SELECT %1 FROM %2 WHERE %3").arg(_what).arg(_table).arg(_where);
        query.exec(queryString);
        if(!checkQuery(query)) {
            return records;
        }
        while(query.next()) {
            QVariantMap record;
            for(int index=0; index<query.record().count(); index++) {
                record.insert(query.record().fieldName(index), query.record().value(index));
            }
            records.append(record);
        }
        return records;
    }

    qint64 Database::insertRecord(const QString &_table, const QVariantMap &_record) {
        if(!checkTable(_table)) {
            return 0;
        }
        const QSet<qint64> identifiers = getIdentifiers(_table);
        const qint64 identifier = _record.contains("Identifier") ? _record.value("Identifier").toInt() : getSmallestAvailableIdentifier(_table);
        QSqlQuery query(m_database);
        QString queryString;
        if(!identifiers.contains(identifier)) {
            queryString = QString("INSERT INTO %1 (Identifier, %2) VALUES (%3, %4)").arg(_table).arg(Core::Utilities::Conversion::convertListToString<QString>(_record.keys())).arg(identifier).arg(Core::Utilities::Conversion::convertListToString<QVariant>(_record.values()));
        }
        else {
            queryString = QString("UPDATE %1 SET %2 WHERE Identifier='%3'").arg(_table).arg(Core::Utilities::Conversion::convertVariantMapToString(_record)).arg(_record.value("Identifier").toInt());
        }
        query.exec(queryString);
        if(!checkQuery(query)) {
            return 0;
        }
        return identifier;
    }

    qint64 Database::updateRecord(const QString &_table, const QVariantMap &_record) {
        if(!checkTable(_table)) {
            return 0;
        }
        const qint64 identifier = _record.contains("Identifier") ? _record.value("Identifier").toInt() : 0;
        QSqlQuery query(m_database);
        const QString queryString = QString("UPDATE %1 SET %2 WHERE Identifier='%3'").arg(_table).arg(Core::Utilities::Conversion::convertVariantMapToString(_record)).arg(identifier);
        query.exec(queryString);
        if(!checkQuery(query)) {
            return 0;
        }
        return identifier;
    }

    qint64 Database::removeRecord(const QString &_table, const QVariantMap &_record) {
        const qint64 identifier = _record.contains("Identifier") ? _record.value("Identifier").toInt() : 0;
        QSqlQuery query(m_database);
        const QString queryString = QString("DELETE FROM %1 WHERE Identifier='%2'").arg(_table).arg(identifier);
        query.exec(queryString);
        if(!checkQuery(query)) {
            return 0;
        }
        return identifier;
    }

    bool Database::removeRecords(const QString &_table, const QString &_where) {
        QSqlQuery query(m_database);
        const QString queryString = QString("DELETE FROM %1 WHERE %2").arg(_table).arg(_where);
        query.exec(queryString);
        if(!checkQuery(query)) {
            return false;
        }
        return true;
    }

    DatabaseSystem::DatabaseSystem(QObject *_parent) :
        QObject(_parent),
        m_database(QSharedPointer<Database>(new Database(QString("%1/%2").arg(QDir::homePath()).arg("QCrypToolDatabase.sqlite")))),
        m_databaseBackup(QSharedPointer<Database>(new Database(QString("%1/%2").arg(QDir::homePath()).arg("QCrypToolDatabase.sqlite.backup")))) {

    }

    DatabaseSystem::~DatabaseSystem() {

    }

    DatabaseSystem &DatabaseSystem::instance() {
        static DatabaseSystem databaseSystem;
        return databaseSystem;
    }

    bool DatabaseSystem::initialize() {
        QFileInfo fileInfoDatabase(m_database->getDatabaseName());
        if(!fileInfoDatabase.exists()) {
            return false;
        }
        QFileInfo fileInfoDatabaseBackup(m_databaseBackup->getDatabaseName());
        if(!fileInfoDatabaseBackup.exists()) {
            return true;
        }
        // ATTENTION: At this point we should insert a merging/migration
        // function to convert data from the backup database to the current
        // database. (TODO/FIXME)
        return true;
    }

}
