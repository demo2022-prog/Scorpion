#include "MainMenu.h"

#include <QMenuBar>
#include <QShortcut>

#include <QDebug>

MainMenu::MainMenu(QWidget *parent): QWidget(parent)
{
    //resize(50,50);

    menuBar = new QMenuBar(this);

    auto fileMenu = new QMenu(tr("File"), menuBar);

    auto action = addAction(fileMenu, tr("&New File\tCtrl+N"), "Ctrl+N");
    connect(action, SIGNAL(triggered()), this, SLOT(onNewFile()));

    action = addAction(fileMenu, tr("&Open File\tCtrl+O"), "Ctrl+O");
    connect(action, SIGNAL(triggered()), this, SLOT(onOpenFile()));

    action = addAction(fileMenu, tr("&Save File\tCtrl+S"), "Ctrl+S");
    connect(action, SIGNAL(triggered()), this, SLOT(onSaveFile()));

    action = addAction(fileMenu, tr("&Open_in_storage\tAlt+O"), "Alt+O");
    connect(action, SIGNAL(triggered()), this, SLOT(onOpenInStorage()));

    action = addAction(fileMenu, tr("&Save_in_storage\tAlt+S"), "Alt+S");
    connect(action, SIGNAL(triggered()), this, SLOT(onSaveInStorage()));

    action = addAction(fileMenu, tr("&Exit\tCtrl+Q"), "Ctrl+Q");
    connect(action, SIGNAL(triggered()), this, SLOT(onExit()));

    menuBar->addMenu(fileMenu);

    auto helpMenu = new QMenu(tr("Help"), menuBar);

    action = addAction(helpMenu, tr("&About"));
    //connect(action, SIGNAL(triggered()), this, SLOT(nCreateFile));

    menuBar->addMenu(helpMenu);

}


QAction* MainMenu::addAction(QMenu *menu, const QString &name, const QString &shortcut)
{
    auto action = new QAction(name, menu);
    action->setShortcut(QKeySequence(shortcut));
    menu->addAction(action);

    return action;
}

void MainMenu::onNewFile()
{
    qDebug() << "DEBUG:MainMenu::onNewFile()";
}

void MainMenu::onOpenFile()
{
    qDebug() << "DEBUG:MainMenu::onOpenFile()";
}

void MainMenu::onSaveFile()
{
    qDebug() << "DEBUG:MainMenu::onSaveFile()";
}

void MainMenu::onOpenInStorage()
{
    qDebug() << "DEBUG:MainMenu::onOpenInStorage()";
}

void MainMenu::onSaveInStorage()
{
    qDebug() << "DEBUG:MainMenu::onSaveInStorage()";
}

void MainMenu::onExit()
{
    qDebug() << "DEBUG:MainMenu::onExit()";
}


