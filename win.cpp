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
    CurrentCheckMode = Mode_MANUAL;           //初始为 自发自用模式
    System_Current_Page = ParamSet_NUM;        //系统当前页
    Advanced_Current_Page = Advanced_PAGE1_NUM; //高级设置当前页
    Account_Type = Login_None;                        //当前登录角色 -- 上电默认未登录
    QFont font("Sans Serif", 13); // 创建Sans Serif一个字体，字号为13
    QApplication::setFont(font); // 设置应用程序的全局字体为宋体

    ui->setupUi(this);
    ui->UI_stackedWidget->setCurrentWidget(ui->UI_page );//开机后进入主页面
    ui->stackedWidget->setCurrentWidget(ui->Host_page);

    LoadLanguageInit(); //初始化语言
    MemoryAllocation(); //初始化内存空间
//    UIPageInit();       //初始化界面
    LCDSetting();   //实时刷新时间
    TableInitialization();//表格初始化
    LinkRelationship(); //函数关联

}

MEGAWin::~MEGAWin()
{
    delete ui;
    //变流器
    delete PCS_vol_AB_explain;
    delete PCS_vol_BC_explain;
    delete PCS_vol_CA_explain;
    delete PCS_cur_A_explain;
    delete PCS_cur_B_explain;
    delete PCS_cur_C_explain;
    delete PCS_active_power_explain;
    delete PCS_reactive_power_explain;
    delete PCS_apparent_power_explain;
    delete PCS_power_factor_explain;
    delete Batter_vol_explain;
    delete Batter_cur_explain;
    delete Batter_power_explain;
    delete Bus_vol_explain;
    delete PCS_IGBT_T_explain;
    delete PCS_Env_T_explain;
    //电网
    delete Grid_vol_AB_explain;
    delete Grid_vol_BC_explain;
    delete Grid_vol_CA_explain;
    delete Grid_cur_A_explain;
    delete Grid_cur_B_explain;
    delete Grid_cur_C_explain;
    delete Grid_active_power_explain;
    delete Grid_reactive_power_explain;
    delete Grid_apparent_power_explain;
    delete Grid_Frequency_explain;
    delete Grid_power_factor_explain;
    //负载
    delete Load_vol_AB_explain;
    delete Load_vol_BC_explain;
    delete Load_vol_CA_explain;
    delete Load_cur_A_explain;
    delete Load_cur_B_explain;
    delete Load_cur_C_explain;
    delete Load_active_power_explain;
    delete Load_reactive_power_explain;
    delete Load_apparent_power_explain;
    delete Load_power_factor_explain;
    //状态
    delete DC_input_Breaker_explain     ;      //直流输入断路器
    delete DC_Cont_explain              ;      //直流输入器
    delete Output_Cont_explain          ;      //输出接触器
    delete Output_Breaker_explain       ;      //输出断路器
    delete Grid_Cont_explain            ;      //电网接触器
    delete Grid_Breaker_explain         ;      //电网断路器
    delete MB_Breaker_explain           ;      //维修旁路
    delete converter_available_explain  ;      //变流器使能
    delete DC_Soft_start_explain        ;      //直流软启动
    delete converter_status_explain     ;      //变流器状态
    delete Reactive_P_Regulation_explain;      //无功调节方式
    delete LVRT_explain                 ;      //
    delete ForcedCharg_explain          ;      //强充
    delete Generator_signal_explain     ;      //柴发信号
    delete Reserve_explain              ;      //保留位
    delete Reserve2_explain             ;      //保留位
    delete EPO_Cont_signal1_explain     ;      //EPO节点信号
    delete EPO_Cont_signal2_explain     ;      //EPO节点信号
    delete Access_signal_explain        ;      //门禁信号
    delete Full_P_signal_explain        ;      //满功率信号
    delete Smoke_alarm_signal_explain   ;      //烟感信号
    delete Hight_temp_signal_explain    ;      //高温信号
    /***************************历史记录**********************************/
    delete Grade_explain       ;
    delete Grade2_explain      ;
    delete Grade3_explain      ;
    delete Grade4_explain      ;
    delete Grade5_explain      ;
    delete Grade6_explain      ;
    delete Grade7_explain      ;
    delete Grade8_explain      ;
    delete Grade9_explain      ;
    delete Grade10_explain     ;
    delete Grade11_explain     ;
    delete Grade12_explain     ;
    delete Grade13_explain     ;
    delete Grade14_explain     ;
    delete Grade15_explain     ;
    delete StartTime_explain   ;
    delete StartTime2_explain  ;
    delete StartTime3_explain  ;
    delete StartTime4_explain  ;
    delete StartTime5_explain  ;
    delete StartTime6_explain  ;
    delete StartTime7_explain  ;
    delete StartTime8_explain  ;
    delete StartTime9_explain  ;
    delete StartTime10_explain ;
    delete StartTime11_explain ;
    delete StartTime12_explain ;
    delete StartTime13_explain ;
    delete StartTime14_explain ;
    delete StartTime15_explain ;
    delete EndTime_explain     ;
    delete EndTime2_explain    ;
    delete EndTime3_explain    ;
    delete EndTime4_explain    ;
    delete EndTime5_explain    ;
    delete EndTime6_explain    ;
    delete EndTime7_explain    ;
    delete EndTime8_explain    ;
    delete EndTime9_explain    ;
    delete EndTime10_explain   ;
    delete EndTime11_explain   ;
    delete EndTime12_explain   ;
    delete EndTime13_explain   ;
    delete EndTime14_explain   ;
    delete EndTime15_explain   ;
    delete Describe_explain    ;
    delete Describe2_explain   ;
    delete Describe3_explain   ;
    delete Describe4_explain   ;
    delete Describe5_explain   ;
    delete Describe6_explain   ;
    delete Describe7_explain   ;
    delete Describe8_explain   ;
    delete Describe9_explain   ;
    delete Describe10_explain  ;
    delete Describe11_explain  ;
    delete Describe12_explain  ;
    delete Describe13_explain  ;
    delete Describe14_explain  ;
    delete Describe15_explain  ;

    /***************************操作日志**********************************/
    delete ModificationTime_explain    ;
    delete ModificationTime2_explain   ;
    delete ModificationTime3_explain   ;
    delete ModificationTime4_explain   ;
    delete ModificationTime5_explain   ;
    delete ModificationTime6_explain   ;
    delete ModificationTime9_explain   ;
    delete ModificationTime11_explain  ;
    delete ModificationTime12_explain  ;
    delete EventRecord_explain         ;
    delete EventRecord2_explain        ;
    delete EventRecord3_explain        ;
    delete EventRecord4_explain        ;
    delete EventRecord5_explain        ;
    delete EventRecord6_explain        ;
    delete EventRecord9_explain        ;
    delete EventRecord11_explain       ;
    delete EventRecord12_explain       ;
    /**********************基础参数设置*************************/
    delete Grid_connected_mode_explain;//并网方式
    delete Constant_power_explain     ;//恒功率
    delete EMS_Comm_type_explain      ;//EMS通讯方式
    delete EMS_CAN_Protocol_explain   ;//EMS CAN 协议
    delete Control_mode_explain       ;//控制模式
    delete Battery_type_explain       ;//电池类型
    delete BMS_Comm_type_explain      ;//电池通信方式
    delete BAT_manufacturers_explain  ;//电池协议

    delete Grid_connected_mode1_explain;//并网方式
    delete Constant_power1_explain     ;//恒功率
    delete EMS_Comm_type1_explain      ;//EMS通讯方式
    delete EMS_CAN_Protocol1_explain   ;//EMS CAN 协议
    delete Control_mode1_explain       ;//控制模式
    delete Battery_type1_explain       ;//电池类型
    delete BMS_Comm_type1_explain      ;//电池通信方式
    delete BAT_manufacturers1_explain  ;//电池协议

    delete Grid_connected_mode2_explain;//并网方式
    delete Constant_power2_explain     ;//恒功率
    delete EMS_Comm_type2_explain      ;//EMS通讯方式
    delete EMS_CAN_Protocol2_explain   ;//EMS CAN 协议
    delete Control_mode2_explain       ;//控制模式
    delete Battery_type2_explain       ;//电池类型
    delete BMS_Comm_type2_explain      ;//电池通信方式
    delete BAT_manufacturers2_explain  ;//电池协议

    delete StartSOC_explain           ;//启动SOC
    delete StopSOC_explain            ;//停止SOC
    delete StartCellVol_explain       ;//启动单体电压
    delete StopCellVol_explain        ;//停止单体电压
    delete StartTotalVol_explain      ;//启动总压
    delete StopTotalVol_explain       ;//停止总压
    delete BackupChargingPower_explain;//后备充电功率
    delete MonthlyCycleDate_explain   ;//月循环日期
    delete DG_Charge_SOC_explain      ;//柴发充电SOC
    delete Grid_Charge_SOC_explain    ;//电网充电SOC
    delete Grid_Capacity_explain      ;//电网容量
    delete Charge_Stop_SOC_explain    ;//充电SOC说明
    delete Disharge_Stop_SOC_explain  ;//放电SOC说明
    /***************************电池设置-锂电****************************/
    delete DOD_OnGrid_explain                      ;//并网DOD说明
    delete DOD_OffGrid_explain                     ;//离网DOD说明
    delete Charge_Volt_Upper_Limit_explain         ;//充电电压上限说明
    delete Charge_Volt_upper_Limit_delta_explain   ;//充电电压上限回差说明
    delete Disc_Volt_lower_Limit_explain           ;//放电电压限制说明
    delete Discharge_Volt_upper_Limit_delta_explain;//放电电压下限回差说明
    delete Charge_Current_Limit_explain            ;//充电电流限制说明
    delete Discharge_Current_Limit_explain         ;//放电电流限制说明
    delete Gen_turn_off_SOC_explain                ;//柴发关闭SOC说明
    delete Gen_turn_on_SOC_explain                 ;//柴发开启SOC说明
    delete ForceCharge_start_explain               ;//强充开启说明
    delete ForceCharge_top_explain                 ;//强充结束说明
    /***************************电池设置-铅酸****************************/
    delete Capacity_explain                   ;
    delete Cell_number_2V_explain             ;
    delete Bat_float_vol_explain              ;
    delete Bat_filling_vol_explain            ;
    delete Charge_limiting_value_explain      ;
    delete Discharge_limiting_value_explain   ;
    delete Generator_turn_off_SOC_B1_explain  ;
    delete Generator_turn_on_SOC_A1_explain   ;
    delete Grid_off_EOD_explain               ;
    delete Grid_on_EOD_explain                ;
    delete Uniform_To_Flushing_current_explain;
    delete Flushing_To_Uniform_current_explain;
    /*******************************自动运行*******************************/
    delete Check1_explain ; delete Check2_explain ; delete Check3_explain ;
    delete Check4_explain ; delete Check5_explain ; delete Check6_explain ;
    delete Check7_explain ; delete Check8_explain ; delete Check9_explain ;
    delete Check10_explain; delete Check11_explain; delete Check12_explain ;
    delete Check13_explain; delete Check14_explain; delete Check15_explain ;
    delete Check16_explain; delete Check17_explain; delete Check18_explain ;
    delete Check19_explain; delete Check20_explain;

    delete Start_T1_explain  ; delete Start_T2_explain  ; delete Start_T3_explain ;
    delete Start_T4_explain  ; delete Start_T5_explain  ; delete Start_T6_explain ;
    delete Start_T7_explain  ; delete Start_T8_explain  ; delete Start_T9_explain ;
    delete Start_T10_explain ; delete Start_T11_explain ; delete Start_T12_explain ;
    delete Start_T13_explain ; delete Start_T14_explain ; delete Start_T15_explain ;
    delete Start_T16_explain ; delete Start_T17_explain ; delete Start_T18_explain ;
    delete Start_T19_explain ; delete Start_T20_explain ;

    delete End_T1_explain  ; delete End_T2_explain  ; delete End_T3_explain ;
    delete End_T4_explain  ; delete End_T5_explain  ; delete End_T6_explain ;
    delete End_T7_explain  ; delete End_T8_explain  ; delete End_T9_explain ;
    delete End_T10_explain ; delete End_T11_explain ; delete End_T12_explain ;
    delete End_T13_explain ; delete End_T14_explain ; delete End_T15_explain ;
    delete End_T16_explain ; delete End_T17_explain ; delete End_T18_explain ;
    delete End_T19_explain ; delete End_T20_explain ;

    delete Start_T1_explain  ; delete Start_T2_explain  ; delete Start_T3_explain ;
    delete Start_T4_explain  ; delete Start_T5_explain  ; delete Start_T6_explain ;
    delete Start_T7_explain  ; delete Start_T8_explain  ; delete Start_T9_explain ;
    delete Start_T10_explain ; delete Start_T11_explain ; delete Start_T12_explain ;
    delete Start_T13_explain ; delete Start_T14_explain ; delete Start_T15_explain ;
    delete Start_T16_explain ; delete Start_T17_explain ; delete Start_T18_explain ;
    delete Start_T19_explain ; delete Start_T20_explain ;


    delete Power1_explain  ; delete Power2_explain  ; delete Power3_explain ;
    delete Power4_explain  ; delete Power5_explain  ; delete Power6_explain ;
    delete Power7_explain  ; delete Power8_explain  ; delete Power9_explain ;
    delete Power10_explain ; delete Power11_explain ; delete Power12_explain ;
    delete Power13_explain ; delete Power14_explain ; delete Power15_explain ;
    delete Power16_explain ; delete Power17_explain ; delete Power18_explain ;
    delete Power19_explain ; delete Power20_explain ;

    delete TimePeriodButtonList;

    /*************************功能设置1*************************/
    delete Power_control_type_explain        ;    //功率控制类型说明
    delete Output_reactive_power_mode_explain;  //输出无功方式说明
    delete Output_reactive_power_explain     ;  //输出无功功率说明
    delete Output_power_factor_explain       ;    //输出功率因素说明
    delete Constant_voltage_explain          ; //恒压说明
    delete Constant_current_explain          ;  //恒流说明
    delete Output_power_limit_explain        ;    //输出功率上限说明
    delete Machine_number_explain            ;    //设备号说明
    delete Parallel_explain                  ;  //并机说明
    delete Host_Address_explain              ;  //主机地址说明
    delete ModbusDeviationAddress_explain    ;  //Modbus偏移地址说明
    delete serial_port_2_explain             ; //串口2说明
    delete serial_port_3_explain             ; //串口3说明
    delete serial_port_4_explain             ; //串口4说明
    delete serial_port_5_explain             ; //串口5说明
    delete serial_port_6_explain             ; //串口6说明
    delete Can_port_1_explain                ;    //CAN1说明
    delete Can_port_2_explain                ;    //CAN2说明
    delete Language_explain                  ;  //语言说明
    delete Sounds_explain                    ;    //声音说明
    delete MeterModel_explain                ; //电表型号
    delete AntiBackflowPowerTolerance_explain;//防逆流功率容差
    delete BmsComFaultTime_explain           ;   //BMS通信故障判定时间
    delete EMSComFaultModel_explain          ;  //EMS通信故障判定时间
    delete System_upgrade_explain            ;    //系统升级说明
    delete Clear_Data_explain                ;  //清除数据说明
    delete Restore_factory_explain           ;  //恢复出厂说明
    /*************************功能设置2*************************/
    delete ChargingPowerLimit_explain        ;//充电功率限制
    delete DischargingPowerLimit_explain     ;//放电功率限制
    delete UserPassPort_explain              ;  //用户密码说明
    delete RootPassport_explain              ;  //超级权限说明
    delete BackupSetParameters_explain       ;//备份设置参数
    delete RestoreBackupSetParameters_explain;//恢复备份设置参数
    /***************************系统参数**************************/
    delete Change_rate_of_power_explain                ;  //功率变化率说明
    delete Grid_frequency_upper_limit_explain          ;  //电网频率变化范围上限说明
    delete Grid_frequency_lower_limit_explain          ;  //电网频率变化范围下限说明
    delete Vol_protection_upper_limit_explain          ;  //电压保护范围上限说明
    delete Vol_protection_lower_limit_explain          ;  //电压保护范围下限说明
    delete HVRT_enable_explain                         ;  //高穿使能说明
    delete LVRT_enable_explain                         ;  //低穿使能说明
    delete Machine_type_explain                        ;  //机器型号说明
    delete Machine_capacity_explain                    ;  //机器容量说明
    delete Output_Fre_grade_explain                    ;  //输出频率等级说明
    delete Output_vol_level_explain                    ;  //输出电压等级说明
    delete Converter_side_vol_level_explain            ;  //逆变电压等级说明(变比)
    delete Grid_connected_mode_of_Inv_explain          ;  //逆变器并网方式说明(变流器防逆流)
    delete PrimaryFrequencyModulationDeadZone_explain  ;//一次调频死区
    delete ActiveFrequencyModulationCoefficient_explain;//有功调频系数
    delete PowerGridRecoveryTime_explain               ;//电网恢复时间
    delete Insulation_detection_enable_explain         ;  //绝缘监测使能说明
    delete Inertia_enable_explain                      ;  //转动惯量使能说明
    delete CV_parallel_explain                         ;  //恒压并机说明
    delete AFD_enable_explain                          ;  //孤岛使能说明
    delete PrimaryFreq_enable_explain                  ;  //一次调频使能说明
}
/******语言初始化*******/
void MEGAWin::LoadLanguageInit()
{
    translator = new QTranslator(qApp);
    if(LanguageType == CHINESE)//开机语言 中文
    {
        translator->load(":/Language/CN.qm");
        qApp->installTranslator(translator);
        ui->retranslateUi(this);
        LanguageType = CHINESE;
        ui->label_42->setStyleSheet("border-image: url(:/new_ui/UI/Battery_area2.png);");
    }
    else if(LanguageType == ENGLISH)//开机语言 英文
    {
        translator->load(":/Language/EN.qm");
        qApp->installTranslator(translator);
        ui->retranslateUi(this);
        LanguageType = ENGLISH;
        ui->label_42->setStyleSheet("border-image: url(:/new_ui/UI/Battery_area3.png);");
    }
}
/************LCD标签初始化和定时器设置***********/
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
/*关联函数*/
void MEGAWin::LinkRelationship()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerOut()));    //关联定时器，以便实时更新时间
    connect(Menu_Group, SIGNAL(buttonClicked(int)), this,SLOT(My_menuAction(int)));//菜单跳转
    connect(SystemMode_Group, SIGNAL(buttonClicked(int)), this,SLOT(WordingMode(int)));//工作模式跳转页面
    connect(ExitReturn_Group, SIGNAL(buttonClicked(int)), this,SLOT(Return(int)));//返回函数
    connect(HomeClick_Group, SIGNAL(buttonClicked(int)), this,SLOT(Home_Click(int)));//主页点击控件函数
