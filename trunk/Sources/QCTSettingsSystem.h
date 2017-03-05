// QCTSettingsSystem.h

#ifndef _QCT_SETTINGSSYSTEM_H_
#define _QCT_SETTINGSSYSTEM_H_

#include <QCT.h>

#include <Core/Utilities.h>

namespace QCT {

    // This singleton class provides an interface to the QCrypTool settings
    // which are stored in the application SQLITE database.
    class SettingsSystem : public QObject {
        Q_OBJECT
    protected:
        SettingsSystem(QObject *_parent = 0);
        virtual ~SettingsSystem();
    public:
        static SettingsSystem &instance();
    public:
        void initialize();
    public:
        QString getSettingsGUILanguage(const QString &_default = QString::null) const;
        int getSettingsGUIScaling(const int _default = 100) const;
    public:
        void setSettingsGUILanguage(const QString &_language) const;
        void setSettingsGUIScaling(const int _scaling) const;
    private:
        QVariantMap getSettingsGUI() const;
        void setSettingsGUI(const QVariantMap &_settingsGUI) const;
    };

}

#endif
