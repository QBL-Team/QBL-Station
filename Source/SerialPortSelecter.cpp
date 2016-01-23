#include "SerialPortSelecter.h"
#include <QDebug>
#include "MainVindow.h"

SerialPortSelecter::SerialPortSelecter(QObject *parent)
{
    setParent(parent);
    port_menu = NULL;
    port_current_selected = NULL;
}

void SerialPortSelecter::setPortMenu(QMenu *menu)
{
    port_menu = menu;
    connect(port_menu,&QMenu::aboutToShow,this,&SerialPortSelecter::refreshPort);
    connect(port_menu,&QMenu::triggered,this,&SerialPortSelecter::portSelected);
}

void SerialPortSelecter::refreshPort()
{
    if(NULL != port_menu){

        //清理掉旧的列表信息

        port_menu->clear();

        for(quint8 i = 0;i < action_item_list.length();i++)
        {
            delete action_item_list.at(i);
        }
        action_item_list.clear();

        //构建新的端口列表，第一个元素为无端口
        action_item_list.append(new QAction("断开连接",NULL));   //注意清理内存，防止内存溢出

        //刷新可用端口信息
        port_list = QSerialPortInfo::availablePorts();

        for(quint8 i = 0;i < port_list.length();i++){
            action_item_list.append(new QAction(port_list.at(i).portName() + " " + port_list.at(i).description(),NULL));
        }
        //添加到菜单中
        port_menu->addActions(action_item_list);
    }
}

void SerialPortSelecter::portSelected(QAction *action)
{
    //当前选择的是空端口
    if(action == action_item_list.at(0)){
        port_current_selected = NULL;
    }

    else {

        for(quint8 i = 1;i < action_item_list.length();i++){
            if(action == action_item_list.at(i)){
                port_current_selected = &(port_list.at(i - 1));
                break;
            }
        }
    }
    emit onPortSelected(port_current_selected);
}
