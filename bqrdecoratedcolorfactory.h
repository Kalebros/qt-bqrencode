#ifndef BQRDECORATEDCOLORFACTORY_H
#define BQRDECORATEDCOLORFACTORY_H

#include "bqrcolorfactory.h"

#include <QPainter>
#include <QBrush>
#include <QPen>

#include <QDebug>

namespace BQREncode {

class BQRDecoratedColorFactory : public BQRColorFactory
{
    Q_OBJECT
public:
    explicit BQRDecoratedColorFactory(QObject *parent=0,QColor color=QColor(Qt::black),QSize size=QSize(300,300));

    QSize getSize() const {
        return _imageSize;
    }

    QString getPathDecoration() const {
        return _pathDecorationImage;
    }

    QSize getBackgroundDecorationSize() const {
        return _decorationSize;
    }

    virtual QImage *buildImageFromCode(const BQRCode &code);
    virtual QImage *buildImageFromCode(const BQRCode *code);

public slots:

    void setSize(QSize size);

    void setPathDecoration(QString path);

    void setBackgroundDecorationSize(QSize decorationSize);

protected:

    QSize _imageSize;   ///< Final size of the image
    QSize _decorationSize;      ///< Decoration background size
    QString _pathDecorationImage;   ///< Path of the decorative image

    QImage *buildDecoratedImage(QImage *originalImage);
};

}


#endif // BQRDECORATEDCOLORFACTORY_H
