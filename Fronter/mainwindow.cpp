#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    QGraphicsScene * m_scene;
    //画布
    m_scene = new QGraphicsScene();
    this->m_imageItem = new QGraphicsPixmapItem();
    //场景增加画布
    m_scene->addItem(m_imageItem);
    ui->graphicsView->setScene(m_scene);
    ui->graphicsView->show();
    this->cam=Camera::getInstance();

}
void MainWindow::run(){
    cv::Mat image;
    QTime dieTime;
    while(true)
    {
        image=cam->nextFrame();
        //cv::resize(image,image,cv::Size(image.cols/4*4,image.rows/4*4));
        //场景

        //控件绑定场景

        //记录绘制图片
        //m_imageShow = image.clone();
        cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
        QImage  img2(image.data,image.cols,image.rows, image.step, QImage::Format_RGB888);
        //m_imageItem->setPixmap(QPixmap::fromImage(QImage((const unsigned char*)image.data, image.cols, image.rows, QImage::Format::Format_RGB888)));
        m_imageItem->setPixmap(QPixmap::fromImage(img2));
        dieTime=QTime::currentTime().addMSecs(80);
                while(QTime::currentTime()<dieTime)
                    QCoreApplication::processEvents(QEventLoop::AllEvents,80);
        //update();
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
