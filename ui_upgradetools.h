/********************************************************************************
** Form generated from reading UI file 'upgradetools.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPGRADETOOLS_H
#define UI_UPGRADETOOLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UpgradeTools
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *MPS;
    QGridLayout *gridLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *Message_label;
    QPlainTextEdit *plainTextEdit;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Modnum_label;
    QSpinBox *spinBox;
    QPushButton *DCDC_btn;
    QPushButton *DCAC_btn;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Monitor_btn;
    QPushButton *Backup_btn;
    QPushButton *Restore_btn;
    QPushButton *Apply_btn;
    QProgressBar *progressBar;
    QWidget *MEGA;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *Modnum_label_2;
    QSpinBox *spinBox_2;
    QLabel *Message_label_2;
    QPlainTextEdit *plainTextEdit_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *Monitor_hex_btn;
    QPushButton *DSP_hex_btn;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QPushButton *BaudRate_btn;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *Monitor_btn_2;
    QPushButton *Backup_btn_2;
    QPushButton *Restore_btn_2;
    QPushButton *PCS_btn;
    QPushButton *Apply_btn_2;
    QProgressBar *progressBar_2;

    void setupUi(QMainWindow *UpgradeTools)
    {
        if (UpgradeTools->objectName().isEmpty())
            UpgradeTools->setObjectName(QStringLiteral("UpgradeTools"));
        UpgradeTools->resize(1034, 653);
        centralwidget = new QWidget(UpgradeTools);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setStyleSheet(QStringLiteral("background-color: rgb(230, 230, 230);"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        MPS = new QWidget();
        MPS->setObjectName(QStringLiteral("MPS"));
        gridLayout = new QGridLayout(MPS);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(MPS);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 35));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QLatin1String("background-color: rgb(240, 160, 0);\n"
"color: rgb(97, 0, 167);"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        Message_label = new QLabel(MPS);
        Message_label->setObjectName(QStringLiteral("Message_label"));
        Message_label->setMinimumSize(QSize(530, 0));
        Message_label->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        Message_label->setFont(font1);
        Message_label->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(Message_label);

        plainTextEdit = new QPlainTextEdit(MPS);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setMinimumSize(QSize(530, 0));
        plainTextEdit->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setPointSize(12);
        plainTextEdit->setFont(font2);
        plainTextEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        plainTextEdit->setReadOnly(true);

        verticalLayout_3->addWidget(plainTextEdit);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        Modnum_label = new QLabel(MPS);
        Modnum_label->setObjectName(QStringLiteral("Modnum_label"));
        QFont font3;
        font3.setPointSize(14);
        Modnum_label->setFont(font3);
        Modnum_label->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        Modnum_label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(Modnum_label);

        spinBox = new QSpinBox(MPS);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimumSize(QSize(0, 96));
        spinBox->setFont(font3);
        spinBox->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        spinBox->setAlignment(Qt::AlignCenter);
        spinBox->setMinimum(1);
        spinBox->setMaximum(99);
        spinBox->setValue(1);

        horizontalLayout_2->addWidget(spinBox);


        verticalLayout_2->addLayout(horizontalLayout_2);

        DCDC_btn = new QPushButton(MPS);
        DCDC_btn->setObjectName(QStringLiteral("DCDC_btn"));
        DCDC_btn->setMinimumSize(QSize(450, 96));
        DCDC_btn->setFont(font3);
        DCDC_btn->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(DCDC_btn);

        DCAC_btn = new QPushButton(MPS);
        DCAC_btn->setObjectName(QStringLiteral("DCAC_btn"));
        DCAC_btn->setMinimumSize(QSize(0, 96));
        DCAC_btn->setFont(font3);
        DCAC_btn->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(DCAC_btn);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        Monitor_btn = new QPushButton(MPS);
        Monitor_btn->setObjectName(QStringLiteral("Monitor_btn"));
        Monitor_btn->setMinimumSize(QSize(0, 96));
        Monitor_btn->setFont(font3);
        Monitor_btn->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(Monitor_btn);

        Backup_btn = new QPushButton(MPS);
        Backup_btn->setObjectName(QStringLiteral("Backup_btn"));
        Backup_btn->setMinimumSize(QSize(0, 96));
        Backup_btn->setFont(font3);
        Backup_btn->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(Backup_btn);

        Restore_btn = new QPushButton(MPS);
        Restore_btn->setObjectName(QStringLiteral("Restore_btn"));
        Restore_btn->setMinimumSize(QSize(0, 96));
        Restore_btn->setFont(font3);
        Restore_btn->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(Restore_btn);


        verticalLayout_2->addLayout(horizontalLayout_3);

        Apply_btn = new QPushButton(MPS);
        Apply_btn->setObjectName(QStringLiteral("Apply_btn"));
        Apply_btn->setMinimumSize(QSize(0, 96));
        Apply_btn->setFont(font3);
        Apply_btn->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(Apply_btn);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        progressBar = new QProgressBar(MPS);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMinimumSize(QSize(980, 0));
        progressBar->setMaximumSize(QSize(16777215, 16777215));
        QFont font4;
        font4.setPointSize(8);
        progressBar->setFont(font4);
        progressBar->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(255, 255, 255);"));
        progressBar->setValue(75);
        progressBar->setAlignment(Qt::AlignCenter);
        progressBar->setTextVisible(true);
        progressBar->setInvertedAppearance(false);
        progressBar->setTextDirection(QProgressBar::TopToBottom);

        gridLayout->addWidget(progressBar, 2, 0, 1, 1);

        tabWidget->addTab(MPS, QString());
        MEGA = new QWidget();
        MEGA->setObjectName(QStringLiteral("MEGA"));
        gridLayout_3 = new QGridLayout(MEGA);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_6 = new QLabel(MEGA);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(0, 35));
        label_6->setFont(font);
        label_6->setStyleSheet(QLatin1String("background-color: rgb(240, 160, 0);\n"
"color: rgb(97, 0, 167);"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        Modnum_label_2 = new QLabel(MEGA);
        Modnum_label_2->setObjectName(QStringLiteral("Modnum_label_2"));
        Modnum_label_2->setFont(font3);
        Modnum_label_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        Modnum_label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(Modnum_label_2);

        spinBox_2 = new QSpinBox(MEGA);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMinimumSize(QSize(0, 96));
        spinBox_2->setFont(font3);
        spinBox_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        spinBox_2->setAlignment(Qt::AlignCenter);
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(99);
        spinBox_2->setValue(1);

        horizontalLayout_5->addWidget(spinBox_2);


        verticalLayout_4->addLayout(horizontalLayout_5);

        Message_label_2 = new QLabel(MEGA);
        Message_label_2->setObjectName(QStringLiteral("Message_label_2"));
        Message_label_2->setMinimumSize(QSize(530, 0));
        Message_label_2->setMaximumSize(QSize(16777215, 16777215));
        Message_label_2->setFont(font1);
        Message_label_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        verticalLayout_4->addWidget(Message_label_2);

        plainTextEdit_2 = new QPlainTextEdit(MEGA);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setMinimumSize(QSize(530, 0));
        plainTextEdit_2->setMaximumSize(QSize(16777215, 16777215));
        plainTextEdit_2->setFont(font2);
        plainTextEdit_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        plainTextEdit_2->setReadOnly(true);

        verticalLayout_4->addWidget(plainTextEdit_2);


        horizontalLayout_4->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        Monitor_hex_btn = new QPushButton(MEGA);
        Monitor_hex_btn->setObjectName(QStringLiteral("Monitor_hex_btn"));
        Monitor_hex_btn->setMinimumSize(QSize(0, 96));
        Monitor_hex_btn->setFont(font3);
        Monitor_hex_btn->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout_7->addWidget(Monitor_hex_btn);

        DSP_hex_btn = new QPushButton(MEGA);
        DSP_hex_btn->setObjectName(QStringLiteral("DSP_hex_btn"));
        DSP_hex_btn->setMinimumSize(QSize(0, 96));
        DSP_hex_btn->setFont(font3);
        DSP_hex_btn->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout_7->addWidget(DSP_hex_btn);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_9 = new QLabel(MEGA);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(0, 96));
        label_9->setFont(font3);
        label_9->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_9);

        BaudRate_btn = new QPushButton(MEGA);
        BaudRate_btn->setObjectName(QStringLiteral("BaudRate_btn"));
        BaudRate_btn->setMinimumSize(QSize(0, 96));
        BaudRate_btn->setFont(font3);
        BaudRate_btn->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout_8->addWidget(BaudRate_btn);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        Monitor_btn_2 = new QPushButton(MEGA);
        Monitor_btn_2->setObjectName(QStringLiteral("Monitor_btn_2"));
        Monitor_btn_2->setMinimumSize(QSize(0, 96));
        Monitor_btn_2->setFont(font3);
        Monitor_btn_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout_6->addWidget(Monitor_btn_2);

        Backup_btn_2 = new QPushButton(MEGA);
        Backup_btn_2->setObjectName(QStringLiteral("Backup_btn_2"));
        Backup_btn_2->setMinimumSize(QSize(0, 96));
        Backup_btn_2->setFont(font3);
        Backup_btn_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout_6->addWidget(Backup_btn_2);

        Restore_btn_2 = new QPushButton(MEGA);
        Restore_btn_2->setObjectName(QStringLiteral("Restore_btn_2"));
        Restore_btn_2->setMinimumSize(QSize(0, 96));
        Restore_btn_2->setFont(font3);
        Restore_btn_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout_6->addWidget(Restore_btn_2);


        verticalLayout_5->addLayout(horizontalLayout_6);

        PCS_btn = new QPushButton(MEGA);
        PCS_btn->setObjectName(QStringLiteral("PCS_btn"));
        PCS_btn->setMinimumSize(QSize(0, 96));
        PCS_btn->setFont(font3);
        PCS_btn->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        verticalLayout_5->addWidget(PCS_btn);

        Apply_btn_2 = new QPushButton(MEGA);
        Apply_btn_2->setObjectName(QStringLiteral("Apply_btn_2"));
        Apply_btn_2->setMinimumSize(QSize(0, 96));
        Apply_btn_2->setFont(font3);
        Apply_btn_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        verticalLayout_5->addWidget(Apply_btn_2);


        horizontalLayout_4->addLayout(verticalLayout_5);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);

        gridLayout_3->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        progressBar_2 = new QProgressBar(MEGA);
        progressBar_2->setObjectName(QStringLiteral("progressBar_2"));
        progressBar_2->setMinimumSize(QSize(980, 0));
        progressBar_2->setMaximumSize(QSize(16777215, 16777215));
        progressBar_2->setFont(font4);
        progressBar_2->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(255, 255, 255);"));
        progressBar_2->setValue(10);
        progressBar_2->setAlignment(Qt::AlignCenter);
        progressBar_2->setTextVisible(true);
        progressBar_2->setInvertedAppearance(false);
        progressBar_2->setTextDirection(QProgressBar::TopToBottom);

        gridLayout_3->addWidget(progressBar_2, 2, 0, 1, 1);

        tabWidget->addTab(MEGA, QString());

        gridLayout_2->addWidget(tabWidget, 0, 1, 1, 1);

        UpgradeTools->setCentralWidget(centralwidget);

        retranslateUi(UpgradeTools);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(UpgradeTools);
    } // setupUi

    void retranslateUi(QMainWindow *UpgradeTools)
    {
        UpgradeTools->setWindowTitle(QApplication::translate("UpgradeTools", "UpgradeTools", Q_NULLPTR));
        label->setText(QApplication::translate("UpgradeTools", "MPS Upgrade app V2.0", Q_NULLPTR));
        Message_label->setText(QApplication::translate("UpgradeTools", " Message:", Q_NULLPTR));
        plainTextEdit->setPlainText(QApplication::translate("UpgradeTools", " Mounting finished \n"
" File checked ok \n"
" Monitor Upadate file not exited \n"
" DCAC Upadate file ready \n"
" DCDC Upadate file not exited \n"
" Start copying...\n"
"\n"
" DCAC_Update.hex \n"
" UPDATE_BEGIN \n"
" Unknown signal received \n"
" Unknown signal received \n"
" Unknown signal received \n"
" ERASE GOING \n"
" ERASE GOING \n"
" BLOCK_DATATRANS_END\n"
" BLOCK_CHECKSUM_OK \n"
" BLOCK_CHECKSUM_OK\n"
" BLOCK_HEAD_OK\n"
" BLOCK_CHECKSUM_OK\n"
" BLOCK_DATATRANS_END\n"
" BLOCK_HEAD_OK \n"
"", Q_NULLPTR));
        Modnum_label->setText(QApplication::translate("UpgradeTools", "Module number", Q_NULLPTR));
        DCDC_btn->setText(QApplication::translate("UpgradeTools", "DCDC Upgrade", Q_NULLPTR));
        DCAC_btn->setText(QApplication::translate("UpgradeTools", "DCAC Upgrade", Q_NULLPTR));
        Monitor_btn->setText(QApplication::translate("UpgradeTools", "Monitor", Q_NULLPTR));
        Backup_btn->setText(QApplication::translate("UpgradeTools", "Backup", Q_NULLPTR));
        Restore_btn->setText(QApplication::translate("UpgradeTools", "Restore", Q_NULLPTR));
        Apply_btn->setText(QApplication::translate("UpgradeTools", "Apply and restart", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(MPS), QApplication::translate("UpgradeTools", "MPS", Q_NULLPTR));
        label_6->setText(QApplication::translate("UpgradeTools", "PCS Upgrade Tools V2.0", Q_NULLPTR));
        Modnum_label_2->setText(QApplication::translate("UpgradeTools", "Module number", Q_NULLPTR));
        Message_label_2->setText(QApplication::translate("UpgradeTools", " Message:", Q_NULLPTR));
        plainTextEdit_2->setPlainText(QApplication::translate("UpgradeTools", " Mounting finished \n"
" File checked ok \n"
" Monitor.hex not exited\n"
" DSPUpadate ok\n"
" Start copying...\n"
" \n"
" DSPUpdate.hex\n"
" UPDATE_BEGIN", Q_NULLPTR));
        Monitor_hex_btn->setText(QApplication::translate("UpgradeTools", "Monitor.hex", Q_NULLPTR));
        DSP_hex_btn->setText(QApplication::translate("UpgradeTools", "DSPUpdate.hex", Q_NULLPTR));
        label_9->setText(QApplication::translate("UpgradeTools", "Baud rate", Q_NULLPTR));
        BaudRate_btn->setText(QApplication::translate("UpgradeTools", "500k", Q_NULLPTR));
        Monitor_btn_2->setText(QApplication::translate("UpgradeTools", "Monitor", Q_NULLPTR));
        Backup_btn_2->setText(QApplication::translate("UpgradeTools", "Backup", Q_NULLPTR));
        Restore_btn_2->setText(QApplication::translate("UpgradeTools", "Restore", Q_NULLPTR));
        PCS_btn->setText(QApplication::translate("UpgradeTools", "DSP Upgrade", Q_NULLPTR));
        Apply_btn_2->setText(QApplication::translate("UpgradeTools", "Restart", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(MEGA), QApplication::translate("UpgradeTools", "PCS", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UpgradeTools: public Ui_UpgradeTools {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPGRADETOOLS_H
