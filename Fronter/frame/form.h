#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QStackedLayout>
#include "mainwindow.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    MainWindow* getmain();

    ~Form();

private slots:
    void subwindowshow();
    void mainshow();

private:
    Ui::Form *ui;
    QStackedLayout* layout;
    MainWindow* main;
};

#endif // FORM_H
