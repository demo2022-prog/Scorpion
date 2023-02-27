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
    setupGui();


    // Связи компонентов
    connect(mainMenu,SIGNAL(about()),businessLogic, SLOT(showAbout()));
    connect(mainMenu,SIGNAL(newFile()),businessLogic, SLOT(createNewDocument()));
    connect(businessLogic, SIGNAL(newDocument(const class Document*)), viewDockuments, SLOT(addDocument(const class Document*)));

    for(int i = 0; i < 10; i++){
        viewDockuments->test();
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupGui()
{
    MainWindow::setWindowTitle(captionWindow);
    MainWindow::setWindowState(Qt::WindowMaximized);

    auto mainWgt = new QWidget(this);

    auto mainLayout = new QVBoxLayout(this);

    mainMenu->setMinimumHeight(25);
    mainLayout->addWidget(mainMenu);

    auto viewWgt = dynamic_cast<QWidget*>(viewDockuments);
    viewWgt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    mainLayout->addWidget(viewWgt);

    mainWgt->setLayout(mainLayout);
    this->setCentralWidget(mainWgt);
}
