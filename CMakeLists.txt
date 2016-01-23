cmake_minimum_required(VERSION 3.3)
project(QBL-Station)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#设置构建路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Build)

#定义Mavlink使用大端模式
add_definitions(-DNATIVE_BIG_ENDIAN)

#设置Qt相关工具开启
set(CMAKE_AUTOMOC ON)

#查找Qt库
find_package(Qt5Widgets)
find_package(Qt5SerialPort)
find_package(Qt5Charts)

set(SOURCE_FILES "Source/main.cpp" "Resource/Resource.cpp" "Source/AboutInfoWidget.cpp" "Source/MainWindow.cpp")
add_executable(QBL-Station ${SOURCE_FILES} "Resource/AppIcon.o")

target_link_libraries(QBL-Station Qt5::Widgets Qt5::SerialPort Qt5::Charts)