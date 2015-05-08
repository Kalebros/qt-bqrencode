#ifndef BQRIMAGEFACTORY_H
#define BQRIMAGEFACTORY_H

#include "bqrencode_global.h"

#include <QObject>
#include <QImage>
#include <QColor>
#include <QRgb>

#include "bqrcode.h"

namespace BQREncode {

/*!
 * BQREncode Image's Factory
 *
 * A image factory builds QImage objects using a BQRCode object's information.
 *
 * We can use differents factories to build differents images (b.e, using a different color, with a central logo,
 * etc...)
 */
class BQRENCODESHARED_EXPORT BQRImageFactory : public QObject
{
    Q_OBJECT
public:
    explicit BQRImageFactory(QObject *parent = 0);

    /*!
     * Build a QR image from the BQRCode object.
     * \param code  BQRCode objec
     * \return QR image
     */
    virtual QImage *buildImageFromCode(const BQRCode *code)=0;

    /*!
     * @overload
     */

    virtual QImage *buildImageFromCode(const BQRCode &code)=0;

signals:

public slots:
};

}

#endif // BQRIMAGEFACTORY_H
