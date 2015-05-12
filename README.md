# qt-bqrencode
QR encode library for Qt 5.*

This library it's a wrapper around qrencode (Kentaru Fukuchi, 2006).
You can find qrencode library at https://fukuchi.org/works/qrencode/, and a
development version at https://github.com/fukuchi/libqrencode/blob/master/qrencode.h

##Compile

Just clone this repository and use *qmake* to compile it, BUT...

### Compile for Android

... if you want to use this library in an Android proyect, I strongly recommend you
to include the .PRI file in your project file (.pro).

```
# Your project .PRO
# ...

include (<qt-bqrencode dir>/BQREncode.pri)

# ...
```

##Usage

If you want to encode some data, just build a **BQRCodeGen** object and use
it to generate a **BQRCode** object. Then, build a **BQRImageFactory** object and
obtain a **QImage** from the **BQRCode**. There is a quick and dirty example:

```c++
using namespace BQREncode;

//...

BQRCodeGen generator(this);
BQRCode *codeQR=generator.encode(QVariant("test information 123"));
BQRImageFactory *factory=new BQRDefaultImageFactory(this);

QImage *qrCodeImage=factory->buildImageFromCode(codeQR);

//...
```
