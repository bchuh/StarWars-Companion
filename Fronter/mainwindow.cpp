#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QScreen>
#include <QString>

std::vector<string> names{ "Admiral Ackbar", "Admiral Piett", "Anakin Skywalker", "Bail Organa", "BB-8", "Bib Fortuna", "Boba Fett", "Bodhi Rook", "C-3PO", "Captain Phasma", "Cassian Andor", "Chewbacca", "Dark Sidious", "Darth Maul", "Darth Vader", "Finn (FN-2187)", "General Grievous", "General Hux", "Grand Moff Tarkin", "Greedo", "Han Solo", "Jabba the Hutt", "Jango Fett", "Jar Jar Binks", "Jyn Erso", "K-2SO", "Kenobi", "Kylo Ren", "Lando Calrissian", "Luke Skywalker", "Mace Windu", "Maz Kanata", "Nien Nunb", "Obi-Wan", "Orson Krennic", "Padmé Amidala", "Poe Dameron", "Princess Leia Organa", "Qi'ra", "Qui-Gon Jinn", "R2-D2", "Rey", "Rose Tico", "Saw Gerrera", "Supreme Leader Snoke", "Tobias Beckett", "Vice-Admiral Holdo", "Watto", "Wedge Antilles", "Wicket W. Warrick", "Yoda" };

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stop = -1;
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_2_clicked()));
    //画布
    auto m_scene = new QGraphicsScene();
    this->m_imageItem = new QGraphicsPixmapItem();
    //场景增加画布
    m_scene->addItem(m_imageItem);
    ui->graphicsView->setScene(m_scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->show();
    this->cam = Camera::getInstance();
    this->model = DLmodule::getInstance("C:\\Users\\zhuze\\OneDrive - Macau University of Science and Technology\\Bill\\3th-2\\Software_proj_manage\\StarWars-Companion\\DL_module");
    this->subWindow=new subwidget(this, "C:\\Users\\zhuze\\OneDrive - Macau University of Science and Technology\\Bill\\3th-2\\Software_proj_manage\\StarWars-Companion\\Database\\star_war.db");
    subWindow->hide();
    connect(subWindow, SIGNAL(mySignal()), this, SLOT(continue_run()));


}
void MainWindow::run() {


    QTime dieTime;
    auto size = ui->graphicsView->size();
    while (isRunning)
    {
        frame = cam->nextFrame(ui->graphicsView->width(), ui->graphicsView->height());
        result = model->classify(frame);
        cv::resize(frame, frame, cv::Size(size.width(), size.height()));
       // std::cout << names[result] << endl;//数据库链接更改
        //场景
        size = ui->graphicsView->size();
        //控件绑定场景

        //记录绘制图片
        //m_frameShow = frame.clone();
        cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);
        QImage  img2(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
        //m_imageItem->setPixmap(QPixmap::fromImage(QImage((const unsigned char*)image.data, image.cols, image.rows, QImage::Format::Format_RGB888)));
        m_imageItem->setPixmap(QPixmap::fromImage(img2));
        dieTime = QTime::currentTime().addMSecs(20);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 20);
        if (stop == 1000)
        {
            Camera::Destory();
            DLmodule::Destory();
            std::cout << "finished by user\n";
            break;
        }
        //update();

    }

}

MainWindow::~MainWindow()
{
    this->cam->Destory();
    this->model->Destory();
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    stop = 1000;
}

void MainWindow::on_pushButton_clicked()
{
    /*
    cout<<"clicked"<<endl;
    cout<<result<<endl;
    subWindow->show();
    subWindow->setID(this->result);
    run();
    */
    auto result = model->detect(frame);
    isRunning=false;
    cout<<result.size()<<endl;
    if(result.size()>0){
        auto item = result.at(0);
        auto rect=item.box;
        cv::Point center_of_rect = (rect.br() + rect.tl())*0.5;
        auto buttom = new QPushButton(ui->graphicsView);//这个buttom只是演示用法，建议保存好创建的buttom的指针
        buttom->move(center_of_rect.x, center_of_rect.y);
        buttom->show();
        update();
    }else{
        cout<<"no result!"<<endl;
        isRunning=true;
        run();
    }



}

void MainWindow::continue_run(){
    run();
}
