#include "subwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    subwidget w;
    //mainwindow 可以调用 subwidget
    w.show();
    return a.exec();
}
