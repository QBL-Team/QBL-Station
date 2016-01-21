#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    widget_about = new about_info_widget;
    port_selecter = new serial_port_selecter(this);
    port_selecter->setPortMenu(ui->menu_setting_port);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete widget_about;
}


void MainWindow::on_action_exit_triggered()
{
    close();
}

void MainWindow::on_action_about_triggered()
{

    widget_about->show();
}

