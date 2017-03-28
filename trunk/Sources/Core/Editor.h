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

        class Editor;
        class EditorWidgetText;
        class EditorWidgetHex;
        class EditorBackEnd;

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
            OptionsSystem &m_optionsSystem;
            TranslationSystem &m_translationSystem;
            ScalingSystem &m_scalingSystem;
            HelpSystem &m_helpSystem;
        private:
            Mode m_mode;
        private:
            ScalingSystem::FontType m_fontTypeText;
            ScalingSystem::FontType m_fontTypeHex;
            EditorWidgetText *m_editorWidgetText;
            EditorWidgetHex *m_editorWidgetHex;
        private:
            EditorBackEnd *m_editorBackEnd;
        };

        class EditorWidgetText : public QTextEdit {
            Q_OBJECT
        public:
            EditorWidgetText(QWidget *_parent = 0);
            virtual ~EditorWidgetText();
        };

        class EditorWidgetHex : public QWidget {
            Q_OBJECT
        public:
            EditorWidgetHex(QWidget *_parent = 0);
            virtual ~EditorWidgetHex();
        };

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

    }
}

#endif
