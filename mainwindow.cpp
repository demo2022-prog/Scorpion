#include "mainwindow.h"

#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>

#include <BusinessLogic.h>
#include <MainMenu.h>
#include <ViewDokuments.h>
#include <StatusBar.h>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // Инициализация компонентов
    businessLogic = new BusinessLogic(this);
    mainMenu = new MainMenu(this);
    viewDockuments = new ViewDokuments(this);
    statusBar = new StatusBar(this);

    // Размещение графических компонентов
    setupGui();

    // Связи компонентов
    connect(mainMenu,SIGNAL(about()),businessLogic, SLOT(showAbout()));

    connect(mainMenu,SIGNAL(newFile()),businessLogic, SLOT(createNewDocument()));
    connect(mainMenu,SIGNAL(openFile()),businessLogic, SLOT(openFile()));

    connect(businessLogic, SIGNAL(newDocument(Document*)), viewDockuments, SLOT(addDocument(Document*)));

    connect(mainMenu,SIGNAL(saveFile()), viewDockuments, SLOT(onSaveFile()));
    connect(mainMenu,SIGNAL(saveFileAs()), viewDockuments, SLOT(onSaveFileAs()));
    connect(viewDockuments, SIGNAL(saveFile(Document*)),businessLogic, SLOT(saveFile(Document*)));
    connect(viewDockuments, SIGNAL(saveFileAs(Document*)),businessLogic, SLOT(saveFileAs(Document*)));
}

MainWindow::~MainWindow()
{

}


void MainWindow::setupGui()
{
    MainWindow::setWindowTitle(captionWindow);
    MainWindow::setWindowIcon(QIcon(iconWindow));
    MainWindow::setWindowState(Qt::WindowMaximized);

    auto mainWgt = new QWidget(this);

    auto mainLayout = new QVBoxLayout();

    mainMenu->setMinimumHeight(30);
    mainLayout->addWidget(mainMenu);

    auto viewWgt = dynamic_cast<QWidget*>(viewDockuments);
    viewWgt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    mainLayout->addWidget(viewWgt);

    statusBar->setMinimumHeight(30);
    mainLayout->addWidget(statusBar);

    mainWgt->setLayout(mainLayout);
    this->setCentralWidget(mainWgt);
}
