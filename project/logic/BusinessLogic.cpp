#include "BusinessLogic.h"


#include "Document.h"
#include "qdebug.h"


#include <QFile>
#include <QTextStream>
#include <QFileDialog>


BusinessLogic::BusinessLogic(QWidget *parent)
    : QWidget{parent}
{

}

BusinessLogic::~BusinessLogic()
{

}


void BusinessLogic::createNewDocument()
{
    auto newDoc = new Document;

    emit newDocument(newDoc);

}

void BusinessLogic::saveFile()
{
    if(senderDocument->getPath().isEmpty()){
        saveFileAs();
        return;
    }

    QFile file(senderDocument->getPath());
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream textSteam(&file);
        textSteam << senderDocument->getText();
    }

    emit newDocument(senderDocument);
}

void BusinessLogic::saveFileAs()
{
    QString firstPath = "/";
    QString filter = tr(""); //tr("Image Files (*.png *.jpg *.bmp)")

    QString fromFileDialog = QFileDialog::getSaveFileName(this,
                                         tr("Open File"),
                                         firstPath,
                                         filter);
    if(fromFileDialog.isEmpty()){
        return;
    }

    senderDocument->changePath(fromFileDialog);
    senderDocument->rename(getNameFromPath(fromFileDialog));

    saveFile();
}

void BusinessLogic::alignmentLeft()
{
    senderDocument->getTextEdit()->setAlignment(Qt::AlignLeft);
}

void BusinessLogic::alignmentCenter()
{
    senderDocument->getTextEdit()->setAlignment(Qt::AlignCenter);
}

void BusinessLogic::alignmentRight()
{
    senderDocument->getTextEdit()->setAlignment(Qt::AlignRight);
}

void BusinessLogic::copy()
{
    senderDocument->getTextEdit()->copy();
}

void BusinessLogic::paste()
{
    senderDocument->getTextEdit()->paste();
}

void BusinessLogic::cut()
{
    senderDocument->getTextEdit()->cut();
}

void BusinessLogic::activeDocument(Document *document)
{
    qDebug() << "DEBUG:" << "NEW ACTIVE DOCUMENT";

    if(document){
        senderDocument = document;

        connect(senderDocument->getTextEdit(), SIGNAL(textChanged()), this, SLOT(textChanged()));

        textChanged();
    }
}

void BusinessLogic::textChanged()
{
    QString text = senderDocument->getTextEdit()->toPlainText();

    QString words = QString::number(text.split(QRegExp("(\\s|\\n|\\r)+"), Qt::SkipEmptyParts).count());

    QString strings = QString::number(text.split("\n").count());

    emit textData(words, strings);
}


void BusinessLogic::openFile()
{

    QString firstPath = "/";
    QString filter = tr(""); //tr("Image Files (*.png *.jpg *.bmp)")

    QString fromFileDialog = QFileDialog::getOpenFileName(this,
                                         tr("Open File"),
                                         firstPath,
                                         filter);

    if(fromFileDialog.length() > 0){
        QFile file(fromFileDialog);
        if(file.open(QFile::ReadOnly)){
            QTextStream stream(&file);
            auto newDoc = new Document;
            newDoc->getTextEdit()->setPlainText(stream.readAll());
            file.close();
            newDoc->changePath(fromFileDialog);
            newDoc->rename(getNameFromPath(fromFileDialog));

            emit newDocument(newDoc);
        }
    }
}

const QString BusinessLogic::getNameFromPath(const QString &path)
{
    QString name = path;

    const int length = path.length() - 1;

    for(int i = length; i > 0; i--){

        if(path[i] != "/"){
            continue;
        }

        name.remove(0, i + 1);
        break;
    }

    return name;
}

