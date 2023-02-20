#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

class MainMenu : public QWidget
{
    Q_OBJECT
public:
    MainMenu(QWidget *parent = 0);
private:
    class QMenuBar* menuBar;
};

#endif // MAINMENU_H
