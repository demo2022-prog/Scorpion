#include "toolbar.h"

#include <QToolBar>

#include <QDebug>

ToolBar::ToolBar(QWidget *parent): QWidget(parent)
{

    toolBar = new QToolBar(this);

    toolBar->addAction(QIcon(":/images/Icons/new.png"),"New File", this, SLOT(onNewFile()));
    toolBar->addAction(QIcon(":/images/Icons/open.png"),"Open File", this, SLOT(onOpenFile()));
    toolBar->addAction(QIcon(":/images/Icons/save.png"),"Save File", this, SLOT(onSaveFile()));
    toolBar->addSeparator();
    toolBar->addAction(QIcon(":/images/Icons/printer.png"),"Printer", this, SLOT(onPrinter()));
    toolBar->addSeparator();
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

void ToolBar::onPrinter()
{
    emit printer();
}
