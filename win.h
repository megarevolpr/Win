#ifndef MEGAWIN_H
#define MEGAWIN_H

#include <QWidget>
#include "Menu.h"
#include <QComboBox>


//QComboBox * combox_OutPower;
//QComboBox *combox_ui_ChargeDischar;


#define CTL_STANDBY         0
#define CTL_CP_P            1
#define CTL_CP_NP           2
#define CTL_CC              3
#define CTL_CV              4






namespace Ui {
class MEGAWin;
}

class MEGAWin : public QWidget
{
    Q_OBJECT

public:
    explicit MEGAWin(QWidget *parent = nullptr);

        QString combox_ui_GridMode_str;
        QComboBox *combox_ui_GridMode;

        QString combox_ui_OnOffGrid_str;    //并离网
        QStringList ui_OnOff_Grid;
        short combox_ui_OnOffGrid_index;

        QComboBox *combox_ui_ChargeDischar; //充放电
        QStringList ui_ChargeDischar;
        QString combox_ui_ChargeDischar_str;
        short combox_ui_ChargeDischar_index;

        QComboBox *combox_RUN;              //运行模式
        QStringList combox_Runmode;
        QString combox_RUN_str;
        short combox_RUN_index;

        QString combox_ControlMode_str;
        QComboBox *combox_ControlMode;      //控制模式
        QStringList combox_CM;
        short combox_ControlMode_index;

        QComboBox * combox_MachineNumber;   //设备号
        QStringList combox_MNumber;
        QString MachineNumber_str;
        short combox_MachineNumber_index;

        QComboBox *combox_Parallel;         //并机
        QStringList combox_Para;
        QString combox_Parallel_str;
        short combox_Parallel_index;

        QComboBox *combox_UnbalancePowerEnable;//功率不平衡使能
        QString combox_UnbalancePowerEnable_str;
        short combox_UnbalancePowerEnable_index;



//        QString combox_UnbalancePowerEnable_str;
//        short combox_UnbalancePowerEnable_index;

        Menu *m_menu;

        void GeneralParam_tbnt_released();//一般参数槽

        QComboBox *combox_ui_OnOff_Grid;//并离网
        QPushButton *AdvancedSetup_btn;//高级设置



        void UIPageInit();//初始化界面
        void VariableInit();//初始化变量

        void MemoryAllocation();

        void FirstPage();

        void SystemSettingPage();//系统设置界面
        void LCDSetting();  //LCD标签初始化和定时器设置

        void LinkRelationship();

        void UserParam_tab();//一般设置表初始化


    ~MEGAWin();

private slots:
    void onTimerOut();
//    void combox_OutPower_change();
//    void PasswordLimit();
    void My_menuAction(int Index);
//    bool PasswordCheck();
    void SystemParam_tbnt_released();
    void AdvancedSetup_btn_clicked();
    void combox_ui_GridMode_change();
    void combox_ui_OnOff_Grid_change();//并离网

    void on_UI_MenuBtn_clicked();//转到槽
    void on_UI_Complete_Btn_clicked();//

    void on_Running_btn_clicked();//跳转变流器实时数据
    void on_Grid_clicked();//跳转电网实时数据
    void on_Load_clicked();//跳转负载实时数据
    void on_Batt_btn_pressed();//跳转到电池信息
    void on_Batt_btn_released();//跳转到电池信息

    void on_SConverter_btn_clicked();

    void on_SGrid_btn_clicked();

    void on_SLoad_btn_clicked();

    void on_TimeSeting_btn_released();

private:
    Ui::MEGAWin *ui;

    QTimer *timer;
//    QTimer *timer2;
    QTimer *Update_RTData_timer;
    QTime *current_time;

};

#endif // MEGAWIN_H
