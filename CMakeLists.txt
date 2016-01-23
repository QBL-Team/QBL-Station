cmake_minimum_required(VERSION 3.3)
project(QBL-Station)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -o2")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

#自动运行Qt库的预处理工�?set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

#设置编译后文件的输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)
link_directories(${LIBRARY_OUTPUT_PATH})

#载入使用的Qt�?find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5SerialPort REQUIRED)
find_package(Qt5Charts REQUIRED)

set(SOURCE_FILES main.cpp Source/MainWindow.cpp Source/MainWindow.h Source/AboutInfoWidget.cpp Source/AboutInfoWidget.h)
add_executable(QBL-Station ${SOURCE_FILES} "Misc/QBL-Station.o")


target_link_libraries(QBL-Station Qt5::Widgets Qt5::SerialPort Qt5::Core Qt5::Gui Qt5::Charts)