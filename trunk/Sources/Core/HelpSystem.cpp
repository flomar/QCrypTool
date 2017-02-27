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
            QMessageBox messageBox(QMessageBox::Information, QString("Information"), QString("TODO/FIXME: show context help\nTODO/FIXME: %1").arg(_identifierContextHelp));
            messageBox.exec();
        }

    }
}
