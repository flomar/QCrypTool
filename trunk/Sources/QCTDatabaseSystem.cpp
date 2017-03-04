// QCTDatabaseSystem.cpp

#include <QCTDatabaseSystem.h>

#include <QCTDatabaseSystem.h>
#include <QCTHelpSystem.h>
#include <QCTScalingSystem.h>
#include <QCTTranslationSystem.h>

namespace QCT {

    DatabaseSystem::DatabaseSystem(QObject *_parent) :
        QObject(_parent),
        m_pathDatabases(QString("%1/%2").arg(QDir::homePath()).arg(".QCrypToolDatabases")),
        m_pathDatabaseQCrypToolSettings(QString("%1/%2/%3").arg(QDir::homePath()).arg(".QCrypToolDatabases").arg("QCrypToolSettings.sqlite")),
        m_pathDatabaseQCrypToolCertificateStore(QString("%1/%2/%3").arg(QDir::homePath()).arg(".QCrypToolDatabases").arg("QCrypToolCertificateStore.sqlite")) {

    }

    DatabaseSystem::~DatabaseSystem() {
        if(m_databaseQCrypToolSettings.isOpen()) {
            m_databaseQCrypToolSettings.close();
        }
        if(m_databaseQCrypToolCertificateStore.isOpen()) {
            m_databaseQCrypToolCertificateStore.close();
        }
    }

    DatabaseSystem &DatabaseSystem::instance() {
        static DatabaseSystem helpSystem;
        return helpSystem;
    }

    void DatabaseSystem::initializeDatabases() {
        if(!QDir().mkpath(m_pathDatabases)) {
            Core::Utilities::MessageBoxes::execMessageBoxCritical(trStr(I18N_QCRYPTOOL_MESSAGEDATABASESYSTEM_DATABASEPATHCOULDNOTBECREATED).arg(m_pathDatabases));
            return;
        }
        m_databaseQCrypToolSettings = QSqlDatabase::addDatabase("QSQLITE");
        m_databaseQCrypToolSettings.setDatabaseName(m_pathDatabaseQCrypToolSettings);
        if(!m_databaseQCrypToolSettings.open()) {
            Core::Utilities::MessageBoxes::execMessageBoxWarning(trStr(I18N_QCRYPTOOL_MESSAGEDATABASESYSTEM_DATABASEFILECOULDNOTBEOPENED).arg(m_databaseQCrypToolSettings.databaseName()));
        }
        m_databaseQCrypToolCertificateStore = QSqlDatabase::addDatabase("QSQLITE");
        m_databaseQCrypToolCertificateStore.setDatabaseName(m_pathDatabaseQCrypToolCertificateStore);
        if(!m_databaseQCrypToolCertificateStore.open()) {
            Core::Utilities::MessageBoxes::execMessageBoxWarning(trStr(I18N_QCRYPTOOL_MESSAGEDATABASESYSTEM_DATABASEFILECOULDNOTBEOPENED).arg(m_databaseQCrypToolCertificateStore.databaseName()));
        }
    }

}
