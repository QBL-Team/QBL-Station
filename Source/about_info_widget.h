#ifndef ABOUT_INFO_WIDGET_H
#define ABOUT_INFO_WIDGET_H

#include <QWidget>

namespace Ui {
class about_info_widget;
}

class about_info_widget : public QWidget
{
    Q_OBJECT

public:
    explicit about_info_widget(QWidget *parent = 0);
    ~about_info_widget();

private:
    Ui::about_info_widget *ui;
};

#endif // ABOUT_INFO_WIDGET_H
