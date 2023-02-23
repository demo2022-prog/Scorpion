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

public slots:
    void showAbout();

private:
    class AboutWidget* aboutWgt;

};

#endif // BUSINESSLOGIC_H
