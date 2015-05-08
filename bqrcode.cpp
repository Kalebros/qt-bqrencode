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
    /// @todo Implements BQRCode::copyOf
    return 0;
}

/*!
  @overload
  */
BQRCode *BQRCode::copyOf(const BQRCode &bqrCode)
{
    return 0;
}

}
