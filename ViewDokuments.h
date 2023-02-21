#ifndef VIEWDOKUMENTS_H
#define VIEWDOKUMENTS_H

#include <QWidget>

class ViewDokuments : public QWidget
{
    Q_OBJECT

public:
    explicit ViewDokuments(QWidget *parent = nullptr);

    virtual void test() = 0;
signals:


};

class MdiArea : public ViewDokuments
{
    Q_OBJECT

public:
    explicit MdiArea(QWidget *parent = nullptr);

private:
    void test() override;

private:
    class QMdiArea* mdiArea;

};

#endif // VIEWDOKUMENTS_H
