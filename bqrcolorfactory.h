#ifndef BQRCOLORFACTORY_H
#define BQRCOLORFACTORY_H

#include "bqrimagefactory.h"

namespace BQREncode {

/*!
 * This factory builds a QR image code using a specific color as active pixel's color.
 */

class BQRColorFactory : public BQRImageFactory
{
    Q_OBJECT
public:
    explicit BQRColorFactory(QObject *parent=0,QColor color=QColor(Qt::black));

    /*!
     * Get the active pixel's color (black by default)
     * @return Active pixel's color
     * @note Doesn't modifies the object
     */
    QColor getColor() const {
        return _color;
    }
    virtual QImage *buildImageFromCode(const BQRCode &code);
    virtual QImage *buildImageFromCode(const BQRCode *code);

public slots:

    /*!
     * Set the active pixel's color (black by default)
     * @param   color   Active pixel's color
     * @note Modifies the object
     */

    void setColor(QColor c) {
        _color=c;
    }

protected:

    QColor _color; ///< Color of the image's pixels
};

}


#endif // BQRCOLORFACTORY_H
