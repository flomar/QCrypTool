// QCTScalingSystem.h

#ifndef _QCT_SCALINGSYSTEM_H_
#define _QCT_SCALINGSYSTEM_H_

#include <QCT.h>

#include <Core/Utilities.h>

namespace QCT {

    // This singleton class is responsible for the application-wide
    // GUI scaling and for providing/manipulating fonts, buttons and
    // other GUI elements. It is used in all Dialog- and MainWindow-
    // derived classes.
    class ScalingSystem : public QObject {
        Q_OBJECT
    protected:
        ScalingSystem(QObject *_parent = 0);
        virtual ~ScalingSystem();
    public:
        static ScalingSystem &instance();
    public:
        bool initialize();
    public:
        void setScaling(const qint32 _scaling, const bool _override = false);
    public:
        qint32 getScalingStep() const { return m_scalingStep; }
        qint32 getScalingMinimum() const { return m_scalingMinimum; }
        qint32 getScalingMaximum() const { return m_scalingMaximum; }
        qint32 getScaling() const { return m_scaling; }
    signals:
        void signalChangedScaling();
        void signalChangedScaling(const qint32 _scaling);
    private:
        void initializeFonts();
    private:
        const qint32 m_scalingStep;
        const qint32 m_scalingMinimum;
        const qint32 m_scalingMaximum;
        qint32 m_scaling;
    private slots:
        void slotRequestScalingIncrease();
        void slotRequestScalingDecrease();
    private:
        const QString m_fontFamilyNormal;
        const QString m_fontFamilyMonospace;
        const int m_fontPixelSizeXS;
        const int m_fontPixelSizeS;
        const int m_fontPixelSizeM;
        const int m_fontPixelSizeL;
        const int m_fontPixelSizeXL;
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
        QFont getFont(const FontType _fontType) const;
        QFont getFontNormal(const FontType _fontType) const;
        QFont getFontMonospace(const FontType _fontType) const;
        QString getFontFamily(const FontType _fontType) const;
        int getFontPixelSize(const FontType _fontType) const;
        QVector<FontType> getVectorFontTypesNormal() const;
        QVector<FontType> getVectorFontTypesMonospace() const;
    public:
        template<class T>
        void setFont(T *_object, const FontType _fontType) {
            if(!_object) return;
            QFont font;
            switch(_fontType) {
            case FONT_TYPE_NORMAL_XS:
                font.setFamily(m_fontFamilyNormal);
                font.setPixelSize(m_fontPixelSizeXS * m_scaling / 100);
                break;
            case FONT_TYPE_NORMAL_S:
                font.setFamily(m_fontFamilyNormal);
                font.setPixelSize(m_fontPixelSizeS * m_scaling / 100);
                break;
            case FONT_TYPE_NORMAL_M:
                font.setFamily(m_fontFamilyNormal);
                font.setPixelSize(m_fontPixelSizeM * m_scaling / 100);
                break;
            case FONT_TYPE_NORMAL_L:
                font.setFamily(m_fontFamilyNormal);
                font.setPixelSize(m_fontPixelSizeL * m_scaling / 100);
                break;
            case FONT_TYPE_NORMAL_XL:
                font.setFamily(m_fontFamilyNormal);
                font.setPixelSize(m_fontPixelSizeXL * m_scaling / 100);
                break;
            case FONT_TYPE_MONOSPACE_XS:
                font.setFamily(m_fontFamilyMonospace);
                font.setPixelSize(m_fontPixelSizeXS * m_scaling / 100);
                break;
            case FONT_TYPE_MONOSPACE_S:
                font.setFamily(m_fontFamilyMonospace);
                font.setPixelSize(m_fontPixelSizeS * m_scaling / 100);
                break;
            case FONT_TYPE_MONOSPACE_M:
                font.setFamily(m_fontFamilyMonospace);
                font.setPixelSize(m_fontPixelSizeM * m_scaling / 100);
                break;
            case FONT_TYPE_MONOSPACE_L:
                font.setFamily(m_fontFamilyMonospace);
                font.setPixelSize(m_fontPixelSizeL * m_scaling / 100);
                break;
            case FONT_TYPE_MONOSPACE_XL:
                font.setFamily(m_fontFamilyMonospace);
                font.setPixelSize(m_fontPixelSizeXL * m_scaling / 100);
                break;
            default:
                break;
            }
            _object->setFont(font);
        }
        template<class T>
        void setBold(T *_object, const bool _bold) {
            if(!_object) return;
            QFont font = _object->font();
            font.setBold(_bold);
            _object->setFont(font);
        }
        template<class T>
        void setItalic(T *_object, const bool _italic) {
            if(!_object) return;
            QFont font = _object->font();
            font.setItalic(_italic);
            _object->setFont(font);
        }
        template<class T>
        void setUnderline(T *_object, const bool _underline) {
            if(!_object) return;
            QFont font = _object->font();
            font.setUnderline(_underline);
            _object->setFont(font);
        }
        template<class T>
        void setFixedWidth(T *_object) {
            if(!_object) return;
            const QSize baseSize = _object->baseSize();
            _object->setFixedWidth(baseSize.width() * m_scaling / 100);
        }
        template<class T>
        void setFixedHeight(T *_object) {
            if(!_object) return;
            const QSize baseSize = _object->baseSize();
            _object->setFixedHeight(baseSize.height() * m_scaling / 100);
        }
        template<class T>
        void setFixedSize(T *_object) {
            if(!_object) return;
            const QSize baseSize = _object->baseSize();
            _object->setFixedSize(baseSize * m_scaling / 100);
        }
    };

}

#endif
