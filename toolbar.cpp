#include "toolbar.h"

#include <QToolBar>

#include <QDebug>

ToolBar::ToolBar(QWidget *parent): QWidget(parent)
{

    Bar = new QToolBar(this);

    Bar->addAction(QIcon(":/images/Icons/new.png"),"New File", this, SLOT(onNewFile()));
    Bar->addAction(QIcon(":/images/Icons/open.png"),"Open File", this, SLOT(onOpenFile()));
    Bar->addAction(QIcon(":/images/Icons/save.png"),"Save File", this, SLOT(onSaveFile()));
    Bar->addSeparator();
    Bar->addAction(QIcon(":/images/Icons/printer.png"),"Printer", this, SLOT(onPrinter()));
    Bar->addSeparator();
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
