//
// Created by Huang on 2016/1/22.
//

#include "MainWindow.h"
#include <QAction>
#include "AboutInfoWidget.h"

void MainWindow::showAbuotInfoWidget() {
    AboutInfoWidget * aboutInfoWidget = new AboutInfoWidget(NULL);

    aboutInfoWidget->setAttribute(Qt::WA_DeleteOnClose);
    aboutInfoWidget->show();
}

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent) {

    ui = new Ui::MainWindow();
    ui->setupUi(this);

    connect(ui->action_help_about,SIGNAL(triggered()),this,SLOT(showAbuotInfoWidget()));
}