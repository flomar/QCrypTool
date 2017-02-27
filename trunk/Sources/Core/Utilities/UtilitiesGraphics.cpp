// UtilitiesGraphics.cpp

#include <Core/Utilities/UtilitiesGraphics.h>

namespace QCrypTool {
    namespace Core {
        namespace Utilities {
            namespace Graphics {

                QPixmap getPixmapFromSvg(const QString &_pathToSvg, const QSize &_size) {
                    QImage image(_size, QImage::Format_ARGB32);
                    QSvgRenderer renderer(_pathToSvg);
                    QPainter painter(&image);
                    renderer.render(&painter);
                    return QPixmap::fromImage(image);
                }

                QIcon getIconFromSvg(const QString &_pathToSvg, const QSize &_size) {
                    QPixmap pixmap = getPixmapFromSvg(_pathToSvg, _size);
                    return QIcon(pixmap);
                }

            }
        }
    }
}
