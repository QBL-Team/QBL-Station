#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "about_info_widget.h"
#include "serial_port_selecter.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    about_info_widget * widget_about;
    serial_port_selecter * port_selecter;

private slots:
    void on_action_exit_triggered();

    void on_action_about_triggered();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
