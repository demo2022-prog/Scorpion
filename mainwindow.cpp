#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>

#include "MainMenu.h"
#include "ViewDokuments.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    MainWindow::setWindowTitle(captionWindow);
    MainWindow::setWindowState(Qt::WindowMaximized);

    auto mainWgt = new QWidget(this);
    auto mainLayout = new QVBoxLayout(this);

    mainMenu = new MainMenu(this);
    viewDockuments = new MdiArea(this);

    mainLayout->addWidget(mainMenu);
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
