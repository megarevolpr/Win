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
    LanguageType = CHINESE; //开机默认为中文


    ui->setupUi(this);

//    this->setMinimumSize(1150,780);
    ui->UI_stackedWidget->setCurrentWidget(ui->UI_page );//开机后进入主页面
    ui->stackedWidget->setCurrentWidget(ui->Bypass_page);
    ui->RTD_PCS_StackedWidget->setCurrentWidget(ui->RTD_Bypass_Y_page);
    ui->RTState_stackedWidget->setCurrentWidget(ui->RTState_Bypass_Y_page);

    LoadLanguageInit(); //初始化语言
    MemoryAllocation(); //初始化内存空间
    UIPageInit();       //初始化界面
    LinkRelationship(); //函数关联

}

MEGAWin::~MEGAWin()
{
    delete ui;
}

void MEGAWin::onTimerOut()//时间显示
{
    if(LanguageType == 1)//语言切换为英文时，时间为英式时间
    {
        QDateTime time = QDateTime::currentDateTime();
        QString str = time.toString("dd-MM-yyyy HH:mm:ss");
        ui->TimeSeting_btn->setText(str);
    }
    else {
        QDateTime time = QDateTime::currentDateTime();
        QString str = time.toString("yyyy-MM-dd HH:mm:ss");
        ui->TimeSeting_btn->setText(str);
    }
}

void MEGAWin::updateTimeOut()
{
    RTDataDisplay();
}

/************************初始化内存空间********************************/
void MEGAWin::MemoryAllocation()
{
    ASKey = true;//确保只绘制一次高级设置页面

    m_menu = new Menu(this);//菜单创建
    UpgradeInterface = new UpgradeTools(this);
    GridExpansionInterface = new GridExpansion(this,LanguageType);
    FaultTable = new FaultTableInterface(this,LanguageType);

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
//    pButton_History->addButton(ui->Day_btn,10);
//    pButton_History->addButton(ui->Year_btn,11);
    pButton_History->addButton(ui->Add_M,12);
    pButton_History->addButton(ui->Add_Y,13);
//    pButton_History->addButton(ui->Month_btn,14);
//    pButton_History->addButton(ui->Total_btn,15);
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
    Grade9_explain      = new QPushButton;
    Grade10_explain     = new QPushButton;
    Grade11_explain     = new QPushButton;
    Grade12_explain     = new QPushButton;
    Grade13_explain     = new QPushButton;
    Grade14_explain     = new QPushButton;
    Grade15_explain     = new QPushButton;
    StartTime_explain   = new QPushButton;
    StartTime2_explain  = new QPushButton;
    StartTime3_explain  = new QPushButton;
    StartTime4_explain  = new QPushButton;
    StartTime5_explain  = new QPushButton;
    StartTime6_explain  = new QPushButton;
    StartTime7_explain  = new QPushButton;
    StartTime8_explain  = new QPushButton;
    StartTime9_explain  = new QPushButton;
    StartTime10_explain = new QPushButton;
    StartTime11_explain = new QPushButton;
    StartTime12_explain = new QPushButton;
    StartTime13_explain = new QPushButton;
    StartTime14_explain = new QPushButton;
    StartTime15_explain = new QPushButton;
    EndTime_explain     = new QPushButton;
    EndTime2_explain    = new QPushButton;
    EndTime3_explain    = new QPushButton;
    EndTime4_explain    = new QPushButton;
    EndTime5_explain    = new QPushButton;
    EndTime6_explain    = new QPushButton;
    EndTime7_explain    = new QPushButton;
    EndTime8_explain    = new QPushButton;
    EndTime9_explain    = new QPushButton;
    EndTime10_explain   = new QPushButton;
    EndTime11_explain   = new QPushButton;
    EndTime12_explain   = new QPushButton;
    EndTime13_explain   = new QPushButton;
    EndTime14_explain   = new QPushButton;
    EndTime15_explain   = new QPushButton;
    Describe_explain    = new QPushButton;
    Describe2_explain   = new QPushButton;
    Describe3_explain   = new QPushButton;
    Describe4_explain   = new QPushButton;
    Describe5_explain   = new QPushButton;
    Describe6_explain   = new QPushButton;
    Describe7_explain   = new QPushButton;
    Describe8_explain   = new QPushButton;
    Describe9_explain   = new QPushButton;
    Describe10_explain  = new QPushButton;
    Describe11_explain  = new QPushButton;
    Describe12_explain  = new QPushButton;
    Describe13_explain  = new QPushButton;
    Describe14_explain  = new QPushButton;
    Describe15_explain  = new QPushButton;
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
    Work_mode_explain = new QPushButton;                //工作模式说明
    Output_power_factor_explain = new QPushButton;      //输出功率因素说明
    Output_reactive_power_explain = new QPushButton;    //输出无功功率说明
    Constant_current_explain = new QPushButton;         //恒流说明
    Constant_voltage_explain = new QPushButton;         //恒压说明
    Control_mode_explain = new QPushButton;             //控制模式说明
    Machine_number_explain = new QPushButton;           //设备号说明
    Parallel_explain = new QPushButton;                 //并机说明

    Grid_connected_mode = nullptr;
    Constant_power = nullptr;
//    Work_mode = nullptr;
    Output_power_factor = nullptr;
    Output_reactive_power = nullptr;
    Constant_current = nullptr;
    Constant_voltage = nullptr;
    Control_mode = nullptr;
    Machine_number = nullptr;
    Parallel = nullptr;

    /***************************电池设置**********************************/

    DOD_OnGrid_explain          = new QPushButton;      //并网DOD
    DOD_OffGrid_explain         = new QPushButton;      //离网DOD
    Charge_Vol_Up_Limit_explain = new QPushButton;      //充电电压上限
    Disc_Vol_lower_Limit_explain= new QPushButton;      //放电电压下限
    Charge_Cur_Limit_explain    = new QPushButton;      //充电限流点
    Discharge_Cur_Limit_explain = new QPushButton;   //放电限流点
    Gen_turn_off_SOC_explain    = new QPushButton;      //柴发关闭SOC
    Gen_turn_on_SOC_explain     = new QPushButton;      //柴发开启SOC
    Gen_charge_SOC_explain      = new QPushButton;      //柴发充电SOC
    Grid_charge_SOC_explain     = new QPushButton;      //电网充电SOC
    ChargeStopSOC_explain       = new QPushButton;
    DischargeStopSOC_explain    = new QPushButton;
    Grid_capacity_explain       = new QPushButton;      //电网容量
    Turn_on_SOC_explain         = new QPushButton;      //启动SOC
    Turn_off_SOC_explain        = new QPushButton;      //停止SOC
    Turn_on_cell_vol_explain    = new QPushButton;      //启动单体电压
    Turn_off_cell_vol_explain   = new QPushButton;      //停止单体电压
    Turn_on_total_vol_explain   = new QPushButton;      //启动总压
    Turn_off_total_vol_explain  = new QPushButton;      //停止总压
    UPS_charge_power_explain    = new QPushButton;      //后备充电功率
    Monthly_cycle_time_explain  = new QPushButton;      //月循环日期
    Charge_power_limit_explain              = new QPushButton;
    Discharge_power_limit_explain           = new QPushButton;
    Charge_Vol_upper_Limit_delta_explain    = new QPushButton;
    Discharge_Vol_lower_Limit_delta_explain = new QPushButton;

    DOD_OnGrid = nullptr;
    DOD_OffGrid = nullptr;
    Charge_Vol_Up_Limit = nullptr;
    Disc_Vol_lower_Limit = nullptr;
    Charge_Cur_Limit = nullptr;
    Discharge_Cur_Limit = nullptr;
    Gen_turn_off_SOC = nullptr;
    Gen_turn_on_SOC = nullptr;
    Gen_charge_SOC = nullptr;
    Grid_charge_SOC = nullptr;
    ChargeStopSOC = nullptr;
    DischargeStopSOC = nullptr;
    Grid_capacity = nullptr;
    Turn_on_SOC = nullptr;
    Turn_off_SOC = nullptr;
    Turn_on_cell_vol = nullptr;
    Turn_off_cell_vol = nullptr;
    Turn_on_total_vol = nullptr;
    Turn_off_total_vol = nullptr;
    UPS_charge_power = nullptr;
    Monthly_cycle_time = nullptr;
    Charge_power_limit = nullptr;
    Discharge_power_limit = nullptr;
    Charge_Vol_upper_Limit_delta = nullptr;
    Discharge_Vol_lower_Limit_delta = nullptr;

    Capacity_explain                    = new QPushButton;//铅酸
    Cell_number_2V_explain              = new QPushButton;
    Bat_float_vol_explain               = new QPushButton;
    Bat_filling_vol_explain             = new QPushButton;
    Charge_limiting_value_explain       = new QPushButton;
    Discharge_limiting_value_explain    = new QPushButton;
    Generator_turn_off_SOC_B1_explain   = new QPushButton;
    Generator_turn_on_SOC_A1_explain    = new QPushButton;
    Grid_off_EOD_explain                = new QPushButton;
    Grid_on_EOD_explain                 = new QPushButton;
    Uniform_To_Flushing_current_explain = new QPushButton;
    Flushing_To_Uniform_current_explain = new QPushButton;

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

//    Manufacturer_name_explain   = new QPushButton;
    MonitoringVersion_explain   = new QPushButton;
    SysProtocol_Version_explain = new QPushButton;
    ConverterVersion_explain    = new QPushButton;
    CPLD_Version_explain        = new QPushButton;
    SN_explain                  = new QPushButton;
//    Manufacturer_name = nullptr;
    MonitoringVersion = nullptr;
    SysProtocol_Version = nullptr;
    ConverterVersion = nullptr;
    CPLD_Version = nullptr;
    SN = nullptr;

    /***************************高级设置**********************************/
    AdvancedSetup_btn = new QPushButton;                //高级设置入口

    //功能设置
    Battery_type_explain                    = new QPushButton;
    BMS_Comm_type_explain                   = new QPushButton;
    Power_control_type_explain              = new QPushButton;
    EMS_Comm_type_explain                   = new QPushButton;
    Output_power_limit_explain              = new QPushButton;
    BAT_protocol_explain                    = new QPushButton;
    Power_Delta_explain                     = new QPushButton;
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
    EnergyMeterModel_explain= new QPushButton;
    BmsComFaultTime_explain = new QPushButton;
    EMSComFaultModel_explain= new QPushButton;

    Battery_type = nullptr;
    BMS_Comm_type = nullptr;
    Power_control_type = nullptr;
    EMS_Comm_type = nullptr;
    Output_power_limit = nullptr;
    BAT_protocol = nullptr;
    Power_Delta = nullptr;
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
//    System_upgrade = nullptr;
    Sounds = nullptr;
    EnergyMeterModel= nullptr;
    BmsComFaultTime = nullptr;
    EMSComFaultModel= nullptr;

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
    System_Anti_Reverse_Flow_explain    = new QPushButton;
    Primary_FM_dead_zone_explain        = new QPushButton;
    PFM_coeff_explain                   = new QPushButton;
    Grid_recover_time_explain           = new QPushButton;
//    DynamicCap_explain                  = new QPushButton;
    Module_Number_explain               = new QPushButton;
    Restore_factory_explain             = new QPushButton;
    BackupSetParameters_explain         = new QPushButton;
    RestoreBackupSetParameters_explain  = new QPushButton;
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
    System_Anti_Reverse_Flow = nullptr;
    Primary_FM_dead_zone = nullptr;
    PFM_coeff = nullptr;
    Grid_recover_time = nullptr;
//    DynamicCap = nullptr;
    Module_Number = nullptr;
    Restore_factory = nullptr;
    BackupSetParameters = nullptr;
    RestoreBackupSetParameters = nullptr;
    Clear_Data = nullptr;

    //外设
    DI_1_Enable_explain = new QPushButton;
    DI_2_Enable_explain = new QPushButton;
    DI_3_Enable_explain = new QPushButton;
    DI_4_Enable_explain = new QPushButton;
    DI_5_Enable_explain = new QPushButton;
    DI_6_Enable_explain = new QPushButton;
    DI_1_NC_O_explain   = new QPushButton;
    DI_2_NC_O_explain   = new QPushButton;
    DI_3_NC_O_explain   = new QPushButton;
    DI_4_NC_O_explain   = new QPushButton;
    DI_5_NC_O_explain   = new QPushButton;
    DI_6_NC_O_explain   = new QPushButton;
    DI_1_Action_explain = new QPushButton;
    DI_2_Action_explain = new QPushButton;
    DI_3_Action_explain = new QPushButton;
    DI_4_Action_explain = new QPushButton;
    DI_5_Action_explain = new QPushButton;
    DI_6_Action_explain = new QPushButton;
    DI_1_Enable = nullptr;
    DI_2_Enable = nullptr;
    DI_3_Enable = nullptr;
    DI_4_Enable = nullptr;
    DI_5_Enable = nullptr;
    DI_6_Enable = nullptr;
    DI_1_NC_O = nullptr;
    DI_2_NC_O = nullptr;
    DI_3_NC_O = nullptr;
    DI_4_NC_O = nullptr;
    DI_5_NC_O = nullptr;
    DI_6_NC_O = nullptr;
    DI_1_Action = nullptr;
    DI_2_Action = nullptr;
    DI_3_Action = nullptr;
    DI_4_Action = nullptr;
    DI_5_Action = nullptr;
    DI_6_Action = nullptr;

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
    DOD_Action = nullptr;
    Prohibit_charging_Action = nullptr;
    Prohibit_discharging_Action = nullptr;
    BMS_warning_Action = nullptr;
    BMS_alarm_Action = nullptr;
    BMS_fualt_Action = nullptr;
    BMS_warning_CP = nullptr;
    BMS_alarm_CP = nullptr;
    BMS_fualt_CP = nullptr;
    BMS_warning_DP = nullptr;
    BMS_alarm_DP = nullptr;
    BMS_fualt_DP = nullptr;

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
    Debug_variable_1 = nullptr;
    Debug_variable_2 = nullptr;
    Debug_variable_3 = nullptr;
    Debug_variable_1_addr = nullptr;
    Debug_variable_2_addr = nullptr;
    Debug_variable_3_addr = nullptr;
    Debug_memery_var_1 = nullptr;
    Debug_memery_var_2 = nullptr;
    Debug_memery_var_3 = nullptr;
    Input_Vol_revise = nullptr;
    Input_Cur_revise = nullptr;

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
    Voltage_1_5_revise = nullptr;
    Bus_Vol_revise = nullptr;
    Grid_A_AB_Vol_revise = nullptr;
    Grid_B_BC_Vol_revise = nullptr;
    Grid_C_CA_Vol_revise = nullptr;
    Output_A_Cur_revise = nullptr;
    Output_B_Cur_revise = nullptr;
    Output_C_Cur_revise = nullptr;
    INV_A_Vol_revise = nullptr;
    INV_B_Vol_revise = nullptr;
    INV_C_Vol_revise = nullptr;

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
    INV_A_ind_Cur_revise = nullptr;
    INV_B_ind_Cur_revise = nullptr;
    INV_C_ind_Cur_revise = nullptr;
    INV_On_off_flag = nullptr;
    Logic_state = nullptr;
    INV_flag = nullptr;
    Grid_flag = nullptr;
    Grid_protect_flag = nullptr;
    Bat_flag = nullptr;
    DC_bus_flag = nullptr;
    INT_main_flag = nullptr;
    parallel_signal = nullptr;

    /*****************************监控调试****************************************/
    pButton_MonitorDebug = new QButtonGroup();
    pButton_MonitorDebug->addButton(ui->DO_TurnON_btn,0);
    pButton_MonitorDebug->addButton(ui->DO_TurnOFF_btn,1);
    pButton_MonitorDebug->addButton(ui->localSoftstart_btn,2);
    pButton_MonitorDebug->addButton(ui->localSoftend_btn,3);
    /*****************************电池设置****************************************/
    pButton_MonitorDebug->addButton(ui->BMSPowerOn_btn,4);//电池上电
    pButton_MonitorDebug->addButton(ui->BMSPowerOff_btn,5);//电池下电

    /*****************************PCS 实时数据****************************************/
    //变流器
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

    //电网
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

    //负载
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
    LVRT_explain                = new QPushButton;//低压穿越
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

    /***********静态/动态IP地址显示标志位**********/
    IPShow = true;
}
/************操作日志 释放 说明************/
void MEGAWin::OperationLog_tab_delete()
{
    delete ModificationTime;
    delete ModificationTime2;
    delete ModificationTime3;
    delete ModificationTime4;
    delete ModificationTime5;
    delete ModificationTime6;
    delete ModificationTime7;
    delete ModificationTime8;
    delete ModificationTime9;
    delete ModificationTime10;
    delete ModificationTime11;
    delete ModificationTime12;
    delete EventRecord;
    delete EventRecord2;
    delete EventRecord3;
    delete EventRecord4;
    delete EventRecord5;
    delete EventRecord6;
    delete EventRecord7;
    delete EventRecord8;
    delete EventRecord9;
    delete EventRecord10;
    delete EventRecord11;
    delete EventRecord12;
}

/************铅酸电池设置 释放 说明************/
void MEGAWin::Battery_Setup_Lead_Tab_delete()
{
    delete Capacity;
    delete Cell_number_2V;
    delete Charge_limiting_value;
    delete Discharge_limiting_value;
    delete Generator_turn_off_SOC_B1;
    delete Generator_turn_on_SOC_A1;
    delete Grid_off_EOD;
    delete Grid_on_EOD;
    delete Bat_float_vol;
    delete Bat_filling_vol;
    delete Uniform_To_Flushing_current;
    delete Flushing_To_Uniform_current;
}
/************历史数据 释放 说明************/
void MEGAWin::HistoryRecord_delete()
{
    delete Grade;
    delete Grade2;
    delete Grade3;
    delete Grade4;
    delete Grade5;
    delete Grade6;
    delete Grade7;
    delete Grade8;
    delete Grade9;
    delete Grade10;
    delete Grade11;
    delete Grade12;
    delete Grade13;
    delete Grade14;
    delete Grade15;
    delete StartTime;
    delete StartTime2;
    delete StartTime3;
    delete StartTime4;
    delete StartTime5;
    delete StartTime6;
    delete StartTime7;
    delete StartTime8;
    delete StartTime9;
    delete StartTime10;
    delete StartTime11;
    delete StartTime12;
    delete StartTime13;
    delete StartTime14;
    delete StartTime15;
    delete EndTime;
    delete EndTime2;
    delete EndTime3;
    delete EndTime4;
    delete EndTime5;
    delete EndTime6;
    delete EndTime7;
    delete EndTime8;
    delete EndTime9;
    delete EndTime10;
    delete EndTime11;
    delete EndTime12;
    delete EndTime13;
    delete EndTime14;
    delete EndTime15;
    delete Describe;
    delete Describe2;
    delete Describe3;
    delete Describe4;
    delete Describe5;
    delete Describe6;
    delete Describe7;
    delete Describe8;
    delete Describe9;
    delete Describe10;
    delete Describe11;
    delete Describe12;
    delete Describe13;
    delete Describe14;
    delete Describe15;
}

/***************************************************************
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
 * 实时状态初始化
 ***************************************************************/
void MEGAWin::RunStatePage()
{
    PCS_Data_Tab();//变流器实时数据
    Grid_Data_Tab();//电网实时数据
    Load_Data_Tab();//负载实时数据
//    RTAlarm();//告警信息
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

/***************************************************************
 * 记录页面初始化
 ***************************************************************/
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
    ui->System_Tab->setCellWidget(7,4, (QWidget *)AdvancedSetup_btn);          //高级设置入口

    ParameterSet();//系统设置

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
    ui->Historicalfailure_tableWidget->setRowCount(15);
    ui->Historicalfailure_tableWidget->setHorizontalHeaderLabels(table_h_headers);
    ui->Historicalfailure_tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->Historicalfailure_tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->Historicalfailure_tableWidget->setStyleSheet("selection-background-color:lightblue;");
    ui->Historicalfailure_tableWidget->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->Historicalfailure_tableWidget->setShowGrid(true);//设置显示格子
    ui->Historicalfailure_tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
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
    for(int i=0;i<15;i++)
    {
        ui->Historicalfailure_tableWidget->setRowHeight(i,40);
    }

    History(ui->Historicalfailure_tableWidget);//历史记录
}

/***************************************************************
 * 操作日志表初始化
 ***************************************************************/
void MEGAWin::OperationLog_tab()
{
    QStringList Ope_headers;
    Ope_headers.clear();
    Ope_headers << tr("ModificationTime") << tr("RecordEvent");
    ui->Operation_tableWidget->setColumnCount(Ope_headers.size());
    ui->Operation_tableWidget->setRowCount(12);
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

    for(int i=0;i<12;i++)
    {
        ui->Operation_tableWidget->setRowHeight(i,40);
    }
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

    ui->Lead_Tab->setColumnWidth(0,175);
    ui->Lead_Tab->setColumnWidth(1,100);
    ui->Lead_Tab->setColumnWidth(2,75);
    ui->Lead_Tab->setColumnWidth(3,175);
    ui->Lead_Tab->setColumnWidth(4,100);
    ui->Lead_Tab->setColumnWidth(5,75);
    for(int i=0;i<17;i++)
    {
        ui->Lithum_Tab->setRowHeight(i,50);
        ui->Lead_Tab->setRowHeight(i,50);
    }
    BetterySetup();//电池设置
    Battery_Setup_Lead_Tab(ui->Lead_Tab);

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
    for(int i=0;i<20;i++)
    {
        ui->Time_tableWidget->setRowHeight(i,40);
    }

    AutoOperation();//自动运行

}
/******************************************************************************
 * 变流器实时数据表初始化
 * ***************************************************************************/
void MEGAWin::PCS_Data_Tab()
{
//    ui->Converter_Tab->clearContents();
    QStringList Converter_Tablist1;
    Converter_Tablist1  << tr("Inv. voltage(AB)") << tr("Inv. voltage(BC)") << tr("Inv. voltage(CA)")
                        << tr("Inv. current(A)") << tr("Inv. current(B)")<< tr("Inv. current(C)")
                        << tr("Inv. active power") << tr("Inv. reactive power") << tr("Inv. apparent power") << tr("Inv. power factor");
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
    for(int i=0;i<10;i++)
    {
        ui->Converter_Tab->setRowHeight(i,35.5);
    }

    PCS_Data();//PCS数据
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
    for(int i=0;i<11;i++)
    {
        ui->Grid_Tab->setRowHeight(i,32);
    }
    Grid_Data();//电网数据
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
                        << tr("Load apparent power") << tr("Load power factor");
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
    for(int i=0;i<10;i++)
    {
        ui->Load_Tab->setRowHeight(i,35.5);
    }
    Load_Data();//负载数据
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
    ui->EquipmentInfor_tableWidget->setRowCount(5);
    ui->EquipmentInfor_tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->EquipmentInfor_tableWidget->verticalHeader()->setVisible(false);//设置垂直头不可见
    ui->EquipmentInfor_tableWidget->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->EquipmentInfor_tableWidget->setShowGrid(true);//设置显示格子
    ui->EquipmentInfor_tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    ui->EquipmentInfor_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
    ui->EquipmentInfor_tableWidget->setStyleSheet("selection-background-color:lightblue;");

    //将设备信息显示到LCD上
    QStringList List4;
    List4 << tr("Name") << tr("System Information") ;
    ui->EquipmentInfor_tableWidget->setHorizontalHeaderLabels(List4);
    ui->EquipmentInfor_tableWidget->setColumnWidth(0,230);
    ui->EquipmentInfor_tableWidget->horizontalHeader()->setStretchLastSection(1);//自动占用剩余空间

    for(int i=0;i<6;i++)
    {
        ui->EquipmentInfor_tableWidget->setRowHeight(i,40);
    }
    SystemMessages();//系统信息

}

