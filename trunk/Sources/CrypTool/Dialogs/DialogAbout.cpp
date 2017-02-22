// DialogAbout.cpp

#include <CrypTool/Dialogs/DialogAbout.h>
#include <ui_DialogAbout.h>

namespace QCrypTool {
    namespace CrypTool {
        namespace Dialogs {

            DialogAbout::DialogAbout(QWidget *_parent, Qt::WindowFlags _flags) :
                Core::Dialog(_parent, _flags),
                m_ui(new Ui::DialogAbout) {
                m_ui->setupUi(this);
            }

            DialogAbout::~DialogAbout() {
                delete m_ui;
            }

            void DialogAbout::initializeSignalsAndSlots() {

            }

            void DialogAbout::initializeData() {

            }

        }
    }
}
