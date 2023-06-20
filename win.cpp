#include "win.h"
#include "ui_win.h"
#include <QMenu>
#include <QTime>
#include <QDate>
#include <QDateTime>
#include <QTimer>
#include <qlistview.h>
#include "UI_Menu/Menu.h"
#include <QDebug>
#include <QMessageBox>
#include <QButtonGroup>
#include <QApplication>

#define NULL_page   0
#define Machine_MEGA 1
#define Machine_MEGA_T 2
#define Machine_MEGA_TS 3
#define Machine_MEGA_TS_T 4

#define Analoge_PAGE  0
#define State_PAGE    1
#define Alarm_PAGE    2
#define BAT_PAGE      3

#define CHINESE     0
#define ENGLISH     1

#define qApp (static_cast<QApplication *>(QCoreApplication::instance()))

MEGAWin::MEGAWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MEGAWin)
{
    ASKey = true;
    LanguageType = CHINESE; //开机默认为中文

    ui->setupUi(this);
    ui->UI_stackedWidget->setCurrentWidget(ui->UI_page );//开机后进入主页面
    ui->stackedWidget->setCurrentWidget(ui->Bypass_page);
    ui->RTD_PCS_StackedWidget->setCurrentWidget(ui->RTD_Bypass_Y_page);
    ui->RTState_stackedWidget->setCurrentWidget(ui->RTState_Bypass_Y_page);

    MemoryAllocation(); //初始化内存空间
    LoadLanguageInit(); //初始化语言
    UIPageInit();       //初始化界面

}

MEGAWin::~MEGAWin()
{
    delete ui;
}

void MEGAWin::onTimerOut()//时间显示
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd HH:mm:ss");
    ui->TimeSeting_btn->setText(str);
}

void MEGAWin::updateTimeOut()
{
    RTDataDisplay();
}

/************************初始化内存空间********************************/
void MEGAWin::MemoryAllocation()
{
    m_menu = new Menu(this);

    /***************************数据报表&导出数据**********************************/

    pButton_History = new QButtonGroup();
    pButton_History->addButton(ui->Dis_D,0);
    pButton_History->addButton(ui->Dis_M,1);
    pButton_History->addButton(ui->Dis_Y,2);
    pButton_History->addButton(ui->Dis_T,3);
    pButton_History->addButton(ui->Char_D,4);
    pButton_History->addButton(ui->Char_M,5);
    pButton_History->addButton(ui->Char_Y,6);
    pButton_History->addButton(ui->Char_T,7);
    pButton_History->addButton(ui->Subtract_M,8);
    pButton_History->addButton(ui->Subtract_Y,9);
    pButton_History->addButton(ui->Day_btn,10);
    pButton_History->addButton(ui->Year_btn,11);
    pButton_History->addButton(ui->Add_M,12);
    pButton_History->addButton(ui->Add_Y,13);
    pButton_History->addButton(ui->Month_btn,14);
    pButton_History->addButton(ui->Total_btn,15);
    pButton_History->addButton(ui->OutPut_historyFailuer,16);
    pButton_History->addButton(ui->Output_OperationLog,17);
    pButton_History->addButton(ui->CoulombmeterReport_btn,18);
    pButton_History->addButton(ui->Eject_btn,19);

    /***************************历史记录**********************************/
    Grade_explain       = new QPushButton;
    Grade2_explain      = new QPushButton;
    Grade3_explain      = new QPushButton;
    Grade4_explain      = new QPushButton;
    Grade5_explain      = new QPushButton;
    Grade6_explain      = new QPushButton;
    Grade7_explain      = new QPushButton;
    Grade8_explain      = new QPushButton;
    StartTime_explain   = new QPushButton;
    StartTime2_explain  = new QPushButton;
    StartTime3_explain  = new QPushButton;
    StartTime4_explain  = new QPushButton;
    StartTime5_explain  = new QPushButton;
    StartTime6_explain  = new QPushButton;
    StartTime7_explain  = new QPushButton;
    StartTime8_explain  = new QPushButton;
    EndTime_explain     = new QPushButton;
    EndTime2_explain    = new QPushButton;
    EndTime3_explain    = new QPushButton;
    EndTime4_explain    = new QPushButton;
    EndTime5_explain    = new QPushButton;
    EndTime6_explain    = new QPushButton;
    EndTime7_explain    = new QPushButton;
    EndTime8_explain    = new QPushButton;
    Describe_explain    = new QPushButton;
    Describe2_explain   = new QPushButton;
    Describe3_explain   = new QPushButton;
    Describe4_explain   = new QPushButton;
    Describe5_explain   = new QPushButton;
    Describe6_explain   = new QPushButton;
    Describe7_explain   = new QPushButton;
    Describe8_explain   = new QPushButton;

    /***************************操作日志**********************************/
    ModificationTime_explain    = new QPushButton;
    ModificationTime2_explain   = new QPushButton;
    ModificationTime3_explain   = new QPushButton;
    ModificationTime4_explain   = new QPushButton;
    ModificationTime5_explain   = new QPushButton;
    ModificationTime6_explain   = new QPushButton;
    ModificationTime7_explain   = new QPushButton;
    ModificationTime8_explain   = new QPushButton;
    ModificationTime9_explain   = new QPushButton;
    ModificationTime10_explain  = new QPushButton;
    ModificationTime11_explain  = new QPushButton;
    ModificationTime12_explain  = new QPushButton;
    EventRecord_explain         = new QPushButton;
    EventRecord2_explain        = new QPushButton;
    EventRecord3_explain        = new QPushButton;
    EventRecord4_explain        = new QPushButton;
    EventRecord5_explain        = new QPushButton;
    EventRecord6_explain        = new QPushButton;
    EventRecord7_explain        = new QPushButton;
    EventRecord8_explain        = new QPushButton;
    EventRecord9_explain        = new QPushButton;
    EventRecord10_explain       = new QPushButton;
    EventRecord11_explain       = new QPushButton;
    EventRecord12_explain       = new QPushButton;
    /***************************参数设置**********************************/

    Grid_connected_mode_explain = new QPushButton;      //PCS并离网方式说明
    Constant_power_explain  = new QPushButton;           //恒功率说明
    Charging_and_discharging_explain = new QPushButton; //充放电说明status
    Work_mode_explain = new QPushButton;                //工作模式说明
    Output_power_factor_explain = new QPushButton;      //输出功率因素说明
    Output_reactive_power_explain = new QPushButton;    //输出无功功率说明
    Constant_current_explain = new QPushButton;         //恒流说明
    Constant_voltage_explain = new QPushButton;         //恒压说明
    Control_mode_explain = new QPushButton;             //控制模式说明
    Machine_number_explain = new QPushButton;           //设备号说明
    Parallel_explain = new QPushButton;                 //并机说明
    Unbalance_power_enable_explain = new QPushButton;   //功率不平衡使能说明
    Phase_A_power_explain = new QPushButton;            //A相功率说明
    Phase_B_power_explain = new QPushButton;            //B相功率说明
    Phase_C_power_explain = new QPushButton;            //C相功率说明

    /***************************电池设置**********************************/

    DOD_OnGrid_explain          = new QPushButton;
    DOD_OffGrid_explain         = new QPushButton;
    Charge_Vol_Up_Limit_explain = new QPushButton;
    Disc_Vol_lower_Limit_explain= new QPushButton;
    Charge_Cur_Limit_explain    = new QPushButton;
    Gen_turn_off_SOC_explain    = new QPushButton;       //柴发关闭SOC
    Gen_turn_on_SOC_explain     = new QPushButton;       //柴发开启SOC
    Gen_charge_SOC_explain      = new QPushButton;       //柴发充电SOC
    Grid_charge_SOC_explain     = new QPushButton;       //电网充电SOC
    Grid_capacity_explain       = new QPushButton;       //电网容量
    Turn_on_SOC_explain         = new QPushButton;
    Turn_off_SOC_explain        = new QPushButton;
    Turn_on_cell_vol_explain    = new QPushButton;
    Turn_off_cell_vol_explain   = new QPushButton;
    Turn_on_total_vol_explain   = new QPushButton;
    Turn_off_total_vol_explain  = new QPushButton;
    UPS_charge_power_explain    = new QPushButton;
    Monthly_cycle_time_explain  = new QPushButton;

    Check1_explain = new QPushButton;Check2_explain= new QPushButton;Check3_explain= new QPushButton;
    Check4_explain= new QPushButton;Check5_explain= new QPushButton;Check6_explain= new QPushButton;
    Check7_explain= new QPushButton;Check8_explain= new QPushButton;Check9_explain= new QPushButton;
    Check10_explain= new QPushButton;Check11_explain= new QPushButton;Check12_explain= new QPushButton;
    Check13_explain= new QPushButton;Check14_explain= new QPushButton;Check15_explain= new QPushButton;
    Check16_explain= new QPushButton;Check17_explain= new QPushButton;Check18_explain= new QPushButton;
    Check19_explain= new QPushButton;Check20_explain= new QPushButton;

    Start_T1_explain = new QPushButton;Start_T2_explain= new QPushButton;Start_T3_explain= new QPushButton;
    Start_T4_explain= new QPushButton;Start_T5_explain= new QPushButton;Start_T6_explain= new QPushButton;
    Start_T7_explain= new QPushButton;Start_T8_explain= new QPushButton;Start_T9_explain= new QPushButton;
    Start_T10_explain= new QPushButton;Start_T11_explain= new QPushButton;Start_T12_explain= new QPushButton;
    Start_T13_explain= new QPushButton;Start_T14_explain= new QPushButton;Start_T15_explain= new QPushButton;
    Start_T16_explain= new QPushButton;Start_T17_explain= new QPushButton;Start_T18_explain= new QPushButton;
    Start_T19_explain= new QPushButton;Start_T20_explain= new QPushButton;

    End_T1_explain = new QPushButton;End_T2_explain= new QPushButton;End_T3_explain= new QPushButton;
    End_T4_explain= new QPushButton;End_T5_explain= new QPushButton;End_T6_explain= new QPushButton;
    End_T7_explain= new QPushButton;End_T8_explain= new QPushButton;End_T9_explain= new QPushButton;
    End_T10_explain= new QPushButton;End_T11_explain= new QPushButton;End_T12_explain= new QPushButton;
    End_T13_explain= new QPushButton;End_T14_explain= new QPushButton;End_T15_explain= new QPushButton;
    End_T16_explain= new QPushButton;End_T17_explain= new QPushButton;End_T18_explain= new QPushButton;
    End_T19_explain= new QPushButton;End_T20_explain= new QPushButton;

    State1_explain = new QPushButton;State2_explain= new QPushButton;State3_explain= new QPushButton;
    State4_explain= new QPushButton;State5_explain= new QPushButton;State6_explain= new QPushButton;
    State7_explain= new QPushButton;State8_explain= new QPushButton;State9_explain= new QPushButton;
    State10_explain= new QPushButton;State11_explain= new QPushButton;State12_explain= new QPushButton;
    State13_explain= new QPushButton;State14_explain= new QPushButton;State15_explain= new QPushButton;
    State16_explain= new QPushButton;State17_explain= new QPushButton;State18_explain= new QPushButton;
    State19_explain= new QPushButton;State20_explain= new QPushButton;

    Power1_explain = new QPushButton;Power2_explain= new QPushButton;Power3_explain= new QPushButton;
    Power4_explain= new QPushButton;Power5_explain= new QPushButton;Power6_explain= new QPushButton;
    Power7_explain= new QPushButton;Power8_explain= new QPushButton;Power9_explain= new QPushButton;
    Power10_explain= new QPushButton;Power11_explain= new QPushButton;Power12_explain= new QPushButton;
    Power13_explain= new QPushButton;Power14_explain= new QPushButton;Power15_explain= new QPushButton;
    Power16_explain= new QPushButton;Power17_explain= new QPushButton;Power18_explain= new QPushButton;
    Power19_explain= new QPushButton;Power20_explain= new QPushButton;

    /***************************系统消息**********************************/
    pButton_Version = new QButtonGroup();
    pButton_Version->addButton(ui->interface_explain_btn,0);
    pButton_Version->addButton(ui->port_explain_btn,1);
    pButton_Version->addButton(ui->ip_explain_btn,2);
    pButton_Version->addButton(ui->netmask_explain_btn,3);
    pButton_Version->addButton(ui->gateway_explain_btn,4);
    pButton_Version->addButton(ui->server_ip_explain_btn,5);
    pButton_Version->addButton(ui->ok,6);

    Manufacturer_name_explain   = new QPushButton;
    MonitoringVersion_explain   = new QPushButton;
    SysProtocol_Version_explain = new QPushButton;
    ConverterVersion_explain    = new QPushButton;
    CPLD_Version_explain        = new QPushButton;
    SN_explain                  = new QPushButton;
    /***************************高级设置**********************************/
    AdvancedSetup_btn = new QPushButton;                //高级设置

    //功能设置
    Battery_type_explain                    = new QPushButton;
    BMS_Comm_type_explain                   = new QPushButton;
    Power_control_type_explain              = new QPushButton;
    EMS_Comm_type_explain                   = new QPushButton;
    Output_power_limit_explain              = new QPushButton;
    BAT_manufacturers_explain               = new QPushButton;
    Power_Delta_explain                     = new QPushButton;
    Charge_power_limit_explain              = new QPushButton;
    Discharge_power_limit_explain           = new QPushButton;
    Charge_Vol_upper_Limit_delta_explain    = new QPushButton;
    Discharge_Vol_lower_Limit_delta_explain = new QPushButton;
    Host_Address_explain                    = new QPushButton;
    serial_port_1_explain                   = new QPushButton;
    serial_port_2_explain                   = new QPushButton;
    serial_port_3_explain                   = new QPushButton;
    serial_port_4_explain                   = new QPushButton;
    serial_port_5_explain                   = new QPushButton;
    Can_port_1_explain      = new QPushButton;
    Can_port_2_explain      = new QPushButton;
    ProtocolVersion_explain = new QPushButton;
    UserPassPort_explain    = new QPushButton;
    RootPassport_explain    = new QPushButton;
    Language_explain        = new QPushButton;
    System_upgrade_explain  = new QPushButton;
    Sounds_explain          = new QPushButton;
    DryContact_explain      = new QPushButton;

    //系统参数
    Change_rate_of_power_explain        = new QPushButton;
    Grid_frequency_upper_limit_explain  = new QPushButton;
    Grid_frequency_lower_limit_explain  = new QPushButton;
    Vol_protection_upper_limit_explain  = new QPushButton;
    Vol_protection_lower_limit_explain  = new QPushButton;
    HVRT_enable_explain                 = new QPushButton;
    LVRT_enable_explain                 = new QPushButton;
    AFD_enable_explain                  = new QPushButton;
    Insulation_detection_enable_explain = new QPushButton;
    PrimaryFreq_enable_explain          = new QPushButton;
    Inertia_enable_explain              = new QPushButton;
    CV_parallel_explain                 = new QPushButton;
    Machine_type_explain                = new QPushButton;
    Machine_capacity_explain            = new QPushButton;
    Output_Fre_grade_explain            = new QPushButton;
    Output_vol_level_explain            = new QPushButton;
    Converter_side_vol_level_explain    = new QPushButton;
    Output_reactive_power_mode_explain  = new QPushButton;
    Grid_connected_mode_of_Inv_explain  = new QPushButton;
    Primary_FM_dead_zone_explain        = new QPushButton;
    PFM_coeff_explain                   = new QPushButton;
    Grid_recover_time_explain           = new QPushButton;
    DynamicCap_explain                  = new QPushButton;
    Module_Number_explain               = new QPushButton;
    Restore_factory_explain             = new QPushButton;
    Clear_Data_explain                  = new QPushButton;

    //外设
    DI_1_Enable_explain = new QPushButton;
    DI_2_Enable_explain = new QPushButton;
    DI_3_Enable_explain = new QPushButton;
    DI_4_Enable_explain = new QPushButton;
    DI_5_Enable_explain = new QPushButton;
    DI_6_Enable_explain = new QPushButton;
    DO_1_Enable_explain = new QPushButton;
    DO_2_Enable_explain = new QPushButton;
    DO_3_Enable_explain = new QPushButton;
    DI_1_NC_O_explain   = new QPushButton;
    DI_2_NC_O_explain   = new QPushButton;
    DI_3_NC_O_explain   = new QPushButton;
    DI_4_NC_O_explain   = new QPushButton;
    DI_5_NC_O_explain   = new QPushButton;
    DI_6_NC_O_explain   = new QPushButton;
    DO_1_NC_O_explain   = new QPushButton;
    DO_2_NC_O_explain   = new QPushButton;
    DO_3_NC_O_explain   = new QPushButton;
    DI_1_Action_explain = new QPushButton;
    DI_2_Action_explain = new QPushButton;
    DI_3_Action_explain = new QPushButton;
    DI_4_Action_explain = new QPushButton;
    DI_5_Action_explain = new QPushButton;
    DI_6_Action_explain = new QPushButton;
    DO_1_Action_explain = new QPushButton;
    DO_2_Action_explain = new QPushButton;
    DO_3_Action_explain = new QPushButton;

    //BMS保护
    DOD_Action_explain                 = new QPushButton;
    Prohibit_charging_Action_explain   = new QPushButton;
    Prohibit_discharging_Action_explain= new QPushButton;
    BMS_warning_Action_explain         = new QPushButton;
    BMS_alarm_Action_explain           = new QPushButton;
    BMS_fualt_Action_explain           = new QPushButton;
    BMS_warning_CP_explain             = new QPushButton;
    BMS_alarm_CP_explain               = new QPushButton;
    BMS_fualt_CP_explain               = new QPushButton;
    BMS_warning_DP_explain             = new QPushButton;
    BMS_alarm_DP_explain               = new QPushButton;
    BMS_fualt_DP_explain               = new QPushButton;

    //调试
    Debug_variable_1_explain        = new QPushButton;
    Debug_variable_2_explain        = new QPushButton;
    Debug_variable_3_explain        = new QPushButton;
    Debug_variable_1_addr_explain   = new QPushButton;
    Debug_variable_2_addr_explain   = new QPushButton;
    Debug_variable_3_addr_explain   = new QPushButton;
    Debug_memery_var_1_explain      = new QPushButton;
    Debug_memery_var_2_explain      = new QPushButton;
    Debug_memery_var_3_explain      = new QPushButton;
    Input_Vol_revise_explain        = new QPushButton;
    Input_Cur_revise_explain        = new QPushButton;

    Voltage_1_5_revise_explain      = new QPushButton;
    Bus_Vol_revise_explain          = new QPushButton;
    Grid_A_AB_Vol_revise_explain    = new QPushButton;
    Grid_B_BC_Vol_revise_explain    = new QPushButton;
    Grid_C_CA_Vol_revise_explain    = new QPushButton;
    Output_A_Cur_revise_explain     = new QPushButton;
    Output_B_Cur_revise_explain     = new QPushButton;
    Output_C_Cur_revise_explain     = new QPushButton;
    INV_A_Vol_revise_explain        = new QPushButton;
    INV_B_Vol_revise_explain        = new QPushButton;
    INV_C_Vol_revise_explain        = new QPushButton;

    INV_A_ind_Cur_revise_explain    = new QPushButton;
    INV_B_ind_Cur_revise_explain    = new QPushButton;
    INV_C_ind_Cur_revise_explain    = new QPushButton;
    INV_On_off_flag_explain         = new QPushButton;
    Logic_state_explain             = new QPushButton;
    INV_flag_explain                = new QPushButton;
    Grid_flag_explain               = new QPushButton;
    Grid_protect_flag_explain       = new QPushButton;
    Bat_flag_explain                = new QPushButton;
    DC_bus_flag_explain             = new QPushButton;
    INT_main_flag_explain           = new QPushButton;
    parallel_signal_explain         = new QPushButton;
    /*****************************监控调试****************************************/
    pButton_MonitorDebug = new QButtonGroup();
    pButton_MonitorDebug->addButton(ui->DO_TurnON_btn,0);
    pButton_MonitorDebug->addButton(ui->DO_TurnOFF_btn,1);
    pButton_MonitorDebug->addButton(ui->localSoftstart_btn,2);
    pButton_MonitorDebug->addButton(ui->localSoftend_btn,3);
    pButton_MonitorDebug->addButton(ui->BMSPowerOn_btn,4);//电池设置-电池上电
    pButton_MonitorDebug->addButton(ui->BMSPowerOff_btn,5);//电池设置-电池下电
    /*****************************PCS数据****************************************/
    PCS_vol_AB_explain = new QPushButton;
    PCS_vol_BC_explain = new QPushButton;
    PCS_vol_CA_explain = new QPushButton;
    PCS_cur_A_explain  = new QPushButton;
    PCS_cur_B_explain  = new QPushButton;
    PCS_cur_C_explain  = new QPushButton;
    PCS_act_P_explain  = new QPushButton;
    PCS_rea_P_explain  = new QPushButton;
    PCS_par_P_explain  = new QPushButton;
    PCS_Pf_explain     = new QPushButton;
    PCS_Bat_vol_explain= new QPushButton;
    PCS_Bat_cur_explain= new QPushButton;
    PCS_Bat_P_explain  = new QPushButton;
    PCS_Bus_vol_explain= new QPushButton;
    PCS_IGBT_T_explain = new QPushButton;
    PCS_Env_T_explain  = new QPushButton;

    Grid_vol_AB_explain = new QPushButton;
    Grid_vol_BC_explain = new QPushButton;
    Grid_vol_CA_explain = new QPushButton;
    Grid_cur_A_explain  = new QPushButton;
    Grid_cur_B_explain  = new QPushButton;
    Grid_cur_C_explain  = new QPushButton;
    Grid_act_P_explain  = new QPushButton;
    Grid_rea_P_explain  = new QPushButton;
    Grid_app_P_explain  = new QPushButton;
    Grid_fre_explain    = new QPushButton;
    Grid_Pf_explain     = new QPushButton;

    Load_vol_AB_explain = new QPushButton;
    Load_vol_BC_explain = new QPushButton;
    Load_vol_CA_explain = new QPushButton;
    Load_cur_A_explain  = new QPushButton;
    Load_cur_B_explain  = new QPushButton;
    Load_cur_C_explain  = new QPushButton;
    Load_act_P_explain  = new QPushButton;
    Load_rea_P_explain  = new QPushButton;
    Load_app_P_explain  = new QPushButton;
    Load_Pf_explain     = new QPushButton;
    /***************************PCS状态**********************************/
    DC_input_Breaker_explain    = new QPushButton;//直流输入断路器
    DC_Cont_explain             = new QPushButton;//直流输入器
    Output_Cont_explain         = new QPushButton;//输出接触器
    Output_Breaker_explain      = new QPushButton;//输出断路器
    Grid_Cont_explain           = new QPushButton;//电网接触器
    Grid_Breaker_explain        = new QPushButton;//电网断路器
    MB_Breaker_explain          = new QPushButton;//维修旁路
    converter_available_explain = new QPushButton;//变流器使能
    DC_Soft_start_explain       = new QPushButton;//直流软启动
    converter_status_explain    = new QPushButton;//变流器状态
    Reactive_P_Regulation_explain = new QPushButton;//无功调节方式
    LVRT_explain                = new QPushButton;//
    Generator_signal_explain    = new QPushButton;//发电机信号
    Reserve_explain             = new QPushButton;//保留位
    Reserve2_explain            = new QPushButton;//保留位
    EPO_Cont_signal1_explain    = new QPushButton;//EPO节点信号
    EPO_Cont_signal2_explain    = new QPushButton;//EPO节点信号
    Access_signal_explain       = new QPushButton;//门禁信号
    Full_P_signal_explain       = new QPushButton;//满功率信号
    Smoke_alarm_signal_explain  = new QPushButton;//烟感信号
    Hight_temp_signal_explain   = new QPushButton;//高温信号

    /***************************电池数据**********************************/
    pButton_BatteryData  = new QButtonGroup();
    pButton_BatteryData->addButton(ui->pushButton_1,0);
    pButton_BatteryData->addButton(ui->pushButton_2,1);
    pButton_BatteryData->addButton(ui->pushButton_3,2);
    pButton_BatteryData->addButton(ui->pushButton_4,3);
    pButton_BatteryData->addButton(ui->pushButton_5,4);
    pButton_BatteryData->addButton(ui->pushButton_6,5);
    pButton_BatteryData->addButton(ui->pushButton_7,6);
    pButton_BatteryData->addButton(ui->pushButton_8,7);
    pButton_BatteryData->addButton(ui->pushButton_9,8);
    pButton_BatteryData->addButton(ui->pushButton_10,9);
    pButton_BatteryData->addButton(ui->pushButton_11,10);
    pButton_BatteryData->addButton(ui->pushButton_12,11);
    pButton_BatteryData->addButton(ui->pushButton_13,12);
    pButton_BatteryData->addButton(ui->pushButton_14,13);
    pButton_BatteryData->addButton(ui->pushButton_15,14);
    pButton_BatteryData->addButton(ui->pushButton_16,15);
    pButton_BatteryData->addButton(ui->pushButton_17,16);

    IPShow = true;
}
/***************************************************************
 * @brief HOSTPAGE init
 * 主页初始化
 ***************************************************************/
