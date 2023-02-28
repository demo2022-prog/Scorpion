#include "BusinessLogic.h"

#include "AboutWidget.h"

#include "Document.h"

#include <QFile>

#include <QTextStream>

#include <QFileDialog>

BusinessLogic::BusinessLogic(QWidget *parent)
    : QWidget{parent}
{
    aboutWgt = new AboutWidget();
}

BusinessLogic::~BusinessLogic()
{
    delete aboutWgt;
}

void BusinessLogic::showAbout()
{
    aboutWgt->show();
}

void BusinessLogic::createNewDocument()
{
    auto newDoc = new Document;

    emit newDocument(newDoc);

}

void BusinessLogic::saveFile(Document *document)
{
    if(document->getPath().isEmpty()){
        saveFileAs(document);
        return;
    }

    QFile file(document->getPath());
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream textSteam(&file);
        textSteam << document->getText();
    }
}

void BusinessLogic::saveFileAs(Document *document)
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

    document->ChangePath(fromFileDialog);
    saveFile(document);
}
