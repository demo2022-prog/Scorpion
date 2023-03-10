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

    // Formating
    void copyFont();
    void setCopyFont();
    void selectFont();
    void selectDedicatedFont();
    void alignmentLeft();
    void alignmentCenter();
    void alignmentRight();
    void copy();
    void paste();
    void cut();

    // Tools
    void printer();

private:
    class QAction* addAction(class QMenu* menu, const QString& name, const QString& shortcut = "");

private slots:
    // File
    void onNewFile();
    void onOpenFile();
    void onSaveFile();

    //Formatting
    void onCopyFont();
    void onSetCopyFont();
    void onSelectFont();
    void onSelectDedicatedFont();
    void onAlignmentLeft();
    void onAlignmentCenter();
    void onAlignmentRight();
    void onCopy();
    void onPaste();
    void onCut();

    // Tools
    void onPrinter();

private:
    class QToolBar* Bar;

};

#endif // TOOLBAR_H
