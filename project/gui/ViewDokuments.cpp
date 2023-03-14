#include "ViewDokuments.h"

#include "Document.h"
#include "qcoreevent.h"
#include "qdebug.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QMdiSubWindow>

#include <QPushButton>

ViewDokuments::ViewDokuments(QWidget *parent)
{

    auto rootLayout = new QHBoxLayout();
    this->setLayout(rootLayout);

    mdiAria = new QMdiArea(this);
    mdiAria->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiAria->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiAria->setTabsMovable(true);
    mdiAria->tileSubWindows();

    connect(mdiAria, SIGNAL(subWindowActivated(QMdiSubWindow*)), this, SLOT(onActivatedWindow(QMdiSubWindow*)));

    rootLayout->addWidget(mdiAria);


    tabWidget = new QTabWidget(this);
    tabWidget->setTabsClosable(true);

    connect(tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(onCloseDocument(int)));

    rootLayout->addWidget(tabWidget);

    QGridLayout *gridLayout = new QGridLayout();

    auto mdiButton = new QPushButton("MDI", this);
    gridLayout->addWidget(mdiButton);
    connect(mdiButton,&QPushButton::clicked, this, [&] () {
        changeView("MDI");
    });
    auto tabButton = new QPushButton("TAB", this);
    gridLayout->addWidget(tabButton);
    connect(tabButton,&QPushButton::clicked, this, [&] () {
        changeView("TAB");
    });


    rootLayout->addLayout(gridLayout);

    if(isMDI)
        tabWidget->close();
    else
        mdiAria->close();
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
    else{
        senderSubWindow = nullptr;
        emit activeDocument(nullptr);
    }
}

void ViewDokuments::onCloseDocument(int index)
{
    qDebug() << "tab::close" << "index:" << index;

    auto wgt = tabWidget->widget(index);

    for(auto chaild : wgt->children()){
        Document *document = qobject_cast<Document *>(chaild);

        if(document){
            qDebug() << "DEL_TAB_1" << widgets;
            widgets.remove(document->getIndex());
            qDebug() << "DEL_TAB_2" << widgets;
        }
    }

    tabWidget->removeTab(index);

}

void ViewDokuments::changeView(QString nameWidget)
{
    if(nameWidget == "MDI"){
        if(isMDI){
            return;
        }
        isMDI = true;
        tabWidget->clear();
        tabWidget->close();
        mdiAria->show();

        for(auto i : widgets){
            QMdiSubWindow * subWindow = mdiAria->addSubWindow(i);
            subWindow->installEventFilter(this);
            subWindow->setAttribute(Qt::WA_DeleteOnClose, true);
            i->show();
        }
    }

    if(nameWidget == "TAB"){
        if(!isMDI){
            return;
        }
        isMDI = false;
        mdiAria->closeAllSubWindows();
        mdiAria->close();
        tabWidget->show();

        QMapIterator<int, QWidget*> i(widgets);
        while (i.hasNext()) {
            i.next();
            tabWidget->insertTab(i.key(), i.value(), i.value()->windowIcon(), i.value()->windowTitle());
            i.value()->show();
        }
    }
}

void ViewDokuments::addDocument(Document *document)
{
    QWidget* wgt;


    if(document->getIndex() == 0){
        wgt = createWidget(document);
        widgets.insert(index, wgt);
    }
    else{
        QMap<int, QWidget*>::const_iterator i = widgets.find(document->getIndex());
        wgt = i.value();
        changeNameAndPathInWgt(document);
        return;
    }


    if(isMDI){
        QMdiSubWindow * subWindow = mdiAria->addSubWindow(wgt);
        subWindow->installEventFilter(this);
        subWindow->setAttribute(Qt::WA_DeleteOnClose, true);

    }
    else
        tabWidget->insertTab(index, wgt, wgt->windowIcon(), wgt->windowTitle());

    index++;

   wgt->show();

   //qDebug() << "ADD" << widgets;

}

QWidget *ViewDokuments::createWidget(Document *document)
{
    QWidget* wgt = new QWidget(this);
    document->setIndex(index);
    document->setParent(wgt);

    QGridLayout *gridLayout = new QGridLayout(wgt);
    wgt->setLayout(gridLayout);

    QLabel *label;
    if(document->getPath().isEmpty())
         label = new QLabel("PATH: no path", wgt);
     else
         label = new QLabel("PATH:" + document->getPath(), wgt);
     gridLayout->addWidget(label);


     gridLayout->addWidget(document->getTextEdit());

     if(document->getName().isEmpty()){
         wgt->setWindowTitle("New Document");
     }
     else{
         wgt->setWindowTitle(document->getName());
     }

     wgt->setWindowIcon(QIcon(":/images/Icons/new.png"));

     return wgt;

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

bool ViewDokuments::eventFilter(QObject *object, QEvent *event)
{
    if(isMDI)
        switch (event->type())
        {
            case QEvent::Close:
            {
                QMdiSubWindow * subWindow = dynamic_cast<QMdiSubWindow*>(object);
                qDebug() << "eventFilter::close";
                //Q_ASSERT (subWindow != NULL);

                if(subWindow)

                    for(auto chaild : subWindow->widget()->children()){
                            Document *document = qobject_cast<Document *>(chaild);
                            if(document){
                                qDebug() << "DEL_MDI_1" << widgets;
                                widgets.remove(document->getIndex());
                                qDebug() << "DEL_MDI_2" << widgets;
                            }
                        }

                break;
            }
            default:
                qt_noop();
        }

    return QObject::eventFilter(object, event);
}

ViewDokuments::~ViewDokuments()
{
//    const auto size = documents.size();
//    for(int i = 0; i < size; i++){
//         documents.pop_back();
//    }
}


