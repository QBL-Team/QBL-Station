//
// Created by Huang on 2016/1/25.
//

#ifndef QBL_STATION_MAVLINKPARSER_H
#define QBL_STATION_MAVLINKPARSER_H

#include <QObject>
#include <QThread>
#include "Library/mavlink/common/mavlink.h"

class MavlinkParser : public QObject {
    Q_OBJECT

public:
    MavlinkParser(QObject* parent)
        : QObject(parent)
    {
        work_thread = new QThread;

        moveToThread(work_thread);
        work_thread->start();
    }

    virtual ~MavlinkParser()
    {
        work_thread->quit();
        work_thread->wait();
        delete work_thread;
    }

public slots:
    /*!
     * \brief parseMessage 解析消息
     * \param byteArray 收到的字节流
     */
    void parseMessage(const QByteArray& byteArray);

signals:
    /*!
     * \brief DataUpdated 数据已刷新
     * \param Axis 最新的传感器数据
     */
    void DataUpdated(float Axis);
    /*!
     * \brief DataUpdate 数据已刷新
     */
    void DataUpdate();

private:
    /*!
     * \brief work_thread 工作线程
     */
    QThread* work_thread;
    /*!
     * \brief mav_msg_reciver 用于接收的消息结构体
     */

    mavlink_message_t mav_msg_reciver;

    /*!
     * \brief mav_msg_status 用于接收数据的状态结构体
     */

    mavlink_status_t mav_msg_status;
};

#endif //QBL_STATION_MAVLINKPARSER_H