void MEGAWin::FirstPage()
{
    ui->Alarm_Button->setDefault(false);
    ui->Alarm_Button->setFlat(true);
    ui->Alarm_Button->setFocusPolicy(Qt::NoFocus);

    ui->Bypass_Running_btn->setFlat(true);
    ui->Bypass_Running_btn->setFocusPolicy(Qt::NoFocus);

    ui->Bypass_Grid_btn->setFlat(true);
    ui->Bypass_Grid_btn->setFocusPolicy(Qt::NoFocus);

    ui->Bypass_Load_Btn->setFlat(true);
    ui->Bypass_Load_Btn->setFocusPolicy(Qt::NoFocus);

    ui->Bypass_Batt_btn->setFlat(true);
    ui->Bypass_Batt_btn->setFocusPolicy(Qt::NoFocus);
}
/***************************************************************
 * @brief RunStatePage init
 * 实时状态初始化
 ***************************************************************/
void MEGAWin::RunStatePage()
{
    ModuleData_Tab();//PCS数据
    RTAlarm();//告警信息
    ModuleState_Tab();//PCS状态
}

/***************************************************************
 * 系统设置页面初始化
 ***************************************************************/
void MEGAWin::SystemSettingPage()
{
    UserParam_tab();/*系统-设置表*/

    BatterySet_tab();/*系统-电池设置表*/

    RunTimeSet_tab();/*系统-自动运行时间设置表*/

    History_tab();/*记录-历史记录、操作日志设置表*/

    Information_tbnt_released();/*系统-系统消息*/
}

/***************************************************************
 * LCD标签初始化和定时器设置
 ***************************************************************/
void MEGAWin::LCDSetting()
{
    ui->TimeSeting_btn->setFlat(true);//设置时间显示控件无边框
    ui->TimeSeting_btn->setFocusPolicy(Qt::NoFocus); //设置无虚线
    timer = new QTimer();
    timer->setInterval(1000);//一秒刷新一次时间
    timer->start();


    Update_RTData_timer = new QTimer();
    Update_RTData_timer->setInterval(500);//设置数据实时显示刷新时间
    Update_RTData_timer->start();

#if 0
    current_time = QTime::currentTime();   //获取当前时间
    int hour = current_time->hour();     //当前的小时
    int minute = current_time->minute(); //当前的分
    int second = current_time->second(); //当前的秒
    int msec = current_time->msec();     //当前的毫秒
#endif
}
/******************************************************************************
 * 一般设置表初始化
 * ***************************************************************************/
void MEGAWin::UserParam_tab()
{
    ui->System_Tab->setColumnCount(6);
    ui->System_Tab->setRowCount(8);
    ui->System_Tab->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->System_Tab->verticalHeader()->setVisible(false);//设置垂直头不可见
    ui->System_Tab->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->System_Tab->setShowGrid(true);//设置显示格子
    ui->System_Tab->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    ui->System_Tab->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
    ui->System_Tab->setEditTriggers(QAbstractItemView::SelectedClicked);//单机修改

    QStringList List5;
    List5 << tr("Name") << tr("Value") << tr("Unit")<< tr("Name") << tr("Value") << tr("Unit");
    ui->System_Tab->setHorizontalHeaderLabels(List5);
    ui->System_Tab->setColumnWidth(0,163);
    ui->System_Tab->setRowHeight(0, 48);
    ui->System_Tab->setColumnWidth(1,163);
    ui->System_Tab->setRowHeight(1, 48);
    ui->System_Tab->setColumnWidth(2,163);
    ui->System_Tab->setRowHeight(2, 48);
    ui->System_Tab->setColumnWidth(3,163);
    ui->System_Tab->setRowHeight(3, 48);
    ui->System_Tab->setColumnWidth(4,163);
    ui->System_Tab->setRowHeight(4, 48);
    ui->System_Tab->setColumnWidth(5,163);
    ui->System_Tab->setRowHeight(5, 48);
    ui->System_Tab->setRowHeight(6, 48);
    ui->System_Tab->setRowHeight(7, 48);

    AdvancedSetup_btn->setText(tr("Advance setting"));
    ui->System_Tab->setCellWidget(7,4, (QWidget *)AdvancedSetup_btn);          //高级设置

    ParameterSet();//系统设置 绘制button

}
/******************************************************************************
 * 历史记录设置表初始化
 * ***************************************************************************/
void MEGAWin::History_tab()
{
    History();//历史记录
    OperationLog();//操作日志
}

/******************************************************************************
 * 电池设置表初始化
 * ***************************************************************************/
void MEGAWin::BatterySet_tab()
{
    ui->Lithum_Tab->setColumnWidth(0,250);
    ui->Lithum_Tab->setColumnWidth(1,120);
    ui->Lithum_Tab->setColumnWidth(2,100);
    ui->Lithum_Tab->setColumnWidth(3,250);
    ui->Lithum_Tab->setColumnWidth(4,120);
    ui->Lithum_Tab->setColumnWidth(5,100);

    BetterySetup();//电池设置 绘制button

}
/******************************************************************************
 * 系统运行时间表初始化
 * ***************************************************************************/
void MEGAWin::RunTimeSet_tab()
{
    QStringList time_str;
    time_str<< tr("Check") << tr("StartTime") << tr("EndTime") << tr("State") << tr("Power(kW)");
    ui->Time_tableWidget->setColumnCount(time_str.size());
    ui->Time_tableWidget->setRowCount(20);
    ui->Time_tableWidget->setHorizontalHeaderLabels(time_str);
    ui->Time_tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->Time_tableWidget->verticalHeader()->setVisible(false);//设置垂直头不可见
    ui->Time_tableWidget->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->Time_tableWidget->setShowGrid(true);//设置显示格子
    ui->Time_tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    ui->Time_tableWidget->setEditTriggers(QAbstractItemView::SelectedClicked);//单机修改
    ui->Time_tableWidget->setColumnWidth(0,70);
    ui->Time_tableWidget->setColumnWidth(1,180);
    ui->Time_tableWidget->setColumnWidth(2,180);
    ui->Time_tableWidget->setColumnWidth(3,130);
    ui->Time_tableWidget->horizontalHeader()->setStretchLastSection(4);

    QStringList choice;
    choice <<tr("charge") << tr("discharge") << tr("Automatic");

    AutoOperation();//自动运行 绘制button

}
/******************************************************************************
 * 实时数据——模拟量
 * ***************************************************************************/
void MEGAWin::RTData_Anologe()
{
    ui->RTDataModel_tableWidget->clearContents();//防止内存泄漏
}
/******************************************************************************
 * 实时数据——状态量
 * ***************************************************************************/
void MEGAWin::RTData_Status()
{
    ui->RTState_MEGA_Tab->clearContents();//防止内存泄漏
    ModuleState_Tab();
}

/*************************************************************************
 * 实时状态数据更新函数
 ************************************************************************/
void MEGAWin::RTDataDisplay()
{
    RTData_Anologe();
}
/*************************************************************************
 * 系统信息槽
 ************************************************************************/
void MEGAWin::Information_tbnt_released()
{
    ui->EquipmentInfor_tableWidget->setColumnCount(2);
    ui->EquipmentInfor_tableWidget->setRowCount(9);
    ui->EquipmentInfor_tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->EquipmentInfor_tableWidget->verticalHeader()->setVisible(false);//设置垂直头不可见
    ui->EquipmentInfor_tableWidget->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->EquipmentInfor_tableWidget->setShowGrid(true);//设置显示格子
    ui->EquipmentInfor_tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    ui->EquipmentInfor_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
    ui->EquipmentInfor_tableWidget->setStyleSheet("selection-background-color:lightblue;");

    //将设备信息显示到LCD上
    QStringList List4;
    List4 << tr("Name") << tr("Information") ;
    ui->EquipmentInfor_tableWidget->setHorizontalHeaderLabels(List4);
    ui->EquipmentInfor_tableWidget->setColumnWidth(0,230);
    ui->EquipmentInfor_tableWidget->horizontalHeader()->setStretchLastSection(1);//自动占用剩余空间

    SystemMessages();//系统信息 绘制button

}

/*************************************************************************
 * PCS故障信息表
 ************************************************************************/
