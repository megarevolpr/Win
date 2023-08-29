/********************************************************************************
** Form generated from reading UI file 'faulttableinterface.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAULTTABLEINTERFACE_H
#define UI_FAULTTABLEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaultTableInterface
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *search_le;
    QPushButton *Search_btn;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QWidget *tab_4;
    QGridLayout *gridLayout_3;
    QTableWidget *tableWidget_2;
    QWidget *tab;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QMainWindow *FaultTableInterface)
    {
        if (FaultTableInterface->objectName().isEmpty())
            FaultTableInterface->setObjectName(QStringLiteral("FaultTableInterface"));
        FaultTableInterface->resize(1086, 623);
        centralwidget = new QWidget(FaultTableInterface);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        search_le = new QLineEdit(centralwidget);
        search_le->setObjectName(QStringLiteral("search_le"));
        search_le->setMinimumSize(QSize(0, 45));

        horizontalLayout->addWidget(search_le);

        Search_btn = new QPushButton(centralwidget);
        Search_btn->setObjectName(QStringLiteral("Search_btn"));
        Search_btn->setMinimumSize(QSize(0, 45));

        horizontalLayout->addWidget(Search_btn);


        verticalLayout_2->addLayout(horizontalLayout);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout = new QGridLayout(tab_3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableWidget = new QTableWidget(tab_3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setTextElideMode(Qt::ElideRight);

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_3 = new QGridLayout(tab_4);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tableWidget_2 = new QTableWidget(tab_4);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));

        gridLayout_3->addWidget(tableWidget_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_4 = new QGridLayout(tab);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        plainTextEdit = new QPlainTextEdit(tab);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(15);
        plainTextEdit->setFont(font);
        plainTextEdit->setReadOnly(true);

        verticalLayout->addWidget(plainTextEdit);


        gridLayout_4->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());

        verticalLayout_2->addWidget(tabWidget);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);

        FaultTableInterface->setCentralWidget(centralwidget);

        retranslateUi(FaultTableInterface);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FaultTableInterface);
    } // setupUi

    void retranslateUi(QMainWindow *FaultTableInterface)
    {
        FaultTableInterface->setWindowTitle(QApplication::translate("FaultTableInterface", "Fault description", Q_NULLPTR));
        search_le->setPlaceholderText(QApplication::translate("FaultTableInterface", "Please enter search keywords", Q_NULLPTR));
        Search_btn->setText(QApplication::translate("FaultTableInterface", "Search", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("FaultTableInterface", "DCAC Fault Description", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("FaultTableInterface", "DCDC Module Fault Description", Q_NULLPTR));
        plainTextEdit->setPlainText(QApplication::translate("FaultTableInterface", "Battery Cut-off Voltage Protection Logic Explanation for Grid-on and grid-off modes:\n"
"\n"
"Grid-on mode:\n"
"  When the battery discharges to the cut-off voltage minus 5V (e.g., if the cut-off voltage is 500V, discharge stops at 495V), an alarm \"Discharge Not Allowed\" will be triggered, and the DCAC converter output power will drop to 0.\n"
"  The \"Discharge Not Allowed\" alarm will be cleared when the battery voltage is greater than the discharge cut-off voltage plus the discharge hysteresis voltage or when the mode is changed to charging.\n"
"  When the battery is charged to the upper limit of the charging voltage, an alarm \"Charging Not Allowed\" will be triggered. If the DCAC is in charging mode, the charging power will drop to 0. If the DCAC is in discharge mode, it will not be affected.\n"
"  The \"Charging Not Allowed\" alarm will be cleared when the battery voltage is lower than the upper limit of the charging voltage minus the charging hysteresis voltage or when it is in discharge mode.\n"
"\n"
""
                        "Grid-off mode:\n"
"  When the battery discharges to the cut-off voltage minus 5V (e.g., if the cut-off voltage is 500V, discharge stops at 495V), an alarm \"Discharge Not Allowed\" will be triggered, and the DCAC converter will shut down. The \"Discharge Not Allowed\" alarm will be cleared when the battery voltage is greater than the discharge cut-off voltage plus the discharge hysteresis voltage. If there is no shutdown command, the system will resume operation.\n"
"  When the battery is charged to the upper limit of the charging voltage, an alarm \"Charging Not Allowed\" will be triggered. If the DCAC is in charging mode or in grid-off discharge mode, it will not be affected.\n"
"  The \"Charging Not Allowed\" alarm will be cleared when the battery voltage is lower than the upper limit of the charging voltage minus the charging hysteresis voltage.", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("FaultTableInterface", "Battery Protection Logic Explanation", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FaultTableInterface: public Ui_FaultTableInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAULTTABLEINTERFACE_H
