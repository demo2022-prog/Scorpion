#ifndef TEST_DOCUMENT_H
#define TEST_DOCUMENT_H

#include <QObject>
#include <QWidget>
#include <QTest>
#include "../project/logic/Document.h"

class Test_Document : public QObject
{
    Q_OBJECT
public:
    explicit Test_Document(QObject *parent = nullptr);

private slots:
    void getTextEdit(); //GUI Тест на создание и получение виджета QLineEdit, а так же добавление текста в него
    void getText(); //Тест на получение текста из виджета
    void rename();
    void changePath();
    void getName();
    void getPath();

public:
    QTextEdit* tEdit;
    Document* doc;

};

#endif // TEST_DOCUMENT_H
