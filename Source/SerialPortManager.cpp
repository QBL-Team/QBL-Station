//
// Created by Huang on 2016/1/23.
//

#include <QtCore/qtextstream.h>
#include <QDebug>
#include "SerialPortManager.h"

SerialPortManager::~SerialPortManager()
{
    thread_work->quit();
    thread_work->wait();
    delete thread_work;
}

SerialPortManager::SerialPortManager(QObject* parent)
    : QObject(parent)
{

    serial_port = new QSerialPort(this);
    thread_work = new QThread;

    serial_port->setBaudRate(QSerialPort::BaudRate::Baud115200);
    serial_port->setDataBits(QSerialPort::DataBits::Data8);
    serial_port->setFlowControl(QSerialPort::FlowControl::NoFlowControl);
    serial_port->setParity(QSerialPort::Parity::NoParity);
    serial_port->setStopBits(QSerialPort::StopBits::OneStop);

    //关联串口接收信号
    connect(serial_port, &QSerialPort::readyRead, this, &SerialPortManager::onByteReceived);
    moveToThread(thread_work);
    thread_work->start();
}

void SerialPortManager::onByteReceived(void)
{
    if (serial_port->isReadable()) {
        emit onByteArrayReceived(serial_port->readAll());
    }
}

void SerialPortManager::onPortSelected(QAction* action)
{
    int i = list_menu_port_disp.indexOf(action);

    //首先关闭端口
    if (serial_port->isOpen()) {
        serial_port->close();
    }
    //当前选择的是断开连接
    if (0 == i) {
        serial_port->setPortName("null");
        emit onPortSelectionChanged("断开连接");
        return;
    }

    i--;

    serial_port->setPort(list_available_port.at(i));

    if (serial_port->open(QSerialPort::OpenModeFlag::ReadWrite)) {
        emit onPortSelectionChanged(list_available_port.at(i).portName() + " " + list_available_port.at(i).description());
    }
    else {
        emit onPortSelectionChanged(list_available_port.at(i).portName() + "端口开启失败");
    }
}

void SerialPortManager::refreshAvaliablePort()
{

    QAction* action;
    //当列表中可用的元素为空时,构建始终存在的第一个元素，断开连接
    if (list_menu_port_disp.length() == 0) {
        action = new QAction(this);
        action->setText("断开连接");
        list_menu_port_disp.append(action);
    }

    //获取可用端口的列表
    list_available_port = QSerialPortInfo::availablePorts();

    //填充列表，若Action的数量足够，则会修改已有的Action，不够则构建新的Action

    for (int i = 0; i < list_available_port.length(); ++i) {

        if (list_menu_port_disp.length() <= i + 1) {
            action = new QAction(NULL);
            list_menu_port_disp.append(action);
        }

        list_menu_port_disp.at(i + 1)->setText(
            list_available_port.at(i).portName() + " " + list_available_port.at(i).description());
    }

    //清理缓存列表中多余的Action
    for (int j = list_available_port.length() + 1; j < list_menu_port_disp.length(); ++j) {
        list_menu_port_disp.at(j)->deleteLater();
        list_menu_port_disp.removeAt(j);
    }

    emit onAvaliablePortRefreshed(list_menu_port_disp);
}
