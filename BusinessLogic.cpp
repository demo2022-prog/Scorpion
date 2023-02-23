#include "BusinessLogic.h"

#include "AboutWidget.h"


BusinessLogic::BusinessLogic(QWidget *parent)
    : QWidget{parent}
{
    aboutWgt = new AboutWidget();
}

BusinessLogic::~BusinessLogic()
{
    delete aboutWgt;
}

void BusinessLogic::showAbout()
{
    aboutWgt->show();
}
