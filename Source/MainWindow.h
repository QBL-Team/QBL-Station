//
// Created by Huang on 2016/1/23.
//

#ifndef QBL_STATION_MAINWINDOW_H
#define QBL_STATION_MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "SerialPortManager.h"
#include "MavlinkParser.h"
#include <QThread>
#include <ui_MainWindow.h>
#include "YTChart.h"

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

    virtual ~MainWindow();

public slots:
    void setStatusBarText(const QString & text);
private:
    //Ui 定义，由Qt Designer产生
    Ui::MainWindow *ui;
    //主要用于展示状态栏的串口状态提示信息
    QLabel label_statusbar_info;
    //连接内部信号，进行应用初始化操作
    void connectSignals();

    //串口管理器
    SerialPortManager * serial_port_manager;
    //Mavlink协议解析器
    MavlinkParser *mavlink_parser;

    YTChart * ytChart;

private slots:
    /*
     * 放置设置->端口菜单的显示内容
     */
    void showMenuSettingPort(QList<QAction *> list);
    /*
     * 清除设置->端口菜单的显示内容
     */
    void clearMenuSettingPort();
    /*
     * 弹出关于窗口
     */
    void showAboutInfo(void);
};


#endif //QBL_STATION_MAINWINDOW_H
