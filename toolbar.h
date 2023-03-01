#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QWidget>

class ToolBar : public QWidget
{
    Q_OBJECT

public:
    ToolBar(QWidget *parent = 0);

signals:
    // File
    void newFile();
    void openFile();
    void saveFile();
//    void saveFileAs();
    void openInStorage();
    void saveInStorage();

    // Tools
    void printer();

private:
    class QAction* addAction(class QMenu* menu, const QString& name, const QString& shortcut = "");

private slots:
    // File
    void onNewFile();
    void onOpenFile();
    void onSaveFile();
//    void onSaveFileAs();
    void onOpenInStorage();
    void onSaveInStorage();

    // Tools
    void onPrinter();

private:
    class QToolBar* toolBar;

};

#endif // TOOLBAR_H
