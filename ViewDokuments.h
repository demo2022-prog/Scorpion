#ifndef VIEWDOKUMENTS_H
#define VIEWDOKUMENTS_H

#include <QWidget>

class Document;

class ViewDokuments
{
public:

    virtual ~ViewDokuments();

    virtual void addDocument(Document* document);

protected:
    QList<Document*> documents;

};

Q_DECLARE_INTERFACE(ViewDokuments,"ViewDokumentsInterface")


#include <QMdiArea>

class MdiArea : public QMdiArea, public ViewDokuments
{
    Q_OBJECT
    Q_INTERFACES(ViewDokuments)   

public:
    explicit MdiArea(QWidget *parent = nullptr);

private slots:
    virtual void addDocument(Document *document) override;

};

#endif // VIEWDOKUMENTS_H
