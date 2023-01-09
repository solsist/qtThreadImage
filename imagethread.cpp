#include "imagethread.h"
#include <QRandomGenerator>
#include <QRgb>

ImageThread::ImageThread(QObject *parent) : QObject(parent)
{

}


void ImageThread::ImageProcess(QImage image)
{

    double x = QRandomGenerator::global()->generateDouble();
    double y = QRandomGenerator::global()->generateDouble();
    int xcoor = int(x*image.width());
    int ycoor = int(y*image.height());
    qDebug()<<xcoor<<ycoor;
    image.setPixelColor(xcoor,ycoor,QColor(0, 255, 0, 255));

    emit sendimage(image);

}
