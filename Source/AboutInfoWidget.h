//
// Created by Huang on 2016/1/22.
//

#ifndef QBL_PILOT_ABOUTINFOWIDGET_H
#define QBL_PILOT_ABOUTINFOWIDGET_H

#include <QWidget>
#include "Ui_AboutInfoWidget.h"

namespace Ui{
    class AboutInfoWidget;
}

class AboutInfoWidget : public QWidget{


public:
    AboutInfoWidget(QWidget * parent = 0);

private:
    Ui::AboutInfoWidget aboutInfoWidget;
};


#endif //QBL_PILOT_ABOUTINFOWIDGET_H
