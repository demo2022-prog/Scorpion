#ifndef VIEWDOKUMENTS_H
#define VIEWDOKUMENTS_H

#include <QWidget>

class Document;

class ViewDokuments
{
public:

    virtual ~ViewDokuments();

    virtual void addDocument(Document* document);

    virtual void saveFile() = 0;

    virtual void saveFileAs() = 0;

    virtual void saveFile(Document* document) = 0;

    virtual void saveFileAs(Document* document) = 0;

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

signals:
    virtual void saveFile(Document* document) override;

    virtual void saveFileAs(Document* document) override;

private slots:
    virtual void addDocument(Document *document) override;

    virtual void saveFile() override;

    virtual void saveFileAs() override;

private:
    Document* findDocument();

};

#endif // VIEWDOKUMENTS_H
