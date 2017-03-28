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
            m_editorWidget(new EditorWidget(this)),
            m_editorBackEnd(new EditorBackEnd(this)),
            m_mode(MODE_NULL),
            m_fontType(ScalingSystem::FONT_TYPE_NULL) {
            connect(&m_scalingSystem, SIGNAL(signalChangedScaling()), this, SLOT(slotChangedScaling()));
            setMode(MODE_TEXT);
            setFontType(ScalingSystem::FONT_TYPE_NORMAL_M);
        }

        Editor::~Editor() {
            disconnect(&m_scalingSystem, SIGNAL(signalChangedScaling()), this, SLOT(slotChangedScaling()));
        }

        void Editor::setMode(const Mode _mode) {
            switch(_mode) {
            case MODE_TEXT:
                m_mode = _mode;
                m_editorWidget->setMode(m_mode);
                break;
            case MODE_HEX:
                m_mode = _mode;
                m_editorWidget->setMode(m_mode);
                break;
            default:
                break;
            }
        }

        void Editor::setFontType(const ScalingSystem::FontType _fontType) {
            switch(_fontType) {
            case ScalingSystem::FONT_TYPE_NORMAL_XS:
            case ScalingSystem::FONT_TYPE_NORMAL_S:
            case ScalingSystem::FONT_TYPE_NORMAL_M:
            case ScalingSystem::FONT_TYPE_NORMAL_L:
            case ScalingSystem::FONT_TYPE_NORMAL_XL:
                if(m_mode == MODE_TEXT) {
                    m_fontType = _fontType;
                    m_editorWidget->setFont(m_scalingSystem.getFont(m_fontType));
                    break;
                }
                break;
            case ScalingSystem::FONT_TYPE_MONOSPACE_XS:
            case ScalingSystem::FONT_TYPE_MONOSPACE_S:
            case ScalingSystem::FONT_TYPE_MONOSPACE_M:
            case ScalingSystem::FONT_TYPE_MONOSPACE_L:
            case ScalingSystem::FONT_TYPE_MONOSPACE_XL:
                if(m_mode == MODE_TEXT || m_mode == MODE_HEX) {
                    m_fontType = _fontType;
                    m_editorWidget->setFont(m_scalingSystem.getFont(m_fontType));
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
            m_editorWidget->setFont(m_scalingSystem.getFont(m_fontType));
            update();
        }

        EditorWidget::EditorWidget(QWidget *_parent) :
            QWidget(_parent),
            m_mode(Editor::MODE_NULL),
            m_widgetText(0),
            m_widgetHex(0) {

        }

        EditorWidget::~EditorWidget() {

        }

        void EditorWidget::setMode(const Editor::Mode _mode) {
            m_mode = _mode;
            update();
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
