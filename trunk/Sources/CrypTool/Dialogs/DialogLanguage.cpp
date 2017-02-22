// DialogLanguage.cpp

#include <CrypTool/Dialogs/DialogLanguage.h>
#include <ui_DialogLanguage.h>

namespace QCrypTool {
    namespace CrypTool {
        namespace Dialogs {

            DialogLanguage::DialogLanguage(QWidget *_parent, Qt::WindowFlags _flags) :
                Core::Dialog(_parent, _flags),
                m_ui(new Ui::DialogLanguage) {
                m_ui->setupUi(this);
            }

            DialogLanguage::~DialogLanguage() {
                delete m_ui;
            }

            void DialogLanguage::initializeSignalsAndSlots() {

            }

            void DialogLanguage::initializeData() {

            }

        }
    }
}
