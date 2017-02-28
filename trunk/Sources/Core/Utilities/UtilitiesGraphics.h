// UtilitiesGraphics.h

#ifndef _QCT_CORE_UTILITIES_UTILITIESGRAPHICS_H_
#define _QCT_CORE_UTILITIES_UTILITIESGRAPHICS_H_

#include <QCT.h>

namespace QCT {
    namespace Core {
        namespace Utilities {
            namespace Graphics {

                // Returns a pixmap based on the specified SVG file and
                // the desired size. This function uses QSvgRenderer,
                // QPainter and QImage internally.
                QPixmap getPixmapFromSvg(const QString &_pathToSvg, const QSize &_size);

                // Returns an icon based on the specified SVG file and
                // the desired size. This function uses QSvgRenderer,
                // QPainter and QImage internally.
                QIcon getIconFromSvg(const QString &_pathToSvg, const QSize &_size);

            }
        }
    }
}

#endif
