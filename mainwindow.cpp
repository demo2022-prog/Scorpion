#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>

#include <BusinessLogic.h>

#include "MainMenu.h"
#include "ViewDokuments.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    MainWindow::setWindowTitle(captionWindow);
    MainWindow::setWindowIcon(QIcon(iconWindow));
    MainWindow::setWindowState(Qt::WindowMaximized);

    // Инициализация компонентов
    businessLogic = new BusinessLogic(this);
    mainMenu = new MainMenu(this);
    viewDockuments = new MdiArea(this);


    // Размещение графических компонентов
    auto mainWgt = new QWidget(this);
    auto mainLayout = new QVBoxLayout(this);

    mainLayout->addWidget(mainMenu);
    mainLayout->addWidget(viewDockuments);

    mainWgt->setLayout(mainLayout);
    setCentralWidget(mainWgt);

    // Связи компонентов
    connect(mainMenu,SIGNAL(about()),businessLogic, SLOT(showAbout()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
