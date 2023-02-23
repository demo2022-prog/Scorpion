#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;

    class BusinessLogic* businessLogic;

    class MainMenu* mainMenu;

    class ViewDokuments* viewDockuments;

    QString captionWindow = ":: Scorpion v.1.0 ::";

};

#endif // MAINWINDOW_H
