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

    /***************************参数设置**********************************/

    Grid_connected_mode_explain = new QPushButton;      //PCS并离网方式说明
    Constant_power_explain  = new QPushButton;           //恒功率说明
    Charging_and_discharging_explain = new QPushButton; //充放电说明
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
    ModuleData_Tab();

    ModuleState_Tab();
}

/***************************************************************
 * 系统设置页面初始化
 ***************************************************************/
void MEGAWin::SystemSettingPage()
{
    /*一般设置表*/
    UserParam_tab();
    /*系统设置表*/
//    FuctionParam_tab();
//    ProtectParam_tab();
//    ExternalDevice_tab();
//    BMSProtection_tab();
//    DebugParam_tab();
    /*设备信息表*/
    EquipmentInfor_tab();
    /*铅酸电池设置表*/
    BatterySet_tab();
    /*自动运行时间设置表*/
    RunTimeSet_tab();
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
/******************************************************************************
 * 设备信息表表初始化
 * ***************************************************************************/
void MEGAWin::EquipmentInfor_tab()
{
    ui->EquipmentInfor_tableWidget->clearContents();
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
    ui->EquipmentInfor_tableWidget->setColumnWidth(0,240);
    ui->EquipmentInfor_tableWidget->horizontalHeader()->setStretchLastSection(1);//自动占用剩余空间
    QStringList Display_Par4;
    Display_Par4 << tr("Converter type") << tr("Manufacturer name") << tr("Monitoring software version") << tr("Protocol version") << tr("Converter software version")
                << tr("CPLD software version") << "SN:";
    for(int i = 0; i < Display_Par4.size(); i++)
    {
        ui->EquipmentInfor_tableWidget->setItem(i, 0, new QTableWidgetItem(QString(Display_Par4.at(i))));
    }
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
    //ui->stackedWidget->setCurrentWidget(ui->SystemInformation_page);

    ui->EquipmentInfor_tableWidget->clearContents();
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
    QStringList Display_Par4;
    Display_Par4 << tr("Manufacturer name") << tr("Monitoring software version") << tr("Protocol version") << tr("Converter software version")
                << tr("CPLD software version") << tr("SN:");//<< tr("Converter type")
    for(int i = 0; i < Display_Par4.size(); i++)
    {
        ui->EquipmentInfor_tableWidget->setItem(i, 0, new QTableWidgetItem(QString(Display_Par4.at(i))));
    }

    QString STR_PRO;
    QString STR_DSP;
    QString STR_CPLD;
    QString SNCODE;

    ui->EquipmentInfor_tableWidget->setItem(0, 1, new QTableWidgetItem(QString(tr("PCS"))));
    ui->EquipmentInfor_tableWidget->item(0, 1)->setTextAlignment(Qt::AlignCenter);

    ui->EquipmentInfor_tableWidget->setItem(1, 1, new QTableWidgetItem("V103B500D004"));
    ui->EquipmentInfor_tableWidget->item(1, 1)->setTextAlignment(Qt::AlignCenter);

    ui->EquipmentInfor_tableWidget->setItem(2, 1, new QTableWidgetItem(STR_PRO));
    ui->EquipmentInfor_tableWidget->item(2, 1)->setTextAlignment(Qt::AlignCenter);
    ui->EquipmentInfor_tableWidget->setItem(3, 1, new QTableWidgetItem(STR_DSP));
    ui->EquipmentInfor_tableWidget->item(3, 1)->setTextAlignment(Qt::AlignCenter);
    ui->EquipmentInfor_tableWidget->setItem(4, 1, new QTableWidgetItem(STR_CPLD));
    ui->EquipmentInfor_tableWidget->item(4, 1)->setTextAlignment(Qt::AlignCenter);
    ui->EquipmentInfor_tableWidget->setItem(5, 1, new QTableWidgetItem(SNCODE));
    ui->EquipmentInfor_tableWidget->item(5, 1)->setTextAlignment(Qt::AlignCenter);


}

void MEGAWin::GeneralParam_tbnt_released()  //一般参数槽
{

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

    for(int i=0;i<12;i++)
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
    for(int i=0;i<9;i++)
    {
        ui->ExternalDevice_tW->setColumnWidth(i,200);
        ui->ExternalDevice_tW->setRowHeight(i,50);
        if(i==3){
            ui->ExternalDevice_tW->setColumnWidth(i,280);
            ui->ExternalDevice_tW->setRowHeight(i,50);
        }
    }
    for(int i=0;i<3;i++)
    {
        ui->BMSProtection_tW->setColumnWidth(i,220);
        ui->BMSProtection_tW->setRowHeight(i,50);
    }
    for(int i=0;i<12;i++)
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
    SystemParam_tbnt_released();

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

    connect(ui->Alarm_Button, SIGNAL(clicked()), this,SLOT(RTAlarm_tbtn_clicked()));//跳转当前告警记录

}

/******************************************************************************
 * 模块实时数据表初始化
 * ***************************************************************************/
void MEGAWin::ModuleData_Tab()
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
void MEGAWin::ModuleState_Tab()
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
        ui->RTState_Bypass_Tab->setColumnWidth(2,220);
        ui->RTState_Bypass_Tab->setColumnWidth(3,100);
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
        ui->RTD_PCS_StackedWidget->setCurrentWidget(ui->RTD_Bypass_Y_page);
        ui->RTState_stackedWidget->setCurrentWidget(ui->RTState_Bypass_Y_page);
        ui->BAT_stackedWidget->setCurrentWidget(ui->BAT_Lithium_page);
        ui->stackedWidget->setCurrentWidget(ui->Status_page);
        ui->Run_tabWidget->setCurrentIndex(0);
        break;
    case RECORDPAGE:
        ui->stackedWidget->setCurrentWidget(ui->Record_page);
        ui->Record_tabWidget->setCurrentWidget(ui->DataReport_page);
        ui->Report_tab->setCurrentWidget(ui->Report_tabPage_T);
        ui->dateEdit->setDate(QDateTime::currentDateTime().date());
        break;
    case SYSTEMPAGE:
        ui->stackedWidget->setCurrentWidget(ui->System_page);
        ui->BatterSet_stackedWidget->setCurrentWidget(ui->Lithium_stackedWidgetPage);
        ui->System_tabWidget->setCurrentIndex(0);
        break;
    case MACHINECLOSE:

        break;
    case MACHINESTANDBY:

        break;
    case MACHINEOPEN:

        break;

    default:
        break;
    }
}


/************************初始化界面********************************/
void MEGAWin::UIPageInit()
{
//    NotifyLogo();
    FirstPage();
    RunStatePage();
//    HistoryPage();
    SystemSettingPage();
    LCDSetting();
    LinkRelationship();

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

void MEGAWin::RTAlarm_tbtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Status_page);
    ui->Run_tabWidget->setCurrentWidget(ui->RTAlarm_page);

    ui->RTAlarm_Data_page->setColumnCount(5);
    ui->RTAlarm_Data_page->setRowCount(30);
    ui->RTAlarm_Data_page->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->RTAlarm_Data_page->verticalHeader()->setVisible(false);//设置垂直头不可见
    ui->RTAlarm_Data_page->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->RTAlarm_Data_page->setShowGrid(true);//设置显示格子
    ui->RTAlarm_Data_page->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    ui->RTAlarm_Data_page->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
    ui->RTAlarm_Data_page->setStyleSheet("selection-background-color:lightblue;");

    ui->RTAlarm_Data_page->setColumnWidth(0,130);
    ui->RTAlarm_Data_page->setColumnWidth(1,90);
    ui->RTAlarm_Data_page->setColumnWidth(2,230);
    ui->RTAlarm_Data_page->setColumnWidth(3,230);
    ui->RTAlarm_Data_page->setColumnWidth(4,270);

    QStringList RTAlarm_Title;
    RTAlarm_Title << tr("告警名称\nAlarm name") << tr("告警等级\nAlarm leve")<< tr("触发条件\nTrigger condition") \
                    << tr("响应动作\nResponse action")<< tr("是否自动复位及复位时间\nWhether to reset automatically\nand reset time");
    ui->RTAlarm_Data_page->setHorizontalHeaderLabels(RTAlarm_Title);

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


void MEGAWin::on_System_tabWidget_currentChanged(int index)
{
    GeneralParam_tbnt_released();
    Information_tbnt_released();
}

