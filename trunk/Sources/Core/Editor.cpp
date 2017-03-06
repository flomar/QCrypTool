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
            m_editorScrollBar(new EditorScrollBar(this)),
            m_editorBackEnd(new EditorBackEnd(this)),
            m_mode(MODE_NULL),
            m_fontType(ScalingSystem::FONT_TYPE_NULL) {
            connect(&m_scalingSystem, SIGNAL(signalChangedScaling()), this, SLOT(slotChangedScaling()));
            setMode(MODE_TEXT);
            setFontType(ScalingSystem::FONT_TYPE_NORMAL_M);
            m_editorWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            QHBoxLayout *horizontalBoxLayout = new QHBoxLayout();
            horizontalBoxLayout->setMargin(0);
            horizontalBoxLayout->setSpacing(0);
            horizontalBoxLayout->addWidget(m_editorWidget);
            horizontalBoxLayout->addWidget(m_editorScrollBar);
            setLayout(horizontalBoxLayout);
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
            return QSize(400, 300) * m_scalingSystem.getScaling();
        }

        void Editor::slotChangedScaling() {
            m_editorWidget->setFont(m_scalingSystem.getFont(m_fontType));
            update();
        }

        EditorBackEnd::EditorBackEnd(QObject *_parent) :
            QObject(_parent),
            m_blockSize(0x1000),
            m_fileSizeMaximum(std::numeric_limits<qint64>::max() / 2) {

        }

        EditorBackEnd::~EditorBackEnd() {

        }

        EditorWidget::EditorWidget(QWidget *_parent) :
            QWidget(_parent),
            m_mode(Editor::MODE_NULL) {

        }

        EditorWidget::~EditorWidget() {

        }

        void EditorWidget::setMode(const Editor::Mode _mode) {
            m_mode = _mode;
            update();
        }

        void EditorWidget::paintEvent(QPaintEvent *_event) {
            Q_UNUSED(_event);
            QPainter painter(this);
            QTextOption textOption;
            textOption.setWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);
            const QFontMetricsF fontMetrics(font());
            const qreal fontWidth = fontMetrics.width("X");
            const qreal fontHeight = fontMetrics.height();
            painter.setPen(QColor(0, 0, 0, 255));
            painter.setBrush(QColor(255, 255, 255, 255));
            painter.drawRect(rect());
            // TODO/FIXME
            if(m_mode == Editor::MODE_TEXT) {
                QString text;
                text.append("TEXT\n");
                for(int i=0; i<10; i++)
                    text.append("This read-only text is just for testing. ");
                painter.drawText(rect(), text, textOption);

            }
            if(m_mode == Editor::MODE_HEX) {
                QString text;
                text.append("HEX\n");
                painter.drawText(rect(), text, textOption);
            }
        }

        EditorScrollBar::EditorScrollBar(QWidget *_parent) :
            QScrollBar(Qt::Vertical, _parent) {

        }

        EditorScrollBar::~EditorScrollBar() {

        }

    }
}
