#ifndef BQRCODEGEN_H
#define BQRCODEGEN_H

#include "bqrencode_global.h"

#include <QObject>
#include <QVariant>
#include <QByteArray>

#include "bqrcode.h"

namespace BQREncode {

/*!
 * BQRCode generator.
 *
 * We can create BQRCodes using this class.
 */

class BQRENCODESHARED_EXPORT BQRCodeGen : public QObject
{
    Q_OBJECT
public:

    /*!
     * Constructor
     */
    explicit BQRCodeGen(QObject *parent = 0);

    /*!
      Generate a BQRCode object encoding the data.

      It uses the QRcode_encodeData function internally. The data has to be converted to QString.

      @param data   Data we wish to encode
      @param version    Version number (check Fukuchi's libqrencode doc at https://fukuchi.org/works/qrencode/manual/index.html)
      @param level  Level of error correction
      @return A BQRCode object
      @note Doesnt' modifies the object's state
     */
    BQRCode *encode(QVariant data=QVariant(),int version=0,QRecLevel level=QR_ECLEVEL_M);

signals:

public slots:
};

}


#endif // BQRCODEGEN_H
