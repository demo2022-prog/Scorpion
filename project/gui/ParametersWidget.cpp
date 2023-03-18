#include "ParametersWidget.h"
#include "ui_ParametersWidget.h"

#include <QSettings>

#include <QDir>
#include <QDirIterator>
#include <QFile>

#include <QStyleFactory>
#include <QDebug>

ParametersWidget::ParametersWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParametersWidget)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/images/Icons/settings.png"));
    setWindowTitle(tr("Parameters"));

    // необходимо разработать отдельный класс Setting со связкой слотами и сигналами
    settings = new QSettings("settings.ini", QSettings::IniFormat, this);

    ui->labelStyleBox->setText(tr("Style:"));
    ui->okButton->setText(tr("OK"));
    ui->cancelButton->setText(tr("Cancel"));

    this->loadStyle();
}

ParametersWidget::~ParametersWidget()
{
    delete ui;
}

void ParametersWidget::loadStyle()
{
    settings->beginGroup("Style");
        int index = settings->value("Style",0).toInt();
    settings->endGroup();

    QString path = ":/styles/";   // path resource style
    int lenghtExt = 4;                   //  lenght ".qss"
    QDirIterator ItR(path, QDir::Files);
    styles.push_back("");
    ui->selectStyleBox->addItem("default");
    while (ItR.hasNext())
    {
        QFile file(ItR.next());        
        if (file.open(QFile::ReadOnly))
        {
            QString styleLoad = file.readAll();
            styles.push_back(styleLoad);

            QString name = file.fileName().mid(path.count(),file.fileName().count()-path.count()-lenghtExt);
            ui->selectStyleBox->addItem(name);

            file.close();
        }
    }

    ui->selectStyleBox->setCurrentIndex(index);

    setStyleSheet(index);
}

void ParametersWidget::setStyleSheet(int index)
{
    if (index == 0)
    {
        qApp->setStyleSheet(QStyleFactory::keys()[0]);
    } else
    {
        qApp->setStyleSheet(styles[index]);
    }
}

void ParametersWidget::on_selectStyleBox_activated(int index)
{
    setStyleSheet(index);

    settings->beginGroup("Style");
        settings->setValue("Style",index);
    settings->endGroup();
}


void ParametersWidget::on_okButton_clicked()
{
    close();
}


void ParametersWidget::on_cancelButton_clicked()
{
    // reset style, temporary solution
    setStyleSheet(0);
    close();
}

