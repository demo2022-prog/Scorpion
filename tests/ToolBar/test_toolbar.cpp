#include "test_toolbar.h"

Test_ToolBar::Test_ToolBar(QObject *parent) : QObject(parent)
{
    bar = new ToolBar();
    QVERIFY(bar != nullptr);

 //   QSignalSpy spy(bar, SIGNAL(newFile()));
//    QCOMPARE(spy.isValid(), true);
}

void Test_ToolBar::emit_slot()
{
    event_bool = true;
}

void Test_ToolBar::onNewFile()
{
    event_bool=false;
    connect(bar, SIGNAL(newFile()), this, SLOT(emit_slot()));  // связь сигнала объекта класса ToolBar со слотом тестового класса
//    connect(this, SIGNAL(echo()), bar, SLOT(onNewFile())); // связь сигнала тестового класса со слотом  объекта класса ToolBar из-за
                                                               // того что этот слот private можно без него если включить friend
    bar->onNewFile();
//    this->echo(); // вызов сигнала для проверки работы слота и сигнала объекта класса ToolBar
    QCOMPARE(event_bool, true); // проверка работы слота и сигнала объекта класса ToolBar
    disconnect(bar, SIGNAL(newFile()), this, SLOT(emit_slot()));
//    disconnect(this, SIGNAL(echo()), bar, SLOT(onNewFile()));
}

void Test_ToolBar::onOpenFile()
{
    event_bool=false;
    connect(bar, SIGNAL(openFile()), this, SLOT(emit_slot()));
    bar->onOpenFile();
    QCOMPARE(event_bool, true);
    disconnect(bar, SIGNAL(openFile()), this, SLOT(emit_slot()));
}

void Test_ToolBar::onSaveFile()
{
    event_bool=false;
    connect(bar, SIGNAL(saveFile()), this, SLOT(emit_slot()));
    bar->onSaveFile();
    QCOMPARE(event_bool, true);
    disconnect(bar, SIGNAL(saveFile()), this, SLOT(emit_slot()));
}

void Test_ToolBar::onCopyFont()
{
    event_bool=false;
    connect(bar, SIGNAL(copyFont()), this, SLOT(emit_slot()));
    bar->onCopyFont();
    QCOMPARE(event_bool, true);
    disconnect(bar, SIGNAL(copyFont()), this, SLOT(emit_slot()));
}

void Test_ToolBar::onSetCopyFont()
{
    event_bool=false;
    connect(bar, SIGNAL(setCopyFont()), this, SLOT(emit_slot()));
    bar->onSetCopyFont();
    QCOMPARE(event_bool, true);
    disconnect(bar, SIGNAL(setCopyFont()), this, SLOT(emit_slot()));
}

void Test_ToolBar::onSelectFont()
{
    event_bool=false;
    connect(bar, SIGNAL(selectFont()), this, SLOT(emit_slot()));
    bar->onSelectFont();
    QCOMPARE(event_bool, true);
    disconnect(bar, SIGNAL(selectFont()), this, SLOT(emit_slot()));
}

void Test_ToolBar::onSelectDedicatedFont()
{
    event_bool=false;
    connect(bar, SIGNAL(selectDedicatedFont()), this, SLOT(emit_slot()));
    bar->onSelectDedicatedFont();
    QCOMPARE(event_bool, true);
    disconnect(bar, SIGNAL(selectDedicatedFont()), this, SLOT(emit_slot()));
}

void Test_ToolBar::onAlignmentLeft()
{
    event_bool=false;
    connect(bar, SIGNAL(alignmentLeft()), this, SLOT(emit_slot()));
    bar->onAlignmentLeft();
    QCOMPARE(event_bool, true);
    disconnect(bar, SIGNAL(alignmentLeft()), this, SLOT(emit_slot()));
}

void Test_ToolBar::onAlignmentCenter()
{
    event_bool=false;
    connect(bar, SIGNAL(alignmentCenter()), this, SLOT(emit_slot()));
    bar->onAlignmentCenter();
    QCOMPARE(event_bool, true);
    disconnect(bar, SIGNAL(alignmentCenter()), this, SLOT(emit_slot()));
}

void Test_ToolBar::onAlignmentRight()
{
    event_bool=false;
    connect(bar, SIGNAL(alignmentRight()), this, SLOT(emit_slot()));
    bar->onAlignmentRight();
    QCOMPARE(event_bool, true);
    disconnect(bar, SIGNAL(alignmentRight()), this, SLOT(emit_slot()));
}

void Test_ToolBar::onCopy()
{
    event_bool=false;
    connect(bar, SIGNAL(copy()), this, SLOT(emit_slot()));
    bar->onCopy();
    QCOMPARE(event_bool, true);
    disconnect(bar, SIGNAL(copy()), this, SLOT(emit_slot()));
}

void Test_ToolBar::onPaste()
{
    event_bool=false;
    connect(bar, SIGNAL(paste()), this, SLOT(emit_slot()));
    bar->onPaste();
    QCOMPARE(event_bool, true);
    disconnect(bar, SIGNAL(paste()), this, SLOT(emit_slot()));
}

void Test_ToolBar::onCut()
{
    event_bool=false;
    connect(bar, SIGNAL(cut()), this, SLOT(emit_slot()));
    bar->onCut();
    QCOMPARE(event_bool, true);
    disconnect(bar, SIGNAL(cut()), this, SLOT(emit_slot()));
}

void Test_ToolBar::onPrinter()
{
    event_bool=false;
    connect(bar, SIGNAL(printer()), this, SLOT(emit_slot()));
    bar->onPrinter();
    QCOMPARE(event_bool, true);
    disconnect(bar, SIGNAL(printer()), this, SLOT(emit_slot()));
}

