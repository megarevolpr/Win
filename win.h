#ifndef MEGAWIN_H
#define MEGAWIN_H

#include <QWidget>
#include <QComboBox>
#include <QPair>
#include <QList>
#include "Menu.h"
#include "msgbox.h"


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
    ~MEGAWin();

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

        Menu *m_menu;


        QComboBox *combox_ui_OnOff_Grid;//并离网

        QPushButton *Phase_C_power_btn;
        QPushButton *AdvancedSetup_btn;//高级设置入口

        QPushButton *Constant_power_explain;    //功率说明

        QList<QPair<QPushButton *, int> > PCS_pairList;
        QList<QString> hand_name;
        QList<QString> btn_explain;

        //实时数据
        QPushButton *PCS_vol_AB_btn;
        QPushButton *PCS_vol_BC_btn;
        QPushButton *PCS_vol_CA_btn;
        QPushButton *PCS_cur_A_btn;
        QPushButton *PCS_cur_B_btn;
        QPushButton *PCS_cur_C_btn;
        QPushButton *PCS_act_P_btn;     //有功功率
        QPushButton *PCS_rea_P_btn;     //无功功率
        QPushButton *PCS_par_P_btn;     //视在功率
        QPushButton *PCS_Pf_btn;        //功率因数
        QPushButton *PCS_Bat_vol_btn;   //电池电压
        QPushButton *PCS_Bat_cur_btn;   //电池电流
        QPushButton *PCS_Bat_P_btn;     //电池功率
        QPushButton *PCS_Bus_vol_btn;   //母线电压
        QPushButton *PCS_IGBT_T_btn;    //IGBT温度
        QPushButton *PCS_Env_T_btn;     //环境温度

        QButtonGroup* pButtonGroup;//PCS_data的button组
//        QButtonGroup* pButtonGroup1;//Battery_data的button组

        QPushButton *Grid_vol_AB_btn;     //
        QPushButton *Grid_vol_BC_btn;
        QPushButton *Grid_vol_CA_btn;
        QPushButton *Grid_cur_A_btn;
        QPushButton *Grid_cur_B_btn;
        QPushButton *Grid_cur_C_btn;
        QPushButton *Grid_act_P_btn;     //有功功率
        QPushButton *Grid_rea_P_btn;     //无功功率
        QPushButton *Grid_app_P_btn;     //视在功率
        QPushButton *Grid_fre_btn;
        QPushButton *Grid_Pf_btn;


        QPushButton *Load_vol_AB_btn;     //
        QPushButton *Load_vol_BC_btn;
        QPushButton *Load_vol_CA_btn;
        QPushButton *Load_cur_A_btn;
        QPushButton *Load_cur_B_btn;
        QPushButton *Load_cur_C_btn;
        QPushButton *Load_act_P_btn;     //有功功率
        QPushButton *Load_rea_P_btn;     //无功功率
        QPushButton *Load_app_P_btn;     //视在功率
        QPushButton *Load_fre_btn;
        QPushButton *Load_Pf_btn;




        void UIPageInit();//初始化界面
        void VariableInit();//初始化变量

        void MemoryAllocation();

        void FirstPage();
        void RunStatePage();

        void SystemSettingPage();//系统设置界面
        void LCDSetting();  //LCD标签初始化和定时器设置

        void LinkRelationship();
        void ModuleData_Tab();//模块数据表格初始化

        void ModuleState_Tab();//实时状态表初始化
        void UserParam_tab();//一般设置表初始化


        void EquipmentInfor_tab();//设备信息表初始化
        void BatterySet_tab();//电池设置表初始化
        void RunTimeSet_tab();//系统自动运行表初始化


        void RTData_Anologe();//实时模拟量数据
        void RTData_Status();//实时状态量数据

private:
        void RTDataDisplay();
        void Information_tbnt_released(); //系统信息槽
        void GeneralParam_tbnt_released();  //一般参数槽

private slots:
    void onTimerOut();
    void updateTimeOut();                       //Fun(Time)
//    void combox_OutPower_change();
//    void PasswordLimit();
    void My_menuAction(int Index);
//    bool PasswordCheck();
    void SystemParam_tbnt_released();

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

    void on_Run_tabWidget_tabBarClicked(int index); //实时数据界面选项卡点击响应
    void combox_ControlMode_change();
    void Constant_power_explain_clicked();//功率说明
    void Phase_C_power_btn_clicked();//C相功率
    void AdvancedSetup_btn_clicked();//高级
    void ToSetButton();

    /******************************PCS数据********************************/
    void slot_btnGroupClicked(int);

    void on_System_tabWidget_currentChanged(int index);

private:
    Ui::MEGAWin *ui;

    QTimer *timer;
//    QTimer *timer2;
    QTimer *Update_RTData_timer;
    QTime *current_time;

};

#endif // MEGAWIN_H
