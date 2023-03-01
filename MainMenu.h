#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = 0);

signals:
    // File
    void newFile();
    void openFile();
    void saveFile();
    void saveFileAs();
    void openInStorage();
    void saveInStorage();
    void exit();

    // Tools
    void parametrs();
    void printer();

    // Formatting
    void copyFont();
    void setCopyFont();
    void selectFont();
    void selectDedicatedFont();
    void alignmentLeft();
    void alignmentCenter();
    void alignmentRight();

    // Help
    void about();

private slots:
    // File
    void onNewFile();
    void onOpenFile();
    void onSaveFile();
    void onSaveFileAs();
    void onOpenInStorage();
    void onSaveInStorage();
    void onExit();

    // Tools
    void onParametrs();
    void onPrinter();

    //Formatting
    void onCopyFont();
    void onSetCopyFont();
    void onSelectFont();
    void onSelectDedicatedFont();
    void onAlignmentLeft();
    void onAlignmentCenter();
    void onAlignmentRight();

    // Help
    void onAbout();

private:
    class QAction* addAction(class QMenu* menu, const QString& name, const QString& shortcut = "");

private:
    class QMenuBar* menuBar;

};

#endif // MAINMENU_H
