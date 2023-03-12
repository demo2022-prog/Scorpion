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
    Bar->addAction(QIcon(":/images/Icons/copy.png"),"Copy", this, SLOT(onCopy()));
    Bar->addAction(QIcon(":/images/Icons/paste.png"),"Paste", this, SLOT(onPaste()));
    Bar->addAction(QIcon(":/images/Icons/cut.png"),"Cut", this, SLOT(onCut()));

    Bar->addSeparator();
    Bar->addAction(QIcon(":/images/Icons/typographyCopyUp.png"),"Copy Font", this, SLOT(onCopyFont()));
    Bar->addAction(QIcon(":/images/Icons/typographyCopy.png"),"Set Copy Font", this, SLOT(onSetCopyFont()));
    Bar->addAction(QIcon(":/images/Icons/typography.png"),"Select Font", this, SLOT(onSelectFont()));
    Bar->addAction(QIcon(":/images/Icons/typographyMouse.png"),"Select Dedicated Font", this, SLOT(onSelectDedicatedFont()));

    Bar->addSeparator();
    Bar->addAction(QIcon(":/images/Icons/textLeft.png"),"Alignment Left", this, SLOT(onAlignmentLeft()));
    Bar->addAction(QIcon(":/images/Icons/textCenter.png"),"Alignment Center", this, SLOT(onAlignmentCenter()));
    Bar->addAction(QIcon(":/images/Icons/textRight.png"),"Alignment Right", this, SLOT(onAlignmentRight()));

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

void ToolBar::onCopyFont()
{
    emit copyFont();
}

void ToolBar::onSetCopyFont()
{
    emit setCopyFont();
}

void ToolBar::onSelectFont()
{
    emit selectFont();
}

void ToolBar::onSelectDedicatedFont()
{
    emit selectDedicatedFont();
}

void ToolBar::onAlignmentLeft()
{
    emit alignmentLeft();

}

void ToolBar::onAlignmentCenter()
{
    emit alignmentCenter();
}

void ToolBar::onAlignmentRight()
{
    emit alignmentRight();
}

void ToolBar::onCopy()
{
    emit copy();
}

void ToolBar::onPaste()
{
    emit paste();
}

void ToolBar::onCut()
{
    emit cut();
}

void ToolBar::onPrinter()
{
    emit printer();
}
