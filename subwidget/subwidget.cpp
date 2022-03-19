#include "subwidget.h"
#include "ui_subwidget.h"

subwidget::subwidget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::subwidget)
{
    ui->setupUi(this);
    ID_index = 0;
    P_index = 1;
    ui->lineEdit->setText(QString::number(ID_index));
    ui->lineEdit->setReadOnly(1);
    ui->lineEdit_2->setReadOnly(1);
    ui->textEdit->setReadOnly(1);
}

subwidget::~subwidget()
{
    delete ui;
}

void subwidget::on_Previous_clicked()
{
    if( -- P_index < 0)
    {
        P_index = 4;
    }
    update();
}

void subwidget::on_Next_clicked()
{
    if( ++ P_index > 4)
    {
        P_index = 1;
    }
    update();
}

void subwidget::on_Back_clicked()
{

}


void subwidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //获取绘图区

    QRect rect1 = ui->frame->frameRect();
    QRect rect2 = ui->frame_2->frameRect();

    //QRect rect3 = ui->widget->rect();
    //qDebug()<<"1"<<rect1;

    //对齐frame
    rect1.translate(ui->frame->pos());
    rect2.translate(ui->frame_2->pos());
    //qDebug()<<"2"<<rect1;
    //构建图形
    //获得路径
    ID_index = 1;
    QImage image1(":/" + QString::number(ID_index) + "/" + QString::number(P_index) + ".jpg");
    QImage image2(":/" + QString::number(ID_index) + "/" + QString::number(P_index + 1) + ".jpg");
    painter.drawImage(rect1,image1);
    painter.drawImage(rect2,image2);
}




//void subwidget::PicChange()
//{
//    for(P_index = 0;P_index < 5; P_index ++)
//    {
//        QImage image1(":/" + QString::number(ID_index) + "/" + QString::number(P_index) + ".jpg");
//        QImage image2(":/" + QString::number(ID_index) + "/" + QString::number(P_index + 1) + ".jpg");
//    }
//}


