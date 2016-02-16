#include "DummyPlug.h"
#include <QTimer>
#include <cmath>

DummyPlug::DummyPlug(QObject* parent)
    : QObject(parent)
{
    QTimer * timer = new QTimer(this);

    connect(timer,&QTimer::timeout,this,&DummyPlug::TimerUpdated);
    timer->start(1000/100);
}

void DummyPlug::TimerUpdated()
{
    static int i = 0;
    float t;
    t = sin(i++ / 5.0) * 1.4;
    emit PlugInput(t);
}
