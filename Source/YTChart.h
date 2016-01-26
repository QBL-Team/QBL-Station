//
// Created by Huang on 2016/1/25.
//

#ifndef QBL_STATION_YTCHART_H
#define QBL_STATION_YTCHART_H

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QValueAxis>
#include <QList>

class YTChart : public QtCharts::QChart {
Q_OBJECT
public:
    YTChart(QGraphicsItem *parent = nullptr, const Qt::WindowFlags &wFlags = Qt::Widget) : QChart(parent, wFlags) {
        list_line_series.append(new QtCharts::QLineSeries(this));
        valueAxisX = new QtCharts::QValueAxis(this);
        QPen pen(Qt::red);
        pen.setWidth(3);
        list_line_series.last()->setPen(pen);
        list_line_series.last()->setUseOpenGL(true);
        for (int i = 0; i < 10000; ++i) {
            list_line_series.last()->append(i, i);
        }

        addSeries(list_line_series.last());
        createDefaultAxes();

        legend()->hide();

        setAxisX(valueAxisX, list_line_series.last());
        valueAxisX->setTickCount(1);
        axisX()->setRange(0, 10000);
        axisY()->setRange(0, 10000);
    }

private:
    QList<QtCharts::QLineSeries *> list_line_series;
    QtCharts::QValueAxis *valueAxisX;
};


#endif //QBL_STATION_YTCHART_H
