cmake_minimum_required(VERSION 3.3)
project(QBL-Station)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} -std=c++11 -mwindows")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -std=c++11 -mwindows")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

#设置构建路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Build)

#定义Mavlink使用大端模式
add_definitions(-DNATIVE_BIG_ENDIAN)
include_directories(Library/mavlink/common)

#设置Qt相关工具开启
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#查找Qt库
find_package(Qt5Widgets REQUIRED)
find_package(Qt5SerialPort REQUIRED)
find_package(Qt5Charts REQUIRED)

set(UI_FILES Source/MainWindow.ui Source/AboutInfoWidget.ui)

set(SOURCE_FILES Source/main.cpp Resource/Resource.qrc Source/AboutInfoWidget.cpp Source/MainWindow.cpp Source/SerialPortManager.cpp Source/SerialPortManager.h Source/MavlinkParser.cpp Source/MavlinkParser.h Source/YTChart.cpp Source/YTChart.h)
add_executable(QBL-Station ${UI_FILES} ${SOURCE_FILES} Resource/AppIcon.rc)

target_link_libraries(QBL-Station Qt5::Widgets Qt5::SerialPort Qt5::Charts)