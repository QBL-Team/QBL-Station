#include "YTChart.h"
#include <QList>
#include <QDebug>

YTChart::YTChart(QWidget* parent)
    : QtCharts::QChartView(parent)
{
    chart = new QtCharts::QChart();
    spline_series = new QtCharts::QSplineSeries(this);

    chart->addSeries(spline_series);
    chart->createDefaultAxes();
    chart->legend()->hide();

    chart->axisX()->setRange(0, 100);
    chart->axisY()->setRange(-1.5, 1.5);

    chart->setMargins(QMargins(0, 0, 0, 0));
    chart->setAnimationOptions(QtCharts::QChart::NoAnimation);
    setRenderHint(QPainter::Antialiasing);
    setChart(chart);
}

YTChart::~YTChart()
{
    delete chart;
}

void YTChart::wheelEvent(QWheelEvent* event)
{

    qDebug()<<event->angleDelta()<<endl;
    event->accept();
}

void YTChart::onDataUpdated(float val)
{
    static uint32_t index = 0;
    static QList<float> list;
    list.append(val);
    if (index > 100) {
        spline_series->remove(0);
        chart->scroll(chart->plotArea().width() / 100, 0);
    }
    spline_series->append(index++, val);
}
