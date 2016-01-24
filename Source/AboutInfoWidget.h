#ifndef ABOUT_INFO_WIDGET_H
#define ABOUT_INFO_WIDGET_H

#include <QWidget>
#include "ui_AboutInfoWidget.h"

class AboutInfoWidget : public QWidget {
Q_OBJECT

public:
    explicit AboutInfoWidget(QWidget *parent = 0);

    ~AboutInfoWidget();

private:
    Ui::AboutInfoWidget * ui;
};

#endif // ABOUT_INFO_WIDGET_H