/*************************************************************************
 * PCS故障信息表
 ************************************************************************/
/*void MEGAWin::PCS_Alarm_information_table()
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
}*/

/***************************************************************
 * 切换语言并应用到所有页面
 ***************************************************************/
void MEGAWin::Change_Language()
{
    m_menu->hide();//隐藏菜单界面

    if(LanguageType == CHINESE)
    {
        LanguageType = ENGLISH;//如果当前是中文，则切英文
        translator->load(":/Language/EN.qm");
        ui->ChangeLanguage_btn->setText(tr("Change Language"));
        qApp->installTranslator(translator);
        ui->retranslateUi(this);
    }
    else if(LanguageType == ENGLISH)
    {
        LanguageType = CHINESE;//如果当前是英文，则切中文
        translator->load(":/Language/CN.qm");
        ui->ChangeLanguage_btn->setText(tr("切换语言"));
        qApp->installTranslator(translator);
        ui->retranslateUi(this);
    }

    Battery_Setup_Lead_Tab_delete();//铅酸电池delete
    OperationLog_tab_delete();//操作日志delete
    HistoryRecord_delete();//历史记录delete
    delete UpgradeInterface;//升级
    delete GridExpansionInterface;
    delete FaultTable;

    RunStatePage();//重新加载实时数据的UI

    SystemSettingPage();//重新加载系统的UI

    RecordPage();//重新加载记录的UI

    SystemParam_tbnt_released();//重新加载高级设置的UI
    UpgradeInterface = new UpgradeTools(this);
    GridExpansionInterface = new GridExpansion(this,LanguageType);
    FaultTable = new FaultTableInterface(this,LanguageType);

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
        ui->UI_SystemParameter_Tab->setColumnWidth(i,160);
        ui->UI_SystemParameter_Tab->setRowHeight(i++,50);

        ui->UI_Parameter_Tab->setColumnWidth(i,90);
        ui->UI_Parameter_Tab->setRowHeight(i,50);
        ui->UI_SystemParameter_Tab->setColumnWidth(i,115);
        ui->UI_SystemParameter_Tab->setRowHeight(i++,50);

        ui->UI_Parameter_Tab->setColumnWidth(i,55);
        ui->UI_Parameter_Tab->setRowHeight(i,50);
        ui->UI_SystemParameter_Tab->setColumnWidth(i,42);
        ui->UI_SystemParameter_Tab->setRowHeight(i,50);
    }


    ui->ExternalDevice_tW->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->ExternalDevice_tW->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->ExternalDevice_tW->setStyleSheet("selection-background-color:lightblue;");
    for(int i=0;i<9;i++)//调整 外设 的列宽列高
    {
        ui->ExternalDevice_tW->setColumnWidth(i,200);
        ui->ExternalDevice_tW->setRowHeight(i,50);
        if(i==3){
            ui->ExternalDevice_tW->setColumnWidth(i,280);
            ui->ExternalDevice_tW->setRowHeight(i,50);
        }
    }

    ui->BMSProtection_tW->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->BMSProtection_tW->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->BMSProtection_tW->setStyleSheet("selection-background-color:lightblue;");
    for(int i=0;i<6;i++)//调整 BMS保护 的列宽列高
    {
        ui->BMSProtection_tW->setColumnWidth(i,250);
        ui->BMSProtection_tW->setRowHeight(i,55);
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
 *高级设置入口
 ***************************************************************/
void MEGAWin::AdvancedSetup_btn_clicked()
{
    m_menu->hide();//隐藏菜单界面

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
//    connect(ui->search_le,SIGNAL(editingFinished()), this, SLOT(on_search_btn_clicked()));//搜索栏关联搜索槽，使LineEdit失去焦点或回车键回车也生效
    connect(System_upgrade_explain, SIGNAL(clicked(bool)), this, SLOT(UpgradeInterface_clicked())); //升级界面关联
    connect(Work_mode_explain, SIGNAL(clicked(bool)), this, SLOT(WorkingMode_clicked())); //升级界面关联
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
        QStringList RTState_Bypass_List1;
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
          RTState_Bypass_List4 << tr("Start Diesel Generator Signal") << tr("DO2")\
                               << tr("DO3") << tr("Dry contact EPO")\
                               << tr("Dry contact Shutdown") << tr("Access control signal")\
                               << tr("Full power signal") << tr("Smoke alarm signal")<< tr("Fire fighting signal");

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
    for(int i=0;i<9;i++)
    {
        ui->RTState_Bypass_Tab->setRowHeight(i,42);
    }
    PCS_State();//PCS状态
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
        ui->BatterSet_tabWidget->setCurrentWidget(ui->Lithium_tabWidgetPage);
        ui->System_tabWidget->setCurrentIndex(0);
        break;
    case MACHINECLOSE:
        QMessageBox::question(this, tr("Turn off")\
                              ,tr("The converter off switch. Click to turn off the converter."), tr("OK"));
        break;
    case MACHINESTANDBY:
        QMessageBox::question(this, tr("Stand-by")\
                              ,tr("The converter standby switch. Click the converter to enter the standby state."), tr("OK"));
        break;
    case MACHINEOPEN:
        QMessageBox::question(this, tr("Turn on")\
                              ,tr("The converter on switch. Click to turn on the converter."), tr("OK"));
        break;
    default:
        break;
    }
}

/***************************************************************
 * 初始化界面
 ***************************************************************/
void MEGAWin::UIPageInit()
{
    FirstPage();//主页点击

    RunStatePage();//PCS运行状态页

    SystemSettingPage();//系统设置页面初始化

    RecordPage();//记录页面初始化

    LCDSetting();//时间实时刷新显示

}

/***************************************************************
 * 初始化语言
 ***************************************************************/
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

/***************************************************************
 * 菜单弹出与隐藏
 ***************************************************************/
void MEGAWin::on_UI_MenuBtn_clicked()
{
    if(m_menu->isHidden())
    {
        if(m_menu != nullptr)
        {
            delete m_menu;
        }
        m_menu = new Menu(this);
        connect(m_menu, SIGNAL(Sent(int)), this, SLOT(My_menuAction(int)));

        m_menu->setGeometry(0, 0, 250, 453);
        m_menu->move(QPoint((this->pos().x() + 10),(this->pos().y()+87)));
//        m_menu->move(QPoint((this->pos().x() + 30),(this->pos().y()+(this->frameGeometry().height()-(450+110)))));
        m_menu->show();
    }
    else
    {
        m_menu->hide();
    }
}

/***************************************************************
 * 退出高级设置
 ***************************************************************/
void MEGAWin::on_UI_Complete_Btn_clicked()
{
    ui->UI_stackedWidget->setCurrentWidget(ui->UI_page);
}

/***************************************************************
 * 显示变流器实时数据
 ***************************************************************/
void MEGAWin::on_Running_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Status_page);
    ui->Run_tabWidget->setCurrentWidget(ui->RTData_page);
    ui->RTD_PCS_StackedWidget->setCurrentWidget(ui->RTD_Bypass_Y_page);
    ui->Bypass_Tab->setCurrentWidget(ui->Bypass_Converter_page);
    ui->SConverter_btn->click();
}

/***************************************************************
 * 显示电网端实时数据
 ***************************************************************/
void MEGAWin::on_Grid_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Status_page);
    ui->Run_tabWidget->setCurrentWidget(ui->RTData_page);
    ui->RTD_PCS_StackedWidget->setCurrentWidget(ui->RTD_Bypass_Y_page);
    ui->Bypass_Tab->setCurrentWidget(ui->Bypass_Grid_page);
    ui->SGrid_btn->click();
}

/***************************************************************
 * 显示负载端实时数据
 ***************************************************************/
void MEGAWin::on_Load_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Status_page);
    ui->Run_tabWidget->setCurrentWidget(ui->RTData_page);
    ui->RTD_PCS_StackedWidget->setCurrentWidget(ui->RTD_Bypass_Y_page);
    ui->Bypass_Tab->setCurrentWidget(ui->Bypass_Load_page);
    ui->SLoad_btn->click();
}

/***************************************************************
 * 显示电池信息
 ***************************************************************/
void MEGAWin::on_Batt_btn_released()
{
    ui->stackedWidget->setCurrentWidget(ui->Status_page);
    ui->Run_tabWidget->setCurrentWidget(ui->BatteryData_page);
    ui->BAT_stackedWidget->setCurrentWidget(ui->BAT_Lithium_page);
}

/***************************************************************
 * 显示故障信息表
 ***************************************************************/
void MEGAWin::on_Alarm_btn_clicker()
{
    ui->stackedWidget->setCurrentWidget(ui->Status_page);
    ui->Run_tabWidget->setCurrentWidget(ui->RTAlarm_page);
    QMessageBox::question(this,tr("Alarm icon"), tr("Alarm icon: It is not displayed when there is no alarm. When there is a minor alarm, a yellow icon is displayed. When there is a fault alarm, a red icon is displayed."),\
                          tr("OK"));
}

/***************************************************************
 * 显示变流器实时数据
 ***************************************************************/
void MEGAWin::on_SConverter_btn_clicked()
{
    ui->Bypass_Tab->setCurrentWidget(ui->Bypass_Converter_page);
}

/***************************************************************
 * 显示电网实时数据
 ***************************************************************/
void MEGAWin::on_SGrid_btn_clicked()
{
    ui->Bypass_Tab->setCurrentWidget(ui->Bypass_Grid_page);
}

/***************************************************************
 * 显示负载实时数据
 ***************************************************************/
void MEGAWin::on_SLoad_btn_clicked()
{
    ui->Bypass_Tab->setCurrentWidget(ui->Bypass_Load_page);
}

/***************************************************************
 * 实时数据界面选项卡点击响应
 ***************************************************************/
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

/***************************************************************
 * 数据报表&导出数据
 ***************************************************************/
void MEGAWin::Data_report_clicked(int nid)
{
    switch (nid) {
    case 0:
        QMessageBox::question(this, tr("Discharge Day")\
                              ,tr("Display today's power discharge amount."), tr("OK"));
        break;
    case 1:
        QMessageBox::question(this, tr("Discharge Month")\
                              ,tr("Display this month's power discharge amount."), tr("OK"));
        break;
    case 2:
        QMessageBox::question(this, tr("Discharge Year")\
                              ,tr("Display this year's power discharge amount."), tr("OK"));
        break;
    case 3:
        QMessageBox::question(this, tr("Discharge Total")\
                              ,tr("Display total power discharge amount."), tr("OK"));
        break;
    case 4:
        QMessageBox::question(this, tr("Charge Day")\
                              ,tr("Display today's power charge amount"), tr("OK"));
        break;
    case 5:
        QMessageBox::question(this, tr("Charge Month")\
                              ,tr("Display this month's power charge amount."), tr("OK"));
        break;
    case 6:
        QMessageBox::question(this, tr("Charge Year")\
                              ,tr("Display this year's power charge amount."), tr("OK"));
        break;
    case 7:
        QMessageBox::question(this, tr("Charge Total")\
                              ,tr("Display total power charge amount."), tr("OK"));
        break;
    case 8:
        QMessageBox::question(this, tr("Month-")\
                              ,tr("To view the data of the previous month."), tr("OK"));
        break;
    case 9:
        QMessageBox::question(this, tr("Year-")\
                              ,tr("To view the data of the previous year."), tr("OK"));
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
                              ,tr("To view the data of the next month."), tr("OK"));
        break;
    case 13:
        QMessageBox::question(this, tr("Year+")\
                              ,tr("To view the data of the next year."), tr("OK"));
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
        QMessageBox::question(this, tr("Historical Failure")\
                              ,tr("Export History Records, click here to export the history records to a U disk. The exported file will be named Record.csv, and it needs to be opened with Excel."), tr("OK"));
        break;
    case 17:
        QMessageBox::question(this, tr("Operation Log")\
                              ,tr("Export operation log. Click here to export operation log to U disk."), tr("OK"));
        break;
    case 18:
        QMessageBox::question(this, tr("Electricity Statistical Table")\
                              ,tr("Export the battery statistics. Click here to export the battery statistics to the U disk.\nThe accuracy is 0.1, which means that the obtained data multiplied by 0.1 gives the actual value."), tr("OK"));
        break;
    case 19:
        QMessageBox::question(this, tr("Eject U disk")\
                              ,tr("Eject U disk."), tr("OK"));
        break;
    }
}

/***************************************************************
 * 系统信息
 ***************************************************************/
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

/***************************************************************
 * 监控调试
 ***************************************************************/
void MEGAWin::MonitorDebug_clicked(int nid)
{
    switch (nid) {
        case 0:
            QMessageBox::question(this, tr("DO turn on")\
                              ,tr("This is the DO control closure, provided for internal debugging use only."), tr("OK"));
            break;
        case 1:
            QMessageBox::question(this, tr("Do turn off")\
                              ,tr("This is the DO control off, provided for internal debugging use only."), tr("OK"));
            break;
        case 2:
            QMessageBox::question(this, tr("Local on")\
                              ,tr("This is to start a local soft boot, only for internal debugging use."), tr("OK"));
            break;
        case 3:
            QMessageBox::question(this, tr("Local off")\
                              ,tr("This is to turn off the local soft boot for internal debugging use only."), tr("OK"));
            break;
        case 4:
            QMessageBox::question(this, tr("Battery power on")\
                          ,tr("Battery power-on: This function allows the BMS to send a command to close the contactor (Note: this feature is only supported by some BMS manufacturers)."), tr("OK"));
            break;
        case 5:
            QMessageBox::question(this, tr("Battery power off")\
                          ,tr("Battery power-off: This function allows the BMS to send a command to open the contactor (Note: this feature is only supported by some BMS manufacturers)."), tr("OK"));
            break;
        default:
            break;
    }
}

/***************************************************************
 * 历史记录
 ***************************************************************/
void MEGAWin::History(QTableWidget *myTable)
{
    QString str1 = tr("0");
    QString str2 = tr("Level");
    QString str3 = tr("0 represents an alarm event, and this item will turn red. 1 represents a status event.");//0表示告警事件，且此项会变红，1表示状态事件
    QString str4 = tr("Start Time");
    QString str5 = tr("Event start time.");//事件开始时间。
    QString str6 = tr("End Time");
    QString str7 = tr("Event end time: '... 'indicates that there is no end time,'-' indicates that the event is in progress.");//19.事件结束时间：表示这条记录的结束时间，'...'表示无结束时间,'-'表示事件正在进行。
    QString str8 = tr("CAN communication failure");
    QString str9 = tr("event description");//事件描述
    QString str10 = tr("event description.");//事件描述。
    QString str11 = tr("Fire alarm (High temp. alarm)");//消防告警(高温告警)
    QString str12 = tr("Power Meter Comm fualttLead-acid abnormal");//电能表通讯故障
    QString str13 = tr("Converter Standby.");//变换器待机
    QString str14 = tr("The grid contactor connected");//电网接触器闭合
    QString str15 = tr("The grid breaker connected");//电网断路器闭合
    QString str16 = tr("The output breaker connected");//输出断路器闭合
    QString str17 = tr("Buck not softened");//低压侧未软起
    QString str18 = tr("Contactor off buck");//低压侧接触器断开
    //QString str19 = tr("Turning on the converter is not allowed");//变流器开机不允许
    QString str20 = tr("The grid breaker disconnected");//电网断路器断开
    //QString str21 = tr("The grid contactor is disconnected");//电网接触器断开

    QString str24 = tr("1");

    int line=0;int column=0;
    Grade9 = new Specification(this,Grade9_explain, myTable, line++, column, \
                                                    str24, str2, str3);
    Grade9->add_Specification();
    Grade10 = new Specification(this,Grade10_explain, myTable, line++, column, \
                                                    str24, str2, str3);
    Grade10->add_Specification();
    Grade11 = new Specification(this,Grade11_explain, myTable, line++, column, \
                                                    str24, str2, str3);
    Grade11->add_Specification();
    Grade12 = new Specification(this,Grade12_explain, myTable, line++, column, \
                                                    str24, str2, str3);
    Grade12->add_Specification();
    Grade13 = new Specification(this,Grade13_explain, myTable, line++, column, \
                                                    str24, str2, str3);
    Grade13->add_Specification();
    Grade14 = new Specification(this,Grade14_explain, myTable, line++, column, \
                                                    str24, str2, str3);
    Grade14->add_Specification();
    Grade15 = new Specification(this,Grade15_explain, myTable, line++, column, \
                                                    str24, str2, str3);
    Grade15->add_Specification();

    Grade = new Specification(this,Grade_explain, myTable, line++, column, \
                                                    str1, str2, str3);
    Grade->add_Specification();
    Grade2 = new Specification(this,Grade2_explain, myTable, line++, column, \
                                                    str1, str2, str3);
    Grade2->add_Specification();
    Grade3 = new Specification(this,Grade3_explain, myTable, line++, column, \
                                                    str1, str2,  str3);
    Grade3->add_Specification();
    Grade4 = new Specification(this,Grade4_explain, myTable, line++, column, \
                                                    str1, str2, str3);
    Grade4->add_Specification();
    Grade5 = new Specification(this,Grade5_explain, myTable, line++, column, \
                                                    str1, str2, str3);
    Grade5->add_Specification();
    Grade6 = new Specification(this,Grade6_explain, myTable, line++, column, \
                                                    str1, str2, str3);
    Grade6->add_Specification();
    Grade7 = new Specification(this,Grade7_explain, myTable, line++, column, \
                                                    str1, str2, \
                                                    str3);
    Grade7->add_Specification();
    Grade8 = new Specification(this,Grade8_explain, myTable, line++, column, \
                                                    str1, str2, str3);
    Grade8->add_Specification();
    line=0;
    column=1;
    if(LanguageType==0)
    {
        StartTime9 = new Specification(this,StartTime9_explain, myTable, line++, column, \
                                                        "2023-7-29 14:59:56", str4, str5);
        StartTime9->add_Specification();
        StartTime10 = new Specification(this,StartTime10_explain, myTable, line++, column, \
                                                        "2023-7-29 14:59:55", str4, str5);
        StartTime10->add_Specification();
        StartTime11 = new Specification(this,StartTime11_explain, myTable, line++, column, \
                                                        "2023-7-29 14:59:51", str4, str5);
        StartTime11->add_Specification();
        StartTime12 = new Specification(this,StartTime12_explain, myTable, line++, column, \
                                                        "2023-7-29 14:59:51", str4, str5);
        StartTime12->add_Specification();
        StartTime13 = new Specification(this,StartTime13_explain, myTable, line++, column, \
                                                        "2023-7-29 14:59:50", str4, str5);
        StartTime13->add_Specification();
        StartTime14 = new Specification(this,StartTime14_explain, myTable, line++, column, \
                                                        "2023-7-29 14:57:50", str4, str5);
        StartTime14->add_Specification();
        StartTime15 = new Specification(this,StartTime15_explain, myTable, line++, column, \
                                                        "2023-7-29 14:57:50", str4, str5);
        StartTime15->add_Specification();

        StartTime = new Specification(this,StartTime_explain, myTable, line++, column, \
                                                        "2023-5-6 15:49:50", str4, str5);
        StartTime->add_Specification();
        StartTime2 = new Specification(this,StartTime2_explain, myTable, line++, column, \
                                                        "2023-5-6 15:48:18", str4, str5);
        StartTime2->add_Specification();
        StartTime3 = new Specification(this,StartTime3_explain, myTable, line++, column, \
                                                        "2023-5-6 15:39:3", str4, str5);
        StartTime3->add_Specification();
        StartTime4 = new Specification(this,StartTime4_explain, myTable, line++, column, \
                                                        "2023-5-6 15:39:3", str4, str5);
        StartTime4->add_Specification();
        StartTime5 = new Specification(this,StartTime5_explain, myTable, line++, column, \
                                                        "2023-5-6 15:39:3", str4, str5);
        StartTime5->add_Specification();
        StartTime6 = new Specification(this,StartTime6_explain, myTable, line++, column, \
                                                        "2023-5-6 15:21:56", str4, str5);
        StartTime6->add_Specification();
        StartTime7 = new Specification(this,StartTime7_explain, myTable, line++, column, \
                                                        "2023-5-6 15:21:38", str4, str5);
        StartTime7->add_Specification();
        StartTime8 = new Specification(this,StartTime8_explain, myTable, line++, column, \
                                                        "2023-5-6 15:21:38", str4, str5);
        StartTime8->add_Specification();
        line=0;
        column=2;
        EndTime9 = new Specification(this,EndTime9_explain, myTable, line++, column, \
                                                        "...", str6, str7);
        EndTime9->add_Specification();
        EndTime10 = new Specification(this,EndTime10_explain, myTable, line++, column, \
                                                        "...", str6, str7);
        EndTime10->add_Specification();
        EndTime11 = new Specification(this,EndTime11_explain, myTable, line++, column, \
                                                        "...", str6, str7);
        EndTime11->add_Specification();
        EndTime12 = new Specification(this,EndTime12_explain, myTable, line++, column, \
                                                        "...", str6, str7);
        EndTime12->add_Specification();
        EndTime13 = new Specification(this,EndTime13_explain, myTable, line++, column, \
                                                        "...", str6, str7);
        EndTime13->add_Specification();
        EndTime14 = new Specification(this,EndTime14_explain, myTable, line++, column, \
                                                        "...", str6, str7);
        EndTime14->add_Specification();
        EndTime15 = new Specification(this,EndTime15_explain, myTable, line++, column, \
                                                        "2023-7-29 16:42:24", str6, str7);
        EndTime15->add_Specification();

        EndTime = new Specification(this,EndTime_explain, myTable, line++, column, \
                                                        "-", str6, str7);
        EndTime->add_Specification();
        EndTime2 = new Specification(this,EndTime2_explain, myTable, line++, column, \
                                                        "-", str6, str7);
        EndTime2->add_Specification();
        EndTime3 = new Specification(this,EndTime3_explain, myTable, line++, column, \
                                                        "...", str6, str7);
        EndTime3->add_Specification();
        EndTime4 = new Specification(this,EndTime4_explain, myTable, line++, column, \
                                                        "-", str6, str7);
        EndTime4->add_Specification();
        EndTime5 = new Specification(this,EndTime5_explain, myTable, line++, column, \
                                                        "...", str6, str7);
        EndTime5->add_Specification();
        EndTime6 = new Specification(this,EndTime6_explain, myTable, line++, column, \
                                                        "-", str6, str7);
        EndTime6->add_Specification();
        EndTime7 = new Specification(this,EndTime7_explain, myTable, line++, column, \
                                                        "-", str6, str7);
        EndTime7->add_Specification();
        EndTime8 = new Specification(this,EndTime8_explain, myTable, line++, column, \
                                                        "-", str6, str7);
        EndTime8->add_Specification();
    }
    else {
        StartTime9 = new Specification(this,StartTime9_explain, myTable, line++, column, \
                                                        "29-7-2023 14:59:56", str4, str5);
        StartTime9->add_Specification();
        StartTime10 = new Specification(this,StartTime10_explain, myTable, line++, column, \
                                                        "29-7-2023 14:59:55", str4, str5);
        StartTime10->add_Specification();
        StartTime11 = new Specification(this,StartTime11_explain, myTable, line++, column, \
                                                        "29-7-2023 14:59:51", str4, str5);
        StartTime11->add_Specification();
        StartTime12 = new Specification(this,StartTime12_explain, myTable, line++, column, \
                                                        "29-7-2023 14:59:51", str4, str5);
        StartTime12->add_Specification();
        StartTime13 = new Specification(this,StartTime13_explain, myTable, line++, column, \
                                                        "29-7-2023 14:59:50", str4, str5);
        StartTime13->add_Specification();
        StartTime14 = new Specification(this,StartTime14_explain, myTable, line++, column, \
                                                        "29-7-2023 14:57:50", str4, str5);
        StartTime14->add_Specification();
        StartTime15 = new Specification(this,StartTime15_explain, myTable, line++, column, \
                                                        "29-7-2023 14:57:50", str4, str5);
        StartTime15->add_Specification();

        StartTime = new Specification(this,StartTime_explain, myTable, line++, column, \
                                                        "6-5-2023 15:49:50", str4, str5);
        StartTime->add_Specification();
        StartTime2 = new Specification(this,StartTime2_explain, myTable, line++, column, \
                                                        "6-5-2023 15:48:18", str4, str5);
        StartTime2->add_Specification();
        StartTime3 = new Specification(this,StartTime3_explain, myTable, line++, column, \
                                                        "6-5-2023 15:39:3", str4, str5);
        StartTime3->add_Specification();
        StartTime4 = new Specification(this,StartTime4_explain, myTable, line++, column, \
                                                        "6-5-2023 15:39:3", str4, str5);
        StartTime4->add_Specification();
        StartTime5 = new Specification(this,StartTime5_explain, myTable, line++, column, \
                                                        "6-5-2023 15:39:3", str4, str5);
        StartTime5->add_Specification();
        StartTime6 = new Specification(this,StartTime6_explain, myTable, line++, column, \
                                                        "6-5-2023 15:21:56", str4, str5);
        StartTime6->add_Specification();
        StartTime7 = new Specification(this,StartTime7_explain, myTable, line++, column, \
                                                        "6-5-2023 15:21:38", str4, str5);
        StartTime7->add_Specification();
        StartTime8 = new Specification(this,StartTime8_explain, myTable, line++, column, \
                                                        "6-5-2023 15:21:38", str4, str5);
        StartTime8->add_Specification();
        line=0;
        column=2;
        EndTime9 = new Specification(this,EndTime9_explain, myTable, line++, column, \
                                                        "...", str6, str7);
        EndTime9->add_Specification();
        EndTime10 = new Specification(this,EndTime10_explain, myTable, line++, column, \
                                                        "...", str6, str7);
        EndTime10->add_Specification();
        EndTime11 = new Specification(this,EndTime11_explain, myTable, line++, column, \
                                                        "...", str6, str7);
        EndTime11->add_Specification();
        EndTime12 = new Specification(this,EndTime12_explain, myTable, line++, column, \
                                                        "...", str6, str7);
        EndTime12->add_Specification();
        EndTime13 = new Specification(this,EndTime13_explain, myTable, line++, column, \
                                                        "...", str6, str7);
        EndTime13->add_Specification();
        EndTime14 = new Specification(this,EndTime14_explain, myTable, line++, column, \
                                                        "...", str6, str7);
        EndTime14->add_Specification();
        EndTime15 = new Specification(this,EndTime15_explain, myTable, line++, column, \
                                                        "29-7-2023 16:42:24", str6, str7);
        EndTime15->add_Specification();

        EndTime = new Specification(this,EndTime_explain, myTable, line++, column, \
                                                        "-", str6, str7);
        EndTime->add_Specification();
        EndTime2 = new Specification(this,EndTime2_explain, myTable, line++, column, \
                                                        "-", str6, str7);
        EndTime2->add_Specification();
        EndTime3 = new Specification(this,EndTime3_explain, myTable, line++, column, \
                                                        "...", str6, str7);
        EndTime3->add_Specification();
        EndTime4 = new Specification(this,EndTime4_explain, myTable, line++, column, \
                                                        "-", str6, str7);
        EndTime4->add_Specification();
        EndTime5 = new Specification(this,EndTime5_explain, myTable, line++, column, \
                                                        "...", str6, str7);
        EndTime5->add_Specification();
        EndTime6 = new Specification(this,EndTime6_explain, myTable, line++, column, \
                                                        "-", str6, str7);
        EndTime6->add_Specification();
        EndTime7 = new Specification(this,EndTime7_explain, myTable, line++, column, \
                                                        "-", str6, str7);
        EndTime7->add_Specification();
        EndTime8 = new Specification(this,EndTime8_explain, myTable, line++, column, \
                                                        "-", str6, str7);
        EndTime8->add_Specification();
    }

    line=0;
    column=3;
    Describe9 = new Specification(this,Describe9_explain, myTable, line++, column, \
                                                    str13, str9, str10);
    Describe9->add_Specification();
    Describe10 = new Specification(this,Describe10_explain, myTable, line++, column, \
                                                    str14, str9, str10);
    Describe10->add_Specification();
    Describe11 = new Specification(this,Describe11_explain, myTable, line++, column, \
                                                    str15, str9, str10);
    Describe11->add_Specification();
    Describe12 = new Specification(this,Describe12_explain, myTable, line++, column, \
                                                    str16, str9, str10);
    Describe12->add_Specification();
    Describe13 = new Specification(this,Describe13_explain, myTable, line++, column, \
                                                    str17, str9, str10);
    Describe13->add_Specification();
    Describe14 = new Specification(this,Describe14_explain, myTable, line++, column, \
                                                    str18, str9, str10);
    Describe14->add_Specification();
    Describe15 = new Specification(this,Describe15_explain, myTable, line++, column, \
                                                    str20, str9, str10);
    Describe15->add_Specification();

    Describe = new Specification(this,Describe_explain, myTable, line++, column, \
                                                    str8, str9, str10);
    Describe->add_Specification();
    Describe2 = new Specification(this,Describe2_explain, myTable, line++, column, \
                                                    str8, str9, str10);
    Describe2->add_Specification();
    Describe3 = new Specification(this,Describe3_explain, myTable, line++, column, \
                                                    str11, str9, str10);
    Describe3->add_Specification();
    Describe4 = new Specification(this,Describe4_explain, myTable, line++, column, \
                                                    str8, str9, str10);
    Describe4->add_Specification();
    Describe5 = new Specification(this,Describe5_explain, myTable, line++, column, \
                                                    str12, str9, str10);
    Describe5->add_Specification();
    Describe6 = new Specification(this,Describe6_explain, myTable, line++, column, \
                                                    str8, str9, str10);
    Describe6->add_Specification();
    Describe7 = new Specification(this,Describe7_explain, myTable, line++, column, \
                                                    str11, str9, str10);
    Describe7->add_Specification();
    Describe8 = new Specification(this,Describe8_explain, myTable, line++, column, \
                                                    str12, str9, str10);
    Describe8->add_Specification();
}

