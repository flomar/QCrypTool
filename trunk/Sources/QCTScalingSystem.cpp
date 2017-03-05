// QCTScalingSystem.cpp

#include <QCTScalingSystem.h>

#include <QCTDatabaseSystem.h>
#include <QCTHelpSystem.h>
#include <QCTScalingSystem.h>
#include <QCTTranslationSystem.h>

namespace QCT {

    ScalingSystem::ScalingSystem(QObject *_parent) :
        QObject(_parent),
        m_scalingMinimum(0.5),
        m_scalingMaximum(2.5),
        m_scaling(1.0),
        m_fontFamilyNormal("Arial"),
        m_fontFamilyMonospace("Courier"),
        m_fontPixelSizeXS(6),
        m_fontPixelSizeS(8),
        m_fontPixelSizeM(10),
        m_fontPixelSizeL(16),
        m_fontPixelSizeXL(24) {

    }

    ScalingSystem::~ScalingSystem() {

    }

    ScalingSystem &ScalingSystem::instance() {
        static ScalingSystem helpSystem;
        return helpSystem;
    }

    void ScalingSystem::initialize() {
        initializeFonts();
        const QVariantMap settingsGUI = DatabaseSystem::instance().getRecord("SettingsGUI", "*", "Identifier=1");
        const QVariant scaling = settingsGUI.value("Scaling");
        setScaling((float)((scaling.isNull() ? (float)(1.0) : (float)(scaling.toInt()) / 100)));
    }

    void ScalingSystem::setScaling(const float _scaling, const bool _override) {
        const float scalingOld = m_scaling;
        if(_scaling < m_scalingMinimum && !_override) {
            m_scaling = m_scalingMinimum;
        }
        else if(_scaling > m_scalingMaximum && !_override) {
            m_scaling = m_scalingMaximum;
        }
        else {
            m_scaling = _scaling;
        }
        if(m_scaling != scalingOld) {
            QVariantMap settingsGUI = DatabaseSystem::instance().getRecord("SettingsGUI", "*", "Identifier=1");
            settingsGUI.insert("Scaling", m_scaling * 100);
            DatabaseSystem::instance().updateRecord("SettingsGUI", settingsGUI);
            emit signalChangedScaling();
        }
    }

    void ScalingSystem::setScalingPercentage(const int _scalingPercentage, const bool _override) {
        const float scaling = (float)(_scalingPercentage) / 100.0;
        setScaling(scaling, _override);
    }

    void ScalingSystem::initializeFonts() {
        QFontDatabase::addApplicationFont(":/QCT/Fonts/Arial.ttf");
        QFontDatabase::addApplicationFont(":/QCT/Fonts/Courier.ttf");
    }

}
