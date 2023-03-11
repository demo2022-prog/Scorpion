#include "MainMenu.h"

#include <QMenuBar>
//#include <QIcon>
#include <QShortcut>

#include <QDebug>

MainMenu::MainMenu(QWidget *parent): QWidget(parent)
{
    //resize(50,50);

    menuBar = new QMenuBar(this);

    auto fileMenu = new QMenu(tr("File"), menuBar);

    auto action = addAction(fileMenu, tr("&New File\tCtrl+N"), "Ctrl+N");
    action->setIcon(QIcon(":/images/Icons/new.png"));
    connect(action, SIGNAL(triggered()), this, SLOT(onNewFile()));

    action = addAction(fileMenu, tr("&Open File\tCtrl+O"), "Ctrl+O");
    action->setIcon(QIcon(":/images/Icons/open.png"));
    connect(action, SIGNAL(triggered()), this, SLOT(onOpenFile()));

    fileMenu->addSeparator();

    action = addAction(fileMenu, tr("&Save File\tCtrl+S"), "Ctrl+S");
    action->setIcon(QIcon(":/images/Icons/save.png"));
    connect(action, SIGNAL(triggered()), this, SLOT(onSaveFile()));

    action = addAction(fileMenu, tr("&Save File As"), "");
    action->setIcon(QIcon(":/images/Icons/SaveAs.png"));
    connect(action, SIGNAL(triggered()), this, SLOT(onSaveFileAs()));

    fileMenu->addSeparator();

    action = addAction(fileMenu, tr("&Open_in_storage\tAlt+O"), "Alt+O");
    //action->setIcon(QIcon("qrc:/images/Icons/new.png"));
    connect(action, SIGNAL(triggered()), this, SLOT(onOpenInStorage()));

    action = addAction(fileMenu, tr("&Save_in_storage\tAlt+S"), "Alt+S");
    //action->setIcon(QIcon("qrc:/images/Icons/new.png"));
    connect(action, SIGNAL(triggered()), this, SLOT(onSaveInStorage()));

    fileMenu->addSeparator();

    action = addAction(fileMenu, tr("&Exit\tCtrl+Q"), "Ctrl+Q");
    action->setIcon(QIcon(":/images/Icons/exit.png"));
    connect(action, SIGNAL(triggered()), this, SLOT(onExit()));

    menuBar->addMenu(fileMenu);

    auto toolsMenu = new QMenu(tr("Tools"), menuBar);

    action = addAction(toolsMenu, tr("&Parametrs"));
    action->setIcon(QIcon(":/images/Icons/settings.png"));
    connect(action, SIGNAL(triggered()), this, SLOT(onParameters()));

    action = addAction(toolsMenu, tr("&Printer\tCtrl+P"), "Ctrl+P");
    action->setIcon(QIcon(":/images/Icons/printer.png"));
    connect(action, SIGNAL(triggered()), this, SLOT(onPrinter()));

    menuBar->addMenu(toolsMenu);

    auto formattingMenu = new QMenu(tr("Formatting"), menuBar);

    action = addAction(formattingMenu, tr("&Copy"), "");
    action->setIcon(QIcon(":/images/Icons/copy.png"));
    connect(action, SIGNAL(triggered()), this, SLOT(onCopy()));

    action = addAction(formattingMenu, tr("&Paste"), "");
    action->setIcon(QIcon(":/images/Icons/paste.png"));
    connect(action, SIGNAL(triggered()), this, SLOT(onPaste()));

    action = addAction(formattingMenu, tr("&Cut"), "");
    action->setIcon(QIcon(":/images/Icons/cut.png"));
    connect(action, SIGNAL(triggered()), this, SLOT(onCut()));

    action = addAction(formattingMenu, tr("&Copy Font"), "");
    action->setIcon(QIcon(":/images/Icons/typographyCopyUp.png"));
    connect(action, SIGNAL(triggered()), this, SLOT(onCopyFont()));

    action = addAction(formattingMenu, tr("&Set Copy Font"), "");
    action->setIcon(QIcon(":/images/Icons/typographyCopy.png"));
    connect(action, SIGNAL(triggered()), this, SLOT(onSetCopyFont()));

    action = addAction(formattingMenu, tr("&Select Font"), "");
    action->setIcon(QIcon(":/images/Icons/typography.png"));
    connect(action, SIGNAL(triggered()), this, SLOT(onSelectFont()));

    action = addAction(formattingMenu, tr("&Select Dedicated Font"), "");
    action->setIcon(QIcon(":/images/Icons/typographyMouse.png"));
    connect(action, SIGNAL(triggered()), this, SLOT(onSelectDedicatedFont()));

    action = addAction(formattingMenu, tr("&Change Font Color"), "");
    action->setIcon(QIcon(":/images/Icons/font_color.png"));
    connect(action, SIGNAL(triggered()), this, SLOT(onChangeFontColor()));

    formattingMenu->addSeparator();

    action = addAction(formattingMenu, tr("&Alignment Left"), "");
    action->setIcon(QIcon(":/images/Icons/textLeft.png"));
    connect(action, SIGNAL(triggered()), this, SLOT(onAlignmentLeft()));

    action = addAction(formattingMenu, tr("&Alignment Center"), "");
    action->setIcon(QIcon(":/images/Icons/textCenter.png"));
    connect(action, SIGNAL(triggered()), this, SLOT(onAlignmentCenter()));

    action = addAction(formattingMenu, tr("&Alignment Right"), "");
    action->setIcon(QIcon(":/images/Icons/textRight.png"));
    connect(action, SIGNAL(triggered()), this, SLOT(onAlignmentRight()));

    menuBar->addMenu(formattingMenu);

    auto helpMenu = new QMenu(tr("Help"), menuBar);

    action = addAction(helpMenu, tr("&About"));
    action->setIcon(QIcon(":/images/Icons/about.png"));
    connect(action, SIGNAL(triggered()), this, SLOT(onAbout()));

    menuBar->addMenu(helpMenu);

}


