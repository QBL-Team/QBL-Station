#ifndef ABOUT_INFO_WIDGET_H
#define ABOUT_INFO_WIDGET_H

#include <QWidget>

namespace Ui {
class AboutInfoWidget;
}

class AboutInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AboutInfoWidget(QWidget *parent = 0);
    ~AboutInfoWidget();

private:
    Ui::AboutInfoWidget *ui;
};

#endif // ABOUT_INFO_WIDGET_H
