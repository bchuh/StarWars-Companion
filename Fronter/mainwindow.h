#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <opencv2\opencv.hpp>
#include "C:\Users\zhuze\OneDrive - Macau University of Science and Technology\Bill\3th-2\Software_proj_manage\StarWars-Companion\Camera_module\camera_module.h"

//连接cam模块步骤：1.项目右键, add existing directory, 选摄像头模块的文件夹
//2. 把上面的include路径改为你电脑上的camera_module.h的绝对路径

//#include <imgproc\types_c.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void run();

private:
    Ui::MainWindow *ui;
    QGraphicsPixmapItem * m_imageItem;
    Camera*cam;
};
#endif // MAINWINDOW_H
