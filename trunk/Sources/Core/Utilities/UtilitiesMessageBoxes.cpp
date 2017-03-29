// UtilitiesMessageBoxes.cpp

#include <Core/Utilities.h>

namespace QCT {
    namespace Core {
        namespace Utilities {
            namespace MessageBoxes {

                int execMessageBoxInformation(const QString &_message) {
                    QMessageBox messageBox(QMessageBox::Information, getProjectName(), _message);
                    return messageBox.exec();
                }

                int execMessageBoxWarning(const QString &_message) {
                    QMessageBox messageBox(QMessageBox::Warning, getProjectName(), _message);
                    return messageBox.exec();
                }

                int execMessageBoxCritical(const QString &_message) {
                    QMessageBox messageBox(QMessageBox::Critical, getProjectName(), _message);
                    return messageBox.exec();
                }

            }
        }
    }
}
