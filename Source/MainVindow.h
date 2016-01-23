#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPortInfo>
#include "AboutInfoWidget.h"
#include "SerialPortSelecter.h"
#include <QLabel>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setStatusText(QString text);

private:
    SerialPortSelecter * port_selecter;
    QLabel status_bar_info_label;
private slots:
    void on_action_exit_triggered();

    void on_action_about_triggered();

public slots:
    void onPortSelected(const QSerialPortInfo * port);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
