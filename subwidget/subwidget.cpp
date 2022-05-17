#include "subwidget.h"
#include "ui_subwidget.h"
#include <QDebug>
#include <QString>
#include <iostream>
#define DIR "C:/Users/YRY/Desktop/SarWar/SarWar/Fronter/image/"

using namespace std;
subwidget::subwidget(QWidget *parent, std::string db_path)
    : QMainWindow(parent)
    , ui(new Ui::subwidget)
{
    ui->setupUi(this);

    //setFixedSize(900,700);
    //设置按钮字体颜色
    //QPushButton *pushbutton = new QPushButton(this);
    //ui->Previous->setAutoFillBackground(true);
    ui->Previous->setFlat(true);
    //ui->Next->setAutoFillBackground(true);
    ui->Next->setFlat(true);
    //ui->Back->setAutoFillBackground(true);
    ui->Back->setFlat(true);

    //逐个调整
    ui->frame_3->setStyleSheet("border:0px");
    ui->frame_2->setStyleSheet("border:0px");
    ui->frame->setStyleSheet("border:0px");
    ui->lineEdit->setStyleSheet("border:0px groove gray;border-radius:10px;padding:2px 4px;background-color: rgb(145, 145, 145);color:rgb(255,255,255);font: 18pt");
    ui->lineEdit_2->setStyleSheet("border:0px groove gray;border-radius:10px;padding:2px 4px;background-color: rgb(145, 145, 145);color:rgb(255,255,255);font: 18pt");
    //ui->lineEdit_3->setStyleSheet("border:0px groove gray;border-radius:10px;padding:2px 4px;background-color: rgb(145, 145, 145);color:rgb(255,255,255);font: 13pt");
    ui->label->setStyleSheet("color:rgb(255,255,255);font: 16pt");
    ui->label_2->setStyleSheet("color:rgb(255,255,255);font: 16pt");
    //ui->label_3->setStyleSheet("color:rgb(255,255,255);font: 15pt");
    ui->Previous->setStyleSheet("color:rgb(255,255,255);font: 15pt");
    ui->Back->setStyleSheet("color:rgb(255,255,255);font: 15pt");
    ui->Next->setStyleSheet("color:rgb(255,255,255);font: 15pt");
    ui->scrollArea_2->setStyleSheet("border:2px groove black;border-radius:10px;padding:4px 6px;background-color: rgb(145, 145, 145);border-color: rgb(255, 203, 0);");
    ui->textEdit->setStyleSheet("color:rgb(255,255,255);font: 18pt");
    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    //ui->lineEdit_3->setReadOnly(true);
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
    //cout<<dbModule->nameQuery(2)<<endl;

}

void subwidget::setID(int id[])
{
   cout<<"subwidget:"<<endl;
   //cout<<dbModule->nameQuery(3);
   //this->setInfo(id, 0, "aa", "N/A");
   //遍历数组 设置按钮图片
   QString dir = DIR;
   QString imagePath1 = dir + QString::number(id[0]) + "/1.jpg";
   QString imagePath2 = dir + QString::number(id[1]) + "/1.jpg";
   QString imagePath3 = dir + QString::number(id[2]) + "/1.jpg";
   //不知道怎么写
   ui->Character1->setStyleSheet("QPushButton{border-image: url(\"" + dir + QString::number(id[0]) + "/1.jpg\") ;color: white;border-radius:16px;} QPushButton:hover{border: 10px double rgb(0, 0, 0)};border-radius:16px;");
   ui->Character2->setStyleSheet("QPushButton{border-image: url(\"" + dir + QString::number(id[1]) + "/1.jpg\") ;color: white;border-radius:16px;} QPushButton:hover{border: 10px double rgb(0, 0, 0)};border-radius:16px;");
   ui->Character3->setStyleSheet("QPushButton{border-image: url(\"" + dir + QString::number(id[2]) + "/1.jpg\") ;color: white;border-radius:16px;} QPushButton:hover{border: 10px double rgb(0, 0, 0)};border-radius:16px;");

   ui->Character1->setFixedSize(QSize(150, 150));
   ui->Character2->setFixedSize(QSize(150, 150));
   ui->Character3->setFixedSize(QSize(150, 150));
   for(int i = 0;i < 3;i++)
           idArr[i] = id[i];
   selectCharacter(0);

}

void subwidget::selectCharacter(int num)
{
    char* temp_name = dbModule->nameQuery(idArr[num]);
    char* temp_info = dbModule->infoQuery(idArr[num]);
    if(temp_name == nullptr)
    {
         cout<<"Error:nameQuery return NULL!"<<endl;
         return;
    }
    else if(temp_info == nullptr)
    {
        cout<<"Error:infoQuery return NULL!"<<endl;
        return;
    }
    else
    {
        string name = temp_name;
        string info = temp_info;
        //cout<<dbModule->nameQuery(id);
        this->setInfo(idArr[num], 0, QString::fromStdString(name), QString::fromStdString(info));
    }
}


void subwidget::setInfo(int ID,int Age,QString Name, QString Intro)
{
    idState = true;
    //SQL 查询返回结果
    //当上级跳转信号时设置
    //初始化人物
    P.ID = ID;
    P.Age = Age;
    P.Intro = Intro;
    P.Name = Name;
    ui->lineEdit->setText(QString::number(P.ID));
    ui->lineEdit_2->setText(P.Name);
    //没有年龄  不显示
    //ui->lineEdit_3->setText(QString::number(P.Age));
    ui->textEdit->setText("     " + P.Intro);
    //paintEvent(nullptr);
    idSlot();
}


void subwidget::on_Previous_clicked()
{
    if( --ImageIndex  < 1)
    {
        ImageIndex = 3;
    }
    emit setSignal();
    ui->progressBar->setValue(0);
    update();
}

void subwidget::on_Next_clicked()
{
    if( ++ ImageIndex > 3)
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
    idState = false;
    //hide();
    emit returnSignal();
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
    rect1.setWidth(rect1.height()*1.5);
    QRect rect2 = ui->frame_2->frameRect();
    rect2.setWidth(rect2.height()*1.5);
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
    QImage image1(DIR + QString::number(P.ID) + "/" + QString::number(ImageIndex) + ".jpg");
    QImage image2(DIR + QString::number(P.ID) + "/" + QString::number(ImageIndex + 1) + ".jpg");
    QImage image3(DIR + QString("icon.png"));
    if(cropped_frame!=nullptr){
        painter.drawImage(rect1,*cropped_frame);
        painter.drawImage(rect2,image1);
        painter.drawImage(rect3,image3);
    }

}

subwidget::~subwidget()
{
    delete ui;
}



void subwidget::on_progressBar_valueChanged(int value)
{
    if (value == 6)
    {
        connect(this,&subwidget::picSignal,this,&subwidget::on_Next_clicked);
    }

}

void subwidget::idSlot()
{

    update();
    while(idState)
    {
        connect(this,&subwidget::setSignal,this,&subwidget::idSlot);
        for(int i = 1; i < 7; i ++)
        {
            //延时
               timer = QTime::currentTime().addMSecs(1000);
               while( QTime::currentTime() < timer )
                  QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
               ui->progressBar->setValue(i);
        }
        emit picSignal();
    }
}

void subwidget::on_Character1_clicked()
{
    selectCharacter(0);
}
void subwidget::on_Character2_clicked()
{
    selectCharacter(1);
}
void subwidget::on_Character3_clicked()
{
    selectCharacter(2);
}
