//
// Created by Huang on 2016/1/25.
//

#include "MavlinkParser.h"

#include <QDebug>

void MavlinkParser::parseMessage(const QByteArray &byteArray) {
    const char *array = byteArray.constData();
    int len = byteArray.length();

    for (int i = 0; i < len; ++i) {
        if (mavlink_parse_char(0, array[i], &mav_msg_reciver, &mav_msg_status)) {
            if (mav_msg_reciver.msgid == MAVLINK_MSG_ID_HEARTBEAT){
                mavlink_heartbeat_t heartbeat_t;
                mavlink_msg_heartbeat_decode(&mav_msg_reciver,&heartbeat_t);
//                qDebug()<<"Heartbeat received :"<<mav_msg_status.packet_rx_success_count<<" "<< "Times after powered :"<<heartbeat_t.custom_mode<<endl;
            }
        }
    }

}
