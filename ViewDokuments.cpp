#include "ViewDokuments.h"

#include <QGridLayout>
#include <QLabel>

#include "Document.h"
#include "qdebug.h"

#include <QMdiSubWindow>

ViewDokuments::~ViewDokuments()
{
    const auto size = documents.size();
    for(int i = 0; i < size; i++){
         documents.pop_back();
    }
}

void ViewDokuments::addDocument(Document *document)
{
    documents.push_back(document);
}


MdiArea::MdiArea(QWidget *parent): QMdiArea(parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    setTabsMovable(true);

    tileSubWindows();

}

void MdiArea::addDocument( Document *document)
{
    QWidget* wgt = new QWidget(this);

    QGridLayout *gridLayout = new QGridLayout(wgt);
    wgt->setLayout(gridLayout);


    if(document->getPath().isEmpty()){
        QLabel *label = new QLabel("PATH: no path", wgt);
        gridLayout->addWidget(label);
    }
    else{
        QLabel *label = new QLabel("PATH:" + document->getPath(), wgt);
        gridLayout->addWidget(label);
    }

    document->setParent(wgt);
    gridLayout->addWidget(document->getTextEdit());

    addSubWindow(wgt);

    if(document->getName().isEmpty()){
        wgt->setWindowTitle("New Document");
    }
    else{
        wgt->setWindowTitle(document->getName());
    }

    wgt->setWindowIcon(QIcon(":/images/Icons/new.png"));

    wgt->show();


    ViewDokuments::addDocument(document);
}

void MdiArea::saveFile()
{
    Document *document = findDocument();
    if(document){
        emit saveFile(document);
    }
}

void MdiArea::saveFileAs()
{
    Document *document = findDocument();
    if(document){
        emit saveFileAs(document);
    }
}

Document *MdiArea::findDocument()
{
    Document *document;

    QMdiSubWindow* subWindow = this->activeSubWindow();

    if(subWindow){
        for(auto chaild : subWindow->widget()->children()){

            Document *document = qobject_cast<Document *>(chaild);

            if(document){
                return document;
            }
        }
    }

    return nullptr;
}


