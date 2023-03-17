#include "mainwindow.h"

#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>

#include <BusinessLogic.h>
#include <MainMenu.h>
#include <ViewDokuments.h>
#include <StatusBar.h>
#include <AboutWidget.h>
#include <ParametersWidget.h>
#include <toolbar.h>

#include <QPrintDialog>

#include <QPrinter>




MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // Инициализация компонентов
    businessLogic = new BusinessLogic(this);
    mainMenu = new MainMenu(this);
    viewDockuments = new ViewDokuments(this);
    statusBar = new StatusBar(this);
    toolBar = new ToolBar(this);
    aboutWgt = new AboutWidget();
    parametersWgt = new ParametersWidget();

    // Размещение графических компонентов
    setupGui();

    // Связи компонентов
    connect(mainMenu,SIGNAL(about()),aboutWgt, SLOT(show()));
    connect(mainMenu,SIGNAL(parameters()),parametersWgt, SLOT(show()));
    connect(mainMenu,SIGNAL(printer()),businessLogic, SLOT(printer()));

    connect(mainMenu,SIGNAL(newFile()),businessLogic, SLOT(createNewDocument()));
    connect(mainMenu,SIGNAL(openFile()),businessLogic, SLOT(openFile()));

    connect(mainMenu,SIGNAL(saveFile()), businessLogic, SLOT(saveFile()));
    connect(mainMenu,SIGNAL(saveFileAs()), businessLogic, SLOT(saveFileAs()));

    connect(mainMenu,SIGNAL(alignmentLeft()), businessLogic, SLOT(alignmentLeft()));
    connect(mainMenu,SIGNAL(alignmentCenter()), businessLogic, SLOT(alignmentCenter()));
    connect(mainMenu,SIGNAL(alignmentRight()), businessLogic, SLOT(alignmentRight()));

    connect(mainMenu,SIGNAL(copyFont()), businessLogic, SLOT(copyFont()));
    connect(mainMenu,SIGNAL(setCopyFont()), businessLogic, SLOT(setCopyFont()));

    connect(mainMenu,SIGNAL(selectFont()), businessLogic, SLOT(selectFont()));
    connect(mainMenu,SIGNAL(selectDedicatedFont()), businessLogic, SLOT(selectDedicatedFont()));
    connect(mainMenu,SIGNAL(changeFontColor()), businessLogic, SLOT(changeFontColor()));

    connect(mainMenu,SIGNAL(copy()), businessLogic, SLOT(copy()));
    connect(mainMenu,SIGNAL(paste()), businessLogic, SLOT(paste()));
    connect(mainMenu,SIGNAL(cut()), businessLogic, SLOT(cut()));

    connect(mainMenu,SIGNAL(changeView(QString)), viewDockuments, SLOT(changeView(QString)));

    connect(mainMenu,SIGNAL(exit()), this, SLOT(close()));

    connect(toolBar,&ToolBar::newFile, businessLogic, &BusinessLogic::createNewDocument);
    connect(toolBar,&ToolBar::openFile, businessLogic, &BusinessLogic::openFile);
    connect(toolBar,SIGNAL(saveFile()), businessLogic, SLOT(saveFile()));

    connect(toolBar,&ToolBar::copy, businessLogic, &BusinessLogic::copy);
    connect(toolBar,&ToolBar::paste, businessLogic, &BusinessLogic::paste);
    connect(toolBar,&ToolBar::cut, businessLogic, &BusinessLogic::cut);

    connect(toolBar,&ToolBar::alignmentLeft, businessLogic, &BusinessLogic::alignmentLeft);
    connect(toolBar,&ToolBar::alignmentCenter, businessLogic, &BusinessLogic::alignmentCenter);
    connect(toolBar,&ToolBar::alignmentRight, businessLogic, &BusinessLogic::alignmentRight);

    connect(toolBar,SIGNAL(copyFont()), businessLogic, SLOT(copyFont()));
    connect(toolBar,SIGNAL(setCopyFont()), businessLogic, SLOT(setCopyFont()));

    connect(toolBar,&ToolBar::selectFont, businessLogic, &BusinessLogic::selectFont);
    connect(toolBar,&ToolBar::selectDedicatedFont, businessLogic, &BusinessLogic::selectDedicatedFont);
    connect(toolBar,&ToolBar::printer, businessLogic, &BusinessLogic::printer);

    connect(toolBar,SIGNAL(changeView(QString)), viewDockuments, SLOT(changeView(QString)));

    connect(viewDockuments, SIGNAL(activeDocument(Document*)),businessLogic, SLOT(activeDocument(Document*)));

    connect(businessLogic, SIGNAL(newDocument(Document*)), viewDockuments, SLOT(addDocument(Document*)));

    connect(businessLogic, SIGNAL(textData(QString,QString)), statusBar, SLOT(showTextData(QString,QString)));
}

MainWindow::~MainWindow()
{
    delete parametersWgt;
    delete aboutWgt;
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

    toolBar->setMinimumHeight(40);
    mainLayout->addWidget(toolBar);

    auto viewWgt = dynamic_cast<QWidget*>(viewDockuments);
    viewWgt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    mainLayout->addWidget(viewWgt);

    statusBar->setMinimumHeight(35);
    statusBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    mainLayout->addWidget(statusBar);

    mainWgt->setLayout(mainLayout);
    this->setCentralWidget(mainWgt);
}
