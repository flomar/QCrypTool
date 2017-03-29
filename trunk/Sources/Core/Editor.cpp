// Editor.cpp

#include <Core/Editor.h>

namespace QCT {
    namespace Core {

        Editor::Editor(const QString &_fileName, QWidget *_parent) :
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
            m_editorDocument(new EditorDocument(_fileName, this)) {
            connect(&m_scalingSystem, SIGNAL(signalChangedScaling()), this, SLOT(slotChangedScaling()));
            connect(m_editorDocument, SIGNAL(signalChangedData(QByteArray)), m_editorWidgetText, SLOT(slotChangedData(QByteArray)));
            connect(m_editorDocument, SIGNAL(signalChangedData(QByteArray)), m_editorWidgetHex, SLOT(slotChangedData(QByteArray)));
            QVBoxLayout *verticalBoxLayout = new QVBoxLayout();
            verticalBoxLayout->setMargin(0);
            verticalBoxLayout->setSpacing(0);
            verticalBoxLayout->addWidget(m_editorWidgetText);
            verticalBoxLayout->addWidget(m_editorWidgetHex);
            setLayout(verticalBoxLayout);
            if(!m_editorDocument->open()) {
                Utilities::MessageBoxes::execMessageBoxCritical("TODO/FIXME: Editor -> could not open document");
            }
            else {
                setMode(m_editorDocument->containsTextOnly() ? MODE_TEXT : MODE_HEX);
                setWindowTitle(m_editorDocument->getTitle());
            }
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

        void EditorWidgetText::slotChangedData(const QByteArray &_data) {
            setText(_data);
        }

        EditorWidgetHex::EditorWidgetHex(QWidget *_parent) :
            QAbstractScrollArea(_parent),
            m_charactersAddress(8),
            m_charactersOuterSpacing(2),
            m_charactersInnerSpacing(1),
            m_fontMetricsWidth(0.0f),
            m_fontMetricsHeight(0.0f),
            m_bytesPerRow(0),
            m_data(QByteArray()) {
            setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        }

        EditorWidgetHex::~EditorWidgetHex() {

        }

        void EditorWidgetHex::paintEvent(QPaintEvent *_event) {
            QAbstractScrollArea::paintEvent(_event);
            QPainter painter(viewport());
            updateFontMetrics();
            updateBytesPerRow();
            for(int indexRow=0; indexRow<(m_data.length() + m_bytesPerRow - 1) / m_bytesPerRow; indexRow++) {
                const QByteArray dataRow = m_data.mid(indexRow * m_bytesPerRow, m_bytesPerRow);
                const QString stringAddress = Utilities::String::fillLeft(QString::number(indexRow * m_bytesPerRow, 16).toUpper(), '0', m_charactersAddress);
                const QString stringHex = Utilities::String::fillRight(Utilities::String::toHex(dataRow, " "), ' ', (m_bytesPerRow - 1) * m_charactersInnerSpacing + m_bytesPerRow * 2);
                const QString stringText = Utilities::String::toText(dataRow, " ");
                painter.drawText(QPointF(0.0f, (indexRow + 1) * m_fontMetricsHeight), QString("%1 %2 %3").arg(stringAddress).arg(stringHex).arg(stringText));
            }
        }

        void EditorWidgetHex::slotChangedData(const QByteArray &_data) {
            m_data = _data;
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

        EditorDocument::EditorDocument(const QString &_fileName, QObject *_parent) :
            QObject(_parent),
            m_fileSizeMaximum(std::numeric_limits<qint32>::max() / 2),
            m_fileName(_fileName),
            m_title(_fileName),
            m_data(QByteArray()) {

        }

        EditorDocument::~EditorDocument() {

        }

        bool EditorDocument::open() {
            if(m_fileName.isEmpty()) {
                m_fileName = Utilities::File::createTempFile();
            }
            m_title = m_fileName;
            QFile file(m_fileName);
            if(file.open(QFile::ReadOnly)) {
                m_data = file.read(m_fileSizeMaximum);
                emit signalChangedData(m_data);
                return true;
            }
            return false;
        }

        bool EditorDocument::containsTextOnly() {
            for(int indexByte=0; indexByte<m_data.length(); indexByte++) {
                const char byte = m_data.at(indexByte);
                if(!isprint(byte) && byte != '\n') {
                    return false;
                }
            }
            return true;
        }

    }
}
