//
// Created by Huang on 2016/1/25.
//

#include "MavlinkParser.h"
#include <QDebug>

void MavlinkParser::parseMessage(const QByteArray& byteArray)
{
    const char* array = byteArray.constData();
    int len = byteArray.length();

    for (int i = 0; i < len; ++i) {
        if (mavlink_parse_char(0, array[i], &mav_msg_reciver, &mav_msg_status)) {
            if (MAVLINK_MSG_ID_HIL_SENSOR == mav_msg_reciver.msgid) {
                mavlink_hil_sensor_t sensor;
                mavlink_msg_hil_sensor_decode(&mav_msg_reciver, &sensor);
                DataUpdated(sensor.xacc);
                DataUpdate();
            }
        }
    }
}
