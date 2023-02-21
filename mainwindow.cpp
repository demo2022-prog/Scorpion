#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "ViewDokuments.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    viewDockuments = new MdiArea(this);
    setCentralWidget(viewDockuments);

}

MainWindow::~MainWindow()
{
    delete ui;
}
