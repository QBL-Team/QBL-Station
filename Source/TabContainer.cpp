#include "TabContainer.h"
#include "ui_TabContainer.h"

TabContainer::TabContainer(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::TabContainer)
{
    ui->setupUi(this);

}

TabContainer::~TabContainer()
{
    delete ui;
}
