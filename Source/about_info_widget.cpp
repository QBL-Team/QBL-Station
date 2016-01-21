#include "about_info_widget.h"
#include "ui_about_info_widget.h"

about_info_widget::about_info_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::about_info_widget)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);
    setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint);
}

about_info_widget::~about_info_widget()
{
    delete ui;
}
