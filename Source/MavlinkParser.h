//
// Created by Huang on 2016/1/25.
//

#ifndef QBL_STATION_MAVLINKPARSER_H
#define QBL_STATION_MAVLINKPARSER_H

#include <QObject>
#include <QThread>
#include "Library/mavlink/common/mavlink.h"

class MavlinkParser : public QObject{
    Q_OBJECT


public:
    MavlinkParser(QObject *parent) : QObject(parent) {
        work_thread = new QThread;

        work_thread->start();
    }

    virtual ~MavlinkParser() {
        work_thread->quit();
        work_thread->wait();
        delete work_thread;
    }

public slots:
    void parseMessage(const QByteArray & byteArray);
private:
    QThread * work_thread;
    mavlink_message_t mav_msg_reciver;
    mavlink_status_t mav_msg_status;
};


#endif //QBL_STATION_MAVLINKPARSER_H
