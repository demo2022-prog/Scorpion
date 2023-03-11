#include "BusinessLogic.h"


#include "Document.h"
#include "qdebug.h"


#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QFontDialog>


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
    if(senderDocument == nullptr)
        return;

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
    if(!senderDocument)
        return;

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
    if(senderDocument)
        senderDocument->getTextEdit()->setAlignment(Qt::AlignLeft);
}

void BusinessLogic::alignmentCenter()
{
    if(senderDocument)
        senderDocument->getTextEdit()->setAlignment(Qt::AlignCenter);
}

void BusinessLogic::alignmentRight()
{
    if(senderDocument)
        senderDocument->getTextEdit()->setAlignment(Qt::AlignRight);
}

void BusinessLogic::copy()
{
    if(senderDocument)
        senderDocument->getTextEdit()->copy();
}

void BusinessLogic::paste()
{
    if(senderDocument)
        senderDocument->getTextEdit()->paste();
}

void BusinessLogic::cut()
{
    if(senderDocument)
        senderDocument->getTextEdit()->cut();
}

void BusinessLogic::selectFont()
{
    if(senderDocument){
        QFont font = senderDocument->getTextEdit()->font();
        QFontDialog fntDlg(font, this);

        bool buttonOk[] = {true};
        font = fntDlg.getFont(buttonOk);

        if(buttonOk[0])
            senderDocument->getTextEdit()->setFont(font);
    }
}

void BusinessLogic::selectDedicatedFont()
{
    if(senderDocument){
        QFont font = senderDocument->getTextEdit()->textCursor().charFormat().font();
        QFontDialog fntDlg(font, this);

        bool buttonOk[] = {true};
        font = fntDlg.getFont(buttonOk);

        if(buttonOk[0]){
            QTextCharFormat cfmt;
            cfmt.setFont(font);
            senderDocument->getTextEdit()->textCursor().setCharFormat(cfmt);
        }
    }
}

void BusinessLogic::activeDocument(Document *document)
{

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

