#include <QApplication>
#include <QDebug>
#include "test_document.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << "Testing class Document\n";
    QTest::qExec(new Test_Document, argc, argv);

    return 0;
}
