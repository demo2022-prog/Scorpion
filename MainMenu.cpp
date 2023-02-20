#include "MainMenu.h"

#include <QMenuBar>

#include <QDebug>

MainMenu::MainMenu(QWidget *parent): QWidget(parent)
{
    //resize(50,50);

    menuBar = new QMenuBar(this);

    auto fileMenu = new QMenu(tr("File"), menuBar);

    auto createFile = new QAction(tr("&Create File\tCtrl+N"), menuBar);

    connect(createFile, SIGNAL(triggered(bool)), this, SLOT(onCreateFile(bool)));

    fileMenu->addAction(createFile);


    menuBar->addMenu(fileMenu);

    //////////////////////////////////////

    auto helpMenu = new QMenu(tr("Help"), menuBar);
    menuBar->addMenu(helpMenu);

}

void MainMenu::onCreateFile(bool)
{
    qDebug() << "DEBUG:MainMenu::onCreateFile(bool)";
}
