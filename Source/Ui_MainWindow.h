/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_file_exit;
    QAction *action_help_about;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu_help;
    QMenu *menu_file;
    QMenu *menu_setting;
    QMenu *menu_setting_port;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(709, 486);
        action_file_exit = new QAction(MainWindow);
        action_file_exit->setObjectName(QStringLiteral("action_file_exit"));
        action_help_about = new QAction(MainWindow);
        action_help_about->setObjectName(QStringLiteral("action_help_about"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 709, 23));
        menu_help = new QMenu(menuBar);
        menu_help->setObjectName(QStringLiteral("menu_help"));
        menu_file = new QMenu(menuBar);
        menu_file->setObjectName(QStringLiteral("menu_file"));
        menu_setting = new QMenu(menuBar);
        menu_setting->setObjectName(QStringLiteral("menu_setting"));
        menu_setting_port = new QMenu(menu_setting);
        menu_setting_port->setObjectName(QStringLiteral("menu_setting_port"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_file->menuAction());
        menuBar->addAction(menu_setting->menuAction());
        menuBar->addAction(menu_help->menuAction());
        menu_help->addAction(action_help_about);
        menu_file->addAction(action_file_exit);
        menu_setting->addAction(menu_setting_port->menuAction());

        retranslateUi(MainWindow);
        QObject::connect(action_file_exit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QBL Station", 0));
        action_file_exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
        action_help_about->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", 0));
#ifndef QT_NO_TOOLTIP
        action_help_about->setToolTip(QApplication::translate("MainWindow", "\345\205\263\344\272\216", 0));
#endif // QT_NO_TOOLTIP
        menu_help->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", 0));
        menu_file->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0));
        menu_setting->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256", 0));
        menu_setting_port->setTitle(QApplication::translate("MainWindow", "\347\253\257\345\217\243\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
