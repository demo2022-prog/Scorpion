#include "toolbar.h"

#include <QToolBar>

#include <QDebug>

ToolBar::ToolBar(QWidget *parent): QWidget(parent)
{

    toolBar = new QToolBar(this);

//    auto fileIcon = new    QMenu(tr("File"), toolBar);

    toolBar->addAction(QIcon(),"New File");

//    auto action = addAction(fileMenu, tr("&New File\tCtrl+N"), "Ctrl+N");
//    action->setIcon(QIcon(":/images/Icons/new.png"));
//    connect(action, SIGNAL(triggered()), this, SLOT(onNewFile()));

//    action = addAction(fileMenu, tr("&Open File\tCtrl+O"), "Ctrl+O");
//    action->setIcon(QIcon(":/images/Icons/open.png"));
//    connect(action, SIGNAL(triggered()), this, SLOT(onOpenFile()));

//    action = addAction(fileMenu, tr("&Save File\tCtrl+S"), "Ctrl+S");
//    action->setIcon(QIcon(":/images/Icons/save.png"));
//    connect(action, SIGNAL(triggered()), this, SLOT(onSaveFile()));

//    action = addAction(fileMenu, tr("&Save FileAs"), "");
//    action->setIcon(QIcon(":/images/Icons/SaveAs.png"));
//    connect(action, SIGNAL(triggered()), this, SLOT(onSaveFileAs()));

//    action = addAction(fileMenu, tr("&Open_in_storage\tAlt+O"), "Alt+O");
//    //action->setIcon(QIcon("qrc:/images/Icons/new.png"));
//    connect(action, SIGNAL(triggered()), this, SLOT(onOpenInStorage()));

//    action = addAction(fileMenu, tr("&Save_in_storage\tAlt+S"), "Alt+S");
//    //action->setIcon(QIcon("qrc:/images/Icons/new.png"));
//    connect(action, SIGNAL(triggered()), this, SLOT(onSaveInStorage()));

//    action = addAction(fileMenu, tr("&Exit\tCtrl+Q"), "Ctrl+Q");
//    action->setIcon(QIcon(":/images/Icons/exit.png"));
//    connect(action, SIGNAL(triggered()), this, SLOT(onExit()));

//    menuBar->addMenu(fileMenu);

//    auto toolsMenu = new QMenu(tr("Tools"), menuBar);

//    action = addAction(toolsMenu, tr("&Parametrs"));
//    action->setIcon(QIcon(":/images/Icons/settings.png"));
//    connect(action, SIGNAL(triggered()), this, SLOT(onParametrs()));

//    action = addAction(toolsMenu, tr("&Printer\tCtrl+P"), "Ctrl+P");
//    action->setIcon(QIcon(":/images/Icons/printer.png"));
//    connect(action, SIGNAL(triggered()), this, SLOT(onPrinter()));

//    menuBar->addMenu(toolsMenu);

//    auto helpMenu = new QMenu(tr("Help"), menuBar);

//    action = addAction(helpMenu, tr("&About"));
//    action->setIcon(QIcon(":/images/Icons/about.png"));
//    connect(action, SIGNAL(triggered()), this, SLOT(onAbout()));

//    menuBar->addMenu(helpMenu);

}

void ToolBar::onNewFile()
{
    emit newFile();
}

void ToolBar::onOpenFile()
{
    emit openFile();
}

void ToolBar::onSaveFile()
{
    emit saveFile();
}

void ToolBar::onOpenInStorage()
{
    emit openInStorage();
}

void ToolBar::onSaveInStorage()
{
    emit saveInStorage();
}

void ToolBar::onPrinter()
{
    emit printer();
}


//QAction* MainMenu::addAction(QMenu *menu, const QString &name, const QString &shortcut)
//{
//    auto action = new QAction(name, menu);
//    action->setShortcut(QKeySequence(shortcut));
//    menu->addAction(action);

//    return action;
//}

//// File
//void MainMenu::onNewFile()
//{
//    emit newFile();
//}

//void MainMenu::onOpenFile()
//{
//    emit openFile();
//}

//void MainMenu::onSaveFile()
//{
//    emit saveFile();
//}

//void MainMenu::onSaveFileAs()
//{
//    emit saveFileAs();
//}

//void MainMenu::onOpenInStorage()
//{
//    emit openInStorage();
//}

//void MainMenu::onSaveInStorage()
//{
//    emit saveInStorage();
//}

//void MainMenu::onExit()
//{
//    emit exit();
//}

//// Tools
//void MainMenu::onParametrs()
//{
//    emit parametrs();
//}

//void MainMenu::onPrinter()
//{
//    emit printer();
//}

//// Help
//void MainMenu::onAbout()
//{
//    emit about();
//}
