#include "TabContainer.h"
#include "ui_TabContainer.h"
#include "DummyPlug.h"

TabContainer::TabContainer(QWidget* parent)
    : QTabWidget(parent)
    , ui(new Ui::TabContainer)
{
    ui->setupUi(this);

    DummyPlug* plug = new DummyPlug(this);

    connect(plug, &DummyPlug::PlugInput, ui->tab_chart, &YTChart::onDataUpdated);
}

TabContainer::~TabContainer()
{
    delete ui;
}
