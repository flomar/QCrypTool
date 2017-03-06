// QCTOptionsSystem.cpp

#include <QCTOptionsSystem.h>

#include <QCTDatabaseSystem.h>
#include <QCTOptionsSystem.h>
#include <QCTTranslationSystem.h>
#include <QCTScalingSystem.h>
#include <QCTHelpSystem.h>

namespace QCT {

    OptionsSystem::OptionsSystem(QObject *_parent) :
        QObject(_parent) {

    }

    OptionsSystem::~OptionsSystem() {

    }

    OptionsSystem &OptionsSystem::instance() {
        static OptionsSystem optionsSystem;
        return optionsSystem;
    }

    void OptionsSystem::initialize() {

    }

    QString OptionsSystem::getOptionsLanguage(const QString &_default) const {
        const QVariantMap options = getOptions();
        if(options.isEmpty()) {
            return _default;
        }
        return options.value("Language").toString();
    }

    int OptionsSystem::getOptionsScaling(const int _default) const {
        const QVariantMap options = getOptions();
        if(options.isEmpty()) {
            return _default;
        }
        return options.value("Scaling").toInt();
    }

    void OptionsSystem::setOptionsLanguage(const QString &_language) const {
        QVariantMap options = getOptions();
        options.insert("Language", _language);
        setOptions(options);
    }

    void OptionsSystem::setOptionsScaling(const int _scaling) const {
        QVariantMap options = getOptions();
        options.insert("Scaling", _scaling);
        setOptions(options);
    }

    QVariantMap OptionsSystem::getOptions() const {
        const QVector<QVariantMap> vectorOptions = DatabaseSystem::instance().getRecords("Options");
        if(vectorOptions.isEmpty()) {
            return QVariantMap();
        }
        return vectorOptions.first();
    }

    void OptionsSystem::setOptions(const QVariantMap &_options) const {
        DatabaseSystem::instance().updateRecord("Options", _options);
    }

}
