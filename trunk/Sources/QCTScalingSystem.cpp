// QCTScalingSystem.cpp

#include <QCTScalingSystem.h>

#include <QCTDatabaseSystem.h>
#include <QCTOptionsSystem.h>
#include <QCTTranslationSystem.h>
#include <QCTScalingSystem.h>
#include <QCTHelpSystem.h>

namespace QCT {

    ScalingSystem::ScalingSystem(QObject *_parent) :
        QObject(_parent),
        m_scalingStep(10),
        m_scalingMinimum(50),
        m_scalingMaximum(1000),
        m_scaling(100),
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
        static ScalingSystem scalingSystem;
        return scalingSystem;
    }

    bool ScalingSystem::initialize() {
        initializeFonts();
        setScaling(OptionsSystem::instance().getOptionsScaling(100));
        return true;
    }

    void ScalingSystem::setScaling(const qint32 _scaling, const bool _override) {
        const qint32 scalingOld = m_scaling;
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
            OptionsSystem::instance().setOptionsScaling(m_scaling);
            emit signalChangedScaling();
            emit signalChangedScaling(m_scaling);
        }
    }

    void ScalingSystem::initializeFonts() {
        QFontDatabase::addApplicationFont(":/QCT/Fonts/Arial.ttf");
        QFontDatabase::addApplicationFont(":/QCT/Fonts/Courier.ttf");
    }

    void ScalingSystem::slotRequestScalingIncrease() {
        setScaling(m_scaling + m_scalingStep);
    }

    void ScalingSystem::slotRequestScalingDecrease() {
        setScaling(m_scaling - m_scalingStep);
    }

    QFont ScalingSystem::getFont(const FontType _fontType) const {
        QFont font;
        font.setFamily(getFontFamily(_fontType));
        font.setPixelSize(getFontPixelSize(_fontType));
        return font;
    }

    QString ScalingSystem::getFontFamily(const FontType _fontType) const {
        QString fontFamily = QString::null;
        switch(_fontType) {
        case FONT_TYPE_NORMAL_XS:
        case FONT_TYPE_NORMAL_S:
        case FONT_TYPE_NORMAL_M:
        case FONT_TYPE_NORMAL_L:
        case FONT_TYPE_NORMAL_XL:
            fontFamily = m_fontFamilyNormal;
            break;
        case FONT_TYPE_MONOSPACE_XS:
        case FONT_TYPE_MONOSPACE_S:
        case FONT_TYPE_MONOSPACE_M:
        case FONT_TYPE_MONOSPACE_L:
        case FONT_TYPE_MONOSPACE_XL:
            fontFamily = m_fontFamilyMonospace;
            break;
        default:
            break;
        }
        return fontFamily;
    }

    int ScalingSystem::getFontPixelSize(const FontType _fontType) const {
        int fontPixelSize = 0;
        switch(_fontType) {
        case FONT_TYPE_NORMAL_XS:
        case FONT_TYPE_MONOSPACE_XS:
            fontPixelSize = m_fontPixelSizeXS * m_scaling / 100;
            break;
        case FONT_TYPE_NORMAL_S:
        case FONT_TYPE_MONOSPACE_S:
            fontPixelSize = m_fontPixelSizeS * m_scaling / 100;
            break;
        case FONT_TYPE_NORMAL_M:
        case FONT_TYPE_MONOSPACE_M:
            fontPixelSize = m_fontPixelSizeM * m_scaling / 100;
            break;
        case FONT_TYPE_NORMAL_L:
        case FONT_TYPE_MONOSPACE_L:
            fontPixelSize = m_fontPixelSizeL * m_scaling / 100;
            break;
        case FONT_TYPE_NORMAL_XL:
        case FONT_TYPE_MONOSPACE_XL:
            fontPixelSize = m_fontPixelSizeXL * m_scaling / 100;
            break;
        default:
            break;
        }
        return fontPixelSize;
    }

}
