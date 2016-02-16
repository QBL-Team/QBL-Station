#ifndef DUMMYPLUG_H
#define DUMMYPLUG_H

#include <QObject>

class DummyPlug : public QObject
{
    Q_OBJECT
public:
    explicit DummyPlug(QObject *parent = 0);

signals:
    void PlugInput(float Axis);
public slots:
    void TimerUpdated(void);
};

#endif // DUMMYPLUG_H
