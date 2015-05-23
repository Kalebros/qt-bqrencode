#ifndef BQRCOLORFACTORY_H
#define BQRCOLORFACTORY_H

#include "bqrimagefactory.h"

namespace BQREncode {

class BQRColorFactory : public BQRImageFactory
{
    Q_OBJECT
public:
    explicit BQRColorFactory(QObject *parent=0,QColor color=QColor(Qt::black));

    QColor getColor() const {
        return _color;
    }

    void setColor(QColor c) {
        _color=c;
    }

    virtual QImage *buildImageFromCode(const BQRCode &code);
    virtual QImage *buildImageFromCode(const BQRCode *code);

protected:

    QColor _color; ///< Color of the image's pixels
};

}


#endif // BQRCOLORFACTORY_H
