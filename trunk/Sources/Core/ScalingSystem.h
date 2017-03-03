// ScalingSystem.h

#ifndef _QCT_CORE_SCALINGSYSTEM_H_
#define _QCT_CORE_SCALINGSYSTEM_H_

#include <QCT.h>
#include <QCTTranslation.h>

#include <Core/Utilities.h>

namespace QCT {
    namespace Core {

        // This singleton class is responsible for the application-wide
        // GUI scaling and for providing the corresponding fonts.
        class ScalingSystem : public QObject {
            Q_OBJECT
        protected:
            ScalingSystem(QObject *_parent = 0);
            virtual ~ScalingSystem();
        public:
            static ScalingSystem &instance();
        public:
            void initializeFonts();
        public:
            void setScaling(const float _scaling, const bool _override = false);
        public:
            float getScalingMinimum() const { return m_scalingMinimum; }
            float getScalingMaximum() const { return m_scalingMaximum; }
            float getScaling() const { return m_scaling; }
        signals:
            void signalChangedScaling();
        private:
            const float m_scalingMinimum;
            const float m_scalingMaximum;
            float m_scaling;
        public:
            enum FontType {
                FONT_TYPE_NULL,
                FONT_TYPE_NORMAL_XS,
                FONT_TYPE_NORMAL_S,
                FONT_TYPE_NORMAL_M,
                FONT_TYPE_NORMAL_L,
                FONT_TYPE_NORMAL_XL,
                FONT_TYPE_MONOSPACE_XS,
                FONT_TYPE_MONOSPACE_S,
                FONT_TYPE_MONOSPACE_M,
                FONT_TYPE_MONOSPACE_L,
                FONT_TYPE_MONOSPACE_XL
            };
        public:
            const QFont &getFont(const FontType _fontType = FONT_TYPE_NORMAL_M) const;
        private:
            void updateFonts();
        private:
            typedef QSharedPointer<QFont> SharedPointerFont;
            QMap<FontType, SharedPointerFont> mapFonts;
        };

    }
}

#endif
