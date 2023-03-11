#include "test_document.h"
#include <QDebug>

Test_Document::Test_Document(QObject *parent) : QObject(parent)
{
    doc = new Document();
}

void Test_Document::getTextEdit()
{
    //Тестирование метода getTextEdit

    tEdit = doc->getTextEdit();
    QTest::keyClicks(tEdit, "Abra cadabra");

    QCOMPARE(tEdit->toPlainText(), QString("Abra cadabra"));    
}

void Test_Document::getText()
{
    //Тестирование метода getText
    QCOMPARE(doc->getText(), QString("Abra cadabra"));
}

void Test_Document::rename()
{
    //Тестирование метода rename
    doc->rename("VeryNewDoc");
    QCOMPARE(doc->name, QString("VeryNewDoc"));
}

void Test_Document::changePath()
{
    //Тестирование метода changePath
    doc->changePath("home/");
    QCOMPARE(doc->path, QString("home/"));
}

void Test_Document::getName()
{
    //Тестирование метода getName
    QCOMPARE(doc->getName(), doc->name);
}

void Test_Document::getPath()
{
    //Тестирование метода getPath
    QCOMPARE(doc->getPath(), doc->path);
}
