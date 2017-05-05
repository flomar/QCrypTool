// Editor.h

#ifndef _QCT_CORE_EDITOR_H_
#define _QCT_CORE_EDITOR_H_

#include <QCT.h>

#include <QCTDatabaseSystem.h>
#include <QCTOptionsSystem.h>
#include <QCTTranslationSystem.h>
#include <QCTScalingSystem.h>
#include <QCTHelpSystem.h>

#include <Core/Utilities.h>

namespace QCT {
    namespace Core {


        class EditorWidget;
        class EditorWidgetContainer;
        class EditorWidgetContainerText;
        class EditorWidgetContainerHex;
        class EditorWidgetStatus;
        class EditorBackEnd;

        typedef QSharedPointer<EditorBackEnd> PointerEditorBackEnd;

        class EditorWidget : public QWidget {
            Q_OBJECT
        public:
            EditorWidget(const QString &_fileName = QString::null, QWidget *_parent = 0);
            virtual ~EditorWidget();
        public:
            enum Mode {
                MODE_NULL,
                MODE_TEXT,
                MODE_HEX
            };
        public:
            void setMode(const Mode _mode);
            void setFontType(const ScalingSystem::FontType _fontType);
        signals:
            void signalChangedMode();
            void signalChangedFontType();
        public:
            void cut();
            void copy();
            void paste();
        public:
            virtual QSize sizeHint() const;
        public:
            const Mode &getMode() const { return m_mode; }
            const ScalingSystem::FontType &getFontType() const { return m_fontType; }
        private slots:
            void slotChangedScaling();
        private:
            Mode m_mode;
            ScalingSystem::FontType m_fontType;
        private:
            PointerEditorBackEnd m_backEnd;
        private:
            EditorWidgetContainer *m_widgetContainer;
            EditorWidgetStatus *m_widgetStatus;
        private:
            DatabaseSystem &m_databaseSystem;
            OptionsSystem &m_optionsSystem;
            TranslationSystem &m_translationSystem;
            ScalingSystem &m_scalingSystem;
            HelpSystem &m_helpSystem;
        };

        class EditorWidgetContainer : public QTextEdit {
            Q_OBJECT
        public:
            EditorWidgetContainer(PointerEditorBackEnd _backEnd, QWidget *_parent);
            virtual ~EditorWidgetContainer();
        public:
            void update();
        protected:
            virtual bool eventFilter(QObject *_object, QEvent *_event);
            virtual void paintEvent(QPaintEvent *_event);
            virtual void resizeEvent(QResizeEvent *_event);
        protected:
            void updateCursorPosition();
        protected slots:
            virtual void slotChangedCursorPosition();
            virtual void slotChangedCursorSelection();
            virtual void slotChangedData();
            virtual void slotChangedIndexCurrentChunk();
        protected:
            virtual void moveCursorLeft(const bool _selection) = 0;
            virtual void moveCursorRight(const bool _selection) = 0;
            virtual void moveCursorUp(const bool _selection) = 0;
            virtual void moveCursorDown(const bool _selection) = 0;
            virtual void moveCursorPageUp(const bool _selection) = 0;
            virtual void moveCursorPageDown(const bool _selection) = 0;
            virtual void moveCursorToStartOfLine(const bool _selection) = 0;
            virtual void moveCursorToEndOfLine(const bool _selection) = 0;
        protected:
            virtual bool processKeyPress(const QString &_character, const int _position) = 0;
            virtual bool processKeyRelease(const QString &_character, const int _position) = 0;
        protected:
            virtual int getTextCursorPosition(const int _cursorPosition) = 0;
            virtual int getDataCursorPosition(const int _cursorPosition) = 0;
        protected:
            virtual QByteArray getFormattedData(const QByteArray &_data) = 0;
            virtual void applyCursorExtraSelections() = 0;
        protected:
            PointerEditorBackEnd m_backEnd;
        protected:
            const QColor m_colorCursorActive;
            const QColor m_colorCursorInactive;
        private:
            int getVisualCursorLine();
            void setVisualCursorLine(const int _line);
        };

        class EditorWidgetContainerText : public EditorWidgetContainer {
            Q_OBJECT
        public:
            EditorWidgetContainerText(PointerEditorBackEnd _backEnd, QWidget *_parent);
            virtual ~EditorWidgetContainerText();
        protected:
            virtual bool eventFilter(QObject *_object, QEvent *_event);
            virtual void paintEvent(QPaintEvent *_event);
        protected:
            virtual void moveCursorLeft(const bool _selection);
            virtual void moveCursorRight(const bool _selection);
            virtual void moveCursorUp(const bool _selection);
            virtual void moveCursorDown(const bool _selection);
            virtual void moveCursorPageUp(const bool _selection);
            virtual void moveCursorPageDown(const bool _selection);
            virtual void moveCursorToStartOfLine(const bool _selection);
            virtual void moveCursorToEndOfLine(const bool _selection);
        protected:
            virtual bool processKeyPress(const QString &_character, const int _position);
            virtual bool processKeyRelease(const QString &_character, const int _position);
        protected:
            virtual int getTextCursorPosition(const int _cursorPosition);
            virtual int getDataCursorPosition(const int _cursorPosition);
        protected:
            virtual QByteArray getFormattedData(const QByteArray &_data);
            virtual void applyCursorExtraSelections();
        };

