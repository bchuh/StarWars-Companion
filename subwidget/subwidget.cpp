#include "subwidget.h"
#include "ui_subwidget.h"
#include <QDebug>
#include <QString>
#include <iostream>

using namespace std;
subwidget::subwidget(QWidget *parent, string db_path)
    : QMainWindow(parent)
    , ui(new Ui::subwidget)
{
    ui->setupUi(this);

    setFixedSize(800,600);
    //设置按钮字体颜色
    //QPushButton *pushbutton = new QPushButton(this);
    //ui->Previous->setAutoFillBackground(true);
    ui->Previous->setFlat(true);
    //ui->Next->setAutoFillBackground(true);
    ui->Next->setFlat(true);
    //ui->Back->setAutoFillBackground(true);
    ui->Back->setFlat(true);

    //设置模版
    //QPalette palette = ui->centralwidget->palette();
    //palette.setColor(QPalette::Window,Qt::red);
    //ui->Previous->setPalette(palette);

    //逐个调整
    ui->frame_3->setStyleSheet("border:0px");
    ui->frame_2->setStyleSheet("border:0px");
    ui->frame->setStyleSheet("border:0px");
    ui->lineEdit->setStyleSheet("border:0px groove gray;border-radius:10px;padding:2px 4px;background-color: rgb(145, 145, 145);color:rgb(255,255,255);font: 15pt");
    ui->lineEdit_2->setStyleSheet("border:0px groove gray;border-radius:10px;padding:2px 4px;background-color: rgb(145, 145, 145);color:rgb(255,255,255);font: 15pt");
    ui->lineEdit_3->setStyleSheet("border:0px groove gray;border-radius:10px;padding:2px 4px;background-color: rgb(145, 145, 145);color:rgb(255,255,255);font: 15pt");
    ui->label->setStyleSheet("color:rgb(255,255,255);font: 15pt");
    ui->label_2->setStyleSheet("color:rgb(255,255,255);font: 15pt");
    ui->label_3->setStyleSheet("color:rgb(255,255,255);font: 15pt");
    ui->Previous->setStyleSheet("color:rgb(255,255,255);font: 15pt");
    ui->Back->setStyleSheet("color:rgb(255,255,255);font: 15pt");
    ui->Next->setStyleSheet("color:rgb(255,255,255);font: 15pt");
    ui->scrollArea_2->setStyleSheet("border:2px groove black;border-radius:10px;padding:4px 6px;background-color: rgb(145, 145, 145);border-color: rgb(255, 203, 0);");
    ui->textEdit->setStyleSheet("color:rgb(255,255,255);font: 18pt");
    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_3->setReadOnly(true);
    ui->textEdit->setReadOnly(true);
    ui->progressBar->setMaximum(6);
    //设置图片起始
    ImageIndex = 1;
    //init db


    dbModule=(SQLiteHelper*)new SQLiteHelper();

    const char* path=db_path.c_str();
    auto temp=dbModule->openDB(const_cast<char*>(path));
    if(temp==false)
        exit(0);
    cout<<dbModule->nameQuery(2)<<endl;



}

void subwidget::setID(int id)
{
   cout<<"subwidget:"<<endl;
   //cout<<dbModule->nameQuery(3);
   //this->setInfo(id, 0, "aa", "N/A");

   char* temp_name=dbModule->nameQuery(id);
   string name=temp_name;
   //cout<<dbModule->nameQuery(id);
   if(temp_name != nullptr){
          this->setInfo(id, 0, QString::fromStdString(name), "N/A"); //目前只支持名字
   }else{
       cout<<"Error:nameQuery return NULL!"<<endl;
   }

}
void subwidget::setInfo(int ID,int Age,QString Name, QString Intro)
{
    //SQL 查询返回结果
    //当上级跳转信号时设置
    //初始化人物
    P.ID = ID;
    P.Age = Age;
    P.Intro = Intro;
    P.Name = Name;
    ui->lineEdit->setText(QString::number(P.ID));
    ui->lineEdit_2->setText(P.Name);
    ui->lineEdit_3->setText(QString::number(P.Age));
    ui->textEdit->setText("     " + P.Intro);

    update();
    while(true)
    {
        connect(this,&subwidget::setSignal,this,&subwidget::on_Back_clicked);
        for(int i = 1; i < 7; i ++)
        {
            //延时
            QTime timer = QTime::currentTime().addMSecs(1000);
               while( QTime::currentTime() < timer )
                  QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
               ui->progressBar->setValue(i);
        }
        emit mySignal();
    }
}


void subwidget::on_Previous_clicked()
{
    if( --ImageIndex  < 1)
    {
        ImageIndex = 4;
    }
    emit setSignal();
    ui->progressBar->setValue(0);
    update();
}

void subwidget::on_Next_clicked()
{
    if( ++ ImageIndex > 4)
    {
        ImageIndex = 1;
    }
    emit setSignal();
    ui->progressBar->setValue(0);
    update();
}


void subwidget::on_Back_clicked()
{
    //返回上一级界面
    hide();
    emit mySignal();
/*
    //演示 当上级跳转传入值 设置文本刷新界面
    P.ID = 1;
    P.Age = 2;
    P.Intro = "3";
    P.Name = "4";
    ui->lineEdit->setText(QString::number(P.ID));
    ui->lineEdit_2->setText(P.Name);
    ui->lineEdit_3->setText(QString::number(P.Age));
    ui->textEdit->setText("     " + P.Intro);
    update();

    while(true)
    {
        connect(this,&subwidget::setSignal,this,&subwidget::on_Back_clicked);
        for(int i = 1; i < 7; i ++)
        {
            //延时
            QEventLoop loop;
                QTimer::singleShot(1000, &loop, SLOT(quit()));
                loop.exec();
               ui->progressBar->setValue(i);
        }
        emit mySignal();
    }
    */
}



//画图
void subwidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //设置背景颜色
    QLinearGradient lineaGrad(QPointF(710,400),QPointF(710,700));
    //渐变白的到灰色
    lineaGrad.setColorAt(0,Qt::black);
    lineaGrad.setColorAt(1,Qt::gray);
    QBrush brush1(lineaGrad);

    painter.setBrush(brush1);
    painter.drawRect(rect());

    //获取绘图区
    QRect rect1 = ui->frame->frameRect();
    QRect rect2 = ui->frame_2->frameRect();
    QRect rect3 = ui->frame_3->frameRect();
    //qDebug()<<"1"<<rect1;

    //对齐frame
    rect1.translate(ui->frame->pos());
    rect2.translate(ui->frame_2->pos());
    rect3.translate(ui->frame_3->pos());

    //qDebug()<<"2"<<rect1;
    //构建图形
    //获得路径
    //P.ID = 1;
    QImage image1(":/" + QString::number(P.ID) + "/" + QString::number(ImageIndex) + ".jpg");
    QImage image2(":/" + QString::number(P.ID) + "/" + QString::number(ImageIndex + 1) + ".jpg");
    QImage image3(":/icon.png");
    painter.drawImage(rect1,image1);
    painter.drawImage(rect2,image2);
    painter.drawImage(rect3,image3);
}

subwidget::~subwidget()
{
    delete ui;
}



void subwidget::on_progressBar_valueChanged(int value)
{
    if (value == 6)
    {
        connect(this,&subwidget::mySignal,this,&subwidget::on_Next_clicked);
    }

}


