/********************************************************************************
** Form generated from reading UI file 'powergridexpansion.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POWERGRIDEXPANSION_H
#define UI_POWERGRIDEXPANSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PowerGridExpansion
{
public:
    QWidget *centralwidget;
    QLabel *label;

    void setupUi(QMainWindow *PowerGridExpansion)
    {
        if (PowerGridExpansion->objectName().isEmpty())
            PowerGridExpansion->setObjectName(QStringLiteral("PowerGridExpansion"));
        PowerGridExpansion->resize(1060, 615);
        centralwidget = new QWidget(PowerGridExpansion);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 60, 731, 491));
        label->setStyleSheet(QString::fromUtf8("image: url(:/new_ui/UI/\347\224\265\347\275\221\346\211\251\345\256\271\351\200\273\350\276\221\345\233\276.png);"));
        PowerGridExpansion->setCentralWidget(centralwidget);

        retranslateUi(PowerGridExpansion);

        QMetaObject::connectSlotsByName(PowerGridExpansion);
    } // setupUi

    void retranslateUi(QMainWindow *PowerGridExpansion)
    {
        PowerGridExpansion->setWindowTitle(QApplication::translate("PowerGridExpansion", "MainWindow", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PowerGridExpansion: public Ui_PowerGridExpansion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POWERGRIDEXPANSION_H
