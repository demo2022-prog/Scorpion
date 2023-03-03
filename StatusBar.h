#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QWidget>

class StatusBar : public QWidget
{
    Q_OBJECT
public:
    explicit StatusBar(QWidget *parent = nullptr);

signals:

private slots:
     void showTextData(const QString& words = "0",const QString& strings = "0");

private:
     class QStatusBar* statusBarWords;
     class QStatusBar* statusBarStrungs;

};

#endif // STATUSBAR_H
