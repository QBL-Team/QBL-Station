//
// Created by Huang on 2016/1/23.
//

#include <QAction>
#include "MainWindow.h"
#include "AboutInfoWidget.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->action_help_about,&QAction::triggered,this,&MainWindow::showAboutInfo);
    connect(ui->action_file_exit,&QAction::triggered,this,&MainWindow::close);
}


void MainWindow::showAboutInfo(void) {
    AboutInfoWidget *aboutInfoWidget = new AboutInfoWidget(NULL);
    aboutInfoWidget->setAttribute(Qt::WA_DeleteOnClose, true);
    aboutInfoWidget->show();
}

MainWindow::~MainWindow() {
    delete ui;
}





