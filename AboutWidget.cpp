#include "AboutWidget.h"
#include "ui_AboutWidget.h"

#include <QIcon>
#include <QFile>
#include <QTextStream>

AboutWidget::AboutWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutWidget)
{
    ui->setupUi(this);

    setWindowIcon(QIcon(":/images/Icons/about.png"));
    setWindowTitle(tr("About the Scorpion"));

    ui->mainLabel->setText(tr("License GPL 3"));
    ui->LicenceTextBrowser->setText(loadFromFile(":/About/License.txt"));

    ui->teamLabel->setText(tr("Team"));
    ui->teamTextBrowser->setText(loadFromFile(":/About/Team.txt"));
}

AboutWidget::~AboutWidget()
{
    delete ui;
}

const QString AboutWidget::loadFromFile(const QString &filePath)
{
    QString text;
    QFile file(filePath);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        text = stream.readAll();
        file.close();
    }

    return text;
}
