// Translator.h

#ifndef _QCRYPTOOL_CORE_TRANSLATOR_H_
#define _QCRYPTOOL_CORE_TRANSLATOR_H_

#include <QCrypTool.h>

namespace QCrypTool {
    namespace Core {

        class Translator : public QObject {
            Q_OBJECT
        protected:
            Translator(QObject *_parent = 0);
            virtual ~Translator();
        public:
            static Translator &instance();
        public:
            void setLanguages(const QVector<QString> &_vectorLanguages);
            void setLanguage(const QString &_prefix, const QString &_language);
        public:
            const QVector<QString> &getLanguages() const { return m_vectorLanguages; }
            const QString &getLanguage() const { return m_language; }
        public:
            QString getString(const QString &_identifier) const;
        private:
            QTranslator m_translator;
            QVector<QString> m_vectorLanguages;
            QString m_language;
        };

    }
}

#endif
