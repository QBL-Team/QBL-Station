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

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = 0);

    virtual ~MainWindow();

public slots:
    /*!
     * \brief setStatusBarText 设置状态栏的提示信息
     * \param text 要显示在状态栏的信息
     */
    void setStatusBarText(const QString& text);

private:
    /*!
     * \brief ui Ui 定义，由Qt Designer产生
     */
    Ui::MainWindow* ui;
    /*!
     * \brief label_statusbar_info 主要用于展示状态栏的串口状态提示信息
     */
    QLabel label_statusbar_info;
    /*!
     * \brief connectSignals 连接内部信号，进行应用初始化操作
     */
    void connectSignals();

    /*!
     * \brief serial_port_manager 串口管理器
     */
    SerialPortManager* serial_port_manager;

    /*!
     * \brief mavlink_parser Mavlink协议解析器
     */
    MavlinkParser* mavlink_parser;

private slots:
    /*!
     * \brief showMenuSettingPort  放置设置->端口菜单的显示内容
     * \param list 要显示的菜单
     */
    void showMenuSettingPort(QList<QAction*> list);
    /*!
     * \brief clearMenuSettingPort 清除设置->端口菜单的显示内容
     */
    void clearMenuSettingPort();
    /*!
     * \brief showAboutInfo 弹出关于窗口
     */
    void showAboutInfo(void);
};

#endif //QBL_STATION_MAINWINDOW_H
