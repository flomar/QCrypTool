// HelpSystem.h

#ifndef _QCT_CORE_HELPSYSTEM_H_
#define _QCT_CORE_HELPSYSTEM_H_

#include <QCT.h>

namespace QCT {
    namespace Core {

        // This singleton class implements the context-sensitive help system
        // of QCrypTool. All MainWindow- and Dialog-derived classes register
        // themselves with the help system and emit a signal whenever the F1
        // key is pressed. These signals are collected in this class.
        class HelpSystem : public QObject {
            Q_OBJECT
        protected:
            HelpSystem(QObject *_parent = 0);
            virtual ~HelpSystem();
        public:
            static HelpSystem &instance();
        private slots:
            void slotRequestContextHelp(const QString &_identifierContextHelp);
        };

    }
}

#endif