//    connect(ui->ChangeLanguage_btn, SIGNAL(clicked(bool)), this, SLOT(ChangeLanguage_btn_clicked()));//切换语言点击槽
}
/*内存空间初始化*/
void MEGAWin::MemoryAllocation()
{
    Mode_Str.clear();
    Mode_title_Str.clear();
    Mode_Str<<tr("Manual")<<tr("Peak Valley")<<tr("UPS")<<tr("Transient Expansion")<<tr("Steady-State Expansion")<<tr("Advanced Settings");
    Mode_title_Str<<tr("Parameters Setting")<<tr("Lithum Settings")<<tr("Lead Settings")<<tr("Operation Time")<<tr("Function Senttings 1")<<tr("Function Senttings 2")\
                 <<tr("System Parameter Settings")<<tr("External Device Settings")<<tr("BMS Protection Settings")<<tr("Debug Settings")<<tr("Port data")<<tr("Monitor Debug Settings");

    //菜单控件组
    Menu_Group = new QButtonGroup();
    Menu_Group->addButton(ui->Login_bt,USER_LOGIN);
    Menu_Group->addButton(ui->Host_btn,HOSTPAGE);
    Menu_Group->addButton(ui->Host_b_btn,HOSTPAGE);
    Menu_Group->addButton(ui->Host_p_btn,HOSTPAGE);
    Menu_Group->addButton(ui->RT_Data_btn,RTDATAPAGE);
    Menu_Group->addButton(ui->RT_Data_b_btn,RTDATAPAGE);
    Menu_Group->addButton(ui->RT_Data_p_btn,RTDATAPAGE);
    Menu_Group->addButton(ui->Record_btn,RECORDPAGE);
    Menu_Group->addButton(ui->Record_b_btn,RECORDPAGE);
    Menu_Group->addButton(ui->Record_p_btn,RECORDPAGE);
    Menu_Group->addButton(ui->System_btn,SYSTEMPAGE);
    Menu_Group->addButton(ui->System_b_btn,SYSTEMPAGE);
    Menu_Group->addButton(ui->System_p_btn,SYSTEMPAGE);
    Menu_Group->addButton(ui->InvTurnOff_btn,MACHINECLOSE);//变流器开启
    Menu_Group->addButton(ui->Inv_Standby_btn,MACHINESTANDBY);
    Menu_Group->addButton(ui->InvTurnOn_btn,MACHINEOPEN);
    Menu_Group->addButton(ui->Sys_Inf_btn,SYSTEMINFORMATION);

    //系统工作模式
    SystemMode_Group = new QButtonGroup();
    SystemMode_Group->addButton(ui->Manual_bt,Mode_MANUAL);
    SystemMode_Group->addButton(ui->PeakValley_bt,Mode_PeakValley);
    SystemMode_Group->addButton(ui->UPS_bt,Mode_UPS);
    SystemMode_Group->addButton(ui->Transient_bt,Mode_TransientExpansion);
    SystemMode_Group->addButton(ui->SteadyState_bt,Mode_SteadyStateExpansion);
    SystemMode_Group->addButton(ui->Advanced_bt,ADVANCED_SETTING);

    //返回控件组
    ExitReturn_Group = new QButtonGroup();
    ExitReturn_Group->addButton(ui->IntrBack_bt,0);
    ExitReturn_Group->addButton(ui->Save_bt,1);
    ExitReturn_Group->addButton(ui->Exit_bt,2);

    //主页点击控件组
    HomeClick_Group = new QButtonGroup();
    HomeClick_Group->addButton(ui->Bypass_Load_Btn,1);
    HomeClick_Group->addButton(ui->Bypass_Running_btn,2);
    HomeClick_Group->addButton(ui->Bypass_Batt_btn,3);
    HomeClick_Group->addButton(ui->Bypass_Grid_btn,4);
    HomeClick_Group->addButton(ui->Alarm_Button,5);

    ButtonToTable = new SpecificationData(this);

    //变流器
    PCS_vol_AB_explain          = new QPushButton;
    PCS_vol_BC_explain          = new QPushButton;
    PCS_vol_CA_explain          = new QPushButton;
    PCS_cur_A_explain           = new QPushButton;
    PCS_cur_B_explain           = new QPushButton;
    PCS_cur_C_explain           = new QPushButton;
    PCS_active_power_explain    = new QPushButton;
    PCS_reactive_power_explain  = new QPushButton;
    PCS_apparent_power_explain  = new QPushButton;
    PCS_power_factor_explain    = new QPushButton;
    Batter_vol_explain          = new QPushButton;
    Batter_cur_explain          = new QPushButton;
    Batter_power_explain        = new QPushButton;
    Bus_vol_explain             = new QPushButton;
    PCS_IGBT_T_explain          = new QPushButton;
    PCS_Env_T_explain           = new QPushButton;
    //电网
    Grid_vol_AB_explain         = new QPushButton;
    Grid_vol_BC_explain         = new QPushButton;
    Grid_vol_CA_explain         = new QPushButton;
    Grid_cur_A_explain          = new QPushButton;
    Grid_cur_B_explain          = new QPushButton;
    Grid_cur_C_explain          = new QPushButton;
    Grid_active_power_explain   = new QPushButton;
    Grid_reactive_power_explain = new QPushButton;
    Grid_apparent_power_explain = new QPushButton;
    Grid_power_factor_explain   = new QPushButton;
    Grid_Frequency_explain      = new QPushButton;
    //负载
    Load_vol_AB_explain         = new QPushButton;
    Load_vol_BC_explain         = new QPushButton;
    Load_vol_CA_explain         = new QPushButton;
    Load_cur_A_explain          = new QPushButton;
    Load_cur_B_explain          = new QPushButton;
    Load_cur_C_explain          = new QPushButton;
    Load_active_power_explain   = new QPushButton;
    Load_reactive_power_explain = new QPushButton;
    Load_apparent_power_explain = new QPushButton;
    Load_power_factor_explain   = new QPushButton;
    //PCS状态
    DC_input_Breaker_explain        = new QPushButton;      //直流输入断路器
    DC_Cont_explain                 = new QPushButton;      //直流输入器
    Output_Cont_explain             = new QPushButton;      //输出接触器
    Output_Breaker_explain          = new QPushButton;      //输出断路器
    Grid_Cont_explain               = new QPushButton;      //电网接触器
    Grid_Breaker_explain            = new QPushButton;      //电网断路器
    MB_Breaker_explain              = new QPushButton;      //维修旁路
    converter_available_explain     = new QPushButton;      //变流器使能
    DC_Soft_start_explain           = new QPushButton;      //直流软启动
    converter_status_explain        = new QPushButton;      //变流器状态
    Reactive_P_Regulation_explain   = new QPushButton;      //无功调节方式
    LVRT_explain                    = new QPushButton;      //
    ForcedCharg_explain             = new QPushButton;      //强充
    Generator_signal_explain        = new QPushButton;      //柴发信号
    Reserve_explain                 = new QPushButton;      //保留位
    Reserve2_explain                = new QPushButton;      //保留位
    EPO_Cont_signal1_explain        = new QPushButton;      //EPO节点信号
    EPO_Cont_signal2_explain        = new QPushButton;      //EPO节点信号
    Access_signal_explain           = new QPushButton;      //门禁信号
    Full_P_signal_explain           = new QPushButton;      //满功率信号
    Smoke_alarm_signal_explain      = new QPushButton;      //烟感信号
    Hight_temp_signal_explain       = new QPushButton;      //高温信号
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
    /***************************操作日志**********************************/
    ModificationTime_explain    = new QPushButton;
    ModificationTime2_explain   = new QPushButton;
    ModificationTime3_explain   = new QPushButton;
    ModificationTime4_explain   = new QPushButton;
    ModificationTime5_explain   = new QPushButton;
    ModificationTime6_explain   = new QPushButton;
    ModificationTime9_explain   = new QPushButton;
    ModificationTime11_explain  = new QPushButton;
    ModificationTime12_explain  = new QPushButton;
    EventRecord_explain         = new QPushButton;
    EventRecord2_explain        = new QPushButton;
    EventRecord3_explain        = new QPushButton;
    EventRecord4_explain        = new QPushButton;
    EventRecord5_explain        = new QPushButton;
    EventRecord6_explain        = new QPushButton;
    EventRecord9_explain        = new QPushButton;
    EventRecord11_explain       = new QPushButton;
    EventRecord12_explain       = new QPushButton;
    /**********************基础参数设置*************************/
    Grid_connected_mode_explain = new QPushButton;//并网方式
    Constant_power_explain      = new QPushButton;//恒功率
    EMS_Comm_type_explain       = new QPushButton;//EMS通讯方式
    EMS_CAN_Protocol_explain    = new QPushButton;//EMS CAN 协议
    Control_mode_explain        = new QPushButton;//控制模式
    Battery_type_explain        = new QPushButton;//电池类型
    BMS_Comm_type_explain       = new QPushButton;//电池通信方式
    BAT_manufacturers_explain   = new QPushButton;//电池协议

    Grid_connected_mode1_explain = new QPushButton;//并网方式
    Constant_power1_explain      = new QPushButton;//恒功率
    EMS_Comm_type1_explain       = new QPushButton;//EMS通讯方式
    EMS_CAN_Protocol1_explain    = new QPushButton;//EMS CAN 协议
    Control_mode1_explain        = new QPushButton;//控制模式
    Battery_type1_explain        = new QPushButton;//电池类型
    BMS_Comm_type1_explain       = new QPushButton;//电池通信方式
    BAT_manufacturers1_explain   = new QPushButton;//电池协议

    Grid_connected_mode2_explain = new QPushButton;//并网方式
    Constant_power2_explain      = new QPushButton;//恒功率
    EMS_Comm_type2_explain       = new QPushButton;//EMS通讯方式
    EMS_CAN_Protocol2_explain    = new QPushButton;//EMS CAN 协议
    Control_mode2_explain        = new QPushButton;//控制模式
    Battery_type2_explain        = new QPushButton;//电池类型
    BMS_Comm_type2_explain       = new QPushButton;//电池通信方式
    BAT_manufacturers2_explain   = new QPushButton;//电池协议

    StartSOC_explain            = new QPushButton;//启动SOC
    StopSOC_explain             = new QPushButton;//停止SOC
    StartCellVol_explain        = new QPushButton;//启动单体电压
    StopCellVol_explain         = new QPushButton;//停止单体电压
    StartTotalVol_explain       = new QPushButton;//启动总压
    StopTotalVol_explain        = new QPushButton;//停止总压
    BackupChargingPower_explain = new QPushButton;//后备充电功率
    MonthlyCycleDate_explain    = new QPushButton;//月循环日期
    DG_Charge_SOC_explain       = new QPushButton;//柴发充电SOC
    Grid_Charge_SOC_explain     = new QPushButton;//电网充电SOC
    Grid_Capacity_explain       = new QPushButton;//电网容量
    Charge_Stop_SOC_explain     = new QPushButton;//充电SOC说明
    Disharge_Stop_SOC_explain   = new QPushButton;//放电SOC说明
    /***************************电池设置-锂电****************************/
    DOD_OnGrid_explain                          = new QPushButton;//并网DOD说明
    DOD_OffGrid_explain                         = new QPushButton;//离网DOD说明
    Charge_Volt_Upper_Limit_explain             = new QPushButton;//充电电压上限说明
    Charge_Volt_upper_Limit_delta_explain       = new QPushButton;//充电电压上限回差说明
    Disc_Volt_lower_Limit_explain               = new QPushButton;//放电电压限制说明
    Discharge_Volt_upper_Limit_delta_explain    = new QPushButton;//放电电压下限回差说明
    Charge_Current_Limit_explain                = new QPushButton;//充电电流限制说明
    Discharge_Current_Limit_explain             = new QPushButton;//放电电流限制说明
    Gen_turn_off_SOC_explain                    = new QPushButton;//柴发关闭SOC说明
    Gen_turn_on_SOC_explain                     = new QPushButton;//柴发开启SOC说明
    ForceCharge_start_explain                   = new QPushButton;//强充开启说明
    ForceCharge_top_explain                     = new QPushButton;//强充结束说明
    /***************************电池设置-铅酸****************************/
    Capacity_explain                    = new QPushButton;
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
    /***************************自动运行**************************/
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

    TimePeriodButtonList = new QList<QPushButton*>;
    TimePeriodButtonList->append(Check1_explain);
    TimePeriodButtonList->append(Check2_explain);
    TimePeriodButtonList->append(Check3_explain);
    TimePeriodButtonList->append(Check4_explain);
    TimePeriodButtonList->append(Check5_explain);
    TimePeriodButtonList->append(Check6_explain);
    TimePeriodButtonList->append(Check7_explain);
    TimePeriodButtonList->append(Check8_explain);
    TimePeriodButtonList->append(Check9_explain);
    TimePeriodButtonList->append(Check10_explain);
    TimePeriodButtonList->append(Check11_explain);
    TimePeriodButtonList->append(Check12_explain);
    TimePeriodButtonList->append(Check13_explain);
    TimePeriodButtonList->append(Check14_explain);
    TimePeriodButtonList->append(Check15_explain);
    TimePeriodButtonList->append(Check16_explain);
    TimePeriodButtonList->append(Check17_explain);
    TimePeriodButtonList->append(Check18_explain);
    TimePeriodButtonList->append(Check19_explain);
    TimePeriodButtonList->append(Check20_explain);

    TimePeriodButtonList->append(Start_T1_explain);
    TimePeriodButtonList->append(Start_T2_explain);
    TimePeriodButtonList->append(Start_T3_explain);
    TimePeriodButtonList->append(Start_T4_explain);
    TimePeriodButtonList->append(Start_T5_explain);
    TimePeriodButtonList->append(Start_T6_explain);
    TimePeriodButtonList->append(Start_T7_explain);
    TimePeriodButtonList->append(Start_T8_explain);
    TimePeriodButtonList->append(Start_T9_explain);
    TimePeriodButtonList->append(Start_T10_explain);
    TimePeriodButtonList->append(Start_T11_explain);
    TimePeriodButtonList->append(Start_T12_explain);
    TimePeriodButtonList->append(Start_T13_explain);
    TimePeriodButtonList->append(Start_T14_explain);
    TimePeriodButtonList->append(Start_T15_explain);
    TimePeriodButtonList->append(Start_T16_explain);
    TimePeriodButtonList->append(Start_T17_explain);
    TimePeriodButtonList->append(Start_T18_explain);
    TimePeriodButtonList->append(Start_T19_explain);
    TimePeriodButtonList->append(Start_T20_explain);

    TimePeriodButtonList->append(End_T1_explain);
    TimePeriodButtonList->append(End_T2_explain);
    TimePeriodButtonList->append(End_T3_explain);
    TimePeriodButtonList->append(End_T4_explain);
    TimePeriodButtonList->append(End_T5_explain);
    TimePeriodButtonList->append(End_T6_explain);
    TimePeriodButtonList->append(End_T7_explain);
    TimePeriodButtonList->append(End_T8_explain);
    TimePeriodButtonList->append(End_T9_explain);
    TimePeriodButtonList->append(End_T10_explain);
    TimePeriodButtonList->append(End_T11_explain);
    TimePeriodButtonList->append(End_T12_explain);
    TimePeriodButtonList->append(End_T13_explain);
    TimePeriodButtonList->append(End_T14_explain);
    TimePeriodButtonList->append(End_T15_explain);
    TimePeriodButtonList->append(End_T16_explain);
    TimePeriodButtonList->append(End_T17_explain);
    TimePeriodButtonList->append(End_T18_explain);
    TimePeriodButtonList->append(End_T19_explain);
    TimePeriodButtonList->append(End_T20_explain);

    TimePeriodButtonList->append(State1_explain);
    TimePeriodButtonList->append(State2_explain);
    TimePeriodButtonList->append(State3_explain);
    TimePeriodButtonList->append(State4_explain);
    TimePeriodButtonList->append(State5_explain);
    TimePeriodButtonList->append(State6_explain);
    TimePeriodButtonList->append(State7_explain);
    TimePeriodButtonList->append(State8_explain);
    TimePeriodButtonList->append(State9_explain);
    TimePeriodButtonList->append(State10_explain);
    TimePeriodButtonList->append(State11_explain);
    TimePeriodButtonList->append(State12_explain);
    TimePeriodButtonList->append(State13_explain);
    TimePeriodButtonList->append(State14_explain);
    TimePeriodButtonList->append(State15_explain);
    TimePeriodButtonList->append(State16_explain);
    TimePeriodButtonList->append(State17_explain);
    TimePeriodButtonList->append(State18_explain);
    TimePeriodButtonList->append(State19_explain);
    TimePeriodButtonList->append(State20_explain);

    TimePeriodButtonList->append(Power1_explain);
    TimePeriodButtonList->append(Power2_explain);
    TimePeriodButtonList->append(Power3_explain);
    TimePeriodButtonList->append(Power4_explain);
    TimePeriodButtonList->append(Power5_explain);
    TimePeriodButtonList->append(Power6_explain);
    TimePeriodButtonList->append(Power7_explain);
    TimePeriodButtonList->append(Power8_explain);
    TimePeriodButtonList->append(Power9_explain);
    TimePeriodButtonList->append(Power10_explain);
    TimePeriodButtonList->append(Power11_explain);
    TimePeriodButtonList->append(Power12_explain);
    TimePeriodButtonList->append(Power13_explain);
    TimePeriodButtonList->append(Power14_explain);
    TimePeriodButtonList->append(Power15_explain);
    TimePeriodButtonList->append(Power16_explain);
    TimePeriodButtonList->append(Power17_explain);
    TimePeriodButtonList->append(Power18_explain);
    TimePeriodButtonList->append(Power19_explain);
    TimePeriodButtonList->append(Power20_explain);
    /*************************功能设置1*************************/
    Power_control_type_explain          = new QPushButton;    //功率控制类型说明
    Output_reactive_power_mode_explain  = new QPushButton;  //输出无功方式说明
    Output_reactive_power_explain       = new QPushButton;  //输出无功功率说明
    Output_power_factor_explain         = new QPushButton;    //输出功率因素说明
    Constant_voltage_explain            = new QPushButton; //恒压说明
    Constant_current_explain            = new QPushButton;  //恒流说明
    Output_power_limit_explain          = new QPushButton;    //输出功率上限说明
    Machine_number_explain              = new QPushButton;    //设备号说明
    Parallel_explain                    = new QPushButton;  //并机说明
    Host_Address_explain                = new QPushButton;  //主机地址说明
    ModbusDeviationAddress_explain      = new QPushButton;  //Modbus偏移地址说明
    serial_port_2_explain               = new QPushButton; //串口2说明
    serial_port_3_explain               = new QPushButton; //串口3说明
    serial_port_4_explain               = new QPushButton; //串口4说明
    serial_port_5_explain               = new QPushButton; //串口5说明
    serial_port_6_explain               = new QPushButton; //串口6说明
    Can_port_1_explain                  = new QPushButton;    //CAN1说明
    Can_port_2_explain                  = new QPushButton;    //CAN2说明
    Language_explain                    = new QPushButton;  //语言说明
    Sounds_explain                      = new QPushButton;    //声音说明
    MeterModel_explain                  = new QPushButton; //电表型号
    AntiBackflowPowerTolerance_explain  = new QPushButton;//防逆流功率容差
    BmsComFaultTime_explain             = new QPushButton;   //BMS通信故障判定时间
    EMSComFaultModel_explain            = new QPushButton;  //EMS通信故障判定时间
    System_upgrade_explain              = new QPushButton;    //系统升级说明
    Clear_Data_explain                  = new QPushButton;  //清除数据说明
    Restore_factory_explain             = new QPushButton;  //恢复出厂说明
    /*************************功能设置2*************************/
    ChargingPowerLimit_explain          = new QPushButton;//充电功率限制
    DischargingPowerLimit_explain       = new QPushButton;//放电功率限制
    UserPassPort_explain                = new QPushButton;  //用户密码说明
    RootPassport_explain                = new QPushButton;  //超级权限说明
    BackupSetParameters_explain         = new QPushButton;//备份设置参数
    RestoreBackupSetParameters_explain  = new QPushButton;//恢复备份设置参数
    /***************************系统参数**************************/
    Change_rate_of_power_explain                = new QPushButton;  //功率变化率说明
    Grid_frequency_upper_limit_explain          = new QPushButton;  //电网频率变化范围上限说明
    Grid_frequency_lower_limit_explain          = new QPushButton;  //电网频率变化范围下限说明
    Vol_protection_upper_limit_explain          = new QPushButton;  //电压保护范围上限说明
    Vol_protection_lower_limit_explain          = new QPushButton;  //电压保护范围下限说明
    HVRT_enable_explain                         = new QPushButton;  //高穿使能说明
    LVRT_enable_explain                         = new QPushButton;  //低穿使能说明
    Machine_type_explain                        = new QPushButton;  //机器型号说明
    Machine_capacity_explain                    = new QPushButton;  //机器容量说明
    Output_Fre_grade_explain                    = new QPushButton;  //输出频率等级说明
    Output_vol_level_explain                    = new QPushButton;  //输出电压等级说明
    Converter_side_vol_level_explain            = new QPushButton;  //逆变电压等级说明(变比)
    Grid_connected_mode_of_Inv_explain          = new QPushButton;  //逆变器并网方式说明(变流器防逆流)
    PrimaryFrequencyModulationDeadZone_explain  = new QPushButton;//一次调频死区
    ActiveFrequencyModulationCoefficient_explain= new QPushButton;//有功调频系数
    PowerGridRecoveryTime_explain               = new QPushButton;//电网恢复时间
    Insulation_detection_enable_explain         = new QPushButton;  //绝缘监测使能说明
    Inertia_enable_explain                      = new QPushButton;  //转动惯量使能说明
    CV_parallel_explain                         = new QPushButton;  //恒压并机说明
    AFD_enable_explain                          = new QPushButton;  //孤岛使能说明
    PrimaryFreq_enable_explain                  = new QPushButton;  //一次调频使能说明
}
/*表格初始化*/
void MEGAWin::TableInitialization()
{
    PCS_DataTableInit();//PCS实时数据
    PCS_StateTableInit();//PCS状态
    History();//历史记录
    OperationLog();//操作日志
    WorkingModeInit();//工作模式
    TimePeriodInit();//时间段
    AdvancedSetInit();//高级设置

    SetControlToTable();
}
/*更新时间显示*/
void MEGAWin::onTimerOut()
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
/*根据菜单索引打开相应的界面*/
void MEGAWin::My_menuAction(int Index)
{
    switch (Index)
    {
        //主页
        case HOSTPAGE:
            {
                ui->UI_stackedWidget->setCurrentWidget(ui->UI_page);
                ui->stackedWidget->setCurrentWidget(ui->Host_page);
            }
            break;
        //实时数据页
        case RTDATAPAGE:
            {
                ui->UI_stackedWidget->setCurrentWidget(ui->UI_page);
                ui->stackedWidget->setCurrentWidget(ui->Status_page);
                ui->Run_tabWidget->setCurrentWidget(ui->RT_Data_page);
            }
            break;
        //历史记录页
        case RECORDPAGE:
            {
                ui->UI_stackedWidget->setCurrentWidget(ui->UI_page);
                ui->stackedWidget->setCurrentWidget(ui->Record_page);
                ui->Record_tabWidget->setCurrentWidget(ui->DataReport_page);
                ui->Report_tab->setCurrentWidget(ui->Report_tabPage_T);
                ui->dateEdit->setDate(QDateTime::currentDateTime().date());
            }
            break;
        //系统设置页
        case SYSTEMPAGE:
            {
                ui->UI_stackedWidget->setCurrentWidget(ui->UI_page);
                ui->stackedWidget->setCurrentWidget(ui->Wordking_page);
                ui->Set_stackedWidget->setCurrentWidget(ui->Mode_page);
            }
            break;
        case MACHINECLOSE:
            {

            }
            break;
        case MACHINESTANDBY:
            {

            }
            break;
        case MACHINEOPEN:
            {

            }
            break;
        //系统信息
        case SYSTEMINFORMATION:
            {
                ui->InfoPageNum_lb->setText( "1/2" );
                ui->UI_stackedWidget->setCurrentWidget(ui->UI_page);
                ui->stackedWidget->setCurrentWidget(ui->Wordking_page);
                ui->Set_stackedWidget->setCurrentWidget(ui->SystemInfor_page);
            }
            break;
        //登录
        case USER_LOGIN:
            {
                if( Account_Type >=  ui->combox_Account->count() )
                {
                    ui->combox_Account->setCurrentIndex( 0 );
                }
                else
                {
                    ui->combox_Account->setCurrentIndex( Account_Type );
                }

                ui->UI_stackedWidget->setCurrentWidget( ui->Login );
            }
            break;
        default:
            break;
    }
}
/*工作模式切换页面*/
void MEGAWin::WordingMode(int Index)
{
    CurrentCheckMode = Index;
    if(CurrentCheckMode != ADVANCED_SETTING )
    {
        if(!ui->Save_bt->isVisible())
        {
            ui->Save_bt->setVisible(true);
        }
        if(System_Current_Page<Lead_PAGE_NUM)
        {
            ui->SetPageNum_lb->setText( QString("%1/%2").arg(System_Current_Page+1).arg(SystemTotal_PAGE) );
        }
        else
        {
            ui->SetPageNum_lb->setText( QString("%1/%2").arg(System_Current_Page).arg(SystemTotal_PAGE) );
        }
        if(System_Current_Page == ParamSet_NUM)
        {
            ui->PageInfo_lb->setText(QString("%1\n%2").arg(Mode_Str.at(CurrentCheckMode)).arg(Mode_title_Str.at(System_Current_Page)));
            if(CurrentCheckMode == Mode_UPS)
            {
                ui->ParamSet_Tab->setVisible(false);
                ui->UPS_ParamSet_Tab->setVisible(true);
                ui->GridExpan_ParamSet_Tab->setVisible(false);

            }
            else if(CurrentCheckMode == Mode_SteadyStateExpansion)
            {
                ui->ParamSet_Tab->setVisible(false);
                ui->UPS_ParamSet_Tab->setVisible(false);
                ui->GridExpan_ParamSet_Tab->setVisible(true);
            }
            else
            {
                ui->ParamSet_Tab->setVisible(true);
                ui->UPS_ParamSet_Tab->setVisible(false);
                ui->GridExpan_ParamSet_Tab->setVisible(false);
            }
        }
        else
        {
            ui->PageInfo_lb->setText(Mode_title_Str.at(System_Current_Page));
        }
        ui->Mode_lb->setText( Mode_Str.at(CurrentCheckMode) );

        ui->UI_stackedWidget->setCurrentWidget(ui->UI_page);
        ui->stackedWidget->setCurrentWidget(ui->Wordking_page);
        ui->Set_stackedWidget->setCurrentWidget(ui->Setting_page);
        ui->setpage_stackedWidget->setCurrentIndex( System_Current_Page );
    }
    else
    {
        if(ui->Save_bt->isVisible())
        {
            ui->Save_bt->setVisible(false);
        }
        CurrentCheckMode = ADVANCED_SETTING;
        ui->Save_bt->setVisible(false);
        ui->SetPageNum_lb->setText( QString("%1/%2").arg(Advanced_Current_Page-SystemTotal_PAGE).arg(AdvancedTotal_PAGE) );
        ui->PageInfo_lb->setText(Mode_title_Str.at(Advanced_Current_Page));
        ui->Set_stackedWidget->setCurrentWidget( ui->Setting_page );
        ui->Mode_lb->setText( tr("Advanced Settings") );
        ui->setpage_stackedWidget->setCurrentIndex( Advanced_Current_Page );
    }


}
/*返回退出键*/
void MEGAWin::Return(int Index)
{
    QString EnableMode("QToolButton::hover{color: rgb(0, 0, 0);border:2px solid rgb(27, 120, 205);background-color: rgb(27, 120, 205);border-radius:15px;}\
                       QToolButton::!hover{color: rgb(255, 255, 255);border:2px solid rgb(27, 120, 205);background-color: rgb(27, 120, 205);border-radius:15px;}");
    QString DisableMode("QToolButton::hover{color: rgb(0, 0, 0);border:2px solid rgb(85, 170, 255);background-color: rgb(85, 170, 255);border-radius:15px;}\
                          QToolButton::!hover{color: rgb(255, 255, 255);border:2px solid rgb(85, 170, 255);background-color: rgb(85, 170, 255);border-radius:15px;}");
    switch (Index)
    {
        case 0:
            {


            }
            break;
        case 1:
            {
                SystemMode_Group->button(0)->setStyleSheet(DisableMode);
                SystemMode_Group->button(1)->setStyleSheet(DisableMode);
                SystemMode_Group->button(2)->setStyleSheet(DisableMode);
                SystemMode_Group->button(3)->setStyleSheet(DisableMode);
                SystemMode_Group->button(4)->setStyleSheet(DisableMode);
                SystemMode_Group->button(CurrentCheckMode)->setStyleSheet(EnableMode);
            }
            break;
        case 2:
            {

            }
            break;
        default:
            break;
    }
    ui->UI_stackedWidget->setCurrentWidget(ui->UI_page);
    ui->stackedWidget->setCurrentWidget(ui->Wordking_page);
    ui->Set_stackedWidget->setCurrentWidget(ui->Mode_page);
}
/*切换登录信息*/
void MEGAWin::Account_Change(uint8_t Account_Type)
{
    if( Account_Type == 0 )         //用户
    {
        ui->Login_bt->setText( tr("USER") );
    }
    else if( Account_Type == 1 )    //维修
    {
        ui->Login_bt->setText( tr("MAINTAIN") );
    }
    else if( Account_Type == 2 )    //超级权限
    {
        ui->Login_bt->setText( tr("Admin") );
    }
    else
    {
        ui->Login_bt->setText( tr("Not Logged in") );
    }
}
/*主页点击*/
void MEGAWin::Home_Click(int Index)
{
    switch (Index) {
    //负载
    case 1:
        {
            ui->stackedWidget->setCurrentWidget(ui->Status_page);
            ui->Run_tabWidget->setCurrentWidget(ui->RT_Data_page);
            ui->Bypass_Tab_2->setCurrentWidget(ui->Bypass_Load_page_2);
            ui->SLoad_btn_2->click();
        }
        break;
    //逆变器
    case 2:
        {
            ui->stackedWidget->setCurrentWidget(ui->Status_page);
            ui->Run_tabWidget->setCurrentWidget(ui->RT_Data_page);
            ui->Bypass_Tab_2->setCurrentWidget(ui->Bypass_Converter_page_2);
            ui->SConverter_btn_2->click();
        }
        break;
    //电池
    case 3:
        {
            ui->stackedWidget->setCurrentWidget(ui->Status_page);
            ui->Run_tabWidget->setCurrentWidget(ui->BatteryData_page);
            ui->BAT_stackedWidget->setCurrentWidget(ui->BAT_Lithium_page);
        }
        break;
    //电网
    case 4:
        {
            ui->stackedWidget->setCurrentWidget(ui->Status_page);
            ui->Run_tabWidget->setCurrentWidget(ui->RT_Data_page);
            ui->Bypass_Tab_2->setCurrentWidget(ui->Bypass_Grid_page_2);
            ui->SGrid_btn_2->click();
        }
        break;
    //告警
    case 5:
        {
            ui->stackedWidget->setCurrentWidget(ui->Status_page);
            ui->Run_tabWidget->setCurrentWidget(ui->RTAlarm_page);
            QMessageBox::question(this,tr("Alarm icon"), \
                                  tr("Alarm icon: It is not displayed when there is no alarm. "
                                     "When there is a minor alarm, a yellow icon is displayed. "
                                     "When there is a fault alarm, a red icon is displayed."), tr("OK"));
        }
        break;
    default:
        break;
    }
}
/*PCS数据-表格初始化*/
void MEGAWin::PCS_DataTableInit()
{
    QStringList Title_TabList;
    Title_TabList << tr("Name") << tr("Value") << tr("Name") << tr("Value");
    //变流器
    QStringList Converter_Tablist1;
    Converter_Tablist1  << tr("Inv. voltage(AB)") << tr("Inv. voltage(BC)") << tr("Inv. voltage(CA)")
                        << tr("Inv. current(A)") << tr("Inv. current(B)")<< tr("Inv. current(C)")
                        << tr("Inv. active power") << tr("Inv. reactive power") << tr("Inv. apparent power") << tr("Inv. power factor");
    QStringList Converter_Tablist2;
    Converter_Tablist2  << tr("Battery voltage") << tr("Battery current") << tr("Battery power")
                        << tr("Bus voltage") << tr("IGBT temperature")
                        << tr("Environment temperature");

    ui->Converter_Tab_2->setColumnCount(4);
    ui->Converter_Tab_2->setRowCount(Converter_Tablist1.size());
    ui->Converter_Tab_2->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->Converter_Tab_2->verticalHeader()->setVisible(false);//设置垂直头不可见
    ui->Converter_Tab_2->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->Converter_Tab_2->setShowGrid(true);//设置显示格子
    ui->Converter_Tab_2->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    ui->Converter_Tab_2->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
    ui->Converter_Tab_2->setStyleSheet("selection-background-color:lightblue;");


    ui->Converter_Tab_2->setHorizontalHeaderLabels(Title_TabList);
    ui->Converter_Tab_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//表格自适应窗口大小
    ui->Converter_Tab_2->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->Converter_Tab_2->verticalHeader()->setMinimumSectionSize(50);
    ui->Converter_Tab_2->verticalHeader()->setMaximumSectionSize(60);
    for(int i = 0; i < Converter_Tablist1.size(); i++)
    {
        ui->Converter_Tab_2->setItem(i, 0, new QTableWidgetItem(Converter_Tablist1.at(i)));
        ui->Converter_Tab_2->item(i, 0)->setTextAlignment(Qt::AlignCenter);
    }
    for(int i = 0; i < Converter_Tablist2.size(); i++)
    {
        ui->Converter_Tab_2->setItem(i, 2, new QTableWidgetItem(Converter_Tablist2.at(i)));
        ui->Converter_Tab_2->item(i, 2)->setTextAlignment(Qt::AlignCenter);
    }
    //电网
    QStringList Grid_Tablist;
    Grid_Tablist << tr("Grid voltage(AB)") << tr("Grid voltage(BC)") << tr("Grid voltage(CA)")
                    << tr("Grid current(A)") << tr("Grid current(B)")<< tr("Grid current(C)")
                    << tr("Grid active power") << tr("Grid reactive power")
                     << tr("Grid apparent power") << tr("Grid frequency") << tr("Grid power factor");

    ui->Grid_Tab_2->setColumnCount(2);
    ui->Grid_Tab_2->setRowCount(Grid_Tablist.size());
    ui->Grid_Tab_2->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->Grid_Tab_2->verticalHeader()->setVisible(false);//设置垂直头不可见
    ui->Grid_Tab_2->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->Grid_Tab_2->setShowGrid(true);//设置显示格子
    ui->Grid_Tab_2->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    ui->Grid_Tab_2->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
    ui->Grid_Tab_2->setStyleSheet("selection-background-color:lightblue;");

    ui->Grid_Tab_2->setHorizontalHeaderLabels(Title_TabList);
    ui->Grid_Tab_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//表格自适应窗口大小
    ui->Grid_Tab_2->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->Grid_Tab_2->verticalHeader()->setMinimumSectionSize(50);
    ui->Grid_Tab_2->verticalHeader()->setMaximumSectionSize(60);
    for(int i = 0; i < Grid_Tablist.size(); i++)
    {
        ui->Grid_Tab_2->setItem(i, 0, new QTableWidgetItem(Grid_Tablist.at(i)));
        ui->Grid_Tab_2->item(i, 0)->setTextAlignment(Qt::AlignCenter);
    }

    //负载
    QStringList Load_Tablist;
    Load_Tablist << tr("Load voltage(AB)") << tr("Load voltage(BC)") << tr("Load voltage(CA)")
                        << tr("Load current(A)") << tr("Load current(B)")<< tr("Load current(C)")
                        << tr("Load active power") << tr("Load reactive power")
                        << tr("Load apparent power") << tr("Load power factor");

    ui->Load_Tab_2->setColumnCount(2);
    ui->Load_Tab_2->setRowCount(Load_Tablist.size());
    ui->Load_Tab_2->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->Load_Tab_2->verticalHeader()->setVisible(false);//设置垂直头不可见
    ui->Load_Tab_2->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->Load_Tab_2->setShowGrid(true);//设置显示格子
    ui->Load_Tab_2->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    ui->Load_Tab_2->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
    ui->Load_Tab_2->setStyleSheet("selection-background-color:lightblue;");

    ui->Load_Tab_2->setHorizontalHeaderLabels(Title_TabList);
    ui->Load_Tab_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//表格自适应窗口大小
    ui->Load_Tab_2->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->Load_Tab_2->verticalHeader()->setMinimumSectionSize(50);
    ui->Load_Tab_2->verticalHeader()->setMaximumSectionSize(60);
    for(int i = 0; i < Load_Tablist.size(); i++)
    {
        ui->Load_Tab_2->setItem(i, 0, new QTableWidgetItem(Load_Tablist.at(i)));
        ui->Load_Tab_2->item(i, 0)->setTextAlignment(Qt::AlignCenter);
    }
}
/*PCS状态-表格初始化*/
void MEGAWin::PCS_StateTableInit()
{
    QStringList Title_TabList;
    Title_TabList << tr("Name") << tr("Value") << tr("Name") << tr("Value")<< tr("Name") << tr("Value");
    QStringList RTState_Bypass_List1;
    RTState_Bypass_List1<< tr("DC input breaker")<< tr("DC contactor")\
                         << tr("Output contactor") << tr("Output breaker") \
                         << tr("Grid contactor") << tr("Grid breaker") << tr("Maintenance Bypass breaker");
    QStringList RTState_Bypass_List2;
     RTState_Bypass_List2 << tr("converter available") << tr("DC Soft start")\
                << tr("converter status") << tr("Reactive power Regulation") << tr("LVRT");
     QStringList RTState_Bypass_List4;
      RTState_Bypass_List4 << tr("Start Diesel Generator Signal") << tr("DO2")\
                           << tr("DO3") << tr("Dry contact EPO")\
                           << tr("Dry contact Shutdown") << tr("Access control signal")\
                           << tr("Full power signal") << tr("Smoke alarm signal")<< tr("Fire fighting signal");

      ui->RTState_Bypass_Tab->setColumnCount(6);
      ui->RTState_Bypass_Tab->setRowCount(RTState_Bypass_List4.size());
      ui->RTState_Bypass_Tab->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
      ui->RTState_Bypass_Tab->verticalHeader()->setVisible(false);//设置垂直头不可见
      ui->RTState_Bypass_Tab->setFrameShape(QFrame::NoFrame);//设置无边框
      ui->RTState_Bypass_Tab->setShowGrid(true);//设置显示格子
      ui->RTState_Bypass_Tab->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
      ui->RTState_Bypass_Tab->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
      ui->RTState_Bypass_Tab->setStyleSheet("selection-background-color:lightblue;");

      ui->RTState_Bypass_Tab->setHorizontalHeaderLabels(Title_TabList);
      ui->RTState_Bypass_Tab->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//表格自适应窗口大小
      ui->RTState_Bypass_Tab->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
      ui->RTState_Bypass_Tab->verticalHeader()->setMinimumSectionSize(50);
      ui->RTState_Bypass_Tab->verticalHeader()->setMaximumSectionSize(60);
      for(int i = 0; i < RTState_Bypass_List1.size(); i++)
      {
          ui->RTState_Bypass_Tab->setItem(i, 0, new QTableWidgetItem(RTState_Bypass_List1.at(i)));
          ui->RTState_Bypass_Tab->item(i, 0)->setTextAlignment(Qt::AlignCenter);
      }
      for(int i = 0; i < RTState_Bypass_List2.size(); i++)
      {
          ui->RTState_Bypass_Tab->setItem(i, 2, new QTableWidgetItem(RTState_Bypass_List2.at(i)));
          ui->RTState_Bypass_Tab->item(i, 2)->setTextAlignment(Qt::AlignCenter);
      }
      for(int i = 0; i < RTState_Bypass_List4.size(); i++)
      {
          ui->RTState_Bypass_Tab->setItem(i, 4, new QTableWidgetItem(RTState_Bypass_List4.at(i)));
          ui->RTState_Bypass_Tab->item(i, 4)->setTextAlignment(Qt::AlignCenter);
      }
}
/*历史记录-表格初始化*/
void MEGAWin::History()
{
    QStringList table_h_headers;
    table_h_headers.clear();
    table_h_headers << tr("Level") << tr("Start Time") << tr("End Time") << tr("Description");
    ui->Historicalfailure_tableWidget->setColumnCount(table_h_headers.size());
    ui->Historicalfailure_tableWidget->setRowCount(15);
    ui->Historicalfailure_tableWidget->setHorizontalHeaderLabels(table_h_headers);
    ui->Historicalfailure_tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->Historicalfailure_tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->Historicalfailure_tableWidget->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->Historicalfailure_tableWidget->setShowGrid(true);//设置显示格子
    ui->Historicalfailure_tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    for (int i = 1; i < ui->Historicalfailure_tableWidget->columnCount(); ++i) {
        ui->Historicalfailure_tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }
    ui->Historicalfailure_tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->Historicalfailure_tableWidget->verticalHeader()->setMinimumSectionSize(50);//设置行高最小值

    /*ui->Historicalfailure_tableWidget->setColumnWidth(1,180);
    ui->Historicalfailure_tableWidget->setColumnWidth(2,180);
    ui->Historicalfailure_tableWidget->horizontalHeader()->setStretchLastSection(true);
    for (int i = 0; i < 15; ++i)
    {
        ui->Historicalfailure_tableWidget->setRowHeight(i, 40);
    }*/

//    Grade_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
//    Grade2_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
//    Grade3_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
//    Grade4_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
//    Grade5_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
//    Grade6_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
//    Grade7_explain->setStyleSheet("background-color:rgb(200, 0, 0);");
//    Grade8_explain->setStyleSheet("background-color:rgb(200, 0, 0);");



//    HistoryRecord(ui->Historicalfailure_tableWidget);   //历史记录页说明
}
/*操作日志-表格初始化*/
void MEGAWin::OperationLog()
{
    QStringList Ope_headers;
    Ope_headers.clear();
    Ope_headers << tr("Modification Time") << tr("Record Event");
    ui->Operation_tableWidget->setColumnCount(Ope_headers.size());
    ui->Operation_tableWidget->setRowCount(9);
    ui->Operation_tableWidget->setHorizontalHeaderLabels(Ope_headers);
    ui->Operation_tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
     ui->Operation_tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->Operation_tableWidget->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->Operation_tableWidget->setShowGrid(true);//设置显示格子
    ui->Operation_tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    ui->Operation_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->Operation_tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->Operation_tableWidget->verticalHeader()->setMinimumSectionSize(50);//设置行高最小值
    /*ui->Operation_tableWidget->setColumnWidth(0,260);
    ui->Operation_tableWidget->horizontalHeader()->setStretchLastSection(true);
    for (int i = 0; i < 9; ++i)
    {
        ui->Operation_tableWidget->setRowHeight(i, 40);
    }*/

//    OperationLog_tab(ui->Operation_tableWidget);    //操作日志页说明
}
/*工作模式-表格初始化*/
void MEGAWin::WorkingModeInit()
{
    Mode_title_Str.clear();
    Mode_title_Str<<tr("Parameters Settings")<<tr("Lithum Settings")<<tr("Lead Settings")<<tr("Operation Time")<<tr("Function Senttings 1")<<tr("Function Senttings 2")\
                 <<tr("System Parameter Settings")<<tr("External Device Settings")<<tr("BMS Protection Settings")<<tr("Debug Settings")<<tr("Port data")<<tr("Monitor Debug Settings");

    //鼠标悬浮提示语
    ui->Information_btn->setToolTip(QString(tr("Working mode introduction")));
    ui->Save_bt->setToolTip(QString(tr("Apply this mode and exit the parameter settings page")));
    ui->Exit_bt->setToolTip(QString(tr("Eexit the parameter settings page")));
    ui->SetNext_bt->setToolTip(QString(tr("Next page")));
    ui->SetPrevious_bt->setToolTip(QString(tr("Last page")));
    ui->UI_captye->setToolTip(QString(tr("Machine typs")));
    ui->TimeSeting_btn->setToolTip(QString(tr("Current system time")));
    ui->Alarm_Button->setToolTip(QString(tr("Alarm severity warning")));
    ui->ChangeLanguage_btn->setToolTip(QString(tr("Chinese and English switching")));
    ui->UI_MenuBtn->setToolTip(QString(tr("Open menu")));
    ui->Login_bt->setToolTip(QString(tr("User login")));
    ui->Converter_State_btn->setToolTip(QString(tr("Converter status")));
    ui->DCDC_Module_State_btn->setToolTip(QString(tr("DCDC module state")));
    ui->IntrBack_bt->setToolTip(QString(tr("Return to previous page")));
    ui->Details_bt->setToolTip(QString(tr("View the detailed running logic and related parameters of the working mode")));
    ui->Bypass_Load_Btn->setToolTip(QString(tr("Load")));
    ui->Bypass_Running_btn->setToolTip(QString(tr("Converter")));
    ui->Bypass_Batt_btn->setToolTip(QString(tr("Battery")));
    ui->Bypass_Grid_btn->setToolTip(QString(tr("Grid")));
    ui->PortNum_bt->setToolTip(QString(tr("Set the port to listen on")));
    ui->Bengin_bt->setToolTip(QString(tr("Start/Stop")));

    //基础参数设置
    ui->ParamSet_Tab->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->ParamSet_Tab->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->ParamSet_Tab->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->ParamSet_Tab->setShowGrid(true);//设置显示格子
    ui->ParamSet_Tab->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    ui->ParamSet_Tab->verticalHeader()->setVisible(false);//设置垂直头不可见
    ui->ParamSet_Tab->horizontalHeader()->setVisible(false);//设置水平头不可见
    ui->ParamSet_Tab->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//表格自适应窗口大小
    ui->ParamSet_Tab->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->ParamSet_Tab->verticalHeader()->setMinimumSectionSize(50);
    ui->ParamSet_Tab->verticalHeader()->setMaximumSectionSize(60);

    ui->GridExpan_ParamSet_Tab->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->GridExpan_ParamSet_Tab->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->GridExpan_ParamSet_Tab->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->GridExpan_ParamSet_Tab->setShowGrid(true);//设置显示格子
    ui->GridExpan_ParamSet_Tab->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    ui->GridExpan_ParamSet_Tab->verticalHeader()->setVisible(false);//设置垂直头不可见
    ui->GridExpan_ParamSet_Tab->horizontalHeader()->setVisible(false);//设置水平头不可见
    ui->GridExpan_ParamSet_Tab->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//表格自适应窗口大小
    ui->GridExpan_ParamSet_Tab->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->GridExpan_ParamSet_Tab->verticalHeader()->setMinimumSectionSize(50);
    ui->GridExpan_ParamSet_Tab->verticalHeader()->setMaximumSectionSize(60);

    ui->UPS_ParamSet_Tab->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->UPS_ParamSet_Tab->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->UPS_ParamSet_Tab->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->UPS_ParamSet_Tab->setShowGrid(true);//设置显示格子
    ui->UPS_ParamSet_Tab->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    ui->UPS_ParamSet_Tab->verticalHeader()->setVisible(false);//设置垂直头不可见
    ui->UPS_ParamSet_Tab->horizontalHeader()->setVisible(false);//设置水平头不可见
    ui->UPS_ParamSet_Tab->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//表格自适应窗口大小
    ui->UPS_ParamSet_Tab->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->UPS_ParamSet_Tab->verticalHeader()->setMinimumSectionSize(50);
    ui->UPS_ParamSet_Tab->verticalHeader()->setMaximumSectionSize(60);

    ui->GridExpan_ParamSet_Tab->setVisible(false);;//隐藏两个表格
    ui->UPS_ParamSet_Tab->setVisible(false);;

    //电池参数设置
    ui->LithumSet_Tab->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->LithumSet_Tab->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->LithumSet_Tab->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->LithumSet_Tab->setShowGrid(true);//设置显示格子
    ui->LithumSet_Tab->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    ui->LithumSet_Tab->verticalHeader()->setVisible(false);//设置垂直头不可见
    ui->LithumSet_Tab->horizontalHeader()->setVisible(false);//设置水平头不可见
    ui->LithumSet_Tab->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//表格自适应窗口大小
    ui->LithumSet_Tab->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->LithumSet_Tab->verticalHeader()->setMinimumSectionSize(50);
    ui->LithumSet_Tab->verticalHeader()->setMaximumSectionSize(60);

    ui->LeadSet_Tab->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->LeadSet_Tab->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->LeadSet_Tab->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->LeadSet_Tab->setShowGrid(true);//设置显示格子
    ui->LeadSet_Tab->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    ui->LeadSet_Tab->verticalHeader()->setVisible(false);//设置垂直头不可见
    ui->LeadSet_Tab->horizontalHeader()->setVisible(false);//设置水平头不可见
    ui->LeadSet_Tab->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//表格自适应窗口大小
    ui->LeadSet_Tab->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->LeadSet_Tab->verticalHeader()->setMinimumSectionSize(50);
    ui->LeadSet_Tab->verticalHeader()->setMaximumSectionSize(60);
}
/*时间段-表格初始化*/
void MEGAWin::TimePeriodInit()
{
    QStringList time_str;
    time_str<< tr("Check")<< tr("StartTime") << tr("EndTime") << tr("Status") << tr("Power(kW)");
    ui->MixedTime_Tab->setColumnCount(time_str.size());
    ui->MixedTime_Tab->setRowCount(20);
    ui->MixedTime_Tab->setHorizontalHeaderLabels(time_str);
    ui->MixedTime_Tab->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->MixedTime_Tab->verticalHeader()->setVisible(false);//设置垂直头不可见
    ui->MixedTime_Tab->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->MixedTime_Tab->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
    ui->MixedTime_Tab->setShowGrid(true);//设置显示格子
    ui->MixedTime_Tab->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    ui->MixedTime_Tab->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->MixedTime_Tab->setColumnWidth(0, 120);
    ui->MixedTime_Tab->setColumnWidth(3, 140);
    for(int sum = 1; sum < ui->MixedTime_Tab->columnCount(); ++sum)
    {
        if(sum != 3)
        {
            ui->MixedTime_Tab->horizontalHeader()->setSectionResizeMode(sum, QHeaderView::Stretch);
        }
    }
    ui->MixedTime_Tab->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->MixedTime_Tab->verticalHeader()->setMinimumSectionSize(50);//设置行高最小值
}
/*高级设置-表格初始化*/
void MEGAWin::AdvancedSetInit()
{
    ui->FunctionSet_Tab1->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->FunctionSet_Tab1->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->FunctionSet_Tab1->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->FunctionSet_Tab1->setShowGrid(true);//设置显示格子
    ui->FunctionSet_Tab1->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    ui->FunctionSet_Tab1->verticalHeader()->setVisible(false);//设置垂直头不可见
    ui->FunctionSet_Tab1->horizontalHeader()->setVisible(false);//设置水平头不可见
    ui->FunctionSet_Tab1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//表格自适应窗口大小
    ui->FunctionSet_Tab1->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->FunctionSet_Tab1->verticalHeader()->setMinimumSectionSize(50);
    ui->FunctionSet_Tab1->verticalHeader()->setMaximumSectionSize(60);

    ui->FunctionSet_Tab2->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->FunctionSet_Tab2->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->FunctionSet_Tab2->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->FunctionSet_Tab2->setShowGrid(true);//设置显示格子
    ui->FunctionSet_Tab2->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    ui->FunctionSet_Tab2->verticalHeader()->setVisible(false);//设置垂直头不可见
    ui->FunctionSet_Tab2->horizontalHeader()->setVisible(false);//设置水平头不可见
    ui->FunctionSet_Tab2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//表格自适应窗口大小
    ui->FunctionSet_Tab2->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->FunctionSet_Tab2->verticalHeader()->setMinimumSectionSize(50);
    ui->FunctionSet_Tab2->verticalHeader()->setMaximumSectionSize(60);

    ui->SystemSet_Tab->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->SystemSet_Tab->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->SystemSet_Tab->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->SystemSet_Tab->setShowGrid(true);//设置显示格子
    ui->SystemSet_Tab->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    ui->SystemSet_Tab->verticalHeader()->setVisible(false);//设置垂直头不可见
    ui->SystemSet_Tab->horizontalHeader()->setVisible(false);//设置水平头不可见
    ui->SystemSet_Tab->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//表格自适应窗口大小
    ui->SystemSet_Tab->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->SystemSet_Tab->verticalHeader()->setMinimumSectionSize(50);
    ui->SystemSet_Tab->verticalHeader()->setMaximumSectionSize(60);

    ui->ExternalDevice_Tab->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->ExternalDevice_Tab->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->ExternalDevice_Tab->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->ExternalDevice_Tab->setShowGrid(true);//设置显示格子
    ui->ExternalDevice_Tab->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    ui->ExternalDevice_Tab->verticalHeader()->setVisible(false);//设置垂直头不可见
    ui->ExternalDevice_Tab->horizontalHeader()->setVisible(false);//设置水平头不可见
    ui->ExternalDevice_Tab->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//表格自适应窗口大小
    ui->ExternalDevice_Tab->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->ExternalDevice_Tab->verticalHeader()->setMinimumSectionSize(50);
    ui->ExternalDevice_Tab->verticalHeader()->setMaximumSectionSize(60);

    ui->BMSProtect_Tab->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->BMSProtect_Tab->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->BMSProtect_Tab->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->BMSProtect_Tab->setShowGrid(true);//设置显示格子
    ui->BMSProtect_Tab->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    ui->BMSProtect_Tab->verticalHeader()->setVisible(false);//设置垂直头不可见
    ui->BMSProtect_Tab->horizontalHeader()->setVisible(false);//设置水平头不可见
    ui->BMSProtect_Tab->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//表格自适应窗口大小
    ui->BMSProtect_Tab->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->BMSProtect_Tab->verticalHeader()->setMinimumSectionSize(50);
    ui->BMSProtect_Tab->verticalHeader()->setMaximumSectionSize(60);

    ui->Debug_Tab->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->Debug_Tab->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->Debug_Tab->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->Debug_Tab->setShowGrid(true);//设置显示格子
    ui->Debug_Tab->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    ui->Debug_Tab->verticalHeader()->setVisible(false);//设置垂直头不可见
    ui->Debug_Tab->horizontalHeader()->setVisible(false);//设置水平头不可见
    ui->Debug_Tab->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//表格自适应窗口大小
    ui->Debug_Tab->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->Debug_Tab->verticalHeader()->setMinimumSectionSize(50);
    ui->Debug_Tab->verticalHeader()->setMaximumSectionSize(60);
}
/*设置控件到表格*/
void MEGAWin::SetControlToTable()
{
    SetConverterDataToTable(ui->Converter_Tab_2);//变流器-控件到表格
    SetGridDataToTable(ui->Grid_Tab_2);//电网-控件到表格
    SetLoadDataToTable(ui->Load_Tab_2);//负载-控件到表格
    SetPCS_StateToTable(ui->RTState_Bypass_Tab);//PCS状态-控件到表格
    SetHistororyRecordToTable(ui->Historicalfailure_tableWidget);//历史记录-控件到表格
    SetOpeationLogToTable(ui->Operation_tableWidget);//操作日志-控件到表格

    SetBasicParameterToTable(ui->ParamSet_Tab);//设置基础参数-控件到表格
    SetBasicParameterUPSToTable(ui->UPS_ParamSet_Tab);//设置基础参数UPS-控件到表格
    SetBasicParameterExpansionToTable(ui->GridExpan_ParamSet_Tab);//设置基础参数稳态扩容-控件到表格

    SetLithiumToTable(ui->LithumSet_Tab);//设置锂电池页-控件到表格
    SetLead_acidToTable(ui->LeadSet_Tab);//设置铅酸电池页-控件到表格
    SetMixedTime_TabToTable(ui->MixedTime_Tab);//设置时间段运行页-控件到表格
    SetAdvancedSetup1ToTable(ui->FunctionSet_Tab1);//设置高级设置页1-控件到表格
    SetAdvancedSetup2ToTable(ui->FunctionSet_Tab2);//设置高级设置页2-控件到表格
    SetAdvancedSetup3ToTable(ui->SystemSet_Tab);//设置高级设置页3-控件到表格
    Device_TabToTable(ui->ExternalDevice_Tab);//设置高级设置外设页-控件到表格
    BMSProtectToTable(ui->BMSProtect_Tab); //设置BMS保护页-控件到表格
    PCS_Debugg(ui->Debug_Tab); //设置高级设置调试页-控件到表格
}
/*变流器-控件到表格*/
void MEGAWin::SetConverterDataToTable(QTableWidget *myTable)
{
    int line=0;int column = 1;//当前解释的button行和列

    ButtonToTable->add_SpecificationData(PCS_vol_AB_explain, myTable, line++, column, \
                                                "0V", tr("Inv. voltage(AB)"), \
                                                tr("Inv. side AB line voltage."));

    ButtonToTable->add_SpecificationData(PCS_vol_BC_explain, myTable, line++, column, \
                                                "0V", tr("Inv. voltage(BC)"), \
                                                tr("Inv. side BC line voltage."));

    ButtonToTable->add_SpecificationData(PCS_vol_CA_explain, myTable, line++, column, \
                                                "0V", tr("Inv. voltage(CA)"), \
                                                tr("Inv. side CA line voltage."));

    ButtonToTable->add_SpecificationData(PCS_cur_A_explain, myTable, line++, column, \
                                                "0A", tr("Inv. current(A)"), \
                                               tr("Inv. side A phase current."));

    ButtonToTable->add_SpecificationData(PCS_cur_B_explain, myTable, line++, column, \
                                                "0A", tr("Inv. current(B)"), \
                                                tr("Inv. side B phase current."));

    ButtonToTable->add_SpecificationData(PCS_cur_C_explain, myTable, line++, column, \
                                                "0A", tr("Inv. current(C)"), \
                                                tr("Inv. side C phase current."));

    ButtonToTable->add_SpecificationData(PCS_active_power_explain, myTable, line++, column, \
                                                "0kW", tr("Inv. active power"), \
                                                tr("Active power P on the inv. side of the converter."));

    ButtonToTable->add_SpecificationData(PCS_reactive_power_explain, myTable, line++, column, \
                                                "0Kvar", tr("Inv. reactive power"), \
                                                tr("Reactive power Q on the inv. side of the converter."));

    ButtonToTable->add_SpecificationData(PCS_apparent_power_explain, myTable, line++, column, \
                                                "0kVA", tr("Inv. apparent power"), \
                                                tr("Apparent power S on the inv. side of the converter."));

    ButtonToTable->add_SpecificationData(PCS_power_factor_explain, myTable, line++, column, \
                                                "0", tr("Inv. power factor"), \
                                                tr("Power factor PF on the inv. side of the converter."));
    line=0;
    column=3;
    ButtonToTable->add_SpecificationData(Batter_vol_explain, myTable, line++, column, \
                                                "0V", tr("Battery voltage"), \
                                                tr("Converter battery side voltage."));

    ButtonToTable->add_SpecificationData(Batter_cur_explain, myTable, line++, column, \
                                                "0A", tr("Battery current"), \
                                                tr("Converter battery side current."));

    ButtonToTable->add_SpecificationData(Batter_power_explain, myTable, line++, column, \
                                                "0kW", tr("Battery power"), \
                                                tr("Converter battery side power."));

    ButtonToTable->add_SpecificationData(Bus_vol_explain, myTable, line++, column, \
                                                "0V", tr("Bus voltage"), \
                                                tr("Converter bus voltage."));

    ButtonToTable->add_SpecificationData(PCS_IGBT_T_explain, myTable, line++, column, \
                                                "0℃", tr("IGBT temperature"), \
                                                tr("The IGBT temperature of the converter: The IGBT temperature must not exceed 102°C. "
                                                   "Otherwise, the converter will operate at a reduced capacity. It will resume full power operation when the temperature drops to 73°C."));

    ButtonToTable->add_SpecificationData(PCS_Env_T_explain, myTable, line++, column, \
                                                "0℃", tr("Environment temperature"), \
                                                tr("The ambient temperature."));
}
/*电网-控件到表格*/
void MEGAWin::SetGridDataToTable(QTableWidget *myTable)
{
    int line=0;int column=1;
    ButtonToTable->add_SpecificationData(Grid_vol_AB_explain, myTable, line++, column, \
                                                "0V", tr("Grid Voltage(AB)"), \
                                                tr("Grid side AB line voltage."));

    ButtonToTable->add_SpecificationData(Grid_vol_BC_explain, myTable, line++, column, \
                                                "0V", tr("Grid Voltage(BC)"), \
                                                tr("Grid side BC line voltage."));

    ButtonToTable->add_SpecificationData(Grid_vol_CA_explain, myTable,line++, column, \
                                                "0V", tr("Grid Voltage(CA)"), \
                                                tr("Grid side CA line voltage."));

    ButtonToTable->add_SpecificationData(Grid_cur_A_explain, myTable, line++, column, \
                                                "0A", tr("Grid Current(A)"), \
                                                tr("Grid side A phase current."));

    ButtonToTable->add_SpecificationData(Grid_cur_B_explain, myTable, line++, column, \
                                                "0A", tr("Grid Current(B)"), \
                                                tr("Grid side B phase current."));

    ButtonToTable->add_SpecificationData(Grid_cur_C_explain, myTable, line++, column, \
                                                "0A", tr("Grid Current(C)"), \
                                                tr("Grid side C phase current."));

    ButtonToTable->add_SpecificationData(Grid_active_power_explain, myTable, line++, column, \
                                                "0kW", tr("Grid active power"), \
                                                tr("Active power P on the grid side of the converter."));

    ButtonToTable->add_SpecificationData(Grid_reactive_power_explain, myTable, line++, column, \
                                                "0Kvar", tr("Grid reactive power"), \
                                                tr("Reactive power Q on the grid side of the converter."));

    ButtonToTable->add_SpecificationData(Grid_apparent_power_explain, myTable, line++, column, \
                                                "0kVA", tr("Grid apparent power"), \
                                                tr("Apparent power S on the grid side of the converter."));

    ButtonToTable->add_SpecificationData(Grid_Frequency_explain, myTable, line++, column, \
                                                "0Hz", tr("Grid frequency"), \
                                                tr("Frequency on the grid side of the converter."));

    ButtonToTable->add_SpecificationData(Grid_power_factor_explain, myTable, line++, column, \
                                                "0", tr("Grid power factor"), \
                                                tr("Power factor PF on the grid side of the converter."));

}
/*负载-控件到表格*/
void MEGAWin::SetLoadDataToTable(QTableWidget *myTable)
{
    int line=0;int column=1;
    ButtonToTable->add_SpecificationData(Load_vol_AB_explain, myTable, line++, column, \
                                                "0V", tr("Load Voltage(AB)"), \
                                                tr("Load side AB line voltage."));

    ButtonToTable->add_SpecificationData(Load_vol_BC_explain, myTable, line++, column, \
                                                "0V", tr("Load Voltage(BC)"), \
                                                tr("Load side BC line voltage."));

    ButtonToTable->add_SpecificationData(Load_vol_CA_explain, myTable, line++, column, \
                                                "0V", tr("Load Voltage(CA)"), \
                                                tr("Load side CA line voltage."));

    ButtonToTable->add_SpecificationData(Load_cur_A_explain, myTable, line++, column, \
                                                "0A", tr("Load Current(A)"), \
                                                tr("Load side A phase current."));

    ButtonToTable->add_SpecificationData(Load_cur_B_explain, myTable, line++, column, \
                                                "0A", tr("Load Current(B)"), \
                                                tr("Load side B phase current."));

    ButtonToTable->add_SpecificationData(Load_cur_C_explain, myTable, line++, column, \
                                                "0A", tr("Load Current(C)"), \
                                                tr("Load side C phase current."));

    ButtonToTable->add_SpecificationData(Load_active_power_explain, myTable, line++, column, \
                                                "0kW", tr("Load active power"), \
                                                tr("Active power P on the load side of the converter."));

    ButtonToTable->add_SpecificationData(Load_reactive_power_explain, myTable, line++, column, \
                                                "0Kvar", tr("Load reactive power"), \
                                                tr("Reactive power Q on the load side of the converter."));

    ButtonToTable->add_SpecificationData(Load_apparent_power_explain, myTable, line++, column, \
                                                "0kVA", tr("Load apparent power"), \
                                                tr("Apparent power S on the load side of the converter."));

    ButtonToTable->add_SpecificationData(Load_power_factor_explain, myTable, line++, column, \
                                                "0", tr("Load power factor"), \
                                               tr("Power factor PF on the load side of the converter."));
}
/*PCS状态-控件到表格*/
void MEGAWin::SetPCS_StateToTable(QTableWidget *myTable)
{
    int line = 0;int column = 1;//当前解释的button行和列
    ButtonToTable->add_SpecificationData(DC_input_Breaker_explain, myTable, line++, column, \
                                                tr("On"), tr("DC input breaker"), \
                                                tr("There are two states for a DC circuit breaker: On, Off."));

    ButtonToTable->add_SpecificationData(DC_Cont_explain, myTable, line++, column, \
                                         tr("On"), tr("DC contactor"), \
                                         tr("The DC contactor has two states: On, Off. After the soft start of the DC side is completed, the DC contactor closes. When the DC side of the battery is disconnected and the voltage of the DC bus drops to a certain level, the DC contactor opens."));

    ButtonToTable->add_SpecificationData(Output_Cont_explain, myTable, line++, column, \
                                         tr("On"), tr("Output contactor"), \
                                         tr("The output contactor has two states: On, Off. The output contactor closes after the soft start on the inv. side is completed. The output contactor opens when the converter is shut down."));

    ButtonToTable->add_SpecificationData(Output_Breaker_explain, myTable, line++, column, \
                                         tr("On"), tr("Output Breaker"), \
                                         tr("The output circuit breaker has two states: On, Off. It can only be manually opened and closed."));

    ButtonToTable->add_SpecificationData(Grid_Cont_explain, myTable, line++, column, \
                                         tr("On"), tr("Grid contactor"), \
                                         tr("The grid contactor has two states: On, Off. When the inverter is in grid-connected mode and the grid voltage is normal, the grid contactor is closed. When the inverter is in island mode, the grid contactor is open. In the islanded state, the grid contactor remains open."));

    ButtonToTable->add_SpecificationData(Grid_Breaker_explain, myTable, line++, column, \
                                         tr("On"), tr("Grid Breaker"), \
                                         tr("The power grid circuit breaker has two states: On, Off; The power grid circuit breaker can only be manually disconnected."));

    ButtonToTable->add_SpecificationData(MB_Breaker_explain, myTable, line++, column, \
                                         tr("On"), tr("Maintenance Bypass Breaker"), \
                                         tr("There are two states for the maintenance bypass circuit breaker: On, Off. This circuit breaker is only used for machine maintenance. If maintenance is required, please contact the maintenance personnel."));
    line = 0;
    column += 2;
    ButtonToTable->add_SpecificationData(converter_available_explain, myTable, line++, column, \
                                         tr("Disabled"), tr("converter available"), \
                                         tr("The converter has two states: Enable,Disabled. The converter is enabled when the self-check is successful. Otherwise, the converter is disabled."));

    ButtonToTable->add_SpecificationData(DC_Soft_start_explain, myTable, line++, column, \
                                         tr("Not starting"), tr("DC Soft start"), \
                                         tr("There are three states for DC soft start: Not starting, Soft starting, and Complete. Soft start refers to the process in which the converter charges the busbar with the battery during startup, causing the busbar voltage to rise close to the battery voltage."));

    ButtonToTable->add_SpecificationData(converter_status_explain, myTable, line++, column, \
                                         tr("Shut down"), tr("converter status"), \
                                         tr("Converter states include: OFF, AC Soft Start, Grid-ON Charge, Grid-ON Discharge, Grid-OFF Discharge, Derating grid-on, Standby, Grid-OFF Charge, Constant Voltage Discharge and Constant Voltage Charge."));

    ButtonToTable->add_SpecificationData(Reactive_P_Regulation_explain, myTable, line++, column, \
                                         tr("Disable"), tr("Reactive Power Regulation"), \
                                         tr("There are three types of reactive power regulation: Disable,PF regulation, and  regulation."));

    ButtonToTable->add_SpecificationData(LVRT_explain, myTable, line++, column, \
                                         tr("Disable"), tr("LVRT"), \
                                         tr("LVRT states : Enable , Disable."));

    ButtonToTable->add_SpecificationData(ForcedCharg_explain, myTable, line++, column, \
                                                tr("Enable"), tr("Forced charge"), \
                                                tr("The Forced charge flag has two states: Enable,Disabled."));
    line = 0;
    column += 2;
    ButtonToTable->add_SpecificationData(Generator_signal_explain, myTable, line++, column, \
                                         tr("Enable"), tr("Start Diesel Generator Signal"), \
                                         tr("Signal to start the diesel generator, start the diesel generator when enabled, stop the diesel generator when disabled."));

    ButtonToTable->add_SpecificationData(Reserve_explain, myTable, line++, column, \
                                         tr("Disable"), tr("DO2"), \
                                         tr("Dry contact 2 is output."));

    ButtonToTable->add_SpecificationData(Reserve2_explain, myTable, line++, column, \
                                         tr("Disable"), tr("DO3"), \
                                         tr("Dry contact 3 is output."));

    ButtonToTable->add_SpecificationData(EPO_Cont_signal1_explain, myTable, line++, column, \
                                         tr("Disable"), tr("Dry contact EPO"), \
                                         tr("Dry contact EPO：Enable，Disable."));

    ButtonToTable->add_SpecificationData(EPO_Cont_signal2_explain, myTable, line++, column, \
                                         tr("Disable"), tr("Dry contact Shutdown"), \
                                         tr("Dry contact Shutdown：Enable，Disable."));

    ButtonToTable->add_SpecificationData(Access_signal_explain, myTable, line++, column, \
                                         tr("Disable"), tr("Access signal"), \
                                         tr("Access signal:Enable, Disable."));

    ButtonToTable->add_SpecificationData(Full_P_signal_explain, myTable, line++, column, \
                                         tr("Disable"), tr("Full power signal"), \
                                         tr("Full power signal:Enable, Disable."));

    ButtonToTable->add_SpecificationData(Smoke_alarm_signal_explain, myTable, line++, column, \
                                         tr("Disable"), tr("Smoke alarm signal"), \
                                         tr("Smoke alarm signal:Enable, Disable."));

    ButtonToTable->add_SpecificationData(Hight_temp_signal_explain, myTable, line++, column, \
                                         tr("Disable"), tr("Fire fighting signal"), \
                                         tr("Fire fighting signal:Enable, Disable."));
}
/*历史记录-控件到表格*/
void MEGAWin::SetHistororyRecordToTable(QTableWidget *myTable)
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
    QString str20 = tr("The grid breaker disconnected");//电网断路器断开

    QString str24 = tr("1");
    int line=0;int column=0;
    ButtonToTable->add_SpecificationData(Grade9_explain, myTable, line++, column, \
                                                    str24, str2, str3);

    ButtonToTable->add_SpecificationData(Grade10_explain, myTable, line++, column, \
                                                    str24, str2, str3);

    ButtonToTable->add_SpecificationData(Grade11_explain, myTable, line++, column, \
                                                    str24, str2, str3);

    ButtonToTable->add_SpecificationData(Grade12_explain, myTable, line++, column, \
                                                    str24, str2, str3);

    ButtonToTable->add_SpecificationData(Grade13_explain, myTable, line++, column, \
                                                    str24, str2, str3);

    ButtonToTable->add_SpecificationData(Grade14_explain, myTable, line++, column, \
                                                    str24, str2, str3);

    ButtonToTable->add_SpecificationData(Grade15_explain, myTable, line++, column, \
                                                    str24, str2, str3);

    ButtonToTable->add_SpecificationData(Grade_explain, myTable, line++, column, \
                                                    str1, str2, str3);

    ButtonToTable->add_SpecificationData(Grade2_explain, myTable, line++, column, \
                                                    str1, str2, str3);

    ButtonToTable->add_SpecificationData(Grade3_explain, myTable, line++, column, \
                                                    str1, str2,  str3);

    ButtonToTable->add_SpecificationData(Grade4_explain, myTable, line++, column, \
                                                    str1, str2, str3);

   ButtonToTable->add_SpecificationData(Grade5_explain, myTable, line++, column, \
                                                    str1, str2, str3);

    ButtonToTable->add_SpecificationData(Grade6_explain, myTable, line++, column, \
                                                    str1, str2, str3);

    ButtonToTable->add_SpecificationData(Grade7_explain, myTable, line++, column, \
                                                    str1, str2, \
                                                    str3);

    ButtonToTable->add_SpecificationData(Grade8_explain, myTable, line++, column, \
                                                    str1, str2, str3);

    line=0;
    column=1;
    if(LanguageType==0)
    {
        ButtonToTable->add_SpecificationData(StartTime9_explain, myTable, line++, column, \
                                                        "2023-7-29 14:59:56", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime10_explain, myTable, line++, column, \
                                                        "2023-7-29 14:59:55", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime11_explain, myTable, line++, column, \
                                                        "2023-7-29 14:59:51", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime12_explain, myTable, line++, column, \
                                                        "2023-7-29 14:59:51", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime13_explain, myTable, line++, column, \
                                                        "2023-7-29 14:59:50", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime14_explain, myTable, line++, column, \
                                                        "2023-7-29 14:57:50", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime15_explain, myTable, line++, column, \
                                                        "2023-7-29 14:57:50", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime_explain, myTable, line++, column, \
                                                        "2023-5-6 15:49:50", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime2_explain, myTable, line++, column, \
                                                        "2023-5-6 15:48:18", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime3_explain, myTable, line++, column, \
                                                        "2023-5-6 15:39:3", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime4_explain, myTable, line++, column, \
                                                        "2023-5-6 15:39:3", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime5_explain, myTable, line++, column, \
                                                        "2023-5-6 15:39:3", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime6_explain, myTable, line++, column, \
                                                        "2023-5-6 15:21:56", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime7_explain, myTable, line++, column, \
                                                        "2023-5-6 15:21:38", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime8_explain, myTable, line++, column, \
                                                        "2023-5-6 15:21:38", str4, str5);

        line=0;
        column=2;
        ButtonToTable->add_SpecificationData(EndTime9_explain, myTable, line++, column, \
                                                        "...", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime10_explain, myTable, line++, column, \
                                                        "...", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime11_explain, myTable, line++, column, \
                                                        "...", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime12_explain, myTable, line++, column, \
                                                        "...", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime13_explain, myTable, line++, column, \
                                                        "...", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime14_explain, myTable, line++, column, \
                                                        "...", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime15_explain, myTable, line++, column, \
                                                        "2023-7-29 16:42:24", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime_explain, myTable, line++, column, \
                                                        "-", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime2_explain, myTable, line++, column, \
                                                        "-", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime3_explain, myTable, line++, column, \
                                                        "...", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime4_explain, myTable, line++, column, \
                                                        "-", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime5_explain, myTable, line++, column, \
                                                        "...", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime6_explain, myTable, line++, column, \
                                                        "-", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime7_explain, myTable, line++, column, \
                                                        "-", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime8_explain, myTable, line++, column, \
                                                        "-", str6, str7);

    }
    else {
        ButtonToTable->add_SpecificationData(StartTime9_explain, myTable, line++, column, \
                                                        "29-7-2023 14:59:56", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime10_explain, myTable, line++, column, \
                                                        "29-7-2023 14:59:55", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime11_explain, myTable, line++, column, \
                                                        "29-7-2023 14:59:51", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime12_explain, myTable, line++, column, \
                                                        "29-7-2023 14:59:51", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime13_explain, myTable, line++, column, \
                                                        "29-7-2023 14:59:50", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime14_explain, myTable, line++, column, \
                                                        "29-7-2023 14:57:50", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime15_explain, myTable, line++, column, \
                                                        "29-7-2023 14:57:50", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime_explain, myTable, line++, column, \
                                                        "6-5-2023 15:49:50", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime2_explain, myTable, line++, column, \
                                                        "6-5-2023 15:48:18", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime3_explain, myTable, line++, column, \
                                                        "6-5-2023 15:39:3", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime4_explain, myTable, line++, column, \
                                                        "6-5-2023 15:39:3", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime5_explain, myTable, line++, column, \
                                                        "6-5-2023 15:39:3", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime6_explain, myTable, line++, column, \
                                                        "6-5-2023 15:21:56", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime7_explain, myTable, line++, column, \
                                                        "6-5-2023 15:21:38", str4, str5);

        ButtonToTable->add_SpecificationData(StartTime8_explain, myTable, line++, column, \
                                                        "6-5-2023 15:21:38", str4, str5);

        line=0;
        column=2;
        ButtonToTable->add_SpecificationData(EndTime9_explain, myTable, line++, column, \
                                                        "...", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime10_explain, myTable, line++, column, \
                                                        "...", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime11_explain, myTable, line++, column, \
                                                        "...", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime12_explain, myTable, line++, column, \
                                                        "...", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime13_explain, myTable, line++, column, \
                                                        "...", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime14_explain, myTable, line++, column, \
                                                        "...", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime15_explain, myTable, line++, column, \
                                                        "29-7-2023 16:42:24", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime_explain, myTable, line++, column, \
                                                        "-", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime2_explain, myTable, line++, column, \
                                                        "-", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime3_explain, myTable, line++, column, \
                                                        "...", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime4_explain, myTable, line++, column, \
                                                        "-", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime5_explain, myTable, line++, column, \
                                                        "...", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime6_explain, myTable, line++, column, \
                                                        "-", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime7_explain, myTable, line++, column, \
                                                        "-", str6, str7);

        ButtonToTable->add_SpecificationData(EndTime8_explain, myTable, line++, column, \
                                                        "-", str6, str7);

    }
    line=0;
    column=3;
    ButtonToTable->add_SpecificationData(Describe9_explain, myTable, line++, column, \
                                                    str13, str9, str10);

    ButtonToTable->add_SpecificationData(Describe10_explain, myTable, line++, column, \
                                                    str14, str9, str10);

    ButtonToTable->add_SpecificationData(Describe11_explain, myTable, line++, column, \
                                                    str15, str9, str10);

    ButtonToTable->add_SpecificationData(Describe12_explain, myTable, line++, column, \
                                                    str16, str9, str10);

    ButtonToTable->add_SpecificationData(Describe13_explain, myTable, line++, column, \
                                                    str17, str9, str10);

    ButtonToTable->add_SpecificationData(Describe14_explain, myTable, line++, column, \
                                                    str18, str9, str10);

    ButtonToTable->add_SpecificationData(Describe15_explain, myTable, line++, column, \
                                                    str20, str9, str10);

    ButtonToTable->add_SpecificationData(Describe_explain, myTable, line++, column, \
                                                    str8, str9, str10);

    ButtonToTable->add_SpecificationData(Describe2_explain, myTable, line++, column, \
                                                    str8, str9, str10);

    ButtonToTable->add_SpecificationData(Describe3_explain, myTable, line++, column, \
                                                    str11, str9, str10);

    ButtonToTable->add_SpecificationData(Describe4_explain, myTable, line++, column, \
                                                    str8, str9, str10);

    ButtonToTable->add_SpecificationData(Describe5_explain, myTable, line++, column, \
                                                    str12, str9, str10);

    ButtonToTable->add_SpecificationData(Describe6_explain, myTable, line++, column, \
                                                    str8, str9, str10);

    ButtonToTable->add_SpecificationData(Describe7_explain, myTable, line++, column, \
                                                    str11, str9, str10);

    ButtonToTable->add_SpecificationData(Describe8_explain, myTable, line++, column, \
                                                    str12, str9, str10);
}
/*操作日志-控件到表格*/
void MEGAWin::SetOpeationLogToTable(QTableWidget *myTable)
{
    QString str = tr("Modification Time");
    QString str1 = tr("Time when the system Settings are modified.");
    QString str2 = tr("Record Event");//事件记录
    QString str3 = tr("System settings operation records.");
    int line=0;int column=0;
    if(LanguageType == CHINESE)
    {
        ButtonToTable->add_SpecificationData(ModificationTime_explain, myTable, line++, column, \
                                                        "2023-05-12 11:32:45", str, \
                                                        str1);

        ButtonToTable->add_SpecificationData(ModificationTime2_explain, myTable, line++, column, \
                                                        "2023-05-12 11:32:33", str, \
                                                        str1);

        ButtonToTable->add_SpecificationData(ModificationTime3_explain, myTable, line++, column, \
                                                        "2023-05-11 19:29:24", str, \
                                                        str1);

        ButtonToTable->add_SpecificationData(ModificationTime4_explain, myTable, line++, column, \
                                                        "2023-05-11 19:29:21", str, \
                                                        str1);

        ButtonToTable->add_SpecificationData(ModificationTime5_explain, myTable, line++, column, \
                                                        "2023-05-11 19:29:10", str, \
                                                        str1);

        ButtonToTable->add_SpecificationData(ModificationTime6_explain, myTable, line++, column, \
                                                        "2023-05-11 19:29:07", str, \
                                                        str1);

        ButtonToTable->add_SpecificationData(ModificationTime9_explain, myTable, line++, column, \
                                                        "2023-05-11 11:20:58", str, \
                                                        str1);

        ButtonToTable->add_SpecificationData(ModificationTime11_explain, myTable, line++, column, \
                                                        "2023-05-11 11:02:18", str, \
                                                        str1);

        ButtonToTable->add_SpecificationData(ModificationTime12_explain, myTable, line++, column, \
                                                        "2023-05-11 11:02:14", str, \
                                                        str1);

    }
    else {
        ButtonToTable->add_SpecificationData(ModificationTime_explain, myTable, line++, column, \
                                                        "12-05-2023 11:32:45", str, \
                                                        str1);

        ButtonToTable->add_SpecificationData(ModificationTime2_explain, myTable, line++, column, \
                                                        "12-05-2023 11:32:33", str, \
                                                        str1);

        ButtonToTable->add_SpecificationData(ModificationTime3_explain, myTable, line++, column, \
                                                        "11-05-2023 19:29:24", str, \
                                                        str1);

        ButtonToTable->add_SpecificationData(ModificationTime4_explain, myTable, line++, column, \
                                                        "11-05-2023 19:29:21", str, \
                                                        str1);

        ButtonToTable->add_SpecificationData(ModificationTime5_explain, myTable, line++, column, \
                                                        "11-05-2023 19:29:10", str, \
                                                        str1);

        ButtonToTable->add_SpecificationData(ModificationTime6_explain, myTable, line++, column, \
                                                        "11-05-2023 19:29:07", str, \
                                                        str1);

        ButtonToTable->add_SpecificationData(ModificationTime9_explain, myTable, line++, column, \
                                                        "11-05-2023 11:20:58", str, \
                                                        str1);

        ButtonToTable->add_SpecificationData(ModificationTime11_explain, myTable, line++, column, \
                                                        "11-05-2023 11:02:18", str, \
                                                        str1);

        ButtonToTable->add_SpecificationData(ModificationTime12_explain, myTable, line++, column, \
                                                        "11-05-2023 11:02:14", str, \
                                                        str1);

    }
    line=0;
    column=1;
    ButtonToTable->add_SpecificationData(EventRecord_explain, myTable, line++, column, \
                                                    tr("Power control type：CP_P->CP_N&&P"), str2, \
                                                    str3);

    ButtonToTable->add_SpecificationData(EventRecord2_explain, myTable, line++, column, \
                                                    tr("Power control type：CP_N&&P->CP_P"), str2, \
                                                    str3);

    ButtonToTable->add_SpecificationData(EventRecord3_explain, myTable,line++, column, \
                                                    tr("Grid Fre Upper limit：0.2->3"), str2, \
                                                    str3);

    ButtonToTable->add_SpecificationData(EventRecord4_explain, myTable, line++, column, \
                                                    tr("Grid Fre Upper limit：3->0.2"), str2, \
                                                    str3);

    ButtonToTable->add_SpecificationData(EventRecord5_explain, myTable, line++, 1, \
                                                    tr("Voltage protection Lower limit：-10->-15"), str2, \
                                                    str3);

    ButtonToTable->add_SpecificationData(EventRecord6_explain, myTable, line++, column, \
                                                    tr("Voltage protection Lower limit：-15->-10"), str2, \
                                                    str3);

    ButtonToTable->add_SpecificationData(EventRecord9_explain, myTable, line++, column, \
                                                    tr("Operation mode：Manual->UPS"), str2, \
                                                    str3);

    ButtonToTable->add_SpecificationData(EventRecord11_explain, myTable, line++, column, \
                                                    tr("Inv ON/Off-Grid：Off->automatic"), str2, \
                                                    str3);

    ButtonToTable->add_SpecificationData(EventRecord12_explain, myTable, line++, column, \
                                                    tr("Inv ON/Off-Grid：automatic->Off"), str2, \
                                         str3);
}
/*基础参数-控件到表格*/
void MEGAWin::SetBasicParameterToTable(QTableWidget *myTable)
{
    int line = 0;
    int column = 1;
    //并网方式
    ButtonToTable->add_SpecificationData(Grid_connected_mode_explain,myTable, line++, column, \
                                         tr("automatic"), tr("Grid conected mode of the converter "), \
                                         tr("When \"Auto\" is selected, the converter will automatically switch between grid-on and grid-off. When the grid side is normal, "
                                            "the converter operates in grid-on mode (PQ).When the grid side is abnormal, the converter operates in grid-off mode (VF).\nWhen \"Grid-on\" is selected, "
                                            "the converter operates in grid-on mode (PQ).When the grid side is abnormal, the converter will shut down.\nWhen \"Grid-off\" is selected, "
                                            "the converter operates in grid-off mode (VF)."));

    //恒功率
    ButtonToTable->add_SpecificationData(Constant_power_explain,myTable , line++, column, \
                                         tr("0"), tr("Constant power(AC)"), \
                                         tr("AC Side Power: You can control the charging and discharging power of the battery from the AC side by modifying this value. "
                                            "When the advanced setting for power control mode is set to Constant Power mode (CP_AC), a positive value indicates discharging, and a negative value indicates charging.\n"
                                            "For example, setting it to -5 means that the AC side will charge the battery at a power of -5 kW. "
                                            "Due to converter losses, the DC side power will be lower than the AC side power in this case. Setting it to 5 means that the AC side will output power at 5 kW. "
                                            "Due to converter losses, the DC side power will be higher than the AC side power in this case."));

    //EMS通信方式
    ButtonToTable->add_SpecificationData(EMS_Comm_type_explain, myTable, line++, column, \
                                         "RS485", tr("EMS Comm type"), \
                                         tr("EMS communication methods: RS485, CAN, Ethernet.\nThe setting communication methods are readable and writable in remote mode, and only readable in local mode. "
                                            "The unselected communication methods are only readable in both remote and local mode."));

    //EMS CAN协议
    ButtonToTable->add_SpecificationData(EMS_CAN_Protocol_explain, myTable, line++, column, \
                                         "RS485", tr("EMS CAN Protocol"), \
                                         tr("."));
    line = 0;
    column = 3;
    //控制方式
    ButtonToTable->add_SpecificationData(Control_mode_explain, myTable, line++, column, \
                                         tr("Local"), tr("Control mode"), \
                                         tr("Local: Converter control through HMI, In this mode, the EMS can only read and cannot write.\n"
                                            "    Remote: In remote mode, the EMS can perform both read and write control."));

    //电池类型
    ButtonToTable->add_SpecificationData(Battery_type_explain, myTable, line++, column, \
                                         tr("Lithium"), tr("Battery type"), \
                                         tr("Battery Types: Lithium, Lead-Acid."));

    //BMS通信方式
    ButtonToTable->add_SpecificationData(BMS_Comm_type_explain, myTable, line++, column, \
                                         "CAN", tr("BMS Comm type"), \
                                         tr("Battery Communication Modes: None, RS485, CAN, Ethernet. "
                                            "(Note: Due to the fact that CAN and Ethernet both have only one port, the battery communication mode and EMS communication mode cannot be selected as \"CAN\" or \"Ethernet\" simultaneously.)"));

    //BMS厂家
    ButtonToTable->add_SpecificationData(BAT_manufacturers_explain, myTable, line++, column, \
                                         tr("Auto"), tr("BAT protocol"), \
                                         tr("Battery Protocol: Parse the messages sent by BMS based on the selected battery protocol."
                                            "\nCurrently supported battery manufacturer protocols include:"
                                            "MEGA, LISHEN, GREATPOWER, GOLD, BMSER, LANLI, SLANPOWER, PYLON, CATL, SUOYING, XINGWANGDA, KUBO, GOLD_V2, TOGOOD, PGS, WOBOYUAN, KGOOER, LD, PYLON_L, VILION, TUOPU,JDI,BGS,HUASU,ALPHA,SHIDING,Freedom."
                                            "\nSelect AUTO to automatically detect the battery manufacturer protocol."));

}
/*基础参数-UPS-控件到表格*/
void MEGAWin::SetBasicParameterUPSToTable(QTableWidget *myTable)
{
    int line = 0;
    int column = 1;
    //并网方式
    ButtonToTable->add_SpecificationData(Grid_connected_mode1_explain,myTable, line++, column, \
                                         tr("automatic"), tr("Grid conected mode of the converter "), \
                                         tr("When \"Auto\" is selected, the converter will automatically switch between grid-on and grid-off. When the grid side is normal, "
                                            "the converter operates in grid-on mode (PQ).When the grid side is abnormal, the converter operates in grid-off mode (VF).\nWhen \"Grid-on\" is selected, "
                                            "the converter operates in grid-on mode (PQ).When the grid side is abnormal, the converter will shut down.\nWhen \"Grid-off\" is selected, "
                                            "the converter operates in grid-off mode (VF)."));

    //恒功率
    ButtonToTable->add_SpecificationData(Constant_power1_explain,myTable , line++, column, \
                                         tr("0"), tr("Constant power(AC)"), \
                                         tr("AC Side Power: You can control the charging and discharging power of the battery from the AC side by modifying this value. "
                                            "When the advanced setting for power control mode is set to Constant Power mode (CP_AC), a positive value indicates discharging, and a negative value indicates charging.\n"
                                            "For example, setting it to -5 means that the AC side will charge the battery at a power of -5 kW. "
                                            "Due to converter losses, the DC side power will be lower than the AC side power in this case. Setting it to 5 means that the AC side will output power at 5 kW. "
                                            "Due to converter losses, the DC side power will be higher than the AC side power in this case."));

    //EMS通信方式
    ButtonToTable->add_SpecificationData(EMS_Comm_type1_explain, myTable, line++, column, \
                                         "RS485", tr("EMS Comm type"), \
                                         tr("EMS communication methods: RS485, CAN, Ethernet.\nThe setting communication methods are readable and writable in remote mode, and only readable in local mode. "
                                            "The unselected communication methods are only readable in both remote and local mode."));

    //EMS CAN协议
    ButtonToTable->add_SpecificationData(EMS_CAN_Protocol1_explain, myTable, line++, column, \
                                         "RS485", tr("EMS CAN Protocol"), \
                                         tr("."));

    //启动SOC
    ButtonToTable->add_SpecificationData(StartSOC_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //启动单体电压
    ButtonToTable->add_SpecificationData(StartCellVol_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));


    //启动总压
    ButtonToTable->add_SpecificationData(StartTotalVol_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //后备充电功率
    ButtonToTable->add_SpecificationData(BackupChargingPower_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));
    line = 0;
    column = 3;
    //控制方式
    ButtonToTable->add_SpecificationData(Control_mode1_explain, myTable, line++, column, \
                                         tr("Local"), tr("Control mode"), \
                                         tr("Local: Converter control through HMI, In this mode, the EMS can only read and cannot write.\n"
                                            "    Remote: In remote mode, the EMS can perform both read and write control."));

    //电池类型
    ButtonToTable->add_SpecificationData(Battery_type1_explain, myTable, line++, column, \
                                         tr("Lithium"), tr("Battery type"), \
                                         tr("Battery Types: Lithium, Lead-Acid."));

    //BMS通信方式
    ButtonToTable->add_SpecificationData(BMS_Comm_type1_explain, myTable, line++, column, \
                                         "CAN", tr("BMS Comm type"), \
                                         tr("Battery Communication Modes: None, RS485, CAN, Ethernet. "
                                            "(Note: Due to the fact that CAN and Ethernet both have only one port, the battery communication mode and EMS communication mode cannot be selected as \"CAN\" or \"Ethernet\" simultaneously.)"));

    //BMS厂家
    ButtonToTable->add_SpecificationData(BAT_manufacturers1_explain, myTable, line++, column, \
                                         tr("Auto"), tr("BAT protocol"), \
                                         tr("Battery Protocol: Parse the messages sent by BMS based on the selected battery protocol."
                                            "\nCurrently supported battery manufacturer protocols include:"
                                            "MEGA, LISHEN, GREATPOWER, GOLD, BMSER, LANLI, SLANPOWER, PYLON, CATL, SUOYING, XINGWANGDA, KUBO, GOLD_V2, TOGOOD, PGS, WOBOYUAN, KGOOER, LD, PYLON_L, VILION, TUOPU,JDI,BGS,HUASU,ALPHA,SHIDING,Freedom."
                                            "\nSelect AUTO to automatically detect the battery manufacturer protocol."));

    //停止SOC
    ButtonToTable->add_SpecificationData(StopSOC_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));
    //停止单体电压
    ButtonToTable->add_SpecificationData(StopCellVol_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //停止总压
    ButtonToTable->add_SpecificationData(StopTotalVol_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //月循环日期
    ButtonToTable->add_SpecificationData(MonthlyCycleDate_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

}
/*基础参数-稳态扩容-控件到表格*/
void MEGAWin::SetBasicParameterExpansionToTable(QTableWidget *myTable)
{
    int line = 0;
    int column = 1;
    //并网方式
    ButtonToTable->add_SpecificationData(Grid_connected_mode2_explain,myTable, line++, column, \
                                         tr("automatic"), tr("Grid conected mode of the converter "), \
                                         tr("When \"Auto\" is selected, the converter will automatically switch between grid-on and grid-off. When the grid side is normal, "
                                            "the converter operates in grid-on mode (PQ).When the grid side is abnormal, the converter operates in grid-off mode (VF).\nWhen \"Grid-on\" is selected, "
                                            "the converter operates in grid-on mode (PQ).When the grid side is abnormal, the converter will shut down.\nWhen \"Grid-off\" is selected, "
                                            "the converter operates in grid-off mode (VF)."));

    //恒功率
    ButtonToTable->add_SpecificationData(Constant_power2_explain,myTable , line++, column, \
                                         tr("0"), tr("Constant power(AC)"), \
                                         tr("AC Side Power: You can control the charging and discharging power of the battery from the AC side by modifying this value. "
                                            "When the advanced setting for power control mode is set to Constant Power mode (CP_AC), a positive value indicates discharging, and a negative value indicates charging.\n"
                                            "For example, setting it to -5 means that the AC side will charge the battery at a power of -5 kW. "
                                            "Due to converter losses, the DC side power will be lower than the AC side power in this case. Setting it to 5 means that the AC side will output power at 5 kW. "
                                            "Due to converter losses, the DC side power will be higher than the AC side power in this case."));

    //EMS通信方式
    ButtonToTable->add_SpecificationData(EMS_Comm_type2_explain, myTable, line++, column, \
                                         "RS485", tr("EMS Comm type"), \
                                         tr("EMS communication methods: RS485, CAN, Ethernet.\nThe setting communication methods are readable and writable in remote mode, and only readable in local mode. "
                                            "The unselected communication methods are only readable in both remote and local mode."));

    //EMS CAN协议
    ButtonToTable->add_SpecificationData(EMS_CAN_Protocol2_explain, myTable, line++, column, \
                                         "RS485", tr("EMS CAN Protocol"), \
                                         tr("."));

    //柴发充电SOC
    ButtonToTable->add_SpecificationData(DG_Charge_SOC_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //充电停止SOC说明
    ButtonToTable->add_SpecificationData(Charge_Stop_SOC_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //电网容量
    ButtonToTable->add_SpecificationData(Grid_Capacity_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));
    line = 0;
    column = 3;
    //控制方式
    ButtonToTable->add_SpecificationData(Control_mode2_explain, myTable, line++, column, \
                                         tr("Local"), tr("Control mode"), \
                                         tr("Local: Converter control through HMI, In this mode, the EMS can only read and cannot write.\n"
                                            "    Remote: In remote mode, the EMS can perform both read and write control."));

    //电池类型
    ButtonToTable->add_SpecificationData(Battery_type2_explain, myTable, line++, column, \
                                         tr("Lithium"), tr("Battery type"), \
                                         tr("Battery Types: Lithium, Lead-Acid."));

    //BMS通信方式
    ButtonToTable->add_SpecificationData(BMS_Comm_type2_explain, myTable, line++, column, \
                                         "CAN", tr("BMS Comm type"), \
                                         tr("Battery Communication Modes: None, RS485, CAN, Ethernet. "
                                            "(Note: Due to the fact that CAN and Ethernet both have only one port, the battery communication mode and EMS communication mode cannot be selected as \"CAN\" or \"Ethernet\" simultaneously.)"));

    //BMS厂家
    ButtonToTable->add_SpecificationData(BAT_manufacturers2_explain, myTable, line++, column, \
                                         tr("Auto"), tr("BAT protocol"), \
                                         tr("Battery Protocol: Parse the messages sent by BMS based on the selected battery protocol."
                                            "\nCurrently supported battery manufacturer protocols include:"
                                            "MEGA, LISHEN, GREATPOWER, GOLD, BMSER, LANLI, SLANPOWER, PYLON, CATL, SUOYING, XINGWANGDA, KUBO, GOLD_V2, TOGOOD, PGS, WOBOYUAN, KGOOER, LD, PYLON_L, VILION, TUOPU,JDI,BGS,HUASU,ALPHA,SHIDING,Freedom."
                                            "\nSelect AUTO to automatically detect the battery manufacturer protocol."));

    //电网充电SOC
    ButtonToTable->add_SpecificationData(Grid_Charge_SOC_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //放电停止SOC说明
    ButtonToTable->add_SpecificationData(Disharge_Stop_SOC_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

}
/*锂电池页-控件到表格*/
void MEGAWin::SetLithiumToTable(QTableWidget *myTable)
{
    int line = 0;int column = 1;//当前解释的button行和列
    //并网DOD说明
    ButtonToTable->add_SpecificationData(DOD_OnGrid_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //充电电压上限说明
    ButtonToTable->add_SpecificationData(Charge_Volt_Upper_Limit_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //充电电压上限回差说明
    ButtonToTable->add_SpecificationData(Charge_Volt_upper_Limit_delta_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //充电电流限制说明
    ButtonToTable->add_SpecificationData(Charge_Current_Limit_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //柴发开启SOC说明
    ButtonToTable->add_SpecificationData(Gen_turn_on_SOC_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //强充开启说明
    ButtonToTable->add_SpecificationData(ForceCharge_start_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));
    line = 0;
    column = 3;
    //离网DOD说明
    ButtonToTable->add_SpecificationData(DOD_OffGrid_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //放电电压限制说明
    ButtonToTable->add_SpecificationData(Disc_Volt_lower_Limit_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //放电电压下限回差说明
    ButtonToTable->add_SpecificationData(Discharge_Volt_upper_Limit_delta_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //放电电流限制说明
    ButtonToTable->add_SpecificationData(Discharge_Current_Limit_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //柴发关闭SOC说明
    ButtonToTable->add_SpecificationData(Gen_turn_off_SOC_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //强充结束说明
    ButtonToTable->add_SpecificationData(ForceCharge_top_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

}
/*铅酸电池页-控件到表格*/
void MEGAWin::SetLead_acidToTable(QTableWidget *myTable)
{
    int line = 0;int column = 1;//当前解释的button行和列
    //容量
    ButtonToTable->add_SpecificationData(Capacity_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //电池节数
    ButtonToTable->add_SpecificationData(Cell_number_2V_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //浮充电压
    ButtonToTable->add_SpecificationData(Bat_float_vol_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //均充电压
    ButtonToTable->add_SpecificationData(Bat_filling_vol_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //充电限流值
    ButtonToTable->add_SpecificationData(Charge_limiting_value_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //发电机关闭
    ButtonToTable->add_SpecificationData(Discharge_limiting_value_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //发电机开启
    ButtonToTable->add_SpecificationData(Generator_turn_off_SOC_B1_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //发电机开启
    ButtonToTable->add_SpecificationData(Generator_turn_on_SOC_A1_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));
    line = 0;
    column = 3;
    //离网EOD
    ButtonToTable->add_SpecificationData(Grid_off_EOD_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //并网EOD
    ButtonToTable->add_SpecificationData(Grid_on_EOD_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));
    line = 7;
    column = 3;
    //均充转浮充电流
    ButtonToTable->add_SpecificationData(Uniform_To_Flushing_current_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));


    //浮充转均充电流
    ButtonToTable->add_SpecificationData(Flushing_To_Uniform_current_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

}
/*时间段运行页-控件到表格*/
void MEGAWin::SetMixedTime_TabToTable(QTableWidget *myTable)
{
    QString temp1 = tr("Check");
    QString temp2 = tr("Start_Time");
    QString temp3 = tr("End_Time");
    QString temp5 = tr("Power");
    QString temp6 = tr("08:00");
    QString temp7 = tr("10:00");
    QString temp8 = tr("End time: The system stops automatically running when the system reaches this time.");
    QString temp10 = tr("Working Power: Only effective in peak shaving mode. Positive values indicate discharging, while negative values indicate charging.");
    QString temp11 = tr("Start time: When the system reaches this time, it starts to run automatically.");
    QString temp12 = tr("Select: After this function is enabled, the system automatically runs the selected function mode within the specified period.");
    QString temp13 = tr("Charge");
    QString temp14 = tr("DisCharge");
    QString temp15 = tr("Status:Display only. When working power is positive, it shows 'Discharge'; when operating power is negative, it shows 'Charge'.");
    QString temp16 = tr("Status");

    for(int i = 0;i < 20; i++ )
    {
        if(i<5)
        {
            ButtonToTable->add_SpecificationData(TimePeriodButtonList->at(i), myTable,i, 0, "√", temp1, temp12);
        }
        else
        {
            ButtonToTable->add_SpecificationData(TimePeriodButtonList->at(i), myTable,i, 0, "", temp1, temp12);
        }

        ButtonToTable->add_SpecificationData(TimePeriodButtonList->at(i+20), myTable, i, 1, temp6, temp2, temp11);
        ButtonToTable->add_SpecificationData(TimePeriodButtonList->at(i+40), myTable, i, 2, temp7, temp3, temp8);

        if(i%2==0)
        {
            ButtonToTable->add_SpecificationData(TimePeriodButtonList->at(i+60), myTable,i, 4, "-10", temp5, temp10);
            ButtonToTable->add_SpecificationData(TimePeriodButtonList->at(i+80), myTable,i, 3, temp13, temp16, temp15);
        }
        if(i%2==1)
        {
            ButtonToTable->add_SpecificationData(TimePeriodButtonList->at(i+60), myTable,i, 4, "10", temp5, temp10);
            ButtonToTable->add_SpecificationData(TimePeriodButtonList->at(i+80), myTable,i, 3, temp14, temp16, temp15);
        }
    }
}
/*高级设置页1-控件到表格*/
void MEGAWin::SetAdvancedSetup1ToTable(QTableWidget *myTable)
{
    int line = 0;int column = 1;//当前解释的button行和列
    //功率控制类型说明
    ButtonToTable->add_SpecificationData(Power_control_type_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //输出无功方式说明
    ButtonToTable->add_SpecificationData(Output_reactive_power_mode_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //输出无功功率说明
    ButtonToTable->add_SpecificationData(Output_reactive_power_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //输出功率因素说明
    ButtonToTable->add_SpecificationData(Output_power_factor_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //恒压说明
    ButtonToTable->add_SpecificationData(Constant_voltage_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //恒流说明
    ButtonToTable->add_SpecificationData(Constant_current_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //输出功率上限说明
    ButtonToTable->add_SpecificationData(Output_power_limit_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //设备号说明
    ButtonToTable->add_SpecificationData(Machine_number_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //并机说明
    ButtonToTable->add_SpecificationData(Parallel_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));
    line = 0;
    column = 3;
    //主机地址说明
    ButtonToTable->add_SpecificationData(Host_Address_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //Modbus偏移地址说明
    ButtonToTable->add_SpecificationData(ModbusDeviationAddress_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //串口2说明
    ButtonToTable->add_SpecificationData(serial_port_2_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //串口3说明
    ButtonToTable->add_SpecificationData(serial_port_3_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //串口4说明
    ButtonToTable->add_SpecificationData(serial_port_4_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //串口5说明
    ButtonToTable->add_SpecificationData(serial_port_5_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //串口6说明
    ButtonToTable->add_SpecificationData(serial_port_6_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //CAN1说明
    ButtonToTable->add_SpecificationData(Can_port_1_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //CAN2说明
    ButtonToTable->add_SpecificationData(Can_port_2_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));
    line = 0;
    column = 5;
    //语言说明
    ButtonToTable->add_SpecificationData(Language_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //声音说明
    ButtonToTable->add_SpecificationData(Sounds_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //电表型号
    ButtonToTable->add_SpecificationData(MeterModel_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //防逆流功率容差
    ButtonToTable->add_SpecificationData(AntiBackflowPowerTolerance_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //BMS通信故障判定时间
    ButtonToTable->add_SpecificationData(BmsComFaultTime_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //EMS通信故障判定时间
    ButtonToTable->add_SpecificationData(EMSComFaultModel_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //系统升级说明
    ButtonToTable->add_SpecificationData(System_upgrade_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //清除数据说明
    ButtonToTable->add_SpecificationData(Clear_Data_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //恢复出厂说明
    ButtonToTable->add_SpecificationData(Restore_factory_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

}
/*高级设置页2-控件到表格*/
void MEGAWin::SetAdvancedSetup2ToTable(QTableWidget *myTable)
{
    int line = 0;int column = 1;//当前解释的button行和列
    //充电功率限制
    ButtonToTable->add_SpecificationData(ChargingPowerLimit_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //放电功率限制
    ButtonToTable->add_SpecificationData(DischargingPowerLimit_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));
    line = 0;
    column = 3;
    //用户密码说明
    ButtonToTable->add_SpecificationData(UserPassPort_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //超级权限说明
    ButtonToTable->add_SpecificationData(RootPassport_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));
    line = 0;
    column = 5;
    //备份设置参数
    ButtonToTable->add_SpecificationData(BackupSetParameters_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //恢复备份设置参数
    ButtonToTable->add_SpecificationData(RestoreBackupSetParameters_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

}
/*高级设置页3-控件到表格*/
void MEGAWin::SetAdvancedSetup3ToTable(QTableWidget *myTable)
{
    int line = 0;int column = 1;//当前解释的button行和列
    //功率变化率说明
    ButtonToTable->add_SpecificationData(Change_rate_of_power_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //电网频率变化范围上限说明
    ButtonToTable->add_SpecificationData(Grid_frequency_upper_limit_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //电网频率变化范围下限说明
    ButtonToTable->add_SpecificationData(Grid_frequency_lower_limit_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //电压保护范围上限说明
    ButtonToTable->add_SpecificationData(Vol_protection_upper_limit_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //电压保护范围下限说明
    ButtonToTable->add_SpecificationData(Vol_protection_lower_limit_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //高穿使能说明
    ButtonToTable->add_SpecificationData(HVRT_enable_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //低穿使能说明
    ButtonToTable->add_SpecificationData(LVRT_enable_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));
    line = 0;
    column = 3;
    //机器型号说明
    ButtonToTable->add_SpecificationData(Machine_type_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //机器容量说明
    ButtonToTable->add_SpecificationData(Machine_capacity_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //输出频率等级说明
    ButtonToTable->add_SpecificationData(Output_Fre_grade_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //输出电压等级说明
    ButtonToTable->add_SpecificationData(Output_vol_level_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //逆变电压等级说明(变比)
    ButtonToTable->add_SpecificationData(Converter_side_vol_level_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //逆变器并网方式说明(变流器防逆流)
    ButtonToTable->add_SpecificationData(Grid_connected_mode_of_Inv_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //一次调频死区
    ButtonToTable->add_SpecificationData(PrimaryFrequencyModulationDeadZone_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));
    line = 0;
    column = 5;
    //有功调频系数
    ButtonToTable->add_SpecificationData(ActiveFrequencyModulationCoefficient_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //电网恢复时间
    ButtonToTable->add_SpecificationData(PowerGridRecoveryTime_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //绝缘监测使能说明
    ButtonToTable->add_SpecificationData(Insulation_detection_enable_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //转动惯量使能说明
    ButtonToTable->add_SpecificationData(Inertia_enable_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //恒压并机说明
    ButtonToTable->add_SpecificationData(CV_parallel_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //孤岛使能说明
    ButtonToTable->add_SpecificationData(AFD_enable_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

    //一次调频使能说明
    ButtonToTable->add_SpecificationData(PrimaryFreq_enable_explain,myTable, line++, column, \
                                         tr(""), tr(""), \
                                         tr("."));

}
/*高级设置外设页-控件到表格*/
void MEGAWin::Device_TabToTable(QTableWidget *myTable)
{

}
/*BMS保护页-控件到表格*/
void MEGAWin::BMSProtectToTable(QTableWidget *myTable)
{

}
/*高级设置调试页-控件到表格*/
void MEGAWin::PCS_Debugg(QTableWidget *myTable)
{

}
/*菜单点击*/
void MEGAWin::on_UI_MenuBtn_clicked()
{
    ui->UI_stackedWidget->setCurrentWidget(ui->Menu_page);
}
/*下一页*/
void MEGAWin::on_SetNext_bt_clicked()
{
    if( CurrentCheckMode != ADVANCED_SETTING )
    {
        System_Current_Page++;
        if( System_Current_Page > MixedMode_PAGE_NUM  )
        {
            System_Current_Page = ParamSet_NUM;
        }
        if( (System_Current_Page == Lithium_PAGE_NUM) || (System_Current_Page == Lead_PAGE_NUM) )
        {
            ui->SetPageNum_lb->setText( QString("%1/%2").arg(Lithium_PAGE_NUM+1).arg(SystemTotal_PAGE) );
        }
        else if( System_Current_Page > Lead_PAGE_NUM )
        {
            ui->SetPageNum_lb->setText( QString("%1/%2").arg(System_Current_Page).arg(SystemTotal_PAGE) );
        }
        else
        {
            ui->SetPageNum_lb->setText( QString("%1/%2").arg(System_Current_Page+1).arg(SystemTotal_PAGE) );
        }
        if( System_Current_Page == MixedMode_PAGE_NUM )
        {

        }
        if(System_Current_Page == ParamSet_NUM)
        {
            ui->PageInfo_lb->setText(QString("%1\n%2").arg(Mode_Str.at(CurrentCheckMode)).arg(Mode_title_Str.at(System_Current_Page)));
            if(CurrentCheckMode == Mode_UPS)
            {
                ui->ParamSet_Tab->setVisible(false);
                ui->UPS_ParamSet_Tab->setVisible(true);
                ui->GridExpan_ParamSet_Tab->setVisible(false);
            }
            else if(CurrentCheckMode == Mode_SteadyStateExpansion)
            {
                ui->ParamSet_Tab->setVisible(false);
                ui->UPS_ParamSet_Tab->setVisible(false);
                ui->GridExpan_ParamSet_Tab->setVisible(true);
            }
            else
            {
                    ui->ParamSet_Tab->setVisible(true);
                ui->UPS_ParamSet_Tab->setVisible(false);
                ui->GridExpan_ParamSet_Tab->setVisible(false);
            }
        }
        else
        {
            ui->PageInfo_lb->setText(Mode_title_Str.at(System_Current_Page));
        }
        ui->setpage_stackedWidget->setCurrentIndex( System_Current_Page );//根据页面索引号切换页面
    }
    else if( CurrentCheckMode == ADVANCED_SETTING )
    {
        Advanced_Current_Page++;
        if( Advanced_Current_Page > MonitorDeb_PAGE_NUM  )
        {
            Advanced_Current_Page = Advanced_PAGE1_NUM;
        }

        ui->PageInfo_lb->setText(Mode_title_Str.at(Advanced_Current_Page));
        ui->SetPageNum_lb->setText( QString("%1/%2").arg(Advanced_Current_Page-SystemTotal_PAGE).arg(AdvancedTotal_PAGE) );
        ui->setpage_stackedWidget->setCurrentIndex( Advanced_Current_Page );
    }
}
/*上一页*/
void MEGAWin::on_SetPrevious_bt_clicked()
{
    if( CurrentCheckMode != ADVANCED_SETTING )
    {
        System_Current_Page--;
        if( System_Current_Page < ParamSet_NUM  )
        {
            System_Current_Page = MixedMode_PAGE_NUM;
        }

        if( (System_Current_Page == Lithium_PAGE_NUM) || (System_Current_Page == Lead_PAGE_NUM) )
        {
            ui->SetPageNum_lb->setText( QString("%1/%2").arg(Lithium_PAGE_NUM+1).arg(SystemTotal_PAGE) );
        }
        else if( System_Current_Page > Lead_PAGE_NUM )
        {
            ui->SetPageNum_lb->setText( QString("%1/%2").arg(System_Current_Page).arg(SystemTotal_PAGE) );
        }
        else
        {
            ui->SetPageNum_lb->setText( QString("%1/%2").arg(System_Current_Page+1).arg(SystemTotal_PAGE) );
        }
        if( System_Current_Page == MixedMode_PAGE_NUM )
        {

        }
        if(System_Current_Page == ParamSet_NUM)
            ui->PageInfo_lb->setText(QString("%1\n%2").arg(Mode_Str.at(CurrentCheckMode)).arg(Mode_title_Str.at(System_Current_Page)));
        else
            ui->PageInfo_lb->setText(Mode_title_Str.at(System_Current_Page));
        ui->setpage_stackedWidget->setCurrentIndex( System_Current_Page );
    }
    else if( CurrentCheckMode == ADVANCED_SETTING )
    {
        Advanced_Current_Page--;
        if( Advanced_Current_Page < Advanced_PAGE1_NUM  )
        {
            Advanced_Current_Page = MonitorDeb_PAGE_NUM;
        }
        ui->SetPageNum_lb->setText( QString("%1/%2").arg(Advanced_Current_Page-SystemTotal_PAGE).arg(AdvancedTotal_PAGE) );
        ui->PageInfo_lb->setText(Mode_title_Str.at(Advanced_Current_Page));
        ui->setpage_stackedWidget->setCurrentIndex( Advanced_Current_Page );
    }
}
/*点击登录*/
void MEGAWin::on_ToLogin_bt_clicked()
{
    if( ui->combox_Account->currentIndex() == Login_User )
    {
        ui->UI_stackedWidget->setCurrentWidget( ui->UI_page );
        ui->stackedWidget->setCurrentWidget( ui->Host_page );
        ui->System_btn->setText(tr("System"));
        Account_Type = Login_User;

    }
    else if( ui->combox_Account->currentIndex() == Login_Maintain )
    {
        ui->UI_stackedWidget->setCurrentWidget( ui->UI_page );
        ui->stackedWidget->setCurrentWidget( ui->Host_page );
        ui->System_btn->setText(tr("System"));
        Account_Type = Login_Maintain;
        Account_Change( Account_Type );
    }
    else if( ui->combox_Account->currentIndex() == Login_Root )
    {
        ui->UI_stackedWidget->setCurrentWidget( ui->UI_page );
        ui->stackedWidget->setCurrentWidget( ui->Host_page );
        ui->System_btn->setText(tr("System"));
        Account_Type = Login_Root;
        Account_Change( Account_Type );
    }
}
/*取消登录*/
void MEGAWin::on_Cancel_bt_clicked()
{
    ui->UI_MenuBtn->click();
    Account_Change( Account_Type );
}
/*实时数据-电网-点击跳转*/
void MEGAWin::on_SGrid_btn_2_clicked()
{
    ui->Bypass_Tab_2->setCurrentWidget(ui->Bypass_Grid_page_2);
}
/*实时数据-变流器-点击跳转*/
void MEGAWin::on_SConverter_btn_2_clicked()
{
    ui->Bypass_Tab_2->setCurrentWidget(ui->Bypass_Converter_page_2);
}
/*实时数据-负载-点击跳转*/
void MEGAWin::on_SLoad_btn_2_clicked()
{
    ui->Bypass_Tab_2->setCurrentWidget(ui->Bypass_Load_page_2);
}
