#ifndef TABCONTAINER_H
#define TABCONTAINER_H

#include <QTabWidget>

namespace Ui {
class TabContainer;
}

class TabContainer : public QTabWidget
{
    Q_OBJECT

public:
    explicit TabContainer(QWidget *parent = 0);
    ~TabContainer();

private:
    Ui::TabContainer *ui;
};

#endif // TABCONTAINER_H
