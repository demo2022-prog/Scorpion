#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>

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
    class BusinessLogic* businessLogic;
    class MainMenu* mainMenu;
    class ViewDokuments* viewDockuments;
    class ToolBar* toolBar;    
    class StatusBar* statusBar;
    class AboutWidget* aboutWgt;
    class ParametersWidget* parametersWgt;


    const QString captionWindow = ":: Scorpion v.1.0 ::";
    const QString iconWindow = "./images/logo.png";

};

#endif // MAINWINDOW_H
