#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QScreen>
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
    auto size=ui->graphicsView->size();
    QScreen *screen=QGuiApplication::primaryScreen ();
    auto dpi = screen->devicePixelRatio();
    while(true)
    {
        image=cam->nextFrame();
        cv::resize(image,image,cv::Size(size.width()*dpi,size.height()*dpi));
        //场景

        //控件绑定场景

        //记录绘制图片
        //m_imageShow = image.clone();
        cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
        QImage  img2(image.data,image.cols,image.rows, image.step, QImage::Format_RGB888);
        //m_imageItem->setPixmap(QPixmap::fromImage(QImage((const unsigned char*)image.data, image.cols, image.rows, QImage::Format::Format_RGB888)));
        m_imageItem->setPixmap(QPixmap::fromImage(img2));
        dieTime=QTime::currentTime().addMSecs(20);
                while(QTime::currentTime()<dieTime)
                    QCoreApplication::processEvents(QEventLoop::AllEvents,20);
        //update();
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
