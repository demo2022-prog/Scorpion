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
    void on_actionAddWindow_triggered();

private:
    Ui::MainWindow *ui;

    class ViewDokuments* viewDockuments;
};

#endif // MAINWINDOW_H
