#include "subwidget.h"
#include "ui_subwidget.h"

subwidget::subwidget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::subwidget)
{
    ui->setupUi(this);

    //设置按钮字体颜色
    //QPushButton *pushbutton = new QPushButton(this);

//    ui->Previous->setAutoFillBackground(true);
      ui->Previous->setFlat(true);
//    ui->Next->setAutoFillBackground(true);
      ui->Next->setFlat(true);
//    ui->Back->setAutoFillBackground(true);
      ui->Back->setFlat(true);


    QPalette palette = ui->centralwidget->palette();
    palette.setColor(QPalette::Window,Qt::red);
    ui->Previous->setPalette(palette);

    //初始化人物id 和 图片id
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
    if( -- P_index < 1)
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
    //返回上一级界面
}


void subwidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //设置背景颜色
    QLinearGradient lineaGrad(QPointF(710,400),QPointF(710,700));
    //渐变白的到灰色
    lineaGrad.setColorAt(0,Qt::black);
    lineaGrad.setColorAt(1,Qt::gray);
    QBrush brush1(lineaGrad);

    //QRect rect = ui->centralwidget->rect();
    painter.setBrush(brush1);
    painter.drawRect(rect());

    //获取绘图区
    QRect rect1 = ui->frame->frameRect();
    QRect rect2 = ui->frame_2->frameRect();
    QRect rect3 = ui->frame_3->frameRect();
    //QRect rect3 = ui->widget->rect();
    //qDebug()<<"1"<<rect1;

    //对齐frame
    rect1.translate(ui->frame->pos());
    rect2.translate(ui->frame_2->pos());
    rect3.translate(ui->frame_3->pos());

    qDebug()<<"2"<<rect1;
    //构建图形
    //获得路径
    ID_index = 1;

    QImage image1(":/" + QString::number(ID_index) + "/" + QString::number(P_index) + ".jpg");
    QImage image2(":/" + QString::number(ID_index) + "/" + QString::number(P_index + 1) + ".jpg");
    QImage image3(":/icon.png");
    painter.drawImage(rect1,image1);
    painter.drawImage(rect2,image2);
    painter.drawImage(rect3,image3);
}




