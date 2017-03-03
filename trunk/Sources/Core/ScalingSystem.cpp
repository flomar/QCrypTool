// ScalingSystem.cpp

#include <Core/ScalingSystem.h>

namespace QCT {
    namespace Core {

        ScalingSystem::ScalingSystem(QObject *_parent) :
            QObject(_parent),
            m_scalingMinimum(0.5),
            m_scalingMaximum(2.5),
            m_scaling(1.0) {

        }

        ScalingSystem::~ScalingSystem() {

        }

        ScalingSystem &ScalingSystem::instance() {
            static ScalingSystem helpSystem;
            return helpSystem;
        }

        void ScalingSystem::initializeFonts() {
            QFontDatabase::addApplicationFont(":/QCT/Fonts/Arial.ttf");
            QFontDatabase::addApplicationFont(":/QCT/Fonts/Courier.ttf");
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
                updateFonts();
                emit signalChangedScaling();
            }
        }

        const QFont &ScalingSystem::getFont(const FontType _fontType) const {
            return *mapFonts.value(_fontType);
        }

        void ScalingSystem::updateFonts() {
            mapFonts.clear();
            const int pixelSizeXS = 8;
            const int pixelSizeS = 10;
            const int pixelSizeM = 12;
            const int pixelSizeL = 16;
            const int pixelSizeXL = 20;
            SharedPointerFont fontNormalXS = SharedPointerFont(new QFont("Arial"));
            SharedPointerFont fontNormalS = SharedPointerFont(new QFont("Arial"));
            SharedPointerFont fontNormalM = SharedPointerFont(new QFont("Arial"));
            SharedPointerFont fontNormalL = SharedPointerFont(new QFont("Arial"));
            SharedPointerFont fontNormalXL = SharedPointerFont(new QFont("Arial"));
            SharedPointerFont fontMonospaceXS = SharedPointerFont(new QFont("Courier"));
            SharedPointerFont fontMonospaceS = SharedPointerFont(new QFont("Courier"));
            SharedPointerFont fontMonospaceM = SharedPointerFont(new QFont("Courier"));
            SharedPointerFont fontMonospaceL = SharedPointerFont(new QFont("Courier"));
            SharedPointerFont fontMonospaceXL = SharedPointerFont(new QFont("Courier"));
            fontNormalXS->setPixelSize(pixelSizeXS * m_scaling);
            fontNormalS->setPixelSize(pixelSizeS * m_scaling);
            fontNormalM->setPixelSize(pixelSizeM * m_scaling);
            fontNormalL->setPixelSize(pixelSizeL * m_scaling);
            fontNormalXL->setPixelSize(pixelSizeXL * m_scaling);
            fontMonospaceXS->setPixelSize(pixelSizeXS * m_scaling);
            fontMonospaceS->setPixelSize(pixelSizeS * m_scaling);
            fontMonospaceM->setPixelSize(pixelSizeM * m_scaling);
            fontMonospaceL->setPixelSize(pixelSizeL * m_scaling);
            fontMonospaceXL->setPixelSize(pixelSizeXL * m_scaling);
            mapFonts.insert(FONT_TYPE_NORMAL_XS, fontNormalXS);
            mapFonts.insert(FONT_TYPE_NORMAL_S, fontNormalS);
            mapFonts.insert(FONT_TYPE_NORMAL_M, fontNormalM);
            mapFonts.insert(FONT_TYPE_NORMAL_L, fontNormalL);
            mapFonts.insert(FONT_TYPE_NORMAL_XL, fontNormalXL);
            mapFonts.insert(FONT_TYPE_MONOSPACE_XS, fontMonospaceXS);
            mapFonts.insert(FONT_TYPE_MONOSPACE_S, fontMonospaceS);
            mapFonts.insert(FONT_TYPE_MONOSPACE_M, fontMonospaceM);
            mapFonts.insert(FONT_TYPE_MONOSPACE_L, fontMonospaceL);
            mapFonts.insert(FONT_TYPE_MONOSPACE_XL, fontMonospaceXL);
        }

    }
}