void MEGAWin::PCS_Data()//PCS数据 绘制button
{
    PCS_vol_AB = new Specification(PCS_vol_AB_explain, ui->Converter_Tab, 0, 1, \
                                            "99.9V", "PCS voltage(AB)", \
                                            "这是PCS的A和B相的电压\nThis is the voltage of the A and B phases of the PCS");
    PCS_vol_AB->add_Specifition();
    PCS_vol_BC = new Specification(PCS_vol_BC_explain, ui->Converter_Tab, 1, 1, \
                                            "99.9V", "PCS voltage(BC)", \
                                            "这是PCS的B和C相的电压\nThis is the voltage of phase B and phase C of PCS");
    PCS_vol_BC->add_Specifition();
    PCS_vol_CA = new Specification(PCS_vol_CA_explain, ui->Converter_Tab, 2, 1, \
                                            "99.7V", "PCS voltage(CA)", \
                                            "这是PCS的A和C相的电压\nThis is the voltage of phase A and phase C of the PCS");
    PCS_vol_CA->add_Specifition();
    PCS_cur_A = new Specification(PCS_cur_A_explain, ui->Converter_Tab, 3, 1, \
                                            "0A", "PCS current(A)", \
                                            "这是PCS的A相电流\nThis is the A-phase current of PCS");
    PCS_cur_A->add_Specifition();
    PCS_cur_B = new Specification(PCS_cur_B_explain, ui->Converter_Tab, 4, 1, \
                                            "0A", "PCS current(B)", \
                                            "这是PCS的B相电流\nThis is the B-phase current of PCS");
    PCS_cur_B->add_Specifition();
    PCS_cur_C = new Specification(PCS_cur_C_explain, ui->Converter_Tab, 5, 1, \
                                            "0A", "PCS current(C)", \
                                            "这是PCS的C相电流\nThis is the C phase current of PCS");
    PCS_cur_C->add_Specifition();
    PCS_act_P = new Specification(PCS_act_P_explain, ui->Converter_Tab, 6, 1, \
                                            "0kW", "PCS Active Power", \
                                            "这是PCS的有功功率\nThis is the active power of PCS");
    PCS_act_P->add_Specifition();
    PCS_rea_P = new Specification(PCS_rea_P_explain, ui->Converter_Tab, 7, 1, \
                                            "0kVar", "PCS Reactive Power", \
                                            "这是PCS的无功功率\nThis is the reactive power of PCS");
    PCS_rea_P->add_Specifition();
    PCS_par_P = new Specification(PCS_par_P_explain, ui->Converter_Tab, 8, 1, \
                                            "0kVA", "PCS Parent Power", \
                                            "这是PCS的视在功率\nThis is the apparent power of PCS");
    PCS_par_P->add_Specifition();

    PCS_Pf = new Specification(PCS_Pf_explain, ui->Converter_Tab, 9, 1, \
                                            "0", "PCS Power factor", \
                                            "这是PCS的功率因数\nThis is the power factor of PCS");
    PCS_Pf->add_Specifition();
    PCS_Bat_vol = new Specification(PCS_Bat_vol_explain, ui->Converter_Tab, 0, 3, \
                                            "0V", "PCS Battery voltage", \
                                            "这是电池电压\nThis is the battery voltage");
    PCS_Bat_vol->add_Specifition();
    PCS_Bat_cur = new Specification(PCS_Bat_cur_explain, ui->Converter_Tab, 1, 3, \
                                            "0A", "PCS Battery current", \
                                            "这是电池电流\nThis is battery current");
    PCS_Bat_cur->add_Specifition();
    PCS_Bat_P = new Specification(PCS_Bat_P_explain, ui->Converter_Tab, 2, 3, \
                                            "0kW", "PCS Battery power", \
                                            "这是电池功率\nThis is battery power");
    PCS_Bat_P->add_Specifition();
    PCS_Bus_vol = new Specification(PCS_Bus_vol_explain, ui->Converter_Tab, 3, 3, \
                                            "0V", "PCS Bus voltage", \
                                            "这是母线电压\nThis is the bus voltage");
    PCS_Bus_vol->add_Specifition();
    PCS_IGBT_T = new Specification(PCS_IGBT_T_explain, ui->Converter_Tab, 4, 3, \
                                            "39℃", "PCS IGBT temperature", \
                                            "这是IGBT温度\nThis is the IGBT temperature");
    PCS_IGBT_T->add_Specifition();
    PCS_Env_T = new Specification(PCS_Env_T_explain, ui->Converter_Tab, 5, 3, \
                                            "25℃", "PCS Environment temperature", \
                                            "这是环境温度\nThis is the ambient temperature");
    PCS_Env_T->add_Specifition();
}

void MEGAWin::Grid_Data()//电网数据 绘制button
{
    Grid_vol_AB = new Specification(Grid_vol_AB_explain, ui->Grid_Tab, 0, 1, \
                                            "0V", "Grid voltage(AB)", \
                                            "这是电网的A和B相的电压\nThis is the voltage of phase A and phase B of the grid");
    Grid_vol_AB->add_Specifition();
    Grid_vol_BC = new Specification(Grid_vol_BC_explain, ui->Grid_Tab, 1, 1, \
                                            "0V", "Grid voltage(BC)", \
                                            "这是电网的B和C相的电压\nThis is the voltage of phase B and phase C of the grid");
    Grid_vol_BC->add_Specifition();
    Grid_vol_CA = new Specification(Grid_vol_CA_explain, ui->Grid_Tab, 2, 1, \
                                            "0V", "Grid voltage(CA)", \
                                            "这是电网的A和C相的电压\nThis is the voltage of phase A and phase C of the grid");
    Grid_vol_CA->add_Specifition();
    Grid_cur_A = new Specification(Grid_cur_A_explain, ui->Grid_Tab, 3, 1, \
                                            "0A", "Grid current(AB)", \
                                            "这是电网的A相电流\nThis is the A-phase current of the grid");
    Grid_cur_A->add_Specifition();
    Grid_cur_B = new Specification(Grid_cur_B_explain, ui->Grid_Tab, 4, 1, \
                                            "0A", "Grid current(B)", \
                                            "这是电网的B相电流\nThis is the B-phase current of the grid");
    Grid_cur_B->add_Specifition();
    Grid_cur_C = new Specification(Grid_cur_C_explain, ui->Grid_Tab, 5, 1, \
                                            "0A", "Grid current(C)", \
                                            "这是电网的C相电流\nThis is the C-phase current of the grid");
    Grid_cur_C->add_Specifition();
    Grid_act_P = new Specification(Grid_act_P_explain, ui->Grid_Tab, 6, 1, \
                                            "0kW", "Grid active power", \
                                            "这是电网的有功功率\nThis is the active power of the grid");
    Grid_act_P->add_Specifition();
    Grid_rea_P = new Specification(Grid_rea_P_explain, ui->Grid_Tab, 7, 1, \
                                            "0kVar", "Grid reactive power", \
                                            "这是电网的无功功率\nThis is the reactive power of the grid");
    Grid_rea_P->add_Specifition();
    Grid_app_P = new Specification(Grid_app_P_explain, ui->Grid_Tab, 8, 1, \
                                            "0kVA", "Grid apparent power", \
                                            "这是电网的视在功率\nThis is the apparent power of the grid");
    Grid_app_P->add_Specifition();
    Grid_fre = new Specification(Grid_fre_explain, ui->Grid_Tab, 9, 1, \
                                            "0Hz", "Grid frequency", \
                                            "这是电网的频率\nThis is the frequency of the grid");
    Grid_fre->add_Specifition();
    Grid_Pf = new Specification(Grid_Pf_explain, ui->Grid_Tab, 10, 1, \
                                            "0", "Grid power factor", \
                                            "这是电网的功率因数\nThis is the power factor of the grid");
    Grid_Pf->add_Specifition();
}

void MEGAWin::Load_Data()//负载数据 绘制button
{
    Load_vol_AB = new Specification(Load_vol_AB_explain, ui->Load_Tab, 0, 1, \
                                            "0V", "Load voltage(AB)", \
                                            "这是负载的A和B相的电压\nThis is the voltage of the A and B phases of the load");
    Load_vol_AB->add_Specifition();
    Load_vol_BC = new Specification(Load_vol_BC_explain, ui->Load_Tab, 1, 1, \
                                            "0V", "Load voltage(BC)", \
                                            "这是负载的B和C相的电压\nThis is the B and C phase voltage of the load");
    Load_vol_BC->add_Specifition();
    Load_vol_CA = new Specification(Load_vol_CA_explain, ui->Load_Tab, 2, 1, \
                                            "0V", "Load voltage(CA)", \
                                            "这是负载的A和C相的电压\nThis is the A and C phase voltage of the load");
    Load_vol_CA->add_Specifition();
    Load_cur_A = new Specification(Load_cur_A_explain, ui->Load_Tab, 3, 1, \
                                            "0A", "Load current(AB)", \
                                            "这是负载的A相电流\nThis is the A-phase current of the load");
    Load_cur_A->add_Specifition();
    Load_cur_B = new Specification(Load_cur_B_explain, ui->Load_Tab, 4, 1, \
                                            "0A", "Load current(B)", \
                                            "这是负载的B相电流\nThis is the B-phase current of the load");
    Load_cur_B->add_Specifition();
    Load_cur_C = new Specification(Load_cur_C_explain, ui->Load_Tab, 5, 1, \
                                            "0A", "Load current(C)", \
                                            "这是负载的C相电流\nThis is the C-phase current of the load");
    Load_cur_C->add_Specifition();
    Load_act_P = new Specification(Load_act_P_explain, ui->Load_Tab, 6, 1, \
                                            "0kW", "Load active power", \
                                            "这是负载的有功功率\nThis is the active power of the load");
    Load_act_P->add_Specifition();
    Load_rea_P = new Specification(Load_rea_P_explain, ui->Load_Tab, 7, 1, \
                                            "0kVar", "Load reactive power", \
                                            "这是负载的无功功率\nThis is the reactive power of the load");
    Load_rea_P->add_Specifition();
    Load_app_P = new Specification(Load_app_P_explain, ui->Load_Tab, 8, 1, \
                                            "0kVA", "Load apparent power", \
                                            "这是负载的视在功率This is the apparent power of the load");
    Load_app_P->add_Specifition();
    Load_Pf = new Specification(Load_Pf_explain, ui->Load_Tab, 9, 1, \
                                            "0", "Load frequency", \
                                            "这是负载的功率因数\nThis is the power factor of the load");
    Load_Pf->add_Specifition();
}

