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
    connect(this, SIGNAL(echo()), bar, SLOT(onNewFile())); // связь сигнала тестового класса со слотом  объекта класса ToolBar из-за
                                                           // того что этот слот private
    this->echo(); // вызов сигнала для проверки работы слота и сигнала объекта класса ToolBar
    QCOMPARE(event_bool, true); // проверка работы слота и сигнала объекта класса ToolBar
    disconnect(bar, SIGNAL(newFile()), this, SLOT(emit_slot()));
    disconnect(this, SIGNAL(echo()), bar, SLOT(onNewFile()));
}

