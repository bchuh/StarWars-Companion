#include "mainwindow.h"

#include <QScreen>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setAttribute(Qt::WA_DeleteOnClose);
    w.setWindowState(Qt::WindowMaximized);
    w.show();
    w.run();
    return a.exec();

}
