#include "MainVindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //串口管理器
    port_selecter = new SerialPortSelecter(this);
    port_selecter->setPortMenu(ui->menu_setting_port);

    //连接信号槽，端口操作菜单被触发时
    connect(port_selecter,&SerialPortSelecter::onPortSelected,this,&MainWindow::onPortSelected);

    //设置biao'qian标签，用于信息的展示
    statusBar()->addPermanentWidget(&status_bar_info_label,1);
    setStatusText("断开连接");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_exit_triggered()
{
    close();
}

void MainWindow::on_action_about_triggered()
{
    AboutInfoWidget * info = new AboutInfoWidget;
    info->setAttribute(Qt::WA_DeleteOnClose);
    info->show();
}

void MainWindow::onPortSelected(const QSerialPortInfo *port)
{
    if(NULL == port){
        setStatusText("断开连接");
        return;
    }

    setStatusText(port->portName() + " " + port->description() + " " + port->manufacturer());
}

void MainWindow::setStatusText(QString text)
{
    status_bar_info_label.setText(text);
}
