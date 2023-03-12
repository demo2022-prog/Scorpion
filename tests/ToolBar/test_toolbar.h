#ifndef TEST_TOOLBAR_H
#define TEST_TOOLBAR_H

#include <QObject>
#include <QWidget>
#include <QTest>
//#include <QtTest>
#include "toolbar.h"

class Test_ToolBar : public QObject
{
    Q_OBJECT
public:
    explicit Test_ToolBar(QObject *parent = nullptr);
signals:
    void echo();

private slots:
      void emit_slot();

      void onNewFile();
      void onOpenFile();
      void onSaveFile();

      // Formating
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

public:

    ToolBar* bar;
    bool event_bool = false;

};

#endif // TEST_TOOLBAR_H
