#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    timer= new QTimer;

    imgId = 1;
    //QPixmap img("C:\\Users\\tingy\\Desktop\\wallpaper\\1.jpg");
    QImage img;
    img.load("C:\\Users\\tingy\\Desktop\\wallpaper\\1.jpg");

    ui->imagineLabel->setPixmap(QPixmap::fromImage(img));


    connect(timer,&QTimer::timeout,this,&Widget::timeoutSlot);
}

Widget::~Widget()
{
    delete ui;
    delete timer;
}

void Widget::on_startButton_clicked()
{
    timer->start(TIMEOUT);
}

void Widget::timeoutSlot(){
    QImage img;
    QString path;
    ++imgId;
    if(imgId==4){
        imgId=1;
    }
    path ="C:\\Users\\tingy\\Desktop\\wallpaper\\";
    path += QString::number(imgId);
    path +=".jpg";
    img.load(path);
    ui->imagineLabel->setPixmap(QPixmap::fromImage(img));
}

void Widget::on_endButton_clicked()
{
    timer->stop();
}


void Widget::on_nextButton_clicked()
{
    QTimer::singleShot(TIMEOUT,this,SLOT(timeoutSlot()));
}

