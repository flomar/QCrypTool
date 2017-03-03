// ScalingSystem.h

#ifndef _QCT_CORE_SCALINGSYSTEM_H_
#define _QCT_CORE_SCALINGSYSTEM_H_

#include <QCT.h>
#include <QCTTranslation.h>

#include <Core/Utilities.h>

namespace QCT {
    namespace Core {

        // This singleton class is responsible for the application-wide
        // GUI scale and for providing the corresponding fonts.
        class ScalingSystem : public QObject {
            Q_OBJECT
        protected:
            ScalingSystem(QObject *_parent = 0);
            virtual ~ScalingSystem();
        public:
            static ScalingSystem &instance();
        public:
            void setScale(const float _scale, const bool _override = false);
        public:
            float getScaleMinimum() const { return m_scaleMinimum; }
            float getScaleMaximum() const { return m_scaleMaximum; }
            float getScale() const { return m_scale; }
        signals:
            void signalChangedScale();
        public:
            const QFont &getFontNormalXS() const { return fontNormalXS; }
            const QFont &getFontNormalS() const { return fontNormalS; }
            const QFont &getFontNormalM() const { return fontNormalM; }
            const QFont &getFontNormalL() const { return fontNormalL; }
            const QFont &getFontNormalXL() const { return fontNormalXL; }
            const QFont &getFontMonospaceXS() const { return fontMonospaceXS; }
            const QFont &getFontMonospaceS() const { return fontMonospaceS; }
            const QFont &getFontMonospaceM() const { return fontMonospaceM; }
            const QFont &getFontMonospaceL() const { return fontMonospaceL; }
            const QFont &getFontMonospaceXL() const { return fontMonospaceXL; }
        private:
            const float m_scaleMinimum;
            const float m_scaleMaximum;
            float m_scale;
        private:
            QFont fontNormalXS;
            QFont fontNormalS;
            QFont fontNormalM;
            QFont fontNormalL;
            QFont fontNormalXL;
            QFont fontMonospaceXS;
            QFont fontMonospaceS;
            QFont fontMonospaceM;
            QFont fontMonospaceL;
            QFont fontMonospaceXL;
        };

    }
}

#endif
