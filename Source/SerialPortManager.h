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

class SerialPortManager : public QObject {
    Q_OBJECT

public:

    SerialPortManager(QObject* parent = nullptr);
    virtual ~SerialPortManager();

public slots:
    /*!
     * \brief refreshAvaliablePort 刷新可用端口列表
     */
    void refreshAvaliablePort();
    /*!
     * \brief onPortSelected 根据用户触发的Action决定开启端口状态
     * \param action 选中的动作列表
     */
    void onPortSelected(QAction* action);

private slots:
    /*!
     * \brief onByteReceived 本函数内部使用，接收数据之后发生信号，将数据发送到其他模块
     */
    void onByteReceived();

signals:
    /*!
     * \brief onPortSelectionChanged 完成端口选择处理之后反馈的提示信息
     * \param text 显示在状态栏上的提示信息
     */
    void onPortSelectionChanged(const QString& text);
    /*!
     * \brief onAvaliablePortRefreshed 端口刷新完成后，返回端口列表
     * \param list 用于显示的端口列表
     */
    void onAvaliablePortRefreshed(QList<QAction*> list);

    /*!
     * \brief onByteArrayReceived 接收到了数据
     * \param byteArray 收到的字节流
     */

    void onByteArrayReceived(QByteArray byteArray);

private:

    /*!
     * \brief serial_port 选定的端口
     */
    QSerialPort* serial_port = NULL;
    /*!
     * \brief list_menu_port_disp 端口信息列表，用于用户界面展示
     */
    QList<QAction*> list_menu_port_disp;
    /*!
     * \brief list_available_port 端口信息列表，用于开启端口
     */
    QList<QSerialPortInfo> list_available_port;
    /*!
     * \brief thread_work 端口的工作线程
     */
    QThread* thread_work;
};

#endif //QBL_STATION_SERIALPORTMANAGER_H
