#include "serial_port_selecter.h"
#include <QDebug>

serial_port_selecter::serial_port_selecter(QObject *parent)
{
    setParent(parent);
    port_menu = NULL;
    port_current_selected = NULL;
}

void serial_port_selecter::setPortMenu(QMenu *menu)
{
    port_menu = menu;
    connect(port_menu,&QMenu::aboutToShow,this,&serial_port_selecter::refreshPort);
    connect(port_menu,&QMenu::triggered,this,&serial_port_selecter::portSelected);
}

void serial_port_selecter::refreshPort()
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
        action_item_list.append(new QAction("无端口",NULL));   //注意清理内存，防止内存溢出

        //刷新可用端口信息
        port_list = QSerialPortInfo::availablePorts();

        for(quint8 i = 0;i < port_list.length();i++){
            action_item_list.append(new QAction(port_list.at(i).portName() + " " + port_list.at(i).description(),NULL));
        }
        //添加到菜单中
        port_menu->addActions(action_item_list);
    }
}

void serial_port_selecter::portSelected(QAction *action)
{
    //当前选择的是空端口
    if(action == action_item_list.at(0)){
        port_current_selected = NULL;
        return;
    }

    //

    for(quint8 i = 1;i < action_item_list.length();i++){
        if(action == action_item_list.at(i)){
            port_current_selected = &(port_list.at(i - 1));
            break;
        }
    }

}
