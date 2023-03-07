#include "ParametersWidget.h"
#include "ui_ParametersWidget.h"
#include <QDir>
#include <QDirIterator>
#include <QFile>

ParametersWidget::ParametersWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParametersWidget)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/images/Icons/settings.png"));
    setWindowTitle(tr("Parameters"));

    ui->labelStyleBox->setText(tr("Style:"));

    this->loadStyle();
}

ParametersWidget::~ParametersWidget()
{
    delete ui;
}

void ParametersWidget::loadStyle()
{
//    settings->beginGroup("Style");
//    auto index = settings->value("Style",0).toInt;
//    settings->endGroup();

    QDirIterator ItR(":/images/Styles/", QDir::Files);
    while (ItR.hasNext())
    {
        QFile file(ItR.next());
        if (file.open(QFile::ReadOnly))
        {
            QString styleLoad = file.readAll();
            styles.push_back(styleLoad);

            QString name = file.fileName().mid(16,file.fileName().count()-16-4);
            ui->selectStyleBox->addItem(name);

            file.close();
        }
    }

//    ui->selectStyleBox->setCurrentIndex(index);
//    connect(ui->selectStyleBox, SIGNAL(activated(int)), SLOT(setStyleSheet(int)));
}

void ParametersWidget::setStyleSheet(int index)
{
    qApp->setStyleSheet(styles[index]);


    //    QFile styleSheet(":/images/Styles/Eclippy.qss");
    //    styleSheet.open(QFile::ReadOnly);
    //    auto content = styleSheet.readAll();
    //    qApp->setStyleSheet(content);
    //    styleSheet.close();
}
