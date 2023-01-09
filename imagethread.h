#ifndef IMAGETHREAD_H
#define IMAGETHREAD_H

#include <QObject>
#include <QImage>
#include <QDebug>

class ImageThread : public QObject
{
    Q_OBJECT
public:
    explicit ImageThread(QObject *parent = nullptr);
    void ImageProcess(QImage image);

signals:
    void sendimage(QImage image);


public slots:
};

#endif // IMAGETHREAD_H
