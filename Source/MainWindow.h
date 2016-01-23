//
// Created by Huang on 2016/1/23.
//

#ifndef QBL_STATION_MAINWINDOW_H
#define QBL_STATION_MAINWINDOW_H

#include <QMainWindow>
#include "MainWindow_Ui.h"

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

    virtual ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:

    void showAboutInfo(void);
};


#endif //QBL_STATION_MAINWINDOW_H
