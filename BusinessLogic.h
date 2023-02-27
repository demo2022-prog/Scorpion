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
    void newDocument(const class Document* document);

public slots:
    void showAbout();

    void createNewDocument();

private:
    class AboutWidget* aboutWgt;

};

#endif // BUSINESSLOGIC_H