void MEGAWin::ParameterSet()//系统设置 绘制button
{
    Grid_connected_mode = new Specification(Grid_connected_mode_explain, ui->System_Tab, 0, 1, \
                                            "automatic", "Grid connected mode of PCS", \
                                            "这是PCS并网方式，一共有三项可选：自动，并网，离网\nThis is PCS grid-connected mode. There are three options: automatic, grid-connected(Off) and off-grid(On)");
    Grid_connected_mode->add_Specifition();

    Constant_power = new Specification(Constant_power_explain, ui->System_Tab, 1, 1, \
                                       "0", "Constant power(AC)", \
                                       "这是恒功率，可以通过修改这项数值来设置机器的功率,'-'代表充电\nThis is the constant power. You can set the power of the machine by changing this value. '-' stands for charge");
    Constant_power->add_Specifition();

    Charging_and_discharging = new Specification(Charging_and_discharging_explain, ui->System_Tab, 2, 1, \
                                                 "Charge", "Charging and discharging", \
                                                 "这是充放电，一共有两项可选：充电，放电\nThis is charge and discharge. There are two options: charge and discharge");
    Charging_and_discharging->add_Specifition();

    Work_mode = new Specification(Work_mode_explain, ui->System_Tab, 3, 1, \
                                  "Manual", "Work mode", \
                                  "这是工作模式，有四项可选：手动，UPS，削峰填谷，受控制削峰填谷\nThis is the working mode, there are four options: manual, UPS, peak cutting and valley filling, controlled peak cutting and valley filling");
    Work_mode->add_Specifition();

    Output_power_factor = new Specification(Output_power_factor_explain, ui->System_Tab, 4, 1, \
                                            "1", "Output power factor", \
                                            "这是输出功率因素\nThis is the power output factor");
    Output_power_factor->add_Specifition();

    Output_reactive_power = new Specification(Output_reactive_power_explain, ui->System_Tab, 5, 1, \
                                              "1", "Output reactive power", \
                                              "这是输出无功功率\nThis is the output reactive power");
    Output_reactive_power->add_Specifition();

    Constant_current = new Specification(Constant_current_explain, ui->System_Tab, 6, 1, \
                                         "100", "Constant current", \
                                         "这是恒流值\nThis is the constant current value");
    Constant_current->add_Specifition();

    Constant_voltage = new Specification(Constant_voltage_explain, ui->System_Tab, 7, 1, \
                                         "600", "Constant voltage", \
                                         "这是恒压值\nThis is constant pressure");
    Constant_voltage->add_Specifition();

    Control_mode = new Specification(Control_mode_explain, ui->System_Tab, 0, 4, \
                                     "Local", "Control mode", \
                                     "这是工作模式，有两项可选：本地，远程\nThis is the working mode, with two options: Local and Remote");
    Control_mode->add_Specifition();

    Machine_number = new Specification(Machine_number_explain, ui->System_Tab, 1, 4, \
                                       "Master_00", "Machine number", \
                                       "这是设备号，可以选择主机或者从机，其中主机有一项可选，从机有九项可选\nThis is the device number. You can choose the host or slave. The host has one option(Master_00) and the slave has nine options");
    Machine_number->add_Specifition();

    Parallel = new Specification(Parallel_explain, ui->System_Tab, 2, 4, \
                                 "Disable", "Parallel", \
                                 "这是并机，有两项可选：使能，禁止\nThis is parallel, with two options: Enable and Disable");
    Parallel->add_Specifition();

    Unbalance_power_enable = new Specification(Unbalance_power_enable_explain, ui->System_Tab, 3, 4, \
                                               "Disable", "Unbalance power enable", \
                                               "这是功率不平衡使能，有两项可选：使能，禁止\nThis is to enable power imbalance, with two options: Enable and Disable");
    Unbalance_power_enable->add_Specifition();

    Phase_A_power = new Specification(Phase_A_power_explain, ui->System_Tab, 4, 4, \
                                      "5", "Phase A power", \
                                      "这是A相功率\nThis is Phase A power");
    Phase_A_power->add_Specifition();

    Phase_B_power = new Specification(Phase_B_power_explain, ui->System_Tab, 5, 4, \
                                      "5", "Phase B power", \
                                      "T这是B相功率\nhis is Phase B power");
    Phase_B_power->add_Specifition();

    Phase_C_power = new Specification(Phase_C_power_explain, ui->System_Tab, 6, 4, \
                                      "5", "Phase C power", \
                                      "这是C相功率\nThis is Phase C power");
    Phase_C_power->add_Specifition();

}

void MEGAWin::BetterySetup()//电池设置 绘制button
{
    DOD_OnGrid = new Specification(DOD_OnGrid_explain, ui->Lithum_Tab, 0, 1, \
                                     "80", "DOD_OnGrid", \
                                     "并网工况下电池的放电深度，默认90\nThe default discharge depth of the battery in grid-connected condition is 90.");
    DOD_OnGrid->add_Specifition();
    DOD_OffGrid = new Specification(DOD_OffGrid_explain, ui->Lithum_Tab, 1, 1, \
                                     "80", "DOD_OffGrid", \
                                     "离网工况下电池的放电深度，默认90\nThe default discharge depth of the battery in off-grid mode is 90.");
    DOD_OffGrid->add_Specifition();
    Charge_Vol_Up_Limit = new Specification(Charge_Vol_Up_Limit_explain, ui->Lithum_Tab, 2, 1, \
                                     "792", "Charge_Vol_Up_Limit", \
                                     "充电时电池电压所允许达到的最大值\nThe maximum allowable battery voltage during charging.");
    Charge_Vol_Up_Limit->add_Specifition();
    Disc_Vol_lower_Limit = new Specification(Disc_Vol_lower_Limit_explain, ui->Lithum_Tab, 3, 1, \
                                     "616", "Disc_Vol_lower_Limit", \
                                     "放电时电池电压所允许的最小值\nThe minimum allowable battery voltage when discharging.");
    Disc_Vol_lower_Limit->add_Specifition();
    Charge_Cur_Limit = new Specification(Charge_Cur_Limit_explain, ui->Lithum_Tab, 4, 1, \
                                     "160", "Charge_Cur_Limit", \
                                     "允许的最大充电电流\nThe maximum allowable charging current.");
    Charge_Cur_Limit->add_Specifition();
    Gen_turn_off_SOC = new Specification(Gen_turn_off_SOC_explain, ui->Lithum_Tab, 5, 1, \
                                     "85", "Gen_turn_off_SOC", \
                                     "达到指定SCO值时，柴油发电机关闭\nWhen the specified SCO value is reached, the diesel generator shuts down.");
    Gen_turn_off_SOC->add_Specifition();
    Gen_turn_on_SOC = new Specification(Gen_turn_on_SOC_explain, ui->Lithum_Tab, 6, 1, \
                                     "25", "Gen_turn_on_SOC", \
                                     "达到指定SOC值时，柴油发电机开启\nWhen the specified SOC value is reached, the diesel generator starts.");
    Gen_turn_on_SOC->add_Specifition();
    Gen_charge_SOC = new Specification(Gen_charge_SOC_explain, ui->Lithum_Tab, 7, 1, \
                                     "10", "Gen_charge_SOC", \
                                     "达到指定SOC值时，柴油发电机开始充电\nWhen the specified SOC value is reached, the diesel generator starts charging.");
    Gen_charge_SOC->add_Specifition();
    Grid_charge_SOC = new Specification(Grid_charge_SOC_explain, ui->Lithum_Tab, 8, 1, \
                                     "15", "Grid_charge_SOC", \
                                     "到达指定SOC值时，开始电网充电\nWhen the specified SOC value is reached, grid charging begins.");
    Grid_charge_SOC->add_Specifition();
    Grid_capacity = new Specification(Grid_capacity_explain, ui->Lithum_Tab, 9, 1, \
                                     "150", "Grid_capacity", \
                                     "电网容量，电网允许带的总负荷\nThe capacity of the grid, the total load allowed on the grid.");
    Grid_capacity->add_Specifition();
    Turn_on_SOC = new Specification(Turn_on_SOC_explain, ui->Lithum_Tab, 0, 4, \
                                     "20", "Turn_on_SOC", \
                                     "当电池剩余电量百分比达到此值时开始充电\nCharging begins when the percentage of remaining battery capacity reaches this value.");
    Turn_on_SOC->add_Specifition();
    Turn_off_SOC = new Specification(Turn_off_SOC_explain, ui->Lithum_Tab, 1, 4, \
                                     "50", "Turn_off_SOC", \
                                     "当电池剩余电量百分比达到此值时停止充电\nStop charging when the percentage of remaining battery power reaches this value.");
    Turn_off_SOC->add_Specifition();
    Turn_on_cell_vol = new Specification(Turn_on_cell_vol_explain, ui->Lithum_Tab, 2, 4, \
                                     "3100", "Turn_on_cell_vol", \
                                     "所有单体中的最高电压达到此值时开始充电\nCharge begins when the highest voltage in all cells reaches this value.");
    Turn_on_cell_vol->add_Specifition();
    Turn_off_cell_vol = new Specification(Turn_off_cell_vol_explain, ui->Lithum_Tab, 3, 4, \
                                     "3500", "Turn_off_cell_vol", \
                                     "所有单体中的最高电压达到此值时停止充电\nThe highest voltage in all cells stops charging when it reaches this value.");
    Turn_off_cell_vol->add_Specifition();
    Turn_on_total_vol = new Specification(Turn_on_total_vol_explain, ui->Lithum_Tab, 4, 4, \
                                     "400", "Turn_on_total_vol", \
                                     "当电池电压达到此值时开始充电\nCharge begins when the battery voltage reaches this value.");
    Turn_on_total_vol->add_Specifition();
    Turn_off_total_vol = new Specification(Turn_off_total_vol_explain, ui->Lithum_Tab, 5, 4, \
                                     "650", "Turn_off_total_vol", \
                                     "当电池电压达到此值时停止充电\nStop charging when the battery voltage reaches this value.");
    Turn_off_total_vol->add_Specifition();
    UPS_charge_power = new Specification(UPS_charge_power_explain, ui->Lithum_Tab, 6, 4, \
                                     "-1", "UPS_charge_power", \
                                     "工作模式为后备模式时的充电功率\nThe charging power when the working mode is backup mode.");
    UPS_charge_power->add_Specifition();
    Monthly_cycle_time = new Specification(Monthly_cycle_time_explain, ui->Lithum_Tab, 7, 4, \
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
            temp[i] = new Specification(temp2[i], ui->Time_tableWidget, i, 0, \
                                                "√", temp3, \
                                                "这是'使能'，选择后将在指定的时间以指定的功率开启指定的状态，并在指定的时间结束\nThis is' Enable ', which will enable the specified state at the specified time with the specified power, and end at the specified time.");
        else
            temp[i] = new Specification(temp2[i], ui->Time_tableWidget, i, 0, \
                                                "", temp3, \
                                                "这是'使能'，选择后将在指定的时间以指定的功率开启指定的状态，并在指定的时间结束\nThis is' Enable ', which will enable the specified state at the specified time with the specified power, and end at the specified time.");
        temp[i]->add_Specifition();
        temp4[i] = new Specification(temp5[i], ui->Time_tableWidget, i, 1, \
                                                temp16, temp6, \
                                                "这是开始时间，将在此时间开始工作\nThis is the start time at which work will begin");
        temp4[i]->add_Specifition();
        temp7[i] = new Specification(temp8[i], ui->Time_tableWidget, i, 2, \
                                                temp17, temp9, \
                                                "这是结束时间，将在此时间结束工作\nWill finish work at this time.");
        temp7[i]->add_Specifition();

        if(i%2==0)
        {
            temp10[i] = new Specification(temp11[i], ui->Time_tableWidget, i, 3, \
                                                    "charge", temp12, \
                                                    "这是状态，将在工作时间执行此状态，有三种可供选择，分别为充电(charge)、放电(discharge)、自动(Automatic)\nThis is the state, which will be executed during working hours.  There are three options: charge（charge）, discharge（discharge）, and Automatic（Automatic）.");
            temp10[i]->add_Specifition();
            temp13[i] = new Specification(temp14[i], ui->Time_tableWidget, i, 4, \
                                                    "-100", temp15, \
                                                    "这是工作功率，此状态下工作时根据工作状态执行此功率\nThis is the working power, which is executed according to the working state when working in this state.");
            temp13[i]->add_Specifition();
        }
        else
        {
            temp10[i] = new Specification(temp11[i], ui->Time_tableWidget, i, 3, \
                                                    "discharge", temp12, \
                                                    "这是状态，将在工作时间执行此状态，有三种可供选择，分别为充电(charge)、放电(discharge)、自动(Automatic)\nThis is the state, which will be executed during working hours.  There are three options: charge（charge）, discharge（discharge）, and Automatic（Automatic）.");
            temp10[i]->add_Specifition();
            temp13[i] = new Specification(temp14[i], ui->Time_tableWidget, i, 4, \
                                                    "100", temp15, \
                                                    "这是工作功率，此状态下工作时根据工作状态执行此功率\nThis is the working power, which is executed according to the working state when working in this state");
            temp13[i]->add_Specifition();
        }
    }

}

