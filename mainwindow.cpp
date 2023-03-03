#include "mainwindow.h"

#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>

#include <BusinessLogic.h>
#include <MainMenu.h>
#include <ViewDokuments.h>
#include <StatusBar.h>

#include "toolbar.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // Инициализация компонентов
    businessLogic = new BusinessLogic(this);
    mainMenu = new MainMenu(this);
    viewDockuments = new ViewDokuments(this);
    statusBar = new StatusBar(this);

    toolBar = new ToolBar(this);

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

    connect(mainMenu,SIGNAL(alignmentLeft()), viewDockuments, SLOT(onAlignmentLeft()));
    connect(mainMenu,SIGNAL(alignmentCenter()), viewDockuments, SLOT(onAlignmentCenter()));
    connect(mainMenu,SIGNAL(alignmentRight()), viewDockuments, SLOT(onAlignmentRight()));
    connect(viewDockuments, SIGNAL(alignmentLeft(Document*)),businessLogic, SLOT(alignmentLeft(Document*)));
    connect(viewDockuments, SIGNAL(alignmentCenter(Document*)),businessLogic, SLOT(alignmentCenter(Document*)));
    connect(viewDockuments, SIGNAL(alignmentRight(Document*)),businessLogic, SLOT(alignmentRight(Document*)));

    connect(mainMenu,SIGNAL(copy()), viewDockuments, SLOT(onCopy()));
    connect(mainMenu,SIGNAL(paste()), viewDockuments, SLOT(onPaste()));
    connect(mainMenu,SIGNAL(cut()), viewDockuments, SLOT(onCut()));
    connect(viewDockuments, SIGNAL(copy(Document*)),businessLogic, SLOT(copy(Document*)));
    connect(viewDockuments, SIGNAL(paste(Document*)),businessLogic, SLOT(paste(Document*)));
    connect(viewDockuments, SIGNAL(cut(Document*)),businessLogic, SLOT(cut(Document*)));

    connect(viewDockuments, SIGNAL(textData(Document*)),businessLogic, SLOT(onTextData(Document*)));
    connect(businessLogic, SIGNAL(textData(QString,QString)), statusBar, SLOT(showTextData(QString,QString)));


    connect(mainMenu,SIGNAL(saveFile()),dynamic_cast<QWidget*>(viewDockuments), SLOT(saveFile()));
    connect(mainMenu,SIGNAL(saveFileAs()),dynamic_cast<QWidget*>(viewDockuments), SLOT(saveFileAs()));
    connect(viewDockuments, SIGNAL(saveFile(Document*)),businessLogic, SLOT(saveFile(Document*)));
    connect(viewDockuments, SIGNAL(saveFileAs(Document*)),businessLogic, SLOT(saveFileAs(Document*)));

    connect(toolBar,&ToolBar::newFile,businessLogic, &BusinessLogic::createNewDocument);
    connect(toolBar,&ToolBar::openFile,businessLogic, &BusinessLogic::openFile);
    connect(toolBar,SIGNAL(saveFile()),viewDockuments, SLOT(saveFile()));

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

    toolBar->setMinimumHeight(40);
    //toolBar->setStyleSheet(QString("QWidget {margin: 0px;}"));
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
