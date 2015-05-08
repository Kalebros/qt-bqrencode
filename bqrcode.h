#ifndef BQRCODE_H
#define BQRCODE_H

#include "bqrencode_global.h"

#include <QObject>

//LIBQRENCODE

#include "qrencode/qrencode.h"

/*!
 * @namespace BQREncode
 * Library namespace
 */

namespace BQREncode {

/*!
 * Encapsulates a QRcode struct.
 *
 * The BQRCode class wrapps around a QRcode and implements
 * methods to quickly consult the information.
 */

class BQRENCODESHARED_EXPORT BQRCode : public QObject
{
    Q_OBJECT
public:

    /*!
     * Constructor
     * @param parent    Qt object parent
     * @param code      QRcode to wrap around
     */
    explicit BQRCode(QObject *parent = 0,QRcode *code=0);

    /*!
      Free resources
      */
    ~BQRCode();

    /*!
     * Check if the object is ready to be used
     *
     * A BQRCode is ready to be used if the internal QRcode pointer is valid.
     * An internal QRcode is valid if it's NOT NULL.
     *
     * @return bool, true: it's valid, false: it's not
     * @note Doesn't modifies the object's state.
     */
    bool isReady() const;

    /*!
      Width of the code.

      A BQRCode object can be used to generate a pixel image, with WIDTH * WIDTH size.
      @return Width of the code.
      @note Doesn't modifies the object's state
      @pre BQRCode object MUST be ready; this method will return 0 otherwise.
      */
    unsigned int width() const;

    /*!
      Version of the code

      @return Version the code
      @note Don't modifies the object's state
      @pre BQRCode object MUST be ready; this method will return -1 otherwise.
      */
    int version() const;

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
    unsigned char getPixel(unsigned int i,unsigned int j) const;

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
    bool isActive(unsigned int i,unsigned int j) const;

    /*!
      Copy the object

      Qt's shared pointer doesn't permit the use of copy constructors; so, if you want to use
      the same QRcode object on two differents BQRCode objects, DONT. But, if you must do it, use this method
      to create a copy of the BQRCode's QRcode internal struct.

      @param bqrCode    Original BQRCode object
      @return A copy of the original BQRCode
      @note Doesn't modifies the object's state
      */
    static BQRCode *copyOf(const BQRCode *bqrCode);

    /*!
      @overload
      */
    static BQRCode *copyOf(const BQRCode &bqrCode);

signals:

public slots:

private:

    QRcode *_code;

};

}

#endif // BQRCODE_H
