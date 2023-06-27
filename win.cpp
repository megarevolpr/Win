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
    Grade = nullptr;
    Grade2 = nullptr;
    Grade3 = nullptr;
    Grade4 = nullptr;
    Grade5 = nullptr;
    Grade6 = nullptr;
    Grade7 = nullptr;
    Grade8 = nullptr;
    StartTime = nullptr;
    StartTime2 = nullptr;
    StartTime3 = nullptr;
    StartTime4 = nullptr;
    StartTime5 = nullptr;
    StartTime6 = nullptr;
    StartTime7 = nullptr;
    StartTime8 = nullptr;
    EndTime = nullptr;
    EndTime2 = nullptr;
    EndTime3 = nullptr;
    EndTime4 = nullptr;
    EndTime5 = nullptr;
    EndTime6 = nullptr;
    EndTime7 = nullptr;
    EndTime8 = nullptr;
    Describe = nullptr;
    Describe2 = nullptr;
    Describe3 = nullptr;
    Describe4 = nullptr;
    Describe5 = nullptr;
    Describe6 = nullptr;
    Describe7 = nullptr;
    Describe8 = nullptr;

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
    ModificationTime = nullptr;
    ModificationTime2 = nullptr;
    ModificationTime3 = nullptr;
    ModificationTime4 = nullptr;
    ModificationTime5 = nullptr;
    ModificationTime6 = nullptr;
    ModificationTime7 = nullptr;
    ModificationTime8 = nullptr;
    ModificationTime9 = nullptr;
    ModificationTime10 = nullptr;
    ModificationTime11 = nullptr;
    ModificationTime12 = nullptr;
    EventRecord = nullptr;
    EventRecord2 = nullptr;
    EventRecord3 = nullptr;
    EventRecord4 = nullptr;
    EventRecord5 = nullptr;
    EventRecord6 = nullptr;
    EventRecord7 = nullptr;
    EventRecord8 = nullptr;
    EventRecord9 = nullptr;
    EventRecord10 = nullptr;
    EventRecord11 = nullptr;
    EventRecord12 = nullptr;
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
    Grid_connected_mode = nullptr;
    Constant_power = nullptr;
    Charging_and_discharging = nullptr;
    Work_mode = nullptr;
    Output_power_factor = nullptr;
    Output_reactive_power = nullptr;
    Constant_current = nullptr;
    Constant_voltage = nullptr;
    Control_mode = nullptr;
    Machine_number = nullptr;
    Parallel = nullptr;
    Unbalance_power_enable = nullptr;
    Phase_A_power = nullptr;
    Phase_B_power = nullptr;
    Phase_C_power = nullptr;

    /***************************电池设置**********************************/

    DOD_OnGrid_explain          = new QPushButton;      //并网DOD
    DOD_OffGrid_explain         = new QPushButton;      //离网DOD
    Charge_Vol_Up_Limit_explain = new QPushButton;      //充电电压上限
    Disc_Vol_lower_Limit_explain= new QPushButton;      //放电电压下限
    Charge_Cur_Limit_explain    = new QPushButton;      //充电限流点
    Gen_turn_off_SOC_explain    = new QPushButton;      //柴发关闭SOC
    Gen_turn_on_SOC_explain     = new QPushButton;      //柴发开启SOC
    Gen_charge_SOC_explain      = new QPushButton;      //柴发充电SOC
    Grid_charge_SOC_explain     = new QPushButton;      //电网充电SOC
    Grid_capacity_explain       = new QPushButton;      //电网容量
    Turn_on_SOC_explain         = new QPushButton;      //启动SOC
    Turn_off_SOC_explain        = new QPushButton;      //停止SOC
    Turn_on_cell_vol_explain    = new QPushButton;      //启动单体电压
    Turn_off_cell_vol_explain   = new QPushButton;      //停止单体电压
    Turn_on_total_vol_explain   = new QPushButton;      //启动总压
    Turn_off_total_vol_explain  = new QPushButton;      //停止总压
    UPS_charge_power_explain    = new QPushButton;      //后备充电功率
    Monthly_cycle_time_explain  = new QPushButton;      //月循环日期
    DOD_OnGrid = nullptr;
    DOD_OffGrid = nullptr;
    Charge_Vol_Up_Limit = nullptr;
    Disc_Vol_lower_Limit = nullptr;
    Charge_Cur_Limit = nullptr;
    Gen_turn_off_SOC = nullptr;
    Gen_turn_on_SOC = nullptr;
    Gen_charge_SOC = nullptr;
    Grid_charge_SOC = nullptr;
    Grid_capacity = nullptr;
    Turn_on_SOC = nullptr;
    Turn_off_SOC = nullptr;
    Turn_on_cell_vol = nullptr;
    Turn_off_cell_vol = nullptr;
    Turn_on_total_vol = nullptr;
    Turn_off_total_vol = nullptr;
    UPS_charge_power = nullptr;
    Monthly_cycle_time = nullptr;

    /*****************************自动运行*******************************/

    Check1_explain= new QPushButton;Check2_explain= new QPushButton;Check3_explain= new QPushButton;
    Check4_explain= new QPushButton;Check5_explain= new QPushButton;Check6_explain= new QPushButton;
    Check7_explain= new QPushButton;Check8_explain= new QPushButton;Check9_explain= new QPushButton;
    Check10_explain= new QPushButton;Check11_explain= new QPushButton;Check12_explain= new QPushButton;
    Check13_explain= new QPushButton;Check14_explain= new QPushButton;Check15_explain= new QPushButton;
    Check16_explain= new QPushButton;Check17_explain= new QPushButton;Check18_explain= new QPushButton;
    Check19_explain= new QPushButton;Check20_explain= new QPushButton;
    Check1 = nullptr;Check2 = nullptr;Check3 = nullptr;Check4 = nullptr;Check5 = nullptr;Check6 = nullptr;
    Check7 = nullptr;Check8 = nullptr;Check9 = nullptr;Check10 = nullptr;Check11 = nullptr;Check12 = nullptr;
    Check13 = nullptr;Check14 = nullptr;Check15 = nullptr;Check16 = nullptr;Check17 = nullptr;Check18 = nullptr;
    Check19 = nullptr;Check20 = nullptr;

    Start_T1_explain= new QPushButton;Start_T2_explain= new QPushButton;Start_T3_explain= new QPushButton;
    Start_T4_explain= new QPushButton;Start_T5_explain= new QPushButton;Start_T6_explain= new QPushButton;
    Start_T7_explain= new QPushButton;Start_T8_explain= new QPushButton;Start_T9_explain= new QPushButton;
    Start_T10_explain= new QPushButton;Start_T11_explain= new QPushButton;Start_T12_explain= new QPushButton;
    Start_T13_explain= new QPushButton;Start_T14_explain= new QPushButton;Start_T15_explain= new QPushButton;
    Start_T16_explain= new QPushButton;Start_T17_explain= new QPushButton;Start_T18_explain= new QPushButton;
    Start_T19_explain= new QPushButton;Start_T20_explain= new QPushButton;
    Start_T1 = nullptr;Start_T2 = nullptr;Start_T3 = nullptr;Start_T4 = nullptr;Start_T5 = nullptr;Start_T6 = nullptr;
    Start_T7 = nullptr;Start_T8 = nullptr;Start_T9 = nullptr;Start_T10 = nullptr;Start_T11 = nullptr;Start_T12 = nullptr;
    Start_T13 = nullptr;Start_T14 = nullptr;Start_T15 = nullptr;Start_T16 = nullptr;Start_T17 = nullptr;Start_T18 = nullptr;
    Start_T19 = nullptr;Start_T20 = nullptr;

    End_T1_explain= new QPushButton;End_T2_explain= new QPushButton;End_T3_explain= new QPushButton;
    End_T4_explain= new QPushButton;End_T5_explain= new QPushButton;End_T6_explain= new QPushButton;
    End_T7_explain= new QPushButton;End_T8_explain= new QPushButton;End_T9_explain= new QPushButton;
    End_T10_explain= new QPushButton;End_T11_explain= new QPushButton;End_T12_explain= new QPushButton;
    End_T13_explain= new QPushButton;End_T14_explain= new QPushButton;End_T15_explain= new QPushButton;
    End_T16_explain= new QPushButton;End_T17_explain= new QPushButton;End_T18_explain= new QPushButton;
    End_T19_explain= new QPushButton;End_T20_explain= new QPushButton;
    End_T1 = nullptr;End_T2 = nullptr;End_T3 = nullptr;End_T4 = nullptr;End_T5 = nullptr;End_T6 = nullptr;
    End_T7 = nullptr;End_T8 = nullptr;End_T9 = nullptr;End_T10 = nullptr;End_T11 = nullptr;End_T12 = nullptr;
    End_T13 = nullptr;End_T14 = nullptr;End_T15 = nullptr;End_T16 = nullptr;End_T17 = nullptr;End_T18 = nullptr;
    End_T19 = nullptr;End_T20 = nullptr;

    State1_explain= new QPushButton;State2_explain= new QPushButton;State3_explain= new QPushButton;
    State4_explain= new QPushButton;State5_explain= new QPushButton;State6_explain= new QPushButton;
    State7_explain= new QPushButton;State8_explain= new QPushButton;State9_explain= new QPushButton;
    State10_explain= new QPushButton;State11_explain= new QPushButton;State12_explain= new QPushButton;
    State13_explain= new QPushButton;State14_explain= new QPushButton;State15_explain= new QPushButton;
    State16_explain= new QPushButton;State17_explain= new QPushButton;State18_explain= new QPushButton;
    State19_explain= new QPushButton;State20_explain= new QPushButton;
    State1 = nullptr;State2 = nullptr;State3 = nullptr;State4 = nullptr;State5 = nullptr;State6 = nullptr;
    State7 = nullptr;State8 = nullptr;State9 = nullptr;State10 = nullptr;State11 = nullptr;State12 = nullptr;
    State13 = nullptr;State14 = nullptr;State15 = nullptr;State16 = nullptr;State17 = nullptr;State18 = nullptr;
    State19 = nullptr;State20 = nullptr;

    Power1_explain= new QPushButton;Power2_explain= new QPushButton;Power3_explain= new QPushButton;
    Power4_explain= new QPushButton;Power5_explain= new QPushButton;Power6_explain= new QPushButton;
    Power7_explain= new QPushButton;Power8_explain= new QPushButton;Power9_explain= new QPushButton;
    Power10_explain= new QPushButton;Power11_explain= new QPushButton;Power12_explain= new QPushButton;
    Power13_explain= new QPushButton;Power14_explain= new QPushButton;Power15_explain= new QPushButton;
    Power16_explain= new QPushButton;Power17_explain= new QPushButton;Power18_explain= new QPushButton;
    Power19_explain= new QPushButton;Power20_explain= new QPushButton;
    Power1 = nullptr;Power2 = nullptr;Power3 = nullptr;Power4 = nullptr;Power5 = nullptr;Power6 = nullptr;
    Power7 = nullptr;Power8 = nullptr;Power9 = nullptr;Power10 = nullptr;Power11 = nullptr;Power12 = nullptr;
    Power13 = nullptr;Power14 = nullptr;Power15 = nullptr;Power16 = nullptr;Power17 = nullptr;Power18 = nullptr;
    Power19 = nullptr;Power20 = nullptr;

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
    Manufacturer_name = nullptr;
    MonitoringVersion = nullptr;
    SysProtocol_Version = nullptr;
    ConverterVersion = nullptr;
    CPLD_Version = nullptr;
    SN = nullptr;
    /***************************高级设置**********************************/
    AdvancedSetup_btn = new QPushButton;                //高级设置

    //功能设置
    Battery_type_explain                    = new QPushButton;
    BMS_Comm_type_explain                   = new QPushButton;
    Power_control_type_explain              = new QPushButton;
    EMS_Comm_type_explain                   = new QPushButton;
    Output_power_limit_explain              = new QPushButton;
    BAT_protocol_explain                    = new QPushButton;
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
    Battery_type = nullptr;
    BMS_Comm_type = nullptr;
    Power_control_type = nullptr;
    EMS_Comm_type = nullptr;
    Output_power_limit = nullptr;
    BAT_protocol = nullptr;
    Power_Delta = nullptr;
    Charge_power_limit = nullptr;
    Discharge_power_limit = nullptr;
    Charge_Vol_upper_Limit_delta = nullptr;
    Discharge_Vol_lower_Limit_delta = nullptr;
    Host_Address = nullptr;
    serial_port_1 = nullptr;
    serial_port_2 = nullptr;
    serial_port_3 = nullptr;
    serial_port_4 = nullptr;
    serial_port_5 = nullptr;
    Can_port_1 = nullptr;
    Can_port_2 = nullptr;
    ProtocolVersion = nullptr;
    UserPassPort = nullptr;
    RootPassport = nullptr;
    Language = nullptr;
    System_upgrade = nullptr;
    Sounds = nullptr;

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
    Change_rate_of_power = nullptr;
    Grid_frequency_upper_limit = nullptr;
    Grid_frequency_lower_limit = nullptr;
    Vol_protection_upper_limit = nullptr;
    Vol_protection_lower_limit = nullptr;
    HVRT_enable = nullptr;
    LVRT_enable = nullptr;
    AFD_enable = nullptr;
    Insulation_detection_enable = nullptr;
    PrimaryFreq_enable = nullptr;
    Inertia_enable = nullptr;
    CV_parallel = nullptr;
    Machine_type = nullptr;
    Machine_capacity = nullptr;
    Output_Fre_grade = nullptr;
    Output_vol_level = nullptr;
    Converter_side_vol_level = nullptr;
    Output_reactive_power_mode = nullptr;
    Grid_connected_mode_of_Inv = nullptr;
    Primary_FM_dead_zone = nullptr;
    PFM_coeff = nullptr;
    Grid_recover_time = nullptr;
    DynamicCap = nullptr;
    Module_Number = nullptr;
    Restore_factory = nullptr;
    Clear_Data = nullptr;

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
    PCS_vol_AB = nullptr;
    PCS_vol_BC = nullptr;
    PCS_vol_CA = nullptr;
    PCS_cur_A = nullptr;
    PCS_cur_B = nullptr;
    PCS_cur_C = nullptr;
    PCS_act_P = nullptr;
    PCS_rea_P = nullptr;
    PCS_par_P = nullptr;
    PCS_Pf = nullptr;
    PCS_Bat_vol = nullptr;
    PCS_Bat_cur = nullptr;
    PCS_Bat_P = nullptr;
    PCS_Bus_vol = nullptr;
    PCS_IGBT_T = nullptr;
    PCS_Env_T = nullptr;

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
    Grid_vol_AB = nullptr;
    Grid_vol_BC = nullptr;
    Grid_vol_CA = nullptr;
    Grid_cur_A = nullptr;
    Grid_cur_B = nullptr;
    Grid_cur_C = nullptr;
    Grid_act_P = nullptr;
    Grid_rea_P = nullptr;
    Grid_app_P = nullptr;
    Grid_fre = nullptr;
    Grid_Pf = nullptr;

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
    Load_vol_AB = nullptr;
    Load_vol_BC = nullptr;
    Load_vol_CA = nullptr;
    Load_cur_A = nullptr;
    Load_cur_B = nullptr;
    Load_cur_C = nullptr;
    Load_act_P = nullptr;
    Load_rea_P = nullptr;
    Load_app_P = nullptr;
    Load_Pf = nullptr;

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
    DC_input_Breaker = nullptr;
    DC_Cont = nullptr;
    Output_Cont = nullptr;
    Output_Breaker = nullptr;
    Grid_Cont = nullptr;
    Grid_Breaker = nullptr;
    MB_Breaker = nullptr;
    converter_available = nullptr;
    DC_Soft_start = nullptr;
    converter_status = nullptr;
    Reactive_P_Regulation = nullptr;
    LVRT = nullptr;
    Generator_signal = nullptr;
    Reserve = nullptr;
    Reserve2 = nullptr;
    EPO_Cont_signal1 = nullptr;
    EPO_Cont_signal2 = nullptr;
    Access_signal = nullptr;
    Full_P_signal = nullptr;
    Smoke_alarm_signal = nullptr;
    Hight_temp_signal = nullptr;

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
    PCS_Data_Tab();//变流器实时数据
    Grid_Data_Tab();//电网实时数据
    Load_Data_Tab();//负载实时数据
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

    Information_tbnt_released();/*系统-系统消息*/
}

void MEGAWin::RecordPage()
{
    History_tab();//历史记录表
    OperationLog_tab();//操作日志表
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
 * 参数设置表初始化
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
    QStringList table_h_headers;
    table_h_headers.clear();
    table_h_headers << tr("Level") << tr("Start Time") << tr("End Time") << tr("Description");
    ui->Historicalfailure_tableWidget->setColumnCount(table_h_headers.size());
    ui->Historicalfailure_tableWidget->setRowCount(8);
    ui->Historicalfailure_tableWidget->setHorizontalHeaderLabels(table_h_headers);
    ui->Historicalfailure_tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->Historicalfailure_tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->Historicalfailure_tableWidget->setStyleSheet("selection-background-color:lightblue;");
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

    History();//历史记录
}

void MEGAWin::OperationLog_tab()
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
    ui->Operation_tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->Operation_tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->Operation_tableWidget->setStyleSheet("selection-background-color:lightblue;");

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

    AutoOperation();//自动运行 绘制button

}
/******************************************************************************
 * 变流器实时数据表初始化
 * ***************************************************************************/
void MEGAWin::PCS_Data_Tab()
{
//    ui->Converter_Tab->clearContents();
    QStringList Converter_Tablist1;
    Converter_Tablist1  << tr("PCS voltage(AB)") << tr("PCS voltage(BC)") << tr("PCS voltage(CA)")
                        << tr("PCS current(A)") << tr("PCS current(B)")<< tr("PCS current(C)")
                        << tr("PCS Active P.") << tr("PCS Reactive P.") << tr("PCS Parent P.") << tr("PCS Pf");
    QStringList Converter_Tablist2;
    Converter_Tablist2  << tr("Battery voltage") << tr("Battery current") << tr("Battery power")
                        << tr("Bus voltage") << tr("IGBT temperature")
                        << tr("Environment temperature");

    ui->Converter_Tab->setColumnCount(4);
    ui->Converter_Tab->setRowCount(Converter_Tablist1.size());

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

    PCS_Data();//PCS数据 绘制button
}
/******************************************************************************
 * 电网实时数据表初始化
 * ***************************************************************************/
