#include "ViewDokuments.h"

#include "Document.h"
#include "qdebug.h"

#include <QGridLayout>
#include <QLabel>
#include <QMdiSubWindow>

ViewDokuments::ViewDokuments(QWidget *parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    setTabsMovable(true);

    tileSubWindows();

    connect(this, SIGNAL(subWindowActivated(QMdiSubWindow*)),this, SLOT(onActivatedWindow(QMdiSubWindow*)));
}

void ViewDokuments::onActivatedWindow(QMdiSubWindow *window)
{
    if(window){

        senderSubWindow = window;

        for(auto chaild : window->widget()->children()){

            Document *document = qobject_cast<Document *>(chaild);

            if(document){
                emit activeDocument(document);
            }
        }
    }
}

void ViewDokuments::addDocument( Document *document)
{
    for(auto oldDoc: documents){
        if(oldDoc == document)
        {
            changeNameAndPathInWgt(document);
            return;
        }
    }

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


    documents.push_back(document);
}

void ViewDokuments::changeNameAndPathInWgt(Document * document)
{
    if(!document){
        qDebug() << "DEBUG:" << "EMPTY DOCUMENT";
    }

    if(senderSubWindow){
        QString newName = document->getName();
        qDebug() << "DEBUG:" << "NEW NAME" << newName;
        senderSubWindow->widget()->setWindowTitle(newName);

        for(auto chaild : senderSubWindow->widget()->children()){
            QLabel *label = qobject_cast<QLabel *>(chaild);

            if(label){
                label->setText("PATH:" + document->getPath());
            }
        }

        senderSubWindow = nullptr;
    }
}

ViewDokuments::~ViewDokuments()
{
    const auto size = documents.size();
    for(int i = 0; i < size; i++){
         documents.pop_back();
    }
}