void MEGAWin::PCS_Alarm_information_table()
{
    ui->RTAlarm_Data_page->setRowHeight(0, 110);
    QStringList RTAlarm_List;
    RTAlarm_List << tr("Inverter overcurrent") << tr("General failure") \
                << tr("Inductive current instantaneous value >3lp or inductive current RMS value >1.36ln") \
                << tr("PCS shut down and disconnect the output contactor") \
                << tr("Recoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(0, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(0, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(1, 130);
    RTAlarm_List.clear();
    RTAlarm_List << tr("Converter fault") << tr("General failure")\
                << tr("During soft startup of converter, inverter voltage RMS more then 1.2Vgrid or inverter voltage RMS less than 0.3Vgrid after 30s") \
                << tr("PCS shut down and Stop the soft startup") \
                << tr("Recoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(1, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(1, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(2, 110);
    RTAlarm_List.clear();
    RTAlarm_List << tr("Battery low voltage") << tr("Warning") \
                << tr("The DC input/output voltage is lower than the battery EOD voltage or less than 1.414 times the grid line voltage") \
                << tr("PCS shut down and the AC contactor is disconnected") \
                << tr("Recoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(2, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(2, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(3, 200);
    RTAlarm_List.clear();
    RTAlarm_List << tr("Low battery power") << tr("Warning") \
                << tr("The battery voltage is lower than the EOD voltage value (applicable to BMS free battery systems to prevent voltage rebound)") \
                << tr("When the PCS is in discharge state, the machine stops (the charging process is not affected) and the AC contactor is disconnected") \
                << tr("Recoverable, The alarm is cleared when the charging time of PCS is longer than 5 minutes");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(3, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(3, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(4, 130);
    RTAlarm_List.clear();
    RTAlarm_List << tr("DC bus overvoltage") << tr("Serious failure") \
                << tr("DC input voltage more then 850V") \
                << tr("PCS shut down, the AC contactor is disconnected, and the DC circuit breaker is tripped") \
                << tr("Unrecoverable");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(4, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(4, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(5, 130);
    RTAlarm_List.clear();
    RTAlarm_List << tr("DC bus short circuit") << tr("Serious failure") \
                << tr("The DC bus voltage is less than 200V, the DC current is more than 50A, and the judgment time is 200us") \
                << tr("PCS shut down, the AC contactor is disconnected, and the DC circuit breaker is tripped") \
                << tr("Unrecoverable");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(5, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(5, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(6, 110);
    RTAlarm_List.clear();
    RTAlarm_List << tr("The output contactor is open") << tr("General failure")\
                << tr("When PCS is running, the auxiliary contact signal of AC contactor is in the disconnected state") \
                << tr("PCS shut down and the AC contactor is disconnected") \
                << tr("Recoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(6, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(6, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(7, 110);
    RTAlarm_List.clear();
    RTAlarm_List << tr("Output contactor short circuit") << tr("General failure")\
                << tr("When PCS is shut down, the auxiliary contact signal of AC contactor is closed") \
                << tr("PCS shut down and the AC contactor is disconnected") \
                << tr("Recoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(7, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(7, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(8, 310);
    RTAlarm_List.clear();
    RTAlarm_List << tr("The converter is overheated") << tr("Warning") \
                << tr("IGBT temperature exceeds 105℃ or reactor temperature exceeds 160℃") \
                << tr("IGBT overtemperature: derating operation (grid-connected); IGBT overtemperature: PCS shut down (off-grid), AC contactor is disconnected; Reactor overtemperature: PCS shut down and AC contactor is disconnected") \
                << tr("Recoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(8, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(8, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(9, 90);
    RTAlarm_List.clear();
    RTAlarm_List << tr("Output over load") << tr("Warning") \
                << tr("Off-grid load power >110%Pn") \
                << tr("PCS shut down and the AC contactor is disconnected") \
                << tr("Recoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(9, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(9, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(10, 170);
    RTAlarm_List.clear();
    RTAlarm_List << tr("The positive and negative terminals of the battery are connected inversely fault") << tr("Warning") \
                << tr("The DC input is reversed") \
                << tr("PCS shut down and the AC contactor is disconnected") \
                << tr("Unrecoverable");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(10, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(10, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(11, 170);
    RTAlarm_List.clear();
    RTAlarm_List << tr("The DC contactor is faulty") << tr("General failure") \
                << tr("When the driving signal is a closed signal, the pressure difference between the battery and the bus is greater than 50V;When the driving signal is off, the auxiliary contact signal is closed") \
                << tr("PCS shut down and the AC contactor is disconnected") \
                << tr("Recoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(11, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(11, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(12, 90);
    RTAlarm_List.clear();
    RTAlarm_List << tr("EMS communicate\nfault") << tr("General failure") \
                << tr("The communication between PCS and EMS is lost, and the judgment time is 3 minutes") \
                << tr("PCS shut down and the AC contactor is disconnected") \
                << tr("Recoverable, the fault recovers automatically 30 seconds after it is rectified");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(12, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(12, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(13, 90);
    RTAlarm_List.clear();
    RTAlarm_List << tr("BMS communicate\nfault") << tr("General failure") \
                << tr("Communication loss between PCS and BMS, judgment time 50s") \
                << tr("PCS shut down and the AC contactor is disconnected") \
                << tr("Recoverable, the fault recovers automatically 30 seconds after it is rectified");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(13, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(13, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(14, 130);
    RTAlarm_List.clear();
    RTAlarm_List << tr("Converter phase loss fault") << tr("General failure") \
                << tr("When the grid-connected power is greater than 50%, one or more lines of the three-phase circuit have no output power, and the judgment time is 10s") \
                << tr("PCS shut down and the AC contactor is disconnected") \
                << tr("Recoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(14, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(14, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(15, 110);
    RTAlarm_List.clear();
    RTAlarm_List << tr("Grid overvoltage") << tr("Warning") \
                << tr("If the power grid voltage exceeds the maximum allowable voltage (90% to 70% can be set), the judgment time is 1s") \
                << tr("PCS shut down and the AC contactor is disconnected") \
                << tr("Recoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(15, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(15, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(16, 110);
    RTAlarm_List.clear();
    RTAlarm_List << tr("Grid undervoltage") << tr("Warning") \
                << tr("If the power grid voltage exceeds the maximum allowable voltage (90% to 70% can be set), the judgment time is 1s") \
                << tr("PCS shut down and the AC contactor is disconnected") \
                << tr("Recoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(16, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(16, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(17, 150);
    RTAlarm_List.clear();
    RTAlarm_List << tr("Grid reverse sequence") << tr("Warning") \
                << tr("The three-phase phase sequence is reversed (the positive sequence mode value of the grid voltage is less than the negative sequence mode value), and the judgment time is 1s") \
                << tr("PCS shut down and the AC contactor is disconnected") \
                << tr("Unrecoverable");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(17, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(17, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(18, 150);
    RTAlarm_List.clear();
    RTAlarm_List << tr("Grid frequency anomaly") << tr("Warning") \
                << tr("Grid frequency frequency beyond the allowable range of PCS (±2Hz can be set)") \
                << tr("PCS shut down and the AC contactor is disconnected") \
                << tr("Recoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(18, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(18, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(19, 150);
    RTAlarm_List.clear();
    RTAlarm_List << tr("Converter shutter island protection") << tr("Warning") \
                << tr("Initiative shutter island protection mode, the power grid loses power, and the load matches the grid-connected power and phase Angle of the inverter") \
                << tr("PCS shut down and the AC contactor is disconnected") \
                << tr("Recoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(19, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(19, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(20, 150);
    RTAlarm_List.clear();
    RTAlarm_List << tr("Drive line fault") << tr("General failure") \
                << tr("The driver cable port is loose") \
                << tr("PCS shut down and the AC contactor is disconnected") \
                << tr("Recoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(20, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(20, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(21, 150);
    RTAlarm_List.clear();
    RTAlarm_List << tr("Lightning protection fault") << tr("Warning") \
                << tr("Surge arrester breakdown or leakage") \
                << tr("PCS shut down and the AC contactor is disconnected") \
                << tr("Unrecoverable");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(21, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(21, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(22, 150);
    RTAlarm_List.clear();
    RTAlarm_List << tr("The AC auxiliary power supply is faulty") << tr("General failure") \
                << tr("The AC auxiliary power output is abnormal. Procedure") \
                << tr("PCS shut down and the AC contactor is disconnected") \
                << tr("Recoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(22, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(22, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(23, 150);
    RTAlarm_List.clear();
    RTAlarm_List << tr("The DC auxiliary power supply is faulty") << tr("General failure") \
                << tr("The DC auxiliary power output is abnormal. Procedure") \
                << tr("PCS shut down and the AC contactor is disconnected") \
                << tr("Recoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(23, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(23, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(24, 150);
    RTAlarm_List.clear();
    RTAlarm_List << tr("Fan failure") << tr("Warning") \
                << tr("The fan cannot be started") \
                << tr("PCS derating operation") \
                << tr("Recoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(24, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(24, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(25, 150);
    RTAlarm_List.clear();
    RTAlarm_List << tr("Emergency shutdown") << tr("Warning") \
                << tr("Press the EPO button on the converter control panel") \
                << tr("PCS shut down and the AC contactor is disconnected") \
                << tr("Recoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(25, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(25, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(26, 150);
    RTAlarm_List.clear();
    RTAlarm_List << tr("CT or Hall open circuit fault") << tr("General failure") \
                << tr("When PCS grid-connected power is greater than 50%, CT detection current is less than 70% of the given quantity") \
                << tr("PCS shut down and the AC contactor is disconnected") \
                << tr("Recoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(26, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(26, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(27, 150);
    RTAlarm_List.clear();
    RTAlarm_List << tr("Insulation impedance anomaly") << tr("Serious failure") \
                << tr("For 1000V systems, the positive or negative ground impedance is less than 33KΩ") \
                << tr("PCS shut down and the AC contactor is disconnected") \
                << tr("Unrecoverable");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(27, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(27, i)->setTextAlignment(Qt::AlignCenter);
    }
}

void MEGAWin::Change_Language()
{
    if(LanguageType == CHINESE)//如果当前是中文，则切英文
    {
        LanguageType = ENGLISH;
        translator->load(":/Language/EN.qm");
        ui->ChangeLanguage_btn->setText(tr("Change Language"));
        qApp->installTranslator(translator);
        ui->retranslateUi(this);
    }
    else if(LanguageType == ENGLISH)//如果当前是英文，则切中文
    {
        LanguageType = CHINESE;
        translator->load(":/Language/CN.qm");
        ui->ChangeLanguage_btn->setText(tr("切换语言"));
        qApp->installTranslator(translator);
        ui->retranslateUi(this);
    }
}

/***************************************************************
 * 系统参数槽
 ***************************************************************/
void MEGAWin::SystemParam_tbnt_released()
{

    for(int i=0;i<12;i++)//调整功能设置、参数设置的列宽列高
    {
        ui->UI_Parameter_Tab->setColumnWidth(i,165);
        ui->UI_Parameter_Tab->setRowHeight(i,50);
        ui->UI_SystemParameter_Tab->setColumnWidth(i,165);
        ui->UI_SystemParameter_Tab->setRowHeight(i++,50);

        ui->UI_Parameter_Tab->setColumnWidth(i,90);
        ui->UI_Parameter_Tab->setRowHeight(i,50);
        ui->UI_SystemParameter_Tab->setColumnWidth(i,90);
        ui->UI_SystemParameter_Tab->setRowHeight(i++,50);

        ui->UI_Parameter_Tab->setColumnWidth(i,55);
        ui->UI_Parameter_Tab->setRowHeight(i,50);
        ui->UI_SystemParameter_Tab->setColumnWidth(i,55);
        ui->UI_SystemParameter_Tab->setRowHeight(i,50);
    }
    for(int i=0;i<9;i++)//调整 外设 的列宽列高
    {
        ui->ExternalDevice_tW->setColumnWidth(i,200);
        ui->ExternalDevice_tW->setRowHeight(i,50);
        if(i==3){
            ui->ExternalDevice_tW->setColumnWidth(i,280);
            ui->ExternalDevice_tW->setRowHeight(i,50);
        }
    }
    for(int i=0;i<3;i++)//调整 BMS保护 的列宽列高
    {
        ui->BMSProtection_tW->setColumnWidth(i,220);
        ui->BMSProtection_tW->setRowHeight(i,50);
    }
    for(int i=0;i<12;i++)//调整 调试 的列宽列高
    {
        if(i%2==0)
        {
            ui->UI_Debug_Tab->setColumnWidth(i,165);
            ui->UI_Debug_Tab->setRowHeight(i,50);
        }
        else
        {
            ui->UI_Debug_Tab->setColumnWidth(i,140);
            ui->UI_Debug_Tab->setRowHeight(i,50);
        }
    }
    for (int i=0;i<11; i++)
    {
            ui->UI_Debug_Tab->item (i,0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->UI_Debug_Tab->item (i,2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->UI_Debug_Tab->item (i,4)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    }

    FunctionSet();/*功能设置*/
    SystemParameter();/*系统参数*/
    Peripheral();/*外设*/
    BMS_Protect();/*BMS保护*/
    Debugg();/*调试*/

}

/***************************************************************
 *高级设置按钮点击功能
 ***************************************************************/
void MEGAWin::AdvancedSetup_btn_clicked()
{
    ui->UI_stackedWidget->setCurrentWidget(ui->BasicSet_page);
    if(ASKey)//保证只执行一次这句话，否则多次进出高级设置，会多次绘制页面，点击一次button，出现个消息对话框
    {
        ASKey = false;
        SystemParam_tbnt_released();
    }
}

/***************************************************************
 * @brief Connected relation function 连通关系函数
 ***************************************************************/
void MEGAWin::LinkRelationship()
{
    connect(m_menu, SIGNAL(Sent(int)), this, SLOT(My_menuAction(int)));

    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerOut()));

    connect(Update_RTData_timer, SIGNAL(timeout()), this, SLOT(updateTimeOut()));

    connect(AdvancedSetup_btn,SIGNAL(clicked(bool)), this, SLOT(AdvancedSetup_btn_clicked()));//高级设置

    connect(ui->Bypass_Batt_btn, SIGNAL(clicked()), this, SLOT(on_Batt_btn_released()));    //主页电池按钮跳转电池信息
    connect(ui->Bypass_Running_btn, SIGNAL(clicked()), this, SLOT(on_Running_btn_clicked()));   //主页变流器按钮跳转变流器实时数据
    connect(ui->Bypass_Grid_btn, SIGNAL(clicked()), this, SLOT(on_Grid_clicked()));    //主页电网按钮跳转电网实时数据
    connect(ui->Bypass_Load_Btn, SIGNAL(clicked()), this, SLOT(on_Load_clicked()));    //主页负载按钮跳转负载实时数据
    connect(ui->Alarm_Button, SIGNAL(clicked()), this,SLOT(on_Alarm_btn_clicker()));//跳转当前告警记录

    connect(pButton_History, SIGNAL(buttonClicked(int)), this,SLOT(Data_report_clicked(int)));//数据报表
    connect(pButton_BatteryData, SIGNAL(buttonClicked(int)), this,SLOT(BatteryData_clicked(int)));//电池数据
    connect(pButton_Version, SIGNAL(buttonClicked(int)), this,SLOT(SystemlnformationVer_clicked(int)));//系统信息
    connect(pButton_MonitorDebug, SIGNAL(buttonClicked(int)), this,SLOT(MonitorDebug_clicked(int)));//监控调试

}

/******************************************************************************
 * 模块实时数据表初始化
 * ***************************************************************************/
void MEGAWin::ModuleData_Tab()//PCS数据
{
        ui->Converter_Tab->clearContents();
        ui->Grid_Tab->clearContents();
        ui->Load_Tab->clearContents();
        QStringList Converter_Tablist1;
        Converter_Tablist1  << tr("PCS voltage(AB)") << tr("PCS voltage(BC)") << tr("PCS voltage(CA)")
                            << tr("PCS current(A)") << tr("PCS current(B)")<< tr("PCS current(C)")
                            << tr("PCS Active P.") << tr("PCS Reactive P.") << tr("PCS Parent P.") << tr("PCS Pf");
        QStringList Converter_Tablist2;
        Converter_Tablist2  << tr("Battery voltage") << tr("Battery current") << tr("Battery power")
                            << tr("Bus voltage") << tr("IGBT temperature")
                            << tr("Environment temperature");

       QStringList Grid_Tablist;
           Grid_Tablist << tr("Grid voltage(AB)") << tr("Grid voltage(BC)") << tr("Grid voltage(CA)")
                           << tr("Grid current(A)") << tr("Grid current(B)")<< tr("Grid current(C)")
                           << tr("Grid active power") << tr("Grid reactive power")
                            << tr("Grid apparent power") << tr("Grid frequency") << tr("Grid power factor");
       QStringList Load_Tablist;
       Load_Tablist << tr("Load voltage(AB)") << tr("Load voltage(BC)") << tr("Load voltage(CA)")
                           << tr("Load current(A)") << tr("Load current(B)")<< tr("Load current(C)")
                           << tr("Load active power") << tr("Load reactive power")
                           << tr("Load apparent power") << tr("Load power fator");
        ui->Converter_Tab->setColumnCount(4);
        ui->Converter_Tab->setRowCount(Converter_Tablist1.size());

        ui->Grid_Tab->setColumnCount(2);
        ui->Grid_Tab->setRowCount(Grid_Tablist.size());

        ui->Load_Tab->setColumnCount(2);
        ui->Load_Tab->setRowCount(Load_Tablist.size());
        //设置表格背景颜色
        QPalette pal;
        pal.setColor(QPalette::Base, QColor(255, 0, 0));
        pal.setColor(QPalette::AlternateBase, QColor(100, 149, 237));

        ui->Converter_Tab->setPalette(pal);
        ui->Converter_Tab->setAlternatingRowColors(true);
        QStringList Converter_TabList;
        Converter_TabList << tr("Name") << tr("Value") << tr("Name") << tr("Value")<< tr("Name") << tr("Value");
        ui->Converter_Tab->setHorizontalHeaderLabels(Converter_TabList);
        ui->Converter_Tab->setColumnWidth(0,200);
        ui->Converter_Tab->setColumnWidth(1,200);
        ui->Converter_Tab->setColumnWidth(2,200);
        ui->Converter_Tab->setColumnWidth(3,200);
        ui->Converter_Tab->horizontalHeader()->setStretchLastSection(3);
        ui->Converter_Tab->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
        ui->Converter_Tab->verticalHeader()->setVisible(false);//设置垂直头不可见
        ui->Converter_Tab->setFrameShape(QFrame::NoFrame);//设置无边框
        ui->Converter_Tab->setShowGrid(true);//设置不显示格子
        ui->Converter_Tab->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
        ui->Converter_Tab->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
        ui->Converter_Tab->setStyleSheet("selection-background-color:lightblue;");
        for(int i = 0; i < Converter_Tablist1.size(); i++)
        {
            ui->Converter_Tab->setItem(i, 0, new QTableWidgetItem(Converter_Tablist1.at(i)));
            ui->Converter_Tab->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        }
        for(int i = 0; i < Converter_Tablist2.size(); i++)
        {
            ui->Converter_Tab->setItem(i, 2, new QTableWidgetItem(Converter_Tablist2.at(i)));
            ui->Converter_Tab->item(i, 2)->setTextAlignment(Qt::AlignCenter);
        }

        ui->Grid_Tab->setPalette(pal);
        ui->Grid_Tab->setAlternatingRowColors(true);
        QStringList Grid_TabList;
        Grid_TabList << tr("Name") << tr("Value");
        ui->Grid_Tab->setHorizontalHeaderLabels(Grid_TabList);
        ui->Grid_Tab->setColumnWidth(0,400);
        ui->Grid_Tab->horizontalHeader()->setStretchLastSection(1);

        ui->Grid_Tab->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
        ui->Grid_Tab->verticalHeader()->setVisible(false);//设置垂直头不可见
        ui->Grid_Tab->setFrameShape(QFrame::NoFrame);//设置无边框
        ui->Grid_Tab->setShowGrid(true);//设置不显示格子
        ui->Grid_Tab->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
        ui->Grid_Tab->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
        ui->Grid_Tab->setStyleSheet("selection-background-color:lightblue;");
        for(int i = 0; i < Grid_Tablist.size(); i++)
        {
            ui->Grid_Tab->setItem(i, 0, new QTableWidgetItem(Grid_Tablist.at(i)));
            ui->Grid_Tab->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        }

        ui->Load_Tab->setPalette(pal);
        ui->Load_Tab->setAlternatingRowColors(true);
        QStringList Load_TabList;
        Load_TabList << tr("Name") << tr("Value");
        ui->Load_Tab->setHorizontalHeaderLabels(Load_TabList);
        ui->Load_Tab->setColumnWidth(0,400);
        ui->Load_Tab->horizontalHeader()->setStretchLastSection(1);
        ui->Load_Tab->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
        ui->Load_Tab->verticalHeader()->setVisible(false);//设置垂直头不可见
        ui->Load_Tab->setFrameShape(QFrame::NoFrame);//设置无边框
        ui->Load_Tab->setShowGrid(true);//设置不显示格子
        ui->Load_Tab->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
        ui->Load_Tab->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
        ui->Load_Tab->setStyleSheet("selection-background-color:lightblue;");
        for(int i = 0; i < Load_Tablist.size(); i++)
        {
            ui->Load_Tab->setItem(i, 0, new QTableWidgetItem(Load_Tablist.at(i)));
            ui->Load_Tab->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        }
        PCS_Data();//PCS数据 绘制button
        Grid_Data();//电网数据 绘制button
        Load_Data();//负载数据 绘制button

}
/******************************************************************************
 * 模块实时状态表初始化
 * ***************************************************************************/
void MEGAWin::ModuleState_Tab()//PCS状态
{

    QPalette pal;
    pal.setColor(QPalette::Base, QColor(255, 0, 0));
    pal.setColor(QPalette::AlternateBase, QColor(100, 149, 237));

    {
        QStringList RTState_Bypass_List1;// << tr("DC input breaker 2")
#ifdef Machine_V2
        RTState_Bypass_List1 << tr("DC input breaker")<< tr("DC contactor")\
            << tr("Output contactor") << tr("Output breaker") << tr("Maintenance Bypass breaker") << tr("Grid breaker");
#else
        RTState_Bypass_List1 << tr("DC input breaker")<< tr("DC contactor")\
                             << tr("Output contactor") << tr("Output breaker") \
                             << tr("Grid contactor") << tr("Grid breaker") << tr("Maintenance Bypass breaker");
#endif
        QStringList RTState_Bypass_List2;
         RTState_Bypass_List2 << tr("converter available") << tr("DC Soft start")\
                    << tr("converter status") << tr("Reactive power Regulation") << tr("LVRT");
         QStringList RTState_Bypass_List4;
          RTState_Bypass_List4 << tr("Generator signal") << tr("Reserve")\
                               << tr("Reserve") << tr("EPO contact signal 1")\
                               << tr("EPO contact signal 2") << tr("Access control signal")\
                               << tr("Full power signal") << tr("Smoke alarm signal")<< tr("Hight temp. signal");

        ui->RTState_Bypass_Tab->setColumnCount(6);
        ui->RTState_Bypass_Tab->setRowCount(9);
        ui->RTState_Bypass_Tab->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
        ui->RTState_Bypass_Tab->verticalHeader()->setVisible(false);//设置垂直头不可见
        ui->RTState_Bypass_Tab->setFrameShape(QFrame::NoFrame);//设置无边框
        ui->RTState_Bypass_Tab->setShowGrid(true);//设置显示格子
        ui->RTState_Bypass_Tab->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
        ui->RTState_Bypass_Tab->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
        ui->RTState_Bypass_Tab->setStyleSheet("selection-background-color:lightblue;");
        QStringList StateList_Bypass;
        StateList_Bypass << tr("Name") << tr("Value")<< tr("Name") << tr("Value")<< tr("Name") << tr("Value");
        ui->RTState_Bypass_Tab->setHorizontalHeaderLabels(StateList_Bypass);
        ui->RTState_Bypass_Tab->setColumnWidth(0,220);
        ui->RTState_Bypass_Tab->setColumnWidth(1,100);
        ui->RTState_Bypass_Tab->setColumnWidth(2,210);
        ui->RTState_Bypass_Tab->setColumnWidth(3,110);
        ui->RTState_Bypass_Tab->setColumnWidth(4,220);
        ui->RTState_Bypass_Tab->setColumnWidth(5,100);

        for(int i = 0; i < RTState_Bypass_List1.size(); i++)
        {
            ui->RTState_Bypass_Tab->setItem(i, 0, new QTableWidgetItem(RTState_Bypass_List1.at(i)));
            ui->RTState_Bypass_Tab->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        }
        for(int j = 0; j < RTState_Bypass_List2.size(); j++)
        {
            ui->RTState_Bypass_Tab->setItem(j, 2, new QTableWidgetItem(RTState_Bypass_List2.at(j)));
            ui->RTState_Bypass_Tab->item(j, 2)->setTextAlignment(Qt::AlignCenter);
        }
        for(int k = 0; k < RTState_Bypass_List4.size(); k++)
        {
            ui->RTState_Bypass_Tab->setItem(k, 4, new QTableWidgetItem(RTState_Bypass_List4.at(k)));
            ui->RTState_Bypass_Tab->item(k, 4)->setTextAlignment(Qt::AlignCenter);
        }
        ui->RTState_Bypass_Tab->resizeRowsToContents();
    }

    PCS_State();//PCS状态 绘制button
}


/***************************************************************
 * 菜单页面选择
 ***************************************************************/
void MEGAWin::My_menuAction(int Index)
{
    switch (Index) {
    case HOSTPAGE:
        ui->stackedWidget->setCurrentWidget(ui->Bypass_page);
        ui->RTD_PCS_StackedWidget->setCurrentWidget(ui->RTD_Bypass_Y_page);
        ui->RTState_stackedWidget->setCurrentWidget(ui->RTState_Bypass_Y_page);
        ui->BAT_stackedWidget->setCurrentWidget(ui->BAT_Lithium_page);
        break;
    case RTDATAPAGE:
        ui->RTState_stackedWidget->setCurrentWidget(ui->RTState_Bypass_Y_page);
        ui->BAT_stackedWidget->setCurrentWidget(ui->BAT_Lithium_page);
        ui->stackedWidget->setCurrentWidget(ui->Status_page);

        ui->RTD_PCS_StackedWidget->setCurrentWidget(ui->RTD_Bypass_Y_page);
        break;
    case RECORDPAGE:
        ui->Record_tabWidget->setCurrentWidget(ui->HistoryRecord_page);
        ui->Record_tabWidget->setCurrentWidget(ui->DataReport_page);
        ui->Report_tab->setCurrentWidget(ui->Report_tabPage_T);
        ui->dateEdit->setDate(QDateTime::currentDateTime().date());
        ui->stackedWidget->setCurrentWidget(ui->Record_page);
        break;
    case SYSTEMPAGE:
        ui->stackedWidget->setCurrentWidget(ui->System_page);
        ui->BatterSet_stackedWidget->setCurrentWidget(ui->Lithium_stackedWidgetPage);
        ui->System_tabWidget->setCurrentIndex(0);
        break;
    case MACHINECLOSE:
        QMessageBox::question(this, "Turn off"\
                              ,"这是变流器关闭开关，点击后开关闭变流器\nThis is the converter off switch. Click to turn on and off the converter", "OK");
        break;
    case MACHINESTANDBY:
        QMessageBox::question(this, "Stand-by"\
                              ,"这是变流器待机开关，点击后变流器进入待机状态\nThis is the converter standby switch. Click the converter to enter the standby state", "OK");
        break;
    case MACHINEOPEN:
        QMessageBox::question(this, "Turn on"\
                              ,"这是变流器打开开关,点击后开启变流器\nThis is the converter on switch, click to turn on the converter", "OK");
        break;
    default:
        break;
    }
}


/************************初始化界面********************************/
void MEGAWin::UIPageInit()
{
    FirstPage();//主页点击

    RunStatePage();//PCS运行状态页

    SystemSettingPage();//系统设置页面初始化

    LCDSetting();//时间设置

    LinkRelationship();//函数关联

}

void MEGAWin::LoadLanguageInit()
{
    translator = new QTranslator(qApp);
    if(LanguageType == CHINESE)//开机语言 中文
    {
        translator->load(":/Language/CN.qm");
        qApp->installTranslator(translator);
        ui->retranslateUi(this);
        LanguageType = CHINESE;
    }
    else if(LanguageType == ENGLISH)//开机语言 英文
    {
        translator->load(":/Language/EN.qm");
        qApp->installTranslator(translator);
        ui->retranslateUi(this);
        LanguageType = ENGLISH;
    }
}

void MEGAWin::on_UI_MenuBtn_clicked()   //菜单
{
    if(m_menu->isHidden())
    {
        m_menu->setGeometry(0, 0, 250, 453);
        m_menu->move(QPoint((this->pos().x() + 10),(this->pos().y() + 85)));
        m_menu->show();
    }
    else
    {
        m_menu->hide();
    }
}

void MEGAWin::on_UI_Complete_Btn_clicked()//退出高级设置
{
    ui->UI_stackedWidget->setCurrentWidget(ui->UI_page);
}

void MEGAWin::on_Running_btn_clicked()  //显示变流器实时数据
{
    ui->stackedWidget->setCurrentWidget(ui->Status_page);
    ui->Run_tabWidget->setCurrentWidget(ui->RTData_page);
    ui->RTD_PCS_StackedWidget->setCurrentWidget(ui->RTD_Bypass_Y_page);
    ui->Bypass_Tab->setCurrentWidget(ui->Bypass_Converter_page);

}

void MEGAWin::on_Grid_clicked()     //显示电网端实时数据
{
    ui->stackedWidget->setCurrentWidget(ui->Status_page);
    ui->Run_tabWidget->setCurrentWidget(ui->RTData_page);
    ui->RTD_PCS_StackedWidget->setCurrentWidget(ui->RTD_Bypass_Y_page);
    ui->Bypass_Tab->setCurrentWidget(ui->Bypass_Grid_page);
}

void MEGAWin::on_Load_clicked()     //显示负载端实时数据
{
    ui->stackedWidget->setCurrentWidget(ui->Status_page);
    ui->Run_tabWidget->setCurrentWidget(ui->RTData_page);
    ui->RTD_PCS_StackedWidget->setCurrentWidget(ui->RTD_Bypass_Y_page);
    ui->Bypass_Tab->setCurrentWidget(ui->Bypass_Load_page);
}

void MEGAWin::on_Batt_btn_released()    //显示电池信息
{
    ui->stackedWidget->setCurrentWidget(ui->Status_page);
    ui->Run_tabWidget->setCurrentWidget(ui->BatteryData_page);
    ui->BAT_stackedWidget->setCurrentWidget(ui->BAT_Lithium_page);
}

void MEGAWin::on_Alarm_btn_clicker()    //显示告警信息
{
    ui->stackedWidget->setCurrentWidget(ui->Status_page);
    ui->Run_tabWidget->setCurrentWidget(ui->RTAlarm_page);
}

void MEGAWin::on_SConverter_btn_clicked()   //显示变流器实时数据
{
    ui->Bypass_Tab->setCurrentWidget(ui->Bypass_Converter_page);
}

void MEGAWin::on_SGrid_btn_clicked()    //显示电网实时数据
{
    ui->Bypass_Tab->setCurrentWidget(ui->Bypass_Grid_page);
}

void MEGAWin::on_SLoad_btn_clicked()    //显示负载实时数据
{
    ui->Bypass_Tab->setCurrentWidget(ui->Bypass_Load_page);
}

/******************实时数据界面选项卡点击响应*******************/
void MEGAWin::on_Run_tabWidget_tabBarClicked(int index)
{
    switch (index) {
    case Analoge_PAGE:

        break;
    case State_PAGE:

        break;
    case Alarm_PAGE:

        break;
    case BAT_PAGE:
        ui->stackedWidget->setCurrentWidget(ui->Status_page);
        ui->Run_tabWidget->setCurrentWidget(ui->BatteryData_page);
        ui->BAT_stackedWidget->setCurrentWidget(ui->BAT_Lithium_page);
        break;
    }

}

/****************数据报表点击槽****************/
void MEGAWin::Data_report_clicked(int nid)
{
    switch (nid) {
    case 0:
        QMessageBox::question(this, "Discharge Day"\
                              ,"这里显示当日放电电量,点击此处将跳转到每日充放电量的直方图，横轴单位为日，纵轴单位为功率(kWh)\nToday's discharge is shown here. Click here to jump to the histogram of daily charge and discharge. The horizontal axis is in days and the vertical axis is in power (kWh).", "OK");
        break;
    case 1:
        QMessageBox::question(this, "Discharge Month"\
                              ,"这里显示当月放电电量,点击此处将跳转到每月充放电量的直方图，横轴单位为月，纵轴单位为功率(kWh)\nThis shows the discharge amount of this month. Click here to jump to the histogram of monthly charge and discharge amount. The horizontal axis is in month and the vertical axis is in power (kWh).", "OK");
        break;
    case 2:
        QMessageBox::question(this, "Discharge Year"\
                              ,"这里显示当年放电电量,点击此处将跳转到每年充放电量的直方图，横轴单位为年，纵轴单位为功率(kWh)\nThis shows the discharge amount of this year. Click here to jump to the histogram of the annual charge and discharge amount. The horizontal axis is in year, and the vertical axis is in power (kWh).", "OK");
        break;
    case 3:
        QMessageBox::question(this, "Discharge Total"\
                              ,"这里显示总放电电量，点击此处将跳转到总览图\nThe total discharge power is displayed here. Click here to jump to the overview chart.", "OK");
        break;
    case 4:
        QMessageBox::question(this, "Charge Day"\
                              ,"这里显示当日充电电量,点击此处将跳转到每日充放电量的直方图，横轴单位为日，纵轴单位为功率(kWh)\nToday's charging is shown here. Click here to jump to the histogram of daily charging and discharging. The horizontal axis is in days, and the vertical axis is in power (kWh).", "OK");
        break;
    case 5:
        QMessageBox::question(this, "Charge Month"\
                              ,"这里显示当月充电电量,点击此处将跳转到每月充放电量的直方图，横轴单位为月，纵轴单位为功率(kWh)\nThis shows the amount of charging in this month. Click here to jump to the histogram of monthly charging and discharging. The horizontal axis is in month and the vertical axis is in power (kWh).", "OK");
        break;
    case 6:
        QMessageBox::question(this, "Charge Year"\
                              ,"这里显示当年充电电量,点击此处将跳转到每年充放电量的直方图，横轴单位为年，纵轴单位为功率(kWh)\nThis shows the amount of charging for this year. Click here to jump to the histogram of charging and discharging for each year. The horizontal axis is in years and the vertical axis is in power (kWh).", "OK");
        break;
    case 7:
        QMessageBox::question(this, "Charge Total"\
                              ,"这里显示总充电电量，点击此处将跳转到总览图\nThis shows the total amount of charging, click here to jump to the overview chart.", "OK");
        break;
    case 8:
        QMessageBox::question(this, "Month-"\
                              ,"查看上一个月的数据，点击后将显示当前显示月份的上一个月的数据\nTo view the data of the previous month, click on it to display the data of the previous month of the current displayed month.", "OK");
        break;
    case 9:
        QMessageBox::question(this, "Year-"\
                              ,"查看上一年的数据，点击后将显示当前显示年份的上一年的数据\nTo view the previous year's data, click on it to display the previous year's data for the current displayed year.", "OK");
        break;
    case 10:
        QMessageBox::question(this, "Daily electricity quantity"\
                              ,"查看当日充放电量，点击此处将跳转到每日充放电量的直方图，横轴单位为日，纵轴单位为功率(kWh)\nTo view the daily charge and discharge volume, click here to jump to the histogram of daily charge and discharge volume. The horizontal axis is in day, and the vertical axis is in power (kWh).", "OK");
        break;
    case 11:
        QMessageBox::question(this, "Annual electricity quantity"\
                              ,"查看当年充放电量,点击此处将跳转到每年充放电量的直方图，横轴单位为年，纵轴单位为功率(kWh)\nTo view the annual charge and discharge volume, click here to jump to the histogram of the annual charge and discharge volume, the horizontal axis is in year, and the vertical axis is in power (kWh).", "OK");
        break;
    case 12:
        QMessageBox::question(this, "Month+"\
                              ,"查看下一个月的数据，点击后将显示当前显示月份的下一个月的数据\nTo view the data for the next month, click to display the data for the next month of the current displayed month.", "OK");
        break;
    case 13:
        QMessageBox::question(this, "Year+"\
                              ,"查看下一年的数据，点击后将显示当前显示年份的下一年的数据\nTo view the data for the next year, click on it to display the data for the next year of the current displayed year.", "OK");
        break;
    case 14:
        QMessageBox::question(this, "Monthly electric quantity"\
                              ,"查看当月充放电量,点击此处将跳转到每月充放电量的直方图，横轴单位为月，纵轴单位为功率(kWh)\nTo view the monthly charge and discharge volume, click here to jump to the histogram of monthly charge and discharge volume. The horizontal axis is in month, and the vertical axis is in power (kWh).", "OK");
        break;
    case 15:
        QMessageBox::question(this, "Total electric quantity"\
                              ,"查看总充放电量，点击此处将跳转到总览图\nTo view the total charge and discharge, click here to jump to the overview chart.", "OK");
        break;
    case 16:
        QMessageBox::question(this, "HistoricalFailure"\
                              ,"导出历史记录，点击此处将会导出历史记录到U盘里\nTo export history, click here to export history to U disk", "OK");
        break;
    case 17:
        QMessageBox::question(this, "OperationLog"\
                              ,"导出操作日志，点击此处将会导出操作日志到U盘里\nExport operation log. Click here to export operation log to U disk.", "OK");
        break;
    case 18:
        QMessageBox::question(this, "Coulombmeter report"\
                              ,"导出电量统计表，点击此处将会导出电量统计表到U盘里\nExport the battery statistics. Click here to export the battery statistics to the U disk.", "OK");
        break;
    case 19:
        QMessageBox::question(this, "Eject Udisk"\
                              ,"退出U盘，将挂载到显控的U盘取消挂载，以保证U盘数据不会损坏\nExit the U disk and unmount the U disk mounted to the display control to ensure that the data in the U disk will not be damaged.", "OK");
        break;
    }

}
/******************系统信息点击槽***********************/
void MEGAWin::SystemlnformationVer_clicked(int nid)
{
    switch (nid) {
    case 0:
        QMessageBox::question(this, "Interface"\
                              ,"这是接口号，默认eth0\nThis is the interface number, which defaults to eth0", "OK");
        break;
    case 1:
        QMessageBox::question(this, "Port"\
                              ,"这是端口号，默认502\nThis is the port number, default 502", "OK");
        break;
    case 2:
        QMessageBox::question(this, "Ip"\
                              ,"这是IP地址，默认192.168.1.100\nThis is the IP address. The default is 192.168.1.100", "OK");
        break;
    case 3:
        QMessageBox::question(this, "Netmask"\
                              ,"这是子网掩码，255.255.255.0\nThis is the subnet mask, 255.255.255.0", "OK");
        break;
    case 4:
        QMessageBox::question(this, "Gateway"\
                              ,"这是网关，默认192.168.1.1\nThis is the gateway. The default is 192.168.1.1", "OK");
        break;
    case 5:
        QMessageBox::question(this, "Serber ip"\
                              ,"这是服务器IP，默认192.168.1.200\nThis is the server IP address. The default is 192.168.1.200", "OK");
        break;
    case 6:
        QMessageBox::question(this, "Apply and Restart system"\
                              ,"这是应用并重启系统，点击后将重启系统，如有升级，将会使用新的程序\nThis is the application and restart the system, click will restart the system, if there is an upgrade, will use the new program.", "OK");
        break;
    default:
        break;
    }
}
/******************监控调试点击槽***********************/
void MEGAWin::MonitorDebug_clicked(int nid)
{
    switch (nid) {
        case 0:
            QMessageBox::question(this, "DO turn on"\
                              ,"这是DO控制闭合，仅提供内部调试使用\nThis is the DO control closure, provided for internal debugging use only.", "OK");
            break;
        case 1:
            QMessageBox::question(this, "Do turn off"\
                              ,"这是DO控制断开，仅提供内部调试使用\nThis is the DO control off, provided for internal debugging use only.", "OK");
            break;
        case 2:
            QMessageBox::question(this, "Local on"\
                              ,"这是启动本地软启动，仅提供内部调试使用\nThis is to start a local soft boot, only for internal debugging use.", "OK");
            break;
        case 3:
            QMessageBox::question(this, "Local off"\
                              ,"这是关闭本地软启动，仅提供内部调试使用\nThis is to turn off the local soft boot for internal debugging use only.", "OK");
            break;
        case 4:
            QMessageBox::question(this, "BMS power on"\
                          ,"这是电池上电\nThis is power on the battery.", "OK");
            break;
        case 5:
            QMessageBox::question(this, "BMS power off"\
                          ,"这是电池下电\nThis is power off the battery.", "OK");
            break;
        default:
            break;
    }
}
/******************历史记录 绘制button***********************/
void MEGAWin::History()
{
    QStringList table_h_headers;
    table_h_headers.clear();
    table_h_headers << tr("Level") << tr("Start Time") << tr("End Time") << tr("Description");
    ui->Historicalfailure_tableWidget->setColumnCount(table_h_headers.size());
    ui->Historicalfailure_tableWidget->setRowCount(8);
    ui->Historicalfailure_tableWidget->setHorizontalHeaderLabels(table_h_headers);
    ui->Historicalfailure_tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->Historicalfailure_tableWidget->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->Historicalfailure_tableWidget->setShowGrid(true);//设置显示格子
    ui->Historicalfailure_tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    ui->Historicalfailure_tableWidget->setEditTriggers(QAbstractItemView::SelectedClicked);//单机修改
    ui->Historicalfailure_tableWidget->setColumnWidth(0,50);
    ui->Historicalfailure_tableWidget->setColumnWidth(1,180);
    ui->Historicalfailure_tableWidget->setColumnWidth(2,180);
    ui->Historicalfailure_tableWidget->horizontalHeader()->setStretchLastSection(true);

    Grade_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    Grade2_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    Grade3_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    Grade4_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    Grade5_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    Grade6_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    Grade7_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    Grade8_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    StartTime_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    StartTime2_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    StartTime3_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    StartTime4_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    StartTime5_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    StartTime6_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    StartTime7_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    StartTime8_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    EndTime_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    EndTime2_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    EndTime3_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    EndTime4_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    EndTime5_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    EndTime6_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    EndTime7_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    EndTime8_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    Describe_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    Describe2_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    Describe3_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    Describe4_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    Describe5_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    Describe6_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    Describe7_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
    Describe8_explain->setStyleSheet("background-color:rgb(200, 0, 0);");

    Grade = new Specification(this,Grade_explain, ui->Historicalfailure_tableWidget, 0, 0, \
                                                    "0", "Level", \
                                                    "这是事件告警等级，当事件告警等级为0时标红，表示这是故障信息\nThis is the event alarm level. When the event alarm level is 0, it is marked red, indicating that this is the fault information.");
    Grade->add_Specification();
    Grade2 = new Specification(this,Grade2_explain, ui->Historicalfailure_tableWidget, 1, 0, \
                                                    "0", "Level", \
                                                    "这是事件告警等级，当事件告警等级为0时标红，表示这是故障信息\nThis is the event alarm level. When the event alarm level is 0, it is marked red, indicating that this is the fault information.");
    Grade2->add_Specification();
    Grade3 = new Specification(this,Grade3_explain, ui->Historicalfailure_tableWidget, 2, 0, \
                                                    "0", "Level", \
                                                    "这是事件告警等级，当事件告警等级为0时标红，表示这是故障信息\nThis is the event alarm level. When the event alarm level is 0, it is marked red, indicating that this is the fault information.");
    Grade3->add_Specification();
    Grade4 = new Specification(this,Grade4_explain, ui->Historicalfailure_tableWidget, 3, 0, \
                                                    "0", "Level", \
                                                    "这是事件告警等级，当事件告警等级为0时标红，表示这是故障信息\nThis is the event alarm level. When the event alarm level is 0, it is marked red, indicating that this is the fault information.");
    Grade4->add_Specification();
    Grade5 = new Specification(this,Grade5_explain, ui->Historicalfailure_tableWidget, 4, 0, \
                                                    "0", "Level", \
                                                    "这是事件告警等级，当事件告警等级为0时标红，表示这是故障信息\nThis is the event alarm level. When the event alarm level is 0, it is marked red, indicating that this is the fault information.");
    Grade5->add_Specification();
    Grade6 = new Specification(this,Grade6_explain, ui->Historicalfailure_tableWidget, 5, 0, \
                                                    "0", "Level", \
                                                    "这是事件告警等级，当事件告警等级为0时标红，表示这是故障信息\nThis is the event alarm level. When the event alarm level is 0, it is marked red, indicating that this is the fault information.");
    Grade6->add_Specification();
    Grade7 = new Specification(this,Grade7_explain, ui->Historicalfailure_tableWidget, 6, 0, \
                                                    "0", "Level", \
                                                    "这是事件告警等级，当事件告警等级为0时标红，表示这是故障信息\nThis is the event alarm level. When the event alarm level is 0, it is marked red, indicating that this is the fault information.");
    Grade7->add_Specification();
    Grade8 = new Specification(this,Grade8_explain, ui->Historicalfailure_tableWidget, 7, 0, \
                                                    "0", "Level", \
                                                    "这是事件告警等级，当事件告警等级为0时标红，表示这是故障信息\nThis is the event alarm level. When the event alarm level is 0, it is marked red, indicating that this is the fault information.");
    Grade8->add_Specification();
    StartTime = new Specification(this,StartTime_explain, ui->Historicalfailure_tableWidget, 0, 1, \
                                                    "2023.5.6 15:49:50", "Start Time", \
                                                    "这是事件开始时间，表示这条记录从这个时间开始出现\nThis is the event start time, which means that the record started appearing at this time.");
    StartTime->add_Specification();
    StartTime2 = new Specification(this,StartTime2_explain, ui->Historicalfailure_tableWidget, 1, 1, \
                                                    "2023.5.6 15:48:18", "Start Time", \
                                                    "这是事件开始时间，表示这条记录从这个时间开始出现\nThis is the event start time, which means that the record started appearing at this time.");
    StartTime2->add_Specification();
    StartTime3 = new Specification(this,StartTime3_explain, ui->Historicalfailure_tableWidget, 2, 1, \
                                                    "2023.5.6 15:39:3", "Start Time", \
                                                    "这是事件开始时间，表示这条记录从这个时间开始出现\nThis is the event start time, which means that the record started appearing at this time.");
    StartTime3->add_Specification();
    StartTime4 = new Specification(this,StartTime4_explain, ui->Historicalfailure_tableWidget, 3, 1, \
                                                    "2023.5.6 15:39:3", "Start Time", \
                                                    "这是事件开始时间，表示这条记录从这个时间开始出现\nThis is the event start time, which means that the record started appearing at this time.");
    StartTime4->add_Specification();
    StartTime5 = new Specification(this,StartTime5_explain, ui->Historicalfailure_tableWidget, 4, 1, \
                                                    "2023.5.6 15:39:3", "Start Time", \
                                                    "这是事件开始时间，表示这条记录从这个时间开始出现\nThis is the event start time, which means that the record started appearing at this time.");
    StartTime5->add_Specification();
    StartTime6 = new Specification(this,StartTime6_explain, ui->Historicalfailure_tableWidget, 5, 1, \
                                                    "2023.5.6 15:21:56", "Start Time", \
                                                    "这是事件开始时间，表示这条记录从这个时间开始出现\nThis is the event start time, which means that the record started appearing at this time.");
    StartTime6->add_Specification();
    StartTime7 = new Specification(this,StartTime7_explain, ui->Historicalfailure_tableWidget, 6, 1, \
                                                    "2023.5.6 15:21:38", "Start Time", \
                                                    "这是事件开始时间，表示这条记录从这个时间开始出现\nThis is the event start time, which means that the record started appearing at this time.");
    StartTime7->add_Specification();
    StartTime8 = new Specification(this,StartTime8_explain, ui->Historicalfailure_tableWidget, 7, 1, \
                                                    "2023.5.6 15:21:38", "Start Time", \
                                                    "这是事件开始时间，表示这条记录从这个时间开始出现\nThis is the event start time, which means that the record started appearing at this time.");
    StartTime8->add_Specification();
    EndTime = new Specification(this,EndTime_explain, ui->Historicalfailure_tableWidget, 0, 2, \
                                                    "-", "End Time", \
                                                    "这是事件结束时间，表示这条记录的结束时间,'...'表示无结束时间\nThis is the event end time, which means the end time of this record,'... 'means no end time.");
    EndTime->add_Specification();
    EndTime2 = new Specification(this,EndTime2_explain, ui->Historicalfailure_tableWidget, 1, 2, \
                                                    "-", "End Time", \
                                                    "这是事件结束时间，表示这条记录的结束时间,'...'表示无结束时间\nThis is the event end time, which means the end time of this record,'... 'means no end time.");
    EndTime2->add_Specification();
    EndTime3 = new Specification(this,EndTime3_explain, ui->Historicalfailure_tableWidget, 2, 2, \
                                                    "...", "End Time", \
                                                    "这是事件结束时间，表示这条记录的结束时间,'...'表示无结束时间\nThis is the event end time, which means the end time of this record,'... 'means no end time.");
    EndTime3->add_Specification();
    EndTime4 = new Specification(this,EndTime4_explain, ui->Historicalfailure_tableWidget, 3, 2, \
                                                    "-", "End Time", \
                                                    "这是事件结束时间，表示这条记录的结束时间,'...'表示无结束时间\nThis is the event end time, which means the end time of this record,'... 'means no end time.");
    EndTime4->add_Specification();
    EndTime5 = new Specification(this,EndTime5_explain, ui->Historicalfailure_tableWidget, 4, 2, \
                                                    "...", "End Time", \
                                                    "这是事件结束时间，表示这条记录的结束时间,'...'表示无结束时间\nThis is the event end time, which means the end time of this record,'... 'means no end time.");
    EndTime5->add_Specification();
    EndTime6 = new Specification(this,EndTime6_explain, ui->Historicalfailure_tableWidget, 5, 2, \
                                                    "-", "End Time", \
                                                    "这是事件结束时间，表示这条记录的结束时间,'...'表示无结束时间\nThis is the event end time, which means the end time of this record,'... 'means no end time.");
    EndTime6->add_Specification();
    EndTime7 = new Specification(this,EndTime7_explain, ui->Historicalfailure_tableWidget, 6, 2, \
                                                    "-", "End Time", \
                                                    "这是事件结束时间，表示这条记录的结束时间,'...'表示无结束时间\nThis is the event end time, which means the end time of this record,'... 'means no end time.");
    EndTime7->add_Specification();
    EndTime8 = new Specification(this,EndTime8_explain, ui->Historicalfailure_tableWidget, 7, 2, \
                                                    "-", "End Time", \
                                                    "这是事件结束时间，表示这条记录的结束时间,'...'表示无结束时间\nThis is the event end time, which means the end time of this record,'... 'means no end time.");
    EndTime8->add_Specification();
    Describe = new Specification(this,Describe_explain, ui->Historicalfailure_tableWidget, 0, 3, \
                                                    "CAN communication failure", "Description", \
                                                    "这是事件描述，当有告警信息时，会将告警信息记录在这里\nThis is the event description, when there is an alarm information, the alarm information will be recorded here.");
    Describe->add_Specification();
    Describe2 = new Specification(this,Describe2_explain, ui->Historicalfailure_tableWidget, 1, 3, \
                                                    "CAN communication failure", "Description", \
                                                    "这是事件描述，当有告警信息时，会将告警信息记录在这里\nThis is the event description, when there is an alarm information, the alarm information will be recorded here.");
    Describe2->add_Specification();
    Describe3 = new Specification(this,Describe3_explain, ui->Historicalfailure_tableWidget, 2, 3, \
                                                    "Fire alarm (High temp. alarm)", "Description", \
                                                    "这是事件描述，当有告警信息时，会将告警信息记录在这里\nThis is the event description, when there is an alarm information, the alarm information will be recorded here.");
    Describe3->add_Specification();
    Describe4 = new Specification(this,Describe4_explain, ui->Historicalfailure_tableWidget, 3, 3, \
                                                    "CAN communication failure", "Description", \
                                                    "这是事件描述，当有告警信息时，会将告警信息记录在这里\nThis is the event description, when there is an alarm information, the alarm information will be recorded here.");
    Describe4->add_Specification();
    Describe5 = new Specification(this,Describe5_explain, ui->Historicalfailure_tableWidget, 4, 3, \
                                                    "PowerMeter Comm fualttLead-acid abnormal", "Description", \
                                                    "这是事件描述，当有告警信息时，会将告警信息记录在这里\nThis is the event description, when there is an alarm information, the alarm information will be recorded here.");
    Describe5->add_Specification();
    Describe6 = new Specification(this,Describe6_explain, ui->Historicalfailure_tableWidget, 5, 3, \
                                                    "CAN communication failure", "Description", \
                                                    "这是事件描述，当有告警信息时，会将告警信息记录在这里\nThis is the event description, when there is an alarm information, the alarm information will be recorded here.");
    Describe6->add_Specification();
    Describe7 = new Specification(this,Describe7_explain, ui->Historicalfailure_tableWidget, 6, 3, \
                                                    "Fire alarm (High temp. alarm)", "Description", \
                                                    "这是事件描述，当有告警信息时，会将告警信息记录在这里\nThis is the event description, when there is an alarm information, the alarm information will be recorded here.");
    Describe7->add_Specification();
    Describe8 = new Specification(this,Describe8_explain, ui->Historicalfailure_tableWidget, 7, 3, \
                                                    "PowerMeter Comm fualttLead-acid abnormal", "Description", \
                                                    "这是事件描述，当有告警信息时，会将告警信息记录在这里\nThis is the event description, when there is an alarm information, the alarm information will be recorded here.");
    Describe8->add_Specification();
}
/******************操作日志 绘制button***********************/
void MEGAWin::OperationLog()
{
    QStringList Ope_headers;
    Ope_headers.clear();
    Ope_headers << tr("ModificationTime") << tr("RecordEvent");
    ui->Operation_tableWidget->setColumnCount(Ope_headers.size());
    ui->Operation_tableWidget->setRowCount(8);
    ui->Operation_tableWidget->setHorizontalHeaderLabels(Ope_headers);
    ui->Operation_tableWidget->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->Operation_tableWidget->setShowGrid(true);//设置显示格子
    ui->Operation_tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    ui->Operation_tableWidget->setEditTriggers(QAbstractItemView::SelectedClicked);//单机修改
    ui->Operation_tableWidget->setColumnWidth(0,260);
    ui->Operation_tableWidget->horizontalHeader()->setStretchLastSection(true);

    ModificationTime = new Specification(this,ModificationTime_explain, ui->Operation_tableWidget, 0, 0, \
                                                    "2023-05-12 11:32:45", "ModificationTime", \
                                                    "系统设置修改时的时间\nTime when the system Settings are modified");
    ModificationTime->add_Specification();
    ModificationTime2 = new Specification(this,ModificationTime2_explain, ui->Operation_tableWidget, 1, 0, \
                                                    "2023-05-12 11:32:33", "ModificationTime", \
                                                    "系统设置修改时的时间\nTime when the system Settings are modified");
    ModificationTime2->add_Specification();
    ModificationTime3 = new Specification(this,ModificationTime3_explain, ui->Operation_tableWidget, 2, 0, \
                                                    "2023-05-11 19:29:24", "ModificationTime", \
                                                    "系统设置修改时的时间\nTime when the system Settings are modified");
    ModificationTime3->add_Specification();
    ModificationTime4 = new Specification(this,ModificationTime4_explain, ui->Operation_tableWidget, 3, 0, \
                                                    "2023-05-11 19:29:21", "ModificationTime", \
                                                    "系统设置修改时的时间\nTime when the system Settings are modified");
    ModificationTime4->add_Specification();
    ModificationTime5 = new Specification(this,ModificationTime5_explain, ui->Operation_tableWidget, 4, 0, \
                                                    "2023-05-11 19:29:10", "ModificationTime", \
                                                    "系统设置修改时的时间\nTime when the system Settings are modified");
    ModificationTime5->add_Specification();
    ModificationTime6 = new Specification(this,ModificationTime6_explain, ui->Operation_tableWidget, 5, 0, \
                                                    "2023-05-11 19:29:07", "ModificationTime", \
                                                    "系统设置修改时的时间\nTime when the system Settings are modified");
    ModificationTime6->add_Specification();
    ModificationTime7 = new Specification(this,ModificationTime7_explain, ui->Operation_tableWidget, 6, 0, \
                                                    "2023-05-11 17:21:16", "ModificationTime", \
                                                    "系统设置修改时的时间\nTime when the system Settings are modified");
    ModificationTime7->add_Specification();
    ModificationTime8 = new Specification(this,ModificationTime8_explain, ui->Operation_tableWidget, 7, 0, \
                                                    "2023-05-11 11:21:02", "ModificationTime", \
                                                    "系统设置修改时的时间\nTime when the system Settings are modified");
    ModificationTime8->add_Specification();
    ModificationTime9 = new Specification(this,ModificationTime9_explain, ui->Operation_tableWidget, 8, 0, \
                                                    "2023-05-11 11:20:58", "ModificationTime", \
                                                    "系统设置修改时的时间\nTime when the system Settings are modified");
    ModificationTime9->add_Specification();
    ModificationTime10 = new Specification(this,ModificationTime10_explain, ui->Operation_tableWidget, 9, 0, \
                                                    "2023-05-11 11:02:22", "ModificationTime", \
                                                    "系统设置修改时的时间\nTime when the system Settings are modified");
    ModificationTime10->add_Specification();
    ModificationTime11 = new Specification(this,ModificationTime11_explain, ui->Operation_tableWidget, 10, 0, \
                                                    "2023-05-11 11:02:18", "ModificationTime", \
                                                    "系统设置修改时的时间\nTime when the system Settings are modified");
    ModificationTime11->add_Specification();
    ModificationTime12 = new Specification(this,ModificationTime12_explain, ui->Operation_tableWidget, 11, 0, \
                                                    "2023-05-11 11:02:14", "ModificationTime", \
                                                    "系统设置修改时的时间\nTime when the system Settings are modified");
    ModificationTime12->add_Specification();
    EventRecord = new Specification(this,EventRecord_explain, ui->Operation_tableWidget, 0, 1, \
                                                    "Power control type：CP_P->CP_N&&P", "RecordEvent", \
                                                    "这里是对系统设置进行修改时的操作记录\nHere is a record of the operation when a change is made to the system Settings.");
    EventRecord->add_Specification();
    EventRecord2 = new Specification(this,EventRecord2_explain, ui->Operation_tableWidget, 1, 1, \
                                                    "Power control type：CP_N&&P->CP_P", "RecordEvent", \
                                                    "这里是对系统设置进行修改时的操作记录\nHere is a record of the operation when a change is made to the system Settings.");
    EventRecord2->add_Specification();
    EventRecord3 = new Specification(this,EventRecord3_explain, ui->Operation_tableWidget, 2, 1, \
                                                    "Grid Fre Upper limit：0.2->3", "RecordEvent", \
                                                    "这里是对系统设置进行修改时的操作记录\nHere is a record of the operation when a change is made to the system Settings.");
    EventRecord3->add_Specification();
    EventRecord4 = new Specification(this,EventRecord4_explain, ui->Operation_tableWidget, 3, 1, \
                                                    "Grid Fre Upper limit：3->0.2", "RecordEvent", \
                                                    "这里是对系统设置进行修改时的操作记录\nHere is a record of the operation when a change is made to the system Settings.");
    EventRecord4->add_Specification();
    EventRecord5 = new Specification(this,EventRecord5_explain, ui->Operation_tableWidget, 4, 1, \
                                                    "Voltage protection Lower limit：-10->-15", "RecordEvent", \
                                                    "这里是对系统设置进行修改时的操作记录\nHere is a record of the operation when a change is made to the system Settings.");
    EventRecord5->add_Specification();
    EventRecord6 = new Specification(this,EventRecord6_explain, ui->Operation_tableWidget, 5, 1, \
                                                    "Voltage protection Lower limit：-15->-10", "RecordEvent", \
                                                    "这里是对系统设置进行修改时的操作记录\nHere is a record of the operation when a change is made to the system Settings.");
    EventRecord6->add_Specification();
    EventRecord7 = new Specification(this,EventRecord7_explain, ui->Operation_tableWidget, 6, 1, \
                                                    "Operation mode：Prevent countercurrnet->Peak valley", "RecordEvent", \
                                                    "这里是对系统设置进行修改时的操作记录\nHere is a record of the operation when a change is made to the system Settings.");
    EventRecord7->add_Specification();
    EventRecord8 = new Specification(this,EventRecord8_explain, ui->Operation_tableWidget, 7, 1, \
                                                    "Operation mode：UPS->Prevent countercurrnet", "RecordEvent", \
                                                    "这里是对系统设置进行修改时的操作记录\nHere is a record of the operation when a change is made to the system Settings.");
    EventRecord8->add_Specification();
    EventRecord9 = new Specification(this,EventRecord9_explain, ui->Operation_tableWidget, 8, 1, \
                                                    "Operation mode：Manual->UPS", "RecordEvent", \
                                                    "这里是对系统设置进行修改时的操作记录\nHere is a record of the operation when a change is made to the system Settings.");
    EventRecord9->add_Specification();
    EventRecord10 = new Specification(this,EventRecord10_explain, ui->Operation_tableWidget, 9, 1, \
                                                    "Operation mode：Peak valley->Manual", "RecordEvent", \
                                                    "这里是对系统设置进行修改时的操作记录\nHere is a record of the operation when a change is made to the system Settings.");
    EventRecord10->add_Specification();
    EventRecord11 = new Specification(this,EventRecord11_explain, ui->Operation_tableWidget, 10, 1, \
                                                    "Inv ON/Off-Grid：Off->automatic", "RecordEvent", \
                                                    "这里是对系统设置进行修改时的操作记录\nHere is a record of the operation when a change is made to the system Settings.");
    EventRecord11->add_Specification();
    EventRecord12 = new Specification(this,EventRecord12_explain, ui->Operation_tableWidget, 11, 1, \
                                                    "Inv ON/Off-Grid：automatic->Off", "RecordEvent", \
                                                    "这里是对系统设置进行修改时的操作记录\nHere is a record of the operation when a change is made to the system Settings.");
    EventRecord12->add_Specification();
}
/******************告警信息 绘表***********************/
void MEGAWin::RTAlarm()
{
    ui->RTAlarm_Data_page->setColumnCount(5);
    ui->RTAlarm_Data_page->setRowCount(30);
    ui->RTAlarm_Data_page->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->RTAlarm_Data_page->verticalHeader()->setVisible(false);//设置垂直头不可见
    ui->RTAlarm_Data_page->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->RTAlarm_Data_page->setShowGrid(true);//设置显示格子
    ui->RTAlarm_Data_page->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    ui->RTAlarm_Data_page->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
    ui->RTAlarm_Data_page->setStyleSheet("selection-background-color:lightblue;");

    ui->RTAlarm_Data_page->setColumnWidth(0,110);
    ui->RTAlarm_Data_page->setColumnWidth(1,85);
    ui->RTAlarm_Data_page->setColumnWidth(2,305);
    ui->RTAlarm_Data_page->setColumnWidth(3,200);
    ui->RTAlarm_Data_page->setColumnWidth(4,250);

    QStringList RTAlarm_Title;
    RTAlarm_Title << tr("Alarm name") << tr("Alarm leve")<< tr("Trigger condition") \
                    << tr("Response action")<< tr("Whether to reset\nautomatically and reset time");
    ui->RTAlarm_Data_page->setHorizontalHeaderLabels(RTAlarm_Title);

    PCS_Alarm_information_table();  //展示PCS故障信息表
}
/*********电池数据点击槽**********/
void MEGAWin::BatteryData_clicked(int nid)
{

    switch (nid) {
    case 0:
        QMessageBox::question(this, "Bat volage"\
                              ,"这是通过CAN/485/TCP通讯协议从BMS上传的电池组的电池总压\nThis is the total battery pressure of the battery pack uploaded from the BMS via the CAN/485/TCP communication protocol.", "OK");
        break;
    case 1:
        QMessageBox::question(this, "Bat current"\
                              ,"这是通过CAN/485/TCP通讯协议从BMS上传的电池组的总电流\nThis is the total current of the battery pack uploaded from the BMS via the CAN/485/TCP communication protocol.", "OK");
        break;
    case 2:
        QMessageBox::question(this, "SOC"\
                              ,"这是通过CAN/485/TCP通讯协议从BMS上传的电池组SOC，即当前电池剩余电量百分比\nThis is the SOC of the battery pack uploaded from the BMS via the CAN/485/TCP communication protocol, that is, the percentage of the current battery remaining.", "OK");
        break;
    case 3:
        QMessageBox::question(this, "SOH"\
                              ,"这是通过CAN/485/TCP通讯协议从BMS上传的电池组SOH，电池组当前的容量与出厂容量的百分比，即电池的健康度\nThis is the SOH of the battery pack uploaded from the BMS through the CAN/485/TCP communication protocol, the percentage of the current capacity of the battery pack to the factory capacity, that is, the health of the battery.", "OK");
        break;
    case 4:
        QMessageBox::question(this, "Cell voltage(max)"\
                              ,"这是通过CAN/485/TCP通讯协议从BMS上传的单体最高电压,即当前所有电池单体的最高电压\nThis is the maximum voltage of the cell uploaded from the BMS via the CAN/485/TCP communication protocol, that is, the maximum voltage of all cell cells at present.", "OK");
        break;
    case 5:
        QMessageBox::question(this, "Cell voltage(min)"\
                              ,"这是通过CAN/485/TCP通讯协议从BMS上传的单体最低电压,即当前所有电池单体的最低电压\nThis is the lowest voltage of the cell uploaded from the BMS via the CAN/485/TCP communication protocol, that is, the lowest voltage of all battery cells at present.", "OK");
        break;
    case 6:
        QMessageBox::question(this, "Cell temp.(max)"\
                              ,"这是通过CAN/485/TCP通讯协议从BMS上传的单体最高温度,即当前所有电池单体的最高温度\nThis is the highest temperature of the cell uploaded from the BMS via the CAN/485/TCP communication protocol, that is, the highest temperature of all battery cells at present.", "OK");
        break;
    case 7:
        QMessageBox::question(this, "Cell temp.(min)"\
                              ,"这是通过CAN/485/TCP通讯协议从BMS上传的单体最低温度,即当前所有电池单体的最低温度\nThis is the lowest temperature of the cell uploaded from the BMS via the CAN/485/TCP communication protocol, that is, the lowest temperature of all battery cells at present.", "OK");
        break;
    case 8:
        QMessageBox::question(this, "Charging current limite"\
                              ,"这是通过CAN/485/TCP通讯协议从BMS上传的充电电流上限，当前电池组所允许通过的最大充电电流(注: 充电末端时，PCS会根据实际电流来进行限流)\nThis is the upper limit of the charging current uploaded from the BMS via the CAN/485/TCP communication protocol, the maximum charging current allowed by the current battery pack (Note: when charging the end, PCS will limit the current according to the actual current).", "OK");
        break;
    case 9:
        QMessageBox::question(this, "Discharging current limite"\
                              ,"这是通过CAN/485/TCP通讯协议从BMS上传的放电电流上限，当前电池组所允许通过的最大放电电流\nThis is the upper limit of the discharge current uploaded from the BMS via the CAN/485/TCP communication protocol, the maximum discharge current allowed by the current battery pack.", "OK");
        break;
    case 10:
        QMessageBox::question(this, "Allow charge power"\
                              ,"这是通过CAN/485/TCP通讯协议从BMS上传的可充电功率，电池的充电功率不可超过这个限制数值\nThis is the rechargeable power uploaded from the BMS through the CAN/485 communication protocol. The charging power of the battery cannot exceed this limit value.", "OK");
        break;
    case 11:
        QMessageBox::question(this, "Allow discharge power"\
                              ,"这是通过CAN/485/TCP通讯协议从BMS上传的可放电功率，电池的放电功率不可超过这个限制数值\nThis is the discharge power uploaded from the BMS using the CAN/485 communication protocol. The discharge power of the battery cannot exceed this limit.", "OK");
        break;
    case 12:
        QMessageBox::question(this, "Allow charge energy"\
                              ,"这是通过CAN/485/TCP通讯协议从BMS上传的允许充电量，当前电池组允许充电的容量(注: 仅部分BMS会提供这个值)\nThis is the allowable charge amount uploaded from the BMS via the CAN/485/TCP communication protocol, the capacity of the current battery pack allowed to charge (Note: only some BMS will provide this value).", "OK");
        break;
    case 13:
        QMessageBox::question(this, "Allow discharge energy"\
                              ,"这是通过CAN/485/TCP通讯协议从BMS上传的允许放电量，当前电池组允许放电的容量(注: 仅部分BMS会提供这个值)\nThis is the allowable discharge from the BMS via the CAN/485/TCP communication protocol, the current capacity of the battery pack allowed to discharge (Note: only some BMS will provide this value).", "OK");
        break;
    case 14:
        QMessageBox::question(this, "Alarm level"\
                              ,"这是告警等级图示，根据BMS上传的告警等级改变颜色，此处可以通过颜色判断告警等级，正常为绿色、一级告警为黄色、二级告警为橙色、三级告警为红色；如果是一级告警或者二级告警，PCS不做响应；如果是三级告警，PCS关机\nThis is the alarm level icon. The color is changed according to the alarm level uploaded by the BMS. The alarm level is green for normal alarms, yellow for primary alarms, orange for secondary alarms, and red for tertiary alarms.If the alarm is Level 1 or Level 2, PCS does not respond.If the alarm is Level 3, the PCS shuts down.", "OK");
        break;
    case 15:
        QMessageBox::question(this, "Charge enable"\
                              ,"这是充电使能，由BMS通过CAN/485/TCP通讯协议上传的当前电池的状态；使能表示目前电池允许充电，禁止表示目前电池不允许充电\nThis is the current battery status uploaded by BMS via CAN/485/TCP. Enable indicates that the battery can be charged. Disable indicates that the battery cannot be charged.", "OK");
        break;
    case 16:
        QMessageBox::question(this, "Discharge enable"\
                              ,"这是放电使能，由BMS通过CAN/485/TCP通讯协议上传的当前电池的状态；使能表示目前电池允许放电，禁止表示目前电池不允许放电\nThis is the current state of the battery uploaded by the BMS via the CAN/485/TCP protocol. Enable indicates that the battery can be discharged. Disable indicates that the battery cannot be discharged.", "OK");
        break;
    default:
        break;
    }
}
/*********PCS数据 绘制button**********/
void MEGAWin::PCS_Data()
{
    PCS_vol_AB = new Specification(this,PCS_vol_AB_explain, ui->Converter_Tab, 0, 1, \
                                            tr("270.2V"), tr("PCS voltage(AB)"), \
                                            tr("The inverter side voltage of the current PCS is the phase voltage between phase A and phase B."));
    PCS_vol_AB->add_Specification();
    PCS_vol_BC = new Specification(this,PCS_vol_BC_explain, ui->Converter_Tab, 1, 1, \
                                            tr("270V"), tr("PCS voltage(BC)"), \
                                            tr("The inverter side voltage of the current PCS is the phase voltage between phase B and phase C."));
    PCS_vol_BC->add_Specification();
    PCS_vol_CA = new Specification(this,PCS_vol_CA_explain, ui->Converter_Tab, 2, 1, \
                                            tr("270.1V"), tr("PCS voltage(CA)"), \
                                            tr("The inverter side voltage of the current PCS is the phase voltage between phase A and phase C."));
    PCS_vol_CA->add_Specification();
    PCS_cur_A = new Specification(this,PCS_cur_A_explain, ui->Converter_Tab, 3, 1, \
                                            tr("0A"), tr("PCS current(A)"), \
                                            tr("The current of the inverter side of the current PCS is the current of phase A."));
    PCS_cur_A->add_Specification();
    PCS_cur_B = new Specification(this,PCS_cur_B_explain, ui->Converter_Tab, 4, 1, \
                                            tr("0A"), tr("PCS current(B)"), \
                                            tr("The current of the inverter side of the current PCS is the current of phase B."));
    PCS_cur_B->add_Specification();
    PCS_cur_C = new Specification(this,PCS_cur_C_explain, ui->Converter_Tab, 5, 1, \
                                            tr("0A"), tr("PCS current(C)"), \
                                            tr("The current of the inverter side of the current PCS is the current of phase C."));
    PCS_cur_C->add_Specification();
    PCS_act_P = new Specification(this,PCS_act_P_explain, ui->Converter_Tab, 6, 1, \
                                            tr("0kW"), tr("PCS Active Power"), \
                                            tr("The active power P of the inverter side of the current PCS."));
    PCS_act_P->add_Specification();
    PCS_rea_P = new Specification(this,PCS_rea_P_explain, ui->Converter_Tab, 7, 1, \
                                            tr("0kVar"), tr("PCS Reactive Power"), \
                                            tr("The reactive power Q of the inverter side of the current PCS."));
    PCS_rea_P->add_Specification();
    PCS_par_P = new Specification(this,PCS_par_P_explain, ui->Converter_Tab, 8, 1, \
                                            tr("0kVA"), tr("PCS Parent Power"), \
                                            tr("The inverter side view of the current PCS is at power S, S= √((P^2+Q^2))."));
    PCS_par_P->add_Specification();

    PCS_Pf = new Specification(this,PCS_Pf_explain, ui->Converter_Tab, 9, 1, \
                                            tr("0"), tr("PCS Power factor"), \
                                            tr("Power factor Pf on the inverter side of current PCS, Pf = P/S."));
    PCS_Pf->add_Specification();
    PCS_Bat_vol = new Specification(this,PCS_Bat_vol_explain, ui->Converter_Tab, 0, 3, \
                                            tr("0V"), tr("PCS Battery voltage"), \
                                            tr("The current PCS samples the battery voltage from the connected battery."));
    PCS_Bat_vol->add_Specification();
    PCS_Bat_cur = new Specification(this,PCS_Bat_cur_explain, ui->Converter_Tab, 1, 3, \
                                            tr("0A"), tr("PCS Battery current"), \
                                            tr("Battery current sampled by the PCS from the connected battery."));
    PCS_Bat_cur->add_Specification();
    PCS_Bat_P = new Specification(this,PCS_Bat_P_explain, ui->Converter_Tab, 2, 3, \
                                            tr("0kW"), tr("PCS Battery power"), \
                                            tr("At present, PCS calculates the product of battery voltage and battery current to obtain battery power."));
    PCS_Bat_P->add_Specification();
    PCS_Bus_vol = new Specification(this,PCS_Bus_vol_explain, ui->Converter_Tab, 3, 3, \
                                            tr("0V"), tr("PCS Bus voltage"), \
                                            tr("The current bus voltage sampled by PCS from the bus side."));
    PCS_Bus_vol->add_Specification();
    PCS_IGBT_T = new Specification(this,PCS_IGBT_T_explain, ui->Converter_Tab, 4, 3, \
                                            tr("39℃"), tr("PCS IGBT temperature"), \
                                            tr("The current IGBT temperature of PCS shall not exceed 105℃, otherwise PCS will run derated."));
    PCS_IGBT_T->add_Specification();
    PCS_Env_T = new Specification(this,PCS_Env_T_explain, ui->Converter_Tab, 5, 3, \
                                            tr("25℃"), tr("PCS Environment temperature"), \
                                            tr("The ambient temperature of the current PCS."));
    PCS_Env_T->add_Specification();
}
/*********电网数据 绘制button**********/
void MEGAWin::Grid_Data()
{
    Grid_vol_AB = new Specification(this,Grid_vol_AB_explain, ui->Grid_Tab, 0, 1, \
                                            tr("0V"), tr("Grid voltage(AB)"), \
                                            tr("The grid side voltage of the current PCS, this item is the phase voltage between phase A and phase B."));
    Grid_vol_AB->add_Specification();
    Grid_vol_BC = new Specification(this,Grid_vol_BC_explain, ui->Grid_Tab, 1, 1, \
                                            tr("0V"), tr("Grid voltage(BC)"), \
                                            tr("The grid side voltage of the current PCS, this item is the phase voltage between phase B and phase C."));
    Grid_vol_BC->add_Specification();
    Grid_vol_CA = new Specification(this,Grid_vol_CA_explain, ui->Grid_Tab, 2, 1, \
                                            tr("0V"), tr("Grid voltage(CA)"), \
                                            tr("The grid side voltage of the current PCS, this item is the phase voltage between phase A and phase C."));
    Grid_vol_CA->add_Specification();
    Grid_cur_A = new Specification(this,Grid_cur_A_explain, ui->Grid_Tab, 3, 1, \
                                            tr("0A"), tr("Grid current(A)"), \
                                            tr("The current on the grid side of PCS, this item is the current of phase A."));
    Grid_cur_A->add_Specification();
    Grid_cur_B = new Specification(this,Grid_cur_B_explain, ui->Grid_Tab, 4, 1, \
                                            tr("0A"), tr("Grid current(B)"), \
                                            tr("The current on the grid side of PCS, this item is the current of phase B."));
    Grid_cur_B->add_Specification();
    Grid_cur_C = new Specification(this,Grid_cur_C_explain, ui->Grid_Tab, 5, 1, \
                                            tr("0A"), tr("Grid current(C)"), \
                                            tr("The current on the grid side of PCS, this item is the current of phase C."));
    Grid_cur_C->add_Specification();
    Grid_act_P = new Specification(this,Grid_act_P_explain, ui->Grid_Tab, 6, 1, \
                                            tr("0kW"), tr("Grid active power"), \
                                            tr("Current active power (P) on the grid side of PCS."));
    Grid_act_P->add_Specification();
    Grid_rea_P = new Specification(this,Grid_rea_P_explain, ui->Grid_Tab, 7, 1, \
                                            tr("0kVar"), tr("Grid reactive power"), \
                                            tr("Current reactive power (Q) on the grid side of PCS."));
    Grid_rea_P->add_Specification();
    Grid_app_P = new Specification(this,Grid_app_P_explain, ui->Grid_Tab, 8, 1, \
                                            tr("0kVA"), tr("Grid apparent power"), \
                                            tr("Current PCS grid side view power (S), S= √((P^2+Q^2))."));
    Grid_app_P->add_Specification();
    Grid_fre = new Specification(this,Grid_fre_explain, ui->Grid_Tab, 9, 1, \
                                            tr("0Hz"), tr("Grid frequency"), \
                                            tr("Current PCS collection of power grid frequency."));
    Grid_fre->add_Specification();
    Grid_Pf = new Specification(this,Grid_Pf_explain, ui->Grid_Tab, 10, 1, \
                                            tr("0"), tr("Grid power factor"), \
                                            tr("Grid side power factor (Pf) of the current PCS, Pf = P/S."));
    Grid_Pf->add_Specification();
}
/*********负载数据 绘制button**********/
void MEGAWin::Load_Data()
{
    Load_vol_AB = new Specification(this,Load_vol_AB_explain, ui->Load_Tab, 0, 1, \
                                            tr("0V"), tr("Load voltage(AB)"), \
                                            tr("The load side voltage of the current PCS, this item is the phase voltage between phase A and phase B."));
    Load_vol_AB->add_Specification();
    Load_vol_BC = new Specification(this,Load_vol_BC_explain, ui->Load_Tab, 1, 1, \
                                            tr("0V"), tr("Load voltage(BC)"), \
                                            tr("The load side voltage of the current PCS, this item is the phase voltage between phase B and phase C."));
    Load_vol_BC->add_Specification();
    Load_vol_CA = new Specification(this,Load_vol_CA_explain, ui->Load_Tab, 2, 1, \
                                            tr("0V"), tr("Load voltage(CA)"), \
                                            tr("The load side voltage of the current PCS, this item is the phase voltage between phase A and phase C."));
    Load_vol_CA->add_Specification();
    Load_cur_A = new Specification(this,Load_cur_A_explain, ui->Load_Tab, 3, 1, \
                                            tr("0A"), tr("Load current(A)"), \
                                            tr("The current on the load side of PCS is the current of phase A."));
    Load_cur_A->add_Specification();
    Load_cur_B = new Specification(this,Load_cur_B_explain, ui->Load_Tab, 4, 1, \
                                            tr("0A"), tr("Load current(B)"), \
                                            tr("The current at the load side of PCS is the current of phase B."));
    Load_cur_B->add_Specification();
    Load_cur_C = new Specification(this,Load_cur_C_explain, ui->Load_Tab, 5, 1, \
                                            tr("0A"), tr("Load current(C)"), \
                                            tr("The current at the load side of PCS is the current of phase C."));
    Load_cur_C->add_Specification();
    Load_act_P = new Specification(this,Load_act_P_explain, ui->Load_Tab, 6, 1, \
                                            tr("0kW"), tr("Load active power"), \
                                            tr("Current PCS active power (P) on load side."));
    Load_act_P->add_Specification();
    Load_rea_P = new Specification(this,Load_rea_P_explain, ui->Load_Tab, 7, 1, \
                                            tr("0kVar"), tr("Load reactive power"), \
                                            tr("Reactive power (Q) on the load side of current PCS."));
    Load_rea_P->add_Specification();
    Load_app_P = new Specification(this,Load_app_P_explain, ui->Load_Tab, 8, 1, \
                                            tr("0kVA"), tr("Load apparent power"), \
                                            tr("Current PCS load side view at power (S), S= √((P^2+Q^2))."));
    Load_app_P->add_Specification();
    Load_Pf = new Specification(this,Load_Pf_explain, ui->Load_Tab, 9, 1, \
                                            tr("0"), tr("Load power factor"), \
                                            tr("The load side power factor (Pf) of the current PCS, Pf = P/S."));
    Load_Pf->add_Specification();
}
/********PCS状态 绘制button*********/
void MEGAWin::PCS_State()
{
    DC_input_Breaker = new Specification(this,DC_input_Breaker_explain, ui->RTState_Bypass_Tab, 0, 1, \
                                            tr("Close"), tr("DC input Breaker"), \
                                            tr("DC input circuit breaker has three states: Break, Close, Trip; The DC input circuit breaker can only be manually disconnected. If the DC input circuit breaker overcurrent, the DC input circuit breaker may trip."));
    DC_input_Breaker->add_Specification();
    DC_Cont = new Specification(this,DC_Cont_explain, ui->RTState_Bypass_Tab, 1, 1, \
                                            tr("Close"), tr("DC contactor"), \
                                            tr("DC contactor has two states: Break, Close; When the DC side is soft Break, the DC contactor is closed. When the DC side of the battery is disconnected, the DC bus voltage drops to a certain voltage, and the DC contactor is disconnected."));
    DC_Cont->add_Specification();
    Output_Cont = new Specification(this,Output_Cont_explain, ui->RTState_Bypass_Tab, 2, 1, \
                                            tr("Close"), tr("Output contactor"), \
                                            tr("The output circuit breaker has three states: Break, Close, Trip; If the output circuit breaker overcurrent, the output circuit breaker will trip."));
    Output_Cont->add_Specification();
    Output_Breaker = new Specification(this,Output_Breaker_explain, ui->RTState_Bypass_Tab, 3, 1, \
                                            tr("Close"), tr("Output Breaker"), \
                                            tr("The output contactor has two states: Break, Close; When the DC side soft opening is completed, the output contactor is closed; When the converter is turned off, the output contactor is disconnected."));
    Output_Breaker->add_Specification();
    Grid_Cont = new Specification(this,Grid_Cont_explain, ui->RTState_Bypass_Tab, 4, 1, \
                                            tr("Close"), tr("Grid contactor"), \
                                            tr("The network contactor has two states: Break, Close; When the converter is in grid-connected mode and the grid side voltage is normal, the network contactor is closed. The converter is in off-grid mode and the network contactor is disconnected."));
    Grid_Cont->add_Specification();
    Grid_Breaker = new Specification(this,Grid_Breaker_explain, ui->RTState_Bypass_Tab, 5, 1, \
                                            tr("Close"), tr("Grid Breaker"), \
                                            tr("The power grid circuit breaker has three states: Break, Close, Trip; The power grid circuit breaker can only be manually disconnected. If the power grid circuit breaker overflows, the power grid circuit breaker may trip."));
    Grid_Breaker->add_Specification();
    MB_Breaker = new Specification(this,MB_Breaker_explain, ui->RTState_Bypass_Tab, 6, 1, \
                                            tr("Close"), tr("Maintenance Bypass Breaker"), \
                                            tr("Maintenance bypass circuit breaker has two states: Break, Close; This circuit breaker is only used for machine maintenance, if necessary, please contact the maintenance personnel."));
    MB_Breaker->add_Specification();
    converter_available = new Specification(this,converter_available_explain, ui->RTState_Bypass_Tab, 0, 3, \
                                            tr("Disable"), tr("converter available"), \
                                            tr("The converter can be enabled in two states: Enable and Disable. When the internal self-test of the machine is no problem, the converter is enabled; Otherwise the converter is prohibited."));
    converter_available->add_Specification();
    DC_Soft_start = new Specification(this,DC_Soft_start_explain, ui->RTState_Bypass_Tab, 1, 3, \
                                            tr("Not starting"), tr("DC Soft start"), \
                                            tr("The DC Soft boot has three states: Soft starting, complete, and Not starting. Soft start means that when the converter is started, it gradually accelerates or decelerates the device to the normal operating state by controlling the change of current or voltage, so as to reduce the current shock and voltage peak in the circuit, protect the circuit components and reduce the mechanical damage of the device. Soft start can increase device life, reduce energy consumption, and improve system efficiency."));
    DC_Soft_start->add_Specification();
    converter_status = new Specification(this,converter_status_explain, ui->RTState_Bypass_Tab, 2, 3, \
                                            tr("Shut down"), tr("converter status"), \
                                            tr("There are eight converter states:Shut down, Soft start, Grid-ON Charge, Grid-ON Discharge, Grid-OFF Discharge, Drop and Connected,Standby, Grid-OFF Charge."));
    converter_status->add_Specification();
    Reactive_P_Regulation = new Specification(this,Reactive_P_Regulation_explain, ui->RTState_Bypass_Tab, 3, 3, \
                                            tr("Disable"), tr("Reactive Power Regulation"), \
                                            tr("There are three types of reactive power regulation: Disable, Pf regulation, and Q regulation."));
    Reactive_P_Regulation->add_Specification();
    LVRT = new Specification(this,LVRT_explain, ui->RTState_Bypass_Tab, 4, 3, \
                                            tr("LVRT"), tr("LVRT"), \
                                            tr("This is the current state of low voltage crossing (LVRT). Low voltage crossing refers to the ability to withstand a certain limit of low voltage of the grid within a certain period of time without exiting the operation. There are two states here, namely Non and LVRT."));
    LVRT->add_Specification();
    Generator_signal = new Specification(this,Generator_signal_explain, ui->RTState_Bypass_Tab, 0, 5, \
                                            tr("Enable"), tr("Generator signal"), \
                                            tr("This is the status of the current chai signal, output dry contact 1, there are Enable and Disable two states, here is the most real physical hardware status."));
    Generator_signal->add_Specification();
    Reserve = new Specification(this,Reserve_explain, ui->RTState_Bypass_Tab, 1, 5, \
                                            tr("Disable"), tr("Reserve"), \
                                            tr("This bit is reserved and has no effect. Dry contact 2 is output. The status of dry contact 2 is Enable(Enable) or Disable(Disable)."));
    Reserve->add_Specification();
    Reserve2 = new Specification(this,Reserve2_explain, ui->RTState_Bypass_Tab, 2, 5, \
                                            tr("Disable"), tr("Reserve2"), \
                                            tr("This bit is reserved and has no effect. Dry contact 2 is output. The status of dry contact 3 is Enable(Enable) or Disable(Disable)"));
    Reserve2->add_Specification();
    EPO_Cont_signal1 = new Specification(this,EPO_Cont_signal1_explain, ui->RTState_Bypass_Tab, 3, 5, \
                                            tr("Disable"), tr("EPO_Cont signal1"), \
                                            tr("This is signal 1 of the EPO node. Enter dry contact 1, that is, dry contact signal 1 of external shutdown. There are two states: Enable and Disable."));
    EPO_Cont_signal1->add_Specification();
    EPO_Cont_signal2 = new Specification(this,EPO_Cont_signal2_explain, ui->RTState_Bypass_Tab, 4, 5, \
                                            tr("Disable"), tr("EPO_Cont signal2"), \
                                            tr("This is signal 2 of the EPO node. Enter dry contact 2, that is, dry contact signal 2 of the external shutdown. There are two states: Enable and Disable."));
    EPO_Cont_signal2->add_Specification();
    Access_signal = new Specification(this,Access_signal_explain, ui->RTState_Bypass_Tab, 5, 5, \
                                            tr("Disable"), tr("Access_signal"), \
                                            tr("This is the access signal. Enter dry contact 3. The status is Enable or Disable. The actual physical hardware status is obtained here."));
    Access_signal->add_Specification();
    Full_P_signal = new Specification(this,Full_P_signal_explain, ui->RTState_Bypass_Tab, 6, 5, \
                                            tr("Disable"), tr("Full_P_signal"), \
                                            tr("This is a full power signal, the input dry contact 4 has two states of Enable and Disable, and what is obtained here is the most real physical hardware state."));
    Full_P_signal->add_Specification();
    Smoke_alarm_signal = new Specification(this,Smoke_alarm_signal_explain, ui->RTState_Bypass_Tab, 7, 5, \
                                            tr("Disable"), tr("Smoke alarm signal"), \
                                            tr("This isa smoke alarm signal. Enter dry contact 5. The status is Enable or Disable. The actual physical hardware status is obtained here."));
    Smoke_alarm_signal->add_Specification();
    Hight_temp_signal = new Specification(this,Hight_temp_signal_explain, ui->RTState_Bypass_Tab, 8, 5, \
                                            tr("Disable"), tr("Hight temp signal"), \
                                            tr("This isa high temperature signal. Input dry contact 6. Two states are available: Enable and Disable."));
    Hight_temp_signal->add_Specification();
}
/*********系统设置 绘制button**********/
void MEGAWin::ParameterSet()
{
    Grid_connected_mode = new Specification(this,Grid_connected_mode_explain, ui->System_Tab, 0, 1, \
                                            "automatic", "Grid connected mode of PCS", \
                                            "这是PCS并网方式，一共有三项可选：自动(automatic)，并网(On)，离网(Off),选择'自动'时将自动识别当前的并网方式\n并网:与相邻电力系统发送电气连接，并进行功率交换(如与电网连接)\n离网：不依赖电网而独立运行(不接电网)\nThis is the PCS grid connection mode, there are three options: automatic(automatic), On(On), Off(Off), select 'automatic' will automatically identify the current grid connection mode \n grid connection: send electrical connection with the adjacent power system, and carry out power exchange (such as connection with the grid)\n off-grid: To operate independently of the grid (not connected to the grid).");
    Grid_connected_mode->add_Specification();

    Constant_power = new Specification(this,Constant_power_explain, ui->System_Tab, 1, 1, \
                                       "0", "Constant power(AC)", \
                                       "这是恒功率，可以通过修改这项数值来设置机器的功率,当控制功率方式选择正负功率(CP_N&P)时,正数表示放电，负数表示充电\nThis is constant power, and the power of the machine can be set by modifying this value. When the power control mode is positive and negative (CP_N&P), the positive number means discharge and the negative number means charge.");
    Constant_power->add_Specification();

    Charging_and_discharging = new Specification(this,Charging_and_discharging_explain, ui->System_Tab, 2, 1, \
                                                 "Charge", "Charging and discharging", \
                                                 "这是充放电，一共有两项可选：充电(Charge)，放电(Discharge)，根据此处选择决定是充电还是放电，当控制功率方式选择恒功率(CP_P)时，此项可调\nThis is Charge and Discharge, and there are two options: charge(Charge) and discharge(Discharge). Charge or discharge can be determined according to the choice here. When the power control mode is Constant power(CP_P), this option can be adjusted.");
    Charging_and_discharging->add_Specification();

    Work_mode = new Specification(this,Work_mode_explain, ui->System_Tab, 3, 1, \
                                  "Manual", "Work mode", \
                                  "这是工作模式，有四项可选：手动(Manual)，UPS(UPS)，削峰填谷(Peak valley)，受控制削峰填谷(Prevent countercurrnet)。\n手动模式时，充放电由自主手动决定。\n削峰填谷模式时，用电高峰时优先使用电池给负载供电，用电低谷时优先给电池充电。\nUPS模式时，将为负载不间断地提供稳定电源。\n受控削峰填谷模式时，对系统防逆流，一般配合电表一起使用。\nThis is the working mode, with four options: Manual(Manual), UPS(UPS), Peak valley(Peak valley), Prevent countercurrnet(Prevent countercurrnet).\nManual mode, charge and discharge are determined manually.\nIn peak valley mode, the battery is preferred to supply power to the load during peak demand. When the power is low, the battery will be charged first.\nUPS mode will provide a stable power supply for the load without interruption.\nIn the controlled peak-load mode(Prevent countercurrnet), the system is anti-countercurrent and generally used with the meter.");
    Work_mode->add_Specification();

    Output_power_factor = new Specification(this,Output_power_factor_explain, ui->System_Tab, 4, 1, \
                                            "1", "Output power factor", \
                                            "这是输出功率因数，是用来衡量电气设备输出效率高低的一个系数，不可调\nThis is the output power factor, which is a coefficient used to measure the output efficiency of electrical equipment and cannot be adjusted.");
    Output_power_factor->add_Specification();

    Output_reactive_power = new Specification(this,Output_reactive_power_explain, ui->System_Tab, 5, 1, \
                                              "1", "Output reactive power", \
                                              "这是输出无功功率，它表达了输出交流电源能量与磁场或电场能量交换的最大速率，不可调\nThis is the output reactive power, which expresses the maximum rate at which the output AC power source energy is exchanged with the magnetic or electric field energy and is not adjustable.");
    Output_reactive_power->add_Specification();

    Constant_current = new Specification(this,Constant_current_explain, ui->System_Tab, 6, 1, \
                                         "100", "Constant current", \
                                         "这是恒流值，当控制功率方式选择恒流(CC)时，此项可调，电流值稳定为此值\nThis is the constant current value, when the control power mode selects constant current (CC), this can be adjusted, the current value is stable for this value.");
    Constant_current->add_Specification();

    Constant_voltage = new Specification(this,Constant_voltage_explain, ui->System_Tab, 7, 1, \
                                         "600", "Constant voltage", \
                                         "这是恒压值，当控制功率方式选择恒压(CV)时，此项可调，电压值稳定为此值\nThis is the constant voltage value, when the control power mode selects constant voltage (CV), this can be adjusted, the voltage value is stable for this value.");
    Constant_voltage->add_Specification();

    Control_mode = new Specification(this,Control_mode_explain, ui->System_Tab, 0, 4, \
                                     "Local", "Control mode", \
                                     "这是工作模式，有两项可选：本地(Local)，远程(Remote)，选择'本地'时，可在本地修改系统参数，选择'远程'时，可通过EMS、485等进行远程修改参数\nThis is the working mode, there are two options: Local (Local), Remote (Remote), select 'local', you can modify the system parameters locally, select 'remote', you can modify the parameters remotely through EMS, 485, etc.");
    Control_mode->add_Specification();

    Machine_number = new Specification(this,Machine_number_explain, ui->System_Tab, 1, 4, \
                                       "Master_00", "Machine number", \
                                       "这是设备号，可以选择主机(Master)或者从机(Slave)，其中主机为Master_00，其余八项Slave_01~Slave_08均为从机\nThis is the device number, and you can choose host(Master) or slave(Slave), where master is Master_00 and Slave_01 to Slave_08 are slaves.");
    Machine_number->add_Specification();

    Parallel = new Specification(this,Parallel_explain, ui->System_Tab, 2, 4, \
                                 "Disable", "Parallel", \
                                 "这是并机模式，有两项可选：使能(Enable)，禁止(Disable)，开启并机时，可将多台设备联合到一起为负载供电\nThis is the parallel mode, with two options: enabled(Enable), disabled(Disable), and when enabled, multiple devices can be combined to power the load.");
    Parallel->add_Specification();

    Unbalance_power_enable = new Specification(this,Unbalance_power_enable_explain, ui->System_Tab, 3, 4, \
                                               "Disable", "Unbalance power enable", \
                                               "这是功率不平衡使能，有两项可选：使能(Enable)，禁止(Disable)，功率不平衡是指三相电流与电压之间的相位差不相等，平均功率不为0导致的功率偏差，使能后将使功率维持平衡\nThis is power imbalance enable, there are two options: enabled(Enable), disabled(Disable), power imbalance refers to the phase difference between the three-phase current and voltage is not equal, the average power is not 0 caused by the power deviation, after enabling will make the power balance.");
    Unbalance_power_enable->add_Specification();

    Phase_A_power = new Specification(this,Phase_A_power_explain, ui->System_Tab, 4, 4, \
                                      "5", "Phase A power", \
                                      "这是A相功率，此处可设置A相的功率\nThis is the power of phase A. The power of phase A can be set here.");
    Phase_A_power->add_Specification();

    Phase_B_power = new Specification(this,Phase_B_power_explain, ui->System_Tab, 5, 4, \
                                      "5", "Phase B power", \
                                      "这是B相功率，此处可设置B相的功率\nThis is the power of phase B. The power of phase B can be set here.");
    Phase_B_power->add_Specification();

    Phase_C_power = new Specification(this,Phase_C_power_explain, ui->System_Tab, 6, 4, \
                                      "5", "Phase C power", \
                                      "这是C相功率，此处可设置C相的功率\nThis is the power of phase C. The power of phase C can be set here.");
    Phase_C_power->add_Specification();

}
/***********电池设置 绘制button************/
void MEGAWin::BetterySetup()
{
    DOD_OnGrid = new Specification(this,DOD_OnGrid_explain, ui->Lithum_Tab, 0, 1, \
                                     "90", "DOD_OnGrid", \
                                     "并网工况下电池的放电深度，默认90\nThe default discharge depth of the battery in grid-connected condition is 90.");
    DOD_OnGrid->add_Specification();
    DOD_OffGrid = new Specification(this,DOD_OffGrid_explain, ui->Lithum_Tab, 1, 1, \
                                     "90", "DOD_OffGrid", \
                                     "离网工况下电池的放电深度，默认90\nThe default discharge depth of the battery in off-grid mode is 90.");
    DOD_OffGrid->add_Specification();
    Charge_Vol_Up_Limit = new Specification(this,Charge_Vol_Up_Limit_explain, ui->Lithum_Tab, 2, 1, \
                                     "792", "Charge_Vol_Up_Limit", \
                                     "充电时电池电压所允许达到的最大值\nThe maximum allowable battery voltage during charging.");
    Charge_Vol_Up_Limit->add_Specification();
    Disc_Vol_lower_Limit = new Specification(this,Disc_Vol_lower_Limit_explain, ui->Lithum_Tab, 3, 1, \
                                     "616", "Disc_Vol_lower_Limit", \
                                     "放电时电池电压所允许的最小值\nThe minimum allowable battery voltage when discharging.");
    Disc_Vol_lower_Limit->add_Specification();
    Charge_Cur_Limit = new Specification(this,Charge_Cur_Limit_explain, ui->Lithum_Tab, 4, 1, \
                                     "160", "Charge_Cur_Limit", \
                                     "允许的最大充电电流\nThe maximum allowable charging current.");
    Charge_Cur_Limit->add_Specification();
    Gen_turn_off_SOC = new Specification(this,Gen_turn_off_SOC_explain, ui->Lithum_Tab, 5, 1, \
                                     "85", "Gen_turn_off_SOC", \
                                     "达到指定SCO值时，柴油发电机关闭\nWhen the specified SCO value is reached, the diesel generator shuts down.");
    Gen_turn_off_SOC->add_Specification();
    Gen_turn_on_SOC = new Specification(this,Gen_turn_on_SOC_explain, ui->Lithum_Tab, 6, 1, \
                                     "25", "Gen_turn_on_SOC", \
                                     "达到指定SOC值时，柴油发电机开启\nWhen the specified SOC value is reached, the diesel generator starts.");
    Gen_turn_on_SOC->add_Specification();
    Gen_charge_SOC = new Specification(this,Gen_charge_SOC_explain, ui->Lithum_Tab, 7, 1, \
                                     "10", "Gen_charge_SOC", \
                                     "达到指定SOC值时，柴油发电机开始充电\nWhen the specified SOC value is reached, the diesel generator starts charging.");
    Gen_charge_SOC->add_Specification();
    Grid_charge_SOC = new Specification(this,Grid_charge_SOC_explain, ui->Lithum_Tab, 8, 1, \
                                     "15", "Grid_charge_SOC", \
                                     "到达指定SOC值时，开始电网充电\nWhen the specified SOC value is reached, grid charging begins.");
    Grid_charge_SOC->add_Specification();
    Grid_capacity = new Specification(this,Grid_capacity_explain, ui->Lithum_Tab, 9, 1, \
                                     "150", "Grid_capacity", \
                                     "电网容量，电网允许带的总负荷\nThe capacity of the grid, the total load allowed on the grid.");
    Grid_capacity->add_Specification();
    Turn_on_SOC = new Specification(this,Turn_on_SOC_explain, ui->Lithum_Tab, 0, 4, \
                                     "20", "Turn_on_SOC", \
                                     "当电池剩余电量百分比达到此值时开始充电\nCharging begins when the percentage of remaining battery capacity reaches this value.");
    Turn_on_SOC->add_Specification();
    Turn_off_SOC = new Specification(this,Turn_off_SOC_explain, ui->Lithum_Tab, 1, 4, \
                                     "50", "Turn_off_SOC", \
                                     "当电池剩余电量百分比达到此值时停止充电\nStop charging when the percentage of remaining battery power reaches this value.");
    Turn_off_SOC->add_Specification();
    Turn_on_cell_vol = new Specification(this,Turn_on_cell_vol_explain, ui->Lithum_Tab, 2, 4, \
                                     "3100", "Turn_on_cell_vol", \
                                     "所有单体中的最高电压达到此值时开始充电\nCharge begins when the highest voltage in all cells reaches this value.");
    Turn_on_cell_vol->add_Specification();
    Turn_off_cell_vol = new Specification(this,Turn_off_cell_vol_explain, ui->Lithum_Tab, 3, 4, \
                                     "3500", "Turn_off_cell_vol", \
                                     "所有单体中的最高电压达到此值时停止充电\nThe highest voltage in all cells stops charging when it reaches this value.");
    Turn_off_cell_vol->add_Specification();
    Turn_on_total_vol = new Specification(this,Turn_on_total_vol_explain, ui->Lithum_Tab, 4, 4, \
                                     "400", "Turn_on_total_vol", \
                                     "当电池电压达到此值时开始充电\nCharge begins when the battery voltage reaches this value.");
    Turn_on_total_vol->add_Specification();
    Turn_off_total_vol = new Specification(this,Turn_off_total_vol_explain, ui->Lithum_Tab, 5, 4, \
                                     "650", "Turn_off_total_vol", \
                                     "当电池电压达到此值时停止充电\nStop charging when the battery voltage reaches this value.");
    Turn_off_total_vol->add_Specification();
    UPS_charge_power = new Specification(this,UPS_charge_power_explain, ui->Lithum_Tab, 6, 4, \
                                     "-1", "UPS_charge_power", \
                                     "工作模式为后备模式时的充电功率\nThe charging power when the working mode is backup mode.");
    UPS_charge_power->add_Specification();
    Monthly_cycle_time = new Specification(this,Monthly_cycle_time_explain, ui->Lithum_Tab, 7, 4, \
                                     "0", "Monthly_cycle_time", \
                                     "当每月到达这一天都会进行一次充放电循环\nA charge-discharge cycle is performed once a month on that date.");
    Monthly_cycle_time->add_Specification();
}
/************自动运行 绘制button*************/
void MEGAWin::AutoOperation()
{
    Specification * temp[]  ={Check1,Check2,Check3,Check4,Check5,Check6,Check7,Check8,Check9,Check10,\
                           Check11,Check12,Check13,Check14,Check15,Check16,Check17,Check18,Check19,Check20};

    QPushButton * temp2[] ={Check1_explain,Check2_explain,Check3_explain,Check4_explain,Check5_explain,\
                           Check6_explain,Check7_explain,Check8_explain,Check9_explain,Check10_explain,\
                           Check11_explain,Check12_explain,Check13_explain,Check14_explain,Check15_explain,\
                           Check16_explain,Check17_explain,Check18_explain,Check19_explain,Check20_explain};

    Specification * temp4[]  ={Start_T1,Start_T2,Start_T3,Start_T4,Start_T5,Start_T6,Start_T7,Start_T8,Start_T9,Start_T10,\
                           Start_T11,Start_T12,Start_T13,Start_T14,Start_T15,Start_T16,Start_T17,Start_T18,Start_T19,Start_T20};

    QPushButton * temp5[] ={Start_T1_explain,Start_T2_explain,Start_T3_explain,Start_T4_explain,Start_T5_explain,\
                           Start_T6_explain,Start_T7_explain,Start_T8_explain,Start_T9_explain,Start_T10_explain,\
                           Start_T11_explain,Start_T12_explain,Start_T13_explain,Start_T14_explain,Start_T15_explain,\
                           Start_T16_explain,Start_T17_explain,Start_T18_explain,Start_T19_explain,Start_T20_explain};

    Specification * temp7[]  ={End_T1,End_T2,End_T3,End_T4,End_T5,End_T6,End_T7,End_T8,End_T9,End_T10,\
                           End_T11,End_T12,End_T13,End_T14,End_T15,End_T16,End_T17,End_T18,End_T19,End_T20};

    QPushButton * temp8[] ={End_T1_explain,End_T2_explain,End_T3_explain,End_T4_explain,End_T5_explain,\
                           End_T6_explain,End_T7_explain,End_T8_explain,End_T9_explain,End_T10_explain,\
                           End_T11_explain,End_T12_explain,End_T13_explain,End_T14_explain,End_T15_explain,\
                           End_T16_explain,End_T17_explain,End_T18_explain,End_T19_explain,End_T20_explain};

    Specification * temp10[]  ={State1,State2,State3,State4,State5,State6,State7,State8,State9,State10,\
                           State11,State12,State13,State14,State15,State16,State17,State18,State19,State20};

    QPushButton * temp11[] ={State1_explain,State2_explain,State3_explain,State4_explain,State5_explain,\
                           State6_explain,State7_explain,State8_explain,State9_explain,State10_explain,\
                           State11_explain,State12_explain,State13_explain,State14_explain,State15_explain,\
                           State16_explain,State17_explain,State18_explain,State19_explain,State20_explain};

    Specification * temp13[]  ={Power1,Power2,Power3,Power4,Power5,Power6,Power7,Power8,Power9,Power10,\
                           Power11,Power12,Power13,Power14,Power15,Power16,Power17,Power18,Power19,Power20};

    QPushButton * temp14[] ={Power1_explain,Power2_explain,Power3_explain,Power4_explain,Power5_explain,\
                           Power6_explain,Power7_explain,Power8_explain,Power9_explain,Power10_explain,\
                           Power11_explain,Power12_explain,Power13_explain,Power14_explain,Power15_explain,\
                           Power16_explain,Power17_explain,Power18_explain,Power19_explain,Power20_explain};

    for(int i=0;i<20;i++)
    {
        QString temp3 = QString("Check%1").arg(i+1);
        QString temp6 = QString("Start_T%1").arg(i+1);
        QString temp9 = QString("End_T%1").arg(i+1);
        QString temp12 = QString("State%1").arg(i+1);
        QString temp15 = QString("Power%1").arg(i+1);

        QString temp16 = QString("%1:00").arg(i+8);
        QString temp17 = QString("%1:00").arg(i+9);

        if(i<5)
            temp[i] = new Specification(this,temp2[i], ui->Time_tableWidget, i, 0, \
                                                "√", temp3, \
                                                "这是'使能'，选择后将在指定的时间以指定的功率开启指定的状态，并在指定的时间结束\nThis is' Enable ', which will enable the specified state at the specified time with the specified power, and end at the specified time.");
        else
            temp[i] = new Specification(this,temp2[i], ui->Time_tableWidget, i, 0, \
                                                "", temp3, \
                                                "这是'使能'，选择后将在指定的时间以指定的功率开启指定的状态，并在指定的时间结束\nThis is' Enable ', which will enable the specified state at the specified time with the specified power, and end at the specified time.");
        temp[i]->add_Specification();
        temp4[i] = new Specification(this,temp5[i], ui->Time_tableWidget, i, 1, \
                                                temp16, temp6, \
                                                "这是开始时间，将在此时间开始以指定的功率进入指定的状态\nThis is the start time at which the specified state will begin to be entered with the specified power.");
        temp4[i]->add_Specification();
        temp7[i] = new Specification(this,temp8[i], ui->Time_tableWidget, i, 2, \
                                                temp17, temp9, \
                                                "这是结束时间，将在此时间结束由'开始时间'开始的状态\nThis is the end time at which the state started with the 'start time' will end.");
        temp7[i]->add_Specification();

        if(i%2==0)
        {
            temp10[i] = new Specification(this,temp11[i], ui->Time_tableWidget, i, 3, \
                                                    "charge", temp12, \
                                                    "这是状态，将在工作时间执行此状态，有三种可供选择，分别为充电(charge)、放电(discharge)、自动(Automatic)\nThis is the state, which will be executed during working hours.  There are three options: charge（charge）, discharge（discharge）, and Automatic（Automatic）.");
            temp13[i] = new Specification(this,temp14[i], ui->Time_tableWidget, i, 4, \
                                                    "-100", temp15, \
                                                    "这是工作功率，此状态下工作时根据工作状态执行此功率，正数为放电，负数为充电\nThis is the working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging.");
        }
        else
        {
            temp10[i] = new Specification(this,temp11[i], ui->Time_tableWidget, i, 3, \
                                                    "discharge", temp12, \
                                                    "这是状态，将在工作时间执行此状态，有三种可供选择，分别为充电(charge)、放电(discharge)、自动(Automatic)\nThis is the state, which will be executed during working hours.  There are three options: charge（charge）, discharge（discharge）, and Automatic（Automatic）.");
            temp13[i] = new Specification(this,temp14[i], ui->Time_tableWidget, i, 4, \
                                                    "100", temp15, \
                                                    "这是工作功率，此状态下工作时根据工作状态执行此功率，正数为放电，负数为充电\nThis is the working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging.");
        }
        temp10[i]->add_Specification();
        temp13[i]->add_Specification();
    }

}
/*********系统信息 绘制button**********/
void MEGAWin::SystemMessages()
{
    Manufacturer_name = new Specification(this,Manufacturer_name_explain, ui->EquipmentInfor_tableWidget, 0, 1, \
                                     "PCS", "Manufacturer name", \
                                     "这是厂家名称\nThis is the name of the manufacturer.");
    Manufacturer_name->add_Specification();
    MonitoringVersion = new Specification(this,MonitoringVersion_explain, ui->EquipmentInfor_tableWidget, 1, 1, \
                                     "V103B500D004", "Monitoring software version", \
                                     "这是监控版本\nThis is the name of the manufacturer.");
    MonitoringVersion->add_Specification();
    SysProtocol_Version = new Specification(this,SysProtocol_Version_explain, ui->EquipmentInfor_tableWidget, 2, 1, \
                                     "V001B001D001", "Manufacturer name", \
                                     "这是协议版本号\nThis is the name of the manufacturer.");
    SysProtocol_Version->add_Specification();
    ConverterVersion = new Specification(this,ConverterVersion_explain, ui->EquipmentInfor_tableWidget, 3, 1, \
                                     "V105B500D008", "Manufacturer name", \
                                     "这是变流器软件版本\nThis is the name of the manufacturer.");
    ConverterVersion->add_Specification();
    CPLD_Version = new Specification(this,CPLD_Version_explain, ui->EquipmentInfor_tableWidget, 4, 1, \
                                     "V001B001D000", "Manufacturer name", \
                                     "这是CPLD软件版本\nThis is the name of the manufacturer.");
    CPLD_Version->add_Specification();
    SN = new Specification(this,SN_explain, ui->EquipmentInfor_tableWidget, 5, 1, \
                                     "F12200000001", "Manufacturer name", \
                                     "这是SN,即产品序列号\nThis is the name of the manufacturer.");
    SN->add_Specification();
}
/***********功能设置 绘制button************/
void MEGAWin::FunctionSet()
{
    Battery_type = new Specification(this,Battery_type_explain, ui->UI_Parameter_Tab, 0, 1, \
                                     "Lithium", "Battery type", \
                                     "根据实际情况选择电池类型，有锂电(Lithium)和铅酸(LeadAcid)两种类型可供选择\n Choose the battery type according to the actual situation, there are two types of lithium(Lithium) and lead acid(LeadAcid) to choose from.");
    Battery_type->add_Specification();
    BMS_Comm_type = new Specification(this,BMS_Comm_type_explain, ui->UI_Parameter_Tab, 1, 1, \
                                      "CAN", "BMS Comm type", \
                                      "设置与电池之间的通信方式，可根据情况选择RS485(RS485)或CAN通信(CAN)或以太网(Ethernet)\nSet the communication mode between the battery, RS485(RS485) or CAN communication(CAN) or Ethernet(Ethernet) can be selected according to the situation.");
    BMS_Comm_type->add_Specification();
    Power_control_type = new Specification(this,Power_control_type_explain, ui->UI_Parameter_Tab, 2, 1,\
                                           "CP_N&&P" , "Power control type", \
                                           "设置控制功率的方式，有恒压(CV)、恒流(CC)、恒功率(CP_P)、正负功率(CP_N&P)。\n恒压(CV)：输出电压值固定，不随负载、输入电压等外部工作条件而变化。\n恒流(CC)：以恒定电流工作，输出的电流大小是恒定不变的，不会随着电压的变化而变化。\n恒功率(CP_P)：可以在'恒功率'处设置功率大小，并根据选择的充电/放电执行动作。\n正负功率(CP_N&P)：可以在'恒功率'处设置功率大小，正数为放电、负数为充电。\nThe control power mode is set, including constant voltage (CV), constant current (CC), constant power (CP_P), positive and negative power (CP_N&P). \nConstant voltage (CV) : The output voltage value is fixed and does not vary with external working conditions such as load and input voltage. \nConstant current (CC) : Operating at a constant current, the output current is constant and does not change with the voltage. \nConstant power (CP_P) : Power can be set at 'constant power' and actions can be performed based on the selected charge/discharge. \nPositive and negative power (CP_N&P) : The power value can be set at the 'constant power', where the positive value is discharging and the negative value is charging.");
    Power_control_type->add_Specification();
    EMS_Comm_type = new Specification(this,EMS_Comm_type_explain, ui->UI_Parameter_Tab, 3, 1, \
                                      "RS485", "EMS Comm type", \
                                      "设置EMS的通信方式，有RS485(RS485),CAN通信(CAN)，以太网(Ethernet)三种方式\nSetting the communication mode of EMS, there are RS485(RS485),CAN communication (CAN) and Ethernet(Ethernet).");
    EMS_Comm_type->add_Specification();
    Output_power_limit = new Specification(this,Output_power_limit_explain, ui->UI_Parameter_Tab, 4, 1,\
                                           "100", "Output power limit", \
                                           "设置允许输出的功率最大值\nSet the maximum power output allowed.");
    Output_power_limit->add_Specification();
    BAT_manufacturers = new Specification(this,BAT_manufacturers_explain, ui->UI_Parameter_Tab, 5, 1, \
                                          "GAOTE", "BAT manufacturers", \
                                          "这是电池厂家，根据选择的电池厂家解析报文\nThis is the battery manufacturer and the packet is parsed according to the selected battery manufacturer.");
    BAT_manufacturers->add_Specification();
    Power_Delta = new Specification(this,Power_Delta_explain, ui->UI_Parameter_Tab, 6, 1, \
                                    "10", "Power Delta", \
                                    "设置功率回差，默认功率回差为10kw，输出功率增加达到'输出功率限制+功率回差'时，会将输出功率降低到'输出功率-功率回差'\nSet the Power Delta, the default power delta is 10kw. When the output power increases to 'output power limit + power delta', the output power will be reduced to 'output power - power delta'.");
    Power_Delta->add_Specification();
    Charge_power_limit = new Specification(this,Charge_power_limit_explain, ui->UI_Parameter_Tab, 7, 1, \
                                           "100", "Charge power limit",\
                                           "设置充电功率限制,允许充电的功率最大值\nSet the charging power limit to allow the maximum power of charging.");
    Charge_power_limit->add_Specification();
    Discharge_power_limit = new Specification(this,Discharge_power_limit_explain, ui->UI_Parameter_Tab, 8, 1, \
                                              "100", "Charge power limit", \
                                              "设置放电功率限制，允许放电的功率最大值\nThe discharge power limit is set to allow the maximum power of the discharge.");
    Discharge_power_limit->add_Specification();
    Charge_Vol_upper_Limit_delta = new Specification(this,Charge_Vol_upper_Limit_delta_explain, ui->UI_Parameter_Tab, 9, 1, \
                                                     "10", "Charge Vol upper Limit delta", \
                                                     "设置充电电压上限回差，默认充电电压上限为10V，充电电压达到'充电电压上限+充电电压回差'时，将会对设备进行禁充，充电电压降到'充电电压上限-充电电压回差'时解除禁充\nSet the upper Limit of Charge voltage delta (Charge Vol upper Limit delta). The default upper limit of charge voltage is 10V. When the charge voltage reaches the 'upper limit of charge voltage + charge voltage delta', the device will be forbidden to charge, and when the charge voltage drops to the 'upper limit of charge voltage - charge voltage delta', the forbidden charge will be lifted.");
    Charge_Vol_upper_Limit_delta->add_Specification();
    Discharge_Vol_lower_Limit_delta = new Specification(this,Discharge_Vol_lower_Limit_delta_explain, ui->UI_Parameter_Tab, 10, 1,\
                                                        "10", "Discharge Vol lower Limit delta", \
                                                        "设置放电电压下限回差，默认放电电压下限回差为10V，放电电电压低于'放电电压下限-放电电电压回差'时，将会对设备进行禁放，放电电压达到'放电电压下限+充电电压回差'时解除禁放\nSet the Discharge voltage lower Limit delta (Discharge Vol lower Limit delta), the default discharge voltage lower limit delta is 10V, when the discharge voltage is lower than the 'discharge voltage lower limit - discharge voltage delta', the device will be prohibited, when the discharge voltage reaches the 'discharge voltage lower limit + charge voltage delta', the prohibited discharge will be lifted.");
    Discharge_Vol_lower_Limit_delta->add_Specification();
    Host_Address = new Specification(this,Host_Address_explain, ui->UI_Parameter_Tab, 0, 4,\
                                     "1", "Host Address", \
                                     "这是设备地址，默认值为1，可调范围在1~255之间，用于EMS通信时匹配主机地址\nThis is the device address, which defaults to 1 and can be adjusted from 1 to 255 to match the host address during EMS communication.");
    Host_Address->add_Specification();
    serial_port_1 = new Specification(this,serial_port_1_explain, ui->UI_Parameter_Tab, 1, 4, \
                                      "9600", "serial port 1", \
                                      "这是串口1，对应触摸屏接口中TXD2、RXD2(上位机232通信)，设置波特率，有六项可供选择，分别是1200、2400、4800、9600、19200、38400，串口1默认波特率是9600bps\nThis is serial port 1, which corresponds to TXD2 and RXD2(upper computer 232 communication) in the touch screen interface. There are six baud rates to choose from, which are 1200, 2400, 4800, 9600, 19200 and 38400 respectively. The default baud rate of serial port 1 is 9600bps.");
    serial_port_1->add_Specification();
    serial_port_2 = new Specification(this,serial_port_2_explain, ui->UI_Parameter_Tab, 2, 4, \
                                      "9600", "serial port 2", \
                                      "这是串口2，对应触摸屏接口中485_3A、485_3B(电池BMS通信)，设置波特率，有六项可供选择，分别是1200、2400、4800、9600、19200、38400，串口2默认波特率是9600bps\nThis is serial port 2, which corresponds to 485_3A and 485_3B(battery BMS communication) in the touch screen interface. There are six baud rates to choose from, which are 1200, 2400, 4800, 9600, 19200 and 38400 respectively. The default baud rate of serial port 2 is 9600bps.");
    serial_port_2->add_Specification();
    serial_port_3 = new Specification(this,serial_port_3_explain, ui->UI_Parameter_Tab, 3, 4, \
                                      "9600", "serial port 3", \
                                      "这是串口3，对应触摸屏接口中485_4A、485_4B(空调)，设置波特率，有六项可供选择，分别是1200、2400、4800、9600、19200、38400，串口3默认波特率是9600bps\nThis is serial port 3, corresponding to the touch screen interface 485_4A, 485_4B(air conditioning), set the baud rate, there are six options to choose from, respectively, 1200, 2400, 4800, 9600, 19200, 38400, serial port 3 default baud rate is 9600bps.");
    serial_port_3->add_Specification();
    serial_port_4 = new Specification(this,serial_port_4_explain, ui->UI_Parameter_Tab, 4, 4, \
                                      "9600", "serial port 4", \
                                      "这是串口4，对应触摸屏接口中485_5A、485_5B(电能表)，设置波特率，有六项可供选择，分别是1200、2400、4800、9600、19200、38400，串口4默认波特率是9600bps\nThis is serial port 4, which corresponds to 485_5A and 485_5B(electricity meter) in the touch screen interface. There are six baud rates to choose from, which are 1200, 2400, 4800, 9600, 19200 and 38400 respectively. The default baud rate of serial port 4 is 9600bps.");
    serial_port_4->add_Specification();
    serial_port_5 = new Specification(this,serial_port_5_explain, ui->UI_Parameter_Tab, 5, 4, \
                                      "9600", "serial port 5", \
                                      "这是串口5，对应触摸屏接口中485_6A、485_6B(EMS通信)，设置波特率，有六项可供选择，分别是1200、2400、4800、9600、19200、38400，串口5默认波特率是9600bps\nThis is serial port 5, which corresponds to 485_6A and 485_6B(EMS communication) in the touch screen interface. There are six baud rates to choose from, which are 1200, 2400, 4800, 9600, 19200 and 38400 respectively. The default baud rate of serial port 5 is 9600bps.");
    serial_port_5->add_Specification();

    Can_port_1 = new Specification(this,Can_port_1_explain, ui->UI_Parameter_Tab, 6, 4, \
                                   "500", "Can port 1", \
                                   "这是CAN1端口，PCS内部通讯的波特率，默认波特率500，无需更改\nThis is the baud rate of CAN1 port and PCS internal communication. The default baud rate is 500, which need not be changed.");
    Can_port_1->add_Specification();
    Can_port_2 = new Specification(this,Can_port_2_explain, ui->UI_Parameter_Tab, 7, 4, \
                                   "250", "Can port 2", \
                                   "这是CAN2端口，PCS与BMS通信的波特率，默认波特率125，根据现场BMS通信波特率进行修改，其中有五项可供选择，分别是100、125、250、500、800\nThis is the baud rate of the CAN2 port and the communication between PCS and BMS. The default baud rate is 125, which is modified according to the on-site BMS communication baud rate. There are five items to choose from, which are 100, 125, 250, 500 and 800 respectively.");
    Can_port_2->add_Specification();
    ProtocolVersion = new Specification(this,ProtocolVersion_explain, ui->UI_Parameter_Tab, 0, 7, \
                                        "5612", "ProtocolVersion", \
                                        "这是协议版本号，用于查看当前协议版本\nThis is the protocol version number used to see the current protocol version.");
    ProtocolVersion->add_Specification();
    UserPassPort = new Specification(this,UserPassPort_explain, ui->UI_Parameter_Tab, 1, 7, \
                                     "123456", "UserPassPort", \
                                     "这是用户密码，可供重新设置用户密码，默认用户密码123456\nThis is the user password, you can reset the user password, the default user password 123456.");
    UserPassPort->add_Specification();
    RootPassport = new Specification(this,RootPassport_explain, ui->UI_Parameter_Tab, 2, 7,\
                                     "888888", "RootPassport", \
                                     "这是超级权限密码，可供重新设置超级权限密码，默认超级权限密码888888\nThis is the super privilege password. You can reset the super privilege password. The default super privilege password is 888888.");
    RootPassport->add_Specification();
    Language = new Specification(this,Language_explain, ui->UI_Parameter_Tab, 3, 7, \
                                 "English", "Language", \
                                 "设置显示屏的显示语言，可供选择为中文与英文，切换语言时系统会重启\nSet the display language of the display screen, which can be selected as Chinese and English. The system will restart when switching languages.");
    Language->add_Specification();
    System_upgrade = new Specification(this,System_upgrade_explain, ui->UI_Parameter_Tab, 4, 7, \
                                       "upgrade", "System_upgrade", \
                                       "点击即可进入系统升级应用程序，根据升级文档进行系统升级\nClick to enter the system upgrade application and upgrade the system according to the upgrade document.");
    System_upgrade->add_Specification();
    Sounds = new Specification(this,Sounds_explain, ui->UI_Parameter_Tab, 5, 7, \
                               "Allow", "Sounds", \
                               "设置显示屏是否开启声音，可供选择为允许(Allow)、禁止(forbid)\nSet whether the display is enabled sound, which can be allowed(Allow) or prohibited(forbid).");
    Sounds->add_Specification();
    DryContact = new Specification(this,DryContact_explain, ui->UI_Parameter_Tab, 6, 7, \
                                   "forbid", "DryContact", \
                                   "根据项目现场配置干接点功能，可供选择为允许(Allow)、禁止(forbid)\nAccording to the project site configuration dry contact function, can be selected as allowed(Allow), prohibited(forbid).");
    DryContact->add_Specification();
}
/***********系统参数 绘制button************/
void MEGAWin::SystemParameter()
{
    Change_rate_of_power = new Specification(this,Change_rate_of_power_explain, ui->UI_SystemParameter_Tab, 0, 1, \
                                             "20", "Change_rate_of_power", \
                                             "功率变化率是与额定功率相比功率变化的大小\nPower change ratio is the magnitude of the power change compared to the rated power.");
    Change_rate_of_power->add_Specification();
    Grid_frequency_upper_limit = new Specification(this,Grid_frequency_upper_limit_explain, ui->UI_SystemParameter_Tab, 1, 1, \
                                                   "3", "Grid_frequency_upper_limit", \
                                                   "电网频率变化范围的最大值,可供选择为0.2、0.5、1、3\nThe maximum value of the frequency variation range of the power grid can be selected as 0.2, 0.5, 1, and 3.");
    Grid_frequency_upper_limit->add_Specification();
    Grid_frequency_lower_limit = new Specification(this,Grid_frequency_lower_limit_explain, ui->UI_SystemParameter_Tab, 2, 1, \
                                                   "-3", "Grid_frequency_lower_limit", \
                                                   "电网频率变化范围的最小值,可供选择为-0.5、-1、-2、-3\nThe minimum value of the frequency variation range of the power grid can be selected as -0.5, -1, -2, -3.");
    Grid_frequency_lower_limit->add_Specification();
    Vol_protection_upper_limit = new Specification(this,Vol_protection_upper_limit_explain, ui->UI_SystemParameter_Tab, 3, 1, \
                                                   "+15", "Vol_protection_upper_limit", \
                                                   "当电压超过电压保护值一定百分比将进行电压保护,可供选择为+10、+15、+20、+30\nWhen the voltage exceeds a certain percentage of the voltage protection value, the voltage protection will be carried out, and the available options are +10, +15, +20, +30.");
    Vol_protection_upper_limit->add_Specification();
    Vol_protection_lower_limit = new Specification(this,Vol_protection_lower_limit_explain, ui->UI_SystemParameter_Tab, 4, 1, \
                                                   "-15", "Vol_protection_lower_limit", \
                                                   "当电压低于电压保护值一定百分比将进行电压保护,可供选择为-10、-15、-20、-30\nWhen the voltage is lower than a certain percentage of the voltage protection value, voltage protection will be carried out, which can be selected as -10, -15, -20, -30.");
    Vol_protection_lower_limit->add_Specification();
    HVRT_enable = new Specification(this,HVRT_enable_explain, ui->UI_SystemParameter_Tab, 5, 1, \
                                                    "prohibit", "HVRT_enable", \
                                                    "这是高压穿越(HVRT)使能,使能后该设备不会因为短时间的高电压而停机,可供选择为允许(Enable)、禁止(prohibit)\nEThis is the High voltage ride through(HVRT) enable, after which the device will not be shut down due to a short period of high voltage. The options are Allow (Enable), forbid(prohibit).");
    HVRT_enable->add_Specification();
    LVRT_enable = new Specification(this,LVRT_enable_explain, ui->UI_SystemParameter_Tab, 6, 1, \
                                    "prohibit", "LVRT_enable", \
                                    "这是低压穿越(LVRT)使能，使能后该设备不会因为短时间的低电压而停机,可供选择为允许(Enable)、禁止(prohibit)\nThis is a Low voltage ride through enable, which prevents the device from shutting down due to a short period of low voltage. The options are Allow(Enable),, forbid(prohibit).");
    LVRT_enable->add_Specification();
    AFD_enable = new Specification(this,AFD_enable_explain, ui->UI_SystemParameter_Tab, 7, 1, \
                                   "prohibit", "AFD_enable", \
                                   "防止孤岛效应，当检测出现孤岛效应(在光伏并网系统中,当大电网出现停电事故时,光伏并网逆变器发电与电网低压侧本地负载如果刚好出现功率相匹配时,容易出现自给自足的维持发电状态,从而出现""孤岛""现象,从而危及检修人员安全)时,让逆变器自动停机,可供选择为允许(Enable)、禁止(prohibit)\nPrevent island effect, When the detection of island effect (in the photovoltaic grid-connected system, when the power failure accident occurs in the large power grid, photovoltaic grid-connected inverter power generation and the local load on the low voltage side of the grid if there is just a power match, it is easy to self-contained maintenance power state, resulting in the phenomenon of ""island"", thereby endangering the safety of maintenance personnel), let the inverter automatic shutdown, optional Permit(Enable) and forbid(prohibit).");
    AFD_enable->add_Specification();
    Insulation_detection_enable = new Specification(this,Insulation_detection_enable_explain, ui->UI_SystemParameter_Tab, 8, 1, \
                                                    "prohibit", "Insulation_detection_enable", \
                                                    "绝缘检测使能，绝缘电阻大于33KΩ要能正常起机运行，小于33KΩ不能起机，并且要告警，默认禁止,可供选择为允许(Enable)、禁止(prohibit)\nEnable insulation detection. If the insulation resistance is greater than 33KΩ, the machine can start normally; if the insulation resistance is smaller than 33KΩ, the machine cannot start, and the alarm should be generated. By default, it is prohibited, which can be selected as Allow(Enable) or forbid(prohibit).");
    Insulation_detection_enable->add_Specification();
    PrimaryFreq_enable = new Specification(this,PrimaryFreq_enable_explain, ui->UI_SystemParameter_Tab, 9, 1, \
                                           "prohibit", "PrimaryFreq_enable", \
                                           "一次调频使能,电网的频率偏离额定值时，通过控制有功功率的增减使电网频率维持稳定，可供选择为允许(Enable)、禁止(prohibit)\nWhen the frequency of the power grid deviates from the rated value, the frequency of the power grid can be maintained stable by controlling the increase or decrease of the active power. The alternatives are Allow(Enable) and forbid(prohibit).");
    PrimaryFreq_enable->add_Specification();
    Inertia_enable = new Specification(this,Inertia_enable_explain, ui->UI_SystemParameter_Tab, 10, 1, \
                                       "prohibit", "Inertia_enable", \
                                       "转动惯量使能，可供选择为允许(Enable)、禁止(prohibit)\nThe moment of inertia is enabled (Enable, prohibit).");
    Inertia_enable->add_Specification();

    CV_parallel = new Specification(this,CV_parallel_explain, ui->UI_SystemParameter_Tab, 11, 1, \
                                    "prohibit", "CV_parallel", \
                                    "恒压并机使能,可供选择为允许(Enable)、禁止(prohibit)\nAllow (Enable) forbid(prohibit) Enable the constant voltage parallel machine.");
    CV_parallel->add_Specification();

    Machine_type = new Specification(this,Machine_type_explain, ui->UI_SystemParameter_Tab, 0, 4, \
                                     "PCS-TS", "Machine_type", \
                                     "根据现场机器机器型号设置，以出厂值为准,可供选择为PCS、PCS-T、PCS-TS、PCS-TS-T\nSet according to the machine model and factory value. PCS, PCs-T, PCS-TS, and PCS-TS-T can be selected.");
    Machine_type->add_Specification();
    Machine_capacity = new Specification(this,Machine_capacity_explain, ui->UI_SystemParameter_Tab, 1, 4, \
                                     "100", "Machine_capacity", \
                                     "PCS的额定容量，以出厂值为准，不可随意更改\nThe rated capacity of PCS is subject to the factory value and cannot be changed at will.");
    Machine_capacity->add_Specification();
    Output_Fre_grade = new Specification(this,Output_Fre_grade_explain, ui->UI_SystemParameter_Tab, 2, 4, \
                                         "50", "Output_Fre_grade", \
                                         "设置输出频率的等级，一般默认50HZ，根据项目地可更改为60Hz\nSet the output frequency level. The default frequency is 50HZ, but it can be changed to 60Hz according to the project.");
    Output_Fre_grade->add_Specification();
    Output_vol_level = new Specification(this,Output_vol_level_explain, ui->UI_SystemParameter_Tab, 3, 4, \
                                         "400", "Output_vol_level", \
                                         "电压等级是通过变压器后输出的电压等级，要根据变压器的变比来设置，以出厂默认值为准，不可更改\nVoltage level is the output voltage level through the transformer, according to the transformer ratio to set, to the factory default value prevail, can not be changed.");
    Output_vol_level->add_Specification();
    Converter_side_vol_level = new Specification(this,Converter_side_vol_level_explain, ui->UI_SystemParameter_Tab, 4, 4, \
                                         "270:400", "Converter_side_vol_level", \
                                         "逆变电压等级是逆变器逆变出来的电压等级，要根据变压器来设置，以出厂默认值为准，不可随意更改，可供更改选择为1:1、60:400、100:400、200:400、270:400、315:400、315:480\n");
    Converter_side_vol_level->add_Specification();
    Output_reactive_power_mode = new Specification(this,Output_reactive_power_mode_explain, ui->UI_SystemParameter_Tab, 5, 4, \
                                         "Non adjustab", "Output_reactive_power_mode", \
                                         "输出无功方式，默认不可调节，可供选择为功率因数(PF)、无功功率(Q)、不可调节(Non adjustable)\nadjustable output reactive power mode, adjustable by default, adjustable power factor (PF), adjustable power (Q), Non adjustable(Non adjustable).");
    Output_reactive_power_mode->add_Specification();
    Grid_connected_mode_of_Inv = new Specification(this,Grid_connected_mode_of_Inv_explain, ui->UI_SystemParameter_Tab, 6, 4, \
                                                   "Non counterc", "Grid_connected_mode_of_Inv", \
                                                   "设置逆变器的并网方式，可逆流即光伏发电转换成交流电后可以并入电网；不可逆则是光伏发电的电流不会流向电网。默认可逆流，可供选择为可逆流(Counterc)、不可逆流(Non counterc)\nThe grid-connected mode of the inverter can be countercurrent, that is, photovoltaic power generation can be converted into alternating current, which can be incorporated into the power grid; Irreversible means that photovoltaic electricity does not flow to the grid. Countercurrent is available by default. The options are Counterc(Counterc) and Non counterc(Non counterc).");
    Grid_connected_mode_of_Inv->add_Specification();
    Primary_FM_dead_zone = new Specification(this,Primary_FM_dead_zone_explain, ui->UI_SystemParameter_Tab, 7, 4, \
                                             "3", "Primary_FM_dead_zone", \
                                             "一次调频死区,为了防止在电网频差小范围变化时调门不必要的动作而设置的频差\nPrimary frequency modulation dead zone A frequency difference set to prevent unwanted switch action when the network frequency difference varies in a small range.");
    Primary_FM_dead_zone->add_Specification();
    PFM_coeff = new Specification(this,PFM_coeff_explain, ui->UI_SystemParameter_Tab, 8, 4, \
                                  "20", "PFM_coeff", \
                                  "设置有功调频系数\nSet the active power frequency modulation coefficient.");
    PFM_coeff->add_Specification();
    Grid_recover_time = new Specification(this,Grid_recover_time_explain, ui->UI_SystemParameter_Tab, 9, 4, \
                                          "10", "Grid_recover_time", \
                                          "电网恢复并网时间：预留功能，设置无效\nGrid restoration time: reserved function, setting invalid.");
    Grid_recover_time->add_Specification();
    DynamicCap = new Specification(this,DynamicCap_explain, ui->UI_SystemParameter_Tab, 10, 4, \
                                   "9600", "DynamicCap", \
                                   "电网扩容使能,当负载在短时间内所需功率大于电网容量时，可暂时从电池辅助供电以达到功率要求，可供选择为允许(Allow)、禁止(forbid)\nEnable the power network expansion. The options are Allow(Allow) and forbid(forbid).");
    DynamicCap->add_Specification();
    Module_Number = new Specification(this,Module_Number_explain, ui->UI_SystemParameter_Tab, 0, 7, \
                                      "1", "Module_Number", \
                                      "PCS的模块数量，默认值1(无效设置)\nNumber of modules for PCS, default 1(invalid setting).");
    Module_Number->add_Specification();
    Restore_factory = new Specification(this,Restore_factory_explain, ui->UI_SystemParameter_Tab,1, 7, \
                                        "restore", "Restore_factory", \
                                        "恢复出厂时的默认设置\nRestore the factory default Settings.");
    Restore_factory->add_Specification();
    Clear_Data = new Specification(this,Clear_Data_explain, ui->UI_SystemParameter_Tab, 2, 7, \
                                   "Clear", "Clear_Data", \
                                   "清除系统此前的记录数据及操作数据\nClear previous recorded data and operation data of the system.");
    Clear_Data->add_Specification();
}
/***********外设 绘制button************/
void MEGAWin::Peripheral()
{
    DI_1_Enable = new Specification(this,DI_1_Enable_explain, ui->ExternalDevice_tW, 0, 0, \
                                   "Enable", "DI_1_Enable", \
                                   "输入干接点1，发生NO关机时执行动作的开关,可选功能为使能(Enable)、禁止(Disable)\nInput dry contact 1, the switch to perform the action when NO shutdown occurs. The optional functions are Enable(Enable) or Disable(Disable).");
    DI_1_Enable->add_Specification();
    DI_2_Enable = new Specification(this,DI_2_Enable_explain, ui->ExternalDevice_tW, 1, 0, \
                                   "Disable", "DI_2_Enable", \
                                   "输入干接点2，发生NC关机时执行动作的开关，可选功能为使能(Enable)、禁止(Disable)\nEnter dry contact 2, the switch that performs the action when NC shutdown occurs.The optional functions are Enable(Enable) or Disable(Disable).");
    DI_2_Enable->add_Specification();
    DI_3_Enable = new Specification(this,DI_3_Enable_explain, ui->ExternalDevice_tW, 2, 0, \
                                   "Enable", "DI_3_Enable", \
                                   "输入干接点3，门禁开启时执行动作的开关，可选功能为使能(Enable)、禁止(Disable)\nEnter dry contact 3. The switch that performs the action when the access control is opened.The optional functions are Enable(Enable) or Disable(Disable).");
    DI_3_Enable->add_Specification();
    DI_4_Enable = new Specification(this,DI_4_Enable_explain, ui->ExternalDevice_tW, 3, 0, \
                                   "Enable", "DI_4_Enable", \
                                   "输入干接点4，柴发信号发出时执行动作的开关，可选功能为使能(Enable)、禁止(Disable)\nInput dry contact 4, the switch to perform the action when the firewood signal is sent.The optional functions are Enable(Enable) or Disable(Disable).");
    DI_4_Enable->add_Specification();
    DI_5_Enable = new Specification(this,DI_5_Enable_explain, ui->ExternalDevice_tW, 4, 0, \
                                   "Enable", "DI_5_Enable", \
                                   "输入干接点5，发生水浸时执行动作的开关，可选功能为使能(Enable)、禁止(Disable)\nEnter dry contact 5, the switch that performs the action when flooding occurs.The optional functions are Enable(Enable) or Disable(Disable).");
    DI_5_Enable->add_Specification();
    DI_6_Enable = new Specification(this,DI_6_Enable_explain, ui->ExternalDevice_tW, 5, 0, \
                                   "Enable", "DI_6_Enable", \
                                   "输入干接点6，消防信号发出时执行动作的开关，可选功能为使能(Enable)、禁止(Disable)\nInput dry contact 6, the switch to perform action when the fire signal is sent.The optional functions are Enable(Enable) or Disable(Disable).");
    DI_6_Enable->add_Specification();
    DO_1_Enable = new Specification(this,DO_1_Enable_explain, ui->ExternalDevice_tW, 6, 0, \
                                   "Disable", "DO_1_Enable", \
                                   "输出干接点1，发电机开启时执行动作的开关，可选功能为使能(Enable)、禁止(Disable)\nOutput dry contact 1, the switch that performs the action when the generator is on.The optional functions are Enable(Enable) or Disable(Disable).");
    DO_1_Enable->add_Specification();
    DO_2_Enable = new Specification(this,DO_2_Enable_explain, ui->ExternalDevice_tW, 7, 0, \
                                   "Disable", "DO_2_Enable", \
                                   "输出干接点2，预留功能，设置无效，可选功能为使能(Enable)、禁止(Disable)\nDry contact 2 is output. The reserved function is invalid.The optional functions are Enable(Enable) or Disable(Disable).");
    DO_2_Enable->add_Specification();
    DO_3_Enable = new Specification(this,DO_3_Enable_explain, ui->ExternalDevice_tW, 8, 0, \
                                   "Disable", "DO_3_Enable", \
                                   "输出干接点3，预留功能，设置无效，可选功能为使能(Enable)、禁止(Disable)\nDry contact 3 is output. The reserved function is invalid.The optional functions are Enable(Enable) or Disable(Disable).");
    DO_3_Enable->add_Specification();

    DI_1_NC_O = new Specification(this,DI_1_NC_O_explain, ui->ExternalDevice_tW, 0, 1, \
                                   "N_O", "DI_1_NC_O", \
                                   "输入干接点1，设置NO关机是常闭电路还是常开电路,可选功能为常开(N_O)常闭(N_C)\nInput dry contact 1, set NO shutdown is normally closed circuit or normally open circuit, optional function is normally open (N_O) normally closed (N_C).");
    DI_1_NC_O->add_Specification();
    DI_2_NC_O = new Specification(this,DI_2_NC_O_explain, ui->ExternalDevice_tW, 1, 1, \
                                   "N_O", "DI_2_NC_O", \
                                   "输入干接点2，设置NC关机是常闭电路还是常开电路可选功能为常开(N_O)常闭(N_C)\nInput dry contact 2, set NC shutdown is normally closed circuit or normally open circuit Optional function is normally open (N_O) normally closed (N_C).");
    DI_2_NC_O->add_Specification();
    DI_3_NC_O = new Specification(this,DI_3_NC_O_explain, ui->ExternalDevice_tW, 2, 1, \
                                   "N_C", "DI_3_NC_O", \
                                   "输入干接点3，设置门禁开是常闭电路还是常开电路可选功能为常开(N_O)常闭(N_C)\nInput dry contact 3, set the access control open normally closed circuit or normally open circuit Optional function: normally open (N_O) normally closed (N_C).");
    DI_3_NC_O->add_Specification();
    DI_4_NC_O = new Specification(this,DI_4_NC_O_explain, ui->ExternalDevice_tW, 3, 1, \
                                   "N_O", "DI_4_NC_O", \
                                   "输入干接点4，设置柴发信号是常闭电路还是常开电路可选功能为常开(N_O)常闭(N_C)\nInput dry contact 4, set the firewood signal is normally closed circuit or normally open circuit Optional function is normally open (N_O) normally closed (N_C).");
    DI_4_NC_O->add_Specification();
    DI_5_NC_O = new Specification(this,DI_5_NC_O_explain, ui->ExternalDevice_tW, 4, 1, \
                                   "N_O", "DI_5_NC_O", \
                                   "输入干接点5，设置水浸是常闭电路还是常开电路可选功能为常开(N_O)常闭(N_C)\nInput dry contact 5, set the flooding is normally closed circuit or normally open circuit Optional function is normally open (N_O) normally closed (N_C).");
    DI_5_NC_O->add_Specification();
    DI_6_NC_O = new Specification(this,DI_6_NC_O_explain, ui->ExternalDevice_tW, 5, 1, \
                                   "N_O", "DI_6_NC_O", \
                                   "输入干接点6，设置消防是常闭电路还是常开电路可选功能为常开(N_O)常闭(N_C)\nInput dry contact 6, set fire is normally closed circuit or normally open circuit Optional function is normally open (N_O) normally closed (N_C).");
    DI_6_NC_O->add_Specification();
    DO_1_NC_O = new Specification(this,DO_1_NC_O_explain, ui->ExternalDevice_tW, 6, 1, \
                                   "N_O", "DO_1_NC_O", \
                                   "输出干接点1，设置发电机是常闭电路还是常开电路可选功能为常开(N_O)常闭(N_C)\nOutput dry contact 1, set the generator is normally closed circuit or normally open circuit Optional function is normally open (N_O) normally closed (N_C).");
    DO_1_NC_O->add_Specification();
    DO_2_NC_O = new Specification(this,DO_2_NC_O_explain, ui->ExternalDevice_tW, 7, 1, \
                                   "N_O", "DO_2_NC_O", \
                                   "输出干接点2，预留功能，设置无效，设置是常闭电路还是常开电路可选功能为常开(N_O)常闭(N_C)\nOutput dry contact 2, reserved function, setting invalid, setting is normally closed circuit or normally open circuit Optional function: normally open (N_O) normally closed (N_C).");
    DO_2_NC_O->add_Specification();
    DO_3_NC_O = new Specification(this,DO_3_NC_O_explain, ui->ExternalDevice_tW, 8, 1, \
                                   "N_O", "DO_3_NC_O", \
                                   "输出干接点3，预留功能，设置无效，设置是常闭电路还是常开电路可选功能为常开(N_O)常闭(N_C)\nOutput dry contact 3, reserved function, setting invalid, setting is normally closed circuit or normally open circuit Optional function: normally open (N_O) normally closed (N_C).");
    DO_3_NC_O->add_Specification();

    DI_1_Action = new Specification(this,DI_1_Action_explain, ui->ExternalDevice_tW, 0, 2, \
                                   "Shut down", "DI_1_Action", \
                                   "输入干接点1，发生NO关机时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\nInput dry contact 1 to perform the action when NO shutdown occurs. The optional functions are prompt(Prompt), standby(Standby), shutdown(Shut down), full standby(Full standby), empty standby(Empty standby), fault standby(Failure standby), and power grid signal(Grid singnal).");
    DI_1_Action->add_Specification();
    DI_2_Action = new Specification(this,DI_2_Action_explain, ui->ExternalDevice_tW, 1, 2, \
                                   "Prompt", "DI_2_Action", \
                                   "输入干接点2，发生NC关机时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\nEnter dry contact 2 to perform the action when the NC is shut down.The optional functions are prompt(Prompt), standby(Standby), shutdown(Shut down), full standby(Full standby), empty standby(Empty standby), fault standby(Failure standby), and power grid signal(Grid singnal)");
    DI_2_Action->add_Specification();
    DI_3_Action = new Specification(this,DI_3_Action_explain, ui->ExternalDevice_tW, 2, 2, \
                                   "Prompt", "DI_3_Action", \
                                   "输入干接点3，门禁打开时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\nEnter dry contact 3. The action is performed when the access control is opened.The optional functions are prompt(Prompt), standby(Standby), shutdown(Shut down), full standby(Full standby), empty standby(Empty standby), fault standby(Failure standby), and power grid signal(Grid singnal)");
    DI_3_Action->add_Specification();
    DI_4_Action = new Specification(this,DI_4_Action_explain, ui->ExternalDevice_tW, 3, 2, \
                                   "Prompt", "DI_4_Action", \
                                   "输入干接点4，柴发信号发出时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\nInput dry contact 4, the action to be performed when the chai signal is issued.The optional functions are prompt(Prompt), standby(Standby), shutdown(Shut down), full standby(Full standby), empty standby(Empty standby), fault standby(Failure standby), and power grid signal(Grid singnal)");
    DI_4_Action->add_Specification();
    DI_5_Action = new Specification(this,DI_5_Action_explain, ui->ExternalDevice_tW, 4, 2, \
                                   "Shut down", "DI_5_Action", \
                                   "输入干接点5，发生水浸时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\nEnter dry contact 5 to perform the action when flooding occurs.The optional functions are prompt(Prompt), standby(Standby), shutdown(Shut down), full standby(Full standby), empty standby(Empty standby), fault standby(Failure standby), and power grid signal(Grid singnal)");
    DI_5_Action->add_Specification();
    DI_6_Action = new Specification(this,DI_6_Action_explain, ui->ExternalDevice_tW, 5, 2, \
                                   "Shut down", "DI_6_Action", \
                                   "输入干接点6，触发消防时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\nEnter dry contact 6 to trigger the fire extinguishing action.The optional functions are prompt(Prompt), standby(Standby), shutdown(Shut down), full standby(Full standby), empty standby(Empty standby), fault standby(Failure standby), and power grid signal(Grid singnal)");
    DI_6_Action->add_Specification();
    DO_1_Action = new Specification(this,DO_1_Action_explain, ui->ExternalDevice_tW, 6, 2, \
                                   "Prompt", "DO_1_Action", \
                                   "输出干接点1，启动发电机时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\nOutput dry contact 1, the action to be performed when starting the generator.The optional functions are prompt(Prompt), standby(Standby), shutdown(Shut down), full standby(Full standby), empty standby(Empty standby), fault standby(Failure standby), and power grid signal(Grid singnal)");
    DO_1_Action->add_Specification();
    DO_2_Action = new Specification(this,DO_2_Action_explain, ui->ExternalDevice_tW, 7, 2, \
                                   "Prompt", "DO_2_Action", \
                                   "输出干接点2，预留功能，设置无效，信号触发时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\nOutput dry contact 2, reserved function, set invalid, the action to be performed when the signal is triggered.The optional functions are prompt(Prompt), standby(Standby), shutdown(Shut down), full standby(Full standby), empty standby(Empty standby), fault standby(Failure standby), and power grid signal(Grid singnal)");
    DO_2_Action->add_Specification();
    DO_3_Action = new Specification(this,DO_3_Action_explain, ui->ExternalDevice_tW, 8, 2, \
                                   "Prompt", "DO_3_Action", \
                                   "输出干接点3，预留功能，设置无效，信号触发时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\nDry contact 3 is output. The reserved function is invalid.The optional functions are prompt(Prompt), standby(Standby), shutdown(Shut down), full standby(Full standby), empty standby(Empty standby), fault standby(Failure standby), and power grid signal(Grid singnal)");
    DO_3_Action->add_Specification();
}
/***********BMS保护 绘制button************/
void MEGAWin::BMS_Protect()
{
    DOD_Action = new Specification(this,DOD_Action_explain, ui->BMSProtection_tW, 0, 0, \
                                   "Standby", "DOD", \
                                   "DOD保护，触发DOD保护时执行的动作，可选功能为不动作(NO action)、降功率(Power down)、待机(Standby)、关机(Shut down)\nDOD protection: Actions to be performed when DOD protection is triggered. The optional functions are NO action(NO action), Power down(Power down), Standby(Standby), Shut down(Shut down).");
    DOD_Action->add_Specification();
    Prohibit_charging_Action = new Specification(this,Prohibit_charging_Action_explain, ui->BMSProtection_tW, 1, 0, \
                                   "Standby", "Prohibit_charging", \
                                   "触发禁充时执行的动作，可选功能为不动作(NO action)、降功率(Power down)、待机(Standby)、关机(Shut down)\naction to be performed when the charging ban is triggered. The optional functions are NO action(NO action), Power down(Power down), Standby(Standby), Shut down(Shut down).");
    Prohibit_charging_Action->add_Specification();
    Prohibit_discharging_Action = new Specification(this,Prohibit_discharging_Action_explain, ui->BMSProtection_tW, 2, 0, \
                                   "Standby", "Prohibit_discharging", \
                                   "触发禁放时执行的动作，可选功能为不动作(NO action)、降功率(Power down)、待机(Standby)、关机(Shut down)\nThe action to be performed when a ban is triggered.The optional functions are NO action(NO action), Power down(Power down), Standby(Standby), Shut down(Shut down).");
    Prohibit_discharging_Action->add_Specification();
    BMS_warning_Action = new Specification(this,BMS_warning_Action_explain, ui->BMSProtection_tW, 3, 0, \
                                   "NO action", "BMS_warning", \
                                   "触发BMS提示时执行的动作，可选功能为不动作(NO action)、降功率(Power down)、待机(Standby)、关机(Shut down)\nAction to be performed when a BMS prompt is triggered.The optional functions are NO action(NO action), Power down(Power down), Standby(Standby), Shut down(Shut down).");
    BMS_warning_Action->add_Specification();
    BMS_alarm_Action = new Specification(this,BMS_alarm_Action_explain, ui->BMSProtection_tW, 4, 0, \
                                   "Standby", "BMS_alarm", \
                                   "触发BMS告警时执行的动作，可选功能为不动作(NO action)、降功率(Power down)、待机(Standby)、关机(Shut down)\nAction when a BMS alarm is triggered.The optional functions are NO action(NO action), Power down(Power down), Standby(Standby), Shut down(Shut down).");
    BMS_alarm_Action->add_Specification();
    BMS_fualt_Action = new Specification(this,BMS_fualt_Action_explain, ui->BMSProtection_tW, 5, 0, \
                                   "Shut down", "BMS_fualt", \
                                   "触发BMS故障时执行的动作，可选功能为不动作(NO action)、降功率(Power down)、待机(Standby)、关机(Shut down)\nAction that is performed when a BMS fault is triggered.The optional functions are NO action(NO action), Power down(Power down), Standby(Standby), Shut down(Shut down).");
    BMS_fualt_Action->add_Specification();
    BMS_warning_CP = new Specification(this,BMS_warning_CP_explain, ui->BMSProtection_tW, 3, 1, \
                                   "0", "BMS_warning_CP", \
                                   "触发BMS提示时的充电功率\nCharge power when BMS prompt is triggered.");
    BMS_warning_CP->add_Specification();
    BMS_alarm_CP = new Specification(this,BMS_alarm_CP_explain, ui->BMSProtection_tW, 4, 1, \
                                   "0", "BMS_alarm_CP", \
                                   "触发BMS告警时执行的的充电功率\nCharge power that is executed when a BMS alarm is triggered.");
    BMS_alarm_CP->add_Specification();
    BMS_fualt_CP = new Specification(this,BMS_fualt_CP_explain, ui->BMSProtection_tW, 5, 1, \
                                   "0", "BMS_fualt_CP", \
                                   "触发BMS故障时的充电功率\nCharging power when a BMS fault is triggered.");
    BMS_fualt_CP->add_Specification();

    BMS_warning_DP = new Specification(this,BMS_warning_DP_explain, ui->BMSProtection_tW, 3, 2, \
                                   "0", "BMS_warning_DP", \
                                   "触发BMS提示时的放电功率\nDischarge power when the BMS prompt is triggered.");
    BMS_warning_DP->add_Specification();
    BMS_alarm_DP = new Specification(this,BMS_alarm_DP_explain, ui->BMSProtection_tW, 4, 2, \
                                   "0", "BMS_alarm_DP", \
                                   "触发BMS告警时的放电功率\nDischarge power when a BMS alarm is triggered.");
    BMS_alarm_DP->add_Specification();
    BMS_fualt_DP = new Specification(this,BMS_fualt_DP_explain, ui->BMSProtection_tW, 5, 2, \
                                   "0", "BMS_fualt_DP", \
                                   "触发BMS故障时的放电功率\nDischarge power when triggering a BMS fault.");
    BMS_fualt_DP->add_Specification();

}
/***********调试 绘制button************/
void MEGAWin::Debugg()
{
    Debug_variable_1 = new Specification(this,Debug_variable_1_explain, ui->UI_Debug_Tab, 0, 1, \
                                   "0", "Debug_variable_1", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_variable_1->add_Specification();
    Debug_variable_2 = new Specification(this,Debug_variable_2_explain, ui->UI_Debug_Tab, 1, 1, \
                                   "0", "Debug_variable_2", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_variable_2->add_Specification();
    Debug_variable_3 = new Specification(this,Debug_variable_3_explain, ui->UI_Debug_Tab, 2, 1, \
                                   "0", "Debug_variable_3", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_variable_3->add_Specification();
    Debug_variable_1_addr = new Specification(this,Debug_variable_1_addr_explain, ui->UI_Debug_Tab, 3, 1, \
                                   "4096", "Debug_variable_1_addr", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_variable_1_addr->add_Specification();
    Debug_variable_2_addr = new Specification(this,Debug_variable_2_addr_explain, ui->UI_Debug_Tab, 4, 1, \
                                   "4096", "Debug_variable_2_addr", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_variable_2_addr->add_Specification();
    Debug_variable_3_addr = new Specification(this,Debug_variable_3_addr_explain, ui->UI_Debug_Tab, 5, 1, \
                                   "4096", "Debug_variable_3_addr", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_variable_3_addr->add_Specification();
    Debug_memery_var_1 = new Specification(this,Debug_memery_var_1_explain, ui->UI_Debug_Tab, 6, 1, \
                                   "0", "Debug_memery_var_1", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_memery_var_1->add_Specification();
    Debug_memery_var_2 = new Specification(this,Debug_memery_var_2_explain, ui->UI_Debug_Tab, 7, 1, \
                                   "0", "Debug_memery_var_2", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_memery_var_2->add_Specification();
    Debug_memery_var_3 = new Specification(this,Debug_memery_var_3_explain, ui->UI_Debug_Tab, 8, 1, \
                                   "0", "Debug_memery_var_3", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_memery_var_3->add_Specification();
    Input_Vol_revise = new Specification(this,Input_Vol_revise_explain, ui->UI_Debug_Tab, 9, 1, \
                                   "", "Input_Vol_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Input_Vol_revise->add_Specification();
    Input_Cur_revise = new Specification(this,Input_Cur_revise_explain, ui->UI_Debug_Tab, 10, 1, \
                                   "", "Input_Cur_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Input_Cur_revise->add_Specification();
    Voltage_1_5_revise = new Specification(this,Voltage_1_5_revise_explain, ui->UI_Debug_Tab, 0, 3, \
                                   "", "Voltage_1_5_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Voltage_1_5_revise->add_Specification();
    Bus_Vol_revise = new Specification(this,Bus_Vol_revise_explain, ui->UI_Debug_Tab, 1, 3, \
                                   "", "Bus_Vol_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Bus_Vol_revise->add_Specification();
    Grid_A_AB_Vol_revise = new Specification(this,Grid_A_AB_Vol_revise_explain, ui->UI_Debug_Tab, 2, 3, \
                                   "", "Grid_A_AB_Vol_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Grid_A_AB_Vol_revise->add_Specification();
    Grid_B_BC_Vol_revise = new Specification(this,Grid_B_BC_Vol_revise_explain, ui->UI_Debug_Tab, 3, 3, \
                                   "", "Grid_B_BC_Vol_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Grid_B_BC_Vol_revise->add_Specification();
    Grid_C_CA_Vol_revise = new Specification(this,Grid_C_CA_Vol_revise_explain, ui->UI_Debug_Tab, 4, 3, \
                                   "", "Grid_C_CA_Vol_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Grid_C_CA_Vol_revise->add_Specification();
    Output_A_Cur_revise = new Specification(this,Output_A_Cur_revise_explain, ui->UI_Debug_Tab, 5, 3, \
                                   "", "Output_A_Cur_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Output_A_Cur_revise->add_Specification();
    Output_B_Cur_revise = new Specification(this,Output_B_Cur_revise_explain, ui->UI_Debug_Tab, 6, 3, \
                                   "", "Output_B_Cur_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Output_B_Cur_revise->add_Specification();
    Output_C_Cur_revise = new Specification(this,Output_C_Cur_revise_explain, ui->UI_Debug_Tab, 7, 3, \
                                   "", "Output_C_Cur_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Output_C_Cur_revise->add_Specification();
    INV_A_Vol_revise = new Specification(this,INV_A_Vol_revise_explain, ui->UI_Debug_Tab, 8, 3, \
                                   "", "INV_A_Vol_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INV_A_Vol_revise->add_Specification();
    INV_B_Vol_revise = new Specification(this,INV_B_Vol_revise_explain, ui->UI_Debug_Tab, 9, 3, \
                                   "", "INV_B_Vol_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INV_B_Vol_revise->add_Specification();
    INV_C_Vol_revise = new Specification(this,INV_C_Vol_revise_explain, ui->UI_Debug_Tab, 10, 3, \
                                   "", "INV_C_Vol_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INV_C_Vol_revise->add_Specification();

    INV_A_ind_Cur_revise = new Specification(this,INV_A_ind_Cur_revise_explain, ui->UI_Debug_Tab, 0, 5, \
                                   "", "INV_A_ind_Cur_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INV_A_ind_Cur_revise->add_Specification();
    INV_B_ind_Cur_revise = new Specification(this,INV_B_ind_Cur_revise_explain, ui->UI_Debug_Tab, 1, 5, \
                                   "", "INV_B_ind_Cur_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INV_B_ind_Cur_revise->add_Specification();
    INV_C_ind_Cur_revise = new Specification(this,INV_C_ind_Cur_revise_explain, ui->UI_Debug_Tab, 2, 5, \
                                   "", "INV_C_ind_Cur_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INV_C_ind_Cur_revise->add_Specification();
    INV_On_off_flag = new Specification(this,INV_On_off_flag_explain, ui->UI_Debug_Tab, 3, 5, \
                                   "0", "INV_On_off_flag", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INV_On_off_flag->add_Specification();
    Logic_state = new Specification(this,Logic_state_explain, ui->UI_Debug_Tab, 4, 5, \
                                   "0", "Logic_state", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Logic_state->add_Specification();
    INV_flag = new Specification(this,INV_flag_explain, ui->UI_Debug_Tab, 5, 5, \
                                   "0", "INV_flag", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INV_flag->add_Specification();
    Grid_flag = new Specification(this,Grid_flag_explain, ui->UI_Debug_Tab, 6, 5, \
                                   "0", "Grid_flag", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Grid_flag->add_Specification();
    Grid_protect_flag = new Specification(this,Grid_protect_flag_explain, ui->UI_Debug_Tab, 7, 5, \
                                   "0", "Grid_protect_flag", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Grid_protect_flag->add_Specification();
    Bat_flag = new Specification(this,Bat_flag_explain, ui->UI_Debug_Tab, 8, 5, \
                                   "0", "Bat_flag", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Bat_flag->add_Specification();
    DC_bus_flag = new Specification(this,DC_bus_flag_explain, ui->UI_Debug_Tab, 9, 5, \
                                   "0", "DC_bus_flag", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    DC_bus_flag->add_Specification();
    INT_main_flag = new Specification(this,INT_main_flag_explain, ui->UI_Debug_Tab, 10, 5, \
                                   "0", "INT_main_flag", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INT_main_flag->add_Specification();
    parallel_signal = new Specification(this,parallel_signal_explain, ui->UI_Debug_Tab, 11, 5, \
                                   "0", "parallel_signal", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    parallel_signal->add_Specification();
}
/*********** 选择静态IP地址 ************/
void MEGAWin::on_radio_static_clicked()
{
    IPShow = true;
    if(IPShow)
    {
        ui->ip_explain_btn->show();
        ui->netmask_explain_btn->show();
        ui->gateway_explain_btn->show();
        ui->server_ip_explain_btn->show();
    }
    else
    {
        ui->ip_explain_btn->hide();
        ui->netmask_explain_btn->hide();
        ui->gateway_explain_btn->hide();
        ui->server_ip_explain_btn->hide();
    }
    QMessageBox::question(this ,"static", "如果选择此项，表示使用静态的IP地址\nIf this parameter is selected, static IP addresses are used", "OK");
}
/*********** 选择自动分配IP地址 ************/
void MEGAWin::on_radio_dhcp_clicked()
{
    IPShow = false;
    if(IPShow)
    {
        ui->ip_explain_btn->show();
        ui->netmask_explain_btn->show();
        ui->gateway_explain_btn->show();
        ui->server_ip_explain_btn->show();
    }
    else
    {
        ui->ip_explain_btn->hide();
        ui->netmask_explain_btn->hide();
        ui->gateway_explain_btn->hide();
        ui->server_ip_explain_btn->hide();
    }
    QMessageBox::question(this ,"dhcp", "如果选择此项，表示使用自动分配的IP地址\nIf this parameter is selected, the automatically assigned IP address is used", "OK");
}
/*********** 调入测试数据 ************/
void MEGAWin::on_radio_test_data_btn_clicked()
{
    QMessageBox::question(this ,"test data", "调入测试数据(仅供内部测试人员使用)\nCall in test data (for internal testing personnel only)", "OK");
}
/****************切换语言*******************/
void MEGAWin::on_ChangeLanguage_btn_clicked()
{
    Change_Language();
}

void MEGAWin::on_ChangeLanguage_btn_1_clicked()
{
    Change_Language();
}