/***************************************************************
 * 操作日志
 ***************************************************************/
void MEGAWin::OperationLog()
{
    QString str = tr("ModificationTime");
    QString str1 = tr("Time when the system Settings are modified.");
    QString str2 = tr("RecordEvent");
    QString str3 = tr("System settings operation records.");

    if(LanguageType == 0)
    {
        ModificationTime = new Specification(this,ModificationTime_explain, ui->Operation_tableWidget, 0, 0, \
                                                        "2023-05-12 11:32:45", str, str1);
        ModificationTime->add_Specification();
        ModificationTime2 = new Specification(this,ModificationTime2_explain, ui->Operation_tableWidget, 1, 0, \
                                                        "2023-05-12 11:32:33", str, str1);
        ModificationTime2->add_Specification();
        ModificationTime3 = new Specification(this,ModificationTime3_explain, ui->Operation_tableWidget, 2, 0, \
                                                        "2023-05-12 19:29:24", str, str1);
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
    }
    else {
        ModificationTime = new Specification(this,ModificationTime_explain, ui->Operation_tableWidget, 0, 0, \
                                                        "12-05-2023 11:32:45", str, str1);
        ModificationTime->add_Specification();
        ModificationTime2 = new Specification(this,ModificationTime2_explain, ui->Operation_tableWidget, 1, 0, \
                                                        "12-05-2023 11:32:33", str, str1);
        ModificationTime2->add_Specification();
        ModificationTime3 = new Specification(this,ModificationTime3_explain, ui->Operation_tableWidget, 2, 0, \
                                                        "11-05-2023 19:29:24", str, str1);
        ModificationTime3->add_Specification();
        ModificationTime4 = new Specification(this,ModificationTime4_explain, ui->Operation_tableWidget, 3, 0, \
                                                        "11-05-2023 19:29:21", str, str1);
        ModificationTime4->add_Specification();
        ModificationTime5 = new Specification(this,ModificationTime5_explain, ui->Operation_tableWidget, 4, 0, \
                                                        "11-05-2023 19:29:10", str, str1);
        ModificationTime5->add_Specification();
        ModificationTime6 = new Specification(this,ModificationTime6_explain, ui->Operation_tableWidget, 5, 0, \
                                                        "11-05-2023 19:29:07", str, str1);
        ModificationTime6->add_Specification();
        ModificationTime7 = new Specification(this,ModificationTime7_explain, ui->Operation_tableWidget, 6, 0, \
                                                        "11-05-2023 17:21:16", str, str1);
        ModificationTime7->add_Specification();
        ModificationTime8 = new Specification(this,ModificationTime8_explain, ui->Operation_tableWidget, 7, 0, \
                                                        "11-05-2023 11:21:02", str, str1);
        ModificationTime8->add_Specification();
        ModificationTime9 = new Specification(this,ModificationTime9_explain, ui->Operation_tableWidget, 8, 0, \
                                                        "11-05-2023 11:20:58", str, str1);
        ModificationTime9->add_Specification();
        ModificationTime10 = new Specification(this,ModificationTime10_explain, ui->Operation_tableWidget, 9, 0, \
                                                        "11-05-2023 11:02:22", str, str1);
        ModificationTime10->add_Specification();
        ModificationTime11 = new Specification(this,ModificationTime11_explain, ui->Operation_tableWidget, 10, 0, \
                                                        "11-05-2023 11:02:18", str,  str1);
        ModificationTime11->add_Specification();
        ModificationTime12 = new Specification(this,ModificationTime12_explain, ui->Operation_tableWidget, 11, 0, \
                                                        "11-05-2023 11:02:14", str, str1);
        ModificationTime12->add_Specification();
    }

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

/***************************************************************
 * PCS故障信息表初始化
 ***************************************************************/
/*void MEGAWin::RTAlarm()
//{
//    ui->RTAlarm_Data_page->setColumnCount(5);
//    ui->RTAlarm_Data_page->setRowCount(28);
//    ui->RTAlarm_Data_page->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
//    ui->RTAlarm_Data_page->verticalHeader()->setVisible(false);//设置垂直头不可见
//    ui->RTAlarm_Data_page->setFrameShape(QFrame::NoFrame);//设置无边框
//    ui->RTAlarm_Data_page->setShowGrid(true);//设置显示格子
//    ui->RTAlarm_Data_page->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
//    ui->RTAlarm_Data_page->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
//    ui->RTAlarm_Data_page->setStyleSheet("selection-background-color:lightblue;");

//    ui->RTAlarm_Data_page->setColumnWidth(0,110);
//    ui->RTAlarm_Data_page->setColumnWidth(1,85);
//    ui->RTAlarm_Data_page->setColumnWidth(2,305);
//    ui->RTAlarm_Data_page->setColumnWidth(3,200);
//    ui->RTAlarm_Data_page->setColumnWidth(4,250);

//    QStringList RTAlarm_Title;
//    RTAlarm_Title << tr("Alarm name") << tr("Alarm leve")<< tr("Trigger condition") \
//                    << tr("Response action")<< tr("Whether to reset\nautomatically and reset time");
//    ui->RTAlarm_Data_page->setHorizontalHeaderLabels(RTAlarm_Title);

//    PCS_Alarm_information_table();  //展示PCS故障信息表
//    excel_read(ui->RTAlarm_Data_page);
}*/

/***************************************************************
 * 电池数据
 ***************************************************************/
void MEGAWin::BatteryData_clicked(int nid)
{
    switch (nid) {
    case 0:
        QMessageBox::question(this, tr("Bat volage")\
                              ,tr("Total voltage of the battery uploaded by BMS."), tr("OK"));
        break;
    case 1:
        QMessageBox::question(this, tr("Bat current")\
                              ,tr("Total current of the battery uploaded by BMS."), tr("OK"));
        break;
    case 2:
        QMessageBox::question(this, tr("SOC")\
                              ,tr("Battery SOH uploaded from BMS, the percentage of available capacity after full charge compared to the rated capacity."), tr("OK"));
        break;
    case 3:
        QMessageBox::question(this, tr("SOH")\
                              ,tr("Battery SOC uploaded by BMS refers to the current remaining battery capacity percentage."), tr("OK"));
        break;
    case 4:
        QMessageBox::question(this, tr("Cell voltage(max)")\
                              ,tr("The highest voltage of single cell uploaded by BMS."), tr("OK"));
        break;
    case 5:
        QMessageBox::question(this, tr("Cell voltage(min)")\
                              ,tr("The lowest voltage of single cell uploaded by BMS."), tr("OK"));
        break;
    case 6:
        QMessageBox::question(this, tr("Cell temp.(max)")\
                              ,tr("The highest temperature of single cell uploaded by BMS."), tr("OK"));
        break;
    case 7:
        QMessageBox::question(this, tr("Cell temp.(min)")\
                              ,tr("The lowest temperature of single cell uploaded by BMS."), tr("OK"));
        break;
    case 8:
        QMessageBox::question(this, tr("Charging current limit")\
                              ,tr("The limit of charging current uploaded by BMS."), tr("OK"));
        break;
    case 9:
        QMessageBox::question(this, tr("Discharging current limit")\
                              ,tr("The limit of discharging current uploaded by BMS."), tr("OK"));
        break;
    case 10:
        QMessageBox::question(this, tr("Allowable charging power")\
                              ,tr("The allowable charging power uploaded by BMS."), tr("OK"));
        break;
    case 11:
        QMessageBox::question(this, tr("Allowable discharging power")\
                              ,tr("The allowable discharging power uploaded by BMS."), tr("OK"));
        break;
    case 12:
        QMessageBox::question(this, tr("Allowable charging energy")\
                              ,tr("The allowable charging capacity uploaded by BMS."), tr("OK"));
        break;
    case 13:
        QMessageBox::question(this, tr("Allowable discharging energy")\
                              ,tr("The allowable discharging capacity uploaded by BMS."), tr("OK"));
        break;
    case 14:
        QMessageBox::question(this, tr("Alarm level")\
                              ,tr("Alarm levels uploaded from BMS, level one alarm is yellow, level two alarm is orange, and level three alarm is red;\nBy default, the converter does not respond to level one and level two alarms, but shuts down in response to level three alarms."), tr("OK"));
        break;
    case 15:
        QMessageBox::question(this, tr("Charging enable")\
                              ,tr("Battery Status Uploaded by BMS: Enable indicates the battery is allowed to charge, Disable indicates the battery is not allowed to charge."), tr("OK"));
        break;
    case 16:
        QMessageBox::question(this, tr("Discharging enable")\
                              ,tr("Battery Status Uploaded by BMS: Enable indicates the battery is allowed to discharge, Disable indicates the battery is not allowed to discharge."), tr("OK"));
        break;
    default:
        break;
    }
}

/***************************************************************
 * PCS数据
 ***************************************************************/
void MEGAWin::PCS_Data()
{
    if(PCS_vol_AB != nullptr)
    {
        delete PCS_vol_AB;
    }
    PCS_vol_AB = new Specification(this,PCS_vol_AB_explain, ui->Converter_Tab, 0, 1, \
                                            "0V", tr("Inv. voltage(AB)"), \
                                            tr("Inv. side AB line voltage."));
    PCS_vol_AB->add_Specification();

    if(PCS_vol_BC != nullptr)
    {
        delete PCS_vol_BC;
    }
    PCS_vol_BC = new Specification(this,PCS_vol_BC_explain, ui->Converter_Tab, 1, 1, \
                                            "0V", tr("Inv. voltage(BC)"), \
                                            tr("Inv. side BC line voltage."));
    PCS_vol_BC->add_Specification();

    if(PCS_vol_CA != nullptr)
    {
        delete PCS_vol_CA;
    }
    PCS_vol_CA = new Specification(this,PCS_vol_CA_explain, ui->Converter_Tab, 2, 1, \
                                            "0V", tr("Inv. voltage(CA)"), \
                                            tr("Inv. side CA line voltage."));
    PCS_vol_CA->add_Specification();

    if(PCS_cur_A != nullptr)
    {
        delete PCS_cur_A;
    }
    PCS_cur_A = new Specification(this,PCS_cur_A_explain, ui->Converter_Tab, 3, 1, \
                                            "0A", tr("Inv. current(A)"), \
                                            tr("Inv. side A phase current."));
    PCS_cur_A->add_Specification();

    if(PCS_cur_B != nullptr)
    {
        delete PCS_cur_B;
    }
    PCS_cur_B = new Specification(this,PCS_cur_B_explain, ui->Converter_Tab, 4, 1, \
                                            "0A", tr("Inv. current(B)"), \
                                            tr("Inv. side B phase current."));
    PCS_cur_B->add_Specification();

    if(PCS_cur_C != nullptr)
    {
        delete PCS_cur_C;
    }
    PCS_cur_C = new Specification(this,PCS_cur_C_explain, ui->Converter_Tab, 5, 1, \
                                            "0A", tr("Inv. current(C)"), \
                                            tr("Inv. side C phase current."));
    PCS_cur_C->add_Specification();

    if(PCS_act_P != nullptr)
    {
        delete PCS_act_P;
    }
    PCS_act_P = new Specification(this,PCS_act_P_explain, ui->Converter_Tab, 6, 1, \
                                            "0kW", tr("Inv. active power"), \
                                            tr("Active power P on the inv. side of the converter."));
    PCS_act_P->add_Specification();

    if(PCS_rea_P != nullptr)
    {
        delete PCS_rea_P;
    }
    PCS_rea_P = new Specification(this,PCS_rea_P_explain, ui->Converter_Tab, 7, 1, \
                                            "0kVar", tr("Inv. reactive power"), \
                                            tr("Reactive power Q on the inv. side of the converter."));
    PCS_rea_P->add_Specification();

    if(PCS_par_P != nullptr)
    {
        delete PCS_par_P;
    }
    PCS_par_P = new Specification(this,PCS_par_P_explain, ui->Converter_Tab, 8, 1, \
                                            "0kVA", tr("Inv. apparent power"), \
                                            tr("Apparent power S on the inv. side of the converter."));
    PCS_par_P->add_Specification();

    if(PCS_Pf != nullptr)
    {
        delete PCS_Pf;
    }

    PCS_Pf = new Specification(this,PCS_Pf_explain, ui->Converter_Tab, 9, 1, \
                                            "0", tr("Inv. power factor"), \
                                            tr("Power factor PF on the inv. side of the converter."));
    PCS_Pf->add_Specification();

    if(PCS_Bat_vol != nullptr)
    {
        delete PCS_Bat_vol;
    }
    PCS_Bat_vol = new Specification(this,PCS_Bat_vol_explain, ui->Converter_Tab, 0, 3, \
                                            "0V", tr("Battery voltage"), \
                                            tr("Converter battery side voltage."));
    PCS_Bat_vol->add_Specification();

    if(PCS_Bat_cur != nullptr)
    {
        delete PCS_Bat_cur;
    }
    PCS_Bat_cur = new Specification(this,PCS_Bat_cur_explain, ui->Converter_Tab, 1, 3, \
                                            "0A", tr("Battery current"), \
                                            tr("Converter battery side current."));
    PCS_Bat_cur->add_Specification();

    if(PCS_Bat_P != nullptr)
    {
        delete PCS_Bat_P;
    }
    PCS_Bat_P = new Specification(this,PCS_Bat_P_explain, ui->Converter_Tab, 2, 3, \
                                            "0kW", tr("Battery power"), \
                                            tr("Converter battery side power."));
    PCS_Bat_P->add_Specification();

    if(PCS_Bus_vol != nullptr)
    {
        delete PCS_Bus_vol;
    }
    PCS_Bus_vol = new Specification(this,PCS_Bus_vol_explain, ui->Converter_Tab, 3, 3, \
                                            "0V", tr("Bus voltage"), \
                                            tr("Converter bus voltage."));
    PCS_Bus_vol->add_Specification();

    if(PCS_IGBT_T != nullptr)
    {
        delete PCS_IGBT_T;
    }
    PCS_IGBT_T = new Specification(this,PCS_IGBT_T_explain, ui->Converter_Tab, 4, 3, \
                                            "0℃", tr("IGBT temperature"), \
                                            tr("The IGBT temperature of the converter: The IGBT temperature must not exceed 102°C. Otherwise, the converter will operate at a reduced capacity. It will resume full power operation when the temperature drops to 73°C."));
    PCS_IGBT_T->add_Specification();

    if(PCS_Env_T != nullptr)
    {
        delete PCS_Env_T;
    }
    PCS_Env_T = new Specification(this,PCS_Env_T_explain, ui->Converter_Tab, 5, 3, \
                                            "0℃", tr("Environment temperature"), \
                                            tr("”The ambient temperature."));
    PCS_Env_T->add_Specification();
}

/***************************************************************
 * 电网数据
 ***************************************************************/
void MEGAWin::Grid_Data()
{
    if(Grid_vol_AB != nullptr)
    {
        delete Grid_vol_AB;
    }
    Grid_vol_AB = new Specification(this,Grid_vol_AB_explain, ui->Grid_Tab, 0, 1, \
                                            "0V", tr("Grid voltage(AB)"), \
                                            tr("Grid side AB line voltage."));
    Grid_vol_AB->add_Specification();

    if(Grid_vol_BC != nullptr)
    {
        delete Grid_vol_BC;
    }
    Grid_vol_BC = new Specification(this,Grid_vol_BC_explain, ui->Grid_Tab, 1, 1, \
                                            "0V", tr("Grid voltage(BC)"), \
                                            tr("Grid side BC line voltage."));
    Grid_vol_BC->add_Specification();

    if(Grid_vol_CA != nullptr)
    {
        delete Grid_vol_CA;
    }
    Grid_vol_CA = new Specification(this,Grid_vol_CA_explain, ui->Grid_Tab, 2, 1, \
                                            "0V", tr("Grid voltage(CA)"), \
                                            tr("Grid side CA line voltage."));
    Grid_vol_CA->add_Specification();

    if(Grid_cur_A != nullptr)
    {
        delete Grid_cur_A;
    }
    Grid_cur_A = new Specification(this,Grid_cur_A_explain, ui->Grid_Tab, 3, 1, \
                                            "0A", tr("Grid current(A)"), \
                                            tr("Grid side A phase current."));
    Grid_cur_A->add_Specification();

    if(Grid_cur_B != nullptr)
    {
        delete Grid_cur_B;
    }
    Grid_cur_B = new Specification(this,Grid_cur_B_explain, ui->Grid_Tab, 4, 1, \
                                            "0A", tr("Grid current(B)"), \
                                            tr("Grid side B phase current."));
    Grid_cur_B->add_Specification();

    if(Grid_cur_C != nullptr)
    {
        delete Grid_cur_C;
    }
    Grid_cur_C = new Specification(this,Grid_cur_C_explain, ui->Grid_Tab, 5, 1, \
                                            "0A", tr("Grid current(C)"), \
                                            tr("Grid side C phase current."));
    Grid_cur_C->add_Specification();

    if(Grid_act_P != nullptr)
    {
        delete Grid_act_P;
    }
    Grid_act_P = new Specification(this,Grid_act_P_explain, ui->Grid_Tab, 6, 1, \
                                            "0kW", tr("Grid active power"), \
                                            tr("Active power P on the grid side of the converter."));
    Grid_act_P->add_Specification();

    if(Grid_rea_P != nullptr)
    {
        delete Grid_rea_P;
    }
    Grid_rea_P = new Specification(this,Grid_rea_P_explain, ui->Grid_Tab, 7, 1, \
                                            "0kVar", tr("Grid reactive power"), \
                                            tr("Reactive power Q on the grid side of the converter."));
    Grid_rea_P->add_Specification();

    if(Grid_app_P != nullptr)
    {
        delete Grid_app_P;
    }
    Grid_app_P = new Specification(this,Grid_app_P_explain, ui->Grid_Tab, 8, 1, \
                                            "0kVA", tr("Grid apparent power"), \
                                            tr("Apparent power S on the grid side of the converter."));
    Grid_app_P->add_Specification();

    if(Grid_fre != nullptr)
    {
        delete Grid_fre;
    }
    Grid_fre = new Specification(this,Grid_fre_explain, ui->Grid_Tab, 9, 1, \
                                            "0Hz", tr("Grid frequency"), \
                                            tr("Frequency on the grid side of the converter."));
    Grid_fre->add_Specification();

    if(Grid_Pf != nullptr)
    {
        delete Grid_Pf;
    }
    Grid_Pf = new Specification(this,Grid_Pf_explain, ui->Grid_Tab, 10, 1, \
                                            "0", tr("Grid power factor"), \
                                            tr("Power factor PF on the grid side of the converter."));
    Grid_Pf->add_Specification();
}

/***************************************************************
 * 负载数据
 ***************************************************************/
void MEGAWin::Load_Data()
{
    if(Load_vol_AB != nullptr)
    {
        delete Load_vol_AB;
    }
    Load_vol_AB = new Specification(this,Load_vol_AB_explain, ui->Load_Tab, 0, 1, \
                                            "0V", tr("Load voltage(AB)"), \
                                            tr("Load side AB line voltage."));
    Load_vol_AB->add_Specification();

    if(Load_vol_BC != nullptr)
    {
        delete Load_vol_BC;
    }
    Load_vol_BC = new Specification(this,Load_vol_BC_explain, ui->Load_Tab, 1, 1, \
                                            "0V", tr("Load voltage(BC)"), \
                                            tr("Load side BC line voltage."));
    Load_vol_BC->add_Specification();

    if(Load_vol_CA != nullptr)
    {
        delete Load_vol_CA;
    }
    Load_vol_CA = new Specification(this,Load_vol_CA_explain, ui->Load_Tab, 2, 1, \
                                            "0V", tr("Load voltage(CA)"), \
                                            tr("Load side CA line voltage."));
    Load_vol_CA->add_Specification();

    if(Load_cur_A != nullptr)
    {
        delete Load_cur_A;
    }
    Load_cur_A = new Specification(this,Load_cur_A_explain, ui->Load_Tab, 3, 1, \
                                            "0A", tr("Load current(A)"), \
                                            tr("Load side A phase current."));
    Load_cur_A->add_Specification();

    if(Load_cur_B != nullptr)
    {
        delete Load_cur_B;
    }
    Load_cur_B = new Specification(this,Load_cur_B_explain, ui->Load_Tab, 4, 1, \
                                            "0A", tr("Load current(B)"), \
                                            tr("Load side B phase current."));
    Load_cur_B->add_Specification();

    if(Load_cur_C != nullptr)
    {
        delete Load_cur_C;
    }
    Load_cur_C = new Specification(this,Load_cur_C_explain, ui->Load_Tab, 5, 1, \
                                            "0A", tr("Load current(C)"), \
                                            tr("Load side C phase current."));
    Load_cur_C->add_Specification();

    if(Load_act_P != nullptr)
    {
        delete Load_act_P;
    }
    Load_act_P = new Specification(this,Load_act_P_explain, ui->Load_Tab, 6, 1, \
                                            "0kW", tr("Load active power"), \
                                            tr("Active power P on the load side of the converter."));
    Load_act_P->add_Specification();

    if(Load_rea_P != nullptr)
    {
        delete Load_rea_P;
    }
    Load_rea_P = new Specification(this,Load_rea_P_explain, ui->Load_Tab, 7, 1, \
                                            "0kVar", tr("Load reactive power"), \
                                            tr("Reactive power Q on the load side of the converter."));
    Load_rea_P->add_Specification();

    if(Load_app_P != nullptr)
    {
        delete Load_app_P;
    }
    Load_app_P = new Specification(this,Load_app_P_explain, ui->Load_Tab, 8, 1, \
                                            "0kVA", tr("Load apparent power"), \
                                            tr("Apparent power S on the load side of the converter."));
    Load_app_P->add_Specification();

    if(Load_Pf != nullptr)
    {
        delete Load_Pf;
    }
    Load_Pf = new Specification(this,Load_Pf_explain, ui->Load_Tab, 9, 1, \
                                            "0", tr("Load power factor"), \
                                            tr("Power factor PF on the load side of the converter."));
    Load_Pf->add_Specification();
}

/***************************************************************
 * PCS状态
 ***************************************************************/
void MEGAWin::PCS_State()
{
    if(DC_input_Breaker != nullptr)
    {
        delete DC_input_Breaker;
    }
    DC_input_Breaker = new Specification(this,DC_input_Breaker_explain, ui->RTState_Bypass_Tab, 0, 1, \
                                            tr("On"), tr("DC input Breaker"), \
                                            tr("There are two states for a DC circuit breaker: On, Off."));
    DC_input_Breaker->add_Specification();

    if(DC_Cont != nullptr)
    {
        delete DC_Cont;
    }
    DC_Cont = new Specification(this,DC_Cont_explain, ui->RTState_Bypass_Tab, 1, 1, \
                                            tr("On"), tr("DC contactor"), \
                                            tr("The DC contactor has two states: On, Off. After the soft start of the DC side is completed, the DC contactor closes. When the DC side of the battery is disconnected and the voltage of the DC bus drops to a certain level, the DC contactor opens."));
    DC_Cont->add_Specification();

    if(Output_Cont != nullptr)
    {
        delete Output_Cont;
    }
    Output_Cont = new Specification(this,Output_Cont_explain, ui->RTState_Bypass_Tab, 2, 1, \
                                            tr("On"), tr("Output contactor"), \
                                            tr("The output contactor has two states: On, Off. The output contactor closes after the soft start on the inv. side is completed. The output contactor opens when the converter is shut down."));
    Output_Cont->add_Specification();

    if(Output_Breaker != nullptr)
    {
        delete Output_Breaker;
    }
    Output_Breaker = new Specification(this,Output_Breaker_explain, ui->RTState_Bypass_Tab, 3, 1, \
                                            tr("On"), tr("Output Breaker"), \
                                            tr("The output circuit breaker has two states: On, Off. It can only be manually opened and closed."));
    Output_Breaker->add_Specification();

    if(Grid_Cont != nullptr)
    {
        delete Grid_Cont;
    }
    Grid_Cont = new Specification(this,Grid_Cont_explain, ui->RTState_Bypass_Tab, 4, 1, \
                                            tr("On"), tr("Grid contactor"), \
                                            tr("The grid contactor has two states: On, Off. When the inverter is in grid-connected mode and the grid voltage is normal, the grid contactor is closed. When the inverter is in island mode, the grid contactor is open. In the islanded state, the grid contactor remains open."));
    Grid_Cont->add_Specification();

    if(Grid_Breaker != nullptr)
    {
        delete Grid_Breaker;
    }
    Grid_Breaker = new Specification(this,Grid_Breaker_explain, ui->RTState_Bypass_Tab, 5, 1, \
                                            tr("On"), tr("Grid Breaker"), \
                                            tr("The power grid circuit breaker has two states: On, Off; The power grid circuit breaker can only be manually disconnected."));
    Grid_Breaker->add_Specification();

    if(MB_Breaker != nullptr)
    {
        delete MB_Breaker;
    }
    MB_Breaker = new Specification(this,MB_Breaker_explain, ui->RTState_Bypass_Tab, 6, 1, \
                                            tr("On"), tr("Maintenance Bypass Breaker"), \
                                            tr("There are two states for the maintenance bypass circuit breaker: On, Off. This circuit breaker is only used for machine maintenance. If maintenance is required, please contact the maintenance personnel."));
    MB_Breaker->add_Specification();

    if(converter_available != nullptr)
    {
        delete converter_available;
    }
    converter_available = new Specification(this,converter_available_explain, ui->RTState_Bypass_Tab, 0, 3, \
                                            tr("Disabled"), tr("converter available"), \
                                            tr("The converter has two states: Enable,Disabled. The converter is enabled when the self-check is successful. Otherwise, the converter is disabled."));
    converter_available->add_Specification();

    if(DC_Soft_start != nullptr)
    {
        delete DC_Soft_start;
    }
    DC_Soft_start = new Specification(this,DC_Soft_start_explain, ui->RTState_Bypass_Tab, 1, 3, \
                                            tr("Not starting"), tr("DC Soft start"), \
                                            tr("There are three states for DC soft start: Not starting, Soft starting, and Complete. Soft start refers to the process in which the converter charges the busbar with the battery during startup, causing the busbar voltage to rise close to the battery voltage."));
    DC_Soft_start->add_Specification();

    if(converter_status != nullptr)
    {
        delete converter_status;
    }
    converter_status = new Specification(this,converter_status_explain, ui->RTState_Bypass_Tab, 2, 3, \
                                            tr("Shut down"), tr("converter status"), \
                                            tr("Converter states include: OFF, AC Soft Start, Grid-ON Charge, Grid-ON Discharge, Grid-OFF Discharge, Derating grid-on, Standby, Grid-OFF Charge, Constant Voltage Discharge and Constant Voltage Charge."));
    converter_status->add_Specification();

    if(Reactive_P_Regulation != nullptr)
    {
        delete Reactive_P_Regulation;
    }
    Reactive_P_Regulation = new Specification(this,Reactive_P_Regulation_explain, ui->RTState_Bypass_Tab, 3, 3, \
                                            tr("Disable"), tr("Reactive Power Regulation"), \
                                            tr("There are three types of reactive power regulation: Disable,PF regulation, and  regulation."));
    Reactive_P_Regulation->add_Specification();

    if(LVRT != nullptr)
    {
        delete LVRT;
    }
    LVRT = new Specification(this,LVRT_explain, ui->RTState_Bypass_Tab, 4, 3, \
                                            tr("Disable"), tr("LVRT"), \
                                            tr("LVRT states : Enable , Disable."));
    LVRT->add_Specification();

    if(Generator_signal != nullptr)
    {
        delete Generator_signal;
    }
    Generator_signal = new Specification(this,Generator_signal_explain, ui->RTState_Bypass_Tab, 0, 5, \
                                            tr("Enable"), tr("Start Diesel Generator Signal"), \
                                            tr("Signal to start the diesel generator, start the diesel generator when enabled, stop the diesel generator when disabled."));
    Generator_signal->add_Specification();

    if(Reserve != nullptr)
    {
        delete Reserve;
    }
    Reserve = new Specification(this,Reserve_explain, ui->RTState_Bypass_Tab, 1, 5, \
                                            tr("Disable"), tr("DO2"), \
                                            tr("Dry contact 2 is output."));
    Reserve->add_Specification();

    if(Reserve2 != nullptr)
    {
        delete Reserve2;
    }
    Reserve2 = new Specification(this,Reserve2_explain, ui->RTState_Bypass_Tab, 2, 5, \
                                            tr("Disable"), tr("DO3"), \
                                            tr("Dry contact 3 is output."));
    Reserve2->add_Specification();

    if(EPO_Cont_signal1 != nullptr)
    {
        delete EPO_Cont_signal1;
    }
    EPO_Cont_signal1 = new Specification(this,EPO_Cont_signal1_explain, ui->RTState_Bypass_Tab, 3, 5, \
                                            tr("Disable"), tr("Dry contact EPO"), \
                                            tr("Dry contact EPO：Enable，Disable."));
    EPO_Cont_signal1->add_Specification();

    if(EPO_Cont_signal2 != nullptr)
    {
        delete EPO_Cont_signal2;
    }
    EPO_Cont_signal2 = new Specification(this,EPO_Cont_signal2_explain, ui->RTState_Bypass_Tab, 4, 5, \
                                            tr("Disable"), tr("Dry contact Shutdown"), \
                                            tr("Dry contact Shutdown：Enable，Disable."));
    EPO_Cont_signal2->add_Specification();

    if(Access_signal != nullptr)
    {
        delete Access_signal;
    }
    Access_signal = new Specification(this,Access_signal_explain, ui->RTState_Bypass_Tab, 5, 5, \
                                            tr("Disable"), tr("Access signal"), \
                                            tr("Access signal:Enable, Disable."));
    Access_signal->add_Specification();

    if(Full_P_signal != nullptr)
    {
        delete Full_P_signal;
    }
    Full_P_signal = new Specification(this,Full_P_signal_explain, ui->RTState_Bypass_Tab, 6, 5, \
                                            tr("Disable"), tr("Full power signal"), \
                                            tr("Full power signal:Enable, Disable."));
    Full_P_signal->add_Specification();

    if(Smoke_alarm_signal != nullptr)
    {
        delete Smoke_alarm_signal;
    }
    Smoke_alarm_signal = new Specification(this,Smoke_alarm_signal_explain, ui->RTState_Bypass_Tab, 7, 5, \
                                            tr("Disable"), tr("Smoke alarm signal"), \
                                            tr("Smoke alarm signal:Enable, Disable."));
    Smoke_alarm_signal->add_Specification();

    if(Hight_temp_signal != nullptr)
    {
        delete Hight_temp_signal;
    }
    Hight_temp_signal = new Specification(this,Hight_temp_signal_explain, ui->RTState_Bypass_Tab, 8, 5, \
                                            tr("Disable"), tr("Fire fighting signal"), \
                                            tr("Fire fighting signal:Enable, Disable."));
    Hight_temp_signal->add_Specification();
}

/***************************************************************
 * 系统设置
 ***************************************************************/
void MEGAWin::ParameterSet()
{
    int line=0;int column=1;
    if(Grid_connected_mode != NULL)
    {
        delete Grid_connected_mode;
    }
    Grid_connected_mode = new Specification(this,Grid_connected_mode_explain, ui->System_Tab, line++, column, \
                                            tr("automatic"), tr("Grid conected mode of the converter "), \
                                            tr("When \"Auto\" is selected, the converter will automatically switch between grid-on and grid-off. When the grid side is normal, the converter operates in grid-on mode (PQ).When the grid side is abnormal, the converter operates in grid-off mode (VF).\
                                               When \"Grid-on\" is selected, the converter operates in grid-on mode (PQ).When the grid side is abnormal, the converter will shut down.\
                                               When \"Grid-off\" is selected, the converter operates in grid-off mode (VF)."));
    Grid_connected_mode->add_Specification();

    if(Constant_power != NULL)
    {
        delete Constant_power;
    }
    Constant_power = new Specification(this,Constant_power_explain, ui->System_Tab, line++, column, \
                                       tr("0"), tr("Constant power(AC)"), \
                                       tr("AC Side Power: You can control the charging and discharging power of the battery from the AC side by modifying this value. When the advanced setting for power control mode is set to Constant Power mode (CP_N&P), a positive value indicates discharging, and a negative value indicates charging.\
\nFor example, setting it to -5 means that the AC side will charge the battery at a power of -5 kW. Due to converter losses, the DC side power will be lower than the AC side power in this case. Setting it to 5 means that the AC side will output power at 5 kW. Due to converter losses, the DC side power will be higher than the AC side power in this case."));
    Constant_power->add_Specification();


   Work_mode_explain->setText(tr("Manual"));
   ui->System_Tab->setCellWidget(line++, column, (QWidget *)Work_mode_explain);
    /*if(Work_mode != NULL)
    {
        delete Work_mode;
    }
    Work_mode = new Specification(this,Work_mode_explain, ui->System_Tab, line++, column, \
                                  tr("Manual"), tr("Work mode"), \
                                  tr("When selecting the manual mode, the converter’s operating status, charging or discharging power (active power), reactive power, power factor etc,can be controlled through HMI or EMS.\
                                     When selecting the UPS mode, When the grid side is abnormal, the system will switch from zero power to grid-off discharge mode to provide energy to critical loads. Please go to the \"Battery Settings\" page to configure this mode. Note: This mode is only applicable to lithium battery mode and requires normal communication between the converter and BMS.\
                                     Peak shaving and valley filling mode is used for peak-valley price arbitrage. The converter can operate according to the local peak-valley electricity price periods. Please set the operating time period, charging or discharging mode, charging or discharging power, and other information on the \"Mixed mode\" page."));
    Work_mode->add_Specification();*/

    if(Output_power_factor != NULL)
    {
        delete Output_power_factor;
    }
    Output_power_factor = new Specification(this,Output_power_factor_explain, ui->System_Tab, line++, column, \
                                            tr("1"), tr("Output power factor"), \
                                            tr("This item can modify the power factor, where the power factor is equal to the ratio of active power to apparent power. A positive value indicates leading reactive power, while a negative value indicates lagging reactive power."));
    Output_power_factor->add_Specification();

    if(Output_reactive_power != NULL)
    {
        delete Output_reactive_power;
    }
    Output_reactive_power = new Specification(this,Output_reactive_power_explain, ui->System_Tab, line++, column, \
                                              tr("1"), tr("Output reactive power"), \
                                              tr("This parameter can change the reactive power Q, positive value indicates leading reactive power, negative value indicates lagging reactive power."));
    Output_reactive_power->add_Specification();

    if(Constant_current != NULL)
    {
        delete Constant_current;
    }
    Constant_current = new Specification(this,Constant_current_explain, ui->System_Tab, line++, column, \
                                         tr("100"), tr("Constant current"), \
                                         tr("Enter the advanced settings interface and select the control power mode. Choose constant voltage and modify the voltage value. Converter will operate at the constant voltage value and function as a constant voltage source."));
    Constant_current->add_Specification();

    if(Constant_voltage != NULL)
    {
        delete Constant_voltage;
    }
    Constant_voltage = new Specification(this,Constant_voltage_explain, ui->System_Tab, line++, column, \
                                         tr("600"), tr("Constant voltage"), \
                                         tr("Enter the advanced settings interface and select the control power mode. Choose constant current and modify the current value. Converter will charge or discharge the battery with this current value. Positive values represent discharging, while negative values represent charging."));
    Constant_voltage->add_Specification();

    if(Control_mode != NULL)
    {
        delete Control_mode;
    }
    line = 0;
    column = 4;
    Control_mode = new Specification(this,Control_mode_explain, ui->System_Tab, line++, column, \
                                     tr("Local"), tr("Control mode"), \
                                     tr("Local: Converter control through HMI, In this mode, the EMS can only read and cannot write.\
\nRemote: In remote mode, the EMS can perform both read and write control."));
    Control_mode->add_Specification();

    if(Machine_number != NULL)
    {
        delete Machine_number;
    }
    Machine_number = new Specification(this,Machine_number_explain, ui->System_Tab, line++, column, \
                                       tr("M_01"), tr("Machine number"), \
                                       tr("Device number: You can set ID number, which can be set within the range of M_01 to M_12."));
    Machine_number->add_Specification();

    if(Parallel != NULL)
    {
        delete Parallel;
    }
    Parallel = new Specification(this,Parallel_explain, ui->System_Tab, line++, column, \
                                 tr("Disable"), tr("Parallel"), \
                                 tr("Parallel operation: When converter operates at grid-off mode in parallel, this item needs to be enabled."));
    Parallel->add_Specification();
}

/***************************************************************
 * 电池设置
 ***************************************************************/
void MEGAWin::BetterySetup()
{
    int line=0;int column=1;
    if(DOD_OnGrid != nullptr)
    {
        delete DOD_OnGrid;
    }
    DOD_OnGrid = new Specification(this,DOD_OnGrid_explain, ui->Lithum_Tab, line++, column, \
                                     "0", tr("Grid-on DOD"), \
                                     tr("Grid-on DOD, allowable depth of discharge in grid-on mode."));
    DOD_OnGrid->add_Specification();

    if(DOD_OffGrid != nullptr)
    {
        delete DOD_OffGrid;
    }
    DOD_OffGrid = new Specification(this,DOD_OffGrid_explain, ui->Lithum_Tab, line++, column, \
                                     "0", tr("Grid-off DOD"), \
                                     tr("Grid-off DOD, allowable depth of discharge in grid-off mode."));
    DOD_OffGrid->add_Specification();

    if(Charge_Vol_Up_Limit != nullptr)
    {
        delete Charge_Vol_Up_Limit;
    }
    Charge_Vol_Up_Limit = new Specification(this,Charge_Vol_Up_Limit_explain, ui->Lithum_Tab, line++, column, \
                                     "0", tr("Charge Volt upper Limit"), \
                                     tr("Charging voltage upper limit: When the battery total voltage reaches this value during charging, the converter will shut down."));
    Charge_Vol_Up_Limit->add_Specification();

    if(Charge_Vol_upper_Limit_delta != nullptr)
    {
        delete Charge_Vol_upper_Limit_delta;
    }
    Charge_Vol_upper_Limit_delta = new Specification(this,Charge_Vol_upper_Limit_delta_explain, ui->Lithum_Tab, line++, column, \
                                                     "0", tr("Charge Vol upper Limit delta"), \
                                                     tr("Charging voltage upper limit hysteresis: When the battery is charging, if the battery total voltage reaches the charging voltage upper limit, the converter will shut down. When the battery total voltage drops below the charging voltage upper limit minus the hysteresis value, the converter will automatically turn on."));
    Charge_Vol_upper_Limit_delta->add_Specification();

    if(Disc_Vol_lower_Limit != nullptr)
    {
        delete Disc_Vol_lower_Limit;
    }
    Disc_Vol_lower_Limit = new Specification(this,Disc_Vol_lower_Limit_explain, ui->Lithum_Tab, line++, column, \
                                     "0", tr("Discharge Volt lower Limit"), \
                                     tr("Discharge voltage lower limit: When the battery total voltage reaches this value during discharge, the converter will shut down."));
    Disc_Vol_lower_Limit->add_Specification();

    if(Discharge_Vol_lower_Limit_delta != nullptr)
    {
        delete Discharge_Vol_lower_Limit_delta;
    }
    Discharge_Vol_lower_Limit_delta = new Specification(this,Discharge_Vol_lower_Limit_delta_explain, ui->Lithum_Tab, line++, column,\
                                                        "0", tr("Discharge Vol lower Limit delta"), \
                                                        tr("Discharge voltage lower limit hysteresis: When the battery is discharging, if the battery total voltage drops below the discharge voltage lower limit, the converter will shut down. When the battery total voltage exceeds the discharge voltage lower limit plus the hysteresis value, the converter will automatically turn on."));
    Discharge_Vol_lower_Limit_delta->add_Specification();

    if(Charge_Cur_Limit != nullptr)
    {
        delete Charge_Cur_Limit;
    }
    Charge_Cur_Limit = new Specification(this,Charge_Cur_Limit_explain, ui->Lithum_Tab, line++, column, \
                                     "0", tr("Charge Current Limit"), \
                                     tr("Charging current limit: The maximum allowable current on the battery side to prevent overcurrent during charging."));
    Charge_Cur_Limit->add_Specification();

    if(Discharge_Cur_Limit != nullptr)
    {
        delete Discharge_Cur_Limit;
    }
    Discharge_Cur_Limit = new Specification(this,Discharge_Cur_Limit_explain, ui->Lithum_Tab, line++, column, \
                                     "0", tr("Discharge Current Limit"), \
                                     tr("Discharging current limit: The maximum allowable current on the battery side to prevent overcurrent during Discharging."));
    Discharge_Cur_Limit->add_Specification();

    if(Charge_power_limit != nullptr)
    {
        delete Charge_power_limit;
    }
    Charge_power_limit = new Specification(this,Charge_power_limit_explain, ui->Lithum_Tab, line++, column, \
                                           "0", tr("Charge power limit"),\
                                           tr("Set the charging power limit to allow the maximum power of charging."));
    Charge_power_limit->add_Specification();

    if(Discharge_power_limit != nullptr)
    {
        delete Discharge_power_limit;
    }
    Discharge_power_limit = new Specification(this,Discharge_power_limit_explain, ui->Lithum_Tab, line++, column, \
                                              "0", tr("Discharge power limit"), \
                                              tr("The discharge power limit is set to allow the maximum power of the discharge."));
    Discharge_power_limit->add_Specification();

    if(Gen_turn_off_SOC != nullptr)
    {
        delete Gen_turn_off_SOC;
    }
    Gen_turn_off_SOC = new Specification(this,Gen_turn_off_SOC_explain, ui->Lithum_Tab, line++, column, \
                                     "0", tr("Generator turn off SOC"), \
                                     tr("When the specified SOC is reached, the diesel generator shuts down."));
    Gen_turn_off_SOC->add_Specification();

    if(Gen_turn_on_SOC != nullptr)
    {
        delete Gen_turn_on_SOC;
    }
    Gen_turn_on_SOC = new Specification(this,Gen_turn_on_SOC_explain, ui->Lithum_Tab, line++, column, \
                                     "0", tr("Genertor turn on SOC"), \
                                     tr("When the specified SOC is reached, the diesel generator starts."));
    Gen_turn_on_SOC->add_Specification();

    if(Gen_charge_SOC != nullptr)
    {
        delete Gen_charge_SOC;
    }
    Gen_charge_SOC = new Specification(this,Gen_charge_SOC_explain, ui->Lithum_Tab, line++, column, \
                                     "0", tr("Charging SOC of Diesel Generator"), \
                                     tr("Charging SOC of Diesel Generator: In grid expansion mode, when a diesel generator is connected, the battery SOC will charge when it is below this SOC."));
    Gen_charge_SOC->add_Specification();

    if(Grid_charge_SOC != nullptr)
    {
        delete Grid_charge_SOC;
    }
    Grid_charge_SOC = new Specification(this,Grid_charge_SOC_explain, ui->Lithum_Tab, line++, column, \
                                     "0", tr("Grid charge SOC"), \
                                     tr("Charging SOC of Grid: In grid expansion mode, when there is no diesel generator connected, the battery SOC will charge when it is below this SOC."));
    Grid_charge_SOC->add_Specification();

    if(ChargeStopSOC != nullptr)
    {
        delete ChargeStopSOC;
    }
    ChargeStopSOC = new Specification(this,ChargeStopSOC_explain, ui->Lithum_Tab, line++, column, \
                                     "0", tr("Charge Stop SOC"), \
                                     tr("Charging Stop SOC: In grid expansion mode, when the battery is charging, it will stop charging when the battery SOC is greater than this SOC."));
    ChargeStopSOC->add_Specification();

    if(DischargeStopSOC != nullptr)
    {
        delete DischargeStopSOC;
    }
    DischargeStopSOC = new Specification(this,DischargeStopSOC_explain, ui->Lithum_Tab, line++, column, \
                                     "0", tr("Discharge Stop SOC"), \
                                     tr("Discharging Stop SOC: In grid expansion mode, the battery will stop discharging when the battery SOC is below this SOC."));
    DischargeStopSOC->add_Specification();

    if(Grid_capacity != nullptr)
    {
        delete Grid_capacity;
    }
    Grid_capacity = new Specification(this,Grid_capacity_explain, ui->Lithum_Tab, line++, column, \
                                     "0", tr("Grid_capacity"), \
                                     tr("Grid Capacity: The maximum power capacity connected to the grid in grid expansion mode."));
    Grid_capacity->add_Specification();


    line = 0;
    column = 4;
    if(Turn_on_SOC != nullptr)
    {
        delete Turn_on_SOC;
    }
    Turn_on_SOC = new Specification(this,Turn_on_SOC_explain, ui->Lithum_Tab, line++, column, \
                                     "0", tr("Turn_on_SOC"), \
                                     tr("Start SOC: In UPS mode, when the battery SOC reaches that value, the converter starts charging."));
    Turn_on_SOC->add_Specification();

    if(Turn_off_SOC != nullptr)
    {
        delete Turn_off_SOC;
    }
    Turn_off_SOC = new Specification(this,Turn_off_SOC_explain, ui->Lithum_Tab, line++, column, \
                                     "0", tr("Turn_off_SOC"), \
                                     tr("Stop SOC: In UPS mode, when the battery SOC reaches that value, the converter stops charging."));
    Turn_off_SOC->add_Specification();

    if(Turn_on_cell_vol != nullptr)
    {
        delete Turn_on_cell_vol;
    }
    Turn_on_cell_vol = new Specification(this,Turn_on_cell_vol_explain, ui->Lithum_Tab, line++, column, \
                                     "0", tr("Turn_on_cell_vol"), \
                                     tr("Start cell voltage: In UPS mode, when the lowest voltage of a battery cell reaches that value, the converter starts charging."));
    Turn_on_cell_vol->add_Specification();

    if(Turn_off_cell_vol != nullptr)
    {
        delete Turn_off_cell_vol;
    }
    Turn_off_cell_vol = new Specification(this,Turn_off_cell_vol_explain, ui->Lithum_Tab, line++, column, \
                                     "0", tr("Turn_off_cell_vol"), \
                                     tr("Stop cell voltage: In UPS mode, when the highest voltage of a battery cell reaches that value, the converter stops charging."));
    Turn_off_cell_vol->add_Specification();

    if(Turn_on_total_vol != nullptr)
    {
        delete Turn_on_total_vol;
    }
    Turn_on_total_vol = new Specification(this,Turn_on_total_vol_explain, ui->Lithum_Tab, line++, column, \
                                     "0", tr("Turn_on_total_vol"), \
                                     tr("Start total voltage: In UPS mode, when the total voltage of the battery reaches that value, the converter starts charging."));
    Turn_on_total_vol->add_Specification();

    if(Turn_off_total_vol != nullptr)
    {
        delete Turn_off_total_vol;
    }
    Turn_off_total_vol = new Specification(this,Turn_off_total_vol_explain, ui->Lithum_Tab, line++, column, \
                                     "650", tr("Turn_off_total_vol"), \
                                     tr("Stop total voltage: In UPS mode, when the total voltage of the battery reaches that value, the converter stops charging."));
    Turn_off_total_vol->add_Specification();

    if(UPS_charge_power != nullptr)
    {
        delete UPS_charge_power;
    }
    UPS_charge_power = new Specification(this,UPS_charge_power_explain, ui->Lithum_Tab, line++, column, \
                                     "0", tr("UPS_charge_power"), \
                                     tr("Backup charging power: In UPS mode, the backup charging power of the converter when the battery starts charging."));
    UPS_charge_power->add_Specification();

    if(Monthly_cycle_time != nullptr)
    {
        delete Monthly_cycle_time;
    }
    Monthly_cycle_time = new Specification(this,Monthly_cycle_time_explain, ui->Lithum_Tab, line++, column, \
                                     "0", tr("Monthly_cycle_time"), \
                                     tr("Monthly cycling date: On the same day of each month, a deep discharge and recharge will be performed."));
    Monthly_cycle_time->add_Specification();
}
//电池设置页说明_铅酸电池
void MEGAWin::Battery_Setup_Lead_Tab(QTableWidget *myTable)
{
    //容量
    Capacity = new Specification(this,Capacity_explain, myTable, 0, 1, \
                                        "0", tr("Capacity"), \
                                        tr("Capacity, the capacity of the lead-acid battery."));
    Capacity->add_Specification();//容量，铅酸电池的容量大小
    //电池节数
    Cell_number_2V = new Specification(this,Cell_number_2V_explain, myTable, 1, 1, \
                                        "0", tr("Cell_number_2V"), \
                                        tr("The number of battery cells connected in series in the battery stack (based on a 2V unit)."));
    Cell_number_2V->add_Specification();
    //浮充电压
    Bat_float_vol = new Specification(this,Bat_float_vol_explain, myTable, 2, 1, \
                                        "0", tr("Battery float voltage"), \
                                        tr("This is the floating charge voltage."));
    Bat_float_vol->add_Specification();
    //均充电压
    Bat_filling_vol = new Specification(this,Bat_filling_vol_explain, myTable, 3, 1, \
                                        "0", tr("Battery filling voltage"), \
                                        tr("This is the filling voltage."));
    Bat_filling_vol->add_Specification();
    //充电限流值
    Charge_limiting_value = new Specification(this,Charge_limiting_value_explain, myTable, 4, 1, \
                                        "0", tr("Charge limiting value"), \
                                        tr("Charging Current Limit: The maximum allowable current on the battery side to prevent overcurrent during charging. (Upper limit: 0.25C)"));
    Charge_limiting_value->add_Specification();
    //放电限流值
    Discharge_limiting_value = new Specification(this,Discharge_limiting_value_explain, myTable, 5, 1, \
                                        "0", tr("Discharge limiting value"), \
                                        tr("Discharge Current Limit: The maximum allowable current on the battery side to prevent overcurrent during discharge. (Upper limit: 0.5C)"));
    Discharge_limiting_value->add_Specification();
    //发电机关闭SOC
    Generator_turn_off_SOC_B1 = new Specification(this,Generator_turn_off_SOC_B1_explain, myTable, 6, 1, \
                                        "0", tr("Generator turn off voltage"), \
                                        tr("Generator Shutdown Voltage: When the specified voltage is reached, the diesel generator will shut down."));
    Generator_turn_off_SOC_B1->add_Specification();
    //发电机开启SOC
    Generator_turn_on_SOC_A1 = new Specification(this,Generator_turn_on_SOC_A1_explain, myTable, 7, 1, \
                                        "0", tr("Generator turn on voltage"), \
                                        tr("Generator Start Voltage: When the specified voltage is reached, the diesel generator will start up."));
    Generator_turn_on_SOC_A1->add_Specification();
    //离网EOD
    Grid_off_EOD = new Specification(this,Grid_off_EOD_explain, myTable, 0, 4, \
                                        "0", tr("Grid-off EOD"), \
                                        tr("Grid-off discharge cut-off voltage."));
    Grid_off_EOD->add_Specification();//
    //并网EOD
    Grid_on_EOD = new Specification(this,Grid_on_EOD_explain, myTable, 1, 4, \
                                        "0", tr("Grid-on EOD"), \
                                        tr("Grid-on discharge cut-off voltage."));
    Grid_on_EOD->add_Specification();//
    //均充转浮充电流
    Uniform_To_Flushing_current = new Specification(this,Uniform_To_Flushing_current_explain, myTable, 7, 4, \
                                        "0", tr("Uniform charging and flushing current"), \
                                        tr("Uniform charging to flushing current: Upper limit of 0.025C."));
    Uniform_To_Flushing_current->add_Specification();//
    //浮充转均充电流
    Flushing_To_Uniform_current = new Specification(this,Flushing_To_Uniform_current_explain, myTable, 8, 4, \
                                        "0", tr("Float turn uniform charging current"), \
                                        tr("Float turn to uniform charging current: Upper limit of 0.15C."));
    Flushing_To_Uniform_current->add_Specification();//
}

/***************************************************************
 * 自动运行
 ***************************************************************/
void MEGAWin::AutoOperation()
{
    QString temp1 = tr("Check");
    QString temp2 = tr("Start_Time");
    QString temp3 = tr("End_Time");
    QString temp4 = tr("State");
    QString temp5 = tr("Power");
    QString temp6 = tr("9:00");
    QString temp7 = tr("10:00");
    QString temp8 = tr("End time: The system stops automatically running when the system reaches this time.");
    QString temp9 = tr("This working state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic.");
    QString temp10 = tr("Working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging.");
    QString temp11 = tr("Start time: When the system reaches this time, it starts to run automatically.");
    QString temp12 = tr("Select: After this function is enabled, the system automatically runs the selected function mode within the specified period.");

    if(Check1 != nullptr)
    {
        delete Check1;
    }
    Check1 = new Specification(this,Check1_explain, ui->Time_tableWidget, 0, 0, "√", temp1, temp12);
    Check1->add_Specification();

    if(Check2 != nullptr)
    {
        delete Check2;
    }
    Check2 = new Specification(this,Check2_explain, ui->Time_tableWidget, 1, 0, "√", temp1, temp12);
    Check2->add_Specification();

    if(Check3 != nullptr)
    {
        delete Check3;
    }
    Check3 = new Specification(this,Check3_explain, ui->Time_tableWidget, 2, 0, "√", temp1, temp12);
    Check3->add_Specification();

    if(Check4 != nullptr)
    {
        delete Check4;
    }
    Check4 = new Specification(this,Check4_explain, ui->Time_tableWidget, 3, 0, "√", temp1, temp12);
    Check4->add_Specification();

    if(Check5 != nullptr)
    {
        delete Check5;
    }
    Check5 = new Specification(this,Check5_explain, ui->Time_tableWidget, 4, 0, "√", temp1, temp12);
    Check5->add_Specification();

    if(Check6 != nullptr)
    {
        delete Check6;
    }
    Check6 = new Specification(this,Check6_explain, ui->Time_tableWidget, 5, 0, "", temp1, temp12);
    Check6->add_Specification();

    if(Check7 != nullptr)
    {
        delete Check7;
    }
    Check7 = new Specification(this,Check7_explain, ui->Time_tableWidget, 6, 0, "", temp1, temp12);
    Check7->add_Specification();

    if(Check8 != nullptr)
    {
        delete Check8;
    }
    Check8 = new Specification(this,Check8_explain, ui->Time_tableWidget, 7, 0, "", temp1, temp12);
    Check8->add_Specification();

    if(Check9 != nullptr)
    {
        delete Check9;
    }
    Check9 = new Specification(this,Check9_explain, ui->Time_tableWidget, 8, 0, "", temp1, temp12);
    Check9->add_Specification();

    if(Check10 != nullptr)
    {
        delete Check10;
    }
    Check10 = new Specification(this,Check10_explain, ui->Time_tableWidget, 9, 0, "", temp1, temp12);
    Check10->add_Specification();

    if(Check11 != nullptr)
    {
        delete Check11;
    }
    Check11 = new Specification(this,Check11_explain, ui->Time_tableWidget, 10, 0, "", temp1, temp12);
    Check11->add_Specification();

    if(Check11 != nullptr)
    {
        delete Check12;
    }
    Check12 = new Specification(this,Check12_explain, ui->Time_tableWidget, 11, 0, "", temp1, temp12);
    Check12->add_Specification();

    if(Check13 != nullptr)
    {
        delete Check13;
    }
    Check13 = new Specification(this,Check13_explain, ui->Time_tableWidget, 12, 0, "", temp1, temp12);
    Check13->add_Specification();

    if(Check14 != nullptr)
    {
        delete Check14;
    }
    Check14 = new Specification(this,Check14_explain, ui->Time_tableWidget, 13, 0, "", temp1, temp12);
    Check14->add_Specification();

    if(Check15 != nullptr)
    {
        delete Check15;
    }
    Check15 = new Specification(this,Check15_explain, ui->Time_tableWidget, 14, 0, "", temp1, temp12);
    Check15->add_Specification();

    if(Check16 != nullptr)
    {
        delete Check16;
    }
    Check16 = new Specification(this,Check16_explain, ui->Time_tableWidget, 15, 0, "", temp1, temp12);
    Check16->add_Specification();

    if(Check17 != nullptr)
    {
        delete Check17;
    }
    Check17 = new Specification(this,Check17_explain, ui->Time_tableWidget, 16, 0, "", temp1, temp12);
    Check17->add_Specification();

    if(Check18 != nullptr)
    {
        delete Check18;
    }
    Check18 = new Specification(this,Check18_explain, ui->Time_tableWidget, 17, 0, "", temp1, temp12);
    Check18->add_Specification();

    if(Check19 != nullptr)
    {
        delete Check19;
    }
    Check19 = new Specification(this,Check19_explain, ui->Time_tableWidget, 18, 0, "", temp1, temp12);
    Check19->add_Specification();

    if(Check20 != nullptr)
    {
        delete Check20;
    }
    Check20 = new Specification(this,Check20_explain, ui->Time_tableWidget, 19, 0, "", temp1, temp12);
    Check20->add_Specification();


    if(Start_T1 != nullptr)
    {
        delete Start_T1;
    }
    Start_T1 = new Specification(this,Start_T1_explain, ui->Time_tableWidget, 0, 1, temp6, temp2, temp11);
    Start_T1->add_Specification();

    if(Start_T2 != nullptr)
    {
        delete Start_T2;
    }
    Start_T2 = new Specification(this,Start_T2_explain, ui->Time_tableWidget, 1, 1, temp6, temp2, temp11);
    Start_T2->add_Specification();

    if(Start_T3 != nullptr)
    {
        delete Start_T3;
    }
    Start_T3 = new Specification(this,Start_T3_explain, ui->Time_tableWidget, 2, 1, temp6, temp2, temp11);
    Start_T3->add_Specification();

    if(Start_T4 != nullptr)
    {
        delete Start_T4;
    }
    Start_T4 = new Specification(this,Start_T4_explain, ui->Time_tableWidget, 3, 1, temp6, temp2, temp11);
    Start_T4->add_Specification();

    if(Start_T5 != nullptr)
    {
        delete Start_T5;
    }
    Start_T5 = new Specification(this,Start_T5_explain, ui->Time_tableWidget, 4, 1, temp6, temp2, temp11);
    Start_T5->add_Specification();

    if(Start_T6 != nullptr)
    {
        delete Start_T6;
    }
    Start_T6 = new Specification(this,Start_T6_explain, ui->Time_tableWidget, 5, 1, temp6, temp2, temp11);
    Start_T6->add_Specification();

    if(Start_T7 != nullptr)
    {
        delete Start_T7;
    }
    Start_T7 = new Specification(this,Start_T7_explain, ui->Time_tableWidget, 6, 1, temp6, temp2, temp11);
    Start_T7->add_Specification();

    if(Start_T8 != nullptr)
    {
        delete Start_T8;
    }
    Start_T8 = new Specification(this,Start_T8_explain, ui->Time_tableWidget, 7, 1, temp6, temp2, temp11);
    Start_T8->add_Specification();

    if(Start_T9 != nullptr)
    {
        delete Start_T9;
    }
    Start_T9 = new Specification(this,Start_T9_explain, ui->Time_tableWidget, 8, 1, temp6, temp2, temp11);
    Start_T9->add_Specification();

    if(Start_T10 != nullptr)
    {
        delete Start_T10;
    }
    Start_T10 = new Specification(this,Start_T10_explain, ui->Time_tableWidget, 9, 1, temp6, temp2, temp11);
    Start_T10->add_Specification();

    if(Start_T11 != nullptr)
    {
        delete Start_T11;
    }
    Start_T11 = new Specification(this,Start_T11_explain, ui->Time_tableWidget, 10, 1, temp6, temp2, temp11);
    Start_T11->add_Specification();

    if(Start_T12 != nullptr)
    {
        delete Start_T12;
    }
    Start_T12 = new Specification(this,Start_T12_explain, ui->Time_tableWidget, 11, 1, temp6, temp2, temp11);
    Start_T12->add_Specification();

    if(Start_T13 != nullptr)
    {
        delete Start_T13;
    }
    Start_T13 = new Specification(this,Start_T13_explain, ui->Time_tableWidget, 12, 1, temp6, temp2, temp11);
    Start_T13->add_Specification();

    if(Start_T14 != nullptr)
    {
        delete Start_T14;
    }
    Start_T14 = new Specification(this,Start_T14_explain, ui->Time_tableWidget, 13, 1, temp6, temp2, temp11);
    Start_T14->add_Specification();

    if(Start_T15 != nullptr)
    {
        delete Start_T15;
    }
    Start_T15 = new Specification(this,Start_T15_explain, ui->Time_tableWidget, 14, 1, temp6, temp2, temp11);
    Start_T15->add_Specification();

    if(Start_T16 != nullptr)
    {
        delete Start_T16;
    }
    Start_T16 = new Specification(this,Start_T16_explain, ui->Time_tableWidget, 15, 1, temp6, temp2, temp11);
    Start_T16->add_Specification();

    if(Start_T17 != nullptr)
    {
        delete Start_T17;
    }
    Start_T17 = new Specification(this,Start_T17_explain, ui->Time_tableWidget, 16, 1, temp6, temp2, temp11);
    Start_T17->add_Specification();

    if(Start_T18 != nullptr)
    {
        delete Start_T18;
    }
    Start_T18 = new Specification(this,Start_T18_explain, ui->Time_tableWidget, 17, 1, temp6, temp2, temp11);
    Start_T18->add_Specification();

    if(Start_T19 != nullptr)
    {
        delete Start_T19;
    }
    Start_T19 = new Specification(this,Start_T19_explain, ui->Time_tableWidget, 18, 1, temp6, temp2, temp11);
    Start_T19->add_Specification();

    if(Start_T20 != nullptr)
    {
        delete Start_T20;
    }
    Start_T20 = new Specification(this,Start_T20_explain, ui->Time_tableWidget, 19, 1, temp6, temp2, temp11);
    Start_T20->add_Specification();


    if(End_T1 != nullptr)
    {
        delete End_T1;
    }
    End_T1 = new Specification(this,End_T1_explain, ui->Time_tableWidget, 0, 2, temp7, temp3, temp8);
    End_T1->add_Specification();

    if(End_T2 != nullptr)
    {
        delete End_T2;
    }
    End_T2 = new Specification(this,End_T2_explain, ui->Time_tableWidget, 1, 2, temp7, temp3, temp8);
    End_T2->add_Specification();

    if(End_T3 != nullptr)
    {
        delete End_T3;
    }
    End_T3 = new Specification(this,End_T3_explain, ui->Time_tableWidget, 2, 2, temp7, temp3, temp8);
    End_T3->add_Specification();

    if(End_T4 != nullptr)
    {
        delete End_T4;
    }
    End_T4 = new Specification(this,End_T4_explain, ui->Time_tableWidget, 3, 2, temp7, temp3, temp8);
    End_T4->add_Specification();

    if(End_T5 != nullptr)
    {
        delete End_T5;
    }
    End_T5 = new Specification(this,End_T5_explain, ui->Time_tableWidget, 4, 2, temp7, temp3, temp8);
    End_T5->add_Specification();

    if(End_T6 != nullptr)
    {
        delete End_T6;
    }
    End_T6 = new Specification(this,End_T6_explain, ui->Time_tableWidget, 5, 2, temp7, temp3, temp8);
    End_T6->add_Specification();

    if(End_T7 != nullptr)
    {
        delete End_T7;
    }
    End_T7 = new Specification(this,End_T7_explain, ui->Time_tableWidget, 6, 2, temp7, temp3, temp8);
    End_T7->add_Specification();

    if(End_T8 != nullptr)
    {
        delete End_T8;
    }
    End_T8 = new Specification(this,End_T8_explain, ui->Time_tableWidget, 7, 2, temp7, temp3, temp8);
    End_T8->add_Specification();

    if(End_T9 != nullptr)
    {
        delete End_T9;
    }
    End_T9 = new Specification(this,End_T9_explain, ui->Time_tableWidget, 8, 2, temp7, temp3, temp8);
    End_T9->add_Specification();

    if(End_T10 != nullptr)
    {
        delete End_T10;
    }
    End_T10 = new Specification(this,End_T10_explain, ui->Time_tableWidget, 9, 2, temp7, temp3, temp8);
    End_T10->add_Specification();

    if(End_T11 != nullptr)
    {
        delete End_T11;
    }
    End_T11 = new Specification(this,End_T11_explain, ui->Time_tableWidget, 10, 2, temp7, temp3, temp8);
    End_T11->add_Specification();

    if(End_T12 != nullptr)
    {
        delete End_T12;
    }
    End_T12 = new Specification(this,End_T12_explain, ui->Time_tableWidget, 11, 2, temp7, temp3, temp8);
    End_T12->add_Specification();

    if(End_T13 != nullptr)
    {
        delete End_T13;
    }
    End_T13 = new Specification(this,End_T13_explain, ui->Time_tableWidget, 12, 2, temp7, temp3, temp8);
    End_T13->add_Specification();

    if(End_T14 != nullptr)
    {
        delete End_T14;
    }
    End_T14 = new Specification(this,End_T14_explain, ui->Time_tableWidget, 13, 2, temp7, temp3, temp8);
    End_T14->add_Specification();

    if(End_T15 != nullptr)
    {
        delete End_T15;
    }
    End_T15 = new Specification(this,End_T15_explain, ui->Time_tableWidget, 14, 2, temp7, temp3, temp8);
    End_T15->add_Specification();

    if(End_T16 != nullptr)
    {
        delete End_T16;
    }
    End_T16 = new Specification(this,End_T16_explain, ui->Time_tableWidget, 15, 2, temp7, temp3, temp8);
    End_T16->add_Specification();

    if(End_T17 != nullptr)
    {
        delete End_T17;
    }
    End_T17 = new Specification(this,End_T17_explain, ui->Time_tableWidget, 16, 2, temp7, temp3, temp8);
    End_T17->add_Specification();

    if(End_T18 != nullptr)
    {
        delete End_T18;
    }
    End_T18 = new Specification(this,End_T18_explain, ui->Time_tableWidget, 17, 2, temp7, temp3, temp8);
    End_T18->add_Specification();

    if(End_T19 != nullptr)
    {
        delete End_T19;
    }
    End_T19 = new Specification(this,End_T19_explain, ui->Time_tableWidget, 18, 2, temp7, temp3, temp8);
    End_T19->add_Specification();

    if(End_T20 != nullptr)
    {
        delete End_T20;
    }
    End_T20 = new Specification(this,End_T20_explain, ui->Time_tableWidget, 19, 2, temp7, temp3, temp8);
    End_T20->add_Specification();


    if(State1 != nullptr)
    {
        delete State1;
    }
    State1 = new Specification(this,State1_explain, ui->Time_tableWidget, 0, 3, tr("charge"), temp4, temp9);
    State1->add_Specification();

    if(State2 != nullptr)
    {
        delete State2;
    }
    State2 = new Specification(this,State2_explain, ui->Time_tableWidget, 1, 3, tr("discharge"), temp4, temp9);
    State2->add_Specification();

    if(State3 != nullptr)
    {
        delete State3;
    }
    State3 = new Specification(this,State3_explain, ui->Time_tableWidget, 2, 3, tr("charge"), temp4, temp9);
    State3->add_Specification();

    if(State4 != nullptr)
    {
        delete State4;
    }
    State4 = new Specification(this,State4_explain, ui->Time_tableWidget, 3, 3, tr("discharge"), temp4, temp9);
    State4->add_Specification();

    if(State5 != nullptr)
    {
        delete State5;
    }
    State5 = new Specification(this,State5_explain, ui->Time_tableWidget, 4, 3, tr("charge"), temp4, temp9);
    State5->add_Specification();

    if(State6 != nullptr)
    {
        delete State6;
    }
    State6 = new Specification(this,State6_explain, ui->Time_tableWidget, 5, 3, tr("discharge"), temp4, temp9);
    State6->add_Specification();

    if(State7 != nullptr)
    {
        delete State7;
    }
    State7 = new Specification(this,State7_explain, ui->Time_tableWidget, 6, 3, tr("charge"), temp4, temp9);
    State7->add_Specification();

    if(State8 != nullptr)
    {
        delete State8;
    }
    State8 = new Specification(this,State8_explain, ui->Time_tableWidget, 7, 3, tr("discharge"), temp4, temp9);
    State8->add_Specification();

    if(State9 != nullptr)
    {
        delete State9;
    }
    State9 = new Specification(this,State9_explain, ui->Time_tableWidget, 8, 3, tr("charge"), temp4, temp9);
    State9->add_Specification();

    if(State10 != nullptr)
    {
        delete State10;
    }
    State10 = new Specification(this,State10_explain, ui->Time_tableWidget, 9, 3, tr("discharge"), temp4, temp9);
    State10->add_Specification();

    if(State11 != nullptr)
    {
        delete State11;
    }
    State11 = new Specification(this,State11_explain, ui->Time_tableWidget, 10, 3, tr("charge"), temp4, temp9);
    State11->add_Specification();

    if(State12 != nullptr)
    {
        delete State12;
    }
    State12 = new Specification(this,State12_explain, ui->Time_tableWidget, 11, 3, tr("discharge"), temp4, temp9);
    State12->add_Specification();

    if(State13 != nullptr)
    {
        delete State13;
    }
    State13 = new Specification(this,State13_explain, ui->Time_tableWidget, 12, 3, tr("charge"), temp4, temp9);
    State13->add_Specification();

    if(State14 != nullptr)
    {
        delete State14;
    }
    State14 = new Specification(this,State14_explain, ui->Time_tableWidget, 13, 3, tr("discharge"), temp4, temp9);
    State14->add_Specification();

    if(State15 != nullptr)
    {
        delete State15;
    }
    State15 = new Specification(this,State15_explain, ui->Time_tableWidget, 14, 3, tr("charge"), temp4, temp9);
    State15->add_Specification();

    if(State16 != nullptr)
    {
        delete State16;
    }
    State16 = new Specification(this,State16_explain, ui->Time_tableWidget, 15, 3, tr("discharge"), temp4, temp9);
    State16->add_Specification();

    if(State17 != nullptr)
    {
        delete State17;
    }
    State17 = new Specification(this,State17_explain, ui->Time_tableWidget, 16, 3, tr("charge"), temp4, temp9);
    State17->add_Specification();

    if(State18 != nullptr)
    {
        delete State18;
    }
    State18 = new Specification(this,State18_explain, ui->Time_tableWidget, 17, 3, tr("discharge"), temp4, temp9);
    State18->add_Specification();

    if(State19 != nullptr)
    {
        delete State19;
    }
    State19 = new Specification(this,State19_explain, ui->Time_tableWidget, 18, 3, tr("charge"), temp4, temp9);
    State19->add_Specification();

    if(State20 != nullptr)
    {
        delete State20;
    }
    State20 = new Specification(this,State20_explain, ui->Time_tableWidget, 19, 3, tr("discharge"), temp4, temp9);
    State20->add_Specification();


    if(Power1 != nullptr)
    {
        delete Power1;
    }
    Power1 = new Specification(this,Power1_explain, ui->Time_tableWidget, 0, 4, "-50", temp5, temp10);
    Power1->add_Specification();

    if(Power2 != nullptr)
    {
        delete Power2;
    }
    Power2 = new Specification(this,Power2_explain, ui->Time_tableWidget, 1, 4, "50", temp5, temp10);
    Power2->add_Specification();

    if(Power3 != nullptr)
    {
        delete Power3;
    }
    Power3 = new Specification(this,Power3_explain, ui->Time_tableWidget, 2, 4, "-50", temp5, temp10);
    Power3->add_Specification();

    if(Power4 != nullptr)
    {
        delete Power4;
    }
    Power4 = new Specification(this,Power4_explain, ui->Time_tableWidget, 3, 4, "50", temp5, temp10);
    Power4->add_Specification();


    if(Power5 != nullptr)
    {
        delete Power5;
    }
    Power5 = new Specification(this,Power5_explain, ui->Time_tableWidget, 4, 4, "-50", temp5, temp10);
    Power5->add_Specification();

    if(Power6 != nullptr)
    {
        delete Power6;
    }
    Power6 = new Specification(this,Power6_explain, ui->Time_tableWidget, 5, 4, "50", temp5, temp10);
    Power6->add_Specification();


    if(Power7 != nullptr)
    {
        delete Power7;
    }
    Power7 = new Specification(this,Power7_explain, ui->Time_tableWidget, 6, 4, "-50", temp5, temp10);
    Power7->add_Specification();

    if(Power8 != nullptr)
    {
        delete Power8;
    }
    Power8 = new Specification(this,Power8_explain, ui->Time_tableWidget, 7, 4, "50", temp5, temp10);
    Power8->add_Specification();


    if(Power9 != nullptr)
    {
        delete Power9;
    }
    Power9 = new Specification(this,Power9_explain, ui->Time_tableWidget, 8, 4, "-50", temp5, temp10);
    Power9->add_Specification();

    if(Power10 != nullptr)
    {
        delete Power10;
    }
    Power10 = new Specification(this,Power10_explain, ui->Time_tableWidget, 9, 4, "50", temp5, temp10);
    Power10->add_Specification();


    if(Power11 != nullptr)
    {
        delete Power11;
    }
    Power11 = new Specification(this,Power11_explain, ui->Time_tableWidget, 10, 4, "-50", temp5, temp10);
    Power11->add_Specification();

    if(Power12 != nullptr)
    {
        delete Power12;
    }
    Power12 = new Specification(this,Power12_explain, ui->Time_tableWidget, 11, 4, "50", temp5, temp10);
    Power12->add_Specification();


    if(Power13 != nullptr)
    {
        delete Power13;
    }
    Power13 = new Specification(this,Power13_explain, ui->Time_tableWidget, 12, 4, "-50", temp5, temp10);
    Power13->add_Specification();

    if(Power14 != nullptr)
    {
        delete Power14;
    }
    Power14 = new Specification(this,Power14_explain, ui->Time_tableWidget, 13, 4, "50", temp5, temp10);
    Power14->add_Specification();


    if(Power15 != nullptr)
    {
        delete Power15;
    }
    Power15 = new Specification(this,Power15_explain, ui->Time_tableWidget, 14, 4, "-50", temp5, temp10);
    Power15->add_Specification();

    if(Power16 != nullptr)
    {
        delete Power16;
    }
    Power16 = new Specification(this,Power16_explain, ui->Time_tableWidget, 15, 4, "50", temp5, temp10);
    Power16->add_Specification();


    if(Power17 != nullptr)
    {
        delete Power17;
    }
    Power17 = new Specification(this,Power17_explain, ui->Time_tableWidget, 16, 4, "-50", temp5, temp10);
    Power17->add_Specification();

    if(Power18 != nullptr)
    {
        delete Power18;
    }
    Power18 = new Specification(this,Power18_explain, ui->Time_tableWidget, 17, 4, "50", temp5, temp10);
    Power18->add_Specification();

    if(Power19 != nullptr)
    {
        delete Power19;
    }
    Power19 = new Specification(this,Power19_explain, ui->Time_tableWidget, 18, 4, "-50", temp5, temp10);
    Power19->add_Specification();

    if(Power20 != nullptr)
    {
        delete Power20;
    }
    Power20 = new Specification(this,Power20_explain, ui->Time_tableWidget, 19, 4, "50", temp5, temp10);
    Power20->add_Specification();

}

/***************************************************************
 * 系统信息
 ***************************************************************/
void MEGAWin::SystemMessages()
{
    /*if(Manufacturer_name != nullptr)
    {
        delete Manufacturer_name;
    }
    Manufacturer_name = new Specification(this,Manufacturer_name_explain, ui->EquipmentInfor_tableWidget, 0, 1, \
                                     "PCS", tr("Manufacturer name"), \
                                     tr("This is the name of the manufacturer."));
    Manufacturer_name->add_Specification();*/

    int line=0;

    if(MonitoringVersion != nullptr)
    {
        delete MonitoringVersion;
    }
    MonitoringVersion = new Specification(this,MonitoringVersion_explain, ui->EquipmentInfor_tableWidget, line++, 1, \
                                     "V103B500D004", tr("Monitoring software version"), \
                                     tr("This is the monitoring version number."));
    MonitoringVersion->add_Specification();

    if(SysProtocol_Version != nullptr)
    {
        delete SysProtocol_Version;
    }
    SysProtocol_Version = new Specification(this,SysProtocol_Version_explain, ui->EquipmentInfor_tableWidget, line++, 1, \
                                     "V001B001D001", tr("Protocol Version"), \
                                     tr("This is the protocol version number."));
    SysProtocol_Version->add_Specification();

    if(ConverterVersion != nullptr)
    {
        delete ConverterVersion;
    }
    ConverterVersion = new Specification(this,ConverterVersion_explain, ui->EquipmentInfor_tableWidget, line++, 1, \
                                     "V105B500D008", tr("Converter software version"), \
                                     tr("This is the converter software version."));
    ConverterVersion->add_Specification();

    if(CPLD_Version != nullptr)
    {
        delete CPLD_Version;
    }
    CPLD_Version = new Specification(this,CPLD_Version_explain, ui->EquipmentInfor_tableWidget, line++, 1, \
                                     "V001B001D000", tr("CPLD software version"), \
                                     tr("This is the CPLD software version."));
    CPLD_Version->add_Specification();

    if(SN != nullptr)
    {
        delete SN;
    }
    SN = new Specification(this,SN_explain, ui->EquipmentInfor_tableWidget, line++, 1, \
                                     "F12200000001", tr("SN"), \
                                     tr("This is SN, the serial number of the product."));
    SN->add_Specification();
}

/***************************************************************
 * 功能设置
 ***************************************************************/
void MEGAWin::FunctionSet()
{
    if(Battery_type != nullptr)
    {
        delete Battery_type;
    }
    Battery_type = new Specification(this,Battery_type_explain, ui->UI_Parameter_Tab, 0, 1, \
                                     tr("Lithium"), tr("Battery type"), \
                                     tr("Battery Types: Lithium, Lead-Acid."));
    Battery_type->add_Specification();

    if(BMS_Comm_type != nullptr)
    {
        delete BMS_Comm_type;
    }
    BMS_Comm_type = new Specification(this,BMS_Comm_type_explain, ui->UI_Parameter_Tab, 1, 1, \
                                      "CAN", tr("BMS Comm type"), \
                                      tr("Battery Communication Modes: None, RS485, CAN, Ethernet. (Note: Due to the fact that CAN and Ethernet both have only one port, the battery communication mode and EMS communication mode cannot be selected as \"CAN\" or \"Ethernet\" simultaneously.)"));
    BMS_Comm_type->add_Specification();

    if(Power_control_type != nullptr)
    {
        delete Power_control_type;
    }
    Power_control_type = new Specification(this,Power_control_type_explain, ui->UI_Parameter_Tab, 2, 1,\
                                           "CP_AC" , tr("Power control type"), \
                                           tr("Constant Voltage (CV) mode: The converter will operate in constant voltage mode on the DC side.\
                                              Constant Current (CC) mode: The converter will operate in constant current mode on the DC side.\
                                              Constant Power AC (CP_AC) mode: The power level can be set at \"constant power.\" The value represents the power level, positive for discharge and negative for charge. For example, setting it to -5 means that the AC side will charge the battery with a power of 5 kW. Due to converter losses, the DC side power will be lower than the AC side power in this case. Conversely, setting it to 5 means that the AC side will output power at 5 kW. Due to converter losses, the DC side power will be higher than the AC side power in this case.\
                                              Reserved."));
    Power_control_type->add_Specification();

    if(EMS_Comm_type != nullptr)
    {
        delete EMS_Comm_type;
    }
    EMS_Comm_type = new Specification(this,EMS_Comm_type_explain, ui->UI_Parameter_Tab, 3, 1, \
                                      "RS485", tr("EMS Comm type"), \
                                      tr("EMS communication methods: RS485, CAN, Ethernet.\
                                         The setting communication methods are readable and writable in remote mode, and only readable in local mode. The unselected communication methods are only readable in both remote and local mode."));
    EMS_Comm_type->add_Specification();

    if(Output_power_limit != nullptr)
    {
        delete Output_power_limit;
    }
    Output_power_limit = new Specification(this,Output_power_limit_explain, ui->UI_Parameter_Tab, 4, 1,\
                                           "100", tr("Output power limit"), \
                                           tr("Output Power Limit: Restricts the upper limit of the set value for the power on the AC side of the converter."));
    Output_power_limit->add_Specification();

    if(BAT_protocol != nullptr)
    {
        delete BAT_protocol;
    }
    BAT_protocol = new Specification(this,BAT_protocol_explain, ui->UI_Parameter_Tab, 5, 1, \
                                          tr("Auto"), tr("BAT protocol"), \
                                          tr("Battery Protocol: Parse the messages sent by BMS based on the selected battery protocol. Currently supported battery manufacturer protocols include:\
MEGA, LISHEN, PENGHUI, GAOTE, XIENENG, LANLI, SHENLAN, PAINENG, NINGDESHIDAI, SUOYING, XINGWANGDA, KUBO, GAOTE_V2, TOGOOD, GROUP_STANDARD, WOBO, KGOOER, LIDE, PAINENG_L, WEILAN, ALPHA, TUOPU, JIEHUI, JDI, FARO.\
                                             \nSelect AUTO to automatically detect the battery manufacturer protocol."));
    BAT_protocol->add_Specification();

    if(Power_Delta != nullptr)
    {
        delete Power_Delta;
    }
    Power_Delta = new Specification(this,Power_Delta_explain, ui->UI_Parameter_Tab, 6, 1, \
                                    "10", tr("Anti-backflow power tolerance"), \
                                    tr("Anti-backflow power tolerance.The default power tolerance is 10 kW. When the output power increases to \"output power limit + power tolerance\", the output power will be reduced to \"output power limit - power tolerance\".\
\n(Note: This setting only takes effect in the system anti-backflow mode and is used to control the power tolerance at the grid entrance)."));
    Power_Delta->add_Specification();


    if(Host_Address != nullptr)
    {
        delete Host_Address;
    }
    Host_Address = new Specification(this,Host_Address_explain, ui->UI_Parameter_Tab, 0, 4,\
                                     "1", tr("Serial Communication Address"), \
                                     tr("Serial Communication Address: The default value is 1, adjustable range is between 1 and 255, used for matching address during serial communication."));
    Host_Address->add_Specification();

    if(serial_port_1 != nullptr)
    {
        delete serial_port_1;
    }
    serial_port_1 = new Specification(this,serial_port_1_explain, ui->UI_Parameter_Tab, 1, 4, \
                                      "9600", tr("serial port 2"), \
                                      tr("Serial Port 2 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 2 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1)."));
    serial_port_1->add_Specification();

    if(serial_port_2 != nullptr)
    {
        delete serial_port_2;
    }
    serial_port_2 = new Specification(this,serial_port_2_explain, ui->UI_Parameter_Tab, 2, 4, \
                                      "9600", tr("serial port 3"), \
                                      tr("Serial Port 3 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 3 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1)."));
    serial_port_2->add_Specification();

    if(serial_port_3 != nullptr)
    {

        delete serial_port_3;
    }
    serial_port_3 = new Specification(this,serial_port_3_explain, ui->UI_Parameter_Tab, 3, 4, \
                                      "9600", tr("serial port 4"), \
                                      tr("Serial Port 4 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 4 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1)."));
    serial_port_3->add_Specification();

    if(serial_port_4 != nullptr)
    {
        delete serial_port_4;
    }
    serial_port_4 = new Specification(this,serial_port_4_explain, ui->UI_Parameter_Tab, 4, 4, \
                                      "9600", tr("serial port 5"), \
                                      tr("Serial Port 5 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 5 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1)."));
    serial_port_4->add_Specification();

    if(serial_port_5 != nullptr)
    {
        delete serial_port_5;
    }
    serial_port_5 = new Specification(this,serial_port_5_explain, ui->UI_Parameter_Tab, 5, 4, \
                                      "9600", tr("serial port 6"), \
                                      tr("Serial Port 6 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 6 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1)."));
    serial_port_5->add_Specification();

    if(Can_port_1 != nullptr)
    {
        delete Can_port_1;
    }
    Can_port_1 = new Specification(this,Can_port_1_explain, ui->UI_Parameter_Tab, 6, 4, \
                                   "500", tr("Can port 1"), \
                                   tr("CAN1 Port: The baud rate for internal communication is 500 kbps by default and cannot be modified. "));
    Can_port_1->add_Specification();

    if(Can_port_2 != nullptr)
    {
        delete Can_port_2;
    }
    Can_port_2 = new Specification(this,Can_port_2_explain, ui->UI_Parameter_Tab, 7, 4, \
                                   "125", tr("Can port 2"), \
                                   tr("CAN2 Port: Optional baud rates for the CAN2 port include 100, 125, 250, 500, and 800 kbps, with a default baud rate of 500 kbps."));
    Can_port_2->add_Specification();

    if(ProtocolVersion != nullptr)
    {
        delete ProtocolVersion;
    }
    ProtocolVersion = new Specification(this,ProtocolVersion_explain, ui->UI_Parameter_Tab, 0, 7, \
                                        "V1.0", tr("ProtocolVersion"), \
                                        tr("Protocol version: View the current protocol version. The default protocol version number is V1.0."));
    ProtocolVersion->add_Specification();

    if(UserPassPort != nullptr)
    {
        delete UserPassPort;
    }
    UserPassPort = new Specification(this,UserPassPort_explain, ui->UI_Parameter_Tab, 1, 7, \
                                     "123456", tr("UserPassPort"), \
                                     tr("User password: Available for resetting the user password. The default user password is 123456. (Note: The user password must be six digits.)"));
    UserPassPort->add_Specification();

    if(RootPassport != nullptr)
    {
        delete RootPassport;
    }
    RootPassport = new Specification(this,RootPassport_explain, ui->UI_Parameter_Tab, 2, 7,\
                                     "888888", tr("Admin password"), \
                                     tr("Admin password: Available for resetting the admin password. The default admin password is 888888. (Note: The admin password must be six digits.)"));
    RootPassport->add_Specification();

    if(Language != nullptr)
    {
        delete Language;
    }
    Language = new Specification(this,Language_explain, ui->UI_Parameter_Tab, 3, 7, \
                                 tr("English"), tr("Language"), \
                                 tr("Set the display language of the display screen, which can be selected as Chinese and English. The system will restart when switching languages."));
    Language->add_Specification();

    /*if(System_upgrade != nullptr)
    {
        delete System_upgrade;
    }
    System_upgrade = new Specification(this,System_upgrade_explain, ui->UI_Parameter_Tab, 4, 7, \
                                       tr("upgrade"), tr("System upgrade"), \
                                       tr("Click to enter the system upgrade application and upgrade the system according to the upgrade document."));
    System_upgrade->add_Specification();*/

    //系统升级说明
    System_upgrade_explain->setText(tr("upgrade"));
    ui->UI_Parameter_Tab->setCellWidget(4, 7, (QWidget *)System_upgrade_explain);

    if(Sounds != nullptr)
    {
        delete Sounds;
    }
    Sounds = new Specification(this,Sounds_explain, ui->UI_Parameter_Tab, 5, 7, \
                               tr("Allow"), tr("Sounds"), \
                               tr("Set whether the display is enabled sound, which can be allowed(Allow) or prohibited(forbid)."));
    Sounds->add_Specification();

    if(EnergyMeterModel != nullptr)
    {
        delete EnergyMeterModel;
    }
    EnergyMeterModel = new Specification(this,EnergyMeterModel_explain, ui->UI_Parameter_Tab, 6, 7, \
                               tr("NONE"), tr("Energy Meter Model"), \
                               tr("Energy meter model: The energy meter model is selected according to the type of energy meter that is connected. According to the characteristics and specifications of the connected watt-hour meter, select the corresponding watt-hour meter model, which can be selected NONE, DTSD1352, AMC96-E4/KC or ADL3000-E-B."));
    EnergyMeterModel->add_Specification();

    if(BmsComFaultTime != nullptr)
    {
        delete BmsComFaultTime;
    }
    BmsComFaultTime = new Specification(this,BmsComFaultTime_explain, ui->UI_Parameter_Tab, 7, 7, \
                               tr("20"), tr("Bms Com. Fault Time"), \
                               tr("BMS communication fault determination time: The BMS communication fault determination time refers to the BMS communication fault when the BMS communication is disconnected and the communication is not recovered after a preset period of time."));
    BmsComFaultTime->add_Specification();

    if(EMSComFaultModel != nullptr)
    {
        delete EMSComFaultModel;
    }
    EMSComFaultModel = new Specification(this,EMSComFaultModel_explain, ui->UI_Parameter_Tab, 8, 7, \
                               tr("120"), tr("EMS Com. Fault Model"), \
                               tr("EMS communication fault determination time: The EMS communication fault determination time refers to the time when the communication between the EMS is disconnected and the communication is not recovered after a preset period of time."));
    EMSComFaultModel->add_Specification();


}

/***************************************************************
 * 系统参数
 ***************************************************************/
void MEGAWin::SystemParameter()
{
    if(Change_rate_of_power != nullptr)
    {
        delete Change_rate_of_power;
    }
    Change_rate_of_power = new Specification(this,Change_rate_of_power_explain, ui->UI_SystemParameter_Tab, 0, 1, \
                                             "20", tr("Power change rate"), \
                                             tr("Power change rate: the rate at which power changes within a second ."));
    Change_rate_of_power->add_Specification();

    if(Grid_frequency_upper_limit != nullptr)
    {
        delete Grid_frequency_upper_limit;
    }
    Grid_frequency_upper_limit = new Specification(this,Grid_frequency_upper_limit_explain, ui->UI_SystemParameter_Tab, 1, 1, \
                                                   "3", tr("Grid frequency upper limit"), \
                                                   tr("Upper limit of power grid frequency variation: The maximum range of frequency variation allowed on the AC side, which can be selected as 0.2, 0.5, 1, 5."));
    Grid_frequency_upper_limit->add_Specification();

    if(Grid_frequency_lower_limit != nullptr)
    {
        delete Grid_frequency_lower_limit;
    }
    Grid_frequency_lower_limit = new Specification(this,Grid_frequency_lower_limit_explain, ui->UI_SystemParameter_Tab, 2, 1, \
                                                   "-3", tr("Grid frequency lower limit"), \
                                                   tr("Lower limit of power grid frequency variation range: The maximum range of frequency variation allowed on the AC side, which can be selected as-0.5, -1, -2, -5."));
    Grid_frequency_lower_limit->add_Specification();

    if(Vol_protection_upper_limit != nullptr)
    {
        delete Vol_protection_upper_limit;
    }
    Vol_protection_upper_limit = new Specification(this,Vol_protection_upper_limit_explain, ui->UI_SystemParameter_Tab, 3, 1, \
                                                   "+15", tr("Vol protection upper limit"), \
                                                   tr("Upper limit of voltage protection range: The maximum range of voltage variation allowed on the AC side, which can be selected as 10, 15, 20."));
    Vol_protection_upper_limit->add_Specification();

    if(Vol_protection_lower_limit != nullptr)
    {
        delete Vol_protection_lower_limit;
    }
    Vol_protection_lower_limit = new Specification(this,Vol_protection_lower_limit_explain, ui->UI_SystemParameter_Tab, 4, 1, \
                                                   "-15", tr("Vol protection lower limit"), \
                                                   tr("Lower limit of voltage protection range: The minimum range of voltage variation allowed on the AC side, which can be selected as -10, -15, -20."));
    Vol_protection_lower_limit->add_Specification();

    if(HVRT_enable != nullptr)
    {
        delete HVRT_enable;
    }
    HVRT_enable = new Specification(this,HVRT_enable_explain, ui->UI_SystemParameter_Tab, 5, 1, \
                                                    tr("prohibit"), tr("HVRT enable"), \
                                                    tr("High voltage ride through(HVRT) enablement: Enable, Disable. (Note: This option is generally used in large grid-on power stations.)"));
    HVRT_enable->add_Specification();

    if(LVRT_enable != nullptr)
    {
        delete LVRT_enable;
    }
    LVRT_enable = new Specification(this,LVRT_enable_explain, ui->UI_SystemParameter_Tab, 6, 1, \
                                    tr("prohibit"), tr("LVRT enable"), \
                                    tr("Low voltage ride through(LVRT) enablement: Enable, Disable. (Note: This option is generally used in large grid-on power stations.)"));
    LVRT_enable->add_Specification();

    if(AFD_enable != nullptr)
    {
        delete AFD_enable;
    }
    AFD_enable = new Specification(this,AFD_enable_explain, ui->UI_SystemParameter_Tab, 7, 1, \
                                   tr("prohibit"), tr("AFD enable"), \
                                   tr("Prevent islanding effect. When islanding effect is detected (in a photovoltaic grid-on system, when a power outage occurs in the main grid, and the PV grid-connected converter generates power that matches the local load on the low-voltage side of the grid, it can easily sustain power generation independently, resulting in an 'island' phenomenon, which endangers the safety of maintenance personnel), the converter automatically shuts down.\
 The options for this feature can be set as 'Enable' or 'prohibited' .(Note: This option is generally used in large grid-on power stations.)"));
    AFD_enable->add_Specification();

    if(Insulation_detection_enable != nullptr)
    {
        delete Insulation_detection_enable;
    }
    Insulation_detection_enable = new Specification(this,Insulation_detection_enable_explain, ui->UI_SystemParameter_Tab, 8, 1, \
                                                    tr("prohibit"), tr("Insulation detection enable"), \
                                                    tr("Insulation detection enable, the insulation resistance should be greater than 33KΩ for normal start-up and operation. If it is less than 33KΩ, it should not start, and an alarm should be triggered. By default, it is disabled, but can be set as 'Enable' or 'prohibited'."));
    Insulation_detection_enable->add_Specification();

    if(PrimaryFreq_enable != nullptr)
    {
        delete PrimaryFreq_enable;
    }
    PrimaryFreq_enable = new Specification(this,PrimaryFreq_enable_explain, ui->UI_SystemParameter_Tab, 9, 1, \
                                           tr("prohibit"), tr("PrimaryFreq enable"), \
                                           tr("Primary frequency control enable: When the grid frequency deviates from the rated value, the active power is controlled to increase or decrease in order to maintain the grid frequency at the rated value. It can be selected as enabled or disabled. (Note: This option is generally used in large grid-on power stations.)"));
    PrimaryFreq_enable->add_Specification();

    if(Inertia_enable != nullptr)
    {
        delete Inertia_enable;
    }
    Inertia_enable = new Specification(this,Inertia_enable_explain, ui->UI_SystemParameter_Tab, 10, 1, \
                                       tr("prohibit"), tr("Inertia enable"), \
                                       tr("Rotational inertia enable: It can be selected as enabled or disabled. (Note: This option is generally used in large grid-on power stations.)"));
    Inertia_enable->add_Specification();

    if(CV_parallel != nullptr)
    {
        delete CV_parallel;
    }
    CV_parallel = new Specification(this,CV_parallel_explain, ui->UI_SystemParameter_Tab, 11, 1, \
                                    tr("prohibit"), tr("CV parallel"), \
                                    tr("Constant voltage parallel operation enable: It can be selected as enabled or disabled.  (Note: This option is generally used in large grid-on power stations.)"));
    CV_parallel->add_Specification();

    if(Machine_type != nullptr)
    {
        delete Machine_type;
    }
    Machine_type = new Specification(this,Machine_type_explain, ui->UI_SystemParameter_Tab, 0, 4, \
                                     "PCS-TS", tr("Machine type"), \
                                     tr("Converter Model: As per factory settings, generally not modifiable."));
    Machine_type->add_Specification();

    if(Machine_capacity != nullptr)
    {
        delete Machine_capacity;
    }
    Machine_capacity = new Specification(this,Machine_capacity_explain, ui->UI_SystemParameter_Tab, 1, 4, \
                                     "100", tr("Machine capacity"), \
                                     tr("The rated capacity of the converter shall be based on the factory value and cannot be changed."));
    Machine_capacity->add_Specification();

    if(Output_Fre_grade != nullptr)
    {
        delete Output_Fre_grade;
    }
    Output_Fre_grade = new Specification(this,Output_Fre_grade_explain, ui->UI_SystemParameter_Tab, 2, 4, \
                                         "50", tr("Output Fre grade"), \
                                         tr("Output Frequency Level: Default 50Hz, typically 50Hz or 60Hz."));
    Output_Fre_grade->add_Specification();

    if(Output_vol_level != nullptr)
    {
        delete Output_vol_level;
    }
    Output_vol_level = new Specification(this,Output_vol_level_explain, ui->UI_SystemParameter_Tab, 3, 4, \
                                         "400", tr("Output vol level"), \
                                         tr("Output Voltage Level: As per factory settings, generally not modifiable."));
    Output_vol_level->add_Specification();

    if(Converter_side_vol_level != nullptr)
    {
        delete Converter_side_vol_level;
    }
    Converter_side_vol_level = new Specification(this,Converter_side_vol_level_explain, ui->UI_SystemParameter_Tab, 4, 4, \
                                         "270:400", tr("Transformer Turns Ratio"), \
                                         tr("Transformer Voltage Ratio: To be determined by the factory nameplate, not modifiable."));
    Converter_side_vol_level->add_Specification();

    if(Output_reactive_power_mode != nullptr)
    {
        delete Output_reactive_power_mode;
    }
    Output_reactive_power_mode = new Specification(this,Output_reactive_power_mode_explain, ui->UI_SystemParameter_Tab, 5, 4, \
                                         tr("Non\nadjustable"), tr("Output reactive power mode"), \
                                         tr("Reactive Power Output Mode: Default non-adjustable, options include Power Factor, Reactive Power, non-adjustable."));
    Output_reactive_power_mode->add_Specification();

    if(Grid_connected_mode_of_Inv != nullptr)
    {
        delete Grid_connected_mode_of_Inv;
    }
    Grid_connected_mode_of_Inv = new Specification(this,Grid_connected_mode_of_Inv_explain, ui->UI_SystemParameter_Tab, 6, 4, \
                                                   tr("Disable"), tr("Converter Anti-Reverse Flow"), \
                                                   tr("Converter Anti-Reverse Flow: Enable, Disable; Enabling prevents converter current from flowing into the grid, while Disabling allows converter current to flow into the grid."));
    Grid_connected_mode_of_Inv->add_Specification();

    //系统防逆流
    if(System_Anti_Reverse_Flow != nullptr)
    {
        delete System_Anti_Reverse_Flow;
    }
    System_Anti_Reverse_Flow = new Specification(this,System_Anti_Reverse_Flow_explain, ui->UI_SystemParameter_Tab, 7, 4, \
                                                   tr("Disable"), tr("System Anti-Reverse Flow"), \
                                                   tr("System Anti-Reverse Flow: Enable, Disable;\
\nEnabling prevents system current from flowing into the grid, while Disabling allows system current to flow into the grid."));
    System_Anti_Reverse_Flow->add_Specification();

    if(Primary_FM_dead_zone != nullptr)
    {
        delete Primary_FM_dead_zone;
    }
    Primary_FM_dead_zone = new Specification(this,Primary_FM_dead_zone_explain, ui->UI_SystemParameter_Tab, 8, 4, \
                                             "3", tr("Primary FM dead zone"), \
                                             tr("Frequency Deviation Deadzone: A frequency difference settings to prevent unnecessary frequency regulation actions during minor grid frequency fluctuations. (Note: This option is generally used in large grid-on power stations.)"));
    Primary_FM_dead_zone->add_Specification();

    if(PFM_coeff != nullptr)
    {
        delete PFM_coeff;
    }
    PFM_coeff = new Specification(this,PFM_coeff_explain, ui->UI_SystemParameter_Tab, 9, 4, \
                                  "20", tr("PFM coeff"), \
                                  tr("Active Frequency Regulation Coefficient: The active frequency regulation coefficient can be configured. (Note: This option is generally used in large grid-on power stations.)"));
    PFM_coeff->add_Specification();

    if(Grid_recover_time != nullptr)
    {
        delete Grid_recover_time;
    }
    Grid_recover_time = new Specification(this,Grid_recover_time_explain, ui->UI_SystemParameter_Tab, 10, 4, \
                                          "10", tr("Grid recover time"), \
                                          tr("Grid restoration time: reserved function, setting invalid."));
    Grid_recover_time->add_Specification();

    /*if(DynamicCap!= nullptr)
    {
        delete DynamicCap;
    }
    DynamicCap = new Specification(this,DynamicCap_explain, ui->UI_SystemParameter_Tab, 10, 4, \
                                   tr("Enable"), tr("DynamicCap"), \
                                   tr("Enable the power network expansion. The options are Enable and Disable."));
    DynamicCap->add_Specification();*/

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

    if(BackupSetParameters != nullptr)
    {
        delete BackupSetParameters;
    }
    BackupSetParameters = new Specification(this,BackupSetParameters_explain, ui->UI_SystemParameter_Tab,2, 7, \
                                        tr("Backup"), tr("Backup Set Parameters"), \
                                        tr("Backup setting parameters: Backup setting parameters refers to backing up the parameters set on the current device so that the backup parameter Settings can be restored when needed."));
    BackupSetParameters->add_Specification();

    if(RestoreBackupSetParameters != nullptr)
    {
        delete RestoreBackupSetParameters;
    }
    RestoreBackupSetParameters = new Specification(this,RestoreBackupSetParameters_explain, ui->UI_SystemParameter_Tab,3, 7, \
                                        tr("Restore\nBackup"), tr("Restore Backup Set Parameters"), \
                                        tr("Restore backup setting parameters: Restore backup setting parameters means to restore the device to the last backup setting parameters and restart the device."));
    RestoreBackupSetParameters->add_Specification();

    if(Clear_Data != nullptr)
    {
        delete Clear_Data;
    }
    Clear_Data = new Specification(this,Clear_Data_explain, ui->UI_SystemParameter_Tab, 4, 7, \
                                   tr("Clear"), tr("Clear Data"), \
                                   tr("Clear previous recorded data and operation data of the system."));
    Clear_Data->add_Specification();
}

/***************************************************************
 * 外设
 ***************************************************************/
void MEGAWin::Peripheral()
{
    QString str = tr("Normally closed circuit (NC) or normally open circuit (NO) according to field Settings.");
    QString str1 = tr("When the dry contact is enabled, the device will perform the selected action when there is a change in the signal.");
    QString str2 = tr("Input Dry Contact: \
                      \nEnabled: Triggers the Action when the dry contact detects a state other than the specified NO/NC.\
                      \nDisabled: No action is taken when the dry contact detects a state other than the specified NO/NC.");

    if(DI_1_Enable != nullptr)
    {
        delete DI_1_Enable;
    }
    DI_1_Enable = new Specification(this,DI_1_Enable_explain, ui->ExternalDevice_tW, 0, 0, \
                                   tr("Enable"), tr("DI 1 Enable"), str2 );
    DI_1_Enable->add_Specification();

    if(DI_2_Enable != nullptr)
    {
        delete DI_2_Enable;
    }
    DI_2_Enable = new Specification(this,DI_2_Enable_explain, ui->ExternalDevice_tW, 1, 0, \
                                   tr("Disable"), tr("DI 2 Enable"), str2);
    DI_2_Enable->add_Specification();

    if(DI_3_Enable != nullptr)
    {
        delete DI_3_Enable;
    }
    DI_3_Enable = new Specification(this,DI_3_Enable_explain, ui->ExternalDevice_tW, 2, 0, \
                                   tr("Enable"), tr("DI 3 Enable"), str2);
    DI_3_Enable->add_Specification();

    if(DI_4_Enable != nullptr)
    {
        delete DI_4_Enable;
    }
    DI_4_Enable = new Specification(this,DI_4_Enable_explain, ui->ExternalDevice_tW, 3, 0, \
                                   tr("Enable"), tr("DI 4 Enable"), str2);
    DI_4_Enable->add_Specification();

    if(DI_5_Enable != nullptr)
    {
        delete DI_5_Enable;
    }
    DI_5_Enable = new Specification(this,DI_5_Enable_explain, ui->ExternalDevice_tW, 4, 0, \
                                   tr("Enable"), tr("DI 5 Enable"), str2);
    DI_5_Enable->add_Specification();

    if(DI_6_Enable != nullptr)
    {
        delete DI_6_Enable;
    }
    DI_6_Enable = new Specification(this,DI_6_Enable_explain, ui->ExternalDevice_tW, 5, 0, \
                                   tr("Enable"), tr("DI 6 Enable"), str2);
    DI_6_Enable->add_Specification();

    if(DI_1_NC_O != nullptr)
    {
        delete DI_1_NC_O;
    }
    DI_1_NC_O = new Specification(this,DI_1_NC_O_explain, ui->ExternalDevice_tW, 0, 1, \
                                   "N_O", tr("DI_1_NC_O"), str);
    DI_1_NC_O->add_Specification();

    if(DI_2_NC_O != nullptr)
    {
        delete DI_2_NC_O;
    }
    DI_2_NC_O = new Specification(this,DI_2_NC_O_explain, ui->ExternalDevice_tW, 1, 1, \
                                   "N_O", tr("DI_2_NC_O"), str);
    DI_2_NC_O->add_Specification();

    if(DI_3_NC_O != nullptr)
    {
        delete DI_3_NC_O;
    }
    DI_3_NC_O = new Specification(this,DI_3_NC_O_explain, ui->ExternalDevice_tW, 2, 1, \
                                   "N_C", tr("DI_3_NC_O"), str);
    DI_3_NC_O->add_Specification();

    if(DI_4_NC_O != nullptr)
    {
        delete DI_4_NC_O;
    }
    DI_4_NC_O = new Specification(this,DI_4_NC_O_explain, ui->ExternalDevice_tW, 3, 1, \
                                   "N_O", tr("DI_4_NC_O"), str);
    DI_4_NC_O->add_Specification();

    if(DI_5_NC_O != nullptr)
    {
        delete DI_5_NC_O;
    }
    DI_5_NC_O = new Specification(this,DI_5_NC_O_explain, ui->ExternalDevice_tW, 4, 1, \
                                   "N_O", tr("DI_5_NC_O"), str);
    DI_5_NC_O->add_Specification();

    if(DI_6_NC_O != nullptr)
    {
        delete DI_6_NC_O;
    }
    DI_6_NC_O = new Specification(this,DI_6_NC_O_explain, ui->ExternalDevice_tW, 5, 1, \
                                   "N_O", tr("DI_6_NC_O"), str);
    DI_6_NC_O->add_Specification();

    if(DI_1_Action != nullptr)
    {
        delete DI_1_Action;
    }
    DI_1_Action = new Specification(this,DI_1_Action_explain, ui->ExternalDevice_tW, 0, 2, \
                                   tr("Shut down"), tr("DI_1_Action"), str1);
    DI_1_Action->add_Specification();

    if(DI_2_Action != nullptr)
    {
        delete DI_2_Action;
    }
    DI_2_Action = new Specification(this,DI_2_Action_explain, ui->ExternalDevice_tW, 1, 2, \
                                   tr("Prompt"), tr("DI_2_Action"), str1);
    DI_2_Action->add_Specification();

    if(DI_3_Action != nullptr)
    {
        delete DI_3_Action;
    }
    DI_3_Action = new Specification(this,DI_3_Action_explain, ui->ExternalDevice_tW, 2, 2, \
                                   tr("Prompt"), tr("DI_3_Action"), str1);
    DI_3_Action->add_Specification();

    if(DI_4_Action != nullptr)
    {
        delete DI_4_Action;
    }
    DI_4_Action = new Specification(this,DI_4_Action_explain, ui->ExternalDevice_tW, 3, 2, \
                                   tr("Prompt"), tr("DI_4_Action"), str1);
    DI_4_Action->add_Specification();

    if(DI_5_Action != nullptr)
    {
        delete DI_5_Action;
    }
    DI_5_Action = new Specification(this,DI_5_Action_explain, ui->ExternalDevice_tW, 4, 2, \
                                   tr("Shut down"), tr("DI_5_Action"), str1);
    DI_5_Action->add_Specification();

    if(DI_6_Action != nullptr)
    {
        delete DI_6_Action;
    }
    DI_6_Action = new Specification(this,DI_6_Action_explain, ui->ExternalDevice_tW, 5, 2, \
                                   tr("Shut down"), tr("DI_6_Action"), str1);
    DI_6_Action->add_Specification();
}

/***************************************************************
 * BMS保护
 ***************************************************************/
void MEGAWin::BMS_Protect()
{
    if(DOD_Action != nullptr)
    {
        delete DOD_Action;
    }
    DOD_Action = new Specification(this,DOD_Action_explain, ui->BMSProtection_tW, 0, 0, \
                                   tr("Standby"), "DOD", \
                                   tr("DOD protection: Actions to be performed when DOD protection is triggered. The optional functions are NO action, Standby, Shut down,0 power standby."));
    DOD_Action->add_Specification();

    if(Prohibit_charging_Action != nullptr)
    {
        delete Prohibit_charging_Action;
    }
    Prohibit_charging_Action = new Specification(this,Prohibit_charging_Action_explain, ui->BMSProtection_tW, 1, 0, \
                                   tr("Standby"), tr("Prohibit charging"), \
                                   tr("The action performed when the charge ban is triggered;Optional function: NO action, Standby, Shut down,0 power standby."));
    Prohibit_charging_Action->add_Specification();

    if(Prohibit_discharging_Action != nullptr)
    {
        delete Prohibit_discharging_Action;
    }
    Prohibit_discharging_Action = new Specification(this,Prohibit_discharging_Action_explain, ui->BMSProtection_tW, 2, 0, \
                                   tr("Standby"), tr("Prohibit discharging"), \
                                   tr("The action to be performed when a ban is triggered.The optional functions are NO action, Standby, Shut down,0 power standby."));
    Prohibit_discharging_Action->add_Specification();

    if(BMS_warning_Action != nullptr)
    {
        delete BMS_warning_Action;
    }
    BMS_warning_Action = new Specification(this,BMS_warning_Action_explain, ui->BMSProtection_tW, 3, 0, \
                                   tr("NO action"), tr("level 1 alarm"), \
                                   tr("Action to be performed when level 1 alarm is triggered.The optional functions are NO action, Power down, Standby, Shut down,0 power standby."));
    BMS_warning_Action->add_Specification();

    if(BMS_alarm_Action != nullptr)
    {
        delete BMS_alarm_Action;
    }
    BMS_alarm_Action = new Specification(this,BMS_alarm_Action_explain, ui->BMSProtection_tW, 4, 0, \
                                   tr("Standby"), tr("level 2 alarm"), \
                                   tr("Action to be performed when level 2 alarm is triggered.The optional functions are NO action, Power down, Standby, Shut down,0 power standby."));
    BMS_alarm_Action->add_Specification();

    if(BMS_fualt_Action != nullptr)
    {
        delete BMS_fualt_Action;
    }
    BMS_fualt_Action = new Specification(this,BMS_fualt_Action_explain, ui->BMSProtection_tW, 5, 0, \
                                   tr("Shut down"), tr("level 3 alarm"), \
                                   tr("Action that is performed when level 3 alarm is triggered.The optional functions are NO action, Standby, Shut down,0 power standby."));
    BMS_fualt_Action->add_Specification();

    if(BMS_warning_CP != nullptr)
    {
        delete BMS_warning_CP;
    }
    BMS_warning_CP = new Specification(this,BMS_warning_CP_explain, ui->BMSProtection_tW, 3, 1, \
                                   "0", tr("level 1 alarm CP"), \
                                   tr("The charging power executed when a level 1 alarm is triggered."));
    BMS_warning_CP->add_Specification();

    if(BMS_alarm_CP != nullptr)
    {
        delete BMS_alarm_CP;
    }
    BMS_alarm_CP = new Specification(this,BMS_alarm_CP_explain, ui->BMSProtection_tW, 4, 1, \
                                   "0", tr("level 2 alarm CP"), \
                                   tr("The charging power executed when a level 2 alarm is triggered."));
    BMS_alarm_CP->add_Specification();

    /*if(BMS_fualt_CP != nullptr)
    {
        delete BMS_fualt_CP;
    }
    BMS_fualt_CP = new Specification(this,BMS_fualt_CP_explain, ui->BMSProtection_tW, 5, 1, \
                                   "0", tr("BMS fualt CP"), \
                                   tr("Charging power when a BMS fault is triggered."));
    BMS_fualt_CP->add_Specification();*/

    if(BMS_warning_DP != nullptr)
    {
        delete BMS_warning_DP;
    }
    BMS_warning_DP = new Specification(this,BMS_warning_DP_explain, ui->BMSProtection_tW, 3, 2, \
                                   "0", tr("level 1 alarm DP"), \
                                   tr("The discharging power executed when a level 1 alarm is triggered."));
    BMS_warning_DP->add_Specification();

    if(BMS_alarm_DP != nullptr)
    {
        delete BMS_alarm_DP;
    }
    BMS_alarm_DP = new Specification(this,BMS_alarm_DP_explain, ui->BMSProtection_tW, 4, 2, \
                                   "0", tr("level 2 alarm DP"), \
                                   tr("The discharging power executed when a level 2 alarm is triggered."));
    BMS_alarm_DP->add_Specification();

    /*if(BMS_fualt_DP != nullptr)
    {
        delete BMS_fualt_DP;
    }
    BMS_fualt_DP = new Specification(this,BMS_fualt_DP_explain, ui->BMSProtection_tW, 5, 2, \
                                   "0", tr("BMS fualt DP"), \
                                   tr("Discharge power when triggering a BMS fault."));
    BMS_fualt_DP->add_Specification();*/
}

/***************************************************************
 * 调试
 ***************************************************************/
void MEGAWin::Debugg()
{
    QString str = tr("It is used for internal debugging only.");

    if(Debug_variable_1 != nullptr)
    {
        delete Debug_variable_1;
    }
    Debug_variable_1 = new Specification(this,Debug_variable_1_explain, ui->UI_Debug_Tab, 0, 1, \
                                   "0", tr("Debug variable 1"), str);
    Debug_variable_1->add_Specification();

    if(Debug_variable_2 != nullptr)
    {
        delete Debug_variable_2;
    }
    Debug_variable_2 = new Specification(this,Debug_variable_2_explain, ui->UI_Debug_Tab, 1, 1, \
                                   "0", tr("Debug variable 2"), str);
    Debug_variable_2->add_Specification();

    if(Debug_variable_3 != nullptr)
    {
        delete Debug_variable_3;
    }
    Debug_variable_3 = new Specification(this,Debug_variable_3_explain, ui->UI_Debug_Tab, 2, 1, \
                                   "0", tr("Debug variable 3"), str);
    Debug_variable_3->add_Specification();

    if(Debug_variable_1_addr != nullptr)
    {
        delete Debug_variable_1_addr;
    }
    Debug_variable_1_addr = new Specification(this,Debug_variable_1_addr_explain, ui->UI_Debug_Tab, 3, 1, \
                                   "4096", tr("Debug variable 1 addr"), str);
    Debug_variable_1_addr->add_Specification();

    if(Debug_variable_2_addr != nullptr)
    {
        delete Debug_variable_2_addr;
    }
    Debug_variable_2_addr = new Specification(this,Debug_variable_2_addr_explain, ui->UI_Debug_Tab, 4, 1, \
                                   "4096", tr("Debug variable 2 addr"), str);
    Debug_variable_2_addr->add_Specification();

    if(Debug_variable_3_addr != nullptr)
    {
        delete Debug_variable_3_addr;
    }
    Debug_variable_3_addr = new Specification(this,Debug_variable_3_addr_explain, ui->UI_Debug_Tab, 5, 1, \
                                   "4096", tr("Debug variable 3 addr"), str);
    Debug_variable_3_addr->add_Specification();

    if(Debug_memery_var_1 != nullptr)
    {
        delete Debug_memery_var_1;
    }
    Debug_memery_var_1 = new Specification(this,Debug_memery_var_1_explain, ui->UI_Debug_Tab, 6, 1, \
                                   "0", tr("Debug memery var 1"), str);
    Debug_memery_var_1->add_Specification();

    if(Debug_memery_var_2 != nullptr)
    {
        delete Debug_memery_var_2;
    }
    Debug_memery_var_2 = new Specification(this,Debug_memery_var_2_explain, ui->UI_Debug_Tab, 7, 1, \
                                   "0", tr("Debug memery var 2"), str);
    Debug_memery_var_2->add_Specification();

    if(Debug_memery_var_3 != nullptr)
    {
        delete Debug_memery_var_3;
    }
    Debug_memery_var_3 = new Specification(this,Debug_memery_var_3_explain, ui->UI_Debug_Tab, 8, 1, \
                                   "0", tr("Debug memery var 3"), str);
    Debug_memery_var_3->add_Specification();

    if(Input_Vol_revise != nullptr)
    {
        delete Input_Vol_revise;
    }
    Input_Vol_revise = new Specification(this,Input_Vol_revise_explain, ui->UI_Debug_Tab, 9, 1, \
                                   "", tr("Input Vol revise"), str);
    Input_Vol_revise->add_Specification();

    if(Input_Cur_revise != nullptr)
    {
        delete Input_Cur_revise;
    }
    Input_Cur_revise = new Specification(this,Input_Cur_revise_explain, ui->UI_Debug_Tab, 10, 1, \
                                   "", tr("Input Cur revise"), str);
    Input_Cur_revise->add_Specification();

    if(Voltage_1_5_revise != nullptr)
    {
        delete Voltage_1_5_revise;
    }
    Voltage_1_5_revise = new Specification(this,Voltage_1_5_revise_explain, ui->UI_Debug_Tab, 0, 3, \
                                   "", tr("1.5 Voltage revise"), str);
    Voltage_1_5_revise->add_Specification();

    if(Bus_Vol_revise != nullptr)
    {
        delete Bus_Vol_revise;
    }
    Bus_Vol_revise = new Specification(this,Bus_Vol_revise_explain, ui->UI_Debug_Tab, 1, 3, \
                                   "", tr("Bus Vol revise"), str);
    Bus_Vol_revise->add_Specification();

    if(Grid_A_AB_Vol_revise != nullptr)
    {
        delete Grid_A_AB_Vol_revise;
    }
    Grid_A_AB_Vol_revise = new Specification(this,Grid_A_AB_Vol_revise_explain, ui->UI_Debug_Tab, 2, 3, \
                                   "", tr("Grid A AB Vol revise"), str);
    Grid_A_AB_Vol_revise->add_Specification();

    if(Grid_B_BC_Vol_revise != nullptr)
    {
        delete Grid_B_BC_Vol_revise;
    }
    Grid_B_BC_Vol_revise = new Specification(this,Grid_B_BC_Vol_revise_explain, ui->UI_Debug_Tab, 3, 3, \
                                   "", tr("Grid B BC Vol revise"), str);
    Grid_B_BC_Vol_revise->add_Specification();

    if(Grid_C_CA_Vol_revise != nullptr)
    {
        delete Grid_C_CA_Vol_revise;
    }
    Grid_C_CA_Vol_revise = new Specification(this,Grid_C_CA_Vol_revise_explain, ui->UI_Debug_Tab, 4, 3, \
                                   "", tr("Grid C CA Vol revise"), str);
    Grid_C_CA_Vol_revise->add_Specification();

    if(Output_A_Cur_revise != nullptr)
    {
        delete Output_A_Cur_revise;
    }
    Output_A_Cur_revise = new Specification(this,Output_A_Cur_revise_explain, ui->UI_Debug_Tab, 5, 3, \
                                   "", tr("Output A Cur revise"), str);
    Output_A_Cur_revise->add_Specification();

    if(Output_B_Cur_revise != nullptr)
    {
        delete Output_B_Cur_revise;
    }
    Output_B_Cur_revise = new Specification(this,Output_B_Cur_revise_explain, ui->UI_Debug_Tab, 6, 3, \
                                   "", tr("Output B Cur revise"), str);
    Output_B_Cur_revise->add_Specification();

    if(Output_C_Cur_revise != nullptr)
    {
        delete Output_C_Cur_revise;
    }
    Output_C_Cur_revise = new Specification(this,Output_C_Cur_revise_explain, ui->UI_Debug_Tab, 7, 3, \
                                   "", tr("Output C Cur revise"), str);
    Output_C_Cur_revise->add_Specification();

    if(INV_A_Vol_revise != nullptr)
    {
        delete INV_A_Vol_revise;
    }
    INV_A_Vol_revise = new Specification(this,INV_A_Vol_revise_explain, ui->UI_Debug_Tab, 8, 3, \
                                   "", tr("INV A Vol revise"), str);
    INV_A_Vol_revise->add_Specification();

    if(INV_B_Vol_revise != nullptr)
    {
        delete INV_B_Vol_revise;
    }
    INV_B_Vol_revise = new Specification(this,INV_B_Vol_revise_explain, ui->UI_Debug_Tab, 9, 3, \
                                   "", tr("INV B Vol revise"), str);
    INV_B_Vol_revise->add_Specification();

    if(INV_C_Vol_revise != nullptr)
    {
        delete INV_C_Vol_revise;
    }
    INV_C_Vol_revise = new Specification(this,INV_C_Vol_revise_explain, ui->UI_Debug_Tab, 10, 3, \
                                   "", tr("INV C Vol revise"), str);
    INV_C_Vol_revise->add_Specification();

    if(INV_A_ind_Cur_revise != nullptr)
    {
        delete INV_A_ind_Cur_revise;
    }
    INV_A_ind_Cur_revise = new Specification(this,INV_A_ind_Cur_revise_explain, ui->UI_Debug_Tab, 0, 5, \
                                   "", tr("INV A ind Cur revise"), str);
    INV_A_ind_Cur_revise->add_Specification();

    if(INV_B_ind_Cur_revise != nullptr)
    {
        delete INV_B_ind_Cur_revise;
    }
    INV_B_ind_Cur_revise = new Specification(this,INV_B_ind_Cur_revise_explain, ui->UI_Debug_Tab, 1, 5, \
                                   "", tr("INV B ind Cur revise"), str);
    INV_B_ind_Cur_revise->add_Specification();

    if(INV_C_ind_Cur_revise != nullptr)
    {
        delete INV_C_ind_Cur_revise;
    }
    INV_C_ind_Cur_revise = new Specification(this,INV_C_ind_Cur_revise_explain, ui->UI_Debug_Tab, 2, 5, \
                                   "", tr("INV_C_ind_Cur_revise"), str);
    INV_C_ind_Cur_revise->add_Specification();

    if(INV_On_off_flag != nullptr)
    {
        delete INV_On_off_flag;
    }
    INV_On_off_flag = new Specification(this,INV_On_off_flag_explain, ui->UI_Debug_Tab, 3, 5, \
                                   "0", tr("INV On off flag"), str);
    INV_On_off_flag->add_Specification();

    if(Logic_state != nullptr)
    {
        delete Logic_state;
    }
    Logic_state = new Specification(this,Logic_state_explain, ui->UI_Debug_Tab, 4, 5, \
                                   "0", tr("Logic state"), str);
    Logic_state->add_Specification();

    if(INV_flag != nullptr)
    {
        delete INV_flag;
    }
    INV_flag = new Specification(this,INV_flag_explain, ui->UI_Debug_Tab, 5, 5, \
                                   "0", tr("INV flag"), str);
    INV_flag->add_Specification();

    if(Grid_flag != nullptr)
    {
        delete Grid_flag;
    }
    Grid_flag = new Specification(this,Grid_flag_explain, ui->UI_Debug_Tab, 6, 5, \
                                   "0", tr("Grid flag"), str);
    Grid_flag->add_Specification();

    if(Grid_protect_flag != nullptr)
    {
        delete Grid_protect_flag;
    }
    Grid_protect_flag = new Specification(this,Grid_protect_flag_explain, ui->UI_Debug_Tab, 7, 5, \
                                   "0", tr("Grid protect flag"), str);
    Grid_protect_flag->add_Specification();

    if(Bat_flag != nullptr)
    {
        delete Bat_flag;
    }
    Bat_flag = new Specification(this,Bat_flag_explain, ui->UI_Debug_Tab, 8, 5, \
                                   "0", tr("Bat flag"), str);
    Bat_flag->add_Specification();

    if(DC_bus_flag != nullptr)
    {
        delete DC_bus_flag;
    }
    DC_bus_flag = new Specification(this,DC_bus_flag_explain, ui->UI_Debug_Tab, 9, 5, \
                                   "0", tr("DC bus flag"), str);
    DC_bus_flag->add_Specification();

    if(INT_main_flag != nullptr)
    {
        delete INT_main_flag;
    }
    INT_main_flag = new Specification(this,INT_main_flag_explain, ui->UI_Debug_Tab, 10, 5, \
                                   "0", tr("INT main flag"), str);
    INT_main_flag->add_Specification();

    if(parallel_signal != nullptr)
    {
        delete parallel_signal;
    }
    parallel_signal = new Specification(this,parallel_signal_explain, ui->UI_Debug_Tab, 11, 5, \
                                   "0", tr("parallel signal"), str);
    parallel_signal->add_Specification();
}

/***************************************************************
 * 选择静态IP地址
 ***************************************************************/
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

/***************************************************************
 * 选择自动分配IP地址
 ***************************************************************/
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

/***************************************************************
 * 主页 当前变流器状态 点击
 ***************************************************************/
void MEGAWin::on_Converter_State_btn_clicked()
{
    QMessageBox::question(this, tr("Converter State"), tr("Display the current status of the DCAC converter."), tr("OK"));
}

/***************************************************************
 * 主页 当前模式 点击
 ***************************************************************/
void MEGAWin::on_Current_Mode_btn_clicked()
{
    QMessageBox::question(this ,tr("Current Mode"), tr("Display the current control power mode."), tr("OK"));
}

/***************************************************************
 * 调入测试数据
 ***************************************************************/
void MEGAWin::on_radio_test_data_btn_clicked()
{
    QMessageBox::question(this ,tr("test data"), tr("Call in test data (for internal testing personnel only)."), tr("OK"));
}

/***************************************************************
 * 修改时间
 ***************************************************************/
void MEGAWin::on_TimeSeting_btn_clicked()
{
    QMessageBox::question(this ,tr("Time"), tr("Click here to modify the time displayed on the HMI."), tr("OK"));
}

/***************************************************************
 * 切换语言
 ***************************************************************/
void MEGAWin::on_ChangeLanguage_btn_clicked()
{
    Change_Language();
}

/***************************************************************
 * 高级设置切换语言
 ***************************************************************/
void MEGAWin::on_ChangeLanguage_btn_1_clicked()
{
    Change_Language();
}

/***************************************************************
 * 故障信息表搜索功能
 ***************************************************************/
void MEGAWin::on_search_btn_clicked()
{
    if(FaultTable->isHidden())
    {
        FaultTable->show();
    }
    else
    {
        FaultTable->hide();
    }
//    QString search = ui->search_le->text();
//    int row=ui->RTAlarm_Data_page->rowCount();

//    if (search == "")   //判断搜索框是否是空，如果是空就显示所有行
//    {
//        for(int i=0; i<row; i++)
//        {
//            ui->RTAlarm_Data_page->setRowHidden(i,false);
//        }
//    }
//    else
//    {
//        //通过你输入的和表格里面所有内容进行比对，找到符合条件的索引
//        QList <QTableWidgetItem *> item = ui->RTAlarm_Data_page->findItems(ui->search_le->text(), Qt::MatchContains);

//        for(int i=0; i<row; i++)
//        {
//            ui->RTAlarm_Data_page->setRowHidden(i,true);//然后把所有行都隐藏
//        }

//        if(!item.empty())   //判断符合条件索引是不是空
//        {
//            //恢复对应的行
//            for(int i=0; i<item.count(); i++)
//            {
//                ui->RTAlarm_Data_page->setRowHidden(item.at(i)->row(),false);//恢复对应的行
//            }
//        }
//    }
}

/***************************************************************
 * 升级工具点击槽
 ***************************************************************/
void MEGAWin::UpgradeInterface_clicked()
{
    int reply = QMessageBox::question(this, tr("Upgrade prompt")\
                          ,tr("Make sure to press the EPO button before upgrading."), tr("Return"),tr("OK"));
    if (reply == 0)
    {
        // 点击了"Cancel"按钮的处理逻辑
        return ;

    } else if (reply == 1) {
        // 点击了"OK"按钮的处理逻辑
        if(UpgradeInterface->isHidden())
        {
            UpgradeInterface->show();
        }
        else
        {
            UpgradeInterface->hide();
        }
    }
}

void MEGAWin::WorkingMode_clicked()
{
    int reply = QMessageBox::question(this, tr("Working mode")\
                          ,tr("When selecting the manual mode, the converter’s operating status, charging or discharging power (active power), reactive power, power factor etc,can be controlled through HMI or EMS.\
                              When selecting the UPS mode, When the grid side is abnormal, the system will switch from zero power to grid-off discharge mode to provide energy to critical loads. Please go to the \"Battery Settings\" page to configure this mode. Note: This mode is only applicable to lithium battery mode and requires normal communication between the converter and BMS.\
                              Peak shaving and valley filling mode is used for peak-valley price arbitrage. The converter can operate according to the local peak-valley electricity price periods. Please set the operating time period, charging or discharging mode, charging or discharging power, and other information on the \"Mixed mode\" page.\nGrid expansion."),\
                                      tr("Click to view grid expansion"),tr("OK"));
    if (reply == 0)
    {
        // 点击了"Grid expansion"按钮的处理逻辑,进入新界面  点击查看电网扩容
        if(GridExpansionInterface->isHidden())
        {
            GridExpansionInterface->show();
        }
        else
        {
            GridExpansionInterface->hide();
        }
        return ;

    } else if (reply == 1) {
        // 点击了"OK"按钮的处理逻辑

    }
}

//从excel快速读取至tabel表
void MEGAWin::excel_read(QTableWidget *tablewidget)
{
//    QFile file("../test.txt");
//    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
//    {
//        QTextStream f_put(&file);
//        f_put.setCodec("UTF-8");

//        int row = 0;
//        tablewidget->setColumnCount(5);

//        while (!f_put.atEnd())
//        {
//            QStringList word;
//            for (int i = 0; i < 6; ++i)
//            {
//                QString entire = f_put.readLine().trimmed();
//                if(i==5)
//                {

//                }
//                else
//                {
//                    word << entire;
//                }
//            }

//            if (word.size() == 5)
//            {
//                tablewidget->insertRow(row);
//                for (int i = 0; i < 5; ++i)
//                {
//                    QTableWidgetItem* item = new QTableWidgetItem(word[i]);
//                    tablewidget->setItem(row, i, item);
//                }
//                tablewidget->setRowHeight(row, 100);
//                ++row;
//            }
//        }

//        tablewidget->setRowCount(row);
//        file.close();
//    }
}
