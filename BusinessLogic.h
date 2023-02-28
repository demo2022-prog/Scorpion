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

public slots:
    void showAbout();

    void createNewDocument();


    void saveFile(Document* document);

    void saveFileAs(Document* document);

    void openFile();

private:
    const QString getNameFromPath(const QString& path);


private:
    class AboutWidget* aboutWgt;

};

#endif // BUSINESSLOGIC_H
