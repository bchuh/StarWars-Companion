#pragma once

#include <QMainWindow>
#include <QPainter>
#include <QImage>
#include <QDebug>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class subwidget; }
QT_END_NAMESPACE

class subwidget : public QMainWindow
{
    Q_OBJECT

public:
    subwidget(QWidget *parent = nullptr);
    ~subwidget();

private slots:

    void on_Previous_clicked();

    void on_Next_clicked();

    void on_Back_clicked();

private:
    //图像事件处理函数(虚函数)
    void paintEvent(QPaintEvent *);
    void PicChange();
private:
    Ui::subwidget *ui;
    int ID_index; //文件的索引
    int P_index; //图片的索引
};
