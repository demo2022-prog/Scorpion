#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QFile styleSheet(":/images/Styles/Eclippy.qss");
//    styleSheet.open(QFile::ReadOnly);
//    auto content = styleSheet.readAll();
//    qApp->setStyleSheet(content);
//    styleSheet.close();

    MainWindow w;    
    w.show();

    return a.exec();
}
