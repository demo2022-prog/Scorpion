#include "StatusBar.h"

#include <QStatusBar>

#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>

StatusBar::StatusBar(QWidget *parent)
    : QWidget{parent}
{
    auto rootLayout = new QHBoxLayout(this);
    this->setLayout(rootLayout);


    auto textDataBeginLabel = new QLabel(this);
    textDataBeginLabel->setText(tr("Text Data ("));
    rootLayout->addWidget(textDataBeginLabel);

    auto wordsLabel = new QLabel(this);
    wordsLabel->setText(tr("Words: "));
    rootLayout->addWidget(wordsLabel);

    statusBarWords = new QStatusBar(this);
    statusBarWords->setMaximumWidth(50);
    rootLayout->addWidget(statusBarWords);

    auto stringsLabel = new QLabel(this);
    stringsLabel->setText(tr("Strings: "));
    rootLayout->addWidget(stringsLabel);

    statusBarStrungs = new QStatusBar(this);
    statusBarStrungs->setMaximumWidth(50);
    rootLayout->addWidget(statusBarStrungs);

    auto textDataEndLabel = new QLabel(this);
    textDataEndLabel->setText(tr(")"));
    rootLayout->addWidget(textDataEndLabel);

    auto spacer = new QSpacerItem(300, 0, QSizePolicy::Expanding);
    rootLayout->addSpacerItem(spacer);

    showTextData();

}

void StatusBar::showTextData(const QString& words,const QString& strings)
{
    statusBarWords->showMessage(words);
    statusBarStrungs->showMessage(strings);
}


