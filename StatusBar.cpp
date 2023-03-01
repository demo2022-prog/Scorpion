#include "StatusBar.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>

StatusBar::StatusBar(QWidget *parent)
    : QStatusBar{parent}
{
    auto label = new QLabel(this);
    label->setText(tr("THIS is STATUS BAAAAR!!!"));
    addPermanentWidget(label);

    auto testButton = new QPushButton("Click me", this);
    addWidget(testButton);
    connect(testButton, SIGNAL(clicked()),this, SLOT(showMessage()));

}

void StatusBar::showMessage()
{
    QStatusBar::showMessage("WTF WTF WTF WTF WTF", 500);
}


