// Editor.cpp

#include <Core/Editor.h>

namespace QCT {
    namespace Core {

        EditorWidget::EditorWidget(const QString &_fileName, QWidget *_parent) :
            QWidget(_parent),
            m_mode(MODE_NULL),
            m_fontType(ScalingSystem::FONT_TYPE_NULL),
            m_backEnd(PointerEditorBackEnd(new EditorBackEnd(_fileName))),
            m_widgetContainer(0),
            m_widgetStatus(0),
            m_databaseSystem(DatabaseSystem::instance()),
            m_optionsSystem(OptionsSystem::instance()),
            m_translationSystem(TranslationSystem::instance()),
            m_scalingSystem(ScalingSystem::instance()),
            m_helpSystem(HelpSystem::instance()) {
            // Connect signals and slots, create and initialize the widget
            // layout, and let the back-end handle the input file. Also set
            // the window title and the widget mode, which in turn creates
            // the proper container widget.
            connect(&m_scalingSystem, SIGNAL(signalChangedScaling()), this, SLOT(slotChangedScaling()));
            QVBoxLayout *verticalBoxLayout = new QVBoxLayout();
            verticalBoxLayout->setMargin(0);
            verticalBoxLayout->setSpacing(0);
            setLayout(verticalBoxLayout);
            setWindowTitle(m_backEnd->getFileName());
            const qint64 nonPrintableCharacters = Utilities::File::calculateNonPrintableCharactersInFile(m_backEnd->getFileName());
            if(nonPrintableCharacters > 0) {
                setMode(MODE_HEX);
            }
            else if(nonPrintableCharacters == 0) {
                setMode(MODE_TEXT);
            }
            else {
                qDebug() << "TODO/FIXME: this should not happen";
            }
        }

        EditorWidget::~EditorWidget() {
            disconnect(&m_scalingSystem, SIGNAL(signalChangedScaling()), this, SLOT(slotChangedScaling()));
        }

        void EditorWidget::setMode(const Mode _mode) {
            // Update the document mode, delete the existing widgets,
            // then create the new widgets depending on the mode, and
            // set the font type.
            m_mode = _mode;
            if(m_widgetContainer) {
                layout()->removeWidget(m_widgetContainer);
                m_widgetContainer->deleteLater();
            }
            if(m_widgetStatus) {
                layout()->removeWidget(m_widgetStatus);
                m_widgetStatus->deleteLater();
            }
            if(m_mode == MODE_TEXT) {
                m_widgetContainer = new EditorWidgetContainerText(m_backEnd, this);
                m_widgetStatus = new EditorWidgetStatus(m_backEnd, this);
                setFontType(ScalingSystem::FONT_TYPE_NORMAL_M);
                layout()->addWidget(m_widgetContainer);
                layout()->addWidget(m_widgetStatus);
            }
            else if(m_mode == MODE_HEX) {
                m_widgetContainer = new EditorWidgetContainerHex(m_backEnd, this);
                m_widgetStatus = new EditorWidgetStatus(m_backEnd, this);
                setFontType(ScalingSystem::FONT_TYPE_MONOSPACE_M);
                layout()->addWidget(m_widgetContainer);
                layout()->addWidget(m_widgetStatus);
            }
            else {
                Utilities::MessageBoxes::execMessageBoxCritical("TODO/FIXME: EditorWidget -> mode is invalid");
            }
            if(m_widgetContainer) {
                setFocus(Qt::ActiveWindowFocusReason);
                m_widgetContainer->setFocus(Qt::ActiveWindowFocusReason);
            }
            emit signalChangedMode();
        }

        void EditorWidget::setFontType(const ScalingSystem::FontType _fontType) {
            const QVector<ScalingSystem::FontType> vectorFontTypesNormal = m_scalingSystem.getVectorFontTypesNormal();
            const QVector<ScalingSystem::FontType> vectorFontTypesMonospace = m_scalingSystem.getVectorFontTypesMonospace();
            if((m_mode == MODE_TEXT && (vectorFontTypesNormal.contains(_fontType) || vectorFontTypesMonospace.contains(_fontType))) || (m_mode == MODE_HEX && vectorFontTypesMonospace.contains(_fontType))) {
                m_fontType = _fontType;
                m_widgetContainer->setFont(ScalingSystem::instance().getFont(m_fontType));
                m_widgetStatus->setFont(ScalingSystem::instance().getFont(ScalingSystem::FONT_TYPE_NORMAL_S));
                update();
            }
            else {
                Utilities::MessageBoxes::execMessageBoxCritical("TODO/FIXME: EditorWidget -> font type is invalid");
            }
            emit signalChangedFontType();
        }

        void EditorWidget::cut() {
            if(m_widgetContainer) {
                m_widgetContainer->cut();
            }
        }

        void EditorWidget::copy() {
            if(m_widgetContainer) {
                m_widgetContainer->copy();
            }
        }

        void EditorWidget::paste() {
            if(m_widgetContainer) {
                m_widgetContainer->paste();
            }
        }

        QSize EditorWidget::sizeHint() const {
            return QSize(400, 300) * m_scalingSystem.getScaling() / 100;
        }