        class EditorWidgetContainerHex : public EditorWidgetContainer {
            Q_OBJECT
        public:
            EditorWidgetContainerHex(PointerEditorBackEnd _backEnd, QWidget *_parent);
            virtual ~EditorWidgetContainerHex();
        protected:
            virtual bool eventFilter(QObject *_object, QEvent *_event);
            virtual void paintEvent(QPaintEvent *_event);
        protected:
            virtual void moveCursorLeft(const bool _selection);
            virtual void moveCursorRight(const bool _selection);
            virtual void moveCursorUp(const bool _selection);
            virtual void moveCursorDown(const bool _selection);
            virtual void moveCursorPageUp(const bool _selection);
            virtual void moveCursorPageDown(const bool _selection);
            virtual void moveCursorToStartOfLine(const bool _selection);
            virtual void moveCursorToEndOfLine(const bool _selection);
        protected:
            virtual bool processKeyPress(const QString &_character, const int _position);
            virtual bool processKeyRelease(const QString &_character, const int _position);
        protected:
            virtual int getTextCursorPosition(const int _cursorPosition);
            virtual int getDataCursorPosition(const int _cursorPosition);
        protected:
            virtual QByteArray getFormattedData(const QByteArray &_data);
            virtual void applyCursorExtraSelections();
        private:
            void updateBytesPerRow();
        private:
            const int m_charactersAddress;
            const int m_charactersOuterSpacing;
            const int m_charactersInnerSpacing;
        private:
            int m_bytesPerRow;
        private:
            bool m_cursorHex;
            bool m_cursorHexFirstHalfByte;
        };

        class EditorWidgetStatus : public QWidget {
            Q_OBJECT
        public:
            EditorWidgetStatus(PointerEditorBackEnd _backEnd, QWidget *_parent);
            virtual ~EditorWidgetStatus();
        public:
            virtual QSize sizeHint() const;
        private slots:
            void slotChangedData();
            void slotChangedIndexCurrentChunk();
        private:
            PointerEditorBackEnd m_backEnd;
        private:
            QLabel *m_labelFileInformation;
            QLabel *m_labelChunkInformation;
        };

        class EditorBackEnd : public QObject {
            Q_OBJECT
        public:
            EditorBackEnd(const QString &_fileName, QObject *_parent = 0);
            virtual ~EditorBackEnd();
        public:
            struct Chunk {
                Chunk(const qint64 _index) : m_index(_index), m_data(QByteArray()), m_dirty(false) { }
                qint64 m_index;
                QByteArray m_data;
                bool m_dirty;
            };
            typedef QSharedPointer<Chunk> PointerChunk;
        public:
            bool processKeyPress(const QString &_character, const int _position, const bool _cursorHex = false, const bool _cursorHexFirstHalfByte = false);
            bool processKeyRelease(const QString &_character, const int _position, const bool _cursorHex = false, const bool _cursorHexFirstHalfByte = false);
        signals:
            void signalChangedData();
        public:
            void setCursorPosition(const int _cursorPosition, const bool _selection);
            int getCursorPosition();
        public:
            bool selection();
            int getCursorSelectionStart();
            int getCursorSelectionEnd();
        signals:
            void signalChangedCursorPosition();
            void signalChangedCursorSelection();
        public:
            QByteArray getData();
            qint64 getDataStart();
            int getDataLength();
        public:
            PointerChunk getChunk(const qint64 _indexChunk);
        public:
            PointerChunk getPreviousChunk();
            PointerChunk getCurrentChunk();
            PointerChunk getNextChunk();
        private:
            bool isCursorInChunk(PointerChunk _chunk);
        public:
            qint64 getFileSizeMaximum() const { return m_fileSizeMaximum; }
            qint64 getFileSize() const { return m_fileSize; }
            const QString &getFileName() const { return m_fileName; }
        public:
            qint64 getChunkSize() const { return m_chunkSize; }
            qint64 getIndexCurrentChunk() const { return m_indexCurrentChunk; }
            qint64 getChunks() const { return m_chunks; }
        public:
            void decreaseCurrentChunk();
            void increaseCurrentChunk();
            void setCurrentChunk(const qint64 _indexChunk);
        signals:
            void signalChangedIndexCurrentChunk();
        private:
            void cleanChunkCache();
        private:
            const qint64 m_fileSizeMaximum;
            qint64 m_fileSize;
            QString m_fileName;
        private:
            const qint64 m_chunkSize;
            const qint64 m_chunkCache;
            qint64 m_indexCurrentChunk;
            qint64 m_chunks;
        private:
            qint64 m_cursorPosition;
            qint64 m_cursorSelectionStart;
            qint64 m_cursorSelectionEnd;
        private:
            QMap<qint64, PointerChunk> m_mapChunks;
        private:
            const QString m_validCharactersText;
            const QString m_validCharactersHex;
        };

    }
}

#endif
