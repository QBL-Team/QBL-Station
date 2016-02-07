#-------------------------------------------------
#
# Project created by QtCreator 2016-01-26T10:25:04
#
#-------------------------------------------------

QT       += core gui serialport charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QBL-Station
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11 -DNATIVE_BIG_ENDIAN

HEADERS += \
    Library/mavlink/common/common.h \
    Library/mavlink/common/mavlink.h \
    Library/mavlink/common/mavlink_msg_actuator_control_target.h \
    Library/mavlink/common/mavlink_msg_adsb_vehicle.h \
    Library/mavlink/common/mavlink_msg_altitude.h \
    Library/mavlink/common/mavlink_msg_att_pos_mocap.h \
    Library/mavlink/common/mavlink_msg_attitude.h \
    Library/mavlink/common/mavlink_msg_attitude_quaternion.h \
    Library/mavlink/common/mavlink_msg_attitude_quaternion_cov.h \
    Library/mavlink/common/mavlink_msg_attitude_target.h \
    Library/mavlink/common/mavlink_msg_auth_key.h \
    Library/mavlink/common/mavlink_msg_autopilot_version.h \
    Library/mavlink/common/mavlink_msg_battery_status.h \
    Library/mavlink/common/mavlink_msg_camera_trigger.h \
    Library/mavlink/common/mavlink_msg_change_operator_control.h \
    Library/mavlink/common/mavlink_msg_change_operator_control_ack.h \
    Library/mavlink/common/mavlink_msg_command_ack.h \
    Library/mavlink/common/mavlink_msg_command_int.h \
    Library/mavlink/common/mavlink_msg_command_long.h \
    Library/mavlink/common/mavlink_msg_control_system_state.h \
    Library/mavlink/common/mavlink_msg_data_stream.h \
    Library/mavlink/common/mavlink_msg_data_transmission_handshake.h \
    Library/mavlink/common/mavlink_msg_debug.h \
    Library/mavlink/common/mavlink_msg_debug_vect.h \
    Library/mavlink/common/mavlink_msg_distance_sensor.h \
    Library/mavlink/common/mavlink_msg_encapsulated_data.h \
    Library/mavlink/common/mavlink_msg_extended_sys_state.h \
    Library/mavlink/common/mavlink_msg_file_transfer_protocol.h \
    Library/mavlink/common/mavlink_msg_global_position_int.h \
    Library/mavlink/common/mavlink_msg_global_position_int_cov.h \
    Library/mavlink/common/mavlink_msg_global_vision_position_estimate.h \
    Library/mavlink/common/mavlink_msg_gps2_raw.h \
    Library/mavlink/common/mavlink_msg_gps2_rtk.h \
    Library/mavlink/common/mavlink_msg_gps_global_origin.h \
    Library/mavlink/common/mavlink_msg_gps_inject_data.h \
    Library/mavlink/common/mavlink_msg_gps_raw_int.h \
    Library/mavlink/common/mavlink_msg_gps_rtk.h \
    Library/mavlink/common/mavlink_msg_gps_status.h \
    Library/mavlink/common/mavlink_msg_heartbeat.h \
    Library/mavlink/common/mavlink_msg_highres_imu.h \
    Library/mavlink/common/mavlink_msg_hil_controls.h \
    Library/mavlink/common/mavlink_msg_hil_gps.h \
    Library/mavlink/common/mavlink_msg_hil_optical_flow.h \
    Library/mavlink/common/mavlink_msg_hil_rc_inputs_raw.h \
    Library/mavlink/common/mavlink_msg_hil_sensor.h \
    Library/mavlink/common/mavlink_msg_hil_state.h \
    Library/mavlink/common/mavlink_msg_hil_state_quaternion.h \
    Library/mavlink/common/mavlink_msg_home_position.h \
    Library/mavlink/common/mavlink_msg_landing_target.h \
    Library/mavlink/common/mavlink_msg_local_position_ned.h \
    Library/mavlink/common/mavlink_msg_local_position_ned_cov.h \
    Library/mavlink/common/mavlink_msg_local_position_ned_system_global_offset.h \
    Library/mavlink/common/mavlink_msg_log_data.h \
    Library/mavlink/common/mavlink_msg_log_entry.h \
    Library/mavlink/common/mavlink_msg_log_erase.h \
    Library/mavlink/common/mavlink_msg_log_request_data.h \
    Library/mavlink/common/mavlink_msg_log_request_end.h \
    Library/mavlink/common/mavlink_msg_log_request_list.h \
    Library/mavlink/common/mavlink_msg_manual_control.h \
    Library/mavlink/common/mavlink_msg_manual_setpoint.h \
    Library/mavlink/common/mavlink_msg_memory_vect.h \
    Library/mavlink/common/mavlink_msg_message_interval.h \
    Library/mavlink/common/mavlink_msg_mission_ack.h \
    Library/mavlink/common/mavlink_msg_mission_clear_all.h \
    Library/mavlink/common/mavlink_msg_mission_count.h \
    Library/mavlink/common/mavlink_msg_mission_current.h \
    Library/mavlink/common/mavlink_msg_mission_item.h \
    Library/mavlink/common/mavlink_msg_mission_item_int.h \
    Library/mavlink/common/mavlink_msg_mission_item_reached.h \
    Library/mavlink/common/mavlink_msg_mission_request.h \
    Library/mavlink/common/mavlink_msg_mission_request_list.h \
    Library/mavlink/common/mavlink_msg_mission_request_partial_list.h \
    Library/mavlink/common/mavlink_msg_mission_set_current.h \
    Library/mavlink/common/mavlink_msg_mission_write_partial_list.h \
    Library/mavlink/common/mavlink_msg_named_value_float.h \
    Library/mavlink/common/mavlink_msg_named_value_int.h \
    Library/mavlink/common/mavlink_msg_nav_controller_output.h \
    Library/mavlink/common/mavlink_msg_optical_flow.h \
    Library/mavlink/common/mavlink_msg_optical_flow_rad.h \
    Library/mavlink/common/mavlink_msg_param_map_rc.h \
    Library/mavlink/common/mavlink_msg_param_request_list.h \
    Library/mavlink/common/mavlink_msg_param_request_read.h \
    Library/mavlink/common/mavlink_msg_param_set.h \
    Library/mavlink/common/mavlink_msg_param_value.h \
    Library/mavlink/common/mavlink_msg_ping.h \
    Library/mavlink/common/mavlink_msg_position_target_global_int.h \
    Library/mavlink/common/mavlink_msg_position_target_local_ned.h \
    Library/mavlink/common/mavlink_msg_power_status.h \
    Library/mavlink/common/mavlink_msg_radio_status.h \
    Library/mavlink/common/mavlink_msg_raw_imu.h \
    Library/mavlink/common/mavlink_msg_raw_pressure.h \
    Library/mavlink/common/mavlink_msg_rc_channels.h \
    Library/mavlink/common/mavlink_msg_rc_channels_override.h \
    Library/mavlink/common/mavlink_msg_rc_channels_raw.h \
    Library/mavlink/common/mavlink_msg_rc_channels_scaled.h \
    Library/mavlink/common/mavlink_msg_request_data_stream.h \
    Library/mavlink/common/mavlink_msg_resource_request.h \
    Library/mavlink/common/mavlink_msg_safety_allowed_area.h \
    Library/mavlink/common/mavlink_msg_safety_set_allowed_area.h \
    Library/mavlink/common/mavlink_msg_scaled_imu.h \
    Library/mavlink/common/mavlink_msg_scaled_imu2.h \
    Library/mavlink/common/mavlink_msg_scaled_imu3.h \
    Library/mavlink/common/mavlink_msg_scaled_pressure.h \
    Library/mavlink/common/mavlink_msg_scaled_pressure2.h \
    Library/mavlink/common/mavlink_msg_scaled_pressure3.h \
    Library/mavlink/common/mavlink_msg_serial_control.h \
    Library/mavlink/common/mavlink_msg_servo_output_raw.h \
    Library/mavlink/common/mavlink_msg_set_actuator_control_target.h \
    Library/mavlink/common/mavlink_msg_set_attitude_target.h \
    Library/mavlink/common/mavlink_msg_set_gps_global_origin.h \
    Library/mavlink/common/mavlink_msg_set_home_position.h \
    Library/mavlink/common/mavlink_msg_set_mode.h \
    Library/mavlink/common/mavlink_msg_set_position_target_global_int.h \
    Library/mavlink/common/mavlink_msg_set_position_target_local_ned.h \
    Library/mavlink/common/mavlink_msg_sim_state.h \
    Library/mavlink/common/mavlink_msg_statustext.h \
    Library/mavlink/common/mavlink_msg_sys_status.h \
    Library/mavlink/common/mavlink_msg_system_time.h \
    Library/mavlink/common/mavlink_msg_terrain_check.h \
    Library/mavlink/common/mavlink_msg_terrain_data.h \
    Library/mavlink/common/mavlink_msg_terrain_report.h \
    Library/mavlink/common/mavlink_msg_terrain_request.h \
    Library/mavlink/common/mavlink_msg_timesync.h \
    Library/mavlink/common/mavlink_msg_v2_extension.h \
    Library/mavlink/common/mavlink_msg_vfr_hud.h \
    Library/mavlink/common/mavlink_msg_vibration.h \
    Library/mavlink/common/mavlink_msg_vicon_position_estimate.h \
    Library/mavlink/common/mavlink_msg_vision_position_estimate.h \
    Library/mavlink/common/mavlink_msg_vision_speed_estimate.h \
    Library/mavlink/common/testsuite.h \
    Library/mavlink/common/version.h \
    Library/mavlink/checksum.h \
    Library/mavlink/mavlink_conversions.h \
    Library/mavlink/mavlink_helpers.h \
    Library/mavlink/mavlink_types.h \
    Library/mavlink/protocol.h \
    Source/AboutInfoWidget.h \
    Source/MainWindow.h \
    Source/MavlinkParser.h \
    Source/SerialPortManager.h \
    Source/YTChart.h

SOURCES += \
    Source/AboutInfoWidget.cpp \
    Source/main.cpp \
    Source/MainWindow.cpp \
    Source/MavlinkParser.cpp \
    Source/SerialPortManager.cpp \
    Source/YTChart.cpp


FORMS += \
    Source/AboutInfoWidget.ui \
    Source/MainWindow.ui

RESOURCES += \
    Resource/Resource.qrc

RC_FILE += \
    Resource/AppIcon.rc