void MEGAWin::FunctionSet()//功能设置绘制button
{
    Battery_type = new Specification(Battery_type_explain, ui->UI_Parameter_Tab, 0, 1, \
                                     "Lithium", "Battery_type", \
                                     "根据实际情况选择电池类型，有锂电(Lithium)和铅酸(LeadAcid)两种类型可供选择\n Choose the battery type according to the actual situation, there are two types of lithium(Lithium) and lead acid(LeadAcid) to choose from.");
    Battery_type->add_Specifition();
    BMS_Comm_type = new Specification(BMS_Comm_type_explain, ui->UI_Parameter_Tab, 1, 1, \
                                      "CAN", "BMS_Comm_type", \
                                      "设置与电池之间的通信方式，可根据情况选择RS485(RS485)或CAN通信(CAN)或以太网(Ethernet)\nSet the communication mode between the battery, RS485(RS485) or CAN communication(CAN) or Ethernet(Ethernet) can be selected according to the situation.");
    BMS_Comm_type->add_Specifition();
    Power_control_type = new Specification(Power_control_type_explain, ui->UI_Parameter_Tab, 2, 1,\
                                           "CP_N&&P" , "Power_control_type", \
                                           "设置控制功率的方式，有恒压(CV)、恒流(CC)、恒功率(CP_P)、正负功率(CP_N&P)\nSet the control power mode, constant voltage(CV), constant current(CC), constant power(CP_P), positive and negative power(CP_N&P).");
    Power_control_type->add_Specifition();
    EMS_Comm_type = new Specification(EMS_Comm_type_explain, ui->UI_Parameter_Tab, 3, 1, \
                                      "RS485", "EMS_Comm_type", \
                                      "设置EMS的通信方式，有RS485(RS485),CAN通信(CAN)，以太网(Ethernet)三种方式\nSetting the communication mode of EMS, there are RS485(RS485),CAN communication (CAN) and Ethernet(Ethernet).");
    EMS_Comm_type->add_Specifition();
    Output_power_limit = new Specification(Output_power_limit_explain, ui->UI_Parameter_Tab, 4, 1,\
                                           "100", "Output_power_limit", \
                                           "设置允许输出的功率最大值\nSet the maximum power output allowed.");
    Output_power_limit->add_Specifition();
    BAT_manufacturers = new Specification(BAT_manufacturers_explain, ui->UI_Parameter_Tab, 5, 1, \
                                          "GAOTE", "BAT_manufacturers", \
                                          "这是电池厂家，根据选择的电池厂家解析报文\nThis is the battery manufacturer and the packet is parsed according to the selected battery manufacturer.");
    BAT_manufacturers->add_Specifition();
    Power_Delta = new Specification(Power_Delta_explain, ui->UI_Parameter_Tab, 6, 1, \
                                    "10", "Power_Delta", \
                                    "设置功率回差，默认功率回差为10kw\nSet the power back difference, and the default power back difference is 10kw.");
    Power_Delta->add_Specifition();
    Charge_power_limit = new Specification(Charge_power_limit_explain, ui->UI_Parameter_Tab, 7, 1, \
                                           "100", "Charge_power_limit",\
                                           "设置充电功率限制,可以限制充电功率\nSet the charging power limit, which can limit the charging power.");
    Charge_power_limit->add_Specifition();
    Discharge_power_limit = new Specification(Discharge_power_limit_explain, ui->UI_Parameter_Tab, 8, 1, \
                                              "100", "Charge_power_limit", \
                                              "设置放电功率限制，可以限制放电功率\nYou can set discharge power limit to limit the discharge power.");
    Discharge_power_limit->add_Specifition();
    Charge_Vol_upper_Limit_delta = new Specification(Charge_Vol_upper_Limit_delta_explain, ui->UI_Parameter_Tab, 9, 1, \
                                                     "10", "Charge_Vol_upper_Limit_delta", \
                                                     "设置充电电压上限回差，默认充电电压上限为10kw\nThe upper limit of charging voltage return difference is set, and the default charging voltage upper limit is 10kw.");
    Charge_Vol_upper_Limit_delta->add_Specifition();
    Discharge_Vol_lower_Limit_delta = new Specification(Discharge_Vol_lower_Limit_delta_explain, ui->UI_Parameter_Tab, 10, 1,\
                                                        "10", "Discharge_Vol_lower_Limit_delta", \
                                                        "设置放电电压下限回差，默认放电电压下限回差为10kw\nSet the discharge voltage lower limit back difference, the default discharge voltage lower limit back difference is 10kw.");
    Discharge_Vol_lower_Limit_delta->add_Specifition();
    Host_Address = new Specification(Host_Address_explain, ui->UI_Parameter_Tab, 0, 4,\
                                     "20", "Host_Address", \
                                     "设置主机地址\nSet host address.");
    Host_Address->add_Specifition();
    serial_port_1 = new Specification(serial_port_1_explain, ui->UI_Parameter_Tab, 1, 4, \
                                      "9600", "serial_port_1", \
                                      "这是串口1，设置波特率，有六项可供选择，分别是1200、2400、4800、9600、19200、38400，串口1默认波特率是9600bps\nThis is serial port 1, set the baud rate, there are six options to choose from, which are 1200, 2400, 4800, 9600, 19200, 38400, and the default baud rate of serial port 1 is 9600bps.");
    serial_port_1->add_Specifition();
    serial_port_2 = new Specification(serial_port_2_explain, ui->UI_Parameter_Tab, 2, 4, \
                                      "9600", "serial_port_2", \
                                      "这是串口2，设置波特率，有六项可供选择，分别是1200、2400、4800、9600、19200、38400，串口2默认波特率是9600bps\nThis is serial port 2, set the baud rate, there are six options to choose from, which are 1200, 2400, 4800, 9600, 19200, 38400, and the default baud rate of serial port 2 is 9600bps");
    serial_port_2->add_Specifition();
    serial_port_3 = new Specification(serial_port_3_explain, ui->UI_Parameter_Tab, 3, 4, \
                                      "9600", "serial_port_3", \
                                      "这是串口3，设置波特率，有六项可供选择，分别是1200、2400、4800、9600、19200、38400，串口3默认波特率是9600bps\nThis is serial port 3, set the baud rate, there are six options to choose from, which are 1200, 2400, 4800, 9600, 19200, 38400, and the default baud rate of serial port 3 is 9600bps.");
    serial_port_3->add_Specifition();
    serial_port_4 = new Specification(serial_port_4_explain, ui->UI_Parameter_Tab, 4, 4, \
                                      "9600", "serial_port_4", \
                                      "这是串口4，设置波特率，有六项可供选择，分别是1200、2400、4800、9600、19200、38400，串口4默认波特率是9600bps\nThis is serial port 4, set the baud rate, there are six options to choose from, which are 1200, 2400, 4800, 9600, 19200, 38400, and the default baud rate of serial port 4 is 9600bps.");
    serial_port_4->add_Specifition();
    serial_port_5 = new Specification(serial_port_5_explain, ui->UI_Parameter_Tab, 5, 4, \
                                      "9600", "serial_port_5", \
                                      "这是串口5，设置波特率，有六项可供选择，分别是1200、2400、4800、9600、19200、38400，串口5默认波特率是9600bps\nThis is serial port 5, set the baud rate, there are six options to choose from, which are 1200, 2400, 4800, 9600, 19200, 38400, and the default baud rate of serial port 5 is 9600bps.");
    serial_port_5->add_Specifition();

    Can_port_1 = new Specification(Can_port_1_explain, ui->UI_Parameter_Tab, 6, 4, \
                                   "500", "Can_port_1", \
                                   "这是CAN1端口，PCS内部通讯的波特率，默认波特率500，无需更改\nThis is the baud rate of CAN1 port and PCS internal communication. The default baud rate is 500, which need not be changed.");
    Can_port_1->add_Specifition();
    Can_port_2 = new Specification(Can_port_2_explain, ui->UI_Parameter_Tab, 7, 4, \
                                   "250", "Can_port_2", \
                                   "这是CAN2端口，PCS与BMS通信的波特率，默认波特率125，根据现场BMS通信波特率进行修改，其中有五项可供选择，分别是100、125、250、500、800\nThis is the baud rate of the CAN2 port and the communication between PCS and BMS. The default baud rate is 125, which is modified according to the on-site BMS communication baud rate. There are five items to choose from, which are 100, 125, 250, 500 and 800 respectively.");
    Can_port_2->add_Specifition();
    ProtocolVersion = new Specification(ProtocolVersion_explain, ui->UI_Parameter_Tab, 0, 7, \
                                        "5612", "ProtocolVersion", \
                                        "这是协议版本号，用于查看当前协议版本\nThis is the protocol version number used to see the current protocol version.");
    ProtocolVersion->add_Specifition();
    UserPassPort = new Specification(UserPassPort_explain, ui->UI_Parameter_Tab, 1, 7, \
                                     "123456", "UserPassPort", \
                                     "这是用户密码，可供重新设置用户密码，默认用户密码123456\nThis is the user password, you can reset the user password, the default user password 123456.");
    UserPassPort->add_Specifition();
    RootPassport = new Specification(RootPassport_explain, ui->UI_Parameter_Tab, 2, 7,\
                                     "888888", "RootPassport", \
                                     "这是超级权限密码，可供重新设置超级权限密码，默认超级权限密码888888\nThis is the super privilege password. You can reset the super privilege password. The default super privilege password is 888888.");
    RootPassport->add_Specifition();
    Language = new Specification(Language_explain, ui->UI_Parameter_Tab, 3, 7, \
                                 "English", "Language", \
                                 "设置显示屏的显示语言，可供选择为中文与英文，切换语言时系统会重启\nSet the display language of the display screen, which can be selected as Chinese and English. The system will restart when switching languages.");
    Language->add_Specifition();
    System_upgrade = new Specification(System_upgrade_explain, ui->UI_Parameter_Tab, 4, 7, \
                                       "upgrade", "System_upgrade", \
                                       "点击即可进入系统升级应用程序，根据升级文档进行系统升级\nClick to enter the system upgrade application and upgrade the system according to the upgrade document.");
    System_upgrade->add_Specifition();
    Sounds = new Specification(Sounds_explain, ui->UI_Parameter_Tab, 5, 7, \
                               "Allow", "Sounds", \
                               "设置显示屏是否开启声音，可供选择为允许(Allow)、禁止(forbid)\nSet whether the display is enabled sound, which can be allowed(Allow) or prohibited(forbid).");
    Sounds->add_Specifition();
    DryContact = new Specification(DryContact_explain, ui->UI_Parameter_Tab, 6, 7, \
                                   "forbid", "DryContact", \
                                   "根据项目现场配置干接点功能，可供选择为允许(Allow)、禁止(forbid)\nAccording to the project site configuration dry contact function, can be selected as allowed(Allow), prohibited(forbid).");
    DryContact->add_Specifition();
}

