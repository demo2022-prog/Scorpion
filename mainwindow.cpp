#include "mainwindow.h"
#include "ui_mainwindow.h"

//#include <QGridLayout>
//#include <QLabel>

#include "ViewDokuments.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    mdiArea = new QMdiArea(this);
//    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
//    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
//    setCentralWidget(mdiArea);

    viewDockuments = new MdiArea(this);
    setCentralWidget(viewDockuments);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAddWindow_triggered()
{
//    QWidget *widget = new QWidget(mdiArea);
//    QGridLayout *gridLayout = new QGridLayout(widget);
//    widget->setLayout(gridLayout);
//    QLabel *label = new QLabel("Hello, I am sub window!!!", widget);
//    gridLayout->addWidget(label);

//    mdiArea->addSubWindow(widget);
//    widget->setWindowTitle("Sub Window");
//    widget->show();
}
