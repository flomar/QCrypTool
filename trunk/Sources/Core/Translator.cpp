// Translator.cpp

#include <Core/Translator.h>

namespace QCrypTool {
    namespace Core {

        Translator::Translator(QObject *_parent) :
            QObject(_parent) {

        }

        Translator::~Translator() {

        }

        Translator &Translator::instance() {
            static Translator translator;
            return translator;
        }

        void Translator::setLanguages(const QVector<QString> &_vectorLanguages) {
            m_vectorLanguages = _vectorLanguages;
        }

        void Translator::setLanguage(const QString &_prefix, const QString &_language) {
            if(m_vectorLanguages.contains(_language)) {
                if(m_translator.load(QString("translations/%1%2.qm").arg(_prefix).arg(_language))) {
                    m_language = _language;
                }
            }
        }

        QString Translator::getString(const QString &_identifier) const {
            return m_translator.translate(_identifier.toLatin1(), _identifier.toLatin1());
        }

    }
}