void MEGAWin::SystemParameter()//系统参数 绘制button
{
    Change_rate_of_power = new Specification(Change_rate_of_power_explain, ui->UI_SystemParameter_Tab, 0, 1, \
                                             "20", "Change_rate_of_power", \
                                             "功率变化率是与额定功率相比功率变化的大小\nPower change ratio is the magnitude of the power change compared to the rated power.");
    Change_rate_of_power->add_Specifition();
    Grid_frequency_upper_limit = new Specification(Grid_frequency_upper_limit_explain, ui->UI_SystemParameter_Tab, 1, 1, \
                                                   "3", "Grid_frequency_upper_limit", \
                                                   "电网频率允许超出额定频率的上限,可供选择为0.2、0.5、1、3\nThe grid frequency is allowed to exceed the upper limit of the rated frequency, which can be selected as 0.2, 0.5, 1, and 3.");
    Grid_frequency_upper_limit->add_Specifition();
    Grid_frequency_lower_limit = new Specification(Grid_frequency_lower_limit_explain, ui->UI_SystemParameter_Tab, 2, 1, \
                                                   "-3", "Grid_frequency_lower_limit", \
                                                   "电网频率允许小于额定频率的下限,可供选择为-0.5、-1、-2、-3\nThe grid frequency is allowed to be less than the lower limit of the rated frequency, which can be selected as -0.5, -1, -2, -3.");
    Grid_frequency_lower_limit->add_Specifition();
    Vol_protection_upper_limit = new Specification(Vol_protection_upper_limit_explain, ui->UI_SystemParameter_Tab, 3, 1, \
                                                   "+15", "Vol_protection_upper_limit", \
                                                   "会进行断电保护的电压最大值,可供选择为+10、+15、+20、+30\nThe maximum voltage for power outage protection can be selected as +10, +15, +20, +30.");
    Vol_protection_upper_limit->add_Specifition();
    Vol_protection_lower_limit = new Specification(Vol_protection_lower_limit_explain, ui->UI_SystemParameter_Tab, 4, 1, \
                                                   "-15", "Vol_protection_lower_limit", \
                                                   "会进行断电保护的电压最小值,可供选择为-10、-15、-20、-30\nThe minimum voltage for power outage protection can be selected as -10, -15, -20, -30.");
    Vol_protection_lower_limit->add_Specifition();
    HVRT_enable = new Specification(HVRT_enable_explain, ui->UI_SystemParameter_Tab, 5, 1, \
                                                    "prohibit", "HVRT_enable", \
                                                    "高压穿越使能,使高压也能穿越，在一定时间内高压不会关机,可供选择为允许(Allow)、禁止(forbid)\nEnable the high voltage pass through, so that the high voltage can also pass through, and the high voltage will not shut down within a certain time. The options are Allow (Allow), forbid (forbid).");
    HVRT_enable->add_Specifition();
    LVRT_enable = new Specification(LVRT_enable_explain, ui->UI_SystemParameter_Tab, 6, 1, \
                                    "prohibit", "LVRT_enable", \
                                    "低压穿越使能，使低压也能穿越，在一定时间内低压不会关机,可供选择为允许(Allow)、禁止(forbid)\nEnable the low-voltage pass through, so that the low-voltage can also pass through, and the low-voltage will not shut down within a certain period of time. The options are Allow(Allow),, forbid(forbid).");
    LVRT_enable->add_Specifition();
    AFD_enable = new Specification(AFD_enable_explain, ui->UI_SystemParameter_Tab, 7, 1, \
                                   "prohibit", "AFD_enable", \
                                   "    防止孤岛效应，当检测出现孤岛效应(在光伏并网系统中,当大电网出现停电事故时,光伏并网逆变器发电与电网低压侧本地负载如果刚好出现功率相匹配时,容易出现自给自足的维持发电状态,从而出现""孤岛""现象,从而危及检修人员安全)时,让逆变器自动停机,可供选择为允许(Allow)、禁止(forbid)\nPrevent island effect, When the detection of island effect (in the photovoltaic grid-connected system, when the power failure accident occurs in the large power grid, photovoltaic grid-connected inverter power generation and the local load on the low voltage side of the grid if there is just a power match, it is easy to self-contained maintenance power state, resulting in the phenomenon of ""island"", thereby endangering the safety of maintenance personnel), let the inverter automatic shutdown, optional Permit(Allow) and forbid(forbid).");
    AFD_enable->add_Specifition();
    Insulation_detection_enable = new Specification(Insulation_detection_enable_explain, ui->UI_SystemParameter_Tab, 8, 1, \
                                                    "prohibit", "Insulation_detection_enable", \
                                                    "   绝缘检测使能，绝缘电阻大于33KΩ要能正常起机运行，小于33KΩ不能起机，并且要告警，默认禁止,可供选择为允许(Allow)、禁止(forbid)\nEnable insulation detection. If the insulation resistance is greater than 33KΩ, the machine can start normally; if the insulation resistance is smaller than 33KΩ, the machine cannot start, and the alarm should be generated. By default, it is prohibited, which can be selected as Allow(Allow) or forbid(forbid).");
    Insulation_detection_enable->add_Specifition();
    PrimaryFreq_enable = new Specification(PrimaryFreq_enable_explain, ui->UI_SystemParameter_Tab, 9, 1, \
                                           "prohibit", "PrimaryFreq_enable", \
                                           "    一次调频使能,电网的频率偏离额定值时，通过控制有功功率的增减使电网频率维持稳定，可供选择为允许(Allow)、禁止(forbid)\nWhen the frequency of the power grid deviates from the rated value, the frequency of the power grid can be maintained stable by controlling the increase or decrease of the active power. The alternatives are Allow(Allow) and forbid(forbid).");
    PrimaryFreq_enable->add_Specifition();
    Inertia_enable = new Specification(Inertia_enable_explain, ui->UI_SystemParameter_Tab, 10, 1, \
                                       "prohibit", "Inertia_enable", \
                                       "转动惯量使能,在电力系统稳定性计算中加入转动惯量，可供选择为允许(Allow)、禁止(forbid)\nEnable the moment of inertia. Add the moment of inertia to the stability calculation of the power system. The options are Allow(Allow) and forbid(forbid).");
    Inertia_enable->add_Specifition();

    CV_parallel = new Specification(CV_parallel_explain, ui->UI_SystemParameter_Tab, 11, 1, \
                                    "prohibit", "CV_parallel", \
                                    "恒压并机使能,可供选择为允许(Allow)、禁止(forbid)\nAllow (Allow) forbid (forbid) Enable the constant voltage parallel machine.");
    CV_parallel->add_Specifition();

    Machine_type = new Specification(Machine_type_explain, ui->UI_SystemParameter_Tab, 0, 4, \
                                     "PCS-TS", "Machine_type", \
                                     "根据现场机器机器型号设置，以出厂值为准,可供选择为PCS、PCS-T、PCS-TS、PCS-TS-T\nSet according to the machine model and factory value. PCS, PCs-T, PCS-TS, and PCS-TS-T can be selected.");
    Machine_type->add_Specifition();
    Machine_capacity = new Specification(Machine_capacity_explain, ui->UI_SystemParameter_Tab, 1, 4, \
                                     "100", "Machine_capacity", \
                                     "PCS的额定容量，以出厂值为准，不可随意更改\nThe rated capacity of PCS is subject to the factory value and cannot be changed at will.");
    Machine_capacity->add_Specifition();
    Output_Fre_grade = new Specification(Output_Fre_grade_explain, ui->UI_SystemParameter_Tab, 2, 4, \
                                         "50", "Output_Fre_grade", \
                                         "设置输出频率的等级，一般默认50HZ，根据项目地可更改为60Hz\nSet the output frequency level. The default frequency is 50HZ, but it can be changed to 60Hz according to the project.");
    Output_Fre_grade->add_Specifition();
    Output_vol_level = new Specification(Output_vol_level_explain, ui->UI_SystemParameter_Tab, 3, 4, \
                                         "400", "Output_vol_level", \
                                         "电压等级是通过变压器后输出的电压等级，要根据变压器的变比来设置，以出厂默认值为准，不可更改\nVoltage level is the output voltage level through the transformer, according to the transformer ratio to set, to the factory default value prevail, can not be changed.");
    Output_vol_level->add_Specifition();
    Converter_side_vol_level = new Specification(Converter_side_vol_level_explain, ui->UI_SystemParameter_Tab, 4, 4, \
                                         "270:400", "Converter_side_vol_level", \
                                         "逆变电压等级是逆变器逆变出来的电压等级，要根据变压器来设置，以出厂默认值为准，不可随意更改，可供更改选择为1:1、60:400、100:400、200:400、270:400、315:400、315:480\n");
    Converter_side_vol_level->add_Specifition();
    Output_reactive_power_mode = new Specification(Output_reactive_power_mode_explain, ui->UI_SystemParameter_Tab, 5, 4, \
                                         "Non adjustab", "Output_reactive_power_mode", \
                                         "输出无功方式，默认不可调节，可供选择为功率因数(PF)、无功功率(Q)、不可调节(Non adjustable)\nadjustable output reactive power mode, adjustable by default, adjustable power factor (PF), adjustable power (Q), Non adjustable(Non adjustable).");
    Output_reactive_power_mode->add_Specifition();
    Grid_connected_mode_of_Inv = new Specification(Grid_connected_mode_of_Inv_explain, ui->UI_SystemParameter_Tab, 6, 4, \
                                                   "Non counterc", "Grid_connected_mode_of_Inv", \
                                                   "设置逆变器的并网方式，可逆流即光伏发电转换成交流电后可以并入电网；不可逆则是光伏发电的电流不会流向电网。默认可逆流，可供选择为可逆流(Counterc)、不可逆流(Non counterc)\nThe grid-connected mode of the inverter can be countercurrent, that is, photovoltaic power generation can be converted into alternating current, which can be incorporated into the power grid; Irreversible means that photovoltaic electricity does not flow to the grid. Countercurrent is available by default. The options are Counterc(Counterc) and Non counterc(Non counterc).");
    Grid_connected_mode_of_Inv->add_Specifition();
    Primary_FM_dead_zone = new Specification(Primary_FM_dead_zone_explain, ui->UI_SystemParameter_Tab, 7, 4, \
                                             "3", "Primary_FM_dead_zone", \
                                             "一次调频死区为了防止在电网频差小范围变化时调门不必要的动作而设置的频差\nPrimary frequency modulation dead zone A frequency difference set to prevent unwanted switch action when the network frequency difference varies in a small range.");
    Primary_FM_dead_zone->add_Specifition();
    PFM_coeff = new Specification(PFM_coeff_explain, ui->UI_SystemParameter_Tab, 8, 4, \
                                  "20", "PFM_coeff", \
                                  "设置有功调频系数\nSet the active power frequency modulation coefficient.");
    PFM_coeff->add_Specifition();
    Grid_recover_time = new Specification(Grid_recover_time_explain, ui->UI_SystemParameter_Tab, 9, 4, \
                                          "10", "Grid_recover_time", \
                                          "电网恢复并网时间：预留功能，设置无效\nGrid restoration time: reserved function, setting invalid.");
    Grid_recover_time->add_Specifition();
    DynamicCap = new Specification(DynamicCap_explain, ui->UI_SystemParameter_Tab, 10, 4, \
                                   "9600", "DynamicCap", \
                                   "电网扩容使能,当负载在短时间内所需功率大于电网容量时，可暂时从电池辅助供电以达到功率要求，可供选择为允许(Allow)、禁止(forbid)\nEnable the power network expansion. The options are Allow(Allow) and forbid(forbid).");
    DynamicCap->add_Specifition();
    Module_Number = new Specification(Module_Number_explain, ui->UI_SystemParameter_Tab, 0, 7, \
                                      "1", "Module_Number", \
                                      "PCS的模块数量，默认值1(无效设置)\nNumber of modules for PCS, default 1(invalid setting).");
    Module_Number->add_Specifition();
    Restore_factory = new Specification(Restore_factory_explain, ui->UI_SystemParameter_Tab,1, 7, \
                                        "restore", "Restore_factory", \
                                        "恢复出厂时的默认设置\nRestore the factory default Settings.");
    Restore_factory->add_Specifition();
    Clear_Data = new Specification(Clear_Data_explain, ui->UI_SystemParameter_Tab, 2, 7, \
                                   "Clear", "Clear_Data", \
                                   "清除系统此前的记录数据及操作数据\nClear previous recorded data and operation data of the system.");
    Clear_Data->add_Specifition();
}