void MEGAWin::Grid_Data_Tab()
{
//    ui->Grid_Tab->clearContents();

    QStringList Grid_Tablist;
    Grid_Tablist << tr("Grid voltage(AB)") << tr("Grid voltage(BC)") << tr("Grid voltage(CA)")
                    << tr("Grid current(A)") << tr("Grid current(B)")<< tr("Grid current(C)")
                    << tr("Grid active power") << tr("Grid reactive power")
                     << tr("Grid apparent power") << tr("Grid frequency") << tr("Grid power factor");
    ui->Grid_Tab->setColumnCount(2);
    ui->Grid_Tab->setRowCount(Grid_Tablist.size());


    //设置表格背景颜色
    QPalette pal;
    pal.setColor(QPalette::Base, QColor(255, 0, 0));
    pal.setColor(QPalette::AlternateBase, QColor(100, 149, 237));

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

    Grid_Data();//电网数据 绘制button
}
/******************************************************************************
 * 负载实时数据表初始化
 * ***************************************************************************/
void MEGAWin::Load_Data_Tab()
{
//    ui->Load_Tab->clearContents();
    QStringList Load_Tablist;
    Load_Tablist << tr("Load voltage(AB)") << tr("Load voltage(BC)") << tr("Load voltage(CA)")
                        << tr("Load current(A)") << tr("Load current(B)")<< tr("Load current(C)")
                        << tr("Load active power") << tr("Load reactive power")
                        << tr("Load apparent power") << tr("Load power fator");
    ui->Load_Tab->setColumnCount(2);
    ui->Load_Tab->setRowCount(Load_Tablist.size());
    //设置表格背景颜色
    QPalette pal;
    pal.setColor(QPalette::Base, QColor(255, 0, 0));
    pal.setColor(QPalette::AlternateBase, QColor(100, 149, 237));

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

    Load_Data();//负载数据 绘制button
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
 * 系统信息
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

    RunStatePage();//重新加载实时数据的UI

    SystemSettingPage();//重新加载系统的UI

    RecordPage();//重新加载记录的UI

    SystemParam_tbnt_released();//重新加载高级设置的UI
}

