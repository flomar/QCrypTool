// Editor.h

#ifndef _QCT_CORE_EDITOR_H_
#define _QCT_CORE_EDITOR_H_

#include <QCT.h>

#include <QCTDatabaseSystem.h>
#include <QCTHelpSystem.h>
#include <QCTScalingSystem.h>
#include <QCTSettingsSystem.h>
#include <QCTTranslationSystem.h>

#include <Core/Utilities.h>

namespace QCT {
    namespace Core {

        class Editor;
        class EditorWidget;
        class EditorScrollBar;
        class EditorBackEnd;

        // This class implements an editor provding the visualization
        // and manipulation of both Ascii and Hex data alike.
        class Editor : public QWidget {
            Q_OBJECT
        public:
            Editor(QWidget *_parent = 0);
            virtual ~Editor();
        public:
            enum Mode {
                MODE_NULL,
                MODE_TEXT,
                MODE_HEX
            };
        public:
            void setMode(const Mode _mode);
            void setFontType(const ScalingSystem::FontType _fontType);
        public:
            virtual QSize sizeHint() const;
        protected slots:
            void slotChangedScaling();
        protected:
            DatabaseSystem &m_databaseSystem;
            HelpSystem &m_helpSystem;
            ScalingSystem &m_scalingSystem;
            SettingsSystem &m_settingsSystem;
            TranslationSystem &m_translationSystem;
        private:
            EditorWidget *m_editorWidget;
            EditorScrollBar *m_editorScrollBar;
            EditorBackEnd *m_editorBackEnd;
        private:
            Mode m_mode;
            ScalingSystem::FontType m_fontType;
        };

        // This class implements a back-end for the Editor class to provide
        // caching of very large files. The maximum supported file size is
        // "std::numberic_limits<qint64> / 2" because in Hex mode each
        // half-byte is addressed individually.
        class EditorBackEnd : public QObject {
            Q_OBJECT
        public:
            EditorBackEnd(QObject *_parent = 0);
            virtual ~EditorBackEnd();
        public:
            struct Block {
                Block() : data(QByteArray()), index(0), modified(false) { }
                QByteArray data;
                qint64 index;
                bool modified;
            };
        private:
            const qint64 m_blockSize;
            const qint64 m_fileSizeMaximum;
        };

        // This class implements the drawable area of the Editor class.
        class EditorWidget : public QWidget {
            Q_OBJECT
        public:
            EditorWidget(QWidget *_parent = 0);
            virtual ~EditorWidget();
        public:
            void setMode(const Editor::Mode _mode);
        protected:
            virtual void paintEvent(QPaintEvent *_event);
        private:
            Editor::Mode m_mode;
        };

        // This class implements the scroll bar of the Editor class.
        class EditorScrollBar : public QScrollBar {
            Q_OBJECT
        public:
            EditorScrollBar(QWidget *_parent = 0);
            virtual ~EditorScrollBar();
        };

    }
}

#endif
