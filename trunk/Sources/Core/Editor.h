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
        class EditorDocument;

        class Editor : public QWidget {
            Q_OBJECT
        public:
            Editor(const QString &_fileName = QString::null, QWidget *_parent = 0);
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
            ScalingSystem::FontType m_fontType;
        private:
            EditorWidgetText *m_editorWidgetText;
            EditorWidgetHex *m_editorWidgetHex;
        private:
            EditorDocument *m_editorDocument;
        };

        class EditorWidgetText : public QTextEdit {
            Q_OBJECT
        public:
            EditorWidgetText(QWidget *_parent = 0);
            virtual ~EditorWidgetText();
        protected:
            virtual void paintEvent(QPaintEvent *_event);
        private slots:
            void slotChangedData(const QByteArray &_data);
        };

        class EditorWidgetHex : public QAbstractScrollArea {
            Q_OBJECT
        public:
            EditorWidgetHex(QWidget *_parent = 0);
            virtual ~EditorWidgetHex();
        protected:
            virtual void paintEvent(QPaintEvent *_event);
        private slots:
            void slotChangedData(const QByteArray &_data);
        private:
            void updateFontMetrics();
            void updateBytesPerRow();
        private:
            const int m_charactersAddress;
            const int m_charactersOuterSpacing;
            const int m_charactersInnerSpacing;
            float m_fontMetricsWidth;
            float m_fontMetricsHeight;
            int m_bytesPerRow;
        private:
            QByteArray m_data;
        };

        class EditorDocument : public QObject {
            Q_OBJECT
        public:
            EditorDocument(const QString &_fileName, QObject *_parent = 0);
            virtual ~EditorDocument();
        public:
            bool open();
            bool containsTextOnly();
        public:
            const QString &getFileName() const { return m_fileName; }
            const QString &getTitle() const { return m_title; }
        public:
            const QByteArray &getData() const { return m_data; }
        private:
            const qint64 m_fileSizeMaximum;
        private:
            QString m_fileName;
            QString m_title;
        private:
            QByteArray m_data;
        signals:
            void signalChangedData(const QByteArray &_data);
        };

    }
}

#endif
