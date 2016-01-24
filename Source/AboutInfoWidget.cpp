#include "AboutInfoWidget.h"

AboutInfoWidget::AboutInfoWidget(QWidget *parent) :
        QWidget(parent){
    ui = new Ui::AboutInfoWidget;
    ui->setupUi(this);
    setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
}

AboutInfoWidget::~AboutInfoWidget() {
    delete ui;
}