QAction* MainMenu::addAction(QMenu *menu, const QString &name, const QString &shortcut)
{
    auto action = new QAction(name, menu);
    action->setShortcut(QKeySequence(shortcut));
    menu->addAction(action);

    return action;
}

// File
void MainMenu::onNewFile()
{
    emit newFile();
}

void MainMenu::onOpenFile()
{
    emit openFile();
}

void MainMenu::onSaveFile()
{
    emit saveFile();
}

void MainMenu::onSaveFileAs()
{
    emit saveFileAs();
}

void MainMenu::onOpenInStorage()
{
    emit openInStorage();
}

void MainMenu::onSaveInStorage()
{
    emit saveInStorage();
}

void MainMenu::onExit()
{
    emit exit();
}

// Tools
void MainMenu::onParameters()
{
    emit parameters();
}

void MainMenu::onPrinter()
{
    emit printer();
}

//Formatting
void MainMenu::onCopyFont()
{
    emit copyFont();
}

void MainMenu::onSetCopyFont()
{
    emit setCopyFont();
}

void MainMenu::onSelectFont()
{
    emit selectFont();
}

void MainMenu::onSelectDedicatedFont()
{
    emit selectDedicatedFont();
}

void MainMenu::onChangeFontColor()
{
    emit changeFontColor();
}

void MainMenu::onAlignmentLeft()
{
    emit alignmentLeft();
}

void MainMenu::onAlignmentCenter()
{
    emit alignmentCenter();
}

void MainMenu::onAlignmentRight()
{
    emit alignmentRight();
}

void MainMenu::onCopy()
{
    emit copy();
}

void MainMenu::onPaste()
{
    emit paste();
}

void MainMenu::onCut()
{
    emit cut();
}

// Help
void MainMenu::onAbout()
{
    emit about();
}


