#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = 0);

private:
    class QAction* addAction(class QMenu* menu, const QString& name, const QString& shortcut = "");

private slots:
    void onNewFile();
    void onOpenFile();
    void onSaveFile();
    void onOpenInStorage();
    void onSaveInStorage();
    void onExit();

private:
    class QMenuBar* menuBar;

};

#endif // MAINMENU_H
