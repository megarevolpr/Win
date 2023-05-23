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

#define NULL_page   0
#define Machine_MEGA 1
#define Machine_MEGA_T 2
#define Machine_MEGA_TS 3
#define Machine_MEGA_TS_T 4

#define Analoge_PAGE  0
#define State_PAGE    1
#define Alarm_PAGE    2
#define BAT_PAGE      3

MEGAWin::MEGAWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MEGAWin)
{
    ASKey = true;
    ui->setupUi(this);
    ui->UI_stackedWidget->setCurrentWidget(ui->UI_page );//开机后进入主页面
    ui->stackedWidget->setCurrentWidget(ui->Bypass_page);
    ui->RTD_PCS_StackedWidget->setCurrentWidget(ui->RTD_Bypass_Y_page);
    ui->RTState_stackedWidget->setCurrentWidget(ui->RTState_Bypass_Y_page);

    MemoryAllocation(); //初始化内存空间
    VariableInit();     //变量初始化
    UIPageInit();       //初始化界面

    m_menu = new Menu(this);
    connect(m_menu, SIGNAL(Sent(int)), this, SLOT(My_menuAction(int)));

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
    /*******************************系统设置************************************/
//    combox_ui_ChargeDischar =   new QComboBox();        //充放电设置
//    combox_ui_ChargeDischar->setView(new QListView());

//    combox_RUN  =   new QComboBox();                    //运行模式
//    combox_RUN->setView(new QListView());

//    combox_ControlMode  =   new QComboBox();            //控制模式
//    combox_ControlMode->setView(new QListView());       //控制模式列表

//    combox_ui_OnOff_Grid =   new QComboBox();           //并离网设置
//    combox_ui_OnOff_Grid->setView(new QListView());     //并离网列表设置

//    combox_MachineNumber = new QComboBox();             //设备号
//    combox_MachineNumber->setView(new QListView());

//    combox_Parallel = new QComboBox();                  //并机
//    combox_Parallel->setView(new QListView());

//    combox_UnbalancePowerEnable = new QComboBox();      //功率不平衡使能
//    combox_UnbalancePowerEnable->setView(new QListView());




//    Grid_CM_of_PCS_explain          = new QPushButton;
//    Constant_power_explain          = new QPushButton; //恒功率
//    Charg_and_Discharg_explain      = new QPushButton;
//    Work_mode_explain               = new QPushButton;
//    Output_power_factor_explain     = new QPushButton;
//    Output_reactive_power_explain   = new QPushButton;
//    Constant_current_explain        = new QPushButton;
//    Constant_voltage_explain        = new QPushButton;
//    Control_mode_explain            = new QPushButton;
//    Machine_number_explain          = new QPushButton;
//    Parallel_explain                = new QPushButton;
//    Unbalance_power_enable_explain  = new QPushButton;
//    Phase_A_power_explain           = new QPushButton;
//    Phase_B_power_explain           = new QPushButton;  //B相功率说明
//    Phase_C_power_explain           = new QPushButton;
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
    pButton_Version->addButton(ui->pushButton,4);
    pButton_Version->addButton(ui->pushButton_22,5);
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
    Sleep_mode_explain          = new QPushButton;//睡眠模式
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
    pButton_BatteryData->addButton(ui->pushButton_18,17);
    pButton_BatteryData->addButton(ui->pushButton_19,18);
    pButton_BatteryData->addButton(ui->pushButton_20,19);
    pButton_BatteryData->addButton(ui->pushButton_21,20);


}
/***************************************************************
 * @brief HOSTPAGE init
 * #attribute   Fuction
 * @param non       @see  non
 * @param Non         @see Non
 *
 * @return Non
 *     -<em>false</em> fail
 *     -<em>true</em> succeed
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
 * #attribute   Fuction
 * @param non       @see  non
 * @param Non         @see Non
 *
 * @return Non
 *     -<em>false</em> fail
 *     -<em>true</em> succeed
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

void MEGAWin::LCDSetting()  //LCD标签初始化和定时器设置
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

//    //并离网
//    combox_ui_OnOff_Grid->setStyleSheet("QComboBox QAbstractItemView::item{height: 30}");
//    combox_ui_OnOff_Grid->addItems(ui_OnOff_Grid);
////    combox_ui_OnOff_Grid->setCurrentIndex(ui_sysDspSetData.u16OnOffGrid - 1);
//    combox_ui_OnOffGrid_str = combox_ui_OnOff_Grid->currentText();
//    combox_ui_OnOffGrid_index = combox_ui_OnOff_Grid->currentIndex();

//    //充放电
//    combox_ui_ChargeDischar->setStyleSheet("QComboBox QAbstractItemView::item{height: 30}");
//    combox_ui_ChargeDischar->addItems(ui_ChargeDischar);
////    combox_ui_ChargeDischar->setCurrentIndex(ui_sysDspSetData.u16ChargeOrDischarge - 1);
//    combox_ui_ChargeDischar_str = combox_ui_ChargeDischar->currentText();
//    combox_ui_ChargeDischar_index = combox_ui_ChargeDischar->currentIndex();

//    //运行方式
//    combox_RUN->setStyleSheet("QComboBox QAbstractItemView::item{height: 30}");
//    combox_RUN->addItems(combox_Runmode);
////    combox_RUN->setCurrentIndex(ui_sysDspSetData.u16RunMod);//默认手动控制
//    combox_RUN_str = combox_RUN->currentText();
//    combox_RUN_index = combox_RUN->currentIndex();

//    //控制模式
//    combox_ControlMode->setStyleSheet("QComboBox QAbstractItemView::item{height: 30}");
//    combox_ControlMode->addItems(combox_CM);
////    combox_ControlMode->setCurrentIndex(ui_sysMonSetData.u16ControlMode);
//    combox_ControlMode_str = combox_ControlMode->currentText();
//    combox_ControlMode_index = combox_ControlMode->currentIndex();

//    combox_MachineNumber->setStyleSheet("QComboBox QAbstractItemView::item{height: 30}");
//    combox_MachineNumber->addItems(combox_MNumber);
////    combox_MachineNumber->setCurrentIndex(ui_sysDspSetData.u16MachineNumber);
//    MachineNumber_str = combox_MachineNumber->currentText();
//    combox_MachineNumber_index = combox_MachineNumber->currentIndex();

//    combox_Parallel->setStyleSheet("QComboBox QAbstractItemView::item{height: 30}");
//    combox_Parallel->addItems(combox_Para);
////    combox_Parallel->setCurrentIndex(ui_sysDspSetData.u16EnableParallel);
//    combox_Parallel_str = combox_Parallel->currentText();
//    combox_Parallel_index = combox_Parallel->currentIndex();

//    combox_UnbalancePowerEnable->setStyleSheet("QComboBox QAbstractItemView::item{height: 30}");
//    combox_UnbalancePowerEnable->addItems(combox_Para);
////    combox_UnbalancePowerEnable->setCurrentIndex(ui_sysDspSetData.u16UnbalancePowerEnable);
//    combox_UnbalancePowerEnable_str = combox_UnbalancePowerEnable->currentText();
//    combox_UnbalancePowerEnable_index = combox_UnbalancePowerEnable->currentIndex();


//    Phase_C_power_btn->setText(tr("5"));

//    Constant_power_explain->setText(tr("0"));


//    ui->System_Tab->setCellWidget(0,1, (QWidget *)combox_ui_OnOff_Grid);        //并离网
//    ui->System_Tab->setCellWidget(2,1, (QWidget *)combox_ui_ChargeDischar);     //充放电设置
//    ui->System_Tab->setCellWidget(3,1, (QWidget *)combox_RUN);                  //运行模式

//    ui->System_Tab->setCellWidget(0,4, (QWidget *)combox_ControlMode);          //控制模式
//    ui->System_Tab->setCellWidget(1,4, (QWidget *)combox_MachineNumber);        //设备号
//    ui->System_Tab->setCellWidget(2,4, (QWidget *)combox_Parallel);             //并机
//    ui->System_Tab->setCellWidget(3,4, (QWidget *)combox_UnbalancePowerEnable); //功率不平衡使能

    AdvancedSetup_btn->setText(tr("Advance setting"));
    ui->System_Tab->setCellWidget(7,4, (QWidget *)AdvancedSetup_btn);          //高级设置


//    Grid_CM_of_PCS = new Specification(Grid_CM_of_PCS_explain, ui->System_Tab, 0, 1, "5", "Phase_B_power", "This is Phase_B_power");
//    Grid_CM_of_PCS->add_Specifition();
//    Constant_power = new Specification(Constant_power_explain, ui->System_Tab, 1, 1, "5", "Phase_B_power", "This is Phase_B_power");
//    Constant_power->add_Specifition();
//    Charg_and_Discharg = new Specification(Charg_and_Discharg_explain, ui->System_Tab, 2, 1, "5", "Phase_B_power", "This is Phase_B_power");
//    Charg_and_Discharg->add_Specifition();
//    Work_mode = new Specification(Work_mode_explain, ui->System_Tab, 3, 1, "5", "Phase_B_power", "This is Phase_B_power");
//    Work_mode->add_Specifition();
//    Output_power_factor = new Specification(Output_power_factor_explain, ui->System_Tab, 4, 1, "5", "Phase_B_power", "This is Phase_B_power");
//    Output_power_factor->add_Specifition();
//    Output_reactive_power = new Specification(Output_reactive_power_explain, ui->System_Tab, 5, 1, "5", "Phase_B_power", "This is Phase_B_power");
//    Output_reactive_power->add_Specifition();
//    Constant_current = new Specification(Constant_current_explain, ui->System_Tab, 6, 1, "5", "Phase_B_power", "This is Phase_B_power");
//    Constant_current->add_Specifition();
//    Constant_voltage = new Specification(Constant_voltage_explain, ui->System_Tab, 7, 1, "5", "Phase_B_power", "This is Phase_B_power");
//    Constant_voltage->add_Specifition();
//    Control_mode = new Specification(Control_mode_explain, ui->System_Tab, 0, 4, "5", "Phase_B_power", "This is Phase_B_power");
//    Control_mode->add_Specifition();
//    Machine_number = new Specification(Machine_number_explain, ui->System_Tab, 1, 4, "5", "Phase_B_power", "This is Phase_B_power");
//    Machine_number->add_Specifition();
//    Parallel = new Specification(Parallel_explain, ui->System_Tab, 2, 4, "5", "Phase_B_power", "This is Phase_B_power");
//    Parallel->add_Specifition();
//    Unbalance_power_enable = new Specification(Unbalance_power_enable_explain, ui->System_Tab, 3, 4, "5", "Phase_B_power", "This is Phase_B_power");
//    Unbalance_power_enable->add_Specifition();
//    Phase_A_power = new Specification(Phase_A_power_explain, ui->System_Tab, 4, 4, "5", "Phase_B_power", "This is Phase_B_power");
//    Phase_A_power->add_Specifition();
//    Phase_B_power = new Specification(Phase_B_power_explain, ui->System_Tab, 5, 4, "5", "Phase_B_power", "This is Phase_B_power");
//    Phase_B_power->add_Specifition();
//    Phase_C_power = new Specification(Phase_C_power_explain, ui->System_Tab, 6, 4, "5", "Phase_B_power", "This is Phase_B_power");
//    Phase_C_power->add_Specifition();

    ParameterSet();//系统设置 绘制button

}

void MEGAWin::History_tab()//历史记录设置表初始化
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

void MEGAWin::Information_tbnt_released()//系统信息槽
{
//    ui->EquipmentInfor_tableWidget->clearContents();
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

//    QStringList Display_Par4;
//    Display_Par4 << tr("Manufacturer name") << tr("Monitoring software version") << tr("Protocol version") << tr("Converter software version")
//                << tr("CPLD software version") << tr("SN:");//<< tr("Converter type")
//    for(int i = 0; i < Display_Par4.size(); i++)
//    {
//        ui->EquipmentInfor_tableWidget->setItem(i, 0, new QTableWidgetItem(QString(Display_Par4.at(i))));
//    }



//    QString STR_PRO;
//    QString STR_DSP;
//    QString STR_CPLD;
//    QString SNCODE;
//    ui->EquipmentInfor_tableWidget->setItem(0, 1, new QTableWidgetItem(QString(tr("PCS"))));
//    ui->EquipmentInfor_tableWidget->item(0, 1)->setTextAlignment(Qt::AlignCenter);
//    ui->EquipmentInfor_tableWidget->setItem(1, 1, new QTableWidgetItem("V103B500D004"));
//    ui->EquipmentInfor_tableWidget->item(1, 1)->setTextAlignment(Qt::AlignCenter);
//    ui->EquipmentInfor_tableWidget->setItem(2, 1, new QTableWidgetItem(STR_PRO));
//    ui->EquipmentInfor_tableWidget->item(2, 1)->setTextAlignment(Qt::AlignCenter);
//    ui->EquipmentInfor_tableWidget->setItem(3, 1, new QTableWidgetItem(STR_DSP));
//    ui->EquipmentInfor_tableWidget->item(3, 1)->setTextAlignment(Qt::AlignCenter);
//    ui->EquipmentInfor_tableWidget->setItem(4, 1, new QTableWidgetItem(STR_CPLD));
//    ui->EquipmentInfor_tableWidget->item(4, 1)->setTextAlignment(Qt::AlignCenter);
//    ui->EquipmentInfor_tableWidget->setItem(5, 1, new QTableWidgetItem(SNCODE));
//    ui->EquipmentInfor_tableWidget->item(5, 1)->setTextAlignment(Qt::AlignCenter);



}

//void MEGAWin::GeneralParam_tbnt_released()  //一般参数槽
//{

//}
/*************************************************************************
 * PCS故障信息表
 ************************************************************************/
