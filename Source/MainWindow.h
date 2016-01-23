//
// Created by Huang on 2016/1/22.
//

#ifndef QBL_PILOT_MAINWINDOW_H
#define QBL_PILOT_MAINWINDOW_H

#include <QMainWindow>
#include "Ui_MainWindow.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget * parent = 0);

private slots:
    void showAbuotInfoWidget();

private:
    Ui::MainWindow * ui;
};


#endif //QBL_PILOT_MAINWINDOW_H
