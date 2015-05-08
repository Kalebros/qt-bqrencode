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

#include "bqrcodegen.h"

namespace BQREncode {

/*!
 * Constructor
 */
BQRCodeGen::BQRCodeGen(QObject *parent) : QObject(parent)
{

}

/*!
  Generate a BQRCode object encoding the data.

  It uses the QRcode_encodeData function internally. The data has to be converted to QString.

  @param data   Data we wish to encode
  @param version    Version number (check Fukuchi's libqrencode doc at https://fukuchi.org/works/qrencode/manual/index.html)
  @param level  Level of error correction
  @return A BQRCode object
  @note Doesnt' modifies the object's state
 */
BQRCode *BQRCodeGen::encode(QVariant data,int version,QRecLevel level)
{
    if(!data.isValid()||data.isNull())
        return new BQRCode(this);

    QString dataString=data.toString();
    QRcode *code=QRcode_encodeData(dataString.length(),(const unsigned char*)dataString.toStdString().c_str(),version,level);
    if(code)
        return new BQRCode(this,code);
    else return new BQRCode(this);
}


}

