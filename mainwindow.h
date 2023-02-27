#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    void setupGui();

private slots:

private:
    Ui::MainWindow *ui;

    class BusinessLogic* businessLogic;

    class MainMenu* mainMenu;

    class ViewDokuments* viewDockuments;

    const QString captionWindow = ":: Scorpion v.1.0 ::";
    const QString iconWindow = "./images/logo.png";

};

#endif // MAINWINDOW_H
