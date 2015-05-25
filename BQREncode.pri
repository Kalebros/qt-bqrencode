#-------------------------------------------------
#
# BQREncode .pri file
#
#-------------------------------------------------

INCLUDEPATH += $$PWD

SOURCES += \
    $$PWD\qrencode/bitstream.c \
    $$PWD\qrencode/mask.c \
    $$PWD\qrencode/mmask.c \
    $$PWD\qrencode/mqrspec.c \
    $$PWD\qrencode/qrencode.c \
    $$PWD\qrencode/qrinput.c \
    $$PWD\qrencode/qrspec.c \
    $$PWD\qrencode/rscode.c \
    $$PWD\qrencode/split.c \
    $$PWD\bqrcode.cpp \
    $$PWD\bqrcodegen.cpp \
    $$PWD\bqrimagefactory.cpp \
    $$PWD\bqrdefaultimagefactory.cpp \
    $$PWD\bqrcolorfactory.cpp \
    $$PWD\bqrdecoratedcolorfactory.cpp

HEADERS +=\
        $$PWD\bqrencode_global.h \
    $$PWD\qrencode/bitstream.h \
    $$PWD\qrencode/config.h \
    $$PWD\qrencode/mask.h \
    $$PWD\qrencode/mmask.h \
    $$PWD\qrencode/mqrspec.h \
    $$PWD\qrencode/qrencode.h \
    $$PWD\qrencode/qrencode_inner.h \
    $$PWD\qrencode/qrinput.h \
    $$PWD\qrencode/qrspec.h \
    $$PWD\qrencode/rscode.h \
    $$PWD\qrencode/split.h \
    $$PWD\bqrcode.h \
    $$PWD\bqrcodegen.h \
    $$PWD\bqrimagefactory.h \
    $$PWD\bqrdefaultimagefactory.h \
    $$PWD\bqrcolorfactory.h \
    $$PWD\bqrdecoratedcolorfactory.h
