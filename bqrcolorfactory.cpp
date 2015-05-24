//
//    This file is part of BQREncode
//    BQREncode, a library wrapper of libqrencode for Qt 5*
//    Copyright (C) 2015, Antonio Ramírez Marti (morgulero@gmail.com)

//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Lesser General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.

//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU Lesser General Public License for more details.

//    You should have received a copy of the GNU Lesser General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#include "bqrcolorfactory.h"

namespace BQREncode {

BQRColorFactory::BQRColorFactory(QObject *parent,QColor color)
    : BQRImageFactory(parent)
{
    _color=color;
}

QImage *BQRColorFactory::buildImageFromCode(const BQRCode &code)
{
    if(!code.isReady())
        return 0;

    QImage *res=new QImage(code.width()+8,code.width()+8,QImage::Format_RGB32);

    res->fill(Qt::white);
    QRgb blackPixel=_color.rgb();

    for(unsigned int i=4;i<code.width()+4;i++) {
        for(unsigned int j=4;j<code.width()+4;j++) {
            if(code.isActive(i-4,j-4))
                res->setPixel(i,j,blackPixel);
        }
    }

    return res;
}

QImage *BQRColorFactory::buildImageFromCode(const BQRCode *code)
{
    if(!code->isReady())
        return 0;

    QImage *res=new QImage(code->width()+8,code->width()+8,QImage::Format_RGB32);

    res->fill(Qt::white);
    QRgb blackPixel=_color.rgb();

    for(unsigned int i=4;i<code->width()+4;i++) {
        for(unsigned int j=4;j<code->width()+4;j++) {
            if(code->isActive(i-4,j-4))
                res->setPixel(i,j,blackPixel);
        }
    }

    return res;
}

}
