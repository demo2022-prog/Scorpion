#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>

#include "ViewDokuments.h"

#include <QPushButton> // вместо MainMenu

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    MainWindow::setWindowTitle(captionWindow);
    MainWindow::setWindowState(Qt::WindowMaximized);

    auto mainWgt = new QWidget(this);
    auto mainLayout = new QVBoxLayout(this);

    auto button = new QPushButton("MainMenu",this); // вместо MainMenu
    viewDockuments = new MdiArea(this);

    mainLayout->addWidget(button); // вместо MainMenu
    mainLayout->addWidget(viewDockuments);

    mainWgt->setLayout(mainLayout);
    setCentralWidget(mainWgt);

    viewDockuments->test();
    viewDockuments->test();
    viewDockuments->test();
    viewDockuments->test();

}

MainWindow::~MainWindow()
{
    delete ui;
}
