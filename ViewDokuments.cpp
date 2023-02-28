#include "ViewDokuments.h"

#include <QGridLayout>
#include <QLabel>

#include "Document.h"

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

    QLabel *label = new QLabel("Hello, I am sub window!!!", wgt);
    gridLayout->addWidget(label);

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

