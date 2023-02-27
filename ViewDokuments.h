#ifndef VIEWDOKUMENTS_H
#define VIEWDOKUMENTS_H

#include <QWidget>

class ViewDokuments
{
public:
    virtual void test() = 0;

};

Q_DECLARE_INTERFACE(ViewDokuments,"ViewDokumentsInterface")


#include <QMdiArea>

class MdiArea : public QMdiArea, public ViewDokuments
{
    Q_OBJECT
    Q_INTERFACES(ViewDokuments)

public:
    explicit MdiArea(QWidget *parent = nullptr);

private:
    void test() override;

};

#endif // VIEWDOKUMENTS_H
