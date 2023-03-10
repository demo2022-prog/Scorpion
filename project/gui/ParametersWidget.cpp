#include "ParametersWidget.h"
#include "ui_ParametersWidget.h"
#include <QDir>
#include <QDirIterator>
#include <QFile>

#include <QStyleFactory>
#include <QDebug>

ParametersWidget::ParametersWidget(QSettings *set, QWidget *parent) :
    setFile(set), QWidget(parent),
    ui(new Ui::ParametersWidget)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/images/Icons/settings.png"));
    setWindowTitle(tr("Parameters"));   

    ui->labelStyleBox->setText(tr("Style:"));
    ui->okButton->setText(tr("OK"));
    ui->cancelButton->setText(tr("Cancel"));

//    setFile->beginGroup("Style");
//    auto index = setFile->value("Style",0).toInt();
//    setFile->endGroup();

    this->loadStyle();
}

ParametersWidget::~ParametersWidget()
{
    delete ui;
}

void ParametersWidget::loadStyle()
{
    int index = 0;
    QString path = ":/images/Styles/";   // path resource style
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

