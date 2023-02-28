#ifndef BUSINESSLOGIC_H
#define BUSINESSLOGIC_H

#include <QWidget>

class BusinessLogic : public QWidget
{
    Q_OBJECT
public:
    explicit BusinessLogic(QWidget *parent = nullptr);
    ~BusinessLogic();

signals:
    void newDocument(class Document* document);

public slots:
    void showAbout();

    void createNewDocument();

    void openFile();

private:
    const QString getNameFromPath(const QString& path);

private:
    class AboutWidget* aboutWgt;

};

#endif // BUSINESSLOGIC_H