void MEGAWin::Peripheral()//外设 绘制button
{
    DI_1_Enable = new Specification(DI_1_Enable_explain, ui->ExternalDevice_tW, 0, 0, \
                                   "Enable", "DI_1_Enable", \
                                   "输入干接点1，发生NO关机时执行动作的开关,可选功能为使能(Enable)、禁止(Disable)\n");
    DI_1_Enable->add_Specifition();
    DI_2_Enable = new Specification(DI_2_Enable_explain, ui->ExternalDevice_tW, 1, 0, \
                                   "Enable", "DI_2_Enable", \
                                   "输入干接点2，发生NC关机时执行动作的开关，可选功能为使能(Enable)、禁止(Disable)\n");
    DI_2_Enable->add_Specifition();
    DI_3_Enable = new Specification(DI_3_Enable_explain, ui->ExternalDevice_tW, 2, 0, \
                                   "Enable", "DI_3_Enable", \
                                   "输入干接点3，门禁开启时执行动作的开关，可选功能为使能(Enable)、禁止(Disable)\n");
    DI_3_Enable->add_Specifition();
    DI_4_Enable = new Specification(DI_4_Enable_explain, ui->ExternalDevice_tW, 3, 0, \
                                   "Enable", "DI_4_Enable", \
                                   "输入干接点4，柴发信号发出时执行动作的开关，可选功能为使能(Enable)、禁止(Disable)\n");
    DI_4_Enable->add_Specifition();
    DI_5_Enable = new Specification(DI_5_Enable_explain, ui->ExternalDevice_tW, 4, 0, \
                                   "Enable", "DI_5_Enable", \
                                   "输入干接点5，发生水浸时执行动作的开关，可选功能为使能(Enable)、禁止(Disable)\n");
    DI_5_Enable->add_Specifition();
    DI_6_Enable = new Specification(DI_6_Enable_explain, ui->ExternalDevice_tW, 5, 0, \
                                   "Enable", "DI_6_Enable", \
                                   "输入干接点6，消防信号发出时执行动作的开关，可选功能为使能(Enable)、禁止(Disable)\n");
    DI_6_Enable->add_Specifition();
    DO_1_Enable = new Specification(DO_1_Enable_explain, ui->ExternalDevice_tW, 6, 0, \
                                   "Enable", "DO_1_Enable", \
                                   "输出干接点1，发电机开启时执行动作的开关，可选功能为使能(Enable)、禁止(Disable)\n");
    DO_1_Enable->add_Specifition();
    DO_2_Enable = new Specification(DO_2_Enable_explain, ui->ExternalDevice_tW, 7, 0, \
                                   "Enable", "DO_2_Enable", \
                                   "输出干接点2，预留功能，设置无效，可选功能为使能(Enable)、禁止(Disable)\n");
    DO_2_Enable->add_Specifition();
    DO_3_Enable = new Specification(DO_3_Enable_explain, ui->ExternalDevice_tW, 8, 0, \
                                   "Enable", "DO_3_Enable", \
                                   "输出干接点3，预留功能，设置无效，可选功能为使能(Enable)、禁止(Disable)\n");
    DO_3_Enable->add_Specifition();

    DI_1_NC_O = new Specification(DI_1_NC_O_explain, ui->ExternalDevice_tW, 0, 1, \
                                   "N_O", "DI_1_NC_O", \
                                   "输入干接点1，设置NO关机是常闭电路还是常开电路,可选功能为常开(N_O)常闭(N_C)\n");
    DI_1_NC_O->add_Specifition();
    DI_2_NC_O = new Specification(DI_2_NC_O_explain, ui->ExternalDevice_tW, 1, 1, \
                                   "N_O", "DI_2_NC_O", \
                                   "输入干接点2，设置NC关机是常闭电路还是常开电路可选功能为常开(N_O)常闭(N_C)\n");
    DI_2_NC_O->add_Specifition();
    DI_3_NC_O = new Specification(DI_3_NC_O_explain, ui->ExternalDevice_tW, 2, 1, \
                                   "N_C", "DI_3_NC_O", \
                                   "输入干接点3，设置门禁开是常闭电路还是常开电路可选功能为常开(N_O)常闭(N_C)\n");
    DI_3_NC_O->add_Specifition();
    DI_4_NC_O = new Specification(DI_4_NC_O_explain, ui->ExternalDevice_tW, 3, 1, \
                                   "N_O", "DI_4_NC_O", \
                                   "输入干接点4，设置柴发信号是常闭电路还是常开电路可选功能为常开(N_O)常闭(N_C)\n");
    DI_4_NC_O->add_Specifition();
    DI_5_NC_O = new Specification(DI_5_NC_O_explain, ui->ExternalDevice_tW, 4, 1, \
                                   "N_O", "DI_5_NC_O", \
                                   "输入干接点5，设置水浸是常闭电路还是常开电路可选功能为常开(N_O)常闭(N_C)\n");
    DI_5_NC_O->add_Specifition();
    DI_6_NC_O = new Specification(DI_6_NC_O_explain, ui->ExternalDevice_tW, 5, 1, \
                                   "N_O", "DI_6_NC_O", \
                                   "输入干接点6，设置消防是常闭电路还是常开电路可选功能为常开(N_O)常闭(N_C)\n");
    DI_6_NC_O->add_Specifition();
    DO_1_NC_O = new Specification(DO_1_NC_O_explain, ui->ExternalDevice_tW, 6, 1, \
                                   "N_O", "DO_1_NC_O", \
                                   "输出干接点1，设置发电机是常闭电路还是常开电路可选功能为常开(N_O)常闭(N_C)\n");
    DO_1_NC_O->add_Specifition();
    DO_2_NC_O = new Specification(DO_2_NC_O_explain, ui->ExternalDevice_tW, 7, 1, \
                                   "N_O", "DO_2_NC_O", \
                                   "输出干接点2，预留功能，设置无效，设置是常闭电路还是常开电路可选功能为常开(N_O)常闭(N_C)\n");
    DO_2_NC_O->add_Specifition();
    DO_3_NC_O = new Specification(DO_3_NC_O_explain, ui->ExternalDevice_tW, 8, 1, \
                                   "N_O", "DO_3_NC_O", \
                                   "输出干接点3，预留功能，设置无效，设置是常闭电路还是常开电路可选功能为常开(N_O)常闭(N_C)\n");
    DO_3_NC_O->add_Specifition();

    DI_1_Action = new Specification(DI_1_Action_explain, ui->ExternalDevice_tW, 0, 2, \
                                   "Shut down", "DI_1_Action", \
                                   "输入干接点1，发生NO关机时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\n");
    DI_1_Action->add_Specifition();
    DI_2_Action = new Specification(DI_2_Action_explain, ui->ExternalDevice_tW, 1, 2, \
                                   "Prompt", "DI_2_Action", \
                                   "输入干接点2，发生NC关机时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\n");
    DI_2_Action->add_Specifition();
    DI_3_Action = new Specification(DI_3_Action_explain, ui->ExternalDevice_tW, 2, 2, \
                                   "Prompt", "DI_3_Action", \
                                   "输入干接点3，门禁打开时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\n");
    DI_3_Action->add_Specifition();
    DI_4_Action = new Specification(DI_4_Action_explain, ui->ExternalDevice_tW, 3, 2, \
                                   "Prompt", "DI_4_Action", \
                                   "输入干接点4，柴发信号发出时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\n");
    DI_4_Action->add_Specifition();
    DI_5_Action = new Specification(DI_5_Action_explain, ui->ExternalDevice_tW, 4, 2, \
                                   "Shut down", "DI_5_Action", \
                                   "输入干接点5，发生水浸时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\n");
    DI_5_Action->add_Specifition();
    DI_6_Action = new Specification(DI_6_Action_explain, ui->ExternalDevice_tW, 5, 2, \
                                   "Shut down", "DI_6_Action", \
                                   "输入干接点6，触发消防时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\n");
    DI_6_Action->add_Specifition();
    DO_1_Action = new Specification(DO_1_Action_explain, ui->ExternalDevice_tW, 6, 2, \
                                   "Prompt", "DO_1_Action", \
                                   "输出干接点1，启动发电机时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\n");
    DO_1_Action->add_Specifition();
    DO_2_Action = new Specification(DO_2_Action_explain, ui->ExternalDevice_tW, 7, 2, \
                                   "Prompt", "DO_2_Action", \
                                   "输出干接点2，预留功能，设置无效，信号触发时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\n");
    DO_2_Action->add_Specifition();
    DO_3_Action = new Specification(DO_3_Action_explain, ui->ExternalDevice_tW, 8, 2, \
                                   "Prompt", "DO_3_Action", \
                                   "输出干接点3，预留功能，设置无效，信号触发时执行的动作,可选功能为提示(Prompt)、待机(Standby)、关机(Shut down)、充满待机(Full standby)、放空待机(Empty standby)、故障待机(Failure standby)、电网信号(Grid singnal)\n");
    DO_3_Action->add_Specifition();
}