        void EditorWidget::slotChangedScaling() {
            if(m_widgetContainer) {
                m_widgetContainer->setFont(m_scalingSystem.getFont(m_fontType));
                m_widgetStatus->setFont(m_scalingSystem.getFont(ScalingSystem::FONT_TYPE_NORMAL_S));
                update();
            }
        }

        EditorWidgetContainer::EditorWidgetContainer(PointerEditorBackEnd _backEnd, QWidget *_parent) :
            QTextEdit(_parent),
            m_backEnd(_backEnd),
            m_colorCursorActive(QColor(255, 0, 0, 64)),
            m_colorCursorInactive(QColor(0, 0, 255, 64)) {
            setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            connect(m_backEnd.data(), SIGNAL(signalChangedData()), this, SLOT(slotChangedData()));
            connect(m_backEnd.data(), SIGNAL(signalChangedCursorPosition()), this, SLOT(slotChangedCursorPosition()));
            connect(m_backEnd.data(), SIGNAL(signalChangedCursorSelection()), this, SLOT(slotChangedCursorSelection()));
            connect(m_backEnd.data(), SIGNAL(signalChangedIndexCurrentChunk()), this, SLOT(slotChangedIndexCurrentChunk()));
            setReadOnly(true);
            installEventFilter(this);
        }

        EditorWidgetContainer::~EditorWidgetContainer() {
            disconnect(m_backEnd.data(), SIGNAL(signalChangedData()), this, SLOT(slotChangedData()));
            disconnect(m_backEnd.data(), SIGNAL(signalChangedCursorPosition()), this, SLOT(slotChangedCursorPosition()));
            disconnect(m_backEnd.data(), SIGNAL(signalChangedCursorSelection()), this, SLOT(slotChangedCursorSelection()));
            disconnect(m_backEnd.data(), SIGNAL(signalChangedIndexCurrentChunk()), this, SLOT(slotChangedIndexCurrentChunk()));
        }

        void EditorWidgetContainer::update() {
            QTextEdit::update();
            setText(getFormattedData(m_backEnd->getData()));
            updateCursorPosition();
        }

        bool EditorWidgetContainer::eventFilter(QObject *_object, QEvent *_event) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(_event);
            if(keyEvent) {
                if(keyEvent->type() == QEvent::KeyPress) {
                    if(keyEvent->key() == Qt::Key_Tab) {
                        keyEvent->accept();
                        return true;
                    }
                    else if(keyEvent->key() == Qt::Key_Left) {
                        moveCursorLeft(keyEvent->modifiers() & Qt::ShiftModifier);
                        keyEvent->accept();
                        return true;
                    }
                    else if(keyEvent->key() == Qt::Key_Right) {
                        moveCursorRight(keyEvent->modifiers() & Qt::ShiftModifier);
                        keyEvent->accept();
                        return true;
                    }
                    else if(keyEvent->key() == Qt::Key_Up) {
                        moveCursorUp(keyEvent->modifiers() & Qt::ShiftModifier);
                        keyEvent->accept();
                        return true;
                    }
                    else if(keyEvent->key() == Qt::Key_Down) {
                        moveCursorDown(keyEvent->modifiers() & Qt::ShiftModifier);
                        keyEvent->accept();
                        return true;
                    }
                    else if(keyEvent->key() == Qt::Key_PageUp) {
                        moveCursorPageUp(keyEvent->modifiers() & Qt::ShiftModifier);
                        keyEvent->accept();
                        return true;
                    }
                    else if(keyEvent->key() == Qt::Key_PageDown) {
                        moveCursorPageDown(keyEvent->modifiers() & Qt::ShiftModifier);
                        keyEvent->accept();
                        return true;
                    }
                    else if(keyEvent->key() == Qt::Key_Home) {
                        moveCursorToStartOfLine(keyEvent->key() & Qt::ShiftModifier);
                        keyEvent->accept();
                        return true;
                    }
                    else if(keyEvent->key() == Qt::Key_End) {
                        moveCursorToEndOfLine(keyEvent->key() & Qt::ShiftModifier);
                        keyEvent->accept();
                        return true;
                    }
                }
                if(keyEvent->type() == QEvent::KeyPress) {
                    if(processKeyPress(keyEvent->text(), getDataCursorPosition(textCursor().position()))) {
                        keyEvent->accept();
                        return true;
                    }
                }
                if(keyEvent->type() == QEvent::KeyRelease) {
                    if(processKeyRelease(keyEvent->text(), getDataCursorPosition(textCursor().position()))) {
                        keyEvent->accept();
                        return true;
                    }
                }

            }
            return QTextEdit::eventFilter(_object, _event);
        }

        void EditorWidgetContainer::paintEvent(QPaintEvent *_event) {
            applyCursorExtraSelections();
            QTextEdit::paintEvent(_event);
        }

        void EditorWidgetContainer::resizeEvent(QResizeEvent *_event) {
            QTextEdit::resizeEvent(_event);
            update();
        }

        void EditorWidgetContainer::updateCursorPosition() {
            QTextCursor cursor = textCursor();
            cursor.setPosition(getTextCursorPosition(m_backEnd->getCursorPosition()));
            setTextCursor(cursor);
            ensureCursorVisible();
        }

        void EditorWidgetContainer::slotChangedCursorPosition() {
            updateCursorPosition();
        }

