//
// Created by Huang on 2016/1/23.
//

#include <QAction>
#include <QMenu>
#include <QDebug>
#include "MainWindow.h"
#include "AboutInfoWidget.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    ui = new Ui::MainWindow;
    ui->setupUi(this);

    serial_port_manager = new SerialPortManager;

    //构建状态栏永久信息显示标签
    statusBar()->addPermanentWidget(&label_statusbar_info, 1);
    connectSignals();
    setStatusBarText("断开连接");
}

void MainWindow::showAboutInfo(void) {
    AboutInfoWidget *aboutInfoWidget = new AboutInfoWidget(NULL);
    aboutInfoWidget->setAttribute(Qt::WA_DeleteOnClose, true);
    aboutInfoWidget->show();
}

MainWindow::~MainWindow() {
    delete ui;
    delete serial_port_manager;
}

void MainWindow::setStatusBarText(const QString &text) {
    label_statusbar_info.setText(text);
}

void MainWindow::connectSignals() {
    //关联关于菜单和显示关于菜单
    connect(ui->action_help_about, SIGNAL(triggered(bool)), this, SLOT(showAboutInfo()));
    //关联退出菜单和窗口关闭功能
    connect(ui->action_file_exit, SIGNAL(triggered(bool)), this, SLOT(close()));
    connect(ui->menu_setting_port,SIGNAL(aboutToShow()),this,SLOT(clearMenuSettingPort()));
    //关联端口列表菜单和串口管理器的刷新串口功能
    connect(ui->menu_setting_port,SIGNAL(aboutToShow()),serial_port_manager,SLOT(refreshAvaliablePort()));

    //注册数据类型用以信号槽传递
    qRegisterMetaType<QList<QAction *>>("QList<QAction *>");
    //刷新端口完成，将端口列表返回系统界面
    connect(serial_port_manager,SIGNAL(onAvaliablePortRefreshed(QList<QAction *>)),this,SLOT(
            showMenuSettingPort(QList<QAction *>)));

    //用户选择了某一端口，
    connect(ui->menu_setting_port,SIGNAL(triggered(QAction *)),serial_port_manager,SLOT(onPortSelected(QAction * )));
    //将端口状态反馈到主界面的状态栏
    connect(serial_port_manager,SIGNAL(onPortSelectionChanged(const QString &)),this,SLOT(setStatusBarText(const QString &)));
}


void MainWindow::clearMenuSettingPort() {
    ui->menu_setting_port->clear();
}

void MainWindow::showMenuSettingPort(QList<QAction *> list) {
    ui->menu_setting_port->addActions(list);
}