void MEGAWin::PCS_Alarm_information_table()
{
    ui->RTAlarm_Data_page->setRowHeight(0, 110);
    QStringList RTAlarm_List;
    RTAlarm_List << tr("逆变器过流\nInverter overcurrent") << tr("一般故障\nGeneral failure") \
                << tr("电感电流瞬时值>3Ip\n或电感电流有效值>1.36In\nInductive current instantaneous value >3lp or inductive current RMS value >1.36ln") \
                << tr("PCS 停机，输出接触器断开\nPCS shut down and disconnect the output contactor") \
                << tr("可恢复，故障消除5min后自动恢复\nRecoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(0, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(0, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(1, 130);
    RTAlarm_List.clear();
    RTAlarm_List << tr("变流器故障\nConverter fault") << tr("一般故障\nGeneral failure")\
                << tr("变流器开机软启过程中，30s后逆变电压有效值>1.2Vgrid或逆变电压有效值<0.3Vgrid\nDuring soft startup of converter, inverter voltage RMS more then 1.2Vgrid or inverter voltage RMS less than 0.3Vgrid after 30s") \
                << tr("PCS 停机，停止开机软启\nPCS shut down and Stop the soft startup") \
                << tr("可恢复，故障消除5min后自动恢复\nRecoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(1, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(1, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(2, 110);
    RTAlarm_List.clear();
    RTAlarm_List << tr("电池电压低\nBattery low voltage") << tr("告警\nWarning") \
                << tr("直流出入电压低于电池EOD电压或者小于1.414倍电网线电压\nThe DC input/output voltage is lower than the battery EOD voltage or less than 1.414 times the grid line voltage") \
                << tr("PCS 停机，交流接触器断开\nPCS shut down and the AC contactor is disconnected") \
                << tr("可恢复，故障消除5min后自动恢复\nRecoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(2, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(2, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(3, 200);
    RTAlarm_List.clear();
    RTAlarm_List << tr("电池功率低\nLow battery power") << tr("告警\nWarning") \
                << tr("电池电压低于电池EOD电压值(适用无BMS电池系统，防止电压回升)\nThe battery voltage is lower than the EOD voltage value (applicable to BMS free battery systems to prevent voltage rebound)") \
                << tr("处于放电状态时PCS停机(充电过程不受影响)，交流接触器断开\nWhen the PCS is in discharge state, the machine stops (the charging process is not affected) and the AC contactor is disconnected") \
                << tr("可恢复，PCS充电时间大于5min后，告警消除\nRecoverable, The alarm is cleared when the charging time of PCS is longer than 5 minutes");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(3, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(3, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(4, 130);
    RTAlarm_List.clear();
    RTAlarm_List << tr("直流母线过压\nDc bus overvoltage") << tr("严重故障\nSerious failure") \
                << tr("直流输入电压>850V\nDc input voltage more then 850V") \
                << tr("PCS 停机，交流接触器断开，直流断路器脱扣\nPCS shut down, the AC contactor is disconnected, and the DC circuit breaker is tripped") \
                << tr("不可恢复\nUnrecoverable");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(4, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(4, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(5, 130);
    RTAlarm_List.clear();
    RTAlarm_List << tr("直流母线短路\nDc bus short circuit") << tr("严重故障\nSerious failure") \
                << tr("直流母线电压低于200V，直流电流大于50A，判断时间为200us\nThe DC bus voltage is less than 200V, the DC current is more than 50A, and the judgment time is 200us") \
                << tr("PCS 停机，交流接触器断开，直流断路器脱扣\nPCS shut down, the AC contactor is disconnected, and the DC circuit breaker is tripped") \
                << tr("不可恢复\nUnrecoverable");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(5, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(5, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(6, 110);
    RTAlarm_List.clear();
    RTAlarm_List << tr("输出接触器开路\nThe output contactor is open") << tr("一般故障\nGeneral failure")\
                << tr("PCS运行状态下，交流接触器的辅助触点信号为断开状态\nWhen PCS is running, the auxiliary contact signal of AC contactor is in the disconnected state") \
                << tr("PCS 停机，交流接触器断开\nPCS shut down and the AC contactor is disconnected") \
                << tr("可恢复，故障消除5min后自动恢复\nRecoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(6, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(6, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(7, 110);
    RTAlarm_List.clear();
    RTAlarm_List << tr("输出接触器短路\nOutput contactor short circuit") << tr("一般故障\nGeneral failure")\
                << tr("PCS停机状态下，交流接触器的辅助触点信号为闭合状态\nWhen PCS is shut down, the auxiliary contact signal of AC contactor is closed") \
                << tr("PCS 停机，交流接触器断开\nPCS shut down and the AC contactor is disconnected") \
                << tr("可恢复，故障消除5min后自动恢复\nRecoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(7, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(7, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(8, 310);
    RTAlarm_List.clear();
    RTAlarm_List << tr("变流器过温\nThe converter is overheated") << tr("告警\nWarning") \
                << tr("IGBT温度超过105℃或电抗器温度超过160℃\nIGBT temperature exceeds 105℃ or reactor temperature exceeds 160℃") \
                << tr("IGBT过温：降额运行(并网)；IGBT过温：PCS停机(离网)，交流接触器断开；电抗器过温：PCS 停机，交流接触器断开\nIGBT overtemperature: derating operation (grid-connected); IGBT overtemperature: PCS shut down (off-grid), AC contactor is disconnected; Reactor overtemperature: PCS shut down and AC contactor is disconnected") \
                << tr("可恢复，故障消除5min后自动恢复\nRecoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(8, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(8, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(9, 90);
    RTAlarm_List.clear();
    RTAlarm_List << tr("输出过载\nOutput over load") << tr("告警\nWarning") \
                << tr("离网负载功率>110%Pn\nOff-grid load power >110%Pn") \
                << tr("PCS 停机，交流接触器断开\nPCS shut down and the AC contactor is disconnected") \
                << tr("可恢复，故障消除5min后自动恢复\nRecoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(9, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(9, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(10, 170);
    RTAlarm_List.clear();
    RTAlarm_List << tr("电池接反故障\nThe positive and negative terminals of the battery are connected inversely fault") << tr("告警\nWarning") \
                << tr("直流输入正负极性接反\nThe DC input is reversed") \
                << tr("PCS 停机，交流接触器断开\nPCS shut down and the AC contactor is disconnected") \
                << tr("不可恢复\nUnrecoverable");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(10, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(10, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(11, 170);
    RTAlarm_List.clear();
    RTAlarm_List << tr("DC接触器故障\nThe DC contactor is faulty") << tr("一般故障\nGeneral failure") \
                << tr("驱动信号为闭合信号条件下，电池和母线之间的压测>50V；驱动信号为断开条件下，辅助触点信号为闭合状态\nWhen the driving signal is a closed signal, the pressure difference between the battery and the bus is greater than 50V;When the driving signal is off, the auxiliary contact signal is closed") \
                << tr("PCS 停机，交流接触器断开\nPCS shut down and the AC contactor is disconnected") \
                << tr("可恢复，故障消除5min后自动恢复\nRecoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(11, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(11, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(12, 90);
    RTAlarm_List.clear();
    RTAlarm_List << tr("EMS通信故障\nEMS communicate\nfault") << tr("一般故障\nGeneral failure") \
                << tr("PCS与EMS通信丢失，判断时间3min\nThe communication between PCS and EMS is lost, and the judgment time is 3 minutes") \
                << tr("PCS 停机，交流接触器断开\nPCS shut down and the AC contactor is disconnected") \
                << tr("可恢复，故障消除后30s自动恢复\nRecoverable, the fault recovers automatically 30 seconds after it is rectified");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(12, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(12, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(13, 90);
    RTAlarm_List.clear();
    RTAlarm_List << tr("BMS通信故障\nBMS communicate\nfault") << tr("一般故障\nGeneral failure") \
                << tr("PCS与BMS通信丢失，判断时间50s\nCommunication loss between PCS and BMS, judgment time 50s") \
                << tr("PCS 停机，交流接触器断开\nPCS shut down and the AC contactor is disconnected") \
                << tr("可恢复，故障消除后30s自动恢复\nRecoverable, the fault recovers automatically 30 seconds after it is rectified");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(13, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(13, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(14, 130);
    RTAlarm_List.clear();
    RTAlarm_List << tr("变流器缺相故障\nConverter phase loss fault") << tr("一般故障\nGeneral failure") \
                << tr("并网功率大于50%条件下，三相电路出现一项或多项线路无输出功率，判断时间为10s\nWhen the grid-connected power is greater than 50%, one or more lines of the three-phase circuit have no output power, and the judgment time is 10s") \
                << tr("PCS 停机，交流接触器断开\nPCS shut down and the AC contactor is disconnected") \
                << tr("可恢复，故障消除5min后自动恢复\nRecoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(14, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(14, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(15, 110);
    RTAlarm_List.clear();
    RTAlarm_List << tr("电网过压\nGrid overvoltage") << tr("告警\nWarning") \
                << tr("电网电压超过最大允许电压(90%~70%可设定),判断时间1s\nIf the power grid voltage exceeds the maximum allowable voltage (90% to 70% can be set), the judgment time is 1s") \
                << tr("PCS 停机，交流接触器断开\nPCS shut down and the AC contactor is disconnected") \
                << tr("可恢复，故障消除5min后自动恢复\nRecoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(15, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(15, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(16, 110);
    RTAlarm_List.clear();
    RTAlarm_List << tr("电网欠压\nGrid undervoltage") << tr("告警\nWarning") \
                << tr("电网电压超过最大允许电压(90%~70%可设定),判断时间1s\nIf the power grid voltage exceeds the maximum allowable voltage (90% to 70% can be set), the judgment time is 1s") \
                << tr("PCS 停机，交流接触器断开\nPCS shut down and the AC contactor is disconnected") \
                << tr("可恢复，故障消除5min后自动恢复\nRecoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(16, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(16, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(17, 150);
    RTAlarm_List.clear();
    RTAlarm_List << tr("电网反序\nGrid reverse sequence") << tr("告警\nWarning") \
                << tr("三相相序接反(电网电压正序模值小于负序模值)，判断时间为1s\nThe three-phase phase sequence is reversed (the positive sequence mode value of the grid voltage is less than the negative sequence mode value), and the judgment time is 1s") \
                << tr("PCS 停机，交流接触器断开\nPCS shut down and the AC contactor is disconnected") \
                << tr("不可恢复\nUnrecoverable");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(17, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(17, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(18, 150);
    RTAlarm_List.clear();
    RTAlarm_List << tr("电网频率异常\nGrid frequency anomaly") << tr("告警\nWarning") \
                << tr("电网频率超出PCS允许范围内(±2Hz可设定)\nGrid frequency frequency beyond the allowable range of PCS (±2Hz can be set)") \
                << tr("PCS 停机，交流接触器断开\nPCS shut down and the AC contactor is disconnected") \
                << tr("可恢复，故障消除5min后自动恢复\nRecoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(18, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(18, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(19, 150);
    RTAlarm_List.clear();
    RTAlarm_List << tr("变流器孤岛保护\nConverter shutter island protection") << tr("告警\nWarning") \
                << tr("主动孤岛保护模式下电网失电，且负载和逆变器并网功率和相角相匹配\nInitiative shutter island protection mode, the power grid loses power, and the load matches the grid-connected power and phase Angle of the inverter") \
                << tr("PCS 停机，交流接触器断开\nPCS shut down and the AC contactor is disconnected") \
                << tr("可恢复，故障消除5min后自动恢复\nRecoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(19, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(19, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(20, 150);
    RTAlarm_List.clear();
    RTAlarm_List << tr("驱动线故障\nDrive line fault") << tr("一般故障\nGeneral failure") \
                << tr("驱动线端口松动\nThe driver cable port is loose") \
                << tr("PCS 停机，交流接触器断开\nPCS shut down and the AC contactor is disconnected") \
                << tr("可恢复，故障消除5min后自动恢复\nRecoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(20, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(20, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(21, 150);
    RTAlarm_List.clear();
    RTAlarm_List << tr("防雷故障\nLightning protection fault") << tr("告警\nWarning") \
                << tr("防雷器击穿或漏电\nSurge arrester breakdown or leakage") \
                << tr("PCS 停机，交流接触器断开\nPCS shut down and the AC contactor is disconnected") \
                << tr("不可恢复\nUnrecoverable");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(21, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(21, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(22, 150);
    RTAlarm_List.clear();
    RTAlarm_List << tr("绝缘阻抗异常\nDrive line fault") << tr("告警\nWarning") \
                << tr("直流侧正负母线对地电压异常（小于50V）\nAbnormal voltage of positive and negative bus to ground in DC side (less than 50V)") \
                << tr("PCS 停机，交流接触器断开\nPCS shut down and the AC contactor is disconnected") \
                << tr("可恢复，故障消除5min后自动恢复\nRecoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(22, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(22, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(23, 150);
    RTAlarm_List.clear();
    RTAlarm_List << tr("交流辅助电源故障\nThe AC auxiliary power supply is faulty") << tr("一般故障\nGeneral failure") \
                << tr("交流辅助电源输出出现异常\nThe AC auxiliary power output is abnormal. Procedure") \
                << tr("PCS 停机，交流接触器断开\nPCS shut down and the AC contactor is disconnected") \
                << tr("可恢复，故障消除5min后自动恢复\nRecoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(23, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(23, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(24, 150);
    RTAlarm_List.clear();
    RTAlarm_List << tr("直流辅助电源故障\nThe DC auxiliary power supply is faulty") << tr("一般故障\nGeneral failure") \
                << tr("直流辅助电源输出出现异常\nThe DC auxiliary power output is abnormal. Procedure") \
                << tr("PCS 停机，交流接触器断开\nPCS shut down and the AC contactor is disconnected") \
                << tr("可恢复，故障消除5min后自动恢复\nRecoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(24, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(24, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(25, 150);
    RTAlarm_List.clear();
    RTAlarm_List << tr("风扇故障\nFan failure") << tr("告警\nWarning") \
                << tr("风扇无法启动运行\nThe fan cannot be started") \
                << tr("PCS 降额运行\nPCS derating operation") \
                << tr("可恢复，故障消除5min后自动恢复\nRecoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(25, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(25, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(26, 150);
    RTAlarm_List.clear();
    RTAlarm_List << tr("紧急关机\nEmergency shutdown") << tr("告警\nWarning") \
                << tr("在变流器控制面板上按下EPO按钮\nPress the EPO button on the converter control panel") \
                << tr("PCS 停机，交流接触器断开\nPCS shut down and the AC contactor is disconnected") \
                << tr("可恢复，故障消除5min后自动恢复\nRecoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(26, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(26, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(27, 150);
    RTAlarm_List.clear();
    RTAlarm_List << tr("CT或霍尔开路故障\nCT or Hall open circuit fault") << tr("一般故障\nGeneral failure") \
                << tr("PCS并网功率大于50%运行时，CT检测电流小于给定量的70%\nWhen PCS grid-connected power is greater than 50%, CT detection current is less than 70% of the given quantity") \
                << tr("PCS 停机，交流接触器断开\nPCS shut down and the AC contactor is disconnected") \
                << tr("可恢复，故障消除5min后自动恢复\nRecoverable, automatic recovery 5 minutes after the fault is eliminated");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(27, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(27, i)->setTextAlignment(Qt::AlignCenter);
    }

    ui->RTAlarm_Data_page->setRowHeight(28, 150);
    RTAlarm_List.clear();
    RTAlarm_List << tr("绝缘阻抗异常\nAbnormal insulation impedance") << tr("严重故障\nSerious failure") \
                << tr("对于1000V系统，正对地或负对地阻抗小于33K欧姆\nFor 1000V systems, the positive or negative ground impedance is less than 33KΩ") \
                << tr("PCS 停机，交流接触器断开\nPCS shut down and the AC contactor is disconnected") \
                << tr("不可恢复\nUnrecoverable");
    for(int i = 0; i < RTAlarm_List.size(); i++)
    {
        ui->RTAlarm_Data_page->setItem(28, i, new QTableWidgetItem(RTAlarm_List.at(i)));
        ui->RTAlarm_Data_page->item(28, i)->setTextAlignment(Qt::AlignCenter);
    }
}
/**************************************************
初始化变量（system_Page）
**************************************************/
void MEGAWin::VariableInit()
{

}

void MEGAWin::combox_ui_GridMode_change()//逆变器并网方式
{

}

void MEGAWin::combox_ui_OnOff_Grid_change()//并离网
{

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
        QStringList Converter_Tablist2;//<< tr("Inductunce temperature") << tr("Diode temperature")
        Converter_Tablist2  << tr("Battery voltage") << tr("Battery current") << tr("Battery power")
                            << tr("Bus voltage") << tr("IGBT temperature")
                            << tr("Environment temperature") << tr("-")<< tr("-");

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
        ui->Converter_Tab->setColumnWidth(1,100);
        ui->Converter_Tab->setColumnWidth(2,200);
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
        }
        for(int i = 0; i < Converter_Tablist2.size(); i++)
        {
            ui->Converter_Tab->setItem(i, 2, new QTableWidgetItem(Converter_Tablist2.at(i)));
        }

        ui->Grid_Tab->setPalette(pal);
        ui->Grid_Tab->setAlternatingRowColors(true);
        QStringList Grid_TabList;
        Grid_TabList << tr("Name") << tr("Value");
        ui->Grid_Tab->setHorizontalHeaderLabels(Grid_TabList);
        ui->Grid_Tab->setColumnWidth(0,300);
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
        ui->Load_Tab->setColumnWidth(0,300);
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
                    << tr("Output contactor") << tr("Output breaker") << tr("Grid contactor") << tr("Grid breaker") << tr("Maintenance Bypass breaker");
#endif
        QStringList RTState_Bypass_List2;
         RTState_Bypass_List2 << tr("converter available") << tr("DC Soft start")\
                    << tr("converter status") << tr("Reactive power Regulation")\
                    << tr("Sleep mode") << tr("LVRT");
         QStringList RTState_Bypass_List4;
          RTState_Bypass_List4 << tr("Generator signal") << tr("Reserve")\
                               << tr("Reserve") << tr("EPO contact signal 1")\
                               << tr("EPO contact signal 2") << tr("Access control signal")<< tr("Full power signal") << tr("Smoke alarm signal")<< tr("Hight temp. signal");

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
//        ui->Run_tabWidget->setCurrentIndex(0);
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
/***********************************关联槽函数*****************************************/

void MEGAWin::on_UI_MenuBtn_clicked()
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

void MEGAWin::on_UI_Complete_Btn_clicked()
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

void MEGAWin::on_Grid_clicked() //显示电网端实时数据
{
    ui->stackedWidget->setCurrentWidget(ui->Status_page);
    ui->Run_tabWidget->setCurrentWidget(ui->RTData_page);
    ui->RTD_PCS_StackedWidget->setCurrentWidget(ui->RTD_Bypass_Y_page);
    ui->Bypass_Tab->setCurrentWidget(ui->Bypass_Grid_page);
}

void MEGAWin::on_Load_clicked() //显示负载端实时数据
{
    ui->stackedWidget->setCurrentWidget(ui->Status_page);
    ui->Run_tabWidget->setCurrentWidget(ui->RTData_page);
    ui->RTD_PCS_StackedWidget->setCurrentWidget(ui->RTD_Bypass_Y_page);
    ui->Bypass_Tab->setCurrentWidget(ui->Bypass_Load_page);
}

void MEGAWin::on_Batt_btn_pressed() //显示电池信息
{
    ui->stackedWidget->setCurrentWidget(ui->Status_page);
    ui->Run_tabWidget->setCurrentWidget(ui->BatteryData_page);
    ui->BAT_stackedWidget->setCurrentWidget(ui->BAT_Lithium_page);

}

void MEGAWin::on_Batt_btn_released()    //显示电池信息
{
    ui->stackedWidget->setCurrentWidget(ui->Status_page);
    ui->Run_tabWidget->setCurrentWidget(ui->BatteryData_page);
    ui->BAT_stackedWidget->setCurrentWidget(ui->BAT_Lithium_page);
}

void MEGAWin::on_Alarm_btn_clicker()//显示告警信息
{
    ui->stackedWidget->setCurrentWidget(ui->Status_page);
    ui->Run_tabWidget->setCurrentWidget(ui->RTAlarm_page);
}

void MEGAWin::on_SConverter_btn_clicked()
{
    ui->Bypass_Tab->setCurrentWidget(ui->Bypass_Converter_page);
}

void MEGAWin::on_SGrid_btn_clicked()
{
    ui->Bypass_Tab->setCurrentWidget(ui->Bypass_Grid_page);
}

void MEGAWin::on_SLoad_btn_clicked()
{
    ui->Bypass_Tab->setCurrentWidget(ui->Bypass_Load_page);
}

void MEGAWin::on_TimeSeting_btn_released()
{

}

void MEGAWin::on_Run_tabWidget_tabBarClicked(int index) //实时数据界面选项卡点击响应
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

void MEGAWin::combox_ControlMode_change()
{

}


//void MEGAWin::on_System_tabWidget_currentChanged(int index)
//{
//    GeneralParam_tbnt_released();
////    Information_tbnt_released();
//}

void MEGAWin::Data_report_clicked(int nid)//数据报表点击槽
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
//系统信息点击槽
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
                              ,"这是网关，默,192.168.1.1\nThis is the gateway, Mer,192.168.1.1", "OK");
        break;
    case 5:
        QMessageBox::question(this, "Serber ip"\
                              ,"这是服务器IP，默认192.168.1.200\nThis is the server IP address. The default is 192.168.1.200", "OK");
        break;
    case 6:
        QMessageBox::question(this, "Apply and Restart system"\
                              ,"这是应用并重启系统，点击后重启系统\nThis is apply and restart the system, click and restart the system", "OK");
        break;
    default:
        break;
    }
}

void MEGAWin::MonitorDebug_clicked(int nid)//监控调试点击槽
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

void MEGAWin::History()//历史记录 绘制button
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
    Grade->add_Specifition();
    Grade2 = new Specification(this,Grade2_explain, ui->Historicalfailure_tableWidget, 1, 0, \
                                                    "0", "Level", \
                                                    "这是事件告警等级，当事件告警等级为0时标红，表示这是故障信息\nThis is the event alarm level. When the event alarm level is 0, it is marked red, indicating that this is the fault information.");
    Grade2->add_Specifition();
    Grade3 = new Specification(this,Grade3_explain, ui->Historicalfailure_tableWidget, 2, 0, \
                                                    "0", "Level", \
                                                    "这是事件告警等级，当事件告警等级为0时标红，表示这是故障信息\nThis is the event alarm level. When the event alarm level is 0, it is marked red, indicating that this is the fault information.");
    Grade3->add_Specifition();
    Grade4 = new Specification(this,Grade4_explain, ui->Historicalfailure_tableWidget, 3, 0, \
                                                    "0", "Level", \
                                                    "这是事件告警等级，当事件告警等级为0时标红，表示这是故障信息\nThis is the event alarm level. When the event alarm level is 0, it is marked red, indicating that this is the fault information.");
    Grade4->add_Specifition();
    Grade5 = new Specification(this,Grade5_explain, ui->Historicalfailure_tableWidget, 4, 0, \
                                                    "0", "Level", \
                                                    "这是事件告警等级，当事件告警等级为0时标红，表示这是故障信息\nThis is the event alarm level. When the event alarm level is 0, it is marked red, indicating that this is the fault information.");
    Grade5->add_Specifition();
    Grade6 = new Specification(this,Grade6_explain, ui->Historicalfailure_tableWidget, 5, 0, \
                                                    "0", "Level", \
                                                    "这是事件告警等级，当事件告警等级为0时标红，表示这是故障信息\nThis is the event alarm level. When the event alarm level is 0, it is marked red, indicating that this is the fault information.");
    Grade6->add_Specifition();
    Grade7 = new Specification(this,Grade7_explain, ui->Historicalfailure_tableWidget, 6, 0, \
                                                    "0", "Level", \
                                                    "这是事件告警等级，当事件告警等级为0时标红，表示这是故障信息\nThis is the event alarm level. When the event alarm level is 0, it is marked red, indicating that this is the fault information.");
    Grade7->add_Specifition();
    Grade8 = new Specification(this,Grade8_explain, ui->Historicalfailure_tableWidget, 7, 0, \
                                                    "0", "Level", \
                                                    "这是事件告警等级，当事件告警等级为0时标红，表示这是故障信息\nThis is the event alarm level. When the event alarm level is 0, it is marked red, indicating that this is the fault information.");
    Grade8->add_Specifition();
    StartTime = new Specification(this,StartTime_explain, ui->Historicalfailure_tableWidget, 0, 1, \
                                                    "2023.5.6 15:49:50", "Start Time", \
                                                    "这是事件开始时间，表示这条记录从这个时间开始出现\nThis is the event start time, which means that the record started appearing at this time.");
    StartTime->add_Specifition();
    StartTime2 = new Specification(this,StartTime2_explain, ui->Historicalfailure_tableWidget, 1, 1, \
                                                    "2023.5.6 15:48:18", "Start Time", \
                                                    "这是事件开始时间，表示这条记录从这个时间开始出现\nThis is the event start time, which means that the record started appearing at this time.");
    StartTime2->add_Specifition();
    StartTime3 = new Specification(this,StartTime3_explain, ui->Historicalfailure_tableWidget, 2, 1, \
                                                    "2023.5.6 15:39:3", "Start Time", \
                                                    "这是事件开始时间，表示这条记录从这个时间开始出现\nThis is the event start time, which means that the record started appearing at this time.");
    StartTime3->add_Specifition();
    StartTime4 = new Specification(this,StartTime4_explain, ui->Historicalfailure_tableWidget, 3, 1, \
                                                    "2023.5.6 15:39:3", "Start Time", \
                                                    "这是事件开始时间，表示这条记录从这个时间开始出现\nThis is the event start time, which means that the record started appearing at this time.");
    StartTime4->add_Specifition();
    StartTime5 = new Specification(this,StartTime5_explain, ui->Historicalfailure_tableWidget, 4, 1, \
                                                    "2023.5.6 15:39:3", "Start Time", \
                                                    "这是事件开始时间，表示这条记录从这个时间开始出现\nThis is the event start time, which means that the record started appearing at this time.");
    StartTime5->add_Specifition();
    StartTime6 = new Specification(this,StartTime6_explain, ui->Historicalfailure_tableWidget, 5, 1, \
                                                    "2023.5.6 15:21:56", "Start Time", \
                                                    "这是事件开始时间，表示这条记录从这个时间开始出现\nThis is the event start time, which means that the record started appearing at this time.");
    StartTime6->add_Specifition();
    StartTime7 = new Specification(this,StartTime7_explain, ui->Historicalfailure_tableWidget, 6, 1, \
                                                    "2023.5.6 15:21:38", "Start Time", \
                                                    "这是事件开始时间，表示这条记录从这个时间开始出现\nThis is the event start time, which means that the record started appearing at this time.");
    StartTime7->add_Specifition();
    StartTime8 = new Specification(this,StartTime8_explain, ui->Historicalfailure_tableWidget, 7, 1, \
                                                    "2023.5.6 15:21:38", "Start Time", \
                                                    "这是事件开始时间，表示这条记录从这个时间开始出现\nThis is the event start time, which means that the record started appearing at this time.");
    StartTime8->add_Specifition();
    EndTime = new Specification(this,EndTime_explain, ui->Historicalfailure_tableWidget, 0, 2, \
                                                    "-", "End Time", \
                                                    "这是事件结束时间，表示这条记录的结束时间,'...'表示无结束时间\nThis is the event end time, which means the end time of this record,'... 'means no end time.");
    EndTime->add_Specifition();
    EndTime2 = new Specification(this,EndTime2_explain, ui->Historicalfailure_tableWidget, 1, 2, \
                                                    "-", "End Time", \
                                                    "这是事件结束时间，表示这条记录的结束时间,'...'表示无结束时间\nThis is the event end time, which means the end time of this record,'... 'means no end time.");
    EndTime2->add_Specifition();
    EndTime3 = new Specification(this,EndTime3_explain, ui->Historicalfailure_tableWidget, 2, 2, \
                                                    "...", "End Time", \
                                                    "这是事件结束时间，表示这条记录的结束时间,'...'表示无结束时间\nThis is the event end time, which means the end time of this record,'... 'means no end time.");
    EndTime3->add_Specifition();
    EndTime4 = new Specification(this,EndTime4_explain, ui->Historicalfailure_tableWidget, 3, 2, \
                                                    "-", "End Time", \
                                                    "这是事件结束时间，表示这条记录的结束时间,'...'表示无结束时间\nThis is the event end time, which means the end time of this record,'... 'means no end time.");
    EndTime4->add_Specifition();
    EndTime5 = new Specification(this,EndTime5_explain, ui->Historicalfailure_tableWidget, 4, 2, \
                                                    "...", "End Time", \
                                                    "这是事件结束时间，表示这条记录的结束时间,'...'表示无结束时间\nThis is the event end time, which means the end time of this record,'... 'means no end time.");
    EndTime5->add_Specifition();
    EndTime6 = new Specification(this,EndTime6_explain, ui->Historicalfailure_tableWidget, 5, 2, \
                                                    "-", "End Time", \
                                                    "这是事件结束时间，表示这条记录的结束时间,'...'表示无结束时间\nThis is the event end time, which means the end time of this record,'... 'means no end time.");
    EndTime6->add_Specifition();
    EndTime7 = new Specification(this,EndTime7_explain, ui->Historicalfailure_tableWidget, 6, 2, \
                                                    "-", "End Time", \
                                                    "这是事件结束时间，表示这条记录的结束时间,'...'表示无结束时间\nThis is the event end time, which means the end time of this record,'... 'means no end time.");
    EndTime7->add_Specifition();
    EndTime8 = new Specification(this,EndTime8_explain, ui->Historicalfailure_tableWidget, 7, 2, \
                                                    "-", "End Time", \
                                                    "这是事件结束时间，表示这条记录的结束时间,'...'表示无结束时间\nThis is the event end time, which means the end time of this record,'... 'means no end time.");
    EndTime8->add_Specifition();
    Describe = new Specification(this,Describe_explain, ui->Historicalfailure_tableWidget, 0, 3, \
                                                    "CAN communication failure", "Description", \
                                                    "这是事件描述，当有告警信息时，会将告警信息记录在这里\nThis is the event description, when there is an alarm information, the alarm information will be recorded here.");
    Describe->add_Specifition();
    Describe2 = new Specification(this,Describe2_explain, ui->Historicalfailure_tableWidget, 1, 3, \
                                                    "CAN communication failure", "Description", \
                                                    "这是事件描述，当有告警信息时，会将告警信息记录在这里\nThis is the event description, when there is an alarm information, the alarm information will be recorded here.");
    Describe2->add_Specifition();
    Describe3 = new Specification(this,Describe3_explain, ui->Historicalfailure_tableWidget, 2, 3, \
                                                    "Fire alarm (High temp. alarm)", "Description", \
                                                    "这是事件描述，当有告警信息时，会将告警信息记录在这里\nThis is the event description, when there is an alarm information, the alarm information will be recorded here.");
    Describe3->add_Specifition();
    Describe4 = new Specification(this,Describe4_explain, ui->Historicalfailure_tableWidget, 3, 3, \
                                                    "CAN communication failure", "Description", \
                                                    "这是事件描述，当有告警信息时，会将告警信息记录在这里\nThis is the event description, when there is an alarm information, the alarm information will be recorded here.");
    Describe4->add_Specifition();
    Describe5 = new Specification(this,Describe5_explain, ui->Historicalfailure_tableWidget, 4, 3, \
                                                    "PowerMeter Comm fualttLead-acid abnormal", "Description", \
                                                    "这是事件描述，当有告警信息时，会将告警信息记录在这里\nThis is the event description, when there is an alarm information, the alarm information will be recorded here.");
    Describe5->add_Specifition();
    Describe6 = new Specification(this,Describe6_explain, ui->Historicalfailure_tableWidget, 5, 3, \
                                                    "CAN communication failure", "Description", \
                                                    "这是事件描述，当有告警信息时，会将告警信息记录在这里\nThis is the event description, when there is an alarm information, the alarm information will be recorded here.");
    Describe6->add_Specifition();
    Describe7 = new Specification(this,Describe7_explain, ui->Historicalfailure_tableWidget, 6, 3, \
                                                    "Fire alarm (High temp. alarm)", "Description", \
                                                    "这是事件描述，当有告警信息时，会将告警信息记录在这里\nThis is the event description, when there is an alarm information, the alarm information will be recorded here.");
    Describe7->add_Specifition();
    Describe8 = new Specification(this,Describe8_explain, ui->Historicalfailure_tableWidget, 7, 3, \
                                                    "PowerMeter Comm fualttLead-acid abnormal", "Description", \
                                                    "这是事件描述，当有告警信息时，会将告警信息记录在这里\nThis is the event description, when there is an alarm information, the alarm information will be recorded here.");
    Describe8->add_Specifition();
}

void MEGAWin::OperationLog()//操作日志 绘制button
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
    ModificationTime->add_Specifition();
    ModificationTime2 = new Specification(this,ModificationTime2_explain, ui->Operation_tableWidget, 1, 0, \
                                                    "2023-05-12 11:32:33", "ModificationTime", \
                                                    "系统设置修改时的时间\nTime when the system Settings are modified");
    ModificationTime2->add_Specifition();
    ModificationTime3 = new Specification(this,ModificationTime3_explain, ui->Operation_tableWidget, 2, 0, \
                                                    "2023-05-11 19:29:24", "ModificationTime", \
                                                    "系统设置修改时的时间\nTime when the system Settings are modified");
    ModificationTime3->add_Specifition();
    ModificationTime4 = new Specification(this,ModificationTime4_explain, ui->Operation_tableWidget, 3, 0, \
                                                    "2023-05-11 19:29:21", "ModificationTime", \
                                                    "系统设置修改时的时间\nTime when the system Settings are modified");
    ModificationTime4->add_Specifition();
    ModificationTime5 = new Specification(this,ModificationTime5_explain, ui->Operation_tableWidget, 4, 0, \
                                                    "2023-05-11 19:29:10", "ModificationTime", \
                                                    "系统设置修改时的时间\nTime when the system Settings are modified");
    ModificationTime5->add_Specifition();
    ModificationTime6 = new Specification(this,ModificationTime6_explain, ui->Operation_tableWidget, 5, 0, \
                                                    "2023-05-11 19:29:07", "ModificationTime", \
                                                    "系统设置修改时的时间\nTime when the system Settings are modified");
    ModificationTime6->add_Specifition();
    ModificationTime7 = new Specification(this,ModificationTime7_explain, ui->Operation_tableWidget, 6, 0, \
                                                    "2023-05-11 17:21:16", "ModificationTime", \
                                                    "系统设置修改时的时间\nTime when the system Settings are modified");
    ModificationTime7->add_Specifition();
    ModificationTime8 = new Specification(this,ModificationTime8_explain, ui->Operation_tableWidget, 7, 0, \
                                                    "2023-05-11 11:21:02", "ModificationTime", \
                                                    "系统设置修改时的时间\nTime when the system Settings are modified");
    ModificationTime8->add_Specifition();
    ModificationTime9 = new Specification(this,ModificationTime9_explain, ui->Operation_tableWidget, 8, 0, \
                                                    "2023-05-11 11:20:58", "ModificationTime", \
                                                    "系统设置修改时的时间\nTime when the system Settings are modified");
    ModificationTime9->add_Specifition();
    ModificationTime10 = new Specification(this,ModificationTime10_explain, ui->Operation_tableWidget, 9, 0, \
                                                    "2023-05-11 11:02:22", "ModificationTime", \
                                                    "系统设置修改时的时间\nTime when the system Settings are modified");
    ModificationTime10->add_Specifition();
    ModificationTime11 = new Specification(this,ModificationTime11_explain, ui->Operation_tableWidget, 10, 0, \
                                                    "2023-05-11 11:02:18", "ModificationTime", \
                                                    "系统设置修改时的时间\nTime when the system Settings are modified");
    ModificationTime11->add_Specifition();
    ModificationTime12 = new Specification(this,ModificationTime12_explain, ui->Operation_tableWidget, 11, 0, \
                                                    "2023-05-11 11:02:14", "ModificationTime", \
                                                    "系统设置修改时的时间\nTime when the system Settings are modified");
    ModificationTime12->add_Specifition();
    EventRecord = new Specification(this,EventRecord_explain, ui->Operation_tableWidget, 0, 1, \
                                                    "Power control type：CP_P->CP_N&&P", "RecordEvent", \
                                                    "这里是对系统设置进行修改时的操作记录\nHere is a record of the operation when a change is made to the system Settings.");
    EventRecord->add_Specifition();
    EventRecord2 = new Specification(this,EventRecord2_explain, ui->Operation_tableWidget, 1, 1, \
                                                    "Power control type：CP_N&&P->CP_P", "RecordEvent", \
                                                    "这里是对系统设置进行修改时的操作记录\nHere is a record of the operation when a change is made to the system Settings.");
    EventRecord2->add_Specifition();
    EventRecord3 = new Specification(this,EventRecord3_explain, ui->Operation_tableWidget, 2, 1, \
                                                    "Grid Fre Upper limit：0.2->3", "RecordEvent", \
                                                    "这里是对系统设置进行修改时的操作记录\nHere is a record of the operation when a change is made to the system Settings.");
    EventRecord3->add_Specifition();
    EventRecord4 = new Specification(this,EventRecord4_explain, ui->Operation_tableWidget, 3, 1, \
                                                    "Grid Fre Upper limit：3->0.2", "RecordEvent", \
                                                    "这里是对系统设置进行修改时的操作记录\nHere is a record of the operation when a change is made to the system Settings.");
    EventRecord4->add_Specifition();
    EventRecord5 = new Specification(this,EventRecord5_explain, ui->Operation_tableWidget, 4, 1, \
                                                    "Voltage protection Lower limit：-10->-15", "RecordEvent", \
                                                    "这里是对系统设置进行修改时的操作记录\nHere is a record of the operation when a change is made to the system Settings.");
    EventRecord5->add_Specifition();
    EventRecord6 = new Specification(this,EventRecord6_explain, ui->Operation_tableWidget, 5, 1, \
                                                    "Voltage protection Lower limit：-15->-10", "RecordEvent", \
                                                    "这里是对系统设置进行修改时的操作记录\nHere is a record of the operation when a change is made to the system Settings.");
    EventRecord6->add_Specifition();
    EventRecord7 = new Specification(this,EventRecord7_explain, ui->Operation_tableWidget, 6, 1, \
                                                    "Operation mode：Prevent countercurrnet->Peak valley", "RecordEvent", \
                                                    "这里是对系统设置进行修改时的操作记录\nHere is a record of the operation when a change is made to the system Settings.");
    EventRecord7->add_Specifition();
    EventRecord8 = new Specification(this,EventRecord8_explain, ui->Operation_tableWidget, 7, 1, \
                                                    "Operation mode：UPS->Prevent countercurrnet", "RecordEvent", \
                                                    "这里是对系统设置进行修改时的操作记录\nHere is a record of the operation when a change is made to the system Settings.");
    EventRecord8->add_Specifition();
    EventRecord9 = new Specification(this,EventRecord9_explain, ui->Operation_tableWidget, 8, 1, \
                                                    "Operation mode：Manual->UPS", "RecordEvent", \
                                                    "这里是对系统设置进行修改时的操作记录\nHere is a record of the operation when a change is made to the system Settings.");
    EventRecord9->add_Specifition();
    EventRecord10 = new Specification(this,EventRecord10_explain, ui->Operation_tableWidget, 9, 1, \
                                                    "Operation mode：Peak valley->Manual", "RecordEvent", \
                                                    "这里是对系统设置进行修改时的操作记录\nHere is a record of the operation when a change is made to the system Settings.");
    EventRecord10->add_Specifition();
    EventRecord11 = new Specification(this,EventRecord11_explain, ui->Operation_tableWidget, 10, 1, \
                                                    "Inv ON/Off-Grid：Off->automatic", "RecordEvent", \
                                                    "这里是对系统设置进行修改时的操作记录\nHere is a record of the operation when a change is made to the system Settings.");
    EventRecord11->add_Specifition();
    EventRecord12 = new Specification(this,EventRecord12_explain, ui->Operation_tableWidget, 11, 1, \
                                                    "Inv ON/Off-Grid：automatic->Off", "RecordEvent", \
                                                    "这里是对系统设置进行修改时的操作记录\nHere is a record of the operation when a change is made to the system Settings.");
    EventRecord12->add_Specifition();
}

void MEGAWin::RTAlarm()//告警信息 绘表
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
    RTAlarm_Title << tr("告警名称\nAlarm name") << tr("告警等级\nAlarm leve")<< tr("触发条件\nTrigger condition") \
                    << tr("响应动作\nResponse action")<< tr("是否自动复位及复位时间\nWhether to reset\nautomatically and reset time");
    ui->RTAlarm_Data_page->setHorizontalHeaderLabels(RTAlarm_Title);

    PCS_Alarm_information_table();  //展示PCS故障信息表
}

void MEGAWin::BatteryData_clicked(int nid)//电池数据点击槽
{

    switch (nid) {
    case 0:
        QMessageBox::question(this, "Bat volage"\
                              ,"这是通过CAN/485通讯协议从BMS上传的电池电压\nThis is the battery voltage uploaded from the BMS using the CAN/485 communication protocol.", "OK");
        break;
    case 1:
        QMessageBox::question(this, "Bat current"\
                              ,"这是通过CAN/485通讯协议从BMS上传的电池电流\nThis is the battery current uploaded from the BMS using the CAN/485 communication protocol.", "OK");
        break;
    case 2:
        QMessageBox::question(this, "SOC"\
                              ,"这是通过CAN/485通讯协议从BMS上传的电池SOC，即电池剩余电量百分比\nThis is the battery SOC, which is the percentage of remaining battery power, uploaded from the BMS using the CAN/485 communication protocol.", "OK");
        break;
    case 3:
        QMessageBox::question(this, "SOH"\
                              ,"这是通过CAN/485通讯协议从BMS上传的电池SOH，即电池当前的容量与出厂容量的百分比\nThis is the battery SOH uploaded from the BMS using the CAN/485 communication protocol, that is, the percentage of the current capacity of the battery to the factory capacity.", "OK");
        break;
    case 4:
        QMessageBox::question(this, "Cell voltage(max)"\
                              ,"这是通过CAN/485通讯协议从BMS上传的单体最高电压,即当前所有单体电池电压的最高电压\nThis is the maximum voltage of a single cell uploaded from the BMS through the CAN/485 communication protocol, that is, the maximum voltage of all the current battery.", "OK");
        break;
    case 5:
        QMessageBox::question(this, "Cell voltage(min)"\
                              ,"这是通过CAN/485通讯协议从BMS上传的单体最低电压,即当前所有单体电池电压的最低电压\nThis is the minimum voltage of a single cell uploaded from the BMS through the CAN/485 communication protocol, that is, the minimum voltage of all the current battery voltage.", "OK");
        break;
    case 6:
        QMessageBox::question(this, "Cell temp.(max)"\
                              ,"这是通过CAN/485通讯协议从BMS上传的单体最高温度,即当前所有单体电池温度的最高温度\nThis is the highest temperature of a single battery uploaded from the BMS using the CAN/485 communication protocol, that is, the highest temperature of all batteries.", "OK");
        break;
    case 7:
        QMessageBox::question(this, "Cell temp.(min)"\
                              ,"这是通过CAN/485通讯协议从BMS上传的单体最低温度,即当前所有单体电池温度的最低温度\nThis is the lowest temperature of a single battery uploaded from the BMS using the CAN/485 communication protocol, that is, the lowest temperature of all batteries.", "OK");
        break;
    case 8:
        QMessageBox::question(this, "Charging current limite"\
                              ,"这是通过CAN/485通讯协议从BMS上传的充电电流上限，电池的充电的电流不可超过这个限制数值\nThis is the upper limit of the charging current uploaded from the BMS through the CAN/485 communication protocol. The charging current of the battery cannot exceed this limit value.", "OK");
        break;
    case 9:
        QMessageBox::question(this, "Discharging current limite"\
                              ,"这是通过CAN/485通讯协议从BMS上传的放电电流上限，电池的放电的电流不可超过这个限制数值\nThis is the upper limit of the discharge current uploaded from the BMS through the CAN/485 communication protocol. The battery discharge current cannot exceed this limit value.", "OK");
        break;
    case 10:
        QMessageBox::question(this, "Allow charge power"\
                              ,"这是通过CAN/485通讯协议从BMS上传的可充电功率，电池的充电功率不可超过这个限制数值\nThis is the rechargeable power uploaded from the BMS through the CAN/485 communication protocol. The charging power of the battery cannot exceed this limit value.", "OK");
        break;
    case 11:
        QMessageBox::question(this, "Allow discharge power"\
                              ,"这是通过CAN/485通讯协议从BMS上传的可放电功率，电池的放电功率不可超过这个限制数值\nThis is the discharge power uploaded from the BMS using the CAN/485 communication protocol. The discharge power of the battery cannot exceed this limit.", "OK");
        break;
    case 12:
        QMessageBox::question(this, "Allow charge energy"\
                              ,"这是通过CAN/485通讯协议从BMS上传的允许充电量，电池的充电量不可超过这个限制数值\nThis is the allowable charge amount uploaded from BMS through CAN/485 communication protocol. The battery charge amount cannot exceed this limit value.", "OK");
        break;
    case 13:
        QMessageBox::question(this, "Allow discharge energy"\
                              ,"这是通过CAN/485通讯协议从BMS上传的允许放电量，电池的放电量不可超过这个限制数值\nThis is the allowable discharge capacity uploaded from the BMS through the CAN/485 communication protocol. The discharge capacity of the battery cannot exceed this limit.", "OK");
        break;
    case 14:
        QMessageBox::question(this, "Alarm level"\
                              ,"这是告警等级图示，会根据BMS上传的告警等级改变颜色，此处可以通过颜色判断告警等级，正常为绿色、告警1为黄色、告警2为橙色、告警3为红色\nThis is the alarm severity icon. The color of the alarm is changed according to the alarm severity uploaded by the BMS. You can judge the alarm severity by the color.", "OK");
        break;
    case 15:
        QMessageBox::question(this, "Charge enable"\
                              ,"这是充电使能，它是由BMS上传的动作，可以作为判断当前是否可以充电的判断标准\nThis is the charging enable, which is the action uploaded by BMS and can be used as the judging standard to judge whether the current charging is possible.", "OK");
        break;
    case 16:
        QMessageBox::question(this, "Discharge enable"\
                              ,"这是放电使能，它是由BMS上传的动作，可以作为判断当前是否可以放电的判断标准\nThis is discharge enable, it is uploaded by the BMS action, can be used to judge whether the current discharge can judge the criteria.", "OK");
        break;
    case 17:
        QMessageBox::question(this, "Warning2"\
                              ,"这是二级告警时的颜色--橙色，当告警等级(Alarm level)中的颜色与此颜色一致时为二级告警\nThis is the color of a level 2 Alarm: orange. If the color of an Alarm level(Alarm level) is the same as this color, it is a Level 2 alarm.", "OK");
        break;
    case 18:
        QMessageBox::question(this, "Warning3"\
                              ,"这是三级告警时的颜色--红色，当告警等级(Alarm level)中的颜色与此颜色一致时为三级告警\nThis color is red for a level 3 Alarm. If the color in the Alarm level(Alarm level) is the same as this color, it is a Level 3 alarm.", "OK");
        break;
    case 19:
        QMessageBox::question(this, "Normal"\
                              ,"这是正常时的颜色--绿色，表示当前无告警,当告警等级(Alarm level)中的颜色与此颜色一致时为正常\nThis is the normal color. Green: No Alarm is generated. If the color in the Alarm level(Alarm level) is the same as this color, the alarm is normal.", "OK");
        break;
    case 20:
        QMessageBox::question(this, "Warning1"\
                              ,"这是一级告警时的颜色--黄色，当告警等级(Alarm level)中的颜色与此颜色一致时为一级告警\nThis is the color of a level 1 Alarm: yellow. If the color of an Alarm level(Alarm level) is the same as this color, it is a Level 1 alarm.", "OK");
        break;
    default:
        break;
    }
}
void MEGAWin::PCS_Data()//PCS数据 绘制button
{
    PCS_vol_AB = new Specification(this,PCS_vol_AB_explain, ui->Converter_Tab, 0, 1, \
                                            "99.9V", "PCS voltage(AB)", \
                                            "这是从变流器获取的当前PCS的A相和B相之间的电压\nThis is the voltage between the A and B phases of the current PCS obtained from the converter.");
    PCS_vol_AB->add_Specifition();
    PCS_vol_BC = new Specification(this,PCS_vol_BC_explain, ui->Converter_Tab, 1, 1, \
                                            "99.9V", "PCS voltage(BC)", \
                                            "这是从变流器获取的当前PCS的B相和C相之间的电压\nThis is the voltage between the B and C phases of the current PCS obtained from the converter.");
    PCS_vol_BC->add_Specifition();
    PCS_vol_CA = new Specification(this,PCS_vol_CA_explain, ui->Converter_Tab, 2, 1, \
                                            "99.7V", "PCS voltage(CA)", \
                                            "这是从变流器获取的当前PCS的A相和C相之间的电压\nThis is the voltage between phase A and phase C of the current PCS obtained from the converter.");
    PCS_vol_CA->add_Specifition();
    PCS_cur_A = new Specification(this,PCS_cur_A_explain, ui->Converter_Tab, 3, 1, \
                                            "0A", "PCS current(A)", \
                                            "这是从变流器获取的当前PCS的A相电流\nThis is the A-phase current of the current PCS obtained from the converter.");
    PCS_cur_A->add_Specifition();
    PCS_cur_B = new Specification(this,PCS_cur_B_explain, ui->Converter_Tab, 4, 1, \
                                            "0A", "PCS current(B)", \
                                            "这是从变流器获取的当前PCS的B相电流\nThis is the B-phase current of the current PCS obtained from the converter.");
    PCS_cur_B->add_Specifition();
    PCS_cur_C = new Specification(this,PCS_cur_C_explain, ui->Converter_Tab, 5, 1, \
                                            "0A", "PCS current(C)", \
                                            "这是从变流器获取的当前PCS的C相电流\nThis is the C-phase current of the current PCS obtained from the converter.");
    PCS_cur_C->add_Specifition();
    PCS_act_P = new Specification(this,PCS_act_P_explain, ui->Converter_Tab, 6, 1, \
                                            "0kW", "PCS Active Power", \
                                            "这是从变流器获取的当前PCS的有功功率,它反映了交流电源在电阻元件上做功的能力大小\nThis is the active power of the current PCS obtained from the converter, which reflects the capacity of the AC power supply to do work on the resistance element.");
    PCS_act_P->add_Specifition();
    PCS_rea_P = new Specification(this,PCS_rea_P_explain, ui->Converter_Tab, 7, 1, \
                                            "0kVar", "PCS Reactive Power", \
                                            "这是从变流器获取的当前PCS的无功功率,它表达了交流电源能量与磁场或电场能量交换的最大速率\nThis is the reactive power of the current PCS obtained from the converter, which expresses the maximum rate at which the AC power source energy is exchanged with the magnetic or electric field energy.");
    PCS_rea_P->add_Specifition();
    PCS_par_P = new Specification(this,PCS_par_P_explain, ui->Converter_Tab, 8, 1, \
                                            "0kVA", "PCS Parent Power", \
                                            "这是从变流器获取的当前PCS的视在功率,它用来表示变流器的容量大小\nThis is the apparent power of the current PCS obtained from the converter, which is used to represent the capacity of the transformer.");
    PCS_par_P->add_Specifition();

    PCS_Pf = new Specification(this,PCS_Pf_explain, ui->Converter_Tab, 9, 1, \
                                            "0", "PCS Power factor", \
                                            "这是从变流器获取的当前PCS的功率因数,它是交流电路有功功率对视在功率的比值\nThis is the power factor of the current PCS obtained from the converter, which is the ratio of the active power to the apparent power of the AC circuit.");
    PCS_Pf->add_Specifition();
    PCS_Bat_vol = new Specification(this,PCS_Bat_vol_explain, ui->Converter_Tab, 0, 3, \
                                            "0V", "PCS Battery voltage", \
                                            "这是从变流器获取的当前电池电压\nThis is the current battery voltage obtained from the converter.");
    PCS_Bat_vol->add_Specifition();
    PCS_Bat_cur = new Specification(this,PCS_Bat_cur_explain, ui->Converter_Tab, 1, 3, \
                                            "0A", "PCS Battery current", \
                                            "这是从变流器获取的当前电池电流\nThis is the current battery current obtained from the converter.");
    PCS_Bat_cur->add_Specifition();
    PCS_Bat_P = new Specification(this,PCS_Bat_P_explain, ui->Converter_Tab, 2, 3, \
                                            "0kW", "PCS Battery power", \
                                            "这是从变流器获取的当前电池功率\nThis is the current battery power obtained from the converter.");
    PCS_Bat_P->add_Specifition();
    PCS_Bus_vol = new Specification(this,PCS_Bus_vol_explain, ui->Converter_Tab, 3, 3, \
                                            "0V", "PCS Bus voltage", \
                                            "这是从变流器获取的当前母线电压，母线电压是所有供电分支的源头，逆变器所有变压器输出后整流汇总在一起的高压直流电压，这里称之为母线电压\nThis is the current bus voltage obtained from the converter. The bus voltage is the source of all power supply branches and the combined high voltage DC voltage after the output of all transformers of the inverter. It is called the bus voltage here.");
    PCS_Bus_vol->add_Specifition();
    PCS_IGBT_T = new Specification(this,PCS_IGBT_T_explain, ui->Converter_Tab, 4, 3, \
                                            "39℃", "PCS IGBT temperature", \
                                            "这是从变流器获取的当前IGBT温度，IGBT温度是指半导体芯片内的最高工作温度\nThis is the current IGBT temperature obtained from the converter. IGBT temperature is the highest operating temperature inside the semiconductor chip.");
    PCS_IGBT_T->add_Specifition();
    PCS_Env_T = new Specification(this,PCS_Env_T_explain, ui->Converter_Tab, 5, 3, \
                                            "25℃", "PCS Environment temperature", \
                                            "这是从变流器获取的当前环境温度\nThis is the current ambient temperature obtained from the converter.");
    PCS_Env_T->add_Specifition();
}

void MEGAWin::Grid_Data()//电网数据 绘制button
{
    Grid_vol_AB = new Specification(this,Grid_vol_AB_explain, ui->Grid_Tab, 0, 1, \
                                            "0V", "Grid voltage(AB)", \
                                            "这是从变流器获取的当前电网的A相和B相之间的电压\nThis is the voltage between phase A and phase B of the current grid obtained from the converter.");
    Grid_vol_AB->add_Specifition();
    Grid_vol_BC = new Specification(this,Grid_vol_BC_explain, ui->Grid_Tab, 1, 1, \
                                            "0V", "Grid voltage(BC)", \
                                            "这是从变流器获取的当前电网的B相和C相之间的电压\nThis is the voltage between the B and C phases of the current grid obtained from the converter.");
    Grid_vol_BC->add_Specifition();
    Grid_vol_CA = new Specification(this,Grid_vol_CA_explain, ui->Grid_Tab, 2, 1, \
                                            "0V", "Grid voltage(CA)", \
                                            "这是从变流器获取的当前电网的A相和C相之间的电压\nThis is the voltage between phase A and phase C of the current grid obtained from the converter.");
    Grid_vol_CA->add_Specifition();
    Grid_cur_A = new Specification(this,Grid_cur_A_explain, ui->Grid_Tab, 3, 1, \
                                            "0A", "Grid current(AB)", \
                                            "这是从变流器获取的当前电网的A相电流\nThis is the current A-phase current of the grid obtained from the converter.");
    Grid_cur_A->add_Specifition();
    Grid_cur_B = new Specification(this,Grid_cur_B_explain, ui->Grid_Tab, 4, 1, \
                                            "0A", "Grid current(B)", \
                                            "这是从变流器获取的当前电网的B相电流\nThis is the current grid B-phase current obtained from the converter.");
    Grid_cur_B->add_Specifition();
    Grid_cur_C = new Specification(this,Grid_cur_C_explain, ui->Grid_Tab, 5, 1, \
                                            "0A", "Grid current(C)", \
                                            "这是从变流器获取的当前电网的C相电流\nThis is the current C-phase current of the grid obtained from the converter.");
    Grid_cur_C->add_Specifition();
    Grid_act_P = new Specification(this,Grid_act_P_explain, ui->Grid_Tab, 6, 1, \
                                            "0kW", "Grid active power", \
                                            "这是从变流器获取的当前电网的有功功率,它反映了交流电源在电阻元件上做功的能力大小\nThis is the active power of the current grid obtained from the converter, which reflects the ability of the AC power supply to do work on the resistance element.");
    Grid_act_P->add_Specifition();
    Grid_rea_P = new Specification(this,Grid_rea_P_explain, ui->Grid_Tab, 7, 1, \
                                            "0kVar", "Grid reactive power", \
                                            "这是从变流器获取的当前电网的无功功率,它表达了交流电源能量与磁场或电场能量交换的最大速率\nTThis is the reactive power of the current grid obtained from the converter, which expresses the maximum rate at which the energy of the AC source is exchanged with the energy of the magnetic or electric field.");
    Grid_rea_P->add_Specifition();
    Grid_app_P = new Specification(this,Grid_app_P_explain, ui->Grid_Tab, 8, 1, \
                                            "0kVA", "Grid apparent power", \
                                            "这是从变流器获取的当前电网的视在功率,它用来表示电网的容量大小\nThis is the apparent power of the current grid obtained from the converter, which is used to represent the capacity of the grid.");
    Grid_app_P->add_Specifition();
    Grid_fre = new Specification(this,Grid_fre_explain, ui->Grid_Tab, 9, 1, \
                                            "0Hz", "Grid frequency", \
                                            "这是从变流器获取的当前电网的频率\nThis is the frequency of the current grid obtained from the converter.");
    Grid_fre->add_Specifition();
    Grid_Pf = new Specification(this,Grid_Pf_explain, ui->Grid_Tab, 10, 1, \
                                            "0", "Grid power factor", \
                                            "这是从变流器获取的当前电网的功率因数,它是交流电路有功功率对视在功率的比值\nThis is the power factor of the current grid obtained from the converter, which is the ratio of the active power to the apparent power of the AC circuit.");
    Grid_Pf->add_Specifition();
}

void MEGAWin::Load_Data()//负载数据 绘制button
{
    Load_vol_AB = new Specification(this,Load_vol_AB_explain, ui->Load_Tab, 0, 1, \
                                            "0V", "Load voltage(AB)", \
                                            "这是从变流器获取的负载的A相和B相之间的电压\nThis is the voltage between the A and B phases of the load obtained from the converter.");
    Load_vol_AB->add_Specifition();
    Load_vol_BC = new Specification(this,Load_vol_BC_explain, ui->Load_Tab, 1, 1, \
                                            "0V", "Load voltage(BC)", \
                                            "这是从变流器获取的负载的B相和C相之间的电压\nThis is the voltage between the B and C phases of the load obtained from the converter.");
    Load_vol_BC->add_Specifition();
    Load_vol_CA = new Specification(this,Load_vol_CA_explain, ui->Load_Tab, 2, 1, \
                                            "0V", "Load voltage(CA)", \
                                            "这是从变流器获取的负载的A相和C相之间的电压\nThis is the voltage between the A and C phases of the load obtained from the converter.");
    Load_vol_CA->add_Specifition();
    Load_cur_A = new Specification(this,Load_cur_A_explain, ui->Load_Tab, 3, 1, \
                                            "0A", "Load current(AB)", \
                                            "这是从变流器获取的负载的A相电流\nThis is the A-phase current of the load taken from the converter.");
    Load_cur_A->add_Specifition();
    Load_cur_B = new Specification(this,Load_cur_B_explain, ui->Load_Tab, 4, 1, \
                                            "0A", "Load current(B)", \
                                            "这是从变流器获取的负载的B相电流\nThis is the B-phase current of the load obtained from the converter.");
    Load_cur_B->add_Specifition();
    Load_cur_C = new Specification(this,Load_cur_C_explain, ui->Load_Tab, 5, 1, \
                                            "0A", "Load current(C)", \
                                            "这是从变流器获取的负载的C相电流\nThis is the C-phase current of the load obtained from the converter.");
    Load_cur_C->add_Specifition();
    Load_act_P = new Specification(this,Load_act_P_explain, ui->Load_Tab, 6, 1, \
                                            "0kW", "Load active power", \
                                            "这是从变流器获取的负载的有功功率,它反映了交流电源在电阻元件上做功的能力大小\nThis is the active power of the load obtained from the converter, which reflects the ability of the AC supply to do work on the resistance element.");
    Load_act_P->add_Specifition();
    Load_rea_P = new Specification(this,Load_rea_P_explain, ui->Load_Tab, 7, 1, \
                                            "0kVar", "Load reactive power", \
                                            "这是从变流器获取的负载的无功功率,它表达了交流电源能量与磁场或电场能量交换的最大速率\nThis is the reactive power of the load obtained from the converter, which expresses the maximum rate at which the energy of the AC source is exchanged with the energy of the magnetic or electric field.");
    Load_rea_P->add_Specifition();
    Load_app_P = new Specification(this,Load_app_P_explain, ui->Load_Tab, 8, 1, \
                                            "0kVA", "Load apparent power", \
                                            "这是从变流器获取的负载的视在功率,它用来表示负载的容量大小\nThis is the apparent power of the load obtained from the converter, which is used to indicate the capacity of the load.");
    Load_app_P->add_Specifition();
    Load_Pf = new Specification(this,Load_Pf_explain, ui->Load_Tab, 9, 1, \
                                            "0.99", "Load frequency", \
                                            "这是从变流器获取的负载的功率因数，它是有功功率对视在功率的比值\nThis is the power factor of the load obtained from the converter, which is the ratio of active power to apparent power.");
    Load_Pf->add_Specifition();
}

void MEGAWin::PCS_State()//PCS状态 绘制button
{
    DC_input_Breaker = new Specification(this,DC_input_Breaker_explain, ui->RTState_Bypass_Tab, 0, 1, \
                                            "Close", "DC input Breaker", \
                                            "这是当前直流输入断路器的状态，有闭合(Close)、断开(Break)两种状态，直流断路器能准确保护继电保护、自动装置免受过载、短路等故障危害\nThis is the current DC input circuit breaker state, there are Close (Close), Break (Break) two states, DC circuit breaker can accurately protect the relay protection, automatic device from overload, short circuit and other faults.");
    DC_input_Breaker->add_Specifition();
    DC_Cont = new Specification(this,DC_Cont_explain, ui->RTState_Bypass_Tab, 1, 1, \
                                            "Close", "DC contactor", \
                                            "这是当前直流接触器的状态，有闭合(Close)、断开(Break)两种状态,直流接触器在直流回路中用于控制接通或切断直流电路使其启停\nThis is the current state of the DC contactor, with two states: Close(Close) and Break(Break). The DC contactor is used to control the switching on or cutting off the DC circuit in the DC circuit to make it start and stop.");
    DC_Cont->add_Specifition();
    Output_Cont = new Specification(this,Output_Cont_explain, ui->RTState_Bypass_Tab, 2, 1, \
                                            "Close", "Output contactor", \
                                            "这是当前输出接触器的状态，有闭合(Close)、断开(Break)两种状态，输出接触器在输出电路中用于控制接通或切断电路使其启停\nThis is the current state of the output contactor, with two states: Close(Close) and Break(Break). The output contactor is used in the output circuit to control on or off the circuit to make it start or stop.");
    Output_Cont->add_Specifition();
    Output_Breaker = new Specification(this,Output_Breaker_explain, ui->RTState_Bypass_Tab, 3, 1, \
                                            "Close", "Output Breaker", \
                                            "这是当前输出断路器的状态，有闭合(Close)、断开(Break)两种状态，根据需要可以切断和接通输出电路以达到保护电路的作用\nThis is the current output circuit breaker state, there are Close (Close), Break (Break) two states, according to the need to cut off and put on the output circuit to achieve the protection of the circuit.");
    Output_Breaker->add_Specifition();
    Grid_Cont = new Specification(this,Grid_Cont_explain, ui->RTState_Bypass_Tab, 4, 1, \
                                            "Close", "Grid contactor", \
                                            "这是当前电网接触器的状态，有闭合(Close)、断开(Break)两种状态，电网接触器在电网中用于控制接通或切断电路使其启停\nThis is the current state of the power grid contactor, with two states: Close(Close) and Break(Break). The power grid contactor is used in the power grid to control switching on or off the circuit to make it start or stop.");
    Grid_Cont->add_Specifition();
    Grid_Breaker = new Specification(this,Grid_Breaker_explain, ui->RTState_Bypass_Tab, 5, 1, \
                                            "Close", "Grid Breaker", \
                                            "这是当前电网断路器的状态，有闭合(Close)、断开(Break)两种状态，根据需要可以切断和接通电网电路以达到保护电路的作用\nThis is the current state of the circuit breaker of the power grid, there are two states of Close (Close) and Break (Break), according to the need to cut off and connect the power grid circuit to protect the circuit.");
    Grid_Breaker->add_Specifition();
    MB_Breaker = new Specification(this,MB_Breaker_explain, ui->RTState_Bypass_Tab, 6, 1, \
                                            "Close", "Maintenance Bypass Breaker", \
                                            "这是当前维修旁路的状态，有闭合(Close)、断开(Break)两种状态，维修旁路可以在保持提供给负载交流电的同时，使内部除了输出端变压器外其他地方无交流或直流电存在，以保证维护人员的安全\nThis is the status of the maintenance bypass, including Close(Close) and Break(Break). The maintenance bypass provides AC power to the load while ensuring that no AC or DC power exists except the output transformer, ensuring the safety of maintenance personnel.");
    MB_Breaker->add_Specifition();
    converter_available = new Specification(this,converter_available_explain, ui->RTState_Bypass_Tab, 0, 3, \
                                            "Disable", "converter available", \
                                            "这是当前变流器使能的状态，有使能(Enable)、禁止(Disable)两种状态,使能后变流器开机容许\nThis is the status of enabling the current converter. There are two states: Enable(Enable) and Disable(Disable). After enabling, the converter is allowed to start.");
    converter_available->add_Specifition();
    DC_Soft_start = new Specification(this,DC_Soft_start_explain, ui->RTState_Bypass_Tab, 1, 3, \
                                            "Not starting", "DC Soft start", \
                                            "这是当前直流软启动的状态，有软启中(Soft starting)、软启完成(complete)、未启动(Not starting)三种启动状态,软启动是指变流器在启动时，通过控制电流或电压的变化使设备逐渐加速或减速到正常运行状态，以减少电路中的电流冲击和电压峰值，保护电路元器件并减少设备的机械损伤。软启动可以增加设备的寿命，减少能耗，提高系统效率。\nThis is the current DC Soft startup state, including Soft starting(Soft starting), complete(complete) and Not starting(Not starting). Soft startup means that the converter gradually accelerates or decelerates the device to the normal operating state by controlling the change of current or voltage during startup. To reduce the current shock and voltage peak in the circuit, protect circuit components and reduce the mechanical damage of equipment. Soft boot can prolong the service life of the device, reduce power consumption, and improve system efficiency.");
    DC_Soft_start->add_Specifition();
    converter_status = new Specification(this,converter_status_explain, ui->RTState_Bypass_Tab, 2, 3, \
                                            "Shut down", "converter status", \
                                            "这是当前变流器的状态，有关闭(OFF)、软启动(Soft start)、并网充电(Grid-ON Charge)、并网放电(Grid-ON Discharge)、离网放电(Grid-OFF Discharge)、降额并网(Drop and Connected)、待机(Standby)、离网充电(Grid-OFF Charge)这八种状态\nThis is the current state of the converter, There are OFF(OFF), Soft start(Soft start), grid-on Charge(Grid-ON Charge), grid-on Discharge(Grid-ON Discharge), grid-off Discharge(Grid-OFF Discharge), Drop and Connected(Drop and Connected), Standby(Standby) and Grid-OFF Charge(Grid-OFF Charge) are eight states.");
    converter_status->add_Specifition();
    Reactive_P_Regulation = new Specification(this,Reactive_P_Regulation_explain, ui->RTState_Bypass_Tab, 3, 3, \
                                            "SVG", "Reactive Power Regulation", \
                                            "这是无功调节方式，有禁止(Disable)、功率因数调节(Pf regulation)、无功功率调节(Q regulation)、夜间SVG模式(SVG)四种状态，无功调节主要用于调整电压，提高供电稳定性，SVG可以向电网提供动态无功补偿，降低电站孤岛运行的概率，也可一定程度提高低电压穿越能力\nThis is the reactive power regulation mode, including Disable(Disable), Pf regulation(Pf regulation), Q regulation(Q regulation) and night SVG mode(SVG). Reactive power regulation is mainly used to adjust voltage and improve power supply stability. SVG can provide dynamic reactive power compensation to the power grid. Reducing the probability of isolated operation of power station can also improve the low voltage crossing ability to some extent.");
    Reactive_P_Regulation->add_Specifition();
    Sleep_mode = new Specification(this,Sleep_mode_explain, ui->RTState_Bypass_Tab, 4, 3, \
                                            "No dromancy", "Sleep mode", \
                                            "这是当前休眠模式的状态，有未休眠(No dromancy)、休眠(Dromant)两种状态\nThis is the status of the current hibernate mode, being No dromancy(No dromancy) and Dromancy(Dromant).");
    Sleep_mode->add_Specifition();
    LVRT = new Specification(this,LVRT_explain, ui->RTState_Bypass_Tab, 5, 3, \
                                            "LVRT", "LVRT", \
                                            "这是当前低电压穿越(LVRT)的状态，低电压穿越是在确定的时间内承受一定限值的电网低电压而不退出运行的能力，这里有两种状态，分别为无(Non)、有(LVRT)\nThis is the current state of low voltage crossing (LVRT). Low voltage crossing refers to the ability to withstand a certain limit of low voltage of the grid within a certain period of time without exiting the operation. There are two states here, namely Non(Non) and LVRT(LVRT).");
    LVRT->add_Specifition();
    Generator_signal = new Specification(this,Generator_signal_explain, ui->RTState_Bypass_Tab, 0, 5, \
                                            "Enable", "Generator signal", \
                                            "这是当前柴发信号的状态，输出干接点1，有使能(Enable)、禁止(Disable)两种状态,此处获取的是最真实的物理硬件状态，当该干接点电路回路接通时为1(Enable),电路回路断开时为0(Disable)\nThis is the status of the current diesel generator signal, dry contact output 1, there are two states: Enable(Enable) and Disable(Disable), here is the most real physical hardware status, when the dry contact circuit is connected to 1(Enable), when the circuit is disconnected to 0(Disable).");
    Generator_signal->add_Specifition();
    Reserve = new Specification(this,Reserve_explain, ui->RTState_Bypass_Tab, 1, 5, \
                                            "Disable", "Reserve", \
                                            "这是保留位，无作用，输出干接点2，有使能(Enable)、禁止(Disable)两种状态\nThis bit is reserved and has no effect. Dry contact 2 is output. The status of dry contact 2 is Enable(Enable) or Disable(Disable).");
    Reserve->add_Specifition();
    Reserve2 = new Specification(this,Reserve2_explain, ui->RTState_Bypass_Tab, 2, 5, \
                                            "Enable", "Reserve2", \
                                            "这是保留位，无作用，输出干接点3，有使能(Enable)、禁止(Disable)两种状态\nThis bit is reserved and has no effect. Dry contact 2 is output. The status of dry contact 3 is Enable(Enable) or Disable(Disable)");
    Reserve2->add_Specifition();
    EPO_Cont_signal1 = new Specification(this,EPO_Cont_signal1_explain, ui->RTState_Bypass_Tab, 3, 5, \
                                            "Disable", "EPO_Cont signal1", \
                                            "这是EPO节点信号1，输入干接点1，即外部停机干接点信号1，有使能(Enable)、禁止(Disable)两种状态,此处获取的是最真实的物理硬件状态，当该干接点电路回路接通时为1(Enable),电路回路断开时为0(Disable)\nThis is EPO node signal 1, input dry contact 1, that is, external stop dry contact signal 1, there are two states: Enable and Disable. What is obtained here is the most real physical hardware state. When the dry contact circuit is connected, it is 1(Enable), and when the circuit circuit is disconnected, it is 0(Disable).");
    EPO_Cont_signal1->add_Specifition();
    EPO_Cont_signal2 = new Specification(this,EPO_Cont_signal2_explain, ui->RTState_Bypass_Tab, 4, 5, \
                                            "Disable", "EPO_Cont signal2", \
                                            "这是EPO节点信号2，输入干接点2，即外部停机干接点信号2，有使能(Enable)、禁止(Disable)两种状态,此处获取的是最真实的物理硬件状态，当该干接点电路回路接通时为1(Enable),电路回路断开时为0(Disable)\nThis is EPO node signal 2, input dry contact 2, that is, external stop dry contact signal 2, there are two states: Enable and Disable. What is obtained here is the most real physical hardware state. When the dry contact circuit is connected, it is 1(Enable), and when the circuit circuit is disconnected, it is 0(Disable).");
    EPO_Cont_signal2->add_Specifition();
    Access_signal = new Specification(this,Access_signal_explain, ui->RTState_Bypass_Tab, 5, 5, \
                                            "Disable", "Access_signal", \
                                            "这是门禁信号，输入干接点3，有使能(Enable)、禁止(Disable)两种状态,此处获取的是最真实的物理硬件状态，当该干接点电路回路接通时为1(Enable),电路回路断开时为0(Disable)\nThis is the access control signal, input to dry contact 3, there are two states: Enable(Enable) and Disable(Disable). The most real physical hardware state is obtained here, which is 1 when the dry contact circuit circuit is connected (Enable), and 0 when the circuit circuit is disconnected (Disable).");
    Access_signal->add_Specifition();
    Full_P_signal = new Specification(this,Full_P_signal_explain, ui->RTState_Bypass_Tab, 6, 5, \
                                            "Disable", "Full_P_signal", \
                                            "这是满功率信号，输入干接点4，有使能(Enable)、禁止(Disable)两种状态,此处获取的是最真实的物理硬件状态，当该干接点电路回路接通时为1(Enable),电路回路断开时为0(Disable)\nThis is the full power signal, input to dry contact 4, there are two states: Enable(Enable) and Disable(Disable). The most real physical hardware state is obtained here, which is 1 when the dry contact circuit loop is turned on (Enable), and 0 when the circuit loop is disconnected (Disable).");
    Full_P_signal->add_Specifition();
    Smoke_alarm_signal = new Specification(this,Smoke_alarm_signal_explain, ui->RTState_Bypass_Tab, 7, 5, \
                                            "Disable", "Smoke alarm signal", \
                                            "这是烟雾告警信号，输入干接点5，有使能(Enable)、禁止(Disable)两种状态,此处获取的是最真实的物理硬件状态，当该干接点电路回路接通时为1(Enable),电路回路断开时为0(Disable)\nThis is smoke alarm signal, input dry contact 5, there are two states: Enable(Enable) and Disable(Disable). The most real physical hardware state is obtained here. When the dry contact circuit circuit is connected, it is 1(Enable), and when the circuit circuit is disconnected, it is 0(Disable).");
    Smoke_alarm_signal->add_Specifition();
    Hight_temp_signal = new Specification(this,Hight_temp_signal_explain, ui->RTState_Bypass_Tab, 8, 5, \
                                            "Disable", "Hight temp signal", \
                                            "这是高温信号，输入干接点6，有使能(Enable)、禁止(Disable)两种状态,此处获取的是最真实的物理硬件状态，当该干接点电路回路接通时为1(Enable),电路回路断开时为0(Disable)\nThis isa high temperature signal, input to dry contact 6, there are two states: Enable and Disable. The most real physical hardware state is obtained here, which is 1 when the dry contact circuit loop is connected (Enable), and 0 when the circuit loop is disconnected (Disable).");
    Hight_temp_signal->add_Specifition();
}

void MEGAWin::ParameterSet()//系统设置 绘制button
{
    Grid_connected_mode = new Specification(this,Grid_connected_mode_explain, ui->System_Tab, 0, 1, \
                                            "automatic", "Grid connected mode of PCS", \
                                            "这是PCS并网方式，一共有三项可选：自动(automatic)，并网(On)，离网(Off),选择'自动'时将自动识别当前的并网方式\n并网:与相邻电力系统发送电气连接，并进行功率交换(如与电网连接)\n离网：不依赖电网而独立运行(不接电网)\nThis is the PCS grid connection mode, there are three options: automatic(automatic), On(On), Off(Off), select 'automatic' will automatically identify the current grid connection mode \n grid connection: send electrical connection with the adjacent power system, and carry out power exchange (such as connection with the grid)\n off-grid: To operate independently of the grid (not connected to the grid).");
    Grid_connected_mode->add_Specifition();

    Constant_power = new Specification(this,Constant_power_explain, ui->System_Tab, 1, 1, \
                                       "0", "Constant power(AC)", \
                                       "这是恒功率，可以通过修改这项数值来设置机器的功率,当控制功率方式选择正负功率(CP_N&P)时,正数表示放电，负数表示充电\nThis is constant power, and the power of the machine can be set by modifying this value. When the power control mode is positive and negative (CP_N&P), the positive number means discharge and the negative number means charge.");
    Constant_power->add_Specifition();

    Charging_and_discharging = new Specification(this,Charging_and_discharging_explain, ui->System_Tab, 2, 1, \
                                                 "Charge", "Charging and discharging", \
                                                 "这是充放电，一共有两项可选：充电(Charge)，放电(Discharge)，根据此处选择决定是充电还是放电，当控制功率方式选择恒功率(CP_P)时，此项可调\nThis is Charge and Discharge, and there are two options: charge(Charge) and discharge(Discharge). Charge or discharge can be determined according to the choice here. When the power control mode is Constant power(CP_P), this option can be adjusted.");
    Charging_and_discharging->add_Specifition();

    Work_mode = new Specification(this,Work_mode_explain, ui->System_Tab, 3, 1, \
                                  "Manual", "Work mode", \
                                  "这是工作模式，有四项可选：手动(Manual)，UPS(UPS)，削峰填谷(Peak valley)，受控制削峰填谷(Prevent countercurrnet)\n手动模式时，充放电由自主手动决定\n削峰填谷模式时，用电高峰时优先使用电池给负载供电，用电低谷时优先给电池充电\nUPS模式时，将为负载不间断地提供稳定电源\n受控削峰填谷模式时，对系统防逆流，一般配合电表一起使用\nThis is the working mode, with four options: Manual(Manual), UPS(UPS), Peak valley(Peak valley), Prevent countercurrnet(Prevent countercurrnet).\n Manual mode, charge and discharge are determined manually. \n In peak valley mode, the battery is preferred to supply power to the load during peak demand. When the power is low, the battery will be charged first \nUPS mode will provide a stable power supply for the load without interruption \n controlled peak peak and trough mode (Prevent countercurrnet) will prevent the system from countercurrent, generally used with the meter.");
    Work_mode->add_Specifition();

    Output_power_factor = new Specification(this,Output_power_factor_explain, ui->System_Tab, 4, 1, \
                                            "1", "Output power factor", \
                                            "这是输出功率因数，是用来衡量电气设备输出效率高低的一个系数，不可调\nThis is the power output factor");
    Output_power_factor->add_Specifition();

    Output_reactive_power = new Specification(this,Output_reactive_power_explain, ui->System_Tab, 5, 1, \
                                              "1", "Output reactive power", \
                                              "这是输出无功功率，它表达了输出交流电源能量与磁场或电场能量交换的最大速率，不可调\nThis is the output reactive power");
    Output_reactive_power->add_Specifition();

    Constant_current = new Specification(this,Constant_current_explain, ui->System_Tab, 6, 1, \
                                         "100", "Constant current", \
                                         "这是恒流值，当控制功率方式选择恒流(CC)时，此项可调，电流值稳定为此值\nThis is the constant current value");
    Constant_current->add_Specifition();

    Constant_voltage = new Specification(this,Constant_voltage_explain, ui->System_Tab, 7, 1, \
                                         "600", "Constant voltage", \
                                         "这是恒压值，当控制功率方式选择恒压(CV)时，此项可调，电压值稳定为此值\nThis is constant pressure");
    Constant_voltage->add_Specifition();

    Control_mode = new Specification(this,Control_mode_explain, ui->System_Tab, 0, 4, \
                                     "Local", "Control mode", \
                                     "这是工作模式，有两项可选：本地(Local)，远程(Remote)，选择'本地'时，可在本地修改系统参数，选择'远程'时，可通过EMS、485等进行远程修改参数\nThis is the working mode, with two options: Local and Remote");
    Control_mode->add_Specifition();

    Machine_number = new Specification(this,Machine_number_explain, ui->System_Tab, 1, 4, \
                                       "Master_00", "Machine number", \
                                       "这是设备号，可以选择主机或者从机，其中主机为Master_00，其余八项Slave_01~Slave_08均为从机\nThis is the device number. You can choose the host or slave. The host has one option(Master_00) and the slave has nine options");
    Machine_number->add_Specifition();

    Parallel = new Specification(this,Parallel_explain, ui->System_Tab, 2, 4, \
                                 "Disable", "Parallel", \
                                 "这是并机，有两项可选：使能，禁止，开启并机时，可将多台设备联合到一起为负载供电\nThis is parallel, with two options: Enable and Disable");
    Parallel->add_Specifition();

    Unbalance_power_enable = new Specification(this,Unbalance_power_enable_explain, ui->System_Tab, 3, 4, \
                                               "Disable", "Unbalance power enable", \
                                               "这是功率不平衡使能，有两项可选：使能，禁止，功率不平衡是指三相电流与电压之间的相位差不相等，平均功率不为0导致的功率偏差，使能后将使功率维持平衡\nThis is to enable power imbalance, with two options: Enable and Disable");
    Unbalance_power_enable->add_Specifition();

    Phase_A_power = new Specification(this,Phase_A_power_explain, ui->System_Tab, 4, 4, \
                                      "5", "Phase A power", \
                                      "这是A相功率，此处可设置A相的功率\nThis is Phase A power");
    Phase_A_power->add_Specifition();

    Phase_B_power = new Specification(this,Phase_B_power_explain, ui->System_Tab, 5, 4, \
                                      "5", "Phase B power", \
                                      "这是B相功率，此处可设置B相的功率\nhis is Phase B power");
    Phase_B_power->add_Specifition();

    Phase_C_power = new Specification(this,Phase_C_power_explain, ui->System_Tab, 6, 4, \
                                      "5", "Phase C power", \
                                      "这是C相功率，此处可设置C相的功率\nThis is Phase C power");
    Phase_C_power->add_Specifition();

}

void MEGAWin::BetterySetup()//电池设置 绘制button
{
    DOD_OnGrid = new Specification(this,DOD_OnGrid_explain, ui->Lithum_Tab, 0, 1, \
                                     "80", "DOD_OnGrid", \
                                     "并网工况下电池的放电深度，默认90\nThe default discharge depth of the battery in grid-connected condition is 90.");
    DOD_OnGrid->add_Specifition();
    DOD_OffGrid = new Specification(this,DOD_OffGrid_explain, ui->Lithum_Tab, 1, 1, \
                                     "80", "DOD_OffGrid", \
                                     "离网工况下电池的放电深度，默认90\nThe default discharge depth of the battery in off-grid mode is 90.");
    DOD_OffGrid->add_Specifition();
    Charge_Vol_Up_Limit = new Specification(this,Charge_Vol_Up_Limit_explain, ui->Lithum_Tab, 2, 1, \
                                     "792", "Charge_Vol_Up_Limit", \
                                     "充电时电池电压所允许达到的最大值\nThe maximum allowable battery voltage during charging.");
    Charge_Vol_Up_Limit->add_Specifition();
    Disc_Vol_lower_Limit = new Specification(this,Disc_Vol_lower_Limit_explain, ui->Lithum_Tab, 3, 1, \
                                     "616", "Disc_Vol_lower_Limit", \
                                     "放电时电池电压所允许的最小值\nThe minimum allowable battery voltage when discharging.");
    Disc_Vol_lower_Limit->add_Specifition();
    Charge_Cur_Limit = new Specification(this,Charge_Cur_Limit_explain, ui->Lithum_Tab, 4, 1, \
                                     "160", "Charge_Cur_Limit", \
                                     "允许的最大充电电流\nThe maximum allowable charging current.");
    Charge_Cur_Limit->add_Specifition();
    Gen_turn_off_SOC = new Specification(this,Gen_turn_off_SOC_explain, ui->Lithum_Tab, 5, 1, \
                                     "85", "Gen_turn_off_SOC", \
                                     "达到指定SCO值时，柴油发电机关闭\nWhen the specified SCO value is reached, the diesel generator shuts down.");
    Gen_turn_off_SOC->add_Specifition();
    Gen_turn_on_SOC = new Specification(this,Gen_turn_on_SOC_explain, ui->Lithum_Tab, 6, 1, \
                                     "25", "Gen_turn_on_SOC", \
                                     "达到指定SOC值时，柴油发电机开启\nWhen the specified SOC value is reached, the diesel generator starts.");
    Gen_turn_on_SOC->add_Specifition();
    Gen_charge_SOC = new Specification(this,Gen_charge_SOC_explain, ui->Lithum_Tab, 7, 1, \
                                     "10", "Gen_charge_SOC", \
                                     "达到指定SOC值时，柴油发电机开始充电\nWhen the specified SOC value is reached, the diesel generator starts charging.");
    Gen_charge_SOC->add_Specifition();
    Grid_charge_SOC = new Specification(this,Grid_charge_SOC_explain, ui->Lithum_Tab, 8, 1, \
                                     "15", "Grid_charge_SOC", \
                                     "到达指定SOC值时，开始电网充电\nWhen the specified SOC value is reached, grid charging begins.");
    Grid_charge_SOC->add_Specifition();
    Grid_capacity = new Specification(this,Grid_capacity_explain, ui->Lithum_Tab, 9, 1, \
                                     "150", "Grid_capacity", \
                                     "电网容量，电网允许带的总负荷\nThe capacity of the grid, the total load allowed on the grid.");
    Grid_capacity->add_Specifition();
    Turn_on_SOC = new Specification(this,Turn_on_SOC_explain, ui->Lithum_Tab, 0, 4, \
                                     "20", "Turn_on_SOC", \
                                     "当电池剩余电量百分比达到此值时开始充电\nCharging begins when the percentage of remaining battery capacity reaches this value.");
    Turn_on_SOC->add_Specifition();
    Turn_off_SOC = new Specification(this,Turn_off_SOC_explain, ui->Lithum_Tab, 1, 4, \
                                     "50", "Turn_off_SOC", \
                                     "当电池剩余电量百分比达到此值时停止充电\nStop charging when the percentage of remaining battery power reaches this value.");
    Turn_off_SOC->add_Specifition();
    Turn_on_cell_vol = new Specification(this,Turn_on_cell_vol_explain, ui->Lithum_Tab, 2, 4, \
                                     "3100", "Turn_on_cell_vol", \
                                     "所有单体中的最高电压达到此值时开始充电\nCharge begins when the highest voltage in all cells reaches this value.");
    Turn_on_cell_vol->add_Specifition();
    Turn_off_cell_vol = new Specification(this,Turn_off_cell_vol_explain, ui->Lithum_Tab, 3, 4, \
                                     "3500", "Turn_off_cell_vol", \
                                     "所有单体中的最高电压达到此值时停止充电\nThe highest voltage in all cells stops charging when it reaches this value.");
    Turn_off_cell_vol->add_Specifition();
    Turn_on_total_vol = new Specification(this,Turn_on_total_vol_explain, ui->Lithum_Tab, 4, 4, \
                                     "400", "Turn_on_total_vol", \
                                     "当电池电压达到此值时开始充电\nCharge begins when the battery voltage reaches this value.");
    Turn_on_total_vol->add_Specifition();
    Turn_off_total_vol = new Specification(this,Turn_off_total_vol_explain, ui->Lithum_Tab, 5, 4, \
                                     "650", "Turn_off_total_vol", \
                                     "当电池电压达到此值时停止充电\nStop charging when the battery voltage reaches this value.");
    Turn_off_total_vol->add_Specifition();
    UPS_charge_power = new Specification(this,UPS_charge_power_explain, ui->Lithum_Tab, 6, 4, \
                                     "-1", "UPS_charge_power", \
                                     "工作模式为后备模式时的充电功率\nThe charging power when the working mode is backup mode.");
    UPS_charge_power->add_Specifition();
    Monthly_cycle_time = new Specification(this,Monthly_cycle_time_explain, ui->Lithum_Tab, 7, 4, \
                                     "0", "Monthly_cycle_time", \
                                     "当每月到达这一天都会进行一次充放电循环\nA charge-discharge cycle is performed once a month on that date.");
    Monthly_cycle_time->add_Specifition();
}

void MEGAWin::AutoOperation()//自动运行 绘制button
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
        temp[i]->add_Specifition();
        temp4[i] = new Specification(this,temp5[i], ui->Time_tableWidget, i, 1, \
                                                temp16, temp6, \
                                                "这是开始时间，将在此时间开始工作\nThis is the start time at which work will begin");
        temp4[i]->add_Specifition();
        temp7[i] = new Specification(this,temp8[i], ui->Time_tableWidget, i, 2, \
                                                temp17, temp9, \
                                                "这是结束时间，将在此时间结束工作\nWill finish work at this time.");
        temp7[i]->add_Specifition();

        if(i%2==0)
        {
            temp10[i] = new Specification(this,temp11[i], ui->Time_tableWidget, i, 3, \
                                                    "charge", temp12, \
                                                    "这是状态，将在工作时间执行此状态，有三种可供选择，分别为充电(charge)、放电(discharge)、自动(Automatic)\nThis is the state, which will be executed during working hours.  There are three options: charge（charge）, discharge（discharge）, and Automatic（Automatic）.");
            temp10[i]->add_Specifition();
            temp13[i] = new Specification(this,temp14[i], ui->Time_tableWidget, i, 4, \
                                                    "-100", temp15, \
                                                    "这是工作功率，此状态下工作时根据工作状态执行此功率\nThis is the working power, which is executed according to the working state when working in this state.");
            temp13[i]->add_Specifition();
        }
        else
        {
            temp10[i] = new Specification(this,temp11[i], ui->Time_tableWidget, i, 3, \
                                                    "discharge", temp12, \
                                                    "这是状态，将在工作时间执行此状态，有三种可供选择，分别为充电(charge)、放电(discharge)、自动(Automatic)\nThis is the state, which will be executed during working hours.  There are three options: charge（charge）, discharge（discharge）, and Automatic（Automatic）.");
            temp10[i]->add_Specifition();
            temp13[i] = new Specification(this,temp14[i], ui->Time_tableWidget, i, 4, \
                                                    "100", temp15, \
                                                    "这是工作功率，此状态下工作时根据工作状态执行此功率\nThis is the working power, which is executed according to the working state when working in this state");
            temp13[i]->add_Specifition();
        }
    }

}

void MEGAWin::SystemMessages()//系统信息 绘制button
{
    Manufacturer_name = new Specification(this,Manufacturer_name_explain, ui->EquipmentInfor_tableWidget, 0, 1, \
                                     "PCS", "Manufacturer name", \
                                     "这是厂家名称\nThis is the name of the manufacturer.");
    Manufacturer_name->add_Specifition();
    MonitoringVersion = new Specification(this,MonitoringVersion_explain, ui->EquipmentInfor_tableWidget, 1, 1, \
                                     "V103B500D004", "Monitoring software version", \
                                     "这是监控版本\nThis is the name of the manufacturer.");
    MonitoringVersion->add_Specifition();
    SysProtocol_Version = new Specification(this,SysProtocol_Version_explain, ui->EquipmentInfor_tableWidget, 2, 1, \
                                     "V001B001D001", "Manufacturer name", \
                                     "这是协议版本号\nThis is the name of the manufacturer.");
    SysProtocol_Version->add_Specifition();
    ConverterVersion = new Specification(this,ConverterVersion_explain, ui->EquipmentInfor_tableWidget, 3, 1, \
                                     "V105B500D008", "Manufacturer name", \
                                     "这是变流器软件版本\nThis is the name of the manufacturer.");
    ConverterVersion->add_Specifition();
    CPLD_Version = new Specification(this,CPLD_Version_explain, ui->EquipmentInfor_tableWidget, 4, 1, \
                                     "V001B001D000", "Manufacturer name", \
                                     "这是CPLD软件版本\nThis is the name of the manufacturer.");
    CPLD_Version->add_Specifition();
    SN = new Specification(this,SN_explain, ui->EquipmentInfor_tableWidget, 5, 1, \
                                     "F12200000001", "Manufacturer name", \
                                     "这是SN,即产品序列号\nThis is the name of the manufacturer.");
    SN->add_Specifition();
}

void MEGAWin::FunctionSet()//功能设置绘制button
{
    Battery_type = new Specification(this,Battery_type_explain, ui->UI_Parameter_Tab, 0, 1, \
                                     "Lithium", "Battery_type", \
                                     "根据实际情况选择电池类型，有锂电(Lithium)和铅酸(LeadAcid)两种类型可供选择\n Choose the battery type according to the actual situation, there are two types of lithium(Lithium) and lead acid(LeadAcid) to choose from.");
    Battery_type->add_Specifition();
    BMS_Comm_type = new Specification(this,BMS_Comm_type_explain, ui->UI_Parameter_Tab, 1, 1, \
                                      "CAN", "BMS_Comm_type", \
                                      "设置与电池之间的通信方式，可根据情况选择RS485(RS485)或CAN通信(CAN)或以太网(Ethernet)\nSet the communication mode between the battery, RS485(RS485) or CAN communication(CAN) or Ethernet(Ethernet) can be selected according to the situation.");
    BMS_Comm_type->add_Specifition();
    Power_control_type = new Specification(this,Power_control_type_explain, ui->UI_Parameter_Tab, 2, 1,\
                                           "CP_N&&P" , "Power_control_type", \
                                           "设置控制功率的方式，有恒压(CV)、恒流(CC)、恒功率(CP_P)、正负功率(CP_N&P)\nSet the control power mode, constant voltage(CV), constant current(CC), constant power(CP_P), positive and negative power(CP_N&P).");
    Power_control_type->add_Specifition();
    EMS_Comm_type = new Specification(this,EMS_Comm_type_explain, ui->UI_Parameter_Tab, 3, 1, \
                                      "RS485", "EMS_Comm_type", \
                                      "设置EMS的通信方式，有RS485(RS485),CAN通信(CAN)，以太网(Ethernet)三种方式\nSetting the communication mode of EMS, there are RS485(RS485),CAN communication (CAN) and Ethernet(Ethernet).");
    EMS_Comm_type->add_Specifition();
    Output_power_limit = new Specification(this,Output_power_limit_explain, ui->UI_Parameter_Tab, 4, 1,\
                                           "100", "Output_power_limit", \
                                           "设置允许输出的功率最大值\nSet the maximum power output allowed.");
    Output_power_limit->add_Specifition();
    BAT_manufacturers = new Specification(this,BAT_manufacturers_explain, ui->UI_Parameter_Tab, 5, 1, \
                                          "GAOTE", "BAT_manufacturers", \
                                          "这是电池厂家，根据选择的电池厂家解析报文\nThis is the battery manufacturer and the packet is parsed according to the selected battery manufacturer.");
    BAT_manufacturers->add_Specifition();
    Power_Delta = new Specification(this,Power_Delta_explain, ui->UI_Parameter_Tab, 6, 1, \
                                    "10", "Power_Delta", \
                                    "设置功率回差，默认功率回差为10kw\nSet the power back difference, and the default power back difference is 10kw.");
    Power_Delta->add_Specifition();
    Charge_power_limit = new Specification(this,Charge_power_limit_explain, ui->UI_Parameter_Tab, 7, 1, \
                                           "100", "Charge_power_limit",\
                                           "设置充电功率限制,可以限制充电功率\nSet the charging power limit, which can limit the charging power.");
    Charge_power_limit->add_Specifition();
    Discharge_power_limit = new Specification(this,Discharge_power_limit_explain, ui->UI_Parameter_Tab, 8, 1, \
                                              "100", "Charge_power_limit", \
                                              "设置放电功率限制，可以限制放电功率\nYou can set discharge power limit to limit the discharge power.");
    Discharge_power_limit->add_Specifition();
    Charge_Vol_upper_Limit_delta = new Specification(this,Charge_Vol_upper_Limit_delta_explain, ui->UI_Parameter_Tab, 9, 1, \
                                                     "10", "Charge_Vol_upper_Limit_delta", \
                                                     "设置充电电压上限回差，默认充电电压上限为10kw\nThe upper limit of charging voltage return difference is set, and the default charging voltage upper limit is 10kw.");
    Charge_Vol_upper_Limit_delta->add_Specifition();
    Discharge_Vol_lower_Limit_delta = new Specification(this,Discharge_Vol_lower_Limit_delta_explain, ui->UI_Parameter_Tab, 10, 1,\
                                                        "10", "Discharge_Vol_lower_Limit_delta", \
                                                        "设置放电电压下限回差，默认放电电压下限回差为10kw\nSet the discharge voltage lower limit back difference, the default discharge voltage lower limit back difference is 10kw.");
    Discharge_Vol_lower_Limit_delta->add_Specifition();
    Host_Address = new Specification(this,Host_Address_explain, ui->UI_Parameter_Tab, 0, 4,\
                                     "20", "Host_Address", \
                                     "设置主机地址\nSet host address.");
    Host_Address->add_Specifition();
    serial_port_1 = new Specification(this,serial_port_1_explain, ui->UI_Parameter_Tab, 1, 4, \
                                      "9600", "serial_port_1", \
                                      "这是串口1，设置波特率，有六项可供选择，分别是1200、2400、4800、9600、19200、38400，串口1默认波特率是9600bps\nThis is serial port 1, set the baud rate, there are six options to choose from, which are 1200, 2400, 4800, 9600, 19200, 38400, and the default baud rate of serial port 1 is 9600bps.");
    serial_port_1->add_Specifition();
    serial_port_2 = new Specification(this,serial_port_2_explain, ui->UI_Parameter_Tab, 2, 4, \
                                      "9600", "serial_port_2", \
                                      "这是串口2，设置波特率，有六项可供选择，分别是1200、2400、4800、9600、19200、38400，串口2默认波特率是9600bps\nThis is serial port 2, set the baud rate, there are six options to choose from, which are 1200, 2400, 4800, 9600, 19200, 38400, and the default baud rate of serial port 2 is 9600bps");
    serial_port_2->add_Specifition();
    serial_port_3 = new Specification(this,serial_port_3_explain, ui->UI_Parameter_Tab, 3, 4, \
                                      "9600", "serial_port_3", \
                                      "这是串口3，设置波特率，有六项可供选择，分别是1200、2400、4800、9600、19200、38400，串口3默认波特率是9600bps\nThis is serial port 3, set the baud rate, there are six options to choose from, which are 1200, 2400, 4800, 9600, 19200, 38400, and the default baud rate of serial port 3 is 9600bps.");
    serial_port_3->add_Specifition();
    serial_port_4 = new Specification(this,serial_port_4_explain, ui->UI_Parameter_Tab, 4, 4, \
                                      "9600", "serial_port_4", \
                                      "这是串口4，设置波特率，有六项可供选择，分别是1200、2400、4800、9600、19200、38400，串口4默认波特率是9600bps\nThis is serial port 4, set the baud rate, there are six options to choose from, which are 1200, 2400, 4800, 9600, 19200, 38400, and the default baud rate of serial port 4 is 9600bps.");
    serial_port_4->add_Specifition();
    serial_port_5 = new Specification(this,serial_port_5_explain, ui->UI_Parameter_Tab, 5, 4, \
                                      "9600", "serial_port_5", \
                                      "这是串口5，设置波特率，有六项可供选择，分别是1200、2400、4800、9600、19200、38400，串口5默认波特率是9600bps\nThis is serial port 5, set the baud rate, there are six options to choose from, which are 1200, 2400, 4800, 9600, 19200, 38400, and the default baud rate of serial port 5 is 9600bps.");
    serial_port_5->add_Specifition();

    Can_port_1 = new Specification(this,Can_port_1_explain, ui->UI_Parameter_Tab, 6, 4, \
                                   "500", "Can_port_1", \
                                   "这是CAN1端口，PCS内部通讯的波特率，默认波特率500，无需更改\nThis is the baud rate of CAN1 port and PCS internal communication. The default baud rate is 500, which need not be changed.");
    Can_port_1->add_Specifition();
    Can_port_2 = new Specification(this,Can_port_2_explain, ui->UI_Parameter_Tab, 7, 4, \
                                   "250", "Can_port_2", \
                                   "这是CAN2端口，PCS与BMS通信的波特率，默认波特率125，根据现场BMS通信波特率进行修改，其中有五项可供选择，分别是100、125、250、500、800\nThis is the baud rate of the CAN2 port and the communication between PCS and BMS. The default baud rate is 125, which is modified according to the on-site BMS communication baud rate. There are five items to choose from, which are 100, 125, 250, 500 and 800 respectively.");
    Can_port_2->add_Specifition();
    ProtocolVersion = new Specification(this,ProtocolVersion_explain, ui->UI_Parameter_Tab, 0, 7, \
                                        "5612", "ProtocolVersion", \
                                        "这是协议版本号，用于查看当前协议版本\nThis is the protocol version number used to see the current protocol version.");
    ProtocolVersion->add_Specifition();
    UserPassPort = new Specification(this,UserPassPort_explain, ui->UI_Parameter_Tab, 1, 7, \
                                     "123456", "UserPassPort", \
                                     "这是用户密码，可供重新设置用户密码，默认用户密码123456\nThis is the user password, you can reset the user password, the default user password 123456.");
    UserPassPort->add_Specifition();
    RootPassport = new Specification(this,RootPassport_explain, ui->UI_Parameter_Tab, 2, 7,\
                                     "888888", "RootPassport", \
                                     "这是超级权限密码，可供重新设置超级权限密码，默认超级权限密码888888\nThis is the super privilege password. You can reset the super privilege password. The default super privilege password is 888888.");
    RootPassport->add_Specifition();
    Language = new Specification(this,Language_explain, ui->UI_Parameter_Tab, 3, 7, \
                                 "English", "Language", \
                                 "设置显示屏的显示语言，可供选择为中文与英文，切换语言时系统会重启\nSet the display language of the display screen, which can be selected as Chinese and English. The system will restart when switching languages.");
    Language->add_Specifition();
    System_upgrade = new Specification(this,System_upgrade_explain, ui->UI_Parameter_Tab, 4, 7, \
                                       "upgrade", "System_upgrade", \
                                       "点击即可进入系统升级应用程序，根据升级文档进行系统升级\nClick to enter the system upgrade application and upgrade the system according to the upgrade document.");
    System_upgrade->add_Specifition();
    Sounds = new Specification(this,Sounds_explain, ui->UI_Parameter_Tab, 5, 7, \
                               "Allow", "Sounds", \
                               "设置显示屏是否开启声音，可供选择为允许(Allow)、禁止(forbid)\nSet whether the display is enabled sound, which can be allowed(Allow) or prohibited(forbid).");
    Sounds->add_Specifition();
    DryContact = new Specification(this,DryContact_explain, ui->UI_Parameter_Tab, 6, 7, \
                                   "forbid", "DryContact", \
                                   "根据项目现场配置干接点功能，可供选择为允许(Allow)、禁止(forbid)\nAccording to the project site configuration dry contact function, can be selected as allowed(Allow), prohibited(forbid).");
    DryContact->add_Specifition();
}

void MEGAWin::SystemParameter()//系统参数 绘制button
{
    Change_rate_of_power = new Specification(this,Change_rate_of_power_explain, ui->UI_SystemParameter_Tab, 0, 1, \
                                             "20", "Change_rate_of_power", \
                                             "功率变化率是与额定功率相比功率变化的大小\nPower change ratio is the magnitude of the power change compared to the rated power.");
    Change_rate_of_power->add_Specifition();
    Grid_frequency_upper_limit = new Specification(this,Grid_frequency_upper_limit_explain, ui->UI_SystemParameter_Tab, 1, 1, \
                                                   "3", "Grid_frequency_upper_limit", \
                                                   "电网频率允许超出额定频率的上限,可供选择为0.2、0.5、1、3\nThe grid frequency is allowed to exceed the upper limit of the rated frequency, which can be selected as 0.2, 0.5, 1, and 3.");
    Grid_frequency_upper_limit->add_Specifition();
    Grid_frequency_lower_limit = new Specification(this,Grid_frequency_lower_limit_explain, ui->UI_SystemParameter_Tab, 2, 1, \
                                                   "-3", "Grid_frequency_lower_limit", \
                                                   "电网频率允许小于额定频率的下限,可供选择为-0.5、-1、-2、-3\nThe grid frequency is allowed to be less than the lower limit of the rated frequency, which can be selected as -0.5, -1, -2, -3.");
    Grid_frequency_lower_limit->add_Specifition();
    Vol_protection_upper_limit = new Specification(this,Vol_protection_upper_limit_explain, ui->UI_SystemParameter_Tab, 3, 1, \
                                                   "+15", "Vol_protection_upper_limit", \
                                                   "会进行断电保护的电压最大值,可供选择为+10、+15、+20、+30\nThe maximum voltage for power outage protection can be selected as +10, +15, +20, +30.");
    Vol_protection_upper_limit->add_Specifition();
    Vol_protection_lower_limit = new Specification(this,Vol_protection_lower_limit_explain, ui->UI_SystemParameter_Tab, 4, 1, \
                                                   "-15", "Vol_protection_lower_limit", \
                                                   "会进行断电保护的电压最小值,可供选择为-10、-15、-20、-30\nThe minimum voltage for power outage protection can be selected as -10, -15, -20, -30.");
    Vol_protection_lower_limit->add_Specifition();
    HVRT_enable = new Specification(this,HVRT_enable_explain, ui->UI_SystemParameter_Tab, 5, 1, \
                                                    "prohibit", "HVRT_enable", \
                                                    "高压穿越使能,使高压也能穿越，在一定时间内高压不会关机,可供选择为允许(Allow)、禁止(forbid)\nEnable the high voltage pass through, so that the high voltage can also pass through, and the high voltage will not shut down within a certain time. The options are Allow (Allow), forbid (forbid).");
    HVRT_enable->add_Specifition();
    LVRT_enable = new Specification(this,LVRT_enable_explain, ui->UI_SystemParameter_Tab, 6, 1, \
                                    "prohibit", "LVRT_enable", \
                                    "低压穿越使能，使低压也能穿越，在一定时间内低压不会关机,可供选择为允许(Allow)、禁止(forbid)\nEnable the low-voltage pass through, so that the low-voltage can also pass through, and the low-voltage will not shut down within a certain period of time. The options are Allow(Allow),, forbid(forbid).");
    LVRT_enable->add_Specifition();
    AFD_enable = new Specification(this,AFD_enable_explain, ui->UI_SystemParameter_Tab, 7, 1, \
                                   "prohibit", "AFD_enable", \
                                   "    防止孤岛效应，当检测出现孤岛效应(在光伏并网系统中,当大电网出现停电事故时,光伏并网逆变器发电与电网低压侧本地负载如果刚好出现功率相匹配时,容易出现自给自足的维持发电状态,从而出现""孤岛""现象,从而危及检修人员安全)时,让逆变器自动停机,可供选择为允许(Allow)、禁止(forbid)\nPrevent island effect, When the detection of island effect (in the photovoltaic grid-connected system, when the power failure accident occurs in the large power grid, photovoltaic grid-connected inverter power generation and the local load on the low voltage side of the grid if there is just a power match, it is easy to self-contained maintenance power state, resulting in the phenomenon of ""island"", thereby endangering the safety of maintenance personnel), let the inverter automatic shutdown, optional Permit(Allow) and forbid(forbid).");
    AFD_enable->add_Specifition();
    Insulation_detection_enable = new Specification(this,Insulation_detection_enable_explain, ui->UI_SystemParameter_Tab, 8, 1, \
                                                    "prohibit", "Insulation_detection_enable", \
                                                    "   绝缘检测使能，绝缘电阻大于33KΩ要能正常起机运行，小于33KΩ不能起机，并且要告警，默认禁止,可供选择为允许(Allow)、禁止(forbid)\nEnable insulation detection. If the insulation resistance is greater than 33KΩ, the machine can start normally; if the insulation resistance is smaller than 33KΩ, the machine cannot start, and the alarm should be generated. By default, it is prohibited, which can be selected as Allow(Allow) or forbid(forbid).");
    Insulation_detection_enable->add_Specifition();
    PrimaryFreq_enable = new Specification(this,PrimaryFreq_enable_explain, ui->UI_SystemParameter_Tab, 9, 1, \
                                           "prohibit", "PrimaryFreq_enable", \
                                           "    一次调频使能,电网的频率偏离额定值时，通过控制有功功率的增减使电网频率维持稳定，可供选择为允许(Allow)、禁止(forbid)\nWhen the frequency of the power grid deviates from the rated value, the frequency of the power grid can be maintained stable by controlling the increase or decrease of the active power. The alternatives are Allow(Allow) and forbid(forbid).");
    PrimaryFreq_enable->add_Specifition();
    Inertia_enable = new Specification(this,Inertia_enable_explain, ui->UI_SystemParameter_Tab, 10, 1, \
                                       "prohibit", "Inertia_enable", \
                                       "转动惯量使能,在电力系统稳定性计算中加入转动惯量，可供选择为允许(Allow)、禁止(forbid)\nEnable the moment of inertia. Add the moment of inertia to the stability calculation of the power system. The options are Allow(Allow) and forbid(forbid).");
    Inertia_enable->add_Specifition();

    CV_parallel = new Specification(this,CV_parallel_explain, ui->UI_SystemParameter_Tab, 11, 1, \
                                    "prohibit", "CV_parallel", \
                                    "恒压并机使能,可供选择为允许(Allow)、禁止(forbid)\nAllow (Allow) forbid (forbid) Enable the constant voltage parallel machine.");
    CV_parallel->add_Specifition();

    Machine_type = new Specification(this,Machine_type_explain, ui->UI_SystemParameter_Tab, 0, 4, \
                                     "PCS-TS", "Machine_type", \
                                     "根据现场机器机器型号设置，以出厂值为准,可供选择为PCS、PCS-T、PCS-TS、PCS-TS-T\nSet according to the machine model and factory value. PCS, PCs-T, PCS-TS, and PCS-TS-T can be selected.");
    Machine_type->add_Specifition();
    Machine_capacity = new Specification(this,Machine_capacity_explain, ui->UI_SystemParameter_Tab, 1, 4, \
                                     "100", "Machine_capacity", \
                                     "PCS的额定容量，以出厂值为准，不可随意更改\nThe rated capacity of PCS is subject to the factory value and cannot be changed at will.");
    Machine_capacity->add_Specifition();
    Output_Fre_grade = new Specification(this,Output_Fre_grade_explain, ui->UI_SystemParameter_Tab, 2, 4, \
                                         "50", "Output_Fre_grade", \
                                         "设置输出频率的等级，一般默认50HZ，根据项目地可更改为60Hz\nSet the output frequency level. The default frequency is 50HZ, but it can be changed to 60Hz according to the project.");
    Output_Fre_grade->add_Specifition();
    Output_vol_level = new Specification(this,Output_vol_level_explain, ui->UI_SystemParameter_Tab, 3, 4, \
                                         "400", "Output_vol_level", \
                                         "电压等级是通过变压器后输出的电压等级，要根据变压器的变比来设置，以出厂默认值为准，不可更改\nVoltage level is the output voltage level through the transformer, according to the transformer ratio to set, to the factory default value prevail, can not be changed.");
    Output_vol_level->add_Specifition();
    Converter_side_vol_level = new Specification(this,Converter_side_vol_level_explain, ui->UI_SystemParameter_Tab, 4, 4, \
                                         "270:400", "Converter_side_vol_level", \
                                         "逆变电压等级是逆变器逆变出来的电压等级，要根据变压器来设置，以出厂默认值为准，不可随意更改，可供更改选择为1:1、60:400、100:400、200:400、270:400、315:400、315:480\n");
    Converter_side_vol_level->add_Specifition();
    Output_reactive_power_mode = new Specification(this,Output_reactive_power_mode_explain, ui->UI_SystemParameter_Tab, 5, 4, \
                                         "Non adjustab", "Output_reactive_power_mode", \
                                         "输出无功方式，默认不可调节，可供选择为功率因数(PF)、无功功率(Q)、不可调节(Non adjustable)\nadjustable output reactive power mode, adjustable by default, adjustable power factor (PF), adjustable power (Q), Non adjustable(Non adjustable).");
    Output_reactive_power_mode->add_Specifition();
    Grid_connected_mode_of_Inv = new Specification(this,Grid_connected_mode_of_Inv_explain, ui->UI_SystemParameter_Tab, 6, 4, \
                                                   "Non counterc", "Grid_connected_mode_of_Inv", \
                                                   "设置逆变器的并网方式，可逆流即光伏发电转换成交流电后可以并入电网；不可逆则是光伏发电的电流不会流向电网。默认可逆流，可供选择为可逆流(Counterc)、不可逆流(Non counterc)\nThe grid-connected mode of the inverter can be countercurrent, that is, photovoltaic power generation can be converted into alternating current, which can be incorporated into the power grid; Irreversible means that photovoltaic electricity does not flow to the grid. Countercurrent is available by default. The options are Counterc(Counterc) and Non counterc(Non counterc).");
    Grid_connected_mode_of_Inv->add_Specifition();
    Primary_FM_dead_zone = new Specification(this,Primary_FM_dead_zone_explain, ui->UI_SystemParameter_Tab, 7, 4, \
                                             "3", "Primary_FM_dead_zone", \
                                             "一次调频死区为了防止在电网频差小范围变化时调门不必要的动作而设置的频差\nPrimary frequency modulation dead zone A frequency difference set to prevent unwanted switch action when the network frequency difference varies in a small range.");
    Primary_FM_dead_zone->add_Specifition();
    PFM_coeff = new Specification(this,PFM_coeff_explain, ui->UI_SystemParameter_Tab, 8, 4, \
                                  "20", "PFM_coeff", \
                                  "设置有功调频系数\nSet the active power frequency modulation coefficient.");
    PFM_coeff->add_Specifition();
    Grid_recover_time = new Specification(this,Grid_recover_time_explain, ui->UI_SystemParameter_Tab, 9, 4, \
                                          "10", "Grid_recover_time", \
                                          "电网恢复并网时间：预留功能，设置无效\nGrid restoration time: reserved function, setting invalid.");
    Grid_recover_time->add_Specifition();
    DynamicCap = new Specification(this,DynamicCap_explain, ui->UI_SystemParameter_Tab, 10, 4, \
                                   "9600", "DynamicCap", \
                                   "电网扩容使能,当负载在短时间内所需功率大于电网容量时，可暂时从电池辅助供电以达到功率要求，可供选择为允许(Allow)、禁止(forbid)\nEnable the power network expansion. The options are Allow(Allow) and forbid(forbid).");
    DynamicCap->add_Specifition();
    Module_Number = new Specification(this,Module_Number_explain, ui->UI_SystemParameter_Tab, 0, 7, \
                                      "1", "Module_Number", \
                                      "PCS的模块数量，默认值1(无效设置)\nNumber of modules for PCS, default 1(invalid setting).");
    Module_Number->add_Specifition();
    Restore_factory = new Specification(this,Restore_factory_explain, ui->UI_SystemParameter_Tab,1, 7, \
                                        "restore", "Restore_factory", \
                                        "恢复出厂时的默认设置\nRestore the factory default Settings.");
    Restore_factory->add_Specifition();
    Clear_Data = new Specification(this,Clear_Data_explain, ui->UI_SystemParameter_Tab, 2, 7, \
                                   "Clear", "Clear_Data", \
                                   "清除系统此前的记录数据及操作数据\nClear previous recorded data and operation data of the system.");
    Clear_Data->add_Specifition();
}

void MEGAWin::Peripheral()//外设 绘制button
{
    DI_1_Enable = new Specification(this,DI_1_Enable_explain, ui->ExternalDevice_tW, 0, 0, \
                                   "Enable", "DI_1_Enable", \
                                   "输入干接点1，发生NO关机时执行动作的开关,可选功能为使能(Enable)、禁止(Disable)\nInput dry contact 1, the switch to perform the action when NO shutdown occurs. The optional functions are Enable(Enable) or Disable(Disable).");
    DI_1_Enable->add_Specifition();
    DI_2_Enable = new Specification(this,DI_2_Enable_explain, ui->ExternalDevice_tW, 1, 0, \
                                   "Disable", "DI_2_Enable", \
                                   "输入干接点2，发生NC关机时执行动作的开关，可选功能为使能(Enable)、禁止(Disable)\nEnter dry contact 2, the switch that performs the action when NC shutdown occurs.The optional functions are Enable(Enable) or Disable(Disable).");
    DI_2_Enable->add_Specifition();
    DI_3_Enable = new Specification(this,DI_3_Enable_explain, ui->ExternalDevice_tW, 2, 0, \
                                   "Enable", "DI_3_Enable", \
                                   "输入干接点3，门禁开启时执行动作的开关，可选功能为使能(Enable)、禁止(Disable)\nEnter dry contact 3. The switch that performs the action when the access control is opened.The optional functions are Enable(Enable) or Disable(Disable).");
    DI_3_Enable->add_Specifition();
    DI_4_Enable = new Specification(this,DI_4_Enable_explain, ui->ExternalDevice_tW, 3, 0, \
                                   "Enable", "DI_4_Enable", \
                                   "输入干接点4，柴发信号发出时执行动作的开关，可选功能为使能(Enable)、禁止(Disable)\nInput dry contact 4, the switch to perform the action when the firewood signal is sent.The optional functions are Enable(Enable) or Disable(Disable).");
    DI_4_Enable->add_Specifition();
    DI_5_Enable = new Specification(this,DI_5_Enable_explain, ui->ExternalDevice_tW, 4, 0, \
                                   "Enable", "DI_5_Enable", \
                                   "输入干接点5，发生水浸时执行动作的开关，可选功能为使能(Enable)、禁止(Disable)\nEnter dry contact 5, the switch that performs the action when flooding occurs.The optional functions are Enable(Enable) or Disable(Disable).");
    DI_5_Enable->add_Specifition();
    DI_6_Enable = new Specification(this,DI_6_Enable_explain, ui->ExternalDevice_tW, 5, 0, \
                                   "Enable", "DI_6_Enable", \
                                   "输入干接点6，消防信号发出时执行动作的开关，可选功能为使能(Enable)、禁止(Disable)\nInput dry contact 6, the switch to perform action when the fire signal is sent.The optional functions are Enable(Enable) or Disable(Disable).");
    DI_6_Enable->add_Specifition();
    DO_1_Enable = new Specification(this,DO_1_Enable_explain, ui->ExternalDevice_tW, 6, 0, \
                                   "Disable", "DO_1_Enable", \
                                   "输出干接点1，发电机开启时执行动作的开关，可选功能为使能(Enable)、禁止(Disable)\nOutput dry contact 1, the switch that performs the action when the generator is on.The optional functions are Enable(Enable) or Disable(Disable).");
    DO_1_Enable->add_Specifition();
    DO_2_Enable = new Specification(this,DO_2_Enable_explain, ui->ExternalDevice_tW, 7, 0, \
                                   "Disable", "DO_2_Enable", \
                                   "输出干接点2，预留功能，设置无效，可选功能为使能(Enable)、禁止(Disable)\nDry contact 2 is output. The reserved function is invalid.The optional functions are Enable(Enable) or Disable(Disable).");
    DO_2_Enable->add_Specifition();
    DO_3_Enable = new Specification(this,DO_3_Enable_explain, ui->ExternalDevice_tW, 8, 0, \
                                   "Disable", "DO_3_Enable", \
                                   "输出干接点3，预留功能，设置无效，可选功能为使能(Enable)、禁止(Disable)\nDry contact 3 is output. The reserved function is invalid.The optional functions are Enable(Enable) or Disable(Disable).");
    DO_3_Enable->add_Specifition();

    DI_1_NC_O = new Specification(this,DI_1_NC_O_explain, ui->ExternalDevice_tW, 0, 1, \
                                   "N_O", "DI_1_NC_O", \
                                   "输入干接点1，设置NO关机是常闭电路还是常开电路,可选功能为常开(N_O)常闭(N_C)\nInput dry contact 1, set NO shutdown is normally closed circuit or normally open circuit, optional function is normally open (N_O) normally closed (N_C).");
    DI_1_NC_O->add_Specifition();
    DI_2_NC_O = new Specification(this,DI_2_NC_O_explain, ui->ExternalDevice_tW, 1, 1, \
                                   "N_O", "DI_2_NC_O", \
                                   "输入干接点2，设置NC关机是常闭电路还是常开电路可选功能为常开(N_O)常闭(N_C)\nInput dry contact 2, set NC shutdown is normally closed circuit or normally open circuit Optional function is normally open (N_O) normally closed (N_C).");
    DI_2_NC_O->add_Specifition();
    DI_3_NC_O = new Specification(this,DI_3_NC_O_explain, ui->ExternalDevice_tW, 2, 1, \
                                   "N_C", "DI_3_NC_O", \
                                   "输入干接点3，设置门禁开是常闭电路还是常开电路可选功能为常开(N_O)常闭(N_C)\nInput dry contact 3, set the access control open normally closed circuit or normally open circuit Optional function: normally open (N_O) normally closed (N_C).");
    DI_3_NC_O->add_Specifition();
    DI_4_NC_O = new Specification(this,DI_4_NC_O_explain, ui->ExternalDevice_tW, 3, 1, \
                                   "N_O", "DI_4_NC_O", \
                                   "输入干接点4，设置柴发信号是常闭电路还是常开电路可选功能为常开(N_O)常闭(N_C)\nInput dry contact 4, set the firewood signal is normally closed circuit or normally open circuit Optional function is normally open (N_O) normally closed (N_C).");
    DI_4_NC_O->add_Specifition();
    DI_5_NC_O = new Specification(this,DI_5_NC_O_explain, ui->ExternalDevice_tW, 4, 1, \
                                   "N_O", "DI_5_NC_O", \
                                   "输入干接点5，设置水浸是常闭电路还是常开电路可选功能为常开(N_O)常闭(N_C)\nInput dry contact 5, set the flooding is normally closed circuit or normally open circuit Optional function is normally open (N_O) normally closed (N_C).");
    DI_5_NC_O->add_Specifition();
    DI_6_NC_O = new Specification(this,DI_6_NC_O_explain, ui->ExternalDevice_tW, 5, 1, \
                                   "N_O", "DI_6_NC_O", \
                                   "输入干接点6，设置消防是常闭电路还是常开电路可选功能为常开(N_O)常闭(N_C)\nInput dry contact 6, set fire is normally closed circuit or normally open circuit Optional function is normally open (N_O) normally closed (N_C).");
    DI_6_NC_O->add_Specifition();
    DO_1_NC_O = new Specification(this,DO_1_NC_O_explain, ui->ExternalDevice_tW, 6, 1, \
                                   "N_O", "DO_1_NC_O", \
                                   "输出干接点1，设置发电机是常闭电路还是常开电路可选功能为常开(N_O)常闭(N_C)\nOutput dry contact 1, set the generator is normally closed circuit or normally open circuit Optional function is normally open (N_O) normally closed (N_C).");
    DO_1_NC_O->add_Specifition();
    DO_2_NC_O = new Specification(this,DO_2_NC_O_explain, ui->ExternalDevice_tW, 7, 1, \
                                   "N_O", "DO_2_NC_O", \
                                   "输出干接点2，预留功能，设置无效，设置是常闭电路还是常开电路可选功能为常开(N_O)常闭(N_C)\nOutput dry contact 2, reserved function, setting invalid, setting is normally closed circuit or normally open circuit Optional function: normally open (N_O) normally closed (N_C).");
    DO_2_NC_O->add_Specifition();
    DO_3_NC_O = new Specification(this,DO_3_NC_O_explain, ui->ExternalDevice_tW, 8, 1, \
                                   "N_O", "DO_3_NC_O", \
                                   "输出干接点3，预留功能，设置无效，设置是常闭电路还是常开电路可选功能为常开(N_O)常闭(N_C)\nOutput dry contact 3, reserved function, setting invalid, setting is normally closed circuit or normally open circuit Optional function: normally open (N_O) normally closed (N_C).");
    DO_3_NC_O->add_Specifition();

    DI_1_Action = new Specification(this,DI_1_Action_explain, ui->ExternalDevice_tW, 0, 2, \
                                   "Shut down", "DI_1_Action", \
                                   "输入干接点1，发生NO关机时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\nInput dry contact 1 to perform the action when NO shutdown occurs. The optional functions are prompt(Prompt), standby(Standby), shutdown(Shut down), full standby(Full standby), empty standby(Empty standby), fault standby(Failure standby), and power grid signal(Grid singnal).");
    DI_1_Action->add_Specifition();
    DI_2_Action = new Specification(this,DI_2_Action_explain, ui->ExternalDevice_tW, 1, 2, \
                                   "Prompt", "DI_2_Action", \
                                   "输入干接点2，发生NC关机时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\nEnter dry contact 2 to perform the action when the NC is shut down.The optional functions are prompt(Prompt), standby(Standby), shutdown(Shut down), full standby(Full standby), empty standby(Empty standby), fault standby(Failure standby), and power grid signal(Grid singnal)");
    DI_2_Action->add_Specifition();
    DI_3_Action = new Specification(this,DI_3_Action_explain, ui->ExternalDevice_tW, 2, 2, \
                                   "Prompt", "DI_3_Action", \
                                   "输入干接点3，门禁打开时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\nEnter dry contact 3. The action is performed when the access control is opened.The optional functions are prompt(Prompt), standby(Standby), shutdown(Shut down), full standby(Full standby), empty standby(Empty standby), fault standby(Failure standby), and power grid signal(Grid singnal)");
    DI_3_Action->add_Specifition();
    DI_4_Action = new Specification(this,DI_4_Action_explain, ui->ExternalDevice_tW, 3, 2, \
                                   "Prompt", "DI_4_Action", \
                                   "输入干接点4，柴发信号发出时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\nInput dry contact 4, the action to be performed when the chai signal is issued.The optional functions are prompt(Prompt), standby(Standby), shutdown(Shut down), full standby(Full standby), empty standby(Empty standby), fault standby(Failure standby), and power grid signal(Grid singnal)");
    DI_4_Action->add_Specifition();
    DI_5_Action = new Specification(this,DI_5_Action_explain, ui->ExternalDevice_tW, 4, 2, \
                                   "Shut down", "DI_5_Action", \
                                   "输入干接点5，发生水浸时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\nEnter dry contact 5 to perform the action when flooding occurs.The optional functions are prompt(Prompt), standby(Standby), shutdown(Shut down), full standby(Full standby), empty standby(Empty standby), fault standby(Failure standby), and power grid signal(Grid singnal)");
    DI_5_Action->add_Specifition();
    DI_6_Action = new Specification(this,DI_6_Action_explain, ui->ExternalDevice_tW, 5, 2, \
                                   "Shut down", "DI_6_Action", \
                                   "输入干接点6，触发消防时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\nEnter dry contact 6 to trigger the fire extinguishing action.The optional functions are prompt(Prompt), standby(Standby), shutdown(Shut down), full standby(Full standby), empty standby(Empty standby), fault standby(Failure standby), and power grid signal(Grid singnal)");
    DI_6_Action->add_Specifition();
    DO_1_Action = new Specification(this,DO_1_Action_explain, ui->ExternalDevice_tW, 6, 2, \
                                   "Prompt", "DO_1_Action", \
                                   "输出干接点1，启动发电机时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\nOutput dry contact 1, the action to be performed when starting the generator.The optional functions are prompt(Prompt), standby(Standby), shutdown(Shut down), full standby(Full standby), empty standby(Empty standby), fault standby(Failure standby), and power grid signal(Grid singnal)");
    DO_1_Action->add_Specifition();
    DO_2_Action = new Specification(this,DO_2_Action_explain, ui->ExternalDevice_tW, 7, 2, \
                                   "Prompt", "DO_2_Action", \
                                   "输出干接点2，预留功能，设置无效，信号触发时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\nOutput dry contact 2, reserved function, set invalid, the action to be performed when the signal is triggered.The optional functions are prompt(Prompt), standby(Standby), shutdown(Shut down), full standby(Full standby), empty standby(Empty standby), fault standby(Failure standby), and power grid signal(Grid singnal)");
    DO_2_Action->add_Specifition();
    DO_3_Action = new Specification(this,DO_3_Action_explain, ui->ExternalDevice_tW, 8, 2, \
                                   "Prompt", "DO_3_Action", \
                                   "输出干接点3，预留功能，设置无效，信号触发时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\nDry contact 3 is output. The reserved function is invalid.The optional functions are prompt(Prompt), standby(Standby), shutdown(Shut down), full standby(Full standby), empty standby(Empty standby), fault standby(Failure standby), and power grid signal(Grid singnal)");
    DO_3_Action->add_Specifition();
}

void MEGAWin::BMS_Protect()//BMS保护 绘制button
{
    DOD_Action = new Specification(this,DOD_Action_explain, ui->BMSProtection_tW, 0, 0, \
                                   "Standby", "DOD", \
                                   "DOD保护，触发DOD保护时执行的动作，可选功能为不动作(NO action)、降功率(Power down)、待机(Standby)、关机(Shut down)\nDOD protection: Actions to be performed when DOD protection is triggered. The optional functions are NO action(NO action), Power down(Power down), Standby(Standby), Shut down(Shut down).");
    DOD_Action->add_Specifition();
    Prohibit_charging_Action = new Specification(this,Prohibit_charging_Action_explain, ui->BMSProtection_tW, 1, 0, \
                                   "Standby", "Prohibit_charging", \
                                   "触发禁充时执行的动作，可选功能为不动作(NO action)、降功率(Power down)、待机(Standby)、关机(Shut down)\naction to be performed when the charging ban is triggered. The optional functions are NO action(NO action), Power down(Power down), Standby(Standby), Shut down(Shut down).");
    Prohibit_charging_Action->add_Specifition();
    Prohibit_discharging_Action = new Specification(this,Prohibit_discharging_Action_explain, ui->BMSProtection_tW, 2, 0, \
                                   "Standby", "Prohibit_discharging", \
                                   "触发禁放时执行的动作，可选功能为不动作(NO action)、降功率(Power down)、待机(Standby)、关机(Shut down)\nThe action to be performed when a ban is triggered.The optional functions are NO action(NO action), Power down(Power down), Standby(Standby), Shut down(Shut down).");
    Prohibit_discharging_Action->add_Specifition();
    BMS_warning_Action = new Specification(this,BMS_warning_Action_explain, ui->BMSProtection_tW, 3, 0, \
                                   "NO action", "BMS_warning", \
                                   "触发BMS提示时执行的动作，可选功能为不动作(NO action)、降功率(Power down)、待机(Standby)、关机(Shut down)\nAction to be performed when a BMS prompt is triggered.The optional functions are NO action(NO action), Power down(Power down), Standby(Standby), Shut down(Shut down).");
    BMS_warning_Action->add_Specifition();
    BMS_alarm_Action = new Specification(this,BMS_alarm_Action_explain, ui->BMSProtection_tW, 4, 0, \
                                   "Standby", "BMS_alarm", \
                                   "触发BMS告警时执行的动作，可选功能为不动作(NO action)、降功率(Power down)、待机(Standby)、关机(Shut down)\nAction when a BMS alarm is triggered.The optional functions are NO action(NO action), Power down(Power down), Standby(Standby), Shut down(Shut down).");
    BMS_alarm_Action->add_Specifition();
    BMS_fualt_Action = new Specification(this,BMS_fualt_Action_explain, ui->BMSProtection_tW, 5, 0, \
                                   "Shut down", "BMS_fualt", \
                                   "触发BMS故障时执行的动作，可选功能为不动作(NO action)、降功率(Power down)、待机(Standby)、关机(Shut down)\nAction that is performed when a BMS fault is triggered.The optional functions are NO action(NO action), Power down(Power down), Standby(Standby), Shut down(Shut down).");
    BMS_fualt_Action->add_Specifition();
    BMS_warning_CP = new Specification(this,BMS_warning_CP_explain, ui->BMSProtection_tW, 3, 1, \
                                   "0", "BMS_warning_CP", \
                                   "触发BMS提示时的充电功率\nCharge power when BMS prompt is triggered.");
    BMS_warning_CP->add_Specifition();
    BMS_alarm_CP = new Specification(this,BMS_alarm_CP_explain, ui->BMSProtection_tW, 4, 1, \
                                   "0", "BMS_alarm_CP", \
                                   "触发BMS告警时执行的的充电功率\nCharge power that is executed when a BMS alarm is triggered.");
    BMS_alarm_CP->add_Specifition();
    BMS_fualt_CP = new Specification(this,BMS_fualt_CP_explain, ui->BMSProtection_tW, 5, 1, \
                                   "0", "BMS_fualt_CP", \
                                   "触发BMS故障时的充电功率\nCharging power when a BMS fault is triggered.");
    BMS_fualt_CP->add_Specifition();

    BMS_warning_DP = new Specification(this,BMS_warning_DP_explain, ui->BMSProtection_tW, 3, 2, \
                                   "0", "BMS_warning_DP", \
                                   "触发BMS提示时的放电功率\nDischarge power when the BMS prompt is triggered.");
    BMS_warning_DP->add_Specifition();
    BMS_alarm_DP = new Specification(this,BMS_alarm_DP_explain, ui->BMSProtection_tW, 4, 2, \
                                   "0", "BMS_alarm_DP", \
                                   "触发BMS告警时的放电功率\nDischarge power when a BMS alarm is triggered.");
    BMS_alarm_DP->add_Specifition();
    BMS_fualt_DP = new Specification(this,BMS_fualt_DP_explain, ui->BMSProtection_tW, 5, 2, \
                                   "0", "BMS_fualt_DP", \
                                   "触发BMS故障时的放电功率\nDischarge power when triggering a BMS fault.");
    BMS_fualt_DP->add_Specifition();

}

void MEGAWin::Debugg()//调试 绘制button
{
    Debug_variable_1 = new Specification(this,Debug_variable_1_explain, ui->UI_Debug_Tab, 0, 1, \
                                   "0", "Debug_variable_1", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_variable_1->add_Specifition();
    Debug_variable_2 = new Specification(this,Debug_variable_2_explain, ui->UI_Debug_Tab, 1, 1, \
                                   "0", "Debug_variable_2", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_variable_2->add_Specifition();
    Debug_variable_3 = new Specification(this,Debug_variable_3_explain, ui->UI_Debug_Tab, 2, 1, \
                                   "0", "Debug_variable_3", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_variable_3->add_Specifition();
    Debug_variable_1_addr = new Specification(this,Debug_variable_1_addr_explain, ui->UI_Debug_Tab, 3, 1, \
                                   "4096", "Debug_variable_1_addr", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_variable_1_addr->add_Specifition();
    Debug_variable_2_addr = new Specification(this,Debug_variable_2_addr_explain, ui->UI_Debug_Tab, 4, 1, \
                                   "4096", "Debug_variable_2_addr", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_variable_2_addr->add_Specifition();
    Debug_variable_3_addr = new Specification(this,Debug_variable_3_addr_explain, ui->UI_Debug_Tab, 5, 1, \
                                   "4096", "Debug_variable_3_addr", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_variable_3_addr->add_Specifition();
    Debug_memery_var_1 = new Specification(this,Debug_memery_var_1_explain, ui->UI_Debug_Tab, 6, 1, \
                                   "0", "Debug_memery_var_1", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_memery_var_1->add_Specifition();
    Debug_memery_var_2 = new Specification(this,Debug_memery_var_2_explain, ui->UI_Debug_Tab, 7, 1, \
                                   "0", "Debug_memery_var_2", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_memery_var_2->add_Specifition();
    Debug_memery_var_3 = new Specification(this,Debug_memery_var_3_explain, ui->UI_Debug_Tab, 8, 1, \
                                   "0", "Debug_memery_var_3", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_memery_var_3->add_Specifition();
    Input_Vol_revise = new Specification(this,Input_Vol_revise_explain, ui->UI_Debug_Tab, 9, 1, \
                                   "", "Input_Vol_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Input_Vol_revise->add_Specifition();
    Input_Cur_revise = new Specification(this,Input_Cur_revise_explain, ui->UI_Debug_Tab, 10, 1, \
                                   "", "Input_Cur_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Input_Cur_revise->add_Specifition();
    Voltage_1_5_revise = new Specification(this,Voltage_1_5_revise_explain, ui->UI_Debug_Tab, 0, 3, \
                                   "", "Voltage_1_5_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Voltage_1_5_revise->add_Specifition();
    Bus_Vol_revise = new Specification(this,Bus_Vol_revise_explain, ui->UI_Debug_Tab, 1, 3, \
                                   "", "Bus_Vol_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Bus_Vol_revise->add_Specifition();
    Grid_A_AB_Vol_revise = new Specification(this,Grid_A_AB_Vol_revise_explain, ui->UI_Debug_Tab, 2, 3, \
                                   "", "Grid_A_AB_Vol_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Grid_A_AB_Vol_revise->add_Specifition();
    Grid_B_BC_Vol_revise = new Specification(this,Grid_B_BC_Vol_revise_explain, ui->UI_Debug_Tab, 3, 3, \
                                   "", "Grid_B_BC_Vol_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Grid_B_BC_Vol_revise->add_Specifition();
    Grid_C_CA_Vol_revise = new Specification(this,Grid_C_CA_Vol_revise_explain, ui->UI_Debug_Tab, 4, 3, \
                                   "", "Grid_C_CA_Vol_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Grid_C_CA_Vol_revise->add_Specifition();
    Output_A_Cur_revise = new Specification(this,Output_A_Cur_revise_explain, ui->UI_Debug_Tab, 5, 3, \
                                   "", "Output_A_Cur_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Output_A_Cur_revise->add_Specifition();
    Output_B_Cur_revise = new Specification(this,Output_B_Cur_revise_explain, ui->UI_Debug_Tab, 6, 3, \
                                   "", "Output_B_Cur_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Output_B_Cur_revise->add_Specifition();
    Output_C_Cur_revise = new Specification(this,Output_C_Cur_revise_explain, ui->UI_Debug_Tab, 7, 3, \
                                   "", "Output_C_Cur_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Output_C_Cur_revise->add_Specifition();
    INV_A_Vol_revise = new Specification(this,INV_A_Vol_revise_explain, ui->UI_Debug_Tab, 8, 3, \
                                   "", "INV_A_Vol_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INV_A_Vol_revise->add_Specifition();
    INV_B_Vol_revise = new Specification(this,INV_B_Vol_revise_explain, ui->UI_Debug_Tab, 9, 3, \
                                   "", "INV_B_Vol_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INV_B_Vol_revise->add_Specifition();
    INV_C_Vol_revise = new Specification(this,INV_C_Vol_revise_explain, ui->UI_Debug_Tab, 10, 3, \
                                   "", "INV_C_Vol_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INV_C_Vol_revise->add_Specifition();

    INV_A_ind_Cur_revise = new Specification(this,INV_A_ind_Cur_revise_explain, ui->UI_Debug_Tab, 0, 5, \
                                   "", "INV_A_ind_Cur_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INV_A_ind_Cur_revise->add_Specifition();
    INV_B_ind_Cur_revise = new Specification(this,INV_B_ind_Cur_revise_explain, ui->UI_Debug_Tab, 1, 5, \
                                   "", "INV_B_ind_Cur_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INV_B_ind_Cur_revise->add_Specifition();
    INV_C_ind_Cur_revise = new Specification(this,INV_C_ind_Cur_revise_explain, ui->UI_Debug_Tab, 2, 5, \
                                   "", "INV_C_ind_Cur_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INV_C_ind_Cur_revise->add_Specifition();
    INV_On_off_flag = new Specification(this,INV_On_off_flag_explain, ui->UI_Debug_Tab, 3, 5, \
                                   "0", "INV_On_off_flag", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INV_On_off_flag->add_Specifition();
    Logic_state = new Specification(this,Logic_state_explain, ui->UI_Debug_Tab, 4, 5, \
                                   "0", "Logic_state", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Logic_state->add_Specifition();
    INV_flag = new Specification(this,INV_flag_explain, ui->UI_Debug_Tab, 5, 5, \
                                   "0", "INV_flag", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INV_flag->add_Specifition();
    Grid_flag = new Specification(this,Grid_flag_explain, ui->UI_Debug_Tab, 6, 5, \
                                   "0", "Grid_flag", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Grid_flag->add_Specifition();
    Grid_protect_flag = new Specification(this,Grid_protect_flag_explain, ui->UI_Debug_Tab, 7, 5, \
                                   "0", "Grid_protect_flag", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Grid_protect_flag->add_Specifition();
    Bat_flag = new Specification(this,Bat_flag_explain, ui->UI_Debug_Tab, 8, 5, \
                                   "0", "Bat_flag", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Bat_flag->add_Specifition();
    DC_bus_flag = new Specification(this,DC_bus_flag_explain, ui->UI_Debug_Tab, 9, 5, \
                                   "0", "DC_bus_flag", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    DC_bus_flag->add_Specifition();
    INT_main_flag = new Specification(this,INT_main_flag_explain, ui->UI_Debug_Tab, 10, 5, \
                                   "0", "INT_main_flag", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INT_main_flag->add_Specifition();
    parallel_signal = new Specification(this,parallel_signal_explain, ui->UI_Debug_Tab, 11, 5, \
                                   "0", "parallel_signal", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    parallel_signal->add_Specifition();
}
