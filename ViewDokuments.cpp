#include "ViewDokuments.h"


ViewDokuments::ViewDokuments(QWidget *parent)
    : QWidget{parent}
{

}



#include <QMdiArea>
#include <QGridLayout>
#include <QLabel>

MdiArea::MdiArea(QWidget *parent): ViewDokuments{parent}
{
    mdiArea = new QMdiArea(this);
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    test();
}



void MdiArea::test()
{
    QWidget *widget = new QWidget(mdiArea);
    QGridLayout *gridLayout = new QGridLayout(widget);
    widget->setLayout(gridLayout);
    QLabel *label = new QLabel("Hello, I am sub window!!!", widget);
    gridLayout->addWidget(label);

    mdiArea->addSubWindow(widget);
    widget->setWindowTitle("Sub Window");
    widget->show();
}
