#include "AboutInfoWidget.h"
#include "ui_about_info_widget.h"

AboutInfoWidget::AboutInfoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutInfoWidget)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);
    setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint);
}

AboutInfoWidget::~AboutInfoWidget()
{
    delete ui;
}
