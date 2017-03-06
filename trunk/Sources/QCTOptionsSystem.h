// QCTOptionsSystem.h

#ifndef _QCT_OPTIONSSYSTEM_H_
#define _QCT_OPTIONSSYSTEM_H_

#include <QCT.h>

#include <Core/Utilities.h>

namespace QCT {

    // This singleton class provides an interface to the QCrypTool options
    // which are stored in the application's SQLITE database.
    class OptionsSystem : public QObject {
        Q_OBJECT
    protected:
        OptionsSystem(QObject *_parent = 0);
        virtual ~OptionsSystem();
    public:
        static OptionsSystem &instance();
    public:
        void initialize();
    public:
        QString getOptionsLanguage(const QString &_default = QString::null) const;
        int getOptionsScaling(const int _default = 100) const;
    public:
        void setOptionsLanguage(const QString &_language) const;
        void setOptionsScaling(const int _scaling) const;
    private:
        QVariantMap getOptions() const;
        void setOptions(const QVariantMap &_options) const;
    };

}

#endif
