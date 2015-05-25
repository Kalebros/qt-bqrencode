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

#include "bqrdecoratedcolorfactory.h"

namespace BQREncode {

BQRDecoratedColorFactory::BQRDecoratedColorFactory(QObject *parent,QColor color,QSize size) :
    BQRColorFactory(parent,color),
    _imageSize(size)
{
    _pathDecorationImage=QString();
}

QImage *BQRDecoratedColorFactory::buildImageFromCode(const BQRCode &code)
{
    QImage *image =BQRColorFactory::buildImageFromCode(code);

    if(_pathDecorationImage.isEmpty())
        return image;

    return buildDecoratedImage(image);
}

QImage *BQRDecoratedColorFactory::buildImageFromCode(const BQRCode *code)
{
    QImage *image=BQRColorFactory::buildImageFromCode(code);

    if(_pathDecorationImage.isEmpty())
        return image;

    return buildDecoratedImage(image);
}

void BQRDecoratedColorFactory::setSize(QSize size)
{
    _imageSize=size;
    _decorationSize=QSize((size.width()/10)+10,(size.height()/10)+10);
}

void BQRDecoratedColorFactory::setPathDecoration(QString path)
{
    _pathDecorationImage=path;
}

void BQRDecoratedColorFactory::setBackgroundDecorationSize(QSize decorationSize)
{
    _decorationSize=decorationSize;
}

QImage *BQRDecoratedColorFactory::buildDecoratedImage(QImage *originalImage)
{
    QImage *scaledImage=new QImage(originalImage->scaled(_imageSize));
    delete originalImage;

    QImage decorativeImage(_pathDecorationImage);

    QPainter painter(scaledImage);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QPen pPen=painter.pen();
    pPen.setColor(_color);
    pPen.setWidth(5);
    painter.setPen(pPen);
    painter.setBrush(Qt::white);

    QPoint center=scaledImage->rect().center();

    QRect rect_dibujo(QPoint(center.x()-_decorationSize.width(),center.y()-_decorationSize.height()),QPoint(center.x()+_decorationSize.width(),center.y()+_decorationSize.height())); // Tamaño arbitrario

    painter.begin(scaledImage);
    painter.drawEllipse(rect_dibujo);

    painter.setBackgroundMode(Qt::TransparentMode);
    painter.setRenderHint(QPainter::Antialiasing);

    int rectWidth=(_imageSize.width()/10)+10;
    int rectHeight=(_imageSize.height()/10)+10;
    QRect rect_imagen(QPoint(center.x()-rectWidth,center.y()-rectHeight),QPoint(center.x()+rectWidth,center.y()+rectHeight));
    painter.drawImage(rect_imagen,decorativeImage);
    painter.end();

    return scaledImage;
}

}

