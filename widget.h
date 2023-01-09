#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include "imagethread.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void dealimage(QImage image);
    void paintEvent(QPaintEvent *);
    void dealthread();

signals:
    void sendImagetoThread(QImage image);

private slots:
    void on_button_clicked();

private:
    Ui::Widget *ui;
    QThread *thread;
    ImageThread *imagethread;
    QImage image;

};

#endif // WIDGET_H