void MEGAWin::BMS_Protect()//BMS保护 绘制button
{
    DOD_Action = new Specification(DOD_Action_explain, ui->BMSProtection_tW, 0, 0, \
                                   "Standby", "DOD", \
                                   "DOD保护，触发DOD保护时执行的动作，可选功能为不动作(NO action)、降功率(Power down)、待机(Standby)、关机(Shut down)\n");
    DOD_Action->add_Specifition();
    Prohibit_charging_Action = new Specification(Prohibit_charging_Action_explain, ui->BMSProtection_tW, 1, 0, \
                                   "Standby", "Prohibit_charging", \
                                   "触发禁充时执行的动作，可选功能为不动作(NO action)、降功率(Power down)、待机(Standby)、关机(Shut down)\n");
    Prohibit_charging_Action->add_Specifition();
    Prohibit_discharging_Action = new Specification(Prohibit_discharging_Action_explain, ui->BMSProtection_tW, 2, 0, \
                                   "Standby", "Prohibit_discharging", \
                                   "触发禁放时执行的动作，可选功能为不动作(NO action)、降功率(Power down)、待机(Standby)、关机(Shut down)\n");
    Prohibit_discharging_Action->add_Specifition();
    BMS_warning_Action = new Specification(BMS_warning_Action_explain, ui->BMSProtection_tW, 3, 0, \
                                   "NO action", "BMS_warning", \
                                   "触发BMS提示时执行的动作，可选功能为不动作(NO action)、降功率(Power down)、待机(Standby)、关机(Shut down)\n");
    BMS_warning_Action->add_Specifition();
    BMS_alarm_Action = new Specification(BMS_alarm_Action_explain, ui->BMSProtection_tW, 4, 0, \
                                   "Standby", "BMS_alarm", \
                                   "触发BMS告警时执行的动作，可选功能为不动作(NO action)、降功率(Power down)、待机(Standby)、关机(Shut down)\n");
    BMS_alarm_Action->add_Specifition();
    BMS_fualt_Action = new Specification(BMS_fualt_Action_explain, ui->BMSProtection_tW, 5, 0, \
                                   "Shut down", "BMS_fualt", \
                                   "触发BMS故障时执行的动作，可选功能为不动作(NO action)、降功率(Power down)、待机(Standby)、关机(Shut down)\n");
    BMS_fualt_Action->add_Specifition();
    BMS_warning_CP = new Specification(BMS_warning_CP_explain, ui->BMSProtection_tW, 3, 1, \
                                   "0", "BMS_warning_CP", \
                                   "触发BMS提示时的充电功率\n");
    BMS_warning_CP->add_Specifition();
    BMS_alarm_CP = new Specification(BMS_alarm_CP_explain, ui->BMSProtection_tW, 4, 1, \
                                   "0", "BMS_alarm_CP", \
                                   "触发BMS告警时执行的的充电功率\n");
    BMS_alarm_CP->add_Specifition();
    BMS_fualt_CP = new Specification(BMS_fualt_CP_explain, ui->BMSProtection_tW, 5, 1, \
                                   "0", "BMS_fualt_CP", \
                                   "触发BMS故障时的充电功率\n");
    BMS_fualt_CP->add_Specifition();

    BMS_warning_DP = new Specification(BMS_warning_DP_explain, ui->BMSProtection_tW, 3, 2, \
                                   "0", "BMS_warning_DP", \
                                   "触发BMS提示时的放电功率\n");
    BMS_warning_DP->add_Specifition();
    BMS_alarm_DP = new Specification(BMS_alarm_DP_explain, ui->BMSProtection_tW, 4, 2, \
                                   "0", "BMS_alarm_DP", \
                                   "触发BMS告警时的放电功率\n");
    BMS_alarm_DP->add_Specifition();
    BMS_fualt_DP = new Specification(BMS_fualt_DP_explain, ui->BMSProtection_tW, 5, 2, \
                                   "0", "BMS_fualt_DP", \
                                   "触发BMS故障时的放电功率\n");
    BMS_fualt_DP->add_Specifition();

}

