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

#include "bqrcode.h"

namespace BQREncode {

/*!
 * Constructor
 * @param parent    Qt object parent
 * @param code      QRcode to wrap around
 */
BQRCode::BQRCode(QObject *parent, QRcode *code) :
    QObject(parent),
    _code(code)
{
}

/*!
  @overload
  */
BQRCode::BQRCode(QObject *parent, int width, int version, unsigned char *info) :
    QObject(parent)
{
    if(width==-1 || version==-1 || info==0) {
        _code=0;
        return;
    }
    _code=new QRcode();
    _code->version=version;
    _code->width=width;
    _code->data=info;
}

/*!
  Free resources
  */
BQRCode::~BQRCode()
{
    if(_code)
        QRcode_free(_code);
    _code=0;
}

/*!
 * Check if the object is ready to be used
 *
 * A BQRCode is ready to be used if the internal QRcode pointer is valid.
 * An internal QRcode is valid if it's NOT NULL.
 *
 * @return bool, true: it's valid, false: it's not
 * @note Doesn't modifies the object's state.
 */
bool BQRCode::isReady() const
{
    if(_code)
        return true;
    return false;
}

/*!
  Width of the code.

  A BQRCode object can be used to generate a pixel image, with WIDTH * WIDTH size.
  @return Width of the code.
  @note Doesn't modifies the object's state
  @pre BQRCode object MUST be ready; this method will return 0 otherwise.
  */
unsigned int BQRCode::width() const
{
    if(_code)
        return _code->width;
    return 0;
}

/*!
  Version of the code

  @return Version the code
  @note Don't modifies the object's state
  @pre BQRCode object MUST be ready; this method will return -1 otherwise.
  */
int BQRCode::version() const
{
    if(_code)
        return _code->version;
    return -1;
}

/*!
  Pixel data at (i,j)

  A pixel it's an unsigned byte, and every bit has significance:
  -# Finder pattern and separator (Most Significant Bit)
  -# Alignment pattern
  -# Timing pattern
  -# Version information
  -# Format informattion
  -# Data and ECC code area
  -# Color (1: black, 0: white)

  Consult https://fukuchi.org/works/qrencode/manual/structQRcode.html

  @param i  Coordinate X
  @param j  Coordinate Y
  @return unsigned char, pixel data
  @note Doesn't modifies the object's state
  @pre BQRCode object MUST be ready; this method returns undefined otherwise.
  @pre i < BQRCode object's width, j < BQRCode object's width.
  */
unsigned char BQRCode::getPixel(unsigned int i,unsigned int j) const
{
    if(_code)
        return _code->data[(i*_code->width)+j];
    return 0;
}

/*!
  Check pixel color.

  This method checks the pixel data and returns if the pixel at (i,j) coordinates
  it's black (true) or white (false)

  @param i  Coordinate X
  @param j  Coordinate Y
  @return bool, true: it's black, false: it's white
  @note Doesn't modifies the object's state
  @pre BQRCode object MUST be ready; this method returns undefined otherwise.
  @pre i < BQRCode object's width, j < BQRCode object's width
  */
bool BQRCode::isActive(unsigned int i,unsigned int j) const
{
    bool res=false;
    if(_code)
        res=_code->data[(i*_code->width)+j]&0x01;

    return res;
}

/*!
  Copy the object

  Qt's shared pointer doesn't permit the use of copy constructors; so, if you want to use
  the same QRcode object on two differents BQRCode objects, DONT. But, if you must do it, use this method
  to create a copy of the BQRCode's QRcode internal struct.

  @param bqrCode    Original BQRCode object
  @return A copy of the original BQRCode
  @note Doesn't modifies the object's state
  */
BQRCode *BQRCode::copyOf(const BQRCode *bqrCode)
{
    //Build a new QRcode struct
    QRcode *copyOfCode=(QRcode*)malloc(sizeof(QRcode));

    unsigned char *copyOfData=new unsigned char[bqrCode->_code->width*bqrCode->_code->width];
    for(int i=0;i<(bqrCode->_code->width*bqrCode->_code->width);i++)
        copyOfData[i]=bqrCode->_code->data[i];

    copyOfCode->data=copyOfData;
    copyOfCode->version=bqrCode->_code->version;
    copyOfCode->width=bqrCode->_code->width;

    return new BQRCode(bqrCode->parent(),copyOfCode);
}

/*!
  @overload
  */
BQRCode *BQRCode::copyOf(const BQRCode &bqrCode)
{
    QRcode *copyOfCode=(QRcode*)malloc(sizeof(QRcode));

    unsigned char *copyOfData=new unsigned char[bqrCode._code->width*bqrCode._code->width];
    for(int i=0;i<(bqrCode._code->width*bqrCode._code->width);i++)
        copyOfData[i]=bqrCode._code->data[i];

    copyOfCode->data=copyOfData;
    copyOfCode->version=bqrCode._code->version;
    copyOfCode->width=bqrCode._code->width;

    return new BQRCode(bqrCode.parent(),copyOfCode);
}

}
