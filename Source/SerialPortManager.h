//
// Created by Huang on 2016/1/23.
//

#ifndef QBL_STATION_SERIALPORTMANAGER_H
#define QBL_STATION_SERIALPORTMANAGER_H

#include <QObject>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QThread>
#include <QList>
#include <QAction>

class SerialPortManager : public QObject{
Q_OBJECT

public:
    SerialPortManager(QObject *parent = nullptr);
    virtual ~SerialPortManager();

public slots:
    /*
     * 刷新可用端口列表
     */
    void refreshAvaliablePort();
    /*
     * 根据用户触发的Action决定开启端口状态
     */
    void onPortSelected(QAction * action);

private slots:
    void onByteReceived();

signals:
    /*
     * 完成端口选择处理之后反馈的提示信息
     */
    void onPortSelectionChanged(const QString & text);
    /*
     * 端口刷新完成后，返回端口列表
     */
    void onAvaliablePortRefreshed(QList<QAction *> list);

    /*
     *
     */
    void onByteArrayReceived(QByteArray byteArray);

private:
    //选定的端口
    QSerialPort * serial_port = NULL;
    //端口信息列表，用于用户界面展示
    QList<QAction *> list_menu_port_disp;
    //端口信息列表，用于开启端口
    QList<QSerialPortInfo> list_available_port;
    //端口的工作线程
    QThread * thread_work;

};


#endif //QBL_STATION_SERIALPORTMANAGER_H
