#include "widget.h"
#include "ui_widget.h"
#include <QRandomGenerator>
#include <QDebug>
#include <QPainter>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    image.load("://pictures/cat.png");
    imagethread = new ImageThread;
    thread = new QThread(this);

    imagethread->moveToThread(thread);
    thread->start();

    connect(this,&Widget::sendImagetoThread,imagethread,&ImageThread::ImageProcess);
    connect(imagethread,&ImageThread::sendimage,this,&Widget::dealimage);
    connect(this,&Widget::destroyed,this,&Widget::dealthread);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_button_clicked()
{
    emit sendImagetoThread(image);
}

void Widget::dealimage(QImage ima)
{
    image = ima;
    update();


}

void Widget::paintEvent(QPaintEvent *)
{
    //QPainter p(this);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->setScaledContents(true);
    //p.drawImage(0,0,image);
}


void Widget::dealthread()
{
    thread->quit();
    thread->wait();
    delete imagethread;
}




