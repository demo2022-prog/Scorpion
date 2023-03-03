#include "ViewDokuments.h"

#include "Document.h"

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

ViewDokuments::~ViewDokuments()
{
    const auto size = documents.size();
    for(int i = 0; i < size; i++){
         documents.pop_back();
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

void ViewDokuments::onSaveFile()
{
    Document *document = findDocument();
    if(document){
        emit saveFile(document);
    }
}

void ViewDokuments::onSaveFileAs()
{
    Document *document = findDocument();
    if(document){
        emit saveFileAs(document);
    }
}

void ViewDokuments::onAlignmentLeft()
{
    Document *document = findDocument();
    if(document){
        emit alignmentLeft(document);
    }
}

void ViewDokuments::onAlignmentCenter()
{
    Document *document = findDocument();
    if(document){
        emit alignmentCenter(document);
    }
}

void ViewDokuments::onAlignmentRight()
{
    Document *document = findDocument();
    if(document){
        emit alignmentRight(document);
    }
}

void ViewDokuments::onCopy()
{
    Document *document = findDocument();
    if(document){
        emit copy(document);
    }
}

void ViewDokuments::onPaste()
{
    Document *document = findDocument();
    if(document){
        emit paste(document);
    }
}

void ViewDokuments::onCut()
{
    Document *document = findDocument();
    if(document){
        emit cut(document);
    }
}

void ViewDokuments::onActivatedWindow(QMdiSubWindow *window)
{
    if(window){

        for(auto chaild : window->widget()->children()){

            Document *document = qobject_cast<Document *>(chaild);

            if(document){
                emit textData(document);
            }
        }
    }

}

Document *ViewDokuments::findDocument()
{
    Document *document;

    QMdiSubWindow* subWindow = this->activeSubWindow();

    if(subWindow){

        for(auto chaild : subWindow->widget()->children()){

            Document *document = qobject_cast<Document *>(chaild);

            if(document){
                senderSubWindow = subWindow;
                return document;
            }
        }
    }

    return nullptr;
}

void ViewDokuments::changeNameAndPathInWgt(Document * document)
{
    if(senderSubWindow){
        senderSubWindow->widget()->setWindowTitle(document->getName());

        for(auto chaild : senderSubWindow->widget()->children()){
            QLabel *label = qobject_cast<QLabel *>(chaild);

            if(label){
                label->setText("PATH:" + document->getPath());
            }
        }

        senderSubWindow = nullptr;
    }
}


