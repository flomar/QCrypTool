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
            m_fontType(ScalingSystem::FONT_TYPE_NULL),
            m_editorWidgetText(new EditorWidgetText(this)),
            m_editorWidgetHex(new EditorWidgetHex(this)),
            m_editorBackEnd(0) {
            connect(&m_scalingSystem, SIGNAL(signalChangedScaling()), this, SLOT(slotChangedScaling()));
            QVBoxLayout *verticalBoxLayout = new QVBoxLayout();
            verticalBoxLayout->setMargin(0);
            verticalBoxLayout->setSpacing(0);
            verticalBoxLayout->addWidget(m_editorWidgetText);
            verticalBoxLayout->addWidget(m_editorWidgetHex);
            setLayout(verticalBoxLayout);
            setMode(MODE_TEXT);
        }

        Editor::~Editor() {
            disconnect(&m_scalingSystem, SIGNAL(signalChangedScaling()), this, SLOT(slotChangedScaling()));
        }

        void Editor::setMode(const Mode _mode) {
            m_mode = _mode;
            m_editorWidgetText->setVisible(m_mode == MODE_TEXT);
            m_editorWidgetHex->setVisible(m_mode == MODE_HEX);
            setFontType(m_mode == MODE_TEXT ? ScalingSystem::FONT_TYPE_NORMAL_M : ScalingSystem::FONT_TYPE_MONOSPACE_M);
        }

        void Editor::setFontType(const ScalingSystem::FontType _fontType) {
            m_fontType = _fontType;
            const QVector<ScalingSystem::FontType> vectorFontTypesNormal = QVector<ScalingSystem::FontType>() << ScalingSystem::FONT_TYPE_NORMAL_XS << ScalingSystem::FONT_TYPE_NORMAL_S << ScalingSystem::FONT_TYPE_NORMAL_M << ScalingSystem::FONT_TYPE_NORMAL_L << ScalingSystem::FONT_TYPE_NORMAL_XL;
            const QVector<ScalingSystem::FontType> vectorFontTypesMonospace = QVector<ScalingSystem::FontType>() << ScalingSystem::FONT_TYPE_MONOSPACE_XS << ScalingSystem::FONT_TYPE_MONOSPACE_S << ScalingSystem::FONT_TYPE_MONOSPACE_M << ScalingSystem::FONT_TYPE_MONOSPACE_L << ScalingSystem::FONT_TYPE_MONOSPACE_XL;
            if(m_mode == MODE_TEXT) {
                if(vectorFontTypesNormal.contains(_fontType) || vectorFontTypesMonospace.contains(_fontType)) {
                    m_editorWidgetText->setFont(ScalingSystem::instance().getFont(m_fontType));
                }
            }
            else if(m_mode == MODE_HEX) {
                if(vectorFontTypesMonospace.contains(_fontType)) {
                    m_editorWidgetHex->setFont(ScalingSystem::instance().getFont(m_fontType));
                }
            }
            update();
        }

        QSize Editor::sizeHint() const {
            return QSize(400, 300) * m_scalingSystem.getScaling() / 100;
        }

        void Editor::slotChangedScaling() {
            if(m_mode == MODE_TEXT) {
                m_editorWidgetText->setFont(m_scalingSystem.getFont(m_fontType));
            }
            else if(m_mode == MODE_HEX) {
                m_editorWidgetHex->setFont(m_scalingSystem.getFont(m_fontType));
            }
            update();
        }

        EditorWidgetText::EditorWidgetText(QWidget *_parent) :
            QTextEdit(_parent) {
            setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        }

        EditorWidgetText::~EditorWidgetText() {

        }

        void EditorWidgetText::paintEvent(QPaintEvent *_event) {
            QTextEdit::paintEvent(_event);
        }

        EditorWidgetHex::EditorWidgetHex(QWidget *_parent) :
            QAbstractScrollArea(_parent),
            m_charactersAddress(8),
            m_charactersOuterSpacing(2),
            m_charactersInnerSpacing(1),
            m_fontMetricsWidth(0.0f),
            m_fontMetricsHeight(0.0f),
            m_bytesPerRow(0) {
            setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        }

        EditorWidgetHex::~EditorWidgetHex() {

        }

        void EditorWidgetHex::paintEvent(QPaintEvent *_event) {
            QAbstractScrollArea::paintEvent(_event);
            QPainter painter(viewport());

            // update some internal values with each repaint
            updateFontMetrics();
            updateBytesPerRow();

            const QString data = "This text is displayed for testing purposes only, don't expect anything fancy!";

            for(int indexRow=0; indexRow<(data.length() + m_bytesPerRow - 1)/m_bytesPerRow; indexRow++) {
                const QByteArray dataRow = data.mid(indexRow * m_bytesPerRow, m_bytesPerRow).toLatin1();
                const QString stringAddress = Utilities::String::fillLeft(QString::number(indexRow * m_bytesPerRow, 16).toUpper(), '0', m_charactersAddress);
                const QString stringHex = Utilities::String::fillRight(Utilities::String::toHex(dataRow, " "), ' ', (m_bytesPerRow - 1) * m_charactersInnerSpacing + m_bytesPerRow * 2);
                const QString stringText = Utilities::String::toText(dataRow, " ");
                painter.drawText(QPointF(0.0f, (indexRow + 1) * m_fontMetricsHeight), QString("%1 %2 %3").arg(stringAddress).arg(stringHex).arg(stringText));
            }
        }

        void EditorWidgetHex::updateFontMetrics() {
            QFontMetricsF fontMetrics(font());
            m_fontMetricsWidth = fontMetrics.width(QChar('X'));
            m_fontMetricsHeight = fontMetrics.height();
        }

        void EditorWidgetHex::updateBytesPerRow() {
            const int bytesPerRowMinimum = 1;
            int bytesPerRow = bytesPerRowMinimum;
            while(true) {
                const int charactersPerRow = m_charactersAddress + m_charactersOuterSpacing * 2 + (bytesPerRow - 1) * m_charactersInnerSpacing + bytesPerRow * 3;
                const float rowWidth = charactersPerRow * m_fontMetricsWidth;
                if(rowWidth >= (float)viewport()->size().width()) break;
                else bytesPerRow++;
            }
            m_bytesPerRow = bytesPerRow;
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
