// UtilitiesInteraction.cpp

#include <Core/Utilities.h>

namespace QCT {
    namespace Core {
        namespace Utilities {
            namespace Interaction {

                QString getSelectedFileName() {
                    QFileDialog fileDialog;
                    fileDialog.setFileMode(QFileDialog::ExistingFile);
                    if(fileDialog.exec() == QDialog::Accepted) {
                        QList<QString> listSelectedFiles = fileDialog.selectedFiles();
                        if(!listSelectedFiles.isEmpty()) {
                            return listSelectedFiles.first();
                        }
                    }
                    return QString::null;
                }

            }
        }
    }
}
