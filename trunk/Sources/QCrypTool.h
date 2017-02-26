// QCrypTool.h

#ifndef _QCRYPTOOL_QCRYPTOOL_H_
#define _QCRYPTOOL_QCRYPTOOL_H_

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
#include <QDateTime>
#include <QRegExp>
#include <QTranslator>
#include <QMessageBox>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QDirIterator>

namespace QCrypTool {

    QString getApplicationName();
    QString getApplicationVersion();
    QString getApplicationCopyright();

}

#endif
