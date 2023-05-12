#ifndef MEGAWIN_H
#define MEGAWIN_H

#include <QWidget>
#include <QComboBox>
#include <QPair>
#include <QList>
#include "Menu.h"
#include "msgbox.h"
#include "Specification/Specification.h"


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


//        QString combox_ui_GridMode_str;
//        QComboBox *combox_ui_GridMode;

//        QComboBox *combox_ui_OnOff_Grid;//并离网
//        QString combox_ui_OnOffGrid_str;    //并离网
//        QStringList ui_OnOff_Grid;
//        short combox_ui_OnOffGrid_index;

//        QComboBox *combox_ui_ChargeDischar; //充放电
//        QStringList ui_ChargeDischar;
//        QString combox_ui_ChargeDischar_str;
//        short combox_ui_ChargeDischar_index;

//        QComboBox *combox_RUN;              //运行模式
//        QStringList combox_Runmode;
//        QString combox_RUN_str;
//        short combox_RUN_index;

//        QString combox_ControlMode_str;
//        QComboBox *combox_ControlMode;      //控制模式
//        QStringList combox_CM;
//        short combox_ControlMode_index;


//        QComboBox * combox_MachineNumber;   //设备号
//        QStringList combox_MNumber;
//        QString MachineNumber_str;
//        short combox_MachineNumber_index;

//        QComboBox *combox_Parallel;         //并机
//        QStringList combox_Para;
//        QString combox_Parallel_str;
//        short combox_Parallel_index;

//        QComboBox *combox_UnbalancePowerEnable;//功率不平衡使能
//        QString combox_UnbalancePowerEnable_str;
//        short combox_UnbalancePowerEnable_index;

        Menu *m_menu;


        QPushButton *Grid_connected_mode_explain;//并网方式说明
        Specification *Grid_connected_mode;

        QPushButton *Constant_power_explain;     //功率说明
        Specification *Constant_power;



//        QPushButton *Grid_CM_of_PCS_explain;
//        QPushButton *Constant_power_explain;
//        QPushButton *Charg_and_Discharg_explain;
//        QPushButton *Work_mode_explain;
//        QPushButton *Output_power_factor_explain;
//        QPushButton *Output_reactive_power_explain;
//        QPushButton *Constant_current_explain;
//        QPushButton *Constant_voltage_explain;
//        QPushButton *Control_mode_explain;
//        QPushButton *Machine_number_explain;
//        QPushButton *Parallel_explain;
//        QPushButton *Unbalance_power_enable_explain;
//        QPushButton *Phase_A_power_explain;
//        QPushButton *Phase_B_power_explain;    //B相电压说明
//        QPushButton *Phase_C_power_explain;

