#ifndef BUSINESSLOGIC_H
#define BUSINESSLOGIC_H

#include <QWidget>

class Document;

class BusinessLogic : public QWidget
{
    Q_OBJECT
public:
    explicit BusinessLogic(QWidget *parent = nullptr);
    ~BusinessLogic();

signals:
    void newDocument(Document* document);

    void textData(const QString& worlds, const QString& strings);

public slots:
    void activeDocument(Document *document);

    void createNewDocument();

    void openFile();

    void saveFile();

    void saveFileAs();

    void alignmentLeft();

    void alignmentCenter();

    void alignmentRight();

    void copy();

    void paste();

    void cut();


private slots:
    void textChanged();

private:
    const QString getNameFromPath(const QString& path);


private:

    Document* senderDocument;

};

#endif // BUSINESSLOGIC_H
