// UtilitiesGraphics.h

#ifndef _QCRYPTOOL_CORE_UTILITIES_UTILITIESGRAPHICS_H_
#define _QCRYPTOOL_CORE_UTILITIES_UTILITIESGRAPHICS_H_

#include <QCrypTool.h>

namespace QCrypTool {
    namespace Core {
        namespace Utilities {
            namespace Graphics {

                // returns a pixmap based on the specified SVG file and
                // the desired size; this function uses QSvgRenderer,
                // QPainter and QImage internally
                QPixmap getPixmapFromSvg(const QString &_pathToSvg, const QSize &_size);

                // returns an icon based on the specified SVG file and
                // the desired size; this function uses QSvgRenderer,
                // QPainter and QImage internally
                QIcon getIconFromSvg(const QString &_pathToSvg, const QSize &_size);

            }
        }
    }
}

#endif
