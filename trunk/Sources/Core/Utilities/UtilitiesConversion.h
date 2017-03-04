// UtilitiesConversion.h

#include <QCT.h>

namespace QCT {
    namespace Core {
        namespace Utilities {
            namespace Conversion {

                // This function converts a list of types into one string
                // literal with the specified separator inbetween the
                // elements, and the specified quotation mark around them.
                template<typename Type>
                    QString convertListToString(const QList<Type> &_list, const QString &_separator = ", ", const QString &_quotationMark = "'") {
                    QString result;
                    for(int index=0; index<_list.size(); index++) {
                        result.append(_quotationMark);
                        result.append(QVariant(_list.at(index)).toString());
                        result.append(_quotationMark);
                        if(index + 1 < _list.size()) {
                            result.append(_separator);
                        }
                    }
                    return result;
                }

                // This function converts a variant map into one string
                // literal of key/value pairs, with the specified separator
                // inbetween the elements, and the specified quotation marks
                // around them.
                inline QString convertVariantMapToString(const QVariantMap &_variantMap, const QString &_separator = ", ", const QString &_quotationMark = "'") {
                    QString result;
                    const QList<QString> listKeys = _variantMap.keys();
                    for(int index=0; index<listKeys.size(); index++) {
                        result.append(listKeys.at(index));
                        result.append("=");
                        result.append(_quotationMark);
                        result.append(_variantMap.value(listKeys.at(index)).toString());
                        result.append(_quotationMark);
                        if(index + 1 < listKeys.size()) {
                            result.append(_separator);
                        }
                    }
                    return result;
                }

            }
        }
    }
}
