#include "BusinessLogic.h"

#include "AboutWidget.h"

#include "Document.h"
#include "qdebug.h"

#include <QFileDialog>
#include <QTextStream>


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