        void EditorWidgetContainer::slotChangedCursorSelection() {
            repaint();
        }

        void EditorWidgetContainer::slotChangedData() {
            update();
        }

        void EditorWidgetContainer::slotChangedIndexCurrentChunk() {
            // Whenever the current chunk is changed, the ensuing call to
            // update will reset the cursor to the top of the view. We avoid
            // this by temporary storing the visual cursor line relative to
            // the bottom of the view and restoring it after the update call.
            const int line = getVisualCursorLine();
            update();
            setVisualCursorLine(line);
        }

        int EditorWidgetContainer::getVisualCursorLine() {
            QTextCursor cursor = textCursor();
            QTextCursor cursorBottom = cursorForPosition(QPoint(viewport()->width() - 1, viewport()->height() - 1));
            return (cursorRect(cursorBottom).y() - cursorRect(cursor).y()) / cursorRect(cursor).height();
        }

        void EditorWidgetContainer::setVisualCursorLine(const int _line) {
            QTextCursor cursor = textCursor();
            QTextCursor cursorBottom = textCursor();
            cursorBottom.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, _line);
            setTextCursor(cursorBottom);
            setTextCursor(cursor);
        }

        EditorWidgetContainerText::EditorWidgetContainerText(PointerEditorBackEnd _backEnd, QWidget *_parent) :
            EditorWidgetContainer(_backEnd, _parent) {
            setLineWrapMode(QTextEdit::WidgetWidth);
        }

        EditorWidgetContainerText::~EditorWidgetContainerText() {

        }

        bool EditorWidgetContainerText::eventFilter(QObject *_object, QEvent *_event) {
            return EditorWidgetContainer::eventFilter(_object, _event);
        }

        void EditorWidgetContainerText::paintEvent(QPaintEvent *_event) {
            EditorWidgetContainer::paintEvent(_event);
            QPainter painter(viewport());
            painter.drawRect(cursorRect());
        }

        void EditorWidgetContainerText::moveCursorLeft(const bool _selection) {
            QTextCursor cursor = textCursor();
            cursor.movePosition(QTextCursor::Left, QTextCursor::MoveAnchor, 1);
            m_backEnd->setCursorPosition(cursor.position(), _selection);
        }

        void EditorWidgetContainerText::moveCursorRight(const bool _selection) {
            QTextCursor cursor = textCursor();
            cursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, 1);
            m_backEnd->setCursorPosition(cursor.position(), _selection);
        }

        void EditorWidgetContainerText::moveCursorUp(const bool _selection) {
            QTextCursor cursor = textCursor();
            cursor.movePosition(QTextCursor::Up, QTextCursor::MoveAnchor, 1);
            m_backEnd->setCursorPosition(cursor.position(), _selection);
        }

        void EditorWidgetContainerText::moveCursorDown(const bool _selection) {
            QTextCursor cursor = textCursor();
            cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, 1);
            m_backEnd->setCursorPosition(cursor.position(), _selection);
        }

        void EditorWidgetContainerText::moveCursorPageUp(const bool _selection) {
            QTextCursor cursor = textCursor();
            const int lines = viewport()->height() / cursorRect(cursor).height();
            cursor.movePosition(QTextCursor::Up, QTextCursor::MoveAnchor, lines);
            m_backEnd->setCursorPosition(cursor.position(), _selection);
        }

        void EditorWidgetContainerText::moveCursorPageDown(const bool _selection) {
            QTextCursor cursor = textCursor();
            const int lines = viewport()->height() / cursorRect(cursor).height();
            cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, lines);
            m_backEnd->setCursorPosition(cursor.position(), _selection);
        }

        void EditorWidgetContainerText::moveCursorToStartOfLine(const bool _selection) {
            QTextCursor cursor = textCursor();
            cursor.movePosition(QTextCursor::StartOfLine, QTextCursor::MoveAnchor);
            m_backEnd->setCursorPosition(cursor.position(), _selection);
        }

        void EditorWidgetContainerText::moveCursorToEndOfLine(const bool _selection) {
            QTextCursor cursor = textCursor();
            cursor.movePosition(QTextCursor::EndOfLine, QTextCursor::MoveAnchor);
            m_backEnd->setCursorPosition(cursor.position(), _selection);
        }

        bool EditorWidgetContainerText::processKeyPress(const QString &_character, const int _position) {
            return m_backEnd->processKeyPress(_character, _position);
        }

        bool EditorWidgetContainerText::processKeyRelease(const QString &_character, const int _position) {
            return m_backEnd->processKeyRelease(_character, _position);
        }

        int EditorWidgetContainerText::getTextCursorPosition(const int _cursorPosition) {
            return _cursorPosition;
        }

        int EditorWidgetContainerText::getDataCursorPosition(const int _cursorPosition) {
            return _cursorPosition;
        }

        QByteArray EditorWidgetContainerText::getFormattedData(const QByteArray &_data) {
            return _data;
        }

        void EditorWidgetContainerText::applyCursorExtraSelections() {
            QList<ExtraSelection> listExtraSelections;
            if(m_backEnd->selection()) {
                const int selectionStart = qMin(qMax(0, m_backEnd->getCursorSelectionStart()), m_backEnd->getDataLength() - 1);
                const int selectionEnd = qMin(qMax(0, m_backEnd->getCursorSelectionEnd()), m_backEnd->getDataLength() - 1);
                if(selectionStart != -1 && selectionEnd != -1 && selectionStart != selectionEnd) {
                    QTextCursor cursorSelection = textCursor();
                    cursorSelection.setPosition(selectionStart, QTextCursor::MoveAnchor);
                    cursorSelection.setPosition(selectionEnd, QTextCursor::KeepAnchor);
                    ExtraSelection esSelection;
                    esSelection.format.setBackground(m_colorCursorActive);
                    esSelection.cursor = cursorSelection;
                    listExtraSelections.append(esSelection);
                }
            }
            setExtraSelections(listExtraSelections);
        }

        EditorWidgetContainerHex::EditorWidgetContainerHex(PointerEditorBackEnd _backEnd, QWidget *_parent) :
            EditorWidgetContainer(_backEnd, _parent),
            m_charactersAddress(sizeof(qint64) * 2),
            m_charactersOuterSpacing(2),
            m_charactersInnerSpacing(1),
            m_bytesPerRow(0),
            m_cursorHex(true),
            m_cursorHexFirstHalfByte(true) {
            setLineWrapMode(QTextEdit::NoWrap);
            installEventFilter(this);
        }

        EditorWidgetContainerHex::~EditorWidgetContainerHex() {

        }

        bool EditorWidgetContainerHex::eventFilter(QObject *_object, QEvent *_event) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(_event);
            if(keyEvent) {
                if(keyEvent->type() == QEvent::KeyPress) {
                    if(keyEvent->key() == Qt::Key_Tab) {
                        m_cursorHex = !m_cursorHex;
                        m_cursorHexFirstHalfByte = true;
                        updateCursorPosition();
                        keyEvent->accept();
                        return true;
                    }
                }
            }
            return EditorWidgetContainer::eventFilter(_object, _event);
        }

        void EditorWidgetContainerHex::paintEvent(QPaintEvent *_event) {
            EditorWidgetContainer::paintEvent(_event);
        }

        void EditorWidgetContainerHex::moveCursorLeft(const bool _selection) {
            int position = getDataCursorPosition(textCursor().position());
            if(m_cursorHex && m_cursorHexFirstHalfByte && position > 0) {
                m_cursorHexFirstHalfByte = !m_cursorHexFirstHalfByte;
                position -= 1;
            }
            else if(m_cursorHex && !m_cursorHexFirstHalfByte) {
                m_cursorHexFirstHalfByte = !m_cursorHexFirstHalfByte;
            }
            else {
                position -= 1;
            }
            m_backEnd->setCursorPosition(position, _selection);
            updateCursorPosition();
        }

        void EditorWidgetContainerHex::moveCursorRight(const bool _selection) {
            int position = getDataCursorPosition(textCursor().position());
            if(m_cursorHex && m_cursorHexFirstHalfByte) {
                m_cursorHexFirstHalfByte = !m_cursorHexFirstHalfByte;
            }
            else if(m_cursorHex && !m_cursorHexFirstHalfByte && position < m_backEnd->getDataLength() - 1) {
                m_cursorHexFirstHalfByte = !m_cursorHexFirstHalfByte;
                position += 1;
            }
            else {
                position += 1;
            }
            m_backEnd->setCursorPosition(position, _selection);
            updateCursorPosition();
        }

        void EditorWidgetContainerHex::moveCursorUp(const bool _selection) {
            QTextCursor cursor = textCursor();
            cursor.movePosition(QTextCursor::Up, QTextCursor::MoveAnchor, 1);
            m_backEnd->setCursorPosition(getDataCursorPosition(cursor.position()), _selection);
            updateCursorPosition();
        }

        void EditorWidgetContainerHex::moveCursorDown(const bool _selection) {
            QTextCursor cursor = textCursor();
            cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, 1);
            m_backEnd->setCursorPosition(getDataCursorPosition(cursor.position()), _selection);
            updateCursorPosition();
        }

        void EditorWidgetContainerHex::moveCursorPageUp(const bool _selection) {
            QTextCursor cursor = textCursor();
            const int lines = viewport()->height() / cursorRect(cursor).height();
            cursor.movePosition(QTextCursor::Up, QTextCursor::MoveAnchor, lines);
            m_backEnd->setCursorPosition(getDataCursorPosition(cursor.position()), _selection);
            updateCursorPosition();
        }

        void EditorWidgetContainerHex::moveCursorPageDown(const bool _selection) {
            QTextCursor cursor = textCursor();
            const int lines = viewport()->height() / cursorRect(cursor).height();
            cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, lines);
            m_backEnd->setCursorPosition(getDataCursorPosition(cursor.position()), _selection);
            updateCursorPosition();
        }

        void EditorWidgetContainerHex::moveCursorToStartOfLine(const bool _selection) {
            const int position = getDataCursorPosition(textCursor().position());
            const int column = position % m_bytesPerRow;
            const int newPosition = position - column;
            m_cursorHexFirstHalfByte = true;
            m_backEnd->setCursorPosition(newPosition, _selection);
            updateCursorPosition();
        }

        void EditorWidgetContainerHex::moveCursorToEndOfLine(const bool _selection) {
            const int position = getDataCursorPosition(textCursor().position());
            const int column = position % m_bytesPerRow;
            const int newPosition = position - column + m_bytesPerRow - 1;
            m_cursorHexFirstHalfByte = false;
            m_backEnd->setCursorPosition(newPosition, _selection);
            updateCursorPosition();
        }

        bool EditorWidgetContainerHex::processKeyPress(const QString &_character, const int _position) {
            const bool result = m_backEnd->processKeyPress(_character, _position, m_cursorHex, m_cursorHexFirstHalfByte);
            if(result) {
                if(m_cursorHex) {
                    m_cursorHexFirstHalfByte = !m_cursorHexFirstHalfByte;
                }
            }
            return result;
        }

        bool EditorWidgetContainerHex::processKeyRelease(const QString &_character, const int _position) {
            return m_backEnd->processKeyRelease(_character, _position, m_cursorHex, m_cursorHexFirstHalfByte);
        }

        int EditorWidgetContainerHex::getTextCursorPosition(const int _cursorPosition) {
            const int dataPosition = qMin(qMax(0, _cursorPosition), m_backEnd->getDataLength() - 1);
            const int dataRow = dataPosition / m_bytesPerRow;
            const int dataColumn = dataPosition % m_bytesPerRow;
            const int textRow = dataRow;
            const int textColumn = m_charactersAddress + m_charactersOuterSpacing + dataColumn * 3 + (m_cursorHexFirstHalfByte ? 0 : 1);
            const int textPosition = (m_charactersAddress + m_charactersOuterSpacing + m_bytesPerRow * 2 + (m_bytesPerRow - 1) * m_charactersInnerSpacing + m_charactersOuterSpacing + m_bytesPerRow + 1) * textRow + textColumn;
            return textPosition;
        }

        int EditorWidgetContainerHex::getDataCursorPosition(const int _cursorPosition) {
            const int textPosition = _cursorPosition;
            const int textRow = textPosition / (m_charactersAddress + m_charactersOuterSpacing + m_bytesPerRow * 2 + (m_bytesPerRow - 1) * m_charactersInnerSpacing + m_charactersOuterSpacing + m_bytesPerRow + 1);
            const int textColumn = textPosition % (m_charactersAddress + m_charactersOuterSpacing + m_bytesPerRow * 2 + (m_bytesPerRow - 1) * m_charactersInnerSpacing + m_charactersOuterSpacing + m_bytesPerRow + 1);
            const int dataRow = textRow;
            int dataColumn = textColumn;
            dataColumn -= m_charactersAddress;
            dataColumn -= m_charactersOuterSpacing;
            dataColumn /= 3;
            const int dataPosition = qMax(0, m_bytesPerRow * dataRow + dataColumn);
            return dataPosition;
        }

        QByteArray EditorWidgetContainerHex::getFormattedData(const QByteArray &_data) {
            updateBytesPerRow();
            const qint64 dataStart = m_backEnd->getDataStart();
            const int rows = qMax(1, (_data.length() + m_bytesPerRow - 1) / m_bytesPerRow);
            QByteArray displayedText;
            for(int row=0; row<rows; row++) {
                const QByteArray rowBytes = _data.mid(row * m_bytesPerRow, m_bytesPerRow);
                const QString stringAddress = Utilities::String::fillLeft(QString::number(dataStart + (qint64)(row * m_bytesPerRow), 16).toUpper(), '0', m_charactersAddress);
                const QString stringHex = Utilities::String::fillRight(Utilities::String::toHex(rowBytes, Utilities::String::fillLeft(QString(), ' ', m_charactersInnerSpacing)), ' ', m_bytesPerRow * 2 + (m_bytesPerRow - 1) * m_charactersInnerSpacing);
                const QString stringText = Utilities::String::fillRight(Utilities::String::toText(rowBytes, " "), ' ', m_bytesPerRow);
                displayedText += QString("%1%2%3%4%5\n").arg(stringAddress).arg(Utilities::String::fillLeft(QString(), ' ', m_charactersOuterSpacing)).arg(stringHex).arg(Utilities::String::fillLeft(QString(), ' ', m_charactersOuterSpacing)).arg(stringText);
            }
            return displayedText;
        }

        void EditorWidgetContainerHex::applyCursorExtraSelections() {
            QList<ExtraSelection> listExtraSelections;
            if(m_backEnd->selection()) {

                // TODO/FIXME: decide whether the hex edit should support
                // insertion/addition of data or only replacement; if we
                // only support replacement, we can go with the extra
                // selection code in the "else" branch (the old code)
                qDebug() << "TODO/FIXME: EditorWidgetContainerHex::applyCursorExtraSelections ---> CHECK OUT COMMENTS";

                // TODO/FIXME: the third condition (start != end) is NOT true
                // when only two half-bytes of the same byte are selected,
                // although this should be a valid selection

                // TODO/FIXME: in contrast to the text selection functionality,
                // in the hex editor we need to create extra selections on a
                // PER-ROW BASIS for both hex and text, therefore we need
                // to extend the logic quite a bit

#if 0
                const int selectionStart = qMin(qMax(0, m_backEnd->getCursorSelectionStart()), m_backEnd->getDataLength() - 1);
                const int selectionEnd = qMin(qMax(0, m_backEnd->getCursorSelectionEnd()), m_backEnd->getDataLength() - 1);
                if(selectionStart != -1 && selectionEnd != -1 && selectionStart != selectionEnd) {
                    QTextCursor cursorSelection = textCursor();
                    cursorSelection.setPosition(selectionStart, QTextCursor::MoveAnchor);
                    cursorSelection.setPosition(selectionEnd, QTextCursor::KeepAnchor);
                    ExtraSelection esSelection;
                    esSelection.format.setBackground(m_colorCursorActive);
                    esSelection.cursor = cursorSelection;
                    listExtraSelections.append(esSelection);
                }
#endif
            }
            else {
                const int dataPosition = getDataCursorPosition(textCursor().position());
                const int dataRow = dataPosition / m_bytesPerRow;
                const int dataColumn = dataPosition % m_bytesPerRow;
                const int textRow = dataRow;
                const int textColumn = m_charactersAddress + m_charactersOuterSpacing + m_bytesPerRow * 2 + (m_bytesPerRow - 1) * m_charactersInnerSpacing + m_charactersOuterSpacing + dataColumn;
                const int textPosition = (m_charactersAddress + m_charactersOuterSpacing + m_bytesPerRow * 2 + (m_bytesPerRow - 1) * m_charactersInnerSpacing + m_charactersOuterSpacing + m_bytesPerRow + 1) * textRow + textColumn;
                QTextCursor cursorHex = textCursor();
                cursorHex.setPosition(cursorHex.position() + 0);
                cursorHex.setPosition(cursorHex.position() + 1, QTextCursor::KeepAnchor);
                QTextCursor cursorText = textCursor();
                cursorText.setPosition(textPosition + 0);
                cursorText.setPosition(textPosition + 1, QTextCursor::KeepAnchor);
                ExtraSelection esHex;
                esHex.format.setBackground(m_cursorHex ? m_colorCursorActive : m_colorCursorInactive);
                esHex.cursor = cursorHex;
                ExtraSelection esText;
                esText.format.setBackground(m_cursorHex ? m_colorCursorInactive : m_colorCursorActive);
                esText.cursor = cursorText;
                listExtraSelections.append(esHex);
                listExtraSelections.append(esText);
            }
            setExtraSelections(listExtraSelections);
        }

        void EditorWidgetContainerHex::updateBytesPerRow() {
            QFontMetricsF fontMetrics(font());
            const int charactersPerRowMinimum = m_charactersAddress + m_charactersOuterSpacing + 2 + m_charactersOuterSpacing + 1;
            const int charactersPerRowMaximum = qMax(charactersPerRowMinimum, (int)(viewport()->width() / fontMetrics.width('X') - 2));
            int charactersPerRow = 0;
            m_bytesPerRow = 0;
            while(true) {
                charactersPerRow = m_charactersAddress + m_charactersOuterSpacing + m_bytesPerRow * 2 + (m_bytesPerRow - 1) * m_charactersInnerSpacing + m_charactersOuterSpacing + m_bytesPerRow;
                if(charactersPerRow >= charactersPerRowMaximum) break;
                else m_bytesPerRow++;
            }
        }

        EditorWidgetStatus::EditorWidgetStatus(PointerEditorBackEnd _backEnd, QWidget *_parent) :
            QWidget(_parent),
            m_backEnd(_backEnd),
            m_labelFileInformation(new QLabel(this)),
            m_labelChunkInformation(new QLabel(this)) {
            connect(m_backEnd.data(), SIGNAL(signalChangedData()), this, SLOT(slotChangedData()));
            connect(m_backEnd.data(), SIGNAL(signalChangedIndexCurrentChunk()), this, SLOT(slotChangedIndexCurrentChunk()));
            QHBoxLayout *horizontalBoxLayout = new QHBoxLayout();
            horizontalBoxLayout->setMargin(0);
            horizontalBoxLayout->setSpacing(0);
            setLayout(horizontalBoxLayout);
            m_labelFileInformation->setText(QString("%1 (%2 B)").arg(m_backEnd->getFileName()).arg(m_backEnd->getFileSize()));
            m_labelChunkInformation->setText(QString("Chunk %1/%2").arg(m_backEnd->getIndexCurrentChunk() + 1).arg(m_backEnd->getChunks()));
            layout()->addWidget(m_labelFileInformation);
            layout()->addWidget(m_labelChunkInformation);
        }

        EditorWidgetStatus::~EditorWidgetStatus() {
            disconnect(m_backEnd.data(), SIGNAL(signalChangedIndexCurrentChunk()), this, SLOT(slotChangedIndexCurrentChunk()));
        }

        QSize EditorWidgetStatus::sizeHint() const {
            QFontMetricsF fontMetrics(font());
            return QSize(fontMetrics.width(QChar('X')), fontMetrics.height() * 1.25);
        }

        void EditorWidgetStatus::slotChangedData() {
            update();
        }

        void EditorWidgetStatus::slotChangedIndexCurrentChunk() {
            m_labelFileInformation->setText(QString("%1 (%2 B)").arg(m_backEnd->getFileName()).arg(m_backEnd->getFileSize()));
            m_labelChunkInformation->setText(QString("Chunk %1/%2").arg(m_backEnd->getIndexCurrentChunk() + 1).arg(m_backEnd->getChunks()));
        }

        EditorBackEnd::EditorBackEnd(const QString &_fileName, QObject *_parent) :
            QObject(_parent),
            m_fileSizeMaximum(std::numeric_limits<qint64>::max() / 2),
            m_fileSize(0),
            m_fileName(_fileName),
            m_chunkSize(8192),
            m_chunkCache(16),
            m_indexCurrentChunk(0),
            m_chunks(0),
            m_cursorPosition(0),
            m_cursorSelectionStart(-1),
            m_cursorSelectionEnd(-1),
            m_validCharactersText("0123456789 abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"),
            m_validCharactersHex("0123456789abcdefABCDEF") {
            if(m_fileName.isEmpty()) {
                m_fileName = Utilities::File::createTempFile();
            }
            m_fileSize = Utilities::File::getFileSize(m_fileName);
            if(m_fileSize == -1) {
                qDebug() << "TODO/FIXME: critical";
            }
            m_chunks = qMax((qint64)(1), (m_fileSize + m_chunkSize - 1) / m_chunkSize);
        }

        EditorBackEnd::~EditorBackEnd() {

        }

        bool EditorBackEnd::processKeyPress(const QString &_character, const int _position, const bool _cursorHex, const bool _cursorHexFirstHalfByte) {
            PointerChunk pointerCurrentChunk = getCurrentChunk();
            if(!pointerCurrentChunk.isNull()) {
                if(_cursorHex) {
                    qDebug() << "TODO/FIXME: EditorBackEnd::processKeyPress (HEX)";
                }
                else {
                    if(m_validCharactersText.contains(_character)) {
                        pointerCurrentChunk->m_data.insert(_position, _character);
                        m_cursorPosition += _character.length();
                        emit signalChangedData();
                        return true;
                    }
                }
            }
            return false;
        }

        bool EditorBackEnd::processKeyRelease(const QString &_character, const int _position, const bool _cursorHex, const bool _cursorHexFirstHalfByte) {
            Q_UNUSED(_character);
            Q_UNUSED(_position);
            Q_UNUSED(_cursorHex);
            Q_UNUSED(_cursorHexFirstHalfByte);
            return false;
        }

        void EditorBackEnd::setCursorPosition(const int _cursorPosition, const bool _selection) {
            const qint64 dataStart = getDataStart();
            const qint64 cursorPosition = m_cursorPosition;
            const qint64 cursorSelectionStart = m_cursorSelectionStart;
            const qint64 cursorSelectionEnd = m_cursorSelectionEnd;
            m_cursorPosition = qMax((qint64)(0), dataStart + (qint64)(_cursorPosition));
            if(!_selection) {
                m_cursorSelectionStart = -1;
                m_cursorSelectionEnd = -1;
            }
            else {
                if(m_cursorSelectionStart == -1) {
                    m_cursorSelectionStart = cursorPosition;
                    m_cursorSelectionEnd = m_cursorPosition;
                }
                else {
                    m_cursorSelectionEnd = m_cursorPosition;
                }
            }
            PointerChunk pointerPreviousChunk = getPreviousChunk();
            PointerChunk pointerNextChunk = getNextChunk();
            if(isCursorInChunk(pointerPreviousChunk)) {
                decreaseCurrentChunk();
            }
            else if(isCursorInChunk(pointerNextChunk)) {
                increaseCurrentChunk();
            }
            if(m_cursorPosition != cursorPosition) {
                emit signalChangedCursorPosition();
            }
            if(m_cursorSelectionStart != cursorSelectionStart || m_cursorSelectionEnd != cursorSelectionEnd) {
                emit signalChangedCursorSelection();
            }
        }

        int EditorBackEnd::getCursorPosition() {
            const qint64 dataStart = getDataStart();
            const int cursorPosition = (int)(qint64)(m_cursorPosition - dataStart);
            return cursorPosition;
        }

        bool EditorBackEnd::selection() {
            const int selectionStart = getCursorSelectionStart();
            const int selectionEnd = getCursorSelectionEnd();
            return selectionStart != -1 && selectionEnd != -1 && selectionStart != selectionEnd;
        }

        int EditorBackEnd::getCursorSelectionStart() {
            int cursorSelectionStart = -1;
            if(m_cursorSelectionStart != -1) {
                const qint64 dataStart = getDataStart();
                cursorSelectionStart = (int)(qint64)(m_cursorSelectionStart - dataStart);
            }
            return cursorSelectionStart;
        }

        int EditorBackEnd::getCursorSelectionEnd() {
            int cursorSelectionEnd = -1;
            if(m_cursorSelectionEnd != -1) {
                const qint64 dataStart = getDataStart();
                cursorSelectionEnd = (int)(qint64)(m_cursorSelectionEnd - dataStart);
            }
            return cursorSelectionEnd;
        }

        QByteArray EditorBackEnd::getData() {
            QByteArray data;
            PointerChunk pointerPreviousChunk = getPreviousChunk();
            PointerChunk pointerCurrentChunk = getCurrentChunk();
            PointerChunk pointerNextChunk = getNextChunk();
            if(!pointerPreviousChunk.isNull()) {
                data.append(pointerPreviousChunk->m_data);
            }
            if(!pointerCurrentChunk.isNull()) {
                data.append(pointerCurrentChunk->m_data);
            }
            if(!pointerNextChunk.isNull()) {
                data.append(pointerNextChunk->m_data);
            }
            return data;
        }

        qint64 EditorBackEnd::getDataStart() {
            PointerChunk pointerPreviousChunk = getPreviousChunk();
            PointerChunk pointerCurrentChunk = getCurrentChunk();
            PointerChunk pointerNextChunk = getNextChunk();
            qint64 dataStart = -1;
            if(dataStart == -1 && !pointerPreviousChunk.isNull()) {
                dataStart = pointerPreviousChunk->m_index * m_chunkSize;
            }
            else if(dataStart == -1 && !pointerCurrentChunk.isNull()) {
                dataStart = pointerCurrentChunk->m_index * m_chunkSize;
            }
            else if(dataStart == -1 && !pointerNextChunk.isNull()) {
                dataStart = pointerNextChunk->m_index * m_chunkSize;
            }
            else {
                dataStart = 0;
            }
            return dataStart;
        }

        int EditorBackEnd::getDataLength() {
            const QByteArray data = getData();
            return data.length();
        }

        EditorBackEnd::PointerChunk EditorBackEnd::getChunk(const qint64 _indexChunk) {
            PointerChunk pointerChunk = PointerChunk(0);
            if(m_mapChunks.contains(_indexChunk)) {
                pointerChunk = m_mapChunks.value(_indexChunk);
            }
            else if(_indexChunk >= 0 && _indexChunk < m_chunks) {
                QFile file(m_fileName);
                if(file.open(QFile::ReadOnly)) {
                    file.seek(_indexChunk * m_chunkSize);
                    pointerChunk = PointerChunk(new Chunk(_indexChunk));
                    pointerChunk->m_data = file.read(m_chunkSize);
                    m_mapChunks.insert(_indexChunk, pointerChunk);
                }
            }
            return pointerChunk;
        }

        EditorBackEnd::PointerChunk EditorBackEnd::getPreviousChunk() {
            return getChunk(m_indexCurrentChunk - 1);
        }

        EditorBackEnd::PointerChunk EditorBackEnd::getCurrentChunk() {
            return getChunk(m_indexCurrentChunk);
        }

        EditorBackEnd::PointerChunk EditorBackEnd::getNextChunk() {
            return getChunk(m_indexCurrentChunk + 1);
        }

        bool EditorBackEnd::isCursorInChunk(PointerChunk _chunk) {
            bool result = false;
            if(!_chunk.isNull()) {
                const qint64 chunkDataStart = _chunk->m_index * m_chunkSize;
                const qint64 chunkDataEnd = chunkDataStart + (qint64)(_chunk->m_data.length());
                if(m_cursorPosition >= chunkDataStart && m_cursorPosition < chunkDataEnd) {
                    result = true;
                }
            }
            return result;
        }

        void EditorBackEnd::decreaseCurrentChunk() {
            const qint64 indexCurrentChunk = m_indexCurrentChunk;
            m_indexCurrentChunk -= 1;
            m_indexCurrentChunk = qMax(qint64(0), m_indexCurrentChunk);
            if(m_indexCurrentChunk != indexCurrentChunk) {
                cleanChunkCache();
                emit signalChangedIndexCurrentChunk();
            }
        }

        void EditorBackEnd::increaseCurrentChunk() {
            const qint64 indexCurrentChunk = m_indexCurrentChunk;
            m_indexCurrentChunk += 1;
            m_indexCurrentChunk = qMin(m_chunks - 1, m_indexCurrentChunk);
            if(m_indexCurrentChunk != indexCurrentChunk) {
                cleanChunkCache();
                emit signalChangedIndexCurrentChunk();
            }
        }

        void EditorBackEnd::setCurrentChunk(const qint64 _indexChunk) {
            const qint64 indexCurrentChunk = m_indexCurrentChunk;
            m_indexCurrentChunk = _indexChunk;
            m_indexCurrentChunk = qMax(qint64(0), m_indexCurrentChunk);
            m_indexCurrentChunk = qMin(m_chunks - 1, m_indexCurrentChunk);
            if(m_indexCurrentChunk != indexCurrentChunk) {
                cleanChunkCache();
                emit signalChangedIndexCurrentChunk();
            }
        }

        void EditorBackEnd::cleanChunkCache() {
            QSet<qint64> setChunksToBeCleaned;
            foreach(const qint64 indexChunk, m_mapChunks.keys()) {
                PointerChunk pointerChunk = m_mapChunks.value(indexChunk);
                if(pointerChunk.isNull()) {
                    setChunksToBeCleaned.insert(indexChunk);
                }
                else if(indexChunk < m_indexCurrentChunk && m_indexCurrentChunk - indexChunk > m_chunkCache && !pointerChunk->m_dirty) {
                    setChunksToBeCleaned.insert(indexChunk);
                }
                else if(indexChunk > m_indexCurrentChunk && indexChunk - m_indexCurrentChunk > m_chunkCache && !pointerChunk->m_dirty) {
                    setChunksToBeCleaned.insert(indexChunk);
                }
            }
            foreach(const qint64 indexChunk, setChunksToBeCleaned) {
                m_mapChunks.remove(indexChunk);
            }
        }

    }
}
