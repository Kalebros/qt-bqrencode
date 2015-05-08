#-------------------------------------------------
#
# Project created by QtCreator 2015-05-08T14:29:43
#
#-------------------------------------------------

QT       -= gui

TARGET = BQREncode
TEMPLATE = lib

DEFINES += BQRENCODE_LIBRARY

INCLUDEPATH += .

SOURCES += \
    qrencode/bitstream.c \
    qrencode/mask.c \
    qrencode/mmask.c \
    qrencode/mqrspec.c \
    qrencode/qrencode.c \
    qrencode/qrinput.c \
    qrencode/qrspec.c \
    qrencode/rscode.c \
    qrencode/split.c \
    bqrcode.cpp

HEADERS +=\
        bqrencode_global.h \
    qrencode/bitstream.h \
    qrencode/config.h \
    qrencode/mask.h \
    qrencode/mmask.h \
    qrencode/mqrspec.h \
    qrencode/qrencode.h \
    qrencode/qrencode_inner.h \
    qrencode/qrinput.h \
    qrencode/qrspec.h \
    qrencode/rscode.h \
    qrencode/split.h \
    bqrcode.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
