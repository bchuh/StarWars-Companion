#include "frame/form.h"

#include <QScreen>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Form w;
    w.setAttribute(Qt::WA_DeleteOnClose);
    //w.setWindowState(Qt::WindowMaximized);
    w.show();
    w.getmain()->run();
    return a.exec();

}
