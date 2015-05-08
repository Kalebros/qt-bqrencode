#ifndef BQRDEFAULTIMAGEFACTORY_H
#define BQRDEFAULTIMAGEFACTORY_H

#include "bqrencode_global.h"

#include <QObject>

#include "bqrimagefactory.h"

namespace BQREncode {

class BQRENCODESHARED_EXPORT BQRDefaultImageFactory : public BQRImageFactory
{
    Q_OBJECT
public:
    explicit BQRDefaultImageFactory(QObject *parent=0);

    virtual QImage *buildImageFromCode(const BQRCode *code);
    virtual QImage *buildImageFromCode(const BQRCode &code);
};


}


#endif // BQRDEFAULTIMAGEFACTORY_H
