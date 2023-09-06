/********************************************************************************
** Form generated from reading UI file 'Menu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *Host_bt;
    QToolButton *RTDATA_bt;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *Record_bt;
    QToolButton *System_bt;
    QHBoxLayout *horizontalLayout;
    QToolButton *Open_bt;
    QToolButton *Standby_bt;
    QToolButton *Close_bt;

    void setupUi(QDialog *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QStringLiteral("Menu"));
        Menu->resize(364, 462);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Menu->sizePolicy().hasHeightForWidth());
        Menu->setSizePolicy(sizePolicy);
        Menu->setStyleSheet(QStringLiteral("background-color: rgb(171, 216, 255);"));
        gridLayout = new QGridLayout(Menu);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(Menu);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        Host_bt = new QToolButton(widget);
        Host_bt->setObjectName(QStringLiteral("Host_bt"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Host_bt->sizePolicy().hasHeightForWidth());
        Host_bt->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(13);
        Host_bt->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new_ui/UI/04-\345\261\217\345\271\225\346\240\241\345\207\206.png"), QSize(), QIcon::Normal, QIcon::Off);
        Host_bt->setIcon(icon);
        Host_bt->setIconSize(QSize(72, 72));
        Host_bt->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(Host_bt);

        RTDATA_bt = new QToolButton(widget);
        RTDATA_bt->setObjectName(QStringLiteral("RTDATA_bt"));
        sizePolicy1.setHeightForWidth(RTDATA_bt->sizePolicy().hasHeightForWidth());
        RTDATA_bt->setSizePolicy(sizePolicy1);
        RTDATA_bt->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new_ui/UI/03\345\256\236\346\227\266\345\212\237\347\216\207.png"), QSize(), QIcon::Normal, QIcon::Off);
        RTDATA_bt->setIcon(icon1);
        RTDATA_bt->setIconSize(QSize(72, 72));
        RTDATA_bt->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(RTDATA_bt);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        Record_bt = new QToolButton(widget);
        Record_bt->setObjectName(QStringLiteral("Record_bt"));
        sizePolicy1.setHeightForWidth(Record_bt->sizePolicy().hasHeightForWidth());
        Record_bt->setSizePolicy(sizePolicy1);
        Record_bt->setFont(font);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new_ui/UI/03-\345\216\206\345\217\262\350\256\260\345\275\225.png"), QSize(), QIcon::Normal, QIcon::Off);
        Record_bt->setIcon(icon2);
        Record_bt->setIconSize(QSize(72, 72));
        Record_bt->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(Record_bt);

        System_bt = new QToolButton(widget);
        System_bt->setObjectName(QStringLiteral("System_bt"));
        sizePolicy1.setHeightForWidth(System_bt->sizePolicy().hasHeightForWidth());
        System_bt->setSizePolicy(sizePolicy1);
        System_bt->setFont(font);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new_ui/UI/06-\347\263\273\347\273\237\350\256\276\347\275\256.png"), QSize(), QIcon::Normal, QIcon::Off);
        System_bt->setIcon(icon3);
        System_bt->setIconSize(QSize(72, 72));
        System_bt->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(System_bt);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);

        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        verticalLayout->addWidget(widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Open_bt = new QToolButton(Menu);
        Open_bt->setObjectName(QStringLiteral("Open_bt"));
        sizePolicy.setHeightForWidth(Open_bt->sizePolicy().hasHeightForWidth());
        Open_bt->setSizePolicy(sizePolicy);
        Open_bt->setFont(font);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new_ui/UI/\345\274\200\345\205\263\346\234\272-01.png"), QSize(), QIcon::Normal, QIcon::Off);
        Open_bt->setIcon(icon4);
        Open_bt->setIconSize(QSize(32, 32));
        Open_bt->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(Open_bt);

        Standby_bt = new QToolButton(Menu);
        Standby_bt->setObjectName(QStringLiteral("Standby_bt"));
        sizePolicy.setHeightForWidth(Standby_bt->sizePolicy().hasHeightForWidth());
        Standby_bt->setSizePolicy(sizePolicy);
        Standby_bt->setFont(font);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new_ui/UI/Power_Standby.png"), QSize(), QIcon::Normal, QIcon::Off);
        Standby_bt->setIcon(icon5);
        Standby_bt->setIconSize(QSize(32, 32));
        Standby_bt->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(Standby_bt);

        Close_bt = new QToolButton(Menu);
        Close_bt->setObjectName(QStringLiteral("Close_bt"));
        sizePolicy.setHeightForWidth(Close_bt->sizePolicy().hasHeightForWidth());
        Close_bt->setSizePolicy(sizePolicy);
        Close_bt->setFont(font);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new_ui/UI/\345\274\200\345\205\263\346\234\272-02.png"), QSize(), QIcon::Normal, QIcon::Off);
        Close_bt->setIcon(icon6);
        Close_bt->setIconSize(QSize(32, 32));
        Close_bt->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(Close_bt);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 4);
        verticalLayout->setStretch(1, 1);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QDialog *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "Form", Q_NULLPTR));
        Host_bt->setText(QApplication::translate("Menu", "Host", Q_NULLPTR));
        RTDATA_bt->setText(QApplication::translate("Menu", "Rt.Data", Q_NULLPTR));
        Record_bt->setText(QApplication::translate("Menu", "Record", Q_NULLPTR));
        System_bt->setText(QApplication::translate("Menu", "System", Q_NULLPTR));
        Open_bt->setText(QApplication::translate("Menu", "Turn on", Q_NULLPTR));
        Standby_bt->setText(QApplication::translate("Menu", "Stand-by", Q_NULLPTR));
        Close_bt->setText(QApplication::translate("Menu", "Turn off", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
