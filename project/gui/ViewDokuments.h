#ifndef VIEWDOKUMENTS_H
#define VIEWDOKUMENTS_H

#include <QMdiArea>
#include <QTabWidget>
#include <QMap>


class Document;

class ViewDokuments : public QWidget
{
    Q_OBJECT
public:
    explicit ViewDokuments(QWidget *parent = nullptr);
    ~ViewDokuments();

signals:
    void activeDocument(Document* document);

public slots:
    void addDocument(Document *document);

private slots:
    void onActivatedWindow(QMdiSubWindow* window);

    void onActivatedTab(int index);

    void onCloseDocument(int index);

    void changeView(QString nameWidget);

private:
    QWidget* createWidget(Document *document);

    void changeNameAndPathInWgt(Document* document);   

    bool eventFilter(QObject *object, QEvent *event) override;

private:    
    int index = 1;
    QMap<int, QWidget*> widgets;

    QTabWidget* tabWidget;
    QMdiArea* mdiAria;
    QMdiSubWindow* senderSubWindow;

    bool isMDI = true;

};

#endif // VIEWDOKUMENTS_H
