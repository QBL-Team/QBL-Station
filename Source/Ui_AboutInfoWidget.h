/********************************************************************************
** Form generated from reading UI file 'AboutInfoWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTINFOWIDGET_H
#define UI_ABOUTINFOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutInfoWidget
{
public:
    QLabel *label_logo;
    QLabel *label_text;

    void setupUi(QWidget *AboutInfoWidget)
    {
        if (AboutInfoWidget->objectName().isEmpty())
            AboutInfoWidget->setObjectName(QStringLiteral("AboutInfoWidget"));
        AboutInfoWidget->resize(700, 322);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AboutInfoWidget->sizePolicy().hasHeightForWidth());
        AboutInfoWidget->setSizePolicy(sizePolicy);
        AboutInfoWidget->setMinimumSize(QSize(700, 322));
        AboutInfoWidget->setMaximumSize(QSize(700, 322));
        label_logo = new QLabel(AboutInfoWidget);
        label_logo->setObjectName(QStringLiteral("label_logo"));
        label_logo->setGeometry(QRect(30, 33, 240, 257));
        sizePolicy.setHeightForWidth(label_logo->sizePolicy().hasHeightForWidth());
        label_logo->setSizePolicy(sizePolicy);
        label_logo->setMinimumSize(QSize(240, 257));
        label_logo->setMaximumSize(QSize(240, 257));
        label_logo->setPixmap(QPixmap(QString::fromUtf8(":/image/app/image/app/QBL-Station.png")));
        label_logo->setScaledContents(true);
        label_text = new QLabel(AboutInfoWidget);
        label_text->setObjectName(QStringLiteral("label_text"));
        label_text->setGeometry(QRect(322, 0, 378, 322));
        label_text->setStyleSheet(QLatin1String("color: rgb(85, 170, 0);\n"
"font: 24pt \"Microsoft YaHei UI\";"));
        label_text->setScaledContents(false);
        label_text->setAlignment(Qt::AlignCenter);

        retranslateUi(AboutInfoWidget);

        QMetaObject::connectSlotsByName(AboutInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *AboutInfoWidget)
    {
        AboutInfoWidget->setWindowTitle(QApplication::translate("AboutInfoWidget", "\345\205\263\344\272\216QBL Station", 0));
        label_logo->setText(QString());
        label_text->setText(QApplication::translate("AboutInfoWidget", "QBL-Station\n"
"Powered by QBL-Team\n"
"\n"
"V0.0", 0));
    } // retranslateUi

};

namespace Ui {
    class AboutInfoWidget: public Ui_AboutInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTINFOWIDGET_H
