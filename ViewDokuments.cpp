#include "ViewDokuments.h"


#include <QGridLayout>
#include <QLabel>


MdiArea::MdiArea(QWidget *parent): QMdiArea{parent}
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    setTabsMovable(true);

    tileSubWindows();

}


void MdiArea::test()
{
    QWidget *widget = new QWidget(this);
    QGridLayout *gridLayout = new QGridLayout(widget);
    widget->setLayout(gridLayout);
    QLabel *label = new QLabel("Hello, I am sub window!!!", widget);
    gridLayout->addWidget(label);

    addSubWindow(widget);
    widget->setWindowTitle("Sub Window");
    widget->show();
}
