// QCTDatabaseSystem.cpp

#include <QCTDatabaseSystem.h>

#include <QCTDatabaseSystem.h>
#include <QCTHelpSystem.h>
#include <QCTScalingSystem.h>
#include <QCTTranslationSystem.h>

namespace QCT {

    DatabaseSystem::DatabaseSystem(QObject *_parent) :
        QObject(_parent) {

    }

    DatabaseSystem::~DatabaseSystem() {

    }

    DatabaseSystem &DatabaseSystem::instance() {
        static DatabaseSystem helpSystem;
        return helpSystem;
    }

}
