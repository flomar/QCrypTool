// Editor.cpp

#include <Core/Editor.h>

namespace QCT {
    namespace Core {

        Editor::Editor(QWidget *_parent) :
            QWidget(_parent),
            m_databaseSystem(DatabaseSystem::instance()),
            m_optionsSystem(OptionsSystem::instance()),
            m_translationSystem(TranslationSystem::instance()),
            m_scalingSystem(ScalingSystem::instance()),
            m_helpSystem(HelpSystem::instance()),
            m_mode(MODE_NULL),
            m_fontTypeText(ScalingSystem::FONT_TYPE_NULL),
            m_fontTypeHex(ScalingSystem::FONT_TYPE_NULL),
            m_editorWidgetText(new EditorWidgetText()),
            m_editorWidgetHex(new EditorWidgetHex()) {
            connect(&m_scalingSystem, SIGNAL(signalChangedScaling()), this, SLOT(slotChangedScaling()));
            QVBoxLayout *verticalBoxLayout = new QVBoxLayout();
            verticalBoxLayout->setMargin(0);
            verticalBoxLayout->setSpacing(0);
            verticalBoxLayout->addWidget(m_editorWidgetText);
            verticalBoxLayout->addWidget(m_editorWidgetHex);
            m_editorWidgetText->setVisible(false);
            m_editorWidgetHex->setVisible(false);
            m_editorWidgetText->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            m_editorWidgetHex->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            setLayout(verticalBoxLayout);
            setMode(MODE_TEXT);
            setFontType(ScalingSystem::FONT_TYPE_NORMAL_M);
        }

        Editor::~Editor() {
            disconnect(&m_scalingSystem, SIGNAL(signalChangedScaling()), this, SLOT(slotChangedScaling()));
        }

        void Editor::setMode(const Mode _mode) {
            m_mode = _mode;
            m_editorWidgetText->setVisible(m_mode == MODE_TEXT);
            m_editorWidgetHex->setVisible(m_mode == MODE_HEX);
        }

        void Editor::setFontType(const ScalingSystem::FontType _fontType) {
            switch(_fontType) {
            case ScalingSystem::FONT_TYPE_NORMAL_XS:
            case ScalingSystem::FONT_TYPE_NORMAL_S:
            case ScalingSystem::FONT_TYPE_NORMAL_M:
            case ScalingSystem::FONT_TYPE_NORMAL_L:
            case ScalingSystem::FONT_TYPE_NORMAL_XL:
                if(m_mode == MODE_TEXT) {
                    m_fontTypeText = _fontType;
                    m_editorWidgetText->setFont(m_scalingSystem.getFont(m_fontTypeText));
                    break;
                }
                break;
            case ScalingSystem::FONT_TYPE_MONOSPACE_XS:
            case ScalingSystem::FONT_TYPE_MONOSPACE_S:
            case ScalingSystem::FONT_TYPE_MONOSPACE_M:
            case ScalingSystem::FONT_TYPE_MONOSPACE_L:
            case ScalingSystem::FONT_TYPE_MONOSPACE_XL:
                if(m_mode == MODE_TEXT) {
                    m_fontTypeText = _fontType;
                    m_editorWidgetText->setFont(m_scalingSystem.getFont(m_fontTypeText));
                    break;
                }
                if(m_mode == MODE_HEX) {
                    m_fontTypeHex = _fontType;
                    m_editorWidgetHex->setFont(m_scalingSystem.getFont(m_fontTypeHex));
                    break;
                }
                break;
            default:
                break;
            }
        }

        QSize Editor::sizeHint() const {
            return QSize(400, 300) * m_scalingSystem.getScaling() / 100;
        }

        void Editor::slotChangedScaling() {
            m_editorWidgetText->setFont(m_scalingSystem.getFont(m_fontTypeText));
            m_editorWidgetHex->setFont(m_scalingSystem.getFont(m_fontTypeHex));
            update();
        }

        EditorWidgetText::EditorWidgetText(QWidget *_parent) :
            QTextEdit(_parent) {

        }

        EditorWidgetText::~EditorWidgetText() {

        }

        EditorWidgetHex::EditorWidgetHex(QWidget *_parent) :
            QWidget(_parent) {

        }

        EditorWidgetHex::~EditorWidgetHex() {

        }

        EditorBackEnd::EditorBackEnd(QObject *_parent) :
            QObject(_parent),
            m_blockSize(0x1000),
            m_fileSizeMaximum(std::numeric_limits<qint64>::max() / 2) {

        }

        EditorBackEnd::~EditorBackEnd() {

        }

    }
}
