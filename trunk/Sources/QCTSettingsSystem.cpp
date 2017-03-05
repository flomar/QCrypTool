// QCTSettingsSystem.cpp

#include <QCTSettingsSystem.h>

#include <QCTDatabaseSystem.h>
#include <QCTHelpSystem.h>
#include <QCTScalingSystem.h>
#include <QCTSettingsSystem.h>
#include <QCTTranslationSystem.h>

namespace QCT {

    SettingsSystem::SettingsSystem(QObject *_parent) :
        QObject(_parent) {

    }

    SettingsSystem::~SettingsSystem() {

    }

    SettingsSystem &SettingsSystem::instance() {
        static SettingsSystem settingsSystem;
        return settingsSystem;
    }

    void SettingsSystem::initialize() {

    }

    QString SettingsSystem::getSettingsGUILanguage(const QString &_default) const {
        const QVariantMap settingsGUI = getSettingsGUI();
        if(settingsGUI.isEmpty()) {
            return _default;
        }
        return settingsGUI.value("Language").toString();
    }

    int SettingsSystem::getSettingsGUIScaling(const int _default) const {
        const QVariantMap settingsGUI = getSettingsGUI();
        if(settingsGUI.isEmpty()) {
            return _default;
        }
        return settingsGUI.value("Scaling").toInt();
    }

    void SettingsSystem::setSettingsGUILanguage(const QString &_language) const {
        QVariantMap settingsGUI = getSettingsGUI();
        settingsGUI.insert("Language", _language);
        setSettingsGUI(settingsGUI);
    }

    void SettingsSystem::setSettingsGUIScaling(const int _scaling) const {
        QVariantMap settingsGUI = getSettingsGUI();
        settingsGUI.insert("Scaling", _scaling);
        setSettingsGUI(settingsGUI);
    }

    QVariantMap SettingsSystem::getSettingsGUI() const {
        const QVector<QVariantMap> vectorSettingsGUI = DatabaseSystem::instance().getRecords("SettingsGUI");
        if(vectorSettingsGUI.isEmpty()) {
            return QVariantMap();
        }
        return vectorSettingsGUI.first();
    }

    void SettingsSystem::setSettingsGUI(const QVariantMap &_settingsGUI) const {
        DatabaseSystem::instance().updateRecord("SettingsGUI", _settingsGUI);
    }

}
