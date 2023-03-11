#include <QApplication>
#include <QDebug>
#include "test_document.h"
#include "test_toolbar.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << "Testing class Document\n";
    QTest::qExec(new Test_Document, argc, argv);
    qDebug() << "\nTesting class ToolBar\n";
    QTest::qExec(new Test_ToolBar, argc, argv);

    return 0;
}