void MEGAWin::Debugg()//调试 绘制button
{
    Debug_variable_1 = new Specification(Debug_variable_1_explain, ui->UI_Debug_Tab, 0, 1, \
                                   "0", "Debug_variable_1", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_variable_1->add_Specifition();
    Debug_variable_2 = new Specification(Debug_variable_2_explain, ui->UI_Debug_Tab, 1, 1, \
                                   "0", "Debug_variable_2", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_variable_2->add_Specifition();
    Debug_variable_3 = new Specification(Debug_variable_3_explain, ui->UI_Debug_Tab, 2, 1, \
                                   "0", "Debug_variable_3", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_variable_3->add_Specifition();
    Debug_variable_1_addr = new Specification(Debug_variable_1_addr_explain, ui->UI_Debug_Tab, 3, 1, \
                                   "4096", "Debug_variable_1_addr", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_variable_1_addr->add_Specifition();
    Debug_variable_2_addr = new Specification(Debug_variable_2_addr_explain, ui->UI_Debug_Tab, 4, 1, \
                                   "4096", "Debug_variable_2_addr", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_variable_2_addr->add_Specifition();
    Debug_variable_3_addr = new Specification(Debug_variable_3_addr_explain, ui->UI_Debug_Tab, 5, 1, \
                                   "4096", "Debug_variable_3_addr", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_variable_3_addr->add_Specifition();
    Debug_memery_var_1 = new Specification(Debug_memery_var_1_explain, ui->UI_Debug_Tab, 6, 1, \
                                   "0", "Debug_memery_var_1", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_memery_var_1->add_Specifition();
    Debug_memery_var_2 = new Specification(Debug_memery_var_2_explain, ui->UI_Debug_Tab, 7, 1, \
                                   "0", "Debug_memery_var_2", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_memery_var_2->add_Specifition();
    Debug_memery_var_3 = new Specification(Debug_memery_var_3_explain, ui->UI_Debug_Tab, 8, 1, \
                                   "0", "Debug_memery_var_3", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Debug_memery_var_3->add_Specifition();
    Input_Vol_revise = new Specification(Input_Vol_revise_explain, ui->UI_Debug_Tab, 9, 1, \
                                   "", "Input_Vol_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Input_Vol_revise->add_Specifition();
    Input_Cur_revise = new Specification(Input_Cur_revise_explain, ui->UI_Debug_Tab, 10, 1, \
                                   "", "Input_Cur_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Input_Cur_revise->add_Specifition();
    Voltage_1_5_revise = new Specification(Voltage_1_5_revise_explain, ui->UI_Debug_Tab, 0, 3, \
                                   "", "Voltage_1_5_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Voltage_1_5_revise->add_Specifition();
    Bus_Vol_revise = new Specification(Bus_Vol_revise_explain, ui->UI_Debug_Tab, 1, 3, \
                                   "", "Bus_Vol_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Bus_Vol_revise->add_Specifition();
    Grid_A_AB_Vol_revise = new Specification(Grid_A_AB_Vol_revise_explain, ui->UI_Debug_Tab, 2, 3, \
                                   "", "Grid_A_AB_Vol_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Grid_A_AB_Vol_revise->add_Specifition();
    Grid_B_BC_Vol_revise = new Specification(Grid_B_BC_Vol_revise_explain, ui->UI_Debug_Tab, 3, 3, \
                                   "", "Grid_B_BC_Vol_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Grid_B_BC_Vol_revise->add_Specifition();
    Grid_C_CA_Vol_revise = new Specification(Grid_C_CA_Vol_revise_explain, ui->UI_Debug_Tab, 4, 3, \
                                   "", "Grid_C_CA_Vol_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Grid_C_CA_Vol_revise->add_Specifition();
    Output_A_Cur_revise = new Specification(Output_A_Cur_revise_explain, ui->UI_Debug_Tab, 5, 3, \
                                   "", "Output_A_Cur_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Output_A_Cur_revise->add_Specifition();
    Output_B_Cur_revise = new Specification(Output_B_Cur_revise_explain, ui->UI_Debug_Tab, 6, 3, \
                                   "", "Output_B_Cur_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Output_B_Cur_revise->add_Specifition();
    Output_C_Cur_revise = new Specification(Output_C_Cur_revise_explain, ui->UI_Debug_Tab, 7, 3, \
                                   "", "Output_C_Cur_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Output_C_Cur_revise->add_Specifition();
    INV_A_Vol_revise = new Specification(INV_A_Vol_revise_explain, ui->UI_Debug_Tab, 8, 3, \
                                   "", "INV_A_Vol_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INV_A_Vol_revise->add_Specifition();
    INV_B_Vol_revise = new Specification(INV_B_Vol_revise_explain, ui->UI_Debug_Tab, 9, 3, \
                                   "", "INV_B_Vol_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INV_B_Vol_revise->add_Specifition();
    INV_C_Vol_revise = new Specification(INV_C_Vol_revise_explain, ui->UI_Debug_Tab, 10, 3, \
                                   "", "INV_C_Vol_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INV_C_Vol_revise->add_Specifition();

    INV_A_ind_Cur_revise = new Specification(INV_A_ind_Cur_revise_explain, ui->UI_Debug_Tab, 0, 5, \
                                   "", "INV_A_ind_Cur_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INV_A_ind_Cur_revise->add_Specifition();
    INV_B_ind_Cur_revise = new Specification(INV_B_ind_Cur_revise_explain, ui->UI_Debug_Tab, 1, 5, \
                                   "", "INV_B_ind_Cur_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INV_B_ind_Cur_revise->add_Specifition();
    INV_C_ind_Cur_revise = new Specification(INV_C_ind_Cur_revise_explain, ui->UI_Debug_Tab, 2, 5, \
                                   "", "INV_C_ind_Cur_revise", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INV_C_ind_Cur_revise->add_Specifition();
    INV_On_off_flag = new Specification(INV_On_off_flag_explain, ui->UI_Debug_Tab, 3, 5, \
                                   "0", "INV_On_off_flag", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INV_On_off_flag->add_Specifition();
    Logic_state = new Specification(Logic_state_explain, ui->UI_Debug_Tab, 4, 5, \
                                   "0", "Logic_state", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Logic_state->add_Specifition();
    INV_flag = new Specification(INV_flag_explain, ui->UI_Debug_Tab, 5, 5, \
                                   "0", "INV_flag", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INV_flag->add_Specifition();
    Grid_flag = new Specification(Grid_flag_explain, ui->UI_Debug_Tab, 6, 5, \
                                   "0", "Grid_flag", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Grid_flag->add_Specifition();
    Grid_protect_flag = new Specification(Grid_protect_flag_explain, ui->UI_Debug_Tab, 7, 5, \
                                   "0", "Grid_protect_flag", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Grid_protect_flag->add_Specifition();
    Bat_flag = new Specification(Bat_flag_explain, ui->UI_Debug_Tab, 8, 5, \
                                   "0", "Bat_flag", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    Bat_flag->add_Specifition();
    DC_bus_flag = new Specification(DC_bus_flag_explain, ui->UI_Debug_Tab, 9, 5, \
                                   "0", "DC_bus_flag", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    DC_bus_flag->add_Specifition();
    INT_main_flag = new Specification(INT_main_flag_explain, ui->UI_Debug_Tab, 10, 5, \
                                   "0", "INT_main_flag", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    INT_main_flag->add_Specifition();
    parallel_signal = new Specification(parallel_signal_explain, ui->UI_Debug_Tab, 11, 5, \
                                   "0", "parallel_signal", \
                                   "仅提供内部调试使用\nIt is used for internal debugging only");
    parallel_signal->add_Specifition();
}
