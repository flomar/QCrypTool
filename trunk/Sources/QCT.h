// QCT.h

#ifndef _QCT_QCT_H_
#define _QCT_QCT_H_

#include <QDebug>
#include <QSharedPointer>
#include <QApplication>
#include <QMainWindow>
#include <QDialog>
#include <QEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVector>
#include <QMap>
#include <QSet>
#include <QVariant>
#include <QVariantMap>
#include <QDateTime>
#include <QRegExp>
#include <QLocale>
#include <QTranslator>
#include <QMessageBox>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QDirIterator>
#include <QSvgRenderer>
#include <QPainter>
#include <QPixmap>
#include <QIcon>
#include <QImage>
#include <QWhatsThis>
#include <QProcess>
#include <QThread>
#include <QFont>
#include <QFontDatabase>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlIndex>
#include <QSqlField>
#include <QSqlRelationalTableModel>

namespace QCT {

    QString getProjectName();
    QString getProjectVersion();
    QString getProjectCopyright();

}

#endif
