#include "mainwindow.h"

#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>

#include <BusinessLogic.h>
#include <MainMenu.h>
#include <ViewDokuments.h>

#include "toolbar.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // Инициализация компонентов
    businessLogic = new BusinessLogic(this);
    mainMenu = new MainMenu(this);
    viewDockuments = new MdiArea(this);

    toolBar = new ToolBar(this);

    // Размещение графических компонентов
    setupGui();

    // Связи компонентов
    connect(mainMenu,SIGNAL(about()),businessLogic, SLOT(showAbout()));

    connect(mainMenu,SIGNAL(newFile()),businessLogic, SLOT(createNewDocument()));
    connect(mainMenu,SIGNAL(openFile()),businessLogic, SLOT(openFile()));

    connect(businessLogic, SIGNAL(newDocument(Document*)), dynamic_cast<QWidget*>(viewDockuments), SLOT(addDocument(Document*)));

    connect(mainMenu,SIGNAL(saveFile()),dynamic_cast<QWidget*>(viewDockuments), SLOT(saveFile()));
    connect(mainMenu,SIGNAL(saveFileAs()),dynamic_cast<QWidget*>(viewDockuments), SLOT(saveFileAs()));
    connect(dynamic_cast<QWidget*>(viewDockuments), SIGNAL(saveFile(Document*)),businessLogic, SLOT(saveFile(Document*)));
    connect(dynamic_cast<QWidget*>(viewDockuments), SIGNAL(saveFileAs(Document*)),businessLogic, SLOT(saveFileAs(Document*)));

    connect(toolBar,&ToolBar::newFile,businessLogic, &BusinessLogic::createNewDocument);
    connect(toolBar,&ToolBar::openFile,businessLogic, &BusinessLogic::openFile);
    connect(toolBar,SIGNAL(saveFile()),dynamic_cast<QWidget*>(viewDockuments), SLOT(saveFile()));
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

    auto mainLayout = new QVBoxLayout(this);

    mainMenu->setMinimumHeight(25);
    mainLayout->addWidget(mainMenu);

    toolBar->setMinimumHeight(40);
    //toolBar->setStyleSheet(QString("QWidget {margin: 0px;}"));
    mainLayout->addWidget(toolBar);

    auto viewWgt = dynamic_cast<QWidget*>(viewDockuments);
    viewWgt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    mainLayout->addWidget(viewWgt);

    mainWgt->setLayout(mainLayout);
    this->setCentralWidget(mainWgt);
}