//        Specification *Grid_CM_of_PCS;
//        Specification *Constant_power;
//        Specification *Charg_and_Discharg;
//        Specification *Work_mode;
//        Specification *Output_power_factor;
//        Specification *Output_reactive_power;
//        Specification *Constant_current;
//        Specification *Constant_voltage;
//        Specification *Control_mode;
//        Specification *Machine_number;
//        Specification *Parallel;
//        Specification *Unbalance_power_enable;
//        Specification *Phase_A_power;
//        Specification *Phase_B_power;
//        Specification *Phase_C_power;
        /***************************功能设置**************************/
        QPushButton *Battery_type_explain;
        QPushButton *BMS_Comm_type_explain;
        QPushButton *Power_control_type_explain;
        QPushButton *EMS_Comm_type_explain;
        QPushButton *Output_power_limit_explain;
        QPushButton *BAT_manufacturers_explain;
        QPushButton *Power_Delta_explain;
        QPushButton *Charge_power_limit_explain;
        QPushButton *Discharge_power_limit_explain;
        QPushButton *Charge_Vol_upper_Limit_delta_explain;
        QPushButton *Discharge_Vol_lower_Limit_delta_explain;
        QPushButton *Host_Address_explain;
        QPushButton *serial_port_1_explain;
        QPushButton *serial_port_2_explain;
        QPushButton *serial_port_3_explain;
        QPushButton *serial_port_4_explain;
        QPushButton *serial_port_5_explain;
        QPushButton *Can_port_1_explain;
        QPushButton *Can_port_2_explain;
        QPushButton *ProtocolVersion_explain;
        QPushButton *UserPassPort_explain;
        QPushButton *RootPassport_explain;
        QPushButton *Language_explain;
        QPushButton *System_upgrade_explain;
        QPushButton *Sounds_explain;
        QPushButton *DryContact_explain;

        Specification *Battery_type;
        Specification *BMS_Comm_type;
        Specification *Power_control_type;
        Specification *EMS_Comm_type;
        Specification *Output_power_limit;
        Specification *BAT_manufacturers;
        Specification *Power_Delta;
        Specification *Charge_power_limit;
        Specification *Discharge_power_limit;
        Specification *Charge_Vol_upper_Limit_delta;
        Specification *Discharge_Vol_lower_Limit_delta;
        Specification *Host_Address;
        Specification *serial_port_1;
        Specification *serial_port_2;
        Specification *serial_port_3;
        Specification *serial_port_4;
        Specification *serial_port_5;
        Specification *Can_port_1;
        Specification *Can_port_2;
        Specification *ProtocolVersion;
        Specification *UserPassPort;
        Specification *RootPassport;
        Specification *Language;
        Specification *System_upgrade;
        Specification *Sounds;
        Specification *DryContact;

        /***************************系统参数**************************/
        QPushButton *Change_rate_of_power_explain;
        QPushButton *Grid_frequency_upper_limit_explain;
        QPushButton *Grid_frequency_lower_limit_explain;
        QPushButton *Vol_protection_upper_limit_explain;
        QPushButton *Vol_protection_lower_limit_explain;
        QPushButton *HVRT_enable_explain;
        QPushButton *LVRT_enable_explain;
        QPushButton *AFD_enable_explain;
        QPushButton *Insulation_detection_enable_explain;
        QPushButton *PrimaryFreq_enable_explain;
        QPushButton *Inertia_enable_explain;
        QPushButton *CV_parallel_explain;
        QPushButton *Machine_type_explain;
        QPushButton *Machine_capacity_explain;
        QPushButton *Output_Fre_grade_explain;
        QPushButton *Output_vol_level_explain;
        QPushButton *Converter_side_vol_level_explain;
        QPushButton *Output_reactive_power_mode_explain;
        QPushButton *Grid_connected_mode_of_Inv_explain;
        QPushButton *Primary_FM_dead_zone_explain;
        QPushButton *PFM_coeff_explain;
        QPushButton *Grid_recover_time_explain;
        QPushButton *DynamicCap_explain;
        QPushButton *Module_Number_explain;
        QPushButton *Restore_factory_explain;
        QPushButton *Clear_Data_explain;

        Specification *Change_rate_of_power;
        Specification *Grid_frequency_upper_limit;
        Specification *Grid_frequency_lower_limit;
        Specification *Vol_protection_upper_limit;
        Specification *Vol_protection_lower_limit;
        Specification *HVRT_enable;
        Specification *LVRT_enable;
        Specification *AFD_enable;
        Specification *Insulation_detection_enable;
        Specification *PrimaryFreq_enable;
        Specification *Inertia_enable;
        Specification *CV_parallel;
        Specification *Machine_type;
        Specification *Machine_capacity;
        Specification *Output_Fre_grade;
        Specification *Output_vol_level;
        Specification *Converter_side_vol_level;
        Specification *Output_reactive_power_mode;
        Specification *Grid_connected_mode_of_Inv;
        Specification *Primary_FM_dead_zone;
        Specification *PFM_coeff;
        Specification *Grid_recover_time;
        Specification *DynamicCap;
        Specification *Module_Number;
        Specification *Restore_factory;
        Specification *Clear_Data;
        /***************************外设**************************/
        QPushButton *DI_1_Enable_explain;
        QPushButton *DI_2_Enable_explain;
        QPushButton *DI_3_Enable_explain;
        QPushButton *DI_4_Enable_explain;
        QPushButton *DI_5_Enable_explain;
        QPushButton *DI_6_Enable_explain;
        QPushButton *DO_1_Enable_explain;
        QPushButton *DO_2_Enable_explain;
        QPushButton *DO_3_Enable_explain;
        QPushButton *DI_1_NC_O_explain;
        QPushButton *DI_2_NC_O_explain;
        QPushButton *DI_3_NC_O_explain;
        QPushButton *DI_4_NC_O_explain;
        QPushButton *DI_5_NC_O_explain;
        QPushButton *DI_6_NC_O_explain;
        QPushButton *DO_1_NC_O_explain;
        QPushButton *DO_2_NC_O_explain;
        QPushButton *DO_3_NC_O_explain;
        QPushButton *DI_1_Action_explain;
        QPushButton *DI_2_Action_explain;
        QPushButton *DI_3_Action_explain;
        QPushButton *DI_4_Action_explain;
        QPushButton *DI_5_Action_explain;
        QPushButton *DI_6_Action_explain;
        QPushButton *DO_1_Action_explain;
        QPushButton *DO_2_Action_explain;
        QPushButton *DO_3_Action_explain;

        Specification *DI_1_Enable;
        Specification *DI_2_Enable;
        Specification *DI_3_Enable;
        Specification *DI_4_Enable;
        Specification *DI_5_Enable;
        Specification *DI_6_Enable;
        Specification *DO_1_Enable;
        Specification *DO_2_Enable;
        Specification *DO_3_Enable;
        Specification *DI_1_NC_O;
        Specification *DI_2_NC_O;
        Specification *DI_3_NC_O;
        Specification *DI_4_NC_O;
        Specification *DI_5_NC_O;
        Specification *DI_6_NC_O;
        Specification *DO_1_NC_O;
        Specification *DO_2_NC_O;
        Specification *DO_3_NC_O;
        Specification *DI_1_Action;
        Specification *DI_2_Action;
        Specification *DI_3_Action;
        Specification *DI_4_Action;
        Specification *DI_5_Action;
        Specification *DI_6_Action;
        Specification *DO_1_Action;
        Specification *DO_2_Action;
        Specification *DO_3_Action;
        /***************************BMS保护**************************/
        /***************************系统参数**************************/
        /***************************调试**************************/
        /***************************监控调试**************************/

        QPushButton *Charging_and_discharging_explain;  //充放电说明
        Specification *Charging_and_discharging;

        QPushButton *Work_mode_explain;  //工作模式说明
        Specification *Work_mode;

        QPushButton *Output_power_factor_explain;    //输出功率因素说明
        Specification *Output_power_factor;

        QPushButton *Output_reactive_power_explain;  //输出无功功率说明
        Specification *Output_reactive_power;

        QPushButton *Constant_current_explain;  //恒流说明
        Specification *Constant_current;

        QPushButton *Constant_voltage_explain; //恒压说明
        Specification *Constant_voltage;

        QPushButton *Control_mode_explain;  //控制模式说明
        Specification *Control_mode;

        QPushButton *Machine_number_explain;    //设备号说明
        Specification *Machine_number;

        QPushButton *Parallel_explain;  //并机说明
        Specification *Parallel;

        QPushButton *Unbalance_power_enable_explain;    //功率不平衡使能说明
        Specification *Unbalance_power_enable;

        QPushButton *Phase_A_power_explain;      //A相功率说明
        Specification *Phase_A_power;

        QPushButton *Phase_B_power_explain;      //B相功率说明
        Specification *Phase_B_power;


        QPushButton *Phase_C_power_explain;      //C相功率说明
        Specification *Phase_C_power;

        QPushButton *AdvancedSetup_btn;//高级设置入口

//        QList<QPair<QPushButton *, int> > PCS_pairList;
//        QList<QString> hand_name;
//        QList<QString> btn_explain;

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
//    void Constant_power_explain_clicked();//功率说明
//    void Phase_C_power_btn_clicked();//C相功率
    void AdvancedSetup_btn_clicked();//高级
    void ToSetButton();

    /******************************PCS数据********************************/
//    void slot_btnGroupClicked(int);

    void on_System_tabWidget_currentChanged(int index);

private:
    Ui::MEGAWin *ui;

    QTimer *timer;
//    QTimer *timer2;
    QTimer *Update_RTData_timer;
    QTime *current_time;

};

#endif // MEGAWIN_H
