#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>

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
    void on_actionAddWindow_triggered();

private:
    Ui::MainWindow *ui;
    QMdiArea * mdiArea;
    QString captionWindow = ":: Scorpion v.1.0 ::";
};

#endif // MAINWINDOW_H
