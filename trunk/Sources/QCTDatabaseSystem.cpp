// QCTDatabaseSystem.cpp

#include <QCTDatabaseSystem.h>

#include <QCTDatabaseSystem.h>
#include <QCTOptionsSystem.h>
#include <QCTTranslationSystem.h>
#include <QCTScalingSystem.h>
#include <QCTHelpSystem.h>

namespace QCT {

    DatabaseSystem::DatabaseSystem(QObject *_parent) :
        QObject(_parent),
        m_pathDatabase(QString("%1/%2").arg(QDir::homePath()).arg(".QCrypToolDatabase.sqlite")) {

    }

    DatabaseSystem::~DatabaseSystem() {
        if(m_database.isOpen()) {
            m_database.close();
        }
    }

    DatabaseSystem &DatabaseSystem::instance() {
        static DatabaseSystem databaseSystem;
        return databaseSystem;
    }

    void DatabaseSystem::initialize() {
        m_database = QSqlDatabase::addDatabase("QSQLITE");
        m_database.setDatabaseName(m_pathDatabase);
        if(!m_database.open()) {
            Core::Utilities::MessageBoxes::execMessageBoxCritical(trStr(I18N_QCRYPTOOL_MESSAGEDATABASESYSTEM_DATABASEFILECOULDNOTBEOPENED).arg(m_database.databaseName()));
            return;
        }
    }

    bool DatabaseSystem::checkTable(const QString &_table) {
        QSqlDatabase database = QSqlDatabase::database();
        if(!database.open()) {
            Core::Utilities::MessageBoxes::execMessageBoxCritical(trStr(I18N_QCRYPTOOL_MESSAGEDATABASESYSTEM_DATABASEFILECOULDNOTBEOPENED).arg(database.databaseName()));
            return false;
        }
        const QSqlIndex index = QSqlDatabase::database().primaryIndex(_table);
        for(qint64 i=0; i<index.count(); i++) {
            if(index.fieldName(i) == "Identifier") {
                return true;
            }
        }
        Core::Utilities::MessageBoxes::execMessageBoxCritical(trStr(I18N_QCRYPTOOL_MESSAGEDATABASESYSTEM_DATABASETABLEFORMATINVALID).arg(_table));
        return false;
    }

    bool DatabaseSystem::checkQuery(const QSqlQuery &_query) {
        QSqlDatabase database = QSqlDatabase::database();
        if(!database.open()) {
            Core::Utilities::MessageBoxes::execMessageBoxCritical(trStr(I18N_QCRYPTOOL_MESSAGEDATABASESYSTEM_DATABASEFILECOULDNOTBEOPENED).arg(database.databaseName()));
            return false;
        }
        if(!_query.isActive()) {
            Core::Utilities::MessageBoxes::execMessageBoxCritical(trStr(I18N_QCRYPTOOL_MESSAGEDATABASESYSTEM_DATABASEQUERYFAILED).arg(_query.lastError().text()));
            return false;
        }
        return true;
    }

    QSet<qint64> DatabaseSystem::getIdentifiers(const QString &_table) {
        QSet<qint64> identifiers;
        if(!checkTable(_table)) {
            return identifiers;
        }
        QSqlQuery query(QSqlDatabase::database());
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

    qint64 DatabaseSystem::getSmallestAvailableIdentifier(const QString &_table) {
        qint64 identifier = 0;
        const QSet<qint64> identifiers = getIdentifiers(_table);
        for(int potentialIdentifier=1; potentialIdentifier<std::numeric_limits<qint64>::max(); potentialIdentifier++) {
            if(!identifiers.contains(potentialIdentifier)) {
                return potentialIdentifier;
            }
        }
        return identifier;
    }

    QVariantMap DatabaseSystem::getRecord(const QString &_table, const QString &_what, const QString &_where) {
        QVariantMap record;
        if(!checkTable(_table)) {
            return record;
        }
        QSqlQuery query(QSqlDatabase::database());
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

    QVector<QVariantMap> DatabaseSystem::getRecords(const QString &_table, const QList<QString> &_listFields) {
        QVector<QVariantMap> records;
        if(!checkTable(_table)) {
            return records;
        }
        QSqlQuery query(QSqlDatabase::database());
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

    QVector<QVariantMap> DatabaseSystem::getRecords(const QString &_table, const QString &_what, const QString &_where) {
        QVector<QVariantMap> records;
        if(!checkTable(_table)) {
            return records;
        }
        QSqlQuery query(QSqlDatabase::database());
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

    qint64 DatabaseSystem::insertRecord(const QString &_table, const QVariantMap &_record) {
        if(!checkTable(_table)) {
            return 0;
        }
        const QSet<qint64> identifiers = getIdentifiers(_table);
        const qint64 identifier = _record.contains("Identifier") ? _record.value("Identifier").toInt() : getSmallestAvailableIdentifier(_table);
        QSqlQuery query(QSqlDatabase::database());
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

    qint64 DatabaseSystem::updateRecord(const QString &_table, const QVariantMap &_record) {
        if(!checkTable(_table)) {
            return 0;
        }
        const qint64 identifier = _record.contains("Identifier") ? _record.value("Identifier").toInt() : 0;
        QSqlQuery query(QSqlDatabase::database());
        const QString queryString = QString("UPDATE %1 SET %2 WHERE Identifier='%3'").arg(_table).arg(Core::Utilities::Conversion::convertVariantMapToString(_record)).arg(identifier);
        query.exec(queryString);
        if(!checkQuery(query)) {
            return 0;
        }
        return identifier;
    }

    qint64 DatabaseSystem::removeRecord(const QString &_table, const QVariantMap &_record) {
        const qint64 identifier = _record.contains("Identifier") ? _record.value("Identifier").toInt() : 0;
        QSqlQuery query(QSqlDatabase::database());
        const QString queryString = QString("DELETE FROM %1 WHERE Identifier='%2'").arg(_table).arg(identifier);
        query.exec(queryString);
        if(!checkQuery(query)) {
            return 0;
        }
        return identifier;
    }

    bool DatabaseSystem::removeRecords(const QString &_table, const QString &_where) {
        QSqlQuery query(QSqlDatabase::database());
        const QString queryString = QString("DELETE FROM %1 WHERE %2").arg(_table).arg(_where);
        query.exec(queryString);
        if(!checkQuery(query)) {
            return false;
        }
        return true;
    }

}
