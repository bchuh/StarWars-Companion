#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cv::Mat m_imageShow;
    cv::Mat image=cv::imread("C:/Users/YRY/Pictures/cat.png");
    cv::resize(image,image,cv::Size(image.cols/4*4,image.rows/4*4));
    //场景
    QGraphicsScene * m_scene;
    //画布
    QGraphicsPixmapItem * m_imageItem;
    m_scene = new QGraphicsScene();
    m_imageItem = new QGraphicsPixmapItem();
    //场景增加画布
    m_scene->addItem(m_imageItem);
    //控件绑定场景
    ui->graphicsView->setScene(m_scene);
    //记录绘制图片
    //m_imageShow = image.clone();
    cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
    m_imageItem->setPixmap(QPixmap::fromImage(QImage((const unsigned char*)image.data, image.cols, image.rows, QImage::Format::Format_RGB888)));

    ui->graphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
