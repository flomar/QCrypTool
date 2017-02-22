// HelpSystem.cpp

#include <Core/HelpSystem.h>

namespace QCrypTool {
    namespace Core {

        HelpSystem::HelpSystem(QObject *_parent) :
            QObject(_parent) {

        }

        HelpSystem::~HelpSystem() {

        }

        HelpSystem &HelpSystem::instance() {
            static HelpSystem helpSystem;
            return helpSystem;
        }

        void HelpSystem::slotRequestContextHelp(const QString &_identifierContextHelp) {
            qDebug() << QString("TODO/FIXME: HelpSystem::slotRequestContextHelp(%1)").arg(_identifierContextHelp);
        }

    }
}
