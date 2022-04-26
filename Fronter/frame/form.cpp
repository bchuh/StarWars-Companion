#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    this->setWindowTitle("StarWar-Companion");
    main = new MainWindow(this);
    layout = new QStackedLayout(ui->frame);
    layout->addWidget(this->main);
    layout->addWidget(this->main->getmsubwindow());

    //layout->setCurrentWidget(this->main);
    connect(this->main, SIGNAL(subwindowshow()), this, SLOT(subwindowshow()));
    connect(this->main->getmsubwindow(), SIGNAL(returnSignal()), this, SLOT(mainshow()));
}

Form::~Form()
{
    delete ui;
}

MainWindow* Form::getmain()
{
    return this->main;
}

void Form::subwindowshow()
{
    //std::cout<<"now page is "<<layout->currentIndex()<<std::endl;
    layout->setCurrentWidget(this->main->getmsubwindow());
}

void Form::mainshow()
{
    //std::cout<<"now page is "<<layout->currentIndex()<<std::endl;
    layout->setCurrentWidget(this->main);
    this->main->continue_run();
}