/***************************************************************
 * 高级设置表初始化
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

    RecordPage();//记录页面初始化

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
        QMessageBox::question(this, tr("Discharge Day")\
                              ,tr("The discharge quantity of the day is shown here; Click here to jump to a histogram of daily charge and discharge, with the horizontal axis in days and the vertical axis in power (kWh)The discharge quantity of the day is shown here; Click here to jump to a histogram of daily charge and discharge, with the horizontal axis in days and the vertical axis in power (kWh)."), tr("OK"));
        break;
    case 1:
        QMessageBox::question(this, tr("Discharge Month")\
                              ,tr("This shows the discharge amount of this month. Click here to jump to the histogram of monthly charge and discharge amount. The horizontal axis is in month and the vertical axis is in power (kWh)."), tr("OK"));
        break;
    case 2:
        QMessageBox::question(this, tr("Discharge Year")\
                              ,tr("This shows the discharge amount of this year. Click here to jump to the histogram of the annual charge and discharge amount. The horizontal axis is in year, and the vertical axis is in power (kWh)."), tr("OK"));
        break;
    case 3:
        QMessageBox::question(this, tr("Discharge Total")\
                              ,tr("The total discharge power is displayed here. Click here to jump to the overview chart."), tr("OK"));
        break;
    case 4:
        QMessageBox::question(this, tr("Charge Day")\
                              ,tr("Here shows the charge of the day; Click here to jump to a histogram of daily charge and discharge, with the horizontal axis in days and the vertical axis in power (kWh)."), tr("OK"));
        break;
    case 5:
        QMessageBox::question(this, tr("Charge Month")\
                              ,tr("This shows the amount of charging in this month. Click here to jump to the histogram of monthly charging and discharging. The horizontal axis is in month and the vertical axis is in power (kWh)."), tr("OK"));
        break;
    case 6:
        QMessageBox::question(this, tr("Charge Year")\
                              ,tr("This shows the amount of charging for this year. Click here to jump to the histogram of charging and discharging for each year. The horizontal axis is in years and the vertical axis is in power (kWh)."), tr("OK"));
        break;
    case 7:
        QMessageBox::question(this, tr("Charge Total")\
                              ,tr("This shows the total amount of charging, click here to jump to the overview chart."), tr("OK"));
        break;
    case 8:
        QMessageBox::question(this, tr("Month-")\
                              ,tr("To view the data of the previous month, click on it to display the data of the previous month of the current displayed month."), tr("OK"));
        break;
    case 9:
        QMessageBox::question(this, tr("Year-")\
                              ,tr("To view the previous year's data, click on it to display the previous year's data for the current displayed year."), tr("OK"));
        break;
    case 10:
        QMessageBox::question(this, tr("Daily electricity quantity")\
                              ,tr("To view the daily charge and discharge volume, click here to jump to the histogram of daily charge and discharge volume. The horizontal axis is in day, and the vertical axis is in power (kWh)."), tr("OK"));
        break;
    case 11:
        QMessageBox::question(this, tr("Annual electricity quantity")\
                              ,tr("To view the annual charge and discharge volume, click here to jump to the histogram of the annual charge and discharge volume, the horizontal axis is in year, and the vertical axis is in power (kWh)."), tr("OK"));
        break;
    case 12:
        QMessageBox::question(this, tr("Month+")\
                              ,tr("To view the data for the next month, click to display the data for the next month of the current displayed month."), tr("OK"));
        break;
    case 13:
        QMessageBox::question(this, tr("Year+")\
                              ,tr("To view the data for the next year, click on it to display the data for the next year of the current displayed year."), tr("OK"));
        break;
    case 14:
        QMessageBox::question(this, tr("Monthly electric quantity")\
                              ,tr("To view the monthly charge and discharge volume, click here to jump to the histogram of monthly charge and discharge volume. The horizontal axis is in month, and the vertical axis is in power (kWh)."), tr("OK"));
        break;
    case 15:
        QMessageBox::question(this, tr("Total electric quantity")\
                              ,tr("To view the total charge and discharge, click here to jump to the overview chart."), tr("OK"));
        break;
    case 16:
        QMessageBox::question(this, tr("HistoricalFailure")\
                              ,tr("To export history records, click here to export history records to the USB flash drive. The file exported to the USB flash drive is HistoryRecord.csv, which needs to be opened with Excel."), tr("OK"));
        break;
    case 17:
        QMessageBox::question(this, tr("OperationLog")\
                              ,tr("Click here to export operation logs to the USB flash drive. The Log file is Log.csv, and you need to open the file using Excel."), tr("OK"));
        break;
    case 18:
        QMessageBox::question(this, tr("Coulombmeter report")\
                              ,tr("To export the battery table, click here to export the battery table to the USB flash drive. The file exported to the USB flash drive is Report.csv, which needs to be opened with Excel."), tr("OK"));
        break;
    case 19:
        QMessageBox::question(this, tr("Eject Udisk")\
                              ,tr("Exit the U disk and unmount the U disk mounted to the display control to ensure that the data in the U disk will not be damaged."), tr("OK"));
        break;
    }

}
/******************系统信息点击槽***********************/
void MEGAWin::SystemlnformationVer_clicked(int nid)
{
    switch (nid) {
    case 0:
        QMessageBox::question(this, tr("Interface")\
                              ,tr("This is the interface number, which defaults to eth0."), tr("OK"));
        break;
    case 1:
        QMessageBox::question(this, tr("Port")\
                              ,tr("This is the port number, which defaults to 502 and can be changed as needed."), tr("OK"));
        break;
    case 2:
        QMessageBox::question(this, tr("Ip")\
                              ,tr("This is the IP address. The default is 192.168.1.100."), tr("OK"));
        break;
    case 3:
        QMessageBox::question(this, tr("Netmask")\
                              ,tr("This is the subnet mask, 255.255.255.0."), tr("OK"));
        break;
    case 4:
        QMessageBox::question(this, tr("Gateway")\
                              ,tr("This is the gateway. The default is 192.168.1.1."), tr("OK"));
        break;
    case 5:
        QMessageBox::question(this, tr("Serber ip")\
                              ,tr("This is the server IP address. The default is 192.168.1.200."), tr("OK"));
        break;
    case 6:
        QMessageBox::question(this, tr("Apply and Restart system")\
                              ,tr("This is the application and restart the system. After clicking, the system will be restarted. If there is an upgrade of the monitoring screen program, the new monitoring screen program will be used after the restart."), tr("OK"));
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
            QMessageBox::question(this, tr("BMS power on")\
                          ,tr("This is battery power-on, which can give the BMS instructions to close the contactor (Note: only some BMS manufacturers support this function)."), tr("OK"));
            break;
        case 5:
            QMessageBox::question(this, tr("BMS power off")\
                          ,tr("This is the battery power off, this item can give the BMS to disconnect the contactor command (note: only some BMS manufacturers support this function)."), tr("OK"));
            break;
        default:
            break;
    }
}
/******************历史记录 绘制button***********************/
void MEGAWin::History()
{
    QString str1 = tr("0");
    QString str2 = tr("Level");
    QString str3 = tr("This is the event alarm level. When the event alarm level is 0, it is marked red, indicating that this is the fault information.");
    QString str4 = tr("Start Time");
    QString str5 = tr("This is the event start time, which means that the record started appearing at this time.");
    QString str6 = tr("End Time");
    QString str7 = tr("This is the event end time, which means the end time of this record,'... 'means no end time.");
    QString str8 = tr("CAN communication failure");
    QString str9 = tr("Description");
    QString str10 = tr("This is the event description, when there is an alarm information, the alarm information will be recorded here.");
    QString str11 = tr("Fire alarm (High temp. alarm)");
    QString str12 = tr("Power Meter Comm fualttLead-acid abnormal");

    if(Grade != nullptr)
    {
        delete Grade;
    }
    Grade = new Specification(this,Grade_explain, ui->Historicalfailure_tableWidget, 0, 0, str1, str2, str3);
    Grade->add_Specification();

    if(Grade2 != nullptr)
    {
        delete Grade2;
    }
    Grade2 = new Specification(this,Grade2_explain, ui->Historicalfailure_tableWidget, 1, 0, str1, str2, str3);
    Grade2->add_Specification();

    if(Grade2 != nullptr)
    {
        delete Grade3;
    }
    Grade3 = new Specification(this,Grade3_explain, ui->Historicalfailure_tableWidget, 2, 0, str1, str2, str3);
    Grade3->add_Specification();

    if(Grade4 != nullptr)
    {
        delete Grade4;
    }
    Grade4 = new Specification(this,Grade4_explain, ui->Historicalfailure_tableWidget, 3, 0, str1, str2, str3);
    Grade4->add_Specification();

    if(Grade5 != nullptr)
    {
        delete Grade5;
    }
    Grade5 = new Specification(this,Grade5_explain, ui->Historicalfailure_tableWidget, 4, 0, str1, str2, str3);
    Grade5->add_Specification();

    if(Grade6 != nullptr)
    {
        delete Grade6;
    }
    Grade6 = new Specification(this,Grade6_explain, ui->Historicalfailure_tableWidget, 5, 0, str1, str2, str3);
    Grade6->add_Specification();

    if(Grade7 != nullptr)
    {
        delete Grade7;
    }
    Grade7 = new Specification(this,Grade7_explain, ui->Historicalfailure_tableWidget, 6, 0, str1, str2, str3);
    Grade7->add_Specification();

    if(Grade8 != nullptr)
    {
        delete Grade8;
    }
    Grade8 = new Specification(this,Grade8_explain, ui->Historicalfailure_tableWidget, 7, 0, str1, str2, str3);
    Grade8->add_Specification();

    if(StartTime != nullptr)
    {
        delete StartTime;
    }
    StartTime = new Specification(this,StartTime_explain, ui->Historicalfailure_tableWidget, 0, 1, \
                                                    "2023.5.6 15:49:50", str4, str5);
    StartTime->add_Specification();

    if(StartTime2 != nullptr)
    {
        delete StartTime2;
    }
    StartTime2 = new Specification(this,StartTime2_explain, ui->Historicalfailure_tableWidget, 1, 1, \
                                                    "2023.5.6 15:48:18", str4, str5);
    StartTime2->add_Specification();

    if(StartTime3 != nullptr)
    {
        delete StartTime3;
    }
    StartTime3 = new Specification(this,StartTime3_explain, ui->Historicalfailure_tableWidget, 2, 1, \
                                                    "2023.5.6 15:39:3", str4, str5);
    StartTime3->add_Specification();

    if(StartTime4 != nullptr)
    {
        delete StartTime4;
    }
    StartTime4 = new Specification(this,StartTime4_explain, ui->Historicalfailure_tableWidget, 3, 1, \
                                                    "2023.5.6 15:39:3", str4, str5);
    StartTime4->add_Specification();

    if(StartTime5 != nullptr)
    {
        delete StartTime5;
    }
    StartTime5 = new Specification(this,StartTime5_explain, ui->Historicalfailure_tableWidget, 4, 1, \
                                                    "2023.5.6 15:39:3", str4, str5);
    StartTime5->add_Specification();

    if(StartTime6 != nullptr)
    {
        delete StartTime6;
    }
    StartTime6 = new Specification(this,StartTime6_explain, ui->Historicalfailure_tableWidget, 5, 1, \
                                                    "2023.5.6 15:21:56", str4, str5);
    StartTime6->add_Specification();

    if(StartTime7 != nullptr)
    {
        delete StartTime7;
    }
    StartTime7 = new Specification(this,StartTime7_explain, ui->Historicalfailure_tableWidget, 6, 1, \
                                                    "2023.5.6 15:21:38", str4, str5);
    StartTime7->add_Specification();

    if(StartTime8 != nullptr)
    {
        delete StartTime8;
    }
    StartTime8 = new Specification(this,StartTime8_explain, ui->Historicalfailure_tableWidget, 7, 1, \
                                                    "2023.5.6 15:21:38", str4, str5);
    StartTime8->add_Specification();

    if(EndTime != nullptr)
    {
        delete EndTime;
    }
    EndTime = new Specification(this,EndTime_explain, ui->Historicalfailure_tableWidget, 0, 2, "-", str6, str7);
    EndTime->add_Specification();

    if(EndTime2 != nullptr)
    {
        delete EndTime2;
    }
    EndTime2 = new Specification(this,EndTime2_explain, ui->Historicalfailure_tableWidget, 1, 2, "-", str6, str7);
    EndTime2->add_Specification();

    if(EndTime3 != nullptr)
    {
        delete EndTime3;
    }
    EndTime3 = new Specification(this,EndTime3_explain, ui->Historicalfailure_tableWidget, 2, 2, "...", str6, str7);
    EndTime3->add_Specification();

    if(EndTime4 != nullptr)
    {
        delete EndTime4;
    }
    EndTime4 = new Specification(this,EndTime4_explain, ui->Historicalfailure_tableWidget, 3, 2, "-", str6, str7);
    EndTime4->add_Specification();

    if(EndTime5 != nullptr)
    {
        delete EndTime5;
    }
    EndTime5 = new Specification(this,EndTime5_explain, ui->Historicalfailure_tableWidget, 4, 2, "...", str6, str7);
    EndTime5->add_Specification();

    if(EndTime6 != nullptr)
    {
        delete EndTime6;
    }
    EndTime6 = new Specification(this,EndTime6_explain, ui->Historicalfailure_tableWidget, 5, 2, "-", str6, str7);
    EndTime6->add_Specification();

    if(EndTime7 != nullptr)
    {
        delete EndTime7;
    }
    EndTime7 = new Specification(this,EndTime7_explain, ui->Historicalfailure_tableWidget, 6, 2, "-", str6, str7);
    EndTime7->add_Specification();

    if(EndTime8 != nullptr)
    {
        delete EndTime8;
    }
    EndTime8 = new Specification(this,EndTime8_explain, ui->Historicalfailure_tableWidget, 7, 2, "-", str6, str7);
    EndTime8->add_Specification();

    if(Describe != nullptr)
    {
        delete Describe;
    }
    Describe = new Specification(this,Describe_explain, ui->Historicalfailure_tableWidget, 0, 3, str8, str9, str10);
    Describe->add_Specification();

    if(Describe2 != nullptr)
    {
        delete Describe2;
    }
    Describe2 = new Specification(this,Describe2_explain, ui->Historicalfailure_tableWidget, 1, 3, str8, str9, str10);
    Describe2->add_Specification();

    if(Describe3 != nullptr)
    {
        delete Describe3;
    }
    Describe3 = new Specification(this,Describe3_explain, ui->Historicalfailure_tableWidget, 2, 3, str11, str9, str10);
    Describe3->add_Specification();

    if(Describe4 != nullptr)
    {
        delete Describe4;
    }
    Describe4 = new Specification(this,Describe4_explain, ui->Historicalfailure_tableWidget, 3, 3, str8, str9, str10);
    Describe4->add_Specification();

    if(Describe5 != nullptr)
    {
        delete Describe5;
    }
    Describe5 = new Specification(this,Describe5_explain, ui->Historicalfailure_tableWidget, 4, 3, str12, str9, str10);
    Describe5->add_Specification();

    if(Describe6 != nullptr)
    {
        delete Describe6;
    }
    Describe6 = new Specification(this,Describe6_explain, ui->Historicalfailure_tableWidget, 5, 3, str8, str9, str10);
    Describe6->add_Specification();

    if(Describe7 != nullptr)
    {
        delete Describe7;
    }
    Describe7 = new Specification(this,Describe7_explain, ui->Historicalfailure_tableWidget, 6, 3, str11, str9, str10);
    Describe7->add_Specification();

    if(Describe8 != nullptr)
    {
        delete Describe8;
    }
    Describe8 = new Specification(this,Describe8_explain, ui->Historicalfailure_tableWidget, 7, 3, str12, str9, str10);
    Describe8->add_Specification();
}
/******************操作日志 绘制button***********************/
void MEGAWin::OperationLog()
{
    QString str = tr("ModificationTime");
    QString str1 = tr("Time when the system Settings are modified.");
    QString str2 = tr("RecordEvent");
    QString str3 = tr("Here is a record of the operation when a change is made to the system Settings.");

    ModificationTime = new Specification(this,ModificationTime_explain, ui->Operation_tableWidget, 0, 0, \
                                                    "2023-05-12 11:32:45", str, str1);
    ModificationTime->add_Specification();
    ModificationTime2 = new Specification(this,ModificationTime2_explain, ui->Operation_tableWidget, 1, 0, \
                                                    "2023-05-12 11:32:33", str, str1);
    ModificationTime2->add_Specification();
    ModificationTime3 = new Specification(this,ModificationTime3_explain, ui->Operation_tableWidget, 2, 0, \
                                                    "2023-05-11 19:29:24", str, str1);
    ModificationTime3->add_Specification();
    ModificationTime4 = new Specification(this,ModificationTime4_explain, ui->Operation_tableWidget, 3, 0, \
                                                    "2023-05-11 19:29:21", str, str1);
    ModificationTime4->add_Specification();
    ModificationTime5 = new Specification(this,ModificationTime5_explain, ui->Operation_tableWidget, 4, 0, \
                                                    "2023-05-11 19:29:10", str, str1);
    ModificationTime5->add_Specification();
    ModificationTime6 = new Specification(this,ModificationTime6_explain, ui->Operation_tableWidget, 5, 0, \
                                                    "2023-05-11 19:29:07", str, str1);
    ModificationTime6->add_Specification();
    ModificationTime7 = new Specification(this,ModificationTime7_explain, ui->Operation_tableWidget, 6, 0, \
                                                    "2023-05-11 17:21:16", str, str1);
    ModificationTime7->add_Specification();
    ModificationTime8 = new Specification(this,ModificationTime8_explain, ui->Operation_tableWidget, 7, 0, \
                                                    "2023-05-11 11:21:02", str, str1);
    ModificationTime8->add_Specification();
    ModificationTime9 = new Specification(this,ModificationTime9_explain, ui->Operation_tableWidget, 8, 0, \
                                                    "2023-05-11 11:20:58", str, str1);
    ModificationTime9->add_Specification();
    ModificationTime10 = new Specification(this,ModificationTime10_explain, ui->Operation_tableWidget, 9, 0, \
                                                    "2023-05-11 11:02:22", str, str1);
    ModificationTime10->add_Specification();
    ModificationTime11 = new Specification(this,ModificationTime11_explain, ui->Operation_tableWidget, 10, 0, \
                                                    "2023-05-11 11:02:18", str,  str1);
    ModificationTime11->add_Specification();
    ModificationTime12 = new Specification(this,ModificationTime12_explain, ui->Operation_tableWidget, 11, 0, \
                                                    "2023-05-11 11:02:14", str, str1);
    ModificationTime12->add_Specification();
    EventRecord = new Specification(this,EventRecord_explain, ui->Operation_tableWidget, 0, 1, \
                                                    tr("Power control type：CP_P->CP_N&&P"), str2, str3);
    EventRecord->add_Specification();
    EventRecord2 = new Specification(this,EventRecord2_explain, ui->Operation_tableWidget, 1, 1, \
                                                    tr("Power control type：CP_N&&P->CP_P"), str2, str3);
    EventRecord2->add_Specification();
    EventRecord3 = new Specification(this,EventRecord3_explain, ui->Operation_tableWidget, 2, 1, \
                                                    tr("Grid Fre Upper limit：0.2->3"), str2, str3);
    EventRecord3->add_Specification();
    EventRecord4 = new Specification(this,EventRecord4_explain, ui->Operation_tableWidget, 3, 1, \
                                                    tr("Grid Fre Upper limit：3->0.2"), str2, str3);
    EventRecord4->add_Specification();
    EventRecord5 = new Specification(this,EventRecord5_explain, ui->Operation_tableWidget, 4, 1, \
                                                    tr("Voltage protection Lower limit：-10->-15"), str2, str3);
    EventRecord5->add_Specification();
    EventRecord6 = new Specification(this,EventRecord6_explain, ui->Operation_tableWidget, 5, 1, \
                                                    tr("Voltage protection Lower limit：-15->-10"), str2, str3);
    EventRecord6->add_Specification();
    EventRecord7 = new Specification(this,EventRecord7_explain, ui->Operation_tableWidget, 6, 1, \
                                                    tr("Operation mode：Prevent countercurrnet->Peak valley"), str2, str3);
    EventRecord7->add_Specification();
    EventRecord8 = new Specification(this,EventRecord8_explain, ui->Operation_tableWidget, 7, 1, \
                                                    tr("Operation mode：Peak valley->Manual"), str2, str3);
    EventRecord8->add_Specification();
    EventRecord9 = new Specification(this,EventRecord9_explain, ui->Operation_tableWidget, 8, 1, \
                                                    tr("Operation mode：Manual->UPS"), str2, str3);
    EventRecord9->add_Specification();
    EventRecord10 = new Specification(this,EventRecord10_explain, ui->Operation_tableWidget, 9, 1, \
                                                    tr("Operation mode：UPS->Prevent countercurrnet"), str2, str3);
    EventRecord10->add_Specification();
    EventRecord11 = new Specification(this,EventRecord11_explain, ui->Operation_tableWidget, 10, 1, \
                                                    tr("Inv ON/Off-Grid：Off->automatic"), str2, str3);
    EventRecord11->add_Specification();
    EventRecord12 = new Specification(this,EventRecord12_explain, ui->Operation_tableWidget, 11, 1, \
                                                    tr("Inv ON/Off-Grid：automatic->Off"), str2, str3);
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
        QMessageBox::question(this, tr("Bat volage")\
                              ,tr("This is the total battery pressure of the battery pack uploaded from the BMS via the CAN/485/TCP communication protocol."), tr("OK"));
        break;
    case 1:
        QMessageBox::question(this, tr("Bat current")\
                              ,tr("This is the total current of the battery pack uploaded from the BMS via the CAN/485/TCP communication protocol."), tr("OK"));
        break;
    case 2:
        QMessageBox::question(this, tr("SOC")\
                              ,tr("This is the SOC of the battery pack uploaded from the BMS via the CAN/485/TCP communication protocol, that is, the percentage of the current battery remaining."), tr("OK"));
        break;
    case 3:
        QMessageBox::question(this, tr("SOH")\
                              ,tr("This is the SOH of the battery pack uploaded from the BMS through the CAN/485/TCP communication protocol, the percentage of the current capacity of the battery pack to the factory capacity, that is, the health of the battery."), tr("OK"));
        break;
    case 4:
        QMessageBox::question(this, tr("Cell voltage(max)")\
                              ,tr("This is the maximum voltage of the cell uploaded from the BMS via the CAN/485/TCP communication protocol, that is, the maximum voltage of all cell cells at present."), tr("OK"));
        break;
    case 5:
        QMessageBox::question(this, tr("Cell voltage(min)")\
                              ,tr("This is the lowest voltage of the cell uploaded from the BMS via the CAN/485/TCP communication protocol, that is, the lowest voltage of all battery cells at present."), tr("OK"));
        break;
    case 6:
        QMessageBox::question(this, tr("Cell temp.(max)")\
                              ,tr("This is the highest temperature of the cell uploaded from the BMS via the CAN/485/TCP communication protocol, that is, the highest temperature of all battery cells at present."), tr("OK"));
        break;
    case 7:
        QMessageBox::question(this, tr("Cell temp.(min)")\
                              ,tr("This is the lowest temperature of the cell uploaded from the BMS via the CAN/485/TCP communication protocol, that is, the lowest temperature of all battery cells at present."), tr("OK"));
        break;
    case 8:
        QMessageBox::question(this, tr("Charging current limite")\
                              ,tr("This is the upper limit of the charging current uploaded from the BMS via the CAN/485/TCP communication protocol, the maximum charging current allowed by the current battery pack (Note: when charging the end, PCS will limit the current according to the actual current)."), tr("OK"));
        break;
    case 9:
        QMessageBox::question(this, tr("Discharging current limite")\
                              ,tr("This is the upper limit of the discharge current uploaded from the BMS via the CAN/485/TCP communication protocol, the maximum discharge current allowed by the current battery pack."), tr("OK"));
        break;
    case 10:
        QMessageBox::question(this, tr("Allow charge power")\
                              ,tr("This is the rechargeable power uploaded from the BMS through the CAN/485 communication protocol. The charging power of the battery cannot exceed this limit value."), tr("OK"));
        break;
    case 11:
        QMessageBox::question(this, tr("Allow discharge power")\
                              ,tr("This is the discharge power uploaded from the BMS using the CAN/485 communication protocol. The discharge power of the battery cannot exceed this limit."), tr("OK"));
        break;
    case 12:
        QMessageBox::question(this, tr("Allow charge energy")\
                              ,tr("This is the allowable charge amount uploaded from the BMS via the CAN/485/TCP communication protocol, the capacity of the current battery pack allowed to charge (Note: only some BMS will provide this value)."), tr("OK"));
        break;
    case 13:
        QMessageBox::question(this, tr("Allow discharge energy")\
                              ,tr("This is the allowable discharge from the BMS via the CAN/485/TCP communication protocol, the current capacity of the battery pack allowed to discharge (Note: only some BMS will provide this value)."), tr("OK"));
        break;
    case 14:
        QMessageBox::question(this, tr("Alarm level")\
                              ,tr("This is the alarm level icon. The color is changed according to the alarm level uploaded by the BMS. The alarm level is green for normal alarms, yellow for primary alarms, orange for secondary alarms, and red for tertiary alarms.If the alarm is Level 1 or Level 2, PCS does not respond.If the alarm is Level 3, the PCS shuts down."), tr("OK"));
        break;
    case 15:
        QMessageBox::question(this, tr("Charge enable")\
                              ,tr("This is the current battery status uploaded by BMS via CAN/485/TCP. Enable indicates that the battery can be charged. Disable indicates that the battery cannot be charged."), tr("OK"));
        break;
    case 16:
        QMessageBox::question(this, tr("Discharge enable")\
                              ,tr("This is the current state of the battery uploaded by the BMS via the CAN/485/TCP protocol. Enable indicates that the battery can be discharged. Disable indicates that the battery cannot be discharged."), tr("OK"));
        break;
    default:
        break;
    }
}
/*********PCS数据 绘制button**********/
void MEGAWin::PCS_Data()
{
    if(PCS_vol_AB != nullptr)
    {
        delete PCS_vol_AB;
    }
    PCS_vol_AB = new Specification(this,PCS_vol_AB_explain, ui->Converter_Tab, 0, 1, \
                                            tr("270.2V"), tr("PCS voltage(AB)"), \
                                            tr("The inverter side voltage of the current PCS is the phase voltage between phase A and phase B."));
    PCS_vol_AB->add_Specification();

    if(PCS_vol_BC != nullptr)
    {
        delete PCS_vol_BC;
    }
    PCS_vol_BC = new Specification(this,PCS_vol_BC_explain, ui->Converter_Tab, 1, 1, \
                                            tr("270V"), tr("PCS voltage(BC)"), \
                                            tr("The inverter side voltage of the current PCS is the phase voltage between phase B and phase C."));
    PCS_vol_BC->add_Specification();

    if(PCS_vol_CA != nullptr)
    {
        delete PCS_vol_CA;
    }
    PCS_vol_CA = new Specification(this,PCS_vol_CA_explain, ui->Converter_Tab, 2, 1, \
                                            tr("270.1V"), tr("PCS voltage(CA)"), \
                                            tr("The inverter side voltage of the current PCS is the phase voltage between phase A and phase C."));
    PCS_vol_CA->add_Specification();

    if(PCS_cur_A != nullptr)
    {
        delete PCS_cur_A;
    }
    PCS_cur_A = new Specification(this,PCS_cur_A_explain, ui->Converter_Tab, 3, 1, \
                                            tr("0A"), tr("PCS current(A)"), \
                                            tr("The current of the inverter side of the current PCS is the current of phase A."));
    PCS_cur_A->add_Specification();

    if(PCS_cur_B != nullptr)
    {
        delete PCS_cur_B;
    }
    PCS_cur_B = new Specification(this,PCS_cur_B_explain, ui->Converter_Tab, 4, 1, \
                                            tr("0A"), tr("PCS current(B)"), \
                                            tr("The current of the inverter side of the current PCS is the current of phase B."));
    PCS_cur_B->add_Specification();

    if(PCS_cur_C != nullptr)
    {
        delete PCS_cur_C;
    }
    PCS_cur_C = new Specification(this,PCS_cur_C_explain, ui->Converter_Tab, 5, 1, \
                                            tr("0A"), tr("PCS current(C)"), \
                                            tr("The current of the inverter side of the current PCS is the current of phase C."));
    PCS_cur_C->add_Specification();

    if(PCS_act_P != nullptr)
    {
        delete PCS_act_P;
    }
    PCS_act_P = new Specification(this,PCS_act_P_explain, ui->Converter_Tab, 6, 1, \
                                            tr("0kW"), tr("PCS Active Power"), \
                                            tr("The active power P of the inverter side of the current PCS."));
    PCS_act_P->add_Specification();

    if(PCS_rea_P != nullptr)
    {
        delete PCS_rea_P;
    }
    PCS_rea_P = new Specification(this,PCS_rea_P_explain, ui->Converter_Tab, 7, 1, \
                                            tr("0kVar"), tr("PCS Reactive Power"), \
                                            tr("The reactive power Q of the inverter side of the current PCS."));
    PCS_rea_P->add_Specification();

    if(PCS_par_P != nullptr)
    {
        delete PCS_par_P;
    }
    PCS_par_P = new Specification(this,PCS_par_P_explain, ui->Converter_Tab, 8, 1, \
                                            tr("0kVA"), tr("PCS Parent Power"), \
                                            tr("The inverter side view of the current PCS is at power S, S= √((P^2+Q^2))."));
    PCS_par_P->add_Specification();

    if(PCS_Pf != nullptr)
    {
        delete PCS_Pf;
    }

    PCS_Pf = new Specification(this,PCS_Pf_explain, ui->Converter_Tab, 9, 1, \
                                            tr("0"), tr("PCS Power factor"), \
                                            tr("Power factor Pf on the inverter side of current PCS, Pf = P/S."));
    PCS_Pf->add_Specification();

    if(PCS_Bat_vol != nullptr)
    {
        delete PCS_Bat_vol;
    }
    PCS_Bat_vol = new Specification(this,PCS_Bat_vol_explain, ui->Converter_Tab, 0, 3, \
                                            tr("0V"), tr("PCS Battery voltage"), \
                                            tr("The current PCS samples the battery voltage from the connected battery."));
    PCS_Bat_vol->add_Specification();

    if(PCS_Bat_cur != nullptr)
    {
        delete PCS_Bat_cur;
    }
    PCS_Bat_cur = new Specification(this,PCS_Bat_cur_explain, ui->Converter_Tab, 1, 3, \
                                            tr("0A"), tr("PCS Battery current"), \
                                            tr("Battery current sampled by the PCS from the connected battery."));
    PCS_Bat_cur->add_Specification();

    if(PCS_Bat_P != nullptr)
    {
        delete PCS_Bat_P;
    }
    PCS_Bat_P = new Specification(this,PCS_Bat_P_explain, ui->Converter_Tab, 2, 3, \
                                            tr("0kW"), tr("PCS Battery power"), \
                                            tr("At present, PCS calculates the product of battery voltage and battery current to obtain battery power."));
    PCS_Bat_P->add_Specification();

    if(PCS_Bus_vol != nullptr)
    {
        delete PCS_Bus_vol;
    }
    PCS_Bus_vol = new Specification(this,PCS_Bus_vol_explain, ui->Converter_Tab, 3, 3, \
                                            tr("0V"), tr("PCS Bus voltage"), \
                                            tr("The current bus voltage sampled by PCS from the bus side."));
    PCS_Bus_vol->add_Specification();

    if(PCS_IGBT_T != nullptr)
    {
        delete PCS_IGBT_T;
    }
    PCS_IGBT_T = new Specification(this,PCS_IGBT_T_explain, ui->Converter_Tab, 4, 3, \
                                            tr("39℃"), tr("PCS IGBT temperature"), \
                                            tr("The current IGBT temperature of PCS shall not exceed 105℃, otherwise PCS will run derated."));
    PCS_IGBT_T->add_Specification();

    if(PCS_Env_T != nullptr)
    {
        delete PCS_Env_T;
    }
    PCS_Env_T = new Specification(this,PCS_Env_T_explain, ui->Converter_Tab, 5, 3, \
                                            tr("25℃"), tr("PCS Environment temperature"), \
                                            tr("The ambient temperature of the current PCS."));
    PCS_Env_T->add_Specification();
}
/*********电网数据 绘制button**********/
void MEGAWin::Grid_Data()
{
    if(Grid_vol_AB != nullptr)
    {
        delete Grid_vol_AB;
    }
    Grid_vol_AB = new Specification(this,Grid_vol_AB_explain, ui->Grid_Tab, 0, 1, \
                                            tr("0V"), tr("Grid voltage(AB)"), \
                                            tr("The grid side voltage of the current PCS, this item is the phase voltage between phase A and phase B."));
    Grid_vol_AB->add_Specification();

    if(Grid_vol_BC != nullptr)
    {
        delete Grid_vol_BC;
    }
    Grid_vol_BC = new Specification(this,Grid_vol_BC_explain, ui->Grid_Tab, 1, 1, \
                                            tr("0V"), tr("Grid voltage(BC)"), \
                                            tr("The grid side voltage of the current PCS, this item is the phase voltage between phase B and phase C."));
    Grid_vol_BC->add_Specification();

    if(Grid_vol_CA != nullptr)
    {
        delete Grid_vol_CA;
    }
    Grid_vol_CA = new Specification(this,Grid_vol_CA_explain, ui->Grid_Tab, 2, 1, \
                                            tr("0V"), tr("Grid voltage(CA)"), \
                                            tr("The grid side voltage of the current PCS, this item is the phase voltage between phase A and phase C."));
    Grid_vol_CA->add_Specification();

    if(Grid_cur_A != nullptr)
    {
        delete Grid_cur_A;
    }
    Grid_cur_A = new Specification(this,Grid_cur_A_explain, ui->Grid_Tab, 3, 1, \
                                            tr("0A"), tr("Grid current(A)"), \
                                            tr("The current on the grid side of PCS, this item is the current of phase A."));
    Grid_cur_A->add_Specification();

    if(Grid_cur_B != nullptr)
    {
        delete Grid_cur_B;
    }
    Grid_cur_B = new Specification(this,Grid_cur_B_explain, ui->Grid_Tab, 4, 1, \
                                            tr("0A"), tr("Grid current(B)"), \
                                            tr("The current on the grid side of PCS, this item is the current of phase B."));
    Grid_cur_B->add_Specification();

    if(Grid_cur_C != nullptr)
    {
        delete Grid_cur_C;
    }
    Grid_cur_C = new Specification(this,Grid_cur_C_explain, ui->Grid_Tab, 5, 1, \
                                            tr("0A"), tr("Grid current(C)"), \
                                            tr("The current on the grid side of PCS, this item is the current of phase C."));
    Grid_cur_C->add_Specification();

    if(Grid_act_P != nullptr)
    {
        delete Grid_act_P;
    }
    Grid_act_P = new Specification(this,Grid_act_P_explain, ui->Grid_Tab, 6, 1, \
                                            tr("0kW"), tr("Grid active power"), \
                                            tr("Current active power (P) on the grid side of PCS."));
    Grid_act_P->add_Specification();

    if(Grid_rea_P != nullptr)
    {
        delete Grid_rea_P;
    }
    Grid_rea_P = new Specification(this,Grid_rea_P_explain, ui->Grid_Tab, 7, 1, \
                                            tr("0kVar"), tr("Grid reactive power"), \
                                            tr("Current reactive power (Q) on the grid side of PCS."));
    Grid_rea_P->add_Specification();

    if(Grid_app_P != nullptr)
    {
        delete Grid_app_P;
    }
    Grid_app_P = new Specification(this,Grid_app_P_explain, ui->Grid_Tab, 8, 1, \
                                            tr("0kVA"), tr("Grid apparent power"), \
                                            tr("Current PCS grid side view power (S), S= √((P^2+Q^2))."));
    Grid_app_P->add_Specification();

    if(Grid_fre != nullptr)
    {
        delete Grid_fre;
    }
    Grid_fre = new Specification(this,Grid_fre_explain, ui->Grid_Tab, 9, 1, \
                                            tr("0Hz"), tr("Grid frequency"), \
                                            tr("Current PCS collection of power grid frequency."));
    Grid_fre->add_Specification();

    if(Grid_Pf != nullptr)
    {
        delete Grid_Pf;
    }
    Grid_Pf = new Specification(this,Grid_Pf_explain, ui->Grid_Tab, 10, 1, \
                                            tr("0"), tr("Grid power factor"), \
                                            tr("Grid side power factor (Pf) of the current PCS, Pf = P/S."));
    Grid_Pf->add_Specification();
}
/*********负载数据 绘制button**********/
void MEGAWin::Load_Data()
{
    if(Load_vol_AB != nullptr)
    {
        delete Load_vol_AB;
    }
    Load_vol_AB = new Specification(this,Load_vol_AB_explain, ui->Load_Tab, 0, 1, \
                                            tr("0V"), tr("Load voltage(AB)"), \
                                            tr("The load side voltage of the current PCS, this item is the phase voltage between phase A and phase B."));
    Load_vol_AB->add_Specification();

    if(Load_vol_BC != nullptr)
    {
        delete Load_vol_BC;
    }
    Load_vol_BC = new Specification(this,Load_vol_BC_explain, ui->Load_Tab, 1, 1, \
                                            tr("0V"), tr("Load voltage(BC)"), \
                                            tr("The load side voltage of the current PCS, this item is the phase voltage between phase B and phase C."));
    Load_vol_BC->add_Specification();

    if(Load_vol_CA != nullptr)
    {
        delete Load_vol_CA;
    }
    Load_vol_CA = new Specification(this,Load_vol_CA_explain, ui->Load_Tab, 2, 1, \
                                            tr("0V"), tr("Load voltage(CA)"), \
                                            tr("The load side voltage of the current PCS, this item is the phase voltage between phase A and phase C."));
    Load_vol_CA->add_Specification();

    if(Load_cur_A != nullptr)
    {
        delete Load_cur_A;
    }
    Load_cur_A = new Specification(this,Load_cur_A_explain, ui->Load_Tab, 3, 1, \
                                            tr("0A"), tr("Load current(A)"), \
                                            tr("The current on the load side of PCS is the current of phase A."));
    Load_cur_A->add_Specification();

    if(Load_cur_B != nullptr)
    {
        delete Load_cur_B;
    }
    Load_cur_B = new Specification(this,Load_cur_B_explain, ui->Load_Tab, 4, 1, \
                                            tr("0A"), tr("Load current(B)"), \
                                            tr("The current at the load side of PCS is the current of phase B."));
    Load_cur_B->add_Specification();

    if(Load_cur_C != nullptr)
    {
        delete Load_cur_C;
    }
    Load_cur_C = new Specification(this,Load_cur_C_explain, ui->Load_Tab, 5, 1, \
                                            tr("0A"), tr("Load current(C)"), \
                                            tr("The current at the load side of PCS is the current of phase C."));
    Load_cur_C->add_Specification();

    if(Load_act_P != nullptr)
    {
        delete Load_act_P;
    }
    Load_act_P = new Specification(this,Load_act_P_explain, ui->Load_Tab, 6, 1, \
                                            tr("0kW"), tr("Load active power"), \
                                            tr("Current PCS active power (P) on load side."));
    Load_act_P->add_Specification();

    if(Load_rea_P != nullptr)
    {
        delete Load_rea_P;
    }
    Load_rea_P = new Specification(this,Load_rea_P_explain, ui->Load_Tab, 7, 1, \
                                            tr("0kVar"), tr("Load reactive power"), \
                                            tr("Reactive power (Q) on the load side of current PCS."));
    Load_rea_P->add_Specification();

    if(Load_app_P != nullptr)
    {
        delete Load_app_P;
    }
    Load_app_P = new Specification(this,Load_app_P_explain, ui->Load_Tab, 8, 1, \
                                            tr("0kVA"), tr("Load apparent power"), \
                                            tr("Current PCS load side view at power (S), S= √((P^2+Q^2))."));
    Load_app_P->add_Specification();

    if(Load_Pf != nullptr)
    {
        delete Load_Pf;
    }
    Load_Pf = new Specification(this,Load_Pf_explain, ui->Load_Tab, 9, 1, \
                                            tr("0"), tr("Load power factor"), \
                                            tr("The load side power factor (Pf) of the current PCS, Pf = P/S."));
    Load_Pf->add_Specification();
}
/********PCS状态 绘制button*********/
void MEGAWin::PCS_State()
{
    if(DC_input_Breaker != nullptr)
    {
        delete DC_input_Breaker;
    }
    DC_input_Breaker = new Specification(this,DC_input_Breaker_explain, ui->RTState_Bypass_Tab, 0, 1, \
                                            tr("Close"), tr("DC input Breaker"), \
                                            tr("DC input circuit breaker has three states: Break, Close, Trip; The DC input circuit breaker can only be manually disconnected. If the DC input circuit breaker overcurrent, the DC input circuit breaker may trip."));
    DC_input_Breaker->add_Specification();

    if(DC_Cont != nullptr)
    {
        delete DC_Cont;
    }
    DC_Cont = new Specification(this,DC_Cont_explain, ui->RTState_Bypass_Tab, 1, 1, \
                                            tr("Close"), tr("DC contactor"), \
                                            tr("DC contactor has two states: Break, Close; When the DC side is soft Break, the DC contactor is closed. When the DC side of the battery is disconnected, the DC bus voltage drops to a certain voltage, and the DC contactor is disconnected."));
    DC_Cont->add_Specification();

    if(Output_Cont != nullptr)
    {
        delete Output_Cont;
    }
    Output_Cont = new Specification(this,Output_Cont_explain, ui->RTState_Bypass_Tab, 2, 1, \
                                            tr("Close"), tr("Output contactor"), \
                                            tr("The output circuit breaker has three states: Break, Close, Trip; If the output circuit breaker overcurrent, the output circuit breaker will trip."));
    Output_Cont->add_Specification();

    if(Output_Breaker != nullptr)
    {
        delete Output_Breaker;
    }
    Output_Breaker = new Specification(this,Output_Breaker_explain, ui->RTState_Bypass_Tab, 3, 1, \
                                            tr("Close"), tr("Output Breaker"), \
                                            tr("The output contactor has two states: Break, Close; When the DC side soft opening is completed, the output contactor is closed; When the converter is turned off, the output contactor is disconnected."));
    Output_Breaker->add_Specification();

    if(Grid_Cont != nullptr)
    {
        delete Grid_Cont;
    }
    Grid_Cont = new Specification(this,Grid_Cont_explain, ui->RTState_Bypass_Tab, 4, 1, \
                                            tr("Close"), tr("Grid contactor"), \
                                            tr("The network contactor has two states: Break, Close; When the converter is in grid-connected mode and the grid side voltage is normal, the network contactor is closed. The converter is in off-grid mode and the network contactor is disconnected."));
    Grid_Cont->add_Specification();

    if(Grid_Breaker != nullptr)
    {
        delete Grid_Breaker;
    }
    Grid_Breaker = new Specification(this,Grid_Breaker_explain, ui->RTState_Bypass_Tab, 5, 1, \
                                            tr("Close"), tr("Grid Breaker"), \
                                            tr("The power grid circuit breaker has three states: Break, Close, Trip; The power grid circuit breaker can only be manually disconnected. If the power grid circuit breaker overflows, the power grid circuit breaker may trip."));
    Grid_Breaker->add_Specification();

    if(MB_Breaker != nullptr)
    {
        delete MB_Breaker;
    }
    MB_Breaker = new Specification(this,MB_Breaker_explain, ui->RTState_Bypass_Tab, 6, 1, \
                                            tr("Close"), tr("Maintenance Bypass Breaker"), \
                                            tr("Maintenance bypass circuit breaker has two states: Break, Close; This circuit breaker is only used for machine maintenance, if necessary, please contact the maintenance personnel."));
    MB_Breaker->add_Specification();

    if(converter_available != nullptr)
    {
        delete converter_available;
    }
    converter_available = new Specification(this,converter_available_explain, ui->RTState_Bypass_Tab, 0, 3, \
                                            tr("Disable"), tr("converter available"), \
                                            tr("The converter can be enabled in two states: Enable and Disable. When the internal self-test of the machine is no problem, the converter is enabled; Otherwise the converter is prohibited."));
    converter_available->add_Specification();

    if(DC_Soft_start != nullptr)
    {
        delete DC_Soft_start;
    }
    DC_Soft_start = new Specification(this,DC_Soft_start_explain, ui->RTState_Bypass_Tab, 1, 3, \
                                            tr("Not starting"), tr("DC Soft start"), \
                                            tr("The DC Soft boot has three states: Soft starting, complete, and Not starting. Soft start means that when the converter is started, it gradually accelerates or decelerates the device to the normal operating state by controlling the change of current or voltage, so as to reduce the current shock and voltage peak in the circuit, protect the circuit components and reduce the mechanical damage of the device. Soft start can increase device life, reduce energy consumption, and improve system efficiency."));
    DC_Soft_start->add_Specification();

    if(converter_status != nullptr)
    {
        delete converter_status;
    }
    converter_status = new Specification(this,converter_status_explain, ui->RTState_Bypass_Tab, 2, 3, \
                                            tr("Shut down"), tr("converter status"), \
                                            tr("There are eight converter states:Shut down, Soft start, Grid-ON Charge, Grid-ON Discharge, Grid-OFF Discharge, Drop and Connected,Standby, Grid-OFF Charge."));
    converter_status->add_Specification();

    if(Reactive_P_Regulation != nullptr)
    {
        delete Reactive_P_Regulation;
    }
    Reactive_P_Regulation = new Specification(this,Reactive_P_Regulation_explain, ui->RTState_Bypass_Tab, 3, 3, \
                                            tr("Disable"), tr("Reactive Power Regulation"), \
                                            tr("There are three types of reactive power regulation: Disable, Pf regulation, and Q regulation."));
    Reactive_P_Regulation->add_Specification();

    if(LVRT != nullptr)
    {
        delete LVRT;
    }
    LVRT = new Specification(this,LVRT_explain, ui->RTState_Bypass_Tab, 4, 3, \
                                            tr("LVRT"), tr("LVRT"), \
                                            tr("This is the current state of low voltage crossing (LVRT). Low voltage crossing refers to the ability to withstand a certain limit of low voltage of the grid within a certain period of time without exiting the operation. There are two states here, namely Non and LVRT."));
    LVRT->add_Specification();

    if(Generator_signal != nullptr)
    {
        delete Generator_signal;
    }
    Generator_signal = new Specification(this,Generator_signal_explain, ui->RTState_Bypass_Tab, 0, 5, \
                                            tr("Enable"), tr("Generator signal"), \
                                            tr("This is the status of the current chai signal, output dry contact 1, there are Enable and Disable two states, here is the most real physical hardware status."));
    Generator_signal->add_Specification();

    if(Reserve != nullptr)
    {
        delete Reserve;
    }
    Reserve = new Specification(this,Reserve_explain, ui->RTState_Bypass_Tab, 1, 5, \
                                            tr("Disable"), tr("Reserve"), \
                                            tr("This bit is reserved and has no effect. Dry contact 2 is output. The status of dry contact 2 is Enable(Enable) or Disable(Disable)."));
    Reserve->add_Specification();

    if(Reserve2 != nullptr)
    {
        delete Reserve2;
    }
    Reserve2 = new Specification(this,Reserve2_explain, ui->RTState_Bypass_Tab, 2, 5, \
                                            tr("Disable"), tr("Reserve2"), \
                                            tr("This bit is reserved and has no effect. Dry contact 2 is output. The status of dry contact 3 is Enable(Enable) or Disable(Disable)"));
    Reserve2->add_Specification();

    if(EPO_Cont_signal1 != nullptr)
    {
        delete EPO_Cont_signal1;
    }
    EPO_Cont_signal1 = new Specification(this,EPO_Cont_signal1_explain, ui->RTState_Bypass_Tab, 3, 5, \
                                            tr("Disable"), tr("EPO_Cont signal1"), \
                                            tr("This is signal 1 of the EPO node. Enter dry contact 1, that is, dry contact signal 1 of external shutdown. There are two states: Enable and Disable."));
    EPO_Cont_signal1->add_Specification();

    if(EPO_Cont_signal2 != nullptr)
    {
        delete EPO_Cont_signal2;
    }
    EPO_Cont_signal2 = new Specification(this,EPO_Cont_signal2_explain, ui->RTState_Bypass_Tab, 4, 5, \
                                            tr("Disable"), tr("EPO_Cont signal2"), \
                                            tr("This is signal 2 of the EPO node. Enter dry contact 2, that is, dry contact signal 2 of the external shutdown. There are two states: Enable and Disable."));
    EPO_Cont_signal2->add_Specification();

    if(Access_signal != nullptr)
    {
        delete Access_signal;
    }
    Access_signal = new Specification(this,Access_signal_explain, ui->RTState_Bypass_Tab, 5, 5, \
                                            tr("Disable"), tr("Access_signal"), \
                                            tr("This is the access signal. Enter dry contact 3. The status is Enable or Disable. The actual physical hardware status is obtained here."));
    Access_signal->add_Specification();

    if(Full_P_signal != nullptr)
    {
        delete Full_P_signal;
    }
    Full_P_signal = new Specification(this,Full_P_signal_explain, ui->RTState_Bypass_Tab, 6, 5, \
                                            tr("Disable"), tr("Full_P_signal"), \
                                            tr("This is a full power signal, the input dry contact 4 has two states of Enable and Disable, and what is obtained here is the most real physical hardware state."));
    Full_P_signal->add_Specification();

    if(Smoke_alarm_signal != nullptr)
    {
        delete Smoke_alarm_signal;
    }
    Smoke_alarm_signal = new Specification(this,Smoke_alarm_signal_explain, ui->RTState_Bypass_Tab, 7, 5, \
                                            tr("Disable"), tr("Smoke alarm signal"), \
                                            tr("This isa smoke alarm signal. Enter dry contact 5. The status is Enable or Disable. The actual physical hardware status is obtained here."));
    Smoke_alarm_signal->add_Specification();

    if(Hight_temp_signal != nullptr)
    {
        delete Hight_temp_signal;
    }
    Hight_temp_signal = new Specification(this,Hight_temp_signal_explain, ui->RTState_Bypass_Tab, 8, 5, \
                                            tr("Disable"), tr("Hight temp signal"), \
                                            tr("This isa high temperature signal. Input dry contact 6. Two states are available: Enable and Disable."));
    Hight_temp_signal->add_Specification();
}
/*********系统设置 绘制button**********/
void MEGAWin::ParameterSet()
{
    if(Grid_connected_mode != NULL)
    {
        delete Grid_connected_mode;
    }
    Grid_connected_mode = new Specification(this,Grid_connected_mode_explain, ui->System_Tab, 0, 1, \
                                            tr("automatic"), tr("Grid connected mode of PCS"), \
                                            tr("    When automatic and off-grid is selected, it will automatically identify and switch and off-grid. When the voltage on the grid side is normal, the contactor on the grid side will close, and the machine is in grid-connected mode (PQ).When the grid is out of power, the grid side contactor will be disconnected, and the machine is in off-grid mode (VF).\n   When the grid-connected mode is selected, and the grid side voltage is normal, the grid side contactor will close, and the machine is in grid-connected mode (PQ);If the power grid loses power, the machine will give an alarm warning of the power grid low voltage.\n    When off-grid mode is selected, the machine will disconnect the grid side contactor, and the machine is in off-grid mode (VF)."));
    Grid_connected_mode->add_Specification();

    if(Constant_power != NULL)
    {
        delete Constant_power;
    }
    Constant_power = new Specification(this,Constant_power_explain, ui->System_Tab, 1, 1, \
                                       tr("0"), tr("Constant power(AC)"), \
                                       tr("    This is the power setting of the AC side. The charging and discharging power of the AC side can be controlled by modifying the value of this item.When advanced Settings control power mode select constant power mode (CP_N&P), positive value indicates discharge, negative value indicates charging.\n    For example, set -5, indicating that the AC side will charge the battery with a power of -5kW, due to the loss of the inverter, the power on the DC side will be less than the power on the AC side.\n    For example, set 5, indicating that the AC side will be 5kW power output, due to the loss of the inverter, the DC side of the power will be greater than the AC side of the power."));
    Constant_power->add_Specification();

    if(Charging_and_discharging != NULL)
    {
        delete Charging_and_discharging;
    }
    Charging_and_discharging = new Specification(this,Charging_and_discharging_explain, ui->System_Tab, 2, 1, \
                                                 tr("Charge"), tr("Charging and discharging"), \
                                                 tr("Reserve."));
    Charging_and_discharging->add_Specification();

    if(Work_mode != NULL)
    {
        delete Work_mode;
    }
    Work_mode = new Specification(this,Work_mode_explain, ui->System_Tab, 3, 1, \
                                  tr("Manual"), tr("Work mode"), \
                                  tr("    When manual mode is selected (applicable to EMS remote scheduling), you can use the HMI or EMS to control the running status of the machine. Charge and discharge power (active power) Reactive power information such as the power factor.\n    When the UPS mode (backup mode) is selected, the system switches from zero power to off-grid discharge mode to provide energy for critical loads when the power grid loses power.Please go to the battery setting page to set this mode. Note: This mode is only used in lithium mode, and the communication between PCS and BMS is normal.\n    The peak-valley filling mode is used for peak-valley arbitrage. PCS can operate according to the local peak-valley electricity price period, and can go to the automatic operation page to set the charging and discharging mode charging and discharging power and other information during the operation period.\n    When the system anti-countercurrent mode is selected, the PCS in this mode is in the local power grid system, and the energy meter is connected at the entrance of the power grid. When the PCS discharges the system, if the PCS detects that there is energy flowing into the power grid in reverse direction, the PCS will actively reduce the power to prevent energy flowing into the power grid."));
    Work_mode->add_Specification();

    if(Output_power_factor != NULL)
    {
        delete Output_power_factor;
    }
    Output_power_factor = new Specification(this,Output_power_factor_explain, ui->System_Tab, 4, 1, \
                                            tr("1"), tr("Output power factor"), \
                                            tr("    The power factor Pf can be modified. The power factor is equal to the ratio of active power and reactive power. Positive value indicates reactive power lead and negative value indicates reactive power lag.\n    The power factor is a coefficient used to measure the output efficiency of electrical equipment, and the power factor is equal to the ratio of active power to reactive power. When the output reactive power factor is selected in the advanced settings 'system Settings' page, this output power factor can be modified to control the output of active power and reactive power."));
    Output_power_factor->add_Specification();

    if(Output_reactive_power != NULL)
    {
        delete Output_reactive_power;
    }
    Output_reactive_power = new Specification(this,Output_reactive_power_explain, ui->System_Tab, 5, 1, \
                                              tr("1"), tr("Output reactive power"), \
                                              tr("    This parameter can change the reactive power Q, positive value indicates reactive power lead, negative value indicates reactive power lag."));
    Output_reactive_power->add_Specification();

    if(Constant_current != NULL)
    {
        delete Constant_current;
    }
    Constant_current = new Specification(this,Constant_current_explain, ui->System_Tab, 6, 1, \
                                         tr("100"), tr("Constant current"), \
                                         tr("    When the control power mode of the advanced Settings page is set to constant current (CC), modify the constant current value, then the machine will charge and discharge the battery with the current value, positive value represents discharge, negative value represents charging."));
    Constant_current->add_Specification();

    if(Constant_voltage != NULL)
    {
        delete Constant_voltage;
    }
    Constant_voltage = new Specification(this,Constant_voltage_explain, ui->System_Tab, 7, 1, \
                                         tr("600"), tr("Constant voltage"), \
                                         tr("    When the control power mode of the Advanced Settings 'Function Settings' page is set to constant voltage (CV), modify the constant voltage value, the machine will operate at a constant voltage value, and the machine will be used as a constant voltage source."));
    Constant_voltage->add_Specification();

    if(Control_mode != NULL)
    {
        delete Control_mode;
    }
    Control_mode = new Specification(this,Control_mode_explain, ui->System_Tab, 0, 4, \
                                     tr("Local"), tr("Control mode"), \
                                     tr("    This is the control mode;If the local mode is selected, the dispatcher (EMS, RS485) can only monitor data but cannot control PCS. If the remote mode is selected,PCS parameter setting is disabled and the dispatcher (EMS,  RS485) can read and write data."));
    Control_mode->add_Specification();

    if(Machine_number != NULL)
    {
        delete Machine_number;
    }
    Machine_number = new Specification(this,Machine_number_explain, ui->System_Tab, 1, 4, \
                                       tr("Master_00"), tr("Machine number"), \
                                       tr("    This is the device number, and you can choose host(Master) or slave(Slave), where master is Master_00 and Slave_01 to Slave_08 are slaves."));
    Machine_number->add_Specification();

    if(Parallel != NULL)
    {
        delete Parallel;
    }
    Parallel = new Specification(this,Parallel_explain, ui->System_Tab, 2, 4, \
                                 tr("Disable"), tr("Parallel"), \
                                 tr("Reserve."));
    Parallel->add_Specification();

    if(Unbalance_power_enable != NULL)
    {
        delete Unbalance_power_enable;
    }
    Unbalance_power_enable = new Specification(this,Unbalance_power_enable_explain, ui->System_Tab, 3, 4, \
                                               tr("Disable"), tr("Unbalance power enable"), \
                                               tr("Reserve."));
    Unbalance_power_enable->add_Specification();

    if(Phase_A_power != NULL)
    {
        delete Phase_A_power;
    }
    Phase_A_power = new Specification(this,Phase_A_power_explain, ui->System_Tab, 4, 4, \
                                      tr("5"), tr("Phase A power"), \
                                      tr("Reserve."));
    Phase_A_power->add_Specification();

    if(Phase_B_power != NULL)
    {
        delete Phase_B_power;
    }
    Phase_B_power = new Specification(this,Phase_B_power_explain, ui->System_Tab, 5, 4, \
                                      tr("5"), tr("Phase B power"), \
                                      tr("Reserve."));
    Phase_B_power->add_Specification();

    if(Phase_C_power != NULL)
    {
        delete Phase_C_power;
    }
    Phase_C_power = new Specification(this,Phase_C_power_explain, ui->System_Tab, 6, 4, \
                                      tr("5"), tr("Phase C power"), \
                                      tr("Reserve."));
    Phase_C_power->add_Specification();

}
/***********电池设置 绘制button************/
void MEGAWin::BetterySetup()
{
    if(DOD_OnGrid != nullptr)
    {
        delete DOD_OnGrid;
    }
    DOD_OnGrid = new Specification(this,DOD_OnGrid_explain, ui->Lithum_Tab, 0, 1, \
                                     tr("90"), tr("DOD_OnGrid"), \
                                     tr("Grid-connected DOD, the depth of discharge allowed in grid-connected mode."));
    DOD_OnGrid->add_Specification();

    if(DOD_OffGrid != nullptr)
    {
        delete DOD_OffGrid;
    }
    DOD_OffGrid = new Specification(this,DOD_OffGrid_explain, ui->Lithum_Tab, 1, 1, \
                                     tr("90"), tr("DOD_OffGrid"), \
                                     tr("Off-network DOD: Discharge depth allowed in off-network mode."));
    DOD_OffGrid->add_Specification();

    if(Charge_Vol_Up_Limit != nullptr)
    {
        delete Charge_Vol_Up_Limit;
    }
    Charge_Vol_Up_Limit = new Specification(this,Charge_Vol_Up_Limit_explain, ui->Lithum_Tab, 2, 1, \
                                     tr("792"), tr("Charge_Vol_Up_Limit"), \
                                     tr("This is the upper limit of the charging voltage. When the total battery voltage reaches this value during charging, the PCS will enter the constant voltage mode to prevent the battery from overcharging."));
    Charge_Vol_Up_Limit->add_Specification();

    if(Disc_Vol_lower_Limit != nullptr)
    {
        delete Disc_Vol_lower_Limit;
    }
    Disc_Vol_lower_Limit = new Specification(this,Disc_Vol_lower_Limit_explain, ui->Lithum_Tab, 3, 1, \
                                     tr("616"), tr("Disc_Vol_lower_Limit"), \
                                     tr("This is the lower limit of the discharge voltage. When the total battery voltage during discharge reaches this value, PCS will trigger a battery low voltage alarm, and PCS will shut down to prevent battery overdischarge."));
    Disc_Vol_lower_Limit->add_Specification();

    if(Charge_Cur_Limit != nullptr)
    {
        delete Charge_Cur_Limit;
    }
    Charge_Cur_Limit = new Specification(this,Charge_Cur_Limit_explain, ui->Lithum_Tab, 4, 1, \
                                     tr("160"), tr("Charge_Cur_Limit"), \
                                     tr("This is the upper limit of charging current, which is the maximum current allowed on the DC side of PCS to prevent charging overcurrent."));
    Charge_Cur_Limit->add_Specification();

    if(Gen_turn_off_SOC != nullptr)
    {
        delete Gen_turn_off_SOC;
    }
    Gen_turn_off_SOC = new Specification(this,Gen_turn_off_SOC_explain, ui->Lithum_Tab, 5, 1, \
                                     tr("85"), tr("Gen_turn_off_SOC"), \
                                     tr("When the specified SCO value is reached, the diesel generator shuts down."));
    Gen_turn_off_SOC->add_Specification();

    if(Gen_turn_on_SOC != nullptr)
    {
        delete Gen_turn_on_SOC;
    }
    Gen_turn_on_SOC = new Specification(this,Gen_turn_on_SOC_explain, ui->Lithum_Tab, 6, 1, \
                                     tr("25"), tr("Gen_turn_on_SOC"), \
                                     tr("When the specified SOC value is reached, the diesel generator starts."));
    Gen_turn_on_SOC->add_Specification();

    if(Gen_charge_SOC != nullptr)
    {
        delete Gen_charge_SOC;
    }
    Gen_charge_SOC = new Specification(this,Gen_charge_SOC_explain, ui->Lithum_Tab, 7, 1, \
                                     tr("10"), tr("Gen_charge_SOC"), \
                                     tr("This is the diesel generator charging SOC, this parameter is used in the combined power supply mode, when the battery SOC reaches this value, the PCS starts charging."));
    Gen_charge_SOC->add_Specification();

    if(Grid_charge_SOC != nullptr)
    {
        delete Grid_charge_SOC;
    }
    Grid_charge_SOC = new Specification(this,Grid_charge_SOC_explain, ui->Lithum_Tab, 8, 1, \
                                     tr("15"), tr("Grid_charge_SOC"), \
                                     tr("This is the grid charging SOC, this parameter is used in the combined power supply mode, when the battery SOC reaches this value, the PCS starts charging."));
    Grid_charge_SOC->add_Specification();

    if(Grid_capacity != nullptr)
    {
        delete Grid_capacity;
    }
    Grid_capacity = new Specification(this,Grid_capacity_explain, ui->Lithum_Tab, 9, 1, \
                                     tr("100"), tr("Grid_capacity"), \
                                     tr("This is the power grid capacity, the maximum capacity input on the AC side of PCS, and this parameter takes effect in the combined power supply mode."));
    Grid_capacity->add_Specification();

    if(Turn_on_SOC != nullptr)
    {
        delete Turn_on_SOC;
    }
    Turn_on_SOC = new Specification(this,Turn_on_SOC_explain, ui->Lithum_Tab, 0, 4, \
                                     tr("20"), tr("Turn_on_SOC"), \
                                     tr("When UPS mode is selected and battery SOC reaches this value,PCS starts charging."));
    Turn_on_SOC->add_Specification();

    if(Turn_off_SOC != nullptr)
    {
        delete Turn_off_SOC;
    }
    Turn_off_SOC = new Specification(this,Turn_off_SOC_explain, ui->Lithum_Tab, 1, 4, \
                                     tr("50"), tr("Turn_off_SOC"), \
                                     tr("When UPS mode is selected,PCS stops charging when battery SOC reaches this value."));
    Turn_off_SOC->add_Specification();

    if(Turn_on_cell_vol != nullptr)
    {
        delete Turn_on_cell_vol;
    }
    Turn_on_cell_vol = new Specification(this,Turn_on_cell_vol_explain, ui->Lithum_Tab, 2, 4, \
                                     tr("3100"), tr("Turn_on_cell_vol"), \
                                     tr("When UPS mode is selected, the PCS starts charging when the minimum battery voltage reaches the value."));
    Turn_on_cell_vol->add_Specification();

    if(Turn_off_cell_vol != nullptr)
    {
        delete Turn_off_cell_vol;
    }
    Turn_off_cell_vol = new Specification(this,Turn_off_cell_vol_explain, ui->Lithum_Tab, 3, 4, \
                                     tr("3500"), tr("Turn_off_cell_vol"), \
                                     tr("When UPS mode is selected, PCS stops charging when the maximum battery voltage reaches this value."));
    Turn_off_cell_vol->add_Specification();

    if(Turn_on_total_vol != nullptr)
    {
        delete Turn_on_total_vol;
    }
    Turn_on_total_vol = new Specification(this,Turn_on_total_vol_explain, ui->Lithum_Tab, 4, 4, \
                                     tr("400"), tr("Turn_on_total_vol"), \
                                     tr("When the UPS mode is selected, the PCS starts charging when the total battery voltage reaches the value."));
    Turn_on_total_vol->add_Specification();

    if(Turn_off_total_vol != nullptr)
    {
        delete Turn_off_total_vol;
    }
    Turn_off_total_vol = new Specification(this,Turn_off_total_vol_explain, ui->Lithum_Tab, 5, 4, \
                                     tr("650"), tr("Turn_off_total_vol"), \
                                     tr("When UPS mode is selected, PCS stops charging when the total battery voltage reaches this value."));
    Turn_off_total_vol->add_Specification();

    if(UPS_charge_power != nullptr)
    {
        delete UPS_charge_power;
    }
    UPS_charge_power = new Specification(this,UPS_charge_power_explain, ui->Lithum_Tab, 6, 4, \
                                     tr("-1"), tr("UPS_charge_power"), \
                                     tr("When UPS mode is selected, the backup charging power of PCS is used when the battery starts charging."));
    UPS_charge_power->add_Specification();

    if(Monthly_cycle_time != nullptr)
    {
        delete Monthly_cycle_time;
    }
    Monthly_cycle_time = new Specification(this,Monthly_cycle_time_explain, ui->Lithum_Tab, 7, 4, \
                                     tr("0"), tr("Monthly_cycle_time"), \
                                     tr("On the same day of each month, there is a deep charge and discharge."));
    Monthly_cycle_time->add_Specification();
}
/************自动运行 绘制button*************/
void MEGAWin::AutoOperation()
{
    QString temp1 = QString(tr("Check"));
    QString temp2 = QString(tr("Start_Time"));
    QString temp3 = QString(tr("End_Time"));
    QString temp4 = QString(tr("State"));
    QString temp5 = QString(tr("Power"));
    QString temp6 = QString(tr("9:00"));
    QString temp7 = QString(tr("10:00"));

    if(Check1 != nullptr)
    {
        delete Check1;
    }
    Check1 = new Specification(this,Check1_explain, ui->Time_tableWidget, 0, 0, \
                                tr("√"), temp1, \
                                tr("This is' Enable ', which will enable the specified state at the specified time with the specified power, and end at the specified time."));
    Check1->add_Specification();

    if(Check2 != nullptr)
    {
        delete Check2;
    }
    Check2 = new Specification(this,Check2_explain, ui->Time_tableWidget, 1, 0, \
                                tr("√"), temp1, \
                                tr("This is' Enable ', which will enable the specified state at the specified time with the specified power, and end at the specified time."));
    Check2->add_Specification();

    if(Check3 != nullptr)
    {
        delete Check3;
    }
    Check3 = new Specification(this,Check3_explain, ui->Time_tableWidget, 2, 0, \
                                tr("√"), temp1, \
                                tr("This is' Enable ', which will enable the specified state at the specified time with the specified power, and end at the specified time."));
    Check3->add_Specification();

    if(Check4 != nullptr)
    {
        delete Check4;
    }
    Check4 = new Specification(this,Check4_explain, ui->Time_tableWidget, 3, 0, \
                                tr("√"), temp1, \
                                tr("This is' Enable ', which will enable the specified state at the specified time with the specified power, and end at the specified time."));
    Check4->add_Specification();

    if(Check5 != nullptr)
    {
        delete Check5;
    }
    Check5 = new Specification(this,Check5_explain, ui->Time_tableWidget, 4, 0, \
                                tr("√"), temp1, \
                                tr("This is' Enable ', which will enable the specified state at the specified time with the specified power, and end at the specified time."));
    Check5->add_Specification();

    if(Check6 != nullptr)
    {
        delete Check6;
    }
    Check6 = new Specification(this,Check6_explain, ui->Time_tableWidget, 5, 0, \
                                 tr(""), temp1, \
                                 tr("This is' Enable ', which will enable the specified state at the specified time with the specified power, and end at the specified time."));
    Check6->add_Specification();

    if(Check7 != nullptr)
    {
        delete Check7;
    }
    Check7 = new Specification(this,Check7_explain, ui->Time_tableWidget, 6, 0, \
                                 tr(""), temp1, \
                                 tr("This is' Enable ', which will enable the specified state at the specified time with the specified power, and end at the specified time."));
    Check7->add_Specification();

    if(Check8 != nullptr)
    {
        delete Check8;
    }
    Check8 = new Specification(this,Check8_explain, ui->Time_tableWidget, 7, 0, \
                                 tr(""), temp1, \
                                 tr("This is' Enable ', which will enable the specified state at the specified time with the specified power, and end at the specified time."));
    Check8->add_Specification();

    if(Check9 != nullptr)
    {
        delete Check9;
    }
    Check9 = new Specification(this,Check9_explain, ui->Time_tableWidget, 8, 0, \
                                 tr(""), temp1, \
                                 tr("This is' Enable ', which will enable the specified state at the specified time with the specified power, and end at the specified time."));
    Check9->add_Specification();

    if(Check10 != nullptr)
    {
        delete Check10;
    }
    Check10 = new Specification(this,Check10_explain, ui->Time_tableWidget, 9, 0, \
                                 tr(""), temp1, \
                                 tr("This is' Enable ', which will enable the specified state at the specified time with the specified power, and end at the specified time."));
    Check10->add_Specification();

    if(Check11 != nullptr)
    {
        delete Check11;
    }
    Check11 = new Specification(this,Check11_explain, ui->Time_tableWidget, 10, 0, \
                                 tr(""), temp1, \
                                 tr("This is' Enable ', which will enable the specified state at the specified time with the specified power, and end at the specified time."));
    Check11->add_Specification();

    if(Check11 != nullptr)
    {
        delete Check12;
    }
    Check12 = new Specification(this,Check12_explain, ui->Time_tableWidget, 11, 0, \
                                 tr(""), temp1, \
                                 tr("This is' Enable ', which will enable the specified state at the specified time with the specified power, and end at the specified time."));
    Check12->add_Specification();

    if(Check13 != nullptr)
    {
        delete Check13;
    }
    Check13 = new Specification(this,Check13_explain, ui->Time_tableWidget, 12, 0, \
                                 tr(""), temp1, \
                                 tr("This is' Enable ', which will enable the specified state at the specified time with the specified power, and end at the specified time."));
    Check13->add_Specification();

    if(Check14 != nullptr)
    {
        delete Check14;
    }
    Check14 = new Specification(this,Check14_explain, ui->Time_tableWidget, 13, 0, \
                                 tr(""), temp1, \
                                 tr("This is' Enable ', which will enable the specified state at the specified time with the specified power, and end at the specified time."));
    Check14->add_Specification();

    if(Check15 != nullptr)
    {
        delete Check15;
    }
    Check15 = new Specification(this,Check15_explain, ui->Time_tableWidget, 14, 0, \
                                 tr(""), temp1, \
                                 tr("This is' Enable ', which will enable the specified state at the specified time with the specified power, and end at the specified time."));
    Check15->add_Specification();

    if(Check16 != nullptr)
    {
        delete Check16;
    }
    Check16 = new Specification(this,Check16_explain, ui->Time_tableWidget, 15, 0, \
                                 tr(""), temp1, \
                                 tr("This is' Enable ', which will enable the specified state at the specified time with the specified power, and end at the specified time."));
    Check16->add_Specification();

    if(Check17 != nullptr)
    {
        delete Check17;
    }
    Check17 = new Specification(this,Check17_explain, ui->Time_tableWidget, 16, 0, \
                                 tr(""), temp1, \
                                 tr("This is' Enable ', which will enable the specified state at the specified time with the specified power, and end at the specified time."));
    Check17->add_Specification();

    if(Check18 != nullptr)
    {
        delete Check18;
    }
    Check18 = new Specification(this,Check18_explain, ui->Time_tableWidget, 17, 0, \
                                 tr(""), temp1, \
                                 tr("This is' Enable ', which will enable the specified state at the specified time with the specified power, and end at the specified time."));
    Check18->add_Specification();

    if(Check19 != nullptr)
    {
        delete Check19;
    }
    Check19 = new Specification(this,Check19_explain, ui->Time_tableWidget, 18, 0, \
                                 tr(""), temp1, \
                                 tr("This is' Enable ', which will enable the specified state at the specified time with the specified power, and end at the specified time."));
    Check19->add_Specification();

    if(Check20 != nullptr)
    {
        delete Check20;
    }
    Check20 = new Specification(this,Check20_explain, ui->Time_tableWidget, 19, 0, \
                                 tr(""), temp1, \
                                 tr("This is' Enable ', which will enable the specified state at the specified time with the specified power, and end at the specified time."));
    Check20->add_Specification();


    if(Start_T1 != nullptr)
    {
        delete Start_T1;
    }
    Start_T1 = new Specification(this,Start_T1_explain, ui->Time_tableWidget, 0, 1, \
                                  temp6, temp2, \
                                  tr("This is the start time at which the specified state will begin to be entered with the specified power."));
    Start_T1->add_Specification();

    if(Start_T2 != nullptr)
    {
        delete Start_T2;
    }
    Start_T2 = new Specification(this,Start_T2_explain, ui->Time_tableWidget, 1, 1, \
                                  temp6, temp2, \
                                  tr("This is the start time at which the specified state will begin to be entered with the specified power."));
    Start_T2->add_Specification();

    if(Start_T3 != nullptr)
    {
        delete Start_T3;
    }
    Start_T3 = new Specification(this,Start_T3_explain, ui->Time_tableWidget, 2, 1, \
                                  temp6, temp2, \
                                  tr("This is the start time at which the specified state will begin to be entered with the specified power."));
    Start_T3->add_Specification();

    if(Start_T4 != nullptr)
    {
        delete Start_T4;
    }
    Start_T4 = new Specification(this,Start_T4_explain, ui->Time_tableWidget, 3, 1, \
                                  temp6, temp2, \
                                  tr("This is the start time at which the specified state will begin to be entered with the specified power."));
    Start_T4->add_Specification();

    if(Start_T5 != nullptr)
    {
        delete Start_T5;
    }
    Start_T5 = new Specification(this,Start_T5_explain, ui->Time_tableWidget, 4, 1, \
                                  temp6, temp2, \
                                  tr("This is the start time at which the specified state will begin to be entered with the specified power."));
    Start_T5->add_Specification();

    if(Start_T6 != nullptr)
    {
        delete Start_T6;
    }
    Start_T6 = new Specification(this,Start_T6_explain, ui->Time_tableWidget, 5, 1, \
                                  temp6, temp2, \
                                  tr("This is the start time at which the specified state will begin to be entered with the specified power."));
    Start_T6->add_Specification();

    if(Start_T7 != nullptr)
    {
        delete Start_T7;
    }
    Start_T7 = new Specification(this,Start_T7_explain, ui->Time_tableWidget, 6, 1, \
                                  temp6, temp2, \
                                  tr("This is the start time at which the specified state will begin to be entered with the specified power."));
    Start_T7->add_Specification();

    if(Start_T8 != nullptr)
    {
        delete Start_T8;
    }
    Start_T8 = new Specification(this,Start_T8_explain, ui->Time_tableWidget, 7, 1, \
                                  temp6, temp2, \
                                  tr("This is the start time at which the specified state will begin to be entered with the specified power."));
    Start_T8->add_Specification();

    if(Start_T9 != nullptr)
    {
        delete Start_T9;
    }
    Start_T9 = new Specification(this,Start_T9_explain, ui->Time_tableWidget, 8, 1, \
                                  temp6, temp2, \
                                  tr("This is the start time at which the specified state will begin to be entered with the specified power."));
    Start_T9->add_Specification();

    if(Start_T10 != nullptr)
    {
        delete Start_T10;
    }
    Start_T10 = new Specification(this,Start_T10_explain, ui->Time_tableWidget, 9, 1, \
                                  temp6, temp2, \
                                  tr("This is the start time at which the specified state will begin to be entered with the specified power."));
    Start_T10->add_Specification();

    if(Start_T11 != nullptr)
    {
        delete Start_T11;
    }
    Start_T11 = new Specification(this,Start_T11_explain, ui->Time_tableWidget, 10, 1, \
                                  temp6, temp2, \
                                  tr("This is the start time at which the specified state will begin to be entered with the specified power."));
    Start_T11->add_Specification();

    if(Start_T12 != nullptr)
    {
        delete Start_T12;
    }
    Start_T12 = new Specification(this,Start_T12_explain, ui->Time_tableWidget, 11, 1, \
                                  temp6, temp2, \
                                  tr("This is the start time at which the specified state will begin to be entered with the specified power."));
    Start_T12->add_Specification();

    if(Start_T13 != nullptr)
    {
        delete Start_T13;
    }
    Start_T13 = new Specification(this,Start_T13_explain, ui->Time_tableWidget, 12, 1, \
                                  temp6, temp2, \
                                  tr("This is the start time at which the specified state will begin to be entered with the specified power."));
    Start_T13->add_Specification();

    if(Start_T14 != nullptr)
    {
        delete Start_T14;
    }
    Start_T14 = new Specification(this,Start_T14_explain, ui->Time_tableWidget, 13, 1, \
                                  temp6, temp2, \
                                  tr("This is the start time at which the specified state will begin to be entered with the specified power."));
    Start_T14->add_Specification();

    if(Start_T15 != nullptr)
    {
        delete Start_T15;
    }
    Start_T15 = new Specification(this,Start_T15_explain, ui->Time_tableWidget, 14, 1, \
                                  temp6, temp2, \
                                  tr("This is the start time at which the specified state will begin to be entered with the specified power."));
    Start_T15->add_Specification();

    if(Start_T16 != nullptr)
    {
        delete Start_T16;
    }
    Start_T16 = new Specification(this,Start_T16_explain, ui->Time_tableWidget, 15, 1, \
                                  temp6, temp2, \
                                  tr("This is the start time at which the specified state will begin to be entered with the specified power."));
    Start_T16->add_Specification();

    if(Start_T17 != nullptr)
    {
        delete Start_T17;
    }
    Start_T17 = new Specification(this,Start_T17_explain, ui->Time_tableWidget, 16, 1, \
                                  temp6, temp2, \
                                  tr("This is the start time at which the specified state will begin to be entered with the specified power."));
    Start_T17->add_Specification();

    if(Start_T18 != nullptr)
    {
        delete Start_T18;
    }
    Start_T18 = new Specification(this,Start_T18_explain, ui->Time_tableWidget, 17, 1, \
                                  temp6, temp2, \
                                  tr("This is the start time at which the specified state will begin to be entered with the specified power."));
    Start_T18->add_Specification();

    if(Start_T19 != nullptr)
    {
        delete Start_T19;
    }
    Start_T19 = new Specification(this,Start_T19_explain, ui->Time_tableWidget, 18, 1, \
                                  temp6, temp2, \
                                  tr("This is the start time at which the specified state will begin to be entered with the specified power."));
    Start_T19->add_Specification();

    if(Start_T20 != nullptr)
    {
        delete Start_T20;
    }
    Start_T20 = new Specification(this,Start_T20_explain, ui->Time_tableWidget, 19, 1, \
                                  temp6, temp2, \
                                  tr("This is the start time at which the specified state will begin to be entered with the specified power."));
    Start_T20->add_Specification();


    if(End_T1 != nullptr)
    {
        delete End_T1;
    }
    End_T1 = new Specification(this,End_T1_explain, ui->Time_tableWidget, 0, 2, \
                                temp7, temp3, \
                                tr("This is the end time at which the state started with the 'start time' will end."));
    End_T1->add_Specification();

    if(End_T2 != nullptr)
    {
        delete End_T2;
    }
    End_T2 = new Specification(this,End_T2_explain, ui->Time_tableWidget, 1, 2, \
                                temp7, temp3, \
                                tr("This is the end time at which the state started with the 'start time' will end."));
    End_T2->add_Specification();

    if(End_T3 != nullptr)
    {
        delete End_T3;
    }
    End_T3 = new Specification(this,End_T3_explain, ui->Time_tableWidget, 2, 2, \
                                temp7, temp3, \
                                tr("This is the end time at which the state started with the 'start time' will end."));
    End_T3->add_Specification();

    if(End_T4 != nullptr)
    {
        delete End_T4;
    }
    End_T4 = new Specification(this,End_T4_explain, ui->Time_tableWidget, 3, 2, \
                                temp7, temp3, \
                                tr("This is the end time at which the state started with the 'start time' will end."));
    End_T4->add_Specification();

    if(End_T5 != nullptr)
    {
        delete End_T5;
    }
    End_T5 = new Specification(this,End_T5_explain, ui->Time_tableWidget, 4, 2, \
                                temp7, temp3, \
                                tr("This is the end time at which the state started with the 'start time' will end."));
    End_T5->add_Specification();

    if(End_T6 != nullptr)
    {
        delete End_T6;
    }
    End_T6 = new Specification(this,End_T6_explain, ui->Time_tableWidget, 5, 2, \
                                temp7, temp3, \
                                tr("This is the end time at which the state started with the 'start time' will end."));
    End_T6->add_Specification();

    if(End_T7 != nullptr)
    {
        delete End_T7;
    }
    End_T7 = new Specification(this,End_T7_explain, ui->Time_tableWidget, 6, 2, \
                                temp7, temp3, \
                                tr("This is the end time at which the state started with the 'start time' will end."));
    End_T7->add_Specification();

    if(End_T8 != nullptr)
    {
        delete End_T8;
    }
    End_T8 = new Specification(this,End_T8_explain, ui->Time_tableWidget, 7, 2, \
                                temp7, temp3, \
                                tr("This is the end time at which the state started with the 'start time' will end."));
    End_T8->add_Specification();

    if(End_T9 != nullptr)
    {
        delete End_T9;
    }
    End_T9 = new Specification(this,End_T9_explain, ui->Time_tableWidget, 8, 2, \
                                temp7, temp3, \
                                tr("This is the end time at which the state started with the 'start time' will end."));
    End_T9->add_Specification();

    if(End_T10 != nullptr)
    {
        delete End_T10;
    }
    End_T10 = new Specification(this,End_T10_explain, ui->Time_tableWidget, 9, 2, \
                                temp7, temp3, \
                                tr("This is the end time at which the state started with the 'start time' will end."));
    End_T10->add_Specification();

    if(End_T11 != nullptr)
    {
        delete End_T11;
    }
    End_T11 = new Specification(this,End_T11_explain, ui->Time_tableWidget, 10, 2, \
                                temp7, temp3, \
                                tr("This is the end time at which the state started with the 'start time' will end."));
    End_T11->add_Specification();

    if(End_T12 != nullptr)
    {
        delete End_T12;
    }
    End_T12 = new Specification(this,End_T12_explain, ui->Time_tableWidget, 11, 2, \
                                temp7, temp3, \
                                tr("This is the end time at which the state started with the 'start time' will end."));
    End_T12->add_Specification();

    if(End_T13 != nullptr)
    {
        delete End_T13;
    }
    End_T13 = new Specification(this,End_T13_explain, ui->Time_tableWidget, 12, 2, \
                                temp7, temp3, \
                                tr("This is the end time at which the state started with the 'start time' will end."));
    End_T13->add_Specification();

    if(End_T14 != nullptr)
    {
        delete End_T14;
    }
    End_T14 = new Specification(this,End_T14_explain, ui->Time_tableWidget, 13, 2, \
                                temp7, temp3, \
                                tr("This is the end time at which the state started with the 'start time' will end."));
    End_T14->add_Specification();

    if(End_T15 != nullptr)
    {
        delete End_T15;
    }
    End_T15 = new Specification(this,End_T15_explain, ui->Time_tableWidget, 14, 2, \
                                temp7, temp3, \
                                tr("This is the end time at which the state started with the 'start time' will end."));
    End_T15->add_Specification();

    if(End_T16 != nullptr)
    {
        delete End_T16;
    }
    End_T16 = new Specification(this,End_T16_explain, ui->Time_tableWidget, 15, 2, \
                                temp7, temp3, \
                                tr("This is the end time at which the state started with the 'start time' will end."));
    End_T16->add_Specification();

    if(End_T17 != nullptr)
    {
        delete End_T17;
    }
    End_T17 = new Specification(this,End_T17_explain, ui->Time_tableWidget, 16, 2, \
                                temp7, temp3, \
                                tr("This is the end time at which the state started with the 'start time' will end."));
    End_T17->add_Specification();

    if(End_T18 != nullptr)
    {
        delete End_T18;
    }
    End_T18 = new Specification(this,End_T18_explain, ui->Time_tableWidget, 17, 2, \
                                temp7, temp3, \
                                tr("This is the end time at which the state started with the 'start time' will end."));
    End_T18->add_Specification();

    if(End_T19 != nullptr)
    {
        delete End_T19;
    }
    End_T19 = new Specification(this,End_T19_explain, ui->Time_tableWidget, 18, 2, \
                                temp7, temp3, \
                                tr("This is the end time at which the state started with the 'start time' will end."));
    End_T19->add_Specification();

    if(End_T20 != nullptr)
    {
        delete End_T20;
    }
    End_T20 = new Specification(this,End_T20_explain, ui->Time_tableWidget, 19, 2, \
                                temp7, temp3, \
                                tr("This is the end time at which the state started with the 'start time' will end."));
    End_T20->add_Specification();


    if(State1 != nullptr)
    {
        delete State1;
    }
    State1 = new Specification(this,State1_explain, ui->Time_tableWidget, 0, 3, \
                                tr("charge"), temp4, \
                                tr("This is the state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic."));
    State1->add_Specification();

    if(State2 != nullptr)
    {
        delete State2;
    }
    State2 = new Specification(this,State2_explain, ui->Time_tableWidget, 1, 3, \
                                tr("discharge"), temp4, \
                                tr("This is the state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic."));
    State2->add_Specification();

    if(State3 != nullptr)
    {
        delete State3;
    }
    State3 = new Specification(this,State3_explain, ui->Time_tableWidget, 2, 3, \
                                tr("charge"), temp4, \
                                tr("This is the state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic."));
    State3->add_Specification();

    if(State4 != nullptr)
    {
        delete State4;
    }
    State4 = new Specification(this,State4_explain, ui->Time_tableWidget, 3, 3, \
                                tr("discharge"), temp4, \
                                tr("This is the state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic."));
    State4->add_Specification();

    if(State5 != nullptr)
    {
        delete State5;
    }
    State5 = new Specification(this,State5_explain, ui->Time_tableWidget, 4, 3, \
                                tr("charge"), temp4, \
                                tr("This is the state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic."));
    State5->add_Specification();

    if(State6 != nullptr)
    {
        delete State6;
    }
    State6 = new Specification(this,State6_explain, ui->Time_tableWidget, 5, 3, \
                                tr("discharge"), temp4, \
                                tr("This is the state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic."));
    State6->add_Specification();

    if(State7 != nullptr)
    {
        delete State7;
    }
    State7 = new Specification(this,State7_explain, ui->Time_tableWidget, 6, 3, \
                                tr("charge"), temp4, \
                                tr("This is the state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic."));
    State7->add_Specification();

    if(State8 != nullptr)
    {
        delete State8;
    }
    State8 = new Specification(this,State8_explain, ui->Time_tableWidget, 7, 3, \
                                tr("discharge"), temp4, \
                                tr("This is the state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic."));
    State8->add_Specification();

    if(State9 != nullptr)
    {
        delete State9;
    }
    State9 = new Specification(this,State9_explain, ui->Time_tableWidget, 8, 3, \
                                tr("charge"), temp4, \
                                tr("This is the state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic."));
    State9->add_Specification();

    if(State10 != nullptr)
    {
        delete State10;
    }
    State10 = new Specification(this,State10_explain, ui->Time_tableWidget, 9, 3, \
                                tr("discharge"), temp4, \
                                tr("This is the state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic."));
    State10->add_Specification();

    if(State11 != nullptr)
    {
        delete State11;
    }
    State11 = new Specification(this,State11_explain, ui->Time_tableWidget, 10, 3, \
                                tr("charge"), temp4, \
                                tr("This is the state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic."));
    State11->add_Specification();

    if(State12 != nullptr)
    {
        delete State12;
    }
    State12 = new Specification(this,State12_explain, ui->Time_tableWidget, 11, 3, \
                                tr("discharge"), temp4, \
                                tr("This is the state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic."));
    State12->add_Specification();

    if(State13 != nullptr)
    {
        delete State13;
    }
    State13 = new Specification(this,State13_explain, ui->Time_tableWidget, 12, 3, \
                                tr("charge"), temp4, \
                                tr("This is the state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic."));
    State13->add_Specification();

    if(State14 != nullptr)
    {
        delete State14;
    }
    State14 = new Specification(this,State14_explain, ui->Time_tableWidget, 13, 3, \
                                tr("discharge"), temp4, \
                                tr("This is the state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic."));
    State14->add_Specification();

    if(State15 != nullptr)
    {
        delete State15;
    }
    State15 = new Specification(this,State15_explain, ui->Time_tableWidget, 14, 3, \
                                tr("charge"), temp4, \
                                tr("This is the state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic."));
    State15->add_Specification();

    if(State16 != nullptr)
    {
        delete State16;
    }
    State16 = new Specification(this,State16_explain, ui->Time_tableWidget, 15, 3, \
                                tr("discharge"), temp4, \
                                tr("This is the state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic."));
    State16->add_Specification();

    if(State17 != nullptr)
    {
        delete State17;
    }
    State17 = new Specification(this,State17_explain, ui->Time_tableWidget, 16, 3, \
                                tr("charge"), temp4, \
                                tr("This is the state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic."));
    State17->add_Specification();

    if(State18 != nullptr)
    {
        delete State18;
    }
    State18 = new Specification(this,State18_explain, ui->Time_tableWidget, 17, 3, \
                                tr("discharge"), temp4, \
                                tr("This is the state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic."));
    State18->add_Specification();

    if(State19 != nullptr)
    {
        delete State19;
    }
    State19 = new Specification(this,State19_explain, ui->Time_tableWidget, 18, 3, \
                                tr("charge"), temp4, \
                                tr("This is the state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic."));
    State19->add_Specification();

    if(State20 != nullptr)
    {
        delete State20;
    }
    State20 = new Specification(this,State20_explain, ui->Time_tableWidget, 19, 3, \
                                tr("discharge"), temp4, \
                                tr("This is the state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic."));
    State20->add_Specification();


    if(Power1 != nullptr)
    {
        delete Power1;
    }
    Power1 = new Specification(this,Power1_explain, ui->Time_tableWidget, 0, 4, \
                                tr("-50"), temp5, \
                                tr("This is the working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging."));
    Power1->add_Specification();

    if(Power2 != nullptr)
    {
        delete Power2;
    }
    Power2 = new Specification(this,Power2_explain, ui->Time_tableWidget, 1, 4, \
                                tr("50"), temp5, \
                                tr("This is the working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging."));
    Power2->add_Specification();

    if(Power3 != nullptr)
    {
        delete Power3;
    }
    Power3 = new Specification(this,Power3_explain, ui->Time_tableWidget, 2, 4, \
                                tr("-50"), temp5, \
                                tr("This is the working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging."));
    Power3->add_Specification();

    if(Power4 != nullptr)
    {
        delete Power4;
    }
    Power4 = new Specification(this,Power4_explain, ui->Time_tableWidget, 3, 4, \
                                tr("50"), temp5, \
                                tr("This is the working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging."));
    Power4->add_Specification();


    if(Power5 != nullptr)
    {
        delete Power5;
    }
    Power5 = new Specification(this,Power5_explain, ui->Time_tableWidget, 4, 4, \
                                tr("-50"), temp5, \
                                tr("This is the working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging."));
    Power5->add_Specification();

    if(Power6 != nullptr)
    {
        delete Power6;
    }
    Power6 = new Specification(this,Power6_explain, ui->Time_tableWidget, 5, 4, \
                                tr("50"), temp5, \
                                tr("This is the working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging."));
    Power6->add_Specification();


    if(Power7 != nullptr)
    {
        delete Power7;
    }
    Power7 = new Specification(this,Power7_explain, ui->Time_tableWidget, 6, 4, \
                                tr("-50"), temp5, \
                                tr("This is the working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging."));
    Power7->add_Specification();

    if(Power8 != nullptr)
    {
        delete Power8;
    }
    Power8 = new Specification(this,Power8_explain, ui->Time_tableWidget, 7, 4, \
                                tr("50"), temp5, \
                                tr("This is the working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging."));
    Power8->add_Specification();


    if(Power9 != nullptr)
    {
        delete Power9;
    }
    Power9 = new Specification(this,Power9_explain, ui->Time_tableWidget, 8, 4, \
                                tr("-50"), temp5, \
                                tr("This is the working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging."));
    Power9->add_Specification();

    if(Power10 != nullptr)
    {
        delete Power10;
    }
    Power10 = new Specification(this,Power10_explain, ui->Time_tableWidget, 9, 4, \
                                tr("50"), temp5, \
                                tr("This is the working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging."));
    Power10->add_Specification();


    if(Power11 != nullptr)
    {
        delete Power11;
    }
    Power11 = new Specification(this,Power11_explain, ui->Time_tableWidget, 10, 4, \
                                tr("-50"), temp5, \
                                tr("This is the working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging."));
    Power11->add_Specification();

    if(Power12 != nullptr)
    {
        delete Power12;
    }
    Power12 = new Specification(this,Power12_explain, ui->Time_tableWidget, 11, 4, \
                                tr("50"), temp5, \
                                tr("This is the working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging."));
    Power12->add_Specification();


    if(Power13 != nullptr)
    {
        delete Power13;
    }
    Power13 = new Specification(this,Power13_explain, ui->Time_tableWidget, 12, 4, \
                                tr("-50"), temp5, \
                                tr("This is the working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging."));
    Power13->add_Specification();

    if(Power14 != nullptr)
    {
        delete Power14;
    }
    Power14 = new Specification(this,Power14_explain, ui->Time_tableWidget, 13, 4, \
                                tr("50"), temp5, \
                                tr("This is the working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging."));
    Power14->add_Specification();


    if(Power15 != nullptr)
    {
        delete Power15;
    }
    Power15 = new Specification(this,Power15_explain, ui->Time_tableWidget, 14, 4, \
                                tr("-50"), temp5, \
                                tr("This is the working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging."));
    Power15->add_Specification();

    if(Power16 != nullptr)
    {
        delete Power16;
    }
    Power16 = new Specification(this,Power16_explain, ui->Time_tableWidget, 15, 4, \
                                tr("50"), temp5, \
                                tr("This is the working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging."));
    Power16->add_Specification();


    if(Power17 != nullptr)
    {
        delete Power17;
    }
    Power17 = new Specification(this,Power17_explain, ui->Time_tableWidget, 16, 4, \
                                tr("-50"), temp5, \
                                tr("This is the working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging."));
    Power17->add_Specification();

    if(Power18 != nullptr)
    {
        delete Power18;
    }
    Power18 = new Specification(this,Power18_explain, ui->Time_tableWidget, 17, 4, \
                                tr("50"), temp5, \
                                tr("This is the working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging."));
    Power18->add_Specification();

    if(Power19 != nullptr)
    {
        delete Power19;
    }
    Power19 = new Specification(this,Power19_explain, ui->Time_tableWidget, 18, 4, \
                                tr("-50"), temp5, \
                                tr("This is the working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging."));
    Power19->add_Specification();

    if(Power20 != nullptr)
    {
        delete Power20;
    }
    Power20 = new Specification(this,Power20_explain, ui->Time_tableWidget, 19, 4, \
                                tr("50"), temp5, \
                                tr("This is the working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging."));
    Power20->add_Specification();

}
/*********系统信息 绘制button**********/
void MEGAWin::SystemMessages()
{
    if(Manufacturer_name != nullptr)
    {
        delete Manufacturer_name;
    }
    Manufacturer_name = new Specification(this,Manufacturer_name_explain, ui->EquipmentInfor_tableWidget, 0, 1, \
                                     "PCS", tr("Manufacturer name"), \
                                     tr("This is the name of the manufacturer."));
    Manufacturer_name->add_Specification();

    if(MonitoringVersion != nullptr)
    {
        delete MonitoringVersion;
    }
    MonitoringVersion = new Specification(this,MonitoringVersion_explain, ui->EquipmentInfor_tableWidget, 1, 1, \
                                     "V103B500D004", tr("Monitoring software version"), \
                                     tr("This is the name of the manufacturer."));
    MonitoringVersion->add_Specification();

    if(SysProtocol_Version != nullptr)
    {
        delete SysProtocol_Version;
    }
    SysProtocol_Version = new Specification(this,SysProtocol_Version_explain, ui->EquipmentInfor_tableWidget, 2, 1, \
                                     "V001B001D001", tr("Protocol Version"), \
                                     tr("This is the protocol version number."));
    SysProtocol_Version->add_Specification();

    if(ConverterVersion != nullptr)
    {
        delete ConverterVersion;
    }
    ConverterVersion = new Specification(this,ConverterVersion_explain, ui->EquipmentInfor_tableWidget, 3, 1, \
                                     "V105B500D008", tr("Converter software version"), \
                                     tr("This is the converter software version."));
    ConverterVersion->add_Specification();

    if(CPLD_Version != nullptr)
    {
        delete CPLD_Version;
    }
    CPLD_Version = new Specification(this,CPLD_Version_explain, ui->EquipmentInfor_tableWidget, 4, 1, \
                                     "V001B001D000", tr("CPLD software version"), \
                                     tr("This is the CPLD software version."));
    CPLD_Version->add_Specification();

    if(SN != nullptr)
    {
        delete SN;
    }
    SN = new Specification(this,SN_explain, ui->EquipmentInfor_tableWidget, 5, 1, \
                                     "F12200000001", tr("SN"), \
                                     tr("This is SN, the serial number of the product."));
    SN->add_Specification();
}
/***********功能设置 绘制button************/
void MEGAWin::FunctionSet()
{
    if(Battery_type != nullptr)
    {
        delete Battery_type;
    }
    Battery_type = new Specification(this,Battery_type_explain, ui->UI_Parameter_Tab, 0, 1, \
                                     tr("Lithium"), tr("Battery type"), \
                                     tr("Choose the battery type according to the actual situation, there are two types of Lithium and LeadAcid to choose from."));
    Battery_type->add_Specification();

    if(BMS_Comm_type != nullptr)
    {
        delete BMS_Comm_type;
    }
    BMS_Comm_type = new Specification(this,BMS_Comm_type_explain, ui->UI_Parameter_Tab, 1, 1, \
                                      "CAN", tr("BMS Comm type"), \
                                      tr("Set the communication mode between the battery, RS485 or CAN communication or Ethernet can be selected according to the situation."));
    BMS_Comm_type->add_Specification();

    if(Power_control_type != nullptr)
    {
        delete Power_control_type;
    }
    Power_control_type = new Specification(this,Power_control_type_explain, ui->UI_Parameter_Tab, 2, 1,\
                                           "CP_N&&P" , tr("Power control type"), \
                                           tr("Set the control power mode, including constant voltage (CV), constant current (CC), constant power (CP_P), and positive and negative power (CP_N&P).\nIf constant voltage (CV) mode is selected, the converter will operate in constant voltage mode.\nIf constant current (CC) mode is selected, the converter will operate in constant current mode.\nIf you choose constant power (CP_P) or positive and negative power (CP_N&P) mode: you can set the power size at 'constant power', the value is the size of the power size, positive for discharge, negative for charging."));
    Power_control_type->add_Specification();

    if(EMS_Comm_type != nullptr)
    {
        delete EMS_Comm_type;
    }
    EMS_Comm_type = new Specification(this,EMS_Comm_type_explain, ui->UI_Parameter_Tab, 3, 1, \
                                      "RS485", tr("EMS Comm type"), \
                                      tr("You CAN set the communication mode of the EMS, including RS485,CAN, and Ethernet. Select one communication mode that can be read and written remotely, and the other two communication modes can be read only."));
    EMS_Comm_type->add_Specification();

    if(Output_power_limit != nullptr)
    {
        delete Output_power_limit;
    }
    Output_power_limit = new Specification(this,Output_power_limit_explain, ui->UI_Parameter_Tab, 4, 1,\
                                           "100", tr("Output power limit"), \
                                           tr("HMI Limits the range of power Settings on the AC side."));
    Output_power_limit->add_Specification();

    if(BAT_protocol != nullptr)
    {
        delete BAT_protocol;
    }
    BAT_protocol = new Specification(this,BAT_protocol_explain, ui->UI_Parameter_Tab, 5, 1, \
                                          tr("Auto"), tr("BAT protocol"), \
                                          tr("This is the battery protocol that parses the packets sent by the BMS according to the selected battery protocol."));
    BAT_protocol->add_Specification();

    if(Power_Delta != nullptr)
    {
        delete Power_Delta;
    }
    Power_Delta = new Specification(this,Power_Delta_explain, ui->UI_Parameter_Tab, 6, 1, \
                                    "10", tr("Power Delta"), \
                                    tr("Set the power back difference, the default power back difference is 10kw, the output power increases to 'output power limit + power back difference', will reduce the output power to 'output power - power back difference', (Note: this setting only takes effect in the system anti-countercurrent mode, for control of power grid inlet power back difference)."));
    Power_Delta->add_Specification();

    if(Charge_power_limit != nullptr)
    {
        delete Charge_power_limit;
    }
    Charge_power_limit = new Specification(this,Charge_power_limit_explain, ui->UI_Parameter_Tab, 7, 1, \
                                           "100", tr("Charge power limit"),\
                                           tr("Set the charging power limit to allow the maximum power of charging."));
    Charge_power_limit->add_Specification();

    if(Discharge_power_limit != nullptr)
    {
        delete Discharge_power_limit;
    }
    Discharge_power_limit = new Specification(this,Discharge_power_limit_explain, ui->UI_Parameter_Tab, 8, 1, \
                                              "100", tr("Charge power limit"), \
                                              tr("The discharge power limit is set to allow the maximum power of the discharge."));
    Discharge_power_limit->add_Specification();

    if(Charge_Vol_upper_Limit_delta != nullptr)
    {
        delete Charge_Vol_upper_Limit_delta;
    }
    Charge_Vol_upper_Limit_delta = new Specification(this,Charge_Vol_upper_Limit_delta_explain, ui->UI_Parameter_Tab, 9, 1, \
                                                     "10", tr("Charge Vol upper Limit delta"), \
                                                     tr("Set the upper Limit of Charge voltage delta (Charge Vol upper Limit delta). The default upper limit of charge voltage is 10V. When the charge voltage reaches the 'upper limit of charge voltage + charge voltage delta', the device will be forbidden to charge, and when the charge voltage drops to the 'upper limit of charge voltage - charge voltage delta', the forbidden charge will be lifted."));
    Charge_Vol_upper_Limit_delta->add_Specification();

    if(Discharge_Vol_lower_Limit_delta != nullptr)
    {
        delete Discharge_Vol_lower_Limit_delta;
    }
    Discharge_Vol_lower_Limit_delta = new Specification(this,Discharge_Vol_lower_Limit_delta_explain, ui->UI_Parameter_Tab, 10, 1,\
                                                        "10", tr("Discharge Vol lower Limit delta"), \
                                                        tr("Set the Discharge voltage lower Limit delta (Discharge Vol lower Limit delta), the default discharge voltage lower limit delta is 10V, when the discharge voltage is lower than the 'discharge voltage lower limit - discharge voltage delta', the device will be prohibited, when the discharge voltage reaches the 'discharge voltage lower limit + charge voltage delta', the prohibited discharge will be lifted."));
    Discharge_Vol_lower_Limit_delta->add_Specification();

    if(Host_Address != nullptr)
    {
        delete Host_Address;
    }
    Host_Address = new Specification(this,Host_Address_explain, ui->UI_Parameter_Tab, 0, 4,\
                                     "1", tr("Host Address"), \
                                     tr("This is the device address, which defaults to 1 and can be adjusted from 1 to 255 to match the host address during EMS communication."));
    Host_Address->add_Specification();

    if(serial_port_1 != nullptr)
    {
        delete serial_port_1;
    }
    serial_port_1 = new Specification(this,serial_port_1_explain, ui->UI_Parameter_Tab, 1, 4, \
                                      "9600", tr("serial port 1"), \
                                      tr("This is serial port 1, there are six options, namely 1200, 2400, 4800, 9600, 19200, 38400, serial port 1 default baud rate is 9600 BPS, eight data bits, no check, one stop bit(8, N, 1)."));
    serial_port_1->add_Specification();

    if(serial_port_2 != nullptr)
    {
        delete serial_port_2;
    }
    serial_port_2 = new Specification(this,serial_port_2_explain, ui->UI_Parameter_Tab, 2, 4, \
                                      "9600", tr("serial port 2"), \
                                      tr("This is serial port 2, there are six options, namely 1200, 2400, 4800, 9600, 19200, 38400, serial port 2 default baud rate is 9600 BPS, eight data bits, no check, one stop bit(8, N, 1)."));
    serial_port_2->add_Specification();

    if(serial_port_3 != nullptr)
    {

        delete serial_port_3;
    }
    serial_port_3 = new Specification(this,serial_port_3_explain, ui->UI_Parameter_Tab, 3, 4, \
                                      "9600", tr("serial port 3"), \
                                      tr("This is serial port 3, there are six options, namely 1200, 2400, 4800, 9600, 19200, 38400, serial port 3 default baud rate is 9600 BPS, eight data bits, no check, one stop bit(8, N, 1)."));
    serial_port_3->add_Specification();

    if(serial_port_4 != nullptr)
    {
        delete serial_port_4;
    }
    serial_port_4 = new Specification(this,serial_port_4_explain, ui->UI_Parameter_Tab, 4, 4, \
                                      "9600", tr("serial port 4"), \
                                      tr("This is serial port 4, there are six options, namely 1200, 2400, 4800, 9600, 19200, 38400, serial port 4 default baud rate is 9600 BPS, eight data bits, no check, one stop bit(8, N, 1)."));
    serial_port_4->add_Specification();

    if(serial_port_5 != nullptr)
    {
        delete serial_port_5;
    }
    serial_port_5 = new Specification(this,serial_port_5_explain, ui->UI_Parameter_Tab, 5, 4, \
                                      "9600", tr("serial port 5"), \
                                      tr("This is serial port 5, there are six options, namely 1200, 2400, 4800, 9600, 19200, 38400, serial port 5 default baud rate is 9600 BPS, eight data bits, no check, one stop bit(8, N, 1)."));
    serial_port_5->add_Specification();

    if(Can_port_1 != nullptr)
    {
        delete Can_port_1;
    }
    Can_port_1 = new Specification(this,Can_port_1_explain, ui->UI_Parameter_Tab, 6, 4, \
                                   "500", tr("Can port 1"), \
                                   tr("This is the CAN1 port, the baud rate of PCS internal communication, the default baud rate is 500kbps, eight data bits, no check, one stop bit(8, N, 1)."));
    Can_port_1->add_Specification();

    if(Can_port_2 != nullptr)
    {
        delete Can_port_2;
    }
    Can_port_2 = new Specification(this,Can_port_2_explain, ui->UI_Parameter_Tab, 7, 4, \
                                   "125", tr("Can port 2"), \
                                   tr("This is the CAN2 port, the baud rate of PCS internal communication, the default baud rate is 125kbps, eight data bits, no check, one stop bit(8, N, 1)."));
    Can_port_2->add_Specification();

    if(ProtocolVersion != nullptr)
    {
        delete ProtocolVersion;
    }
    ProtocolVersion = new Specification(this,ProtocolVersion_explain, ui->UI_Parameter_Tab, 0, 7, \
                                        "V1.0", tr("ProtocolVersion"), \
                                        tr("This is the protocol version number, which is used to view the current protocol version. The protocol version number defaults to V1.0."));
    ProtocolVersion->add_Specification();

    if(UserPassPort != nullptr)
    {
        delete UserPassPort;
    }
    UserPassPort = new Specification(this,UserPassPort_explain, ui->UI_Parameter_Tab, 1, 7, \
                                     "123456", tr("UserPassPort"), \
                                     tr("This is the user password, you can reset the user password, the default user password 123456, (note: User password must be six digits)."));
    UserPassPort->add_Specification();

    if(RootPassport != nullptr)
    {
        delete RootPassport;
    }
    RootPassport = new Specification(this,RootPassport_explain, ui->UI_Parameter_Tab, 2, 7,\
                                     "888888", tr("RootPassport"), \
                                     tr("This is the super permission password, you can reset the super permission password, the default super permission password 888888, (Note: super permission password must be six digits)."));
    RootPassport->add_Specification();

    if(Language != nullptr)
    {
        delete Language;
    }
    Language = new Specification(this,Language_explain, ui->UI_Parameter_Tab, 3, 7, \
                                 tr("English"), tr("Language"), \
                                 tr("Set the display language of the display screen, which can be selected as Chinese and English. The system will restart when switching languages."));
    Language->add_Specification();

    if(System_upgrade != nullptr)
    {
        delete System_upgrade;
    }
    System_upgrade = new Specification(this,System_upgrade_explain, ui->UI_Parameter_Tab, 4, 7, \
                                       tr("upgrade"), tr("System upgrade"), \
                                       tr("Click to enter the system upgrade application and upgrade the system according to the upgrade document."));
    System_upgrade->add_Specification();

    if(Sounds != nullptr)
    {
        delete Sounds;
    }
    Sounds = new Specification(this,Sounds_explain, ui->UI_Parameter_Tab, 5, 7, \
                               tr("Allow"), tr("Sounds"), \
                               tr("Set whether the display is enabled sound, which can be allowed(Allow) or prohibited(forbid)."));
    Sounds->add_Specification();

}
/***********系统参数 绘制button************/
void MEGAWin::SystemParameter()
{
    if(Change_rate_of_power != nullptr)
    {
        delete Change_rate_of_power;
    }
    Change_rate_of_power = new Specification(this,Change_rate_of_power_explain, ui->UI_SystemParameter_Tab, 0, 1, \
                                             "20", tr("Change rate of power"), \
                                             tr("How fast the power changes per unit time."));
    Change_rate_of_power->add_Specification();

    if(Grid_frequency_upper_limit != nullptr)
    {
        delete Grid_frequency_upper_limit;
    }
    Grid_frequency_upper_limit = new Specification(this,Grid_frequency_upper_limit_explain, ui->UI_SystemParameter_Tab, 1, 1, \
                                                   "3", tr("Grid frequency upper limit"), \
                                                   tr("The upper limit of the frequency range allowed on the AC side is 0.2, 0.5, 1, and 3."));
    Grid_frequency_upper_limit->add_Specification();

    if(Grid_frequency_lower_limit != nullptr)
    {
        delete Grid_frequency_lower_limit;
    }
    Grid_frequency_lower_limit = new Specification(this,Grid_frequency_lower_limit_explain, ui->UI_SystemParameter_Tab, 2, 1, \
                                                   "-3", tr("Grid frequency lower limit"), \
                                                   tr("The lower limit of the frequency range allowed on the AC side can be selected as -0.2, -0.5, -1, or -3."));
    Grid_frequency_lower_limit->add_Specification();

    if(Vol_protection_upper_limit != nullptr)
    {
        delete Vol_protection_upper_limit;
    }
    Vol_protection_upper_limit = new Specification(this,Vol_protection_upper_limit_explain, ui->UI_SystemParameter_Tab, 3, 1, \
                                                   "+15", tr("Vol protection upper limit"), \
                                                   tr("The upper limit of the voltage range allowed on the AC side can be +10, +15, +20, or +30."));
    Vol_protection_upper_limit->add_Specification();

    if(Vol_protection_lower_limit != nullptr)
    {
        delete Vol_protection_lower_limit;
    }
    Vol_protection_lower_limit = new Specification(this,Vol_protection_lower_limit_explain, ui->UI_SystemParameter_Tab, 4, 1, \
                                                   "-15", tr("Vol protection lower limit"), \
                                                   tr("The lower limit of the voltage variation range allowed on the AC side can be -10, -15, -20, or -30."));
    Vol_protection_lower_limit->add_Specification();

    if(HVRT_enable != nullptr)
    {
        delete HVRT_enable;
    }
    HVRT_enable = new Specification(this,HVRT_enable_explain, ui->UI_SystemParameter_Tab, 5, 1, \
                                                    tr("prohibit"), tr("HVRT enable"), \
                                                    tr("This is the high voltage crossing (HVRT) Enable, enable the device will not stop because of a short period of high voltage, the option is to Enable, prohibit, (note: this is generally used in large grid-connected power stations)."));
    HVRT_enable->add_Specification();

    if(LVRT_enable != nullptr)
    {
        delete LVRT_enable;
    }
    LVRT_enable = new Specification(this,LVRT_enable_explain, ui->UI_SystemParameter_Tab, 6, 1, \
                                    tr("prohibit"), tr("LVRT enable"), \
                                    tr("This is the low voltage crossing (LVRT) Enable, enable the device will not stop because of a short period of low voltage, the option is to Enable, prohibit, (note: this is generally used in large grid-connected power stations)."));
    LVRT_enable->add_Specification();

    if(AFD_enable != nullptr)
    {
        delete AFD_enable;
    }
    AFD_enable = new Specification(this,AFD_enable_explain, ui->UI_SystemParameter_Tab, 7, 1, \
                                   tr("prohibit"), tr("AFD enable"), \
                                   tr("Prevent islanding effect, When the detection of the island effect (in the photovoltaic grid-connected system, when the power failure occurs in the large power grid, the photovoltaic grid-connected inverter power generation and the local load on the low-voltage side of the grid if the power is just matched, it is easy to appear self-sufficient maintenance power state, resulting in the 'island' phenomenon, thereby endangering the safety of maintenance personnel), the inverter automatically shut down, and the option is allowed Enable, prohibit, (Note: this is generally used in large grid-connected power stations)."));
    AFD_enable->add_Specification();

    if(Insulation_detection_enable != nullptr)
    {
        delete Insulation_detection_enable;
    }
    Insulation_detection_enable = new Specification(this,Insulation_detection_enable_explain, ui->UI_SystemParameter_Tab, 8, 1, \
                                                    tr("prohibit"), tr("Insulation detection enable"), \
                                                    tr("Insulation detection Enable, insulation resistance greater than 33KΩ to be able to operate normally, less than 33KΩ can not start, and to alarm, the default prohibition, the choice is to Enable, prohibit, (Note: this is generally used in large grid-connected power stations)."));
    Insulation_detection_enable->add_Specification();

    if(PrimaryFreq_enable != nullptr)
    {
        delete PrimaryFreq_enable;
    }
    PrimaryFreq_enable = new Specification(this,PrimaryFreq_enable_explain, ui->UI_SystemParameter_Tab, 9, 1, \
                                           tr("prohibit"), tr("PrimaryFreq enable"), \
                                           tr("When the frequency of the power grid deviates from the rated value, the power grid frequency is maintained stable by controlling the increase or decrease of the active power, which can be selected to Enable, prohibit, (Note: this is generally used in large grid-connected power stations)."));
    PrimaryFreq_enable->add_Specification();

    if(Inertia_enable != nullptr)
    {
        delete Inertia_enable;
    }
    Inertia_enable = new Specification(this,Inertia_enable_explain, ui->UI_SystemParameter_Tab, 10, 1, \
                                       tr("prohibit"), tr("Inertia enable"), \
                                       tr("Moment of inertia Enable, can be selected to Enable, prohibit, (Note: this is generally used in large grid-connected power stations)."));
    Inertia_enable->add_Specification();

    if(CV_parallel != nullptr)
    {
        delete CV_parallel;
    }
    CV_parallel = new Specification(this,CV_parallel_explain, ui->UI_SystemParameter_Tab, 11, 1, \
                                    tr("prohibit"), tr("CV parallel"), \
                                    tr("Constant voltage parallel Enable, you can choose to Enable, prohibit, (Note: this setting is used in constant voltage parallel mode)."));
    CV_parallel->add_Specification();

    if(Machine_type != nullptr)
    {
        delete Machine_type;
    }
    Machine_type = new Specification(this,Machine_type_explain, ui->UI_SystemParameter_Tab, 0, 4, \
                                     "PCS-TS", tr("Machine type"), \
                                     tr("Set according to the machine model and factory value. The default MPS-TS."));
    Machine_type->add_Specification();

    if(Machine_capacity != nullptr)
    {
        delete Machine_capacity;
    }
    Machine_capacity = new Specification(this,Machine_capacity_explain, ui->UI_SystemParameter_Tab, 1, 4, \
                                     "100", tr("Machine capacity"), \
                                     tr("The rated capacity of PCS is subject to the ex-factory value and cannot be changed."));
    Machine_capacity->add_Specification();

    if(Output_Fre_grade != nullptr)
    {
        delete Output_Fre_grade;
    }
    Output_Fre_grade = new Specification(this,Output_Fre_grade_explain, ui->UI_SystemParameter_Tab, 2, 4, \
                                         "50", tr("Output Fre grade"), \
                                         tr("Set the output frequency level, the default is 50Hz, generally 50Hz or 60Hz, can be fine-tuned according to the project."));
    Output_Fre_grade->add_Specification();

    if(Output_vol_level != nullptr)
    {
        delete Output_vol_level;
    }
    Output_vol_level = new Specification(this,Output_vol_level_explain, ui->UI_SystemParameter_Tab, 3, 4, \
                                         "400", tr("Output vol level"), \
                                         tr("The voltage level is changed according to the actual local power grid voltage. The voltage level is subject to delivery. If you need to change it, contact customer service for confirmation."));
    Output_vol_level->add_Specification();

    if(Converter_side_vol_level != nullptr)
    {
        delete Converter_side_vol_level;
    }
    Converter_side_vol_level = new Specification(this,Converter_side_vol_level_explain, ui->UI_SystemParameter_Tab, 4, 4, \
                                         "270:400", tr("Converter side vol level"), \
                                         tr("The inverter voltage level is the voltage level of the inverter, which should be set according to the transformer nameplate, subject to the factory default value, and cannot be changed at will. If you need to change, please contact customer service to confirm."));
    Converter_side_vol_level->add_Specification();

    if(Output_reactive_power_mode != nullptr)
    {
        delete Output_reactive_power_mode;
    }
    Output_reactive_power_mode = new Specification(this,Output_reactive_power_mode_explain, ui->UI_SystemParameter_Tab, 5, 4, \
                                         tr("Non adjustable"), tr("Output reactive power mode"), \
                                         tr("Output reactive mode, the default is not adjustable, can be selected as power factor (Pf), reactive power (Q), Non adjustable."));
    Output_reactive_power_mode->add_Specification();

    if(Grid_connected_mode_of_Inv != nullptr)
    {
        delete Grid_connected_mode_of_Inv;
    }
    Grid_connected_mode_of_Inv = new Specification(this,Grid_connected_mode_of_Inv_explain, ui->UI_SystemParameter_Tab, 6, 4, \
                                                   tr("Non countercurrent"), tr("Grid connected mode of Inv"), \
                                                   tr("Set the grid-connected mode of the inverter, which can be countercurrent, that is, DC can be converted into AC power and then incorporated into the power grid; Irreversible means that the current on the DC side does not flow to the grid. The default value can be Countercurrent. The options can be countercurrent or Non countercurrent. With the local grid qualification, it can be changed to 'countercurrent'; When using Prevent countercurrent mode, you can change to 'countercurrent'."));
    Grid_connected_mode_of_Inv->add_Specification();

    if(Primary_FM_dead_zone != nullptr)
    {
        delete Primary_FM_dead_zone;
    }
    Primary_FM_dead_zone = new Specification(this,Primary_FM_dead_zone_explain, ui->UI_SystemParameter_Tab, 7, 4, \
                                             "3", tr("Primary FM dead zone"), \
                                             tr("Primary frequency modulation dead zone, in order to prevent unnecessary action of the switch when the frequency difference of the grid changes in a small range, (Note: This is generally used in large grid-connected power stations)."));
    Primary_FM_dead_zone->add_Specification();

    if(PFM_coeff != nullptr)
    {
        delete PFM_coeff;
    }
    PFM_coeff = new Specification(this,PFM_coeff_explain, ui->UI_SystemParameter_Tab, 8, 4, \
                                  "20", tr("PFM coeff"), \
                                  tr("This can set the active power frequency modulation coefficient, (Note: this is generally used in large grid-connected power stations)."));
    PFM_coeff->add_Specification();

    if(Grid_recover_time != nullptr)
    {
        delete Grid_recover_time;
    }
    Grid_recover_time = new Specification(this,Grid_recover_time_explain, ui->UI_SystemParameter_Tab, 9, 4, \
                                          "10", tr("Grid recover time"), \
                                          tr("Grid restoration time: reserved function, setting invalid."));
    Grid_recover_time->add_Specification();

    if(DynamicCap!= nullptr)
    {
        delete DynamicCap;
    }
    DynamicCap = new Specification(this,DynamicCap_explain, ui->UI_SystemParameter_Tab, 10, 4, \
                                   tr("Enable"), tr("DynamicCap"), \
                                   tr("Enable the power network expansion. The options are Enable and Disable."));
    DynamicCap->add_Specification();

    if(Module_Number != nullptr)
    {
        delete Module_Number;
    }
    Module_Number = new Specification(this,Module_Number_explain, ui->UI_SystemParameter_Tab, 0, 7, \
                                      "1", tr("Module Number"), \
                                      tr("Number of modules for PCS, default 1(invalid setting)."));
    Module_Number->add_Specification();

    if(Restore_factory != nullptr)
    {
        delete Restore_factory;
    }
    Restore_factory = new Specification(this,Restore_factory_explain, ui->UI_SystemParameter_Tab,1, 7, \
                                        tr("restore"), tr("Restore factory"), \
                                        tr("Restore the factory default Settings."));
    Restore_factory->add_Specification();

    if(Clear_Data != nullptr)
    {
        delete Clear_Data;
    }
    Clear_Data = new Specification(this,Clear_Data_explain, ui->UI_SystemParameter_Tab, 2, 7, \
                                   tr("Clear"), tr("Clear Data"), \
                                   tr("Clear previous recorded data and operation data of the system."));
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
    QMessageBox::question(this ,tr("static"), tr("If this parameter is selected, static IP addresses are used."), tr("OK"));
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
    QMessageBox::question(this ,tr("dhcp"), tr("This is an automatic IP acquisition, currently not supported."), tr("OK"));
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
