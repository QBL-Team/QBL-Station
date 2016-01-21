#ifndef SERIAL_PORT_SELECTER_H
#define SERIAL_PORT_SELECTER_H

#include <QObject>
#include <QMenu>
#include <QAction>
#include <QList>
#include <QSerialPortInfo>

/*!
 * \brief The serial_port_selecter 提供了端口选择功能
 */

class serial_port_selecter : public QObject
{
    Q_OBJECT
public:
    explicit serial_port_selecter(QObject *parent = 0);

    /*!
     * \brief setPortMenu 设置将要被填充端口信息的菜单
     * \param menu 用于放置端口信息的菜单
     */

    void setPortMenu(QMenu * menu);

private:
    /*!
     * \brief port_menu 视图上用于放置端口列表的菜单
     */
    QMenu * port_menu;

    /*!
     * \brief port_list 所有可用端口的列表
     */

    QList<QSerialPortInfo> port_list;

    /*!
     * \brief action_item_list 所有可用端口的集合列表（包含“无端口”）
     */
    QList<QAction *>       action_item_list;

    /*!
     * \brief port_current_selected 当前选中的端口的信息，若无可用端口，值为NULL
     */
    const QSerialPortInfo    *    port_current_selected;
signals:

public slots:

    /*!
     * \brief refreshPort 刷新当前可用端口，并将选项填充到菜单中
     */
    void refreshPort();

    /*!
     * \brief portSelected 端口选择菜单被点击
     * \param action 被触发的动作
     */
    void portSelected(QAction * action);
};

#endif // SERIAL_PORT_SELECTER_H
