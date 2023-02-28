#include "Document.h"

Document::Document(QWidget *parent)
    : QWidget{parent}
{
    textEdit = new QTextEdit(this);
}

void Document::rename(const QString &newName)
{
    this->name = newName;
}

void Document::changePath(const QString &newPath)
{
    this->path = newPath;
}

QString Document::getText()
{
    return textEdit->toPlainText();
}

QTextEdit *Document::getTextEdit()
{
    return textEdit;
}

const QString &Document::getName()
{
    return name;
}

const QString &Document::getPath()
{
    return path;
}
