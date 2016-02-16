#ifndef YTCHART_H
#define YTCHART_H

#include <QChartView>
#include <QChart>
#include <QSplineSeries>
#include <QWheelEvent>

/*!
 * \brief 用于绘制数据随时间变化的曲线
 */

class YTChart : public QtCharts::QChartView {
public:
    YTChart(QWidget* parent = 0);
    ~YTChart();

public slots:
    /*!
     * \brief onDataUpdated 更新数据
     * \param val 最新添加的数据
     */
    void onDataUpdated(float val);

private:
    /*!
     * \brief chart 用于展示图像的图表
     */
    QtCharts::QChart* chart;

    /*!
     * \brief spline_series 用于展示的点集合
     */
    QtCharts::QSplineSeries* spline_series;

protected:
    virtual void wheelEvent(QWheelEvent* event);
};

#endif // YTCHART_H
