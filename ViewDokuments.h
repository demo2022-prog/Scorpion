#ifndef VIEWDOKUMENTS_H
#define VIEWDOKUMENTS_H

#include <QMdiArea>

class Document;

class ViewDokuments : public QMdiArea
{
    Q_OBJECT
public:
    explicit ViewDokuments(QWidget *parent = nullptr);
    ~ViewDokuments();

signals:
     void saveFile(Document* document);

     void saveFileAs(Document* document);

public slots:
    void addDocument(Document *document);

    void onSaveFile();

    void onSaveFileAs();

private:
    Document* findDocument();

    void changeNameAndPathInWgt(Document* document);

private:
    QList<Document*> documents;

    QMdiSubWindow* senderSubWindow;

};

#endif // VIEWDOKUMENTS_H
