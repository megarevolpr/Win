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
//    this->mapFromGlobal(QPoint(0,0));
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
    //创建下拉框
//    combox_ui_GridMode =   new QComboBox();             //并网方式
//    combox_ui_GridMode->setView(new QListView());

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
    Constant_power_explain = new QPushButton;           //恒功率说明
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
    /*****************************PCS数据****************************************/
    PCS_vol_AB_btn = new QPushButton;
    PCS_vol_BC_btn = new QPushButton;
    PCS_vol_CA_btn = new QPushButton;
    PCS_cur_A_btn  = new QPushButton;
    PCS_cur_B_btn  = new QPushButton;
    PCS_cur_C_btn  = new QPushButton;
    PCS_act_P_btn  = new QPushButton;
    PCS_rea_P_btn  = new QPushButton;
    PCS_par_P_btn  = new QPushButton;
    PCS_Pf_btn     = new QPushButton;
    PCS_Bat_vol_btn= new QPushButton;
    PCS_Bat_cur_btn= new QPushButton;
    PCS_Bat_P_btn  = new QPushButton;
    PCS_Bus_vol_btn= new QPushButton;
    PCS_IGBT_T_btn = new QPushButton;
    PCS_Env_T_btn  = new QPushButton;

    pButtonGroup   = new QButtonGroup();
    Grid_vol_AB_btn = new QPushButton;
    Grid_vol_BC_btn = new QPushButton;
    Grid_vol_CA_btn = new QPushButton;
    Grid_cur_A_btn  = new QPushButton;
    Grid_cur_B_btn  = new QPushButton;
    Grid_cur_C_btn  = new QPushButton;
    Grid_act_P_btn  = new QPushButton;
    Grid_rea_P_btn  = new QPushButton;
    Grid_app_P_btn  = new QPushButton;
    Grid_fre_btn    = new QPushButton;
    Grid_Pf_btn     = new QPushButton;

    Load_vol_AB_btn = new QPushButton;
    Load_vol_BC_btn = new QPushButton;
    Load_vol_CA_btn = new QPushButton;
    Load_cur_A_btn  = new QPushButton;
    Load_cur_B_btn  = new QPushButton;
    Load_cur_C_btn  = new QPushButton;
    Load_act_P_btn  = new QPushButton;
    Load_rea_P_btn  = new QPushButton;
    Load_app_P_btn  = new QPushButton;
    Load_fre_btn    = new QPushButton;
    Load_Pf_btn     = new QPushButton;


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

//    timer2 = new QTimer();
//    timer2->setInterval(600000);//设置密码记录时间为10分钟

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
    ui->System_Tab->setRowHeight(0, 50);
    ui->System_Tab->setColumnWidth(1,163);
    ui->System_Tab->setRowHeight(1, 50);
    ui->System_Tab->setColumnWidth(2,163);
    ui->System_Tab->setRowHeight(2, 50);
    ui->System_Tab->setColumnWidth(3,163);
    ui->System_Tab->setRowHeight(3, 50);
    ui->System_Tab->setColumnWidth(4,163);
    ui->System_Tab->setRowHeight(4, 50);
    ui->System_Tab->setColumnWidth(5,163);
    ui->System_Tab->setRowHeight(5, 50);
    ui->System_Tab->horizontalHeader()->setStretchLastSection(3);


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
/******************************************************************************
 * 设备信息表表初始化
 *
 *
 *
 *
 *
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
    //    ui->Lithum_Tab->horizontalHeader()->setStretchLastSection(5);
}
/******************************************************************************
 * 系统运行时间表初始化
 *
 *
 *
 *
 *
 * ***************************************************************************/
void MEGAWin::RunTimeSet_tab()
{
    QStringList time_str;
//    bool ok;
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
    ui->Time_tableWidget->setColumnWidth(0,50);
    ui->Time_tableWidget->setColumnWidth(1,180);
    ui->Time_tableWidget->setColumnWidth(2,180);
    ui->Time_tableWidget->setColumnWidth(3,130);
//    ui->Time_tableWidget->setColumnWidth(4,125);
    ui->Time_tableWidget->horizontalHeader()->setStretchLastSection(4);

    QStringList choice;
    choice <<tr("charge") << tr("discharge") << tr("Automatic");

//    StartTime_l.append(StartTime1);
//    EndTime_l.append(EndTime1);
//    ComboBox_l.append(choice_cb1);
//    CheckBox_l.append(check1);
//    choice_cb1->addItems(choice);
//    PowerBtn_l.append(Power1);
//    StartTime_l.append(StartTime2);
//    EndTime_l.append(EndTime2);
//    ComboBox_l.append(choice_cb2);
//    CheckBox_l.append(check2);
//    choice_cb2->addItems(choice);
//    PowerBtn_l.append(Power2);
//    StartTime_l.append(StartTime3);
//    EndTime_l.append(EndTime3);
//    ComboBox_l.append(choice_cb3);
//    CheckBox_l.append(check3);
//    choice_cb3->addItems(choice);
//    PowerBtn_l.append(Power3);
//    StartTime_l.append(StartTime4);
//    EndTime_l.append(EndTime4);
//    ComboBox_l.append(choice_cb4);
//    CheckBox_l.append(check4);
//    choice_cb4->addItems(choice);
//    PowerBtn_l.append(Power4);
//    StartTime_l.append(StartTime5);
//    EndTime_l.append(EndTime5);
//    ComboBox_l.append(choice_cb5);
//    CheckBox_l.append(check5);
//    choice_cb5->addItems(choice);
//    PowerBtn_l.append(Power5);
//    StartTime_l.append(StartTime6);
//    EndTime_l.append(EndTime6);
//    ComboBox_l.append(choice_cb6);
//    CheckBox_l.append(check6);
//    choice_cb6->addItems(choice);
//    PowerBtn_l.append(Power6);
//    StartTime_l.append(StartTime7);
//    EndTime_l.append(EndTime7);
//    ComboBox_l.append(choice_cb7);
//    CheckBox_l.append(check7);
//    choice_cb7->addItems(choice);
//    PowerBtn_l.append(Power7);
//    StartTime_l.append(StartTime8);
//    EndTime_l.append(EndTime8);
//    ComboBox_l.append(choice_cb8);
//    CheckBox_l.append(check8);
//    choice_cb8->addItems(choice);
//    PowerBtn_l.append(Power8);
//    StartTime_l.append(StartTime9);
//    EndTime_l.append(EndTime9);
//    ComboBox_l.append(choice_cb9);
//    CheckBox_l.append(check9);
//    choice_cb9->addItems(choice);
//    PowerBtn_l.append(Power9);
//    StartTime_l.append(StartTime10);
//    EndTime_l.append(EndTime10);
//    ComboBox_l.append(choice_cb10);
//    CheckBox_l.append(check10);
//    choice_cb10->addItems(choice);
//    PowerBtn_l.append(Power10);
//    StartTime_l.append(StartTime11);
//    EndTime_l.append(EndTime11);
//    ComboBox_l.append(choice_cb11);
//    CheckBox_l.append(check11);
//    choice_cb11->addItems(choice);
//    PowerBtn_l.append(Power11);
//    StartTime_l.append(StartTime12);
//    EndTime_l.append(EndTime12);
//    ComboBox_l.append(choice_cb12);
//    CheckBox_l.append(check12);
//    choice_cb12->addItems(choice);
//    PowerBtn_l.append(Power12);
//    StartTime_l.append(StartTime13);
//    EndTime_l.append(EndTime13);
//    ComboBox_l.append(choice_cb13);
//    CheckBox_l.append(check13);
//    choice_cb13->addItems(choice);
//    PowerBtn_l.append(Power13);
//    StartTime_l.append(StartTime14);
//    EndTime_l.append(EndTime14);
//    ComboBox_l.append(choice_cb14);
//    CheckBox_l.append(check14);
//    choice_cb14->addItems(choice);
//    PowerBtn_l.append(Power14);
//    StartTime_l.append(StartTime15);
//    EndTime_l.append(EndTime15);
//    ComboBox_l.append(choice_cb15);
//    CheckBox_l.append(check15);
//    choice_cb15->addItems(choice);
//    PowerBtn_l.append(Power15);
//    StartTime_l.append(StartTime16);
//    EndTime_l.append(EndTime16);
//    ComboBox_l.append(choice_cb16);
//    CheckBox_l.append(check16);
//    choice_cb16->addItems(choice);
//    PowerBtn_l.append(Power16);
//    StartTime_l.append(StartTime17);
//    EndTime_l.append(EndTime17);
//    ComboBox_l.append(choice_cb17);
//    CheckBox_l.append(check17);
//    choice_cb17->addItems(choice);
//    PowerBtn_l.append(Power17);
//    StartTime_l.append(StartTime18);
//    EndTime_l.append(EndTime18);
//    ComboBox_l.append(choice_cb18);
//    CheckBox_l.append(check18);
//    choice_cb18->addItems(choice);
//    PowerBtn_l.append(Power18);
//    StartTime_l.append(StartTime19);
//    EndTime_l.append(EndTime19);
//    ComboBox_l.append(choice_cb19);
//    CheckBox_l.append(check19);
//    choice_cb19->addItems(choice);
//    PowerBtn_l.append(Power19);
//    StartTime_l.append(StartTime20);
//    EndTime_l.append(EndTime20);
//    ComboBox_l.append(choice_cb20);
//    CheckBox_l.append(check20);
//    choice_cb20->addItems(choice);
//    PowerBtn_l.append(Power20);

//    foreach(QComboBox *box, ComboBox_l)
//    {
//        box->setStyleSheet("QComboBox QAbstractItemView::item{height: 30}");
//        box->setView(new QListView());
//    }

//    for(int i = 0; i < ui->Time_tableWidget->rowCount(); i++)
//    {
//            ui->Time_tableWidget->setCellWidget(i, 0, (QWidget *)CheckBox_l.at(i));
//            ui->Time_tableWidget->setCellWidget(i, 1, (QWidget *)StartTime_l.at(i));
//            ui->Time_tableWidget->setCellWidget(i, 2, (QWidget *)EndTime_l.at(i));
//            ui->Time_tableWidget->setCellWidget(i, 3, (QWidget *)ComboBox_l.at(i));
//            ui->Time_tableWidget->setCellWidget(i, 4, (QWidget *)PowerBtn_l.at(i));
//    }

//    Start_strl_source = new QStringList;
//    End_strl_source = new QStringList;
//    Power_strl_source = new QStringList;
//    Enable_strl_source = new QStringList;
//    Chioce_strl_source = new QStringList;

//    Start_strl_new = new QStringList;
//    End_strl_new = new QStringList;
//    Power_strl_new = new QStringList;
//    Enable_strl_new = new QStringList;
//    Chioce_strl_new = new QStringList;
//    foreach(QCheckBox *Checkbox, CheckBox_l)
//    {
//        Checkbox->setStyleSheet("QCheckBox::indicator {width: 48px; height: 20px;} QCheckBox::indicator:checked {image: url(:/new_ui/UI/Tic.png);}");
//    }
//    foreach(MyPushButton *button, StartTime_l)
//    {
//        Start_strl_source->append(button->text());
//    }
//    foreach(MyPushButton *button, EndTime_l)
//    {
//        End_strl_source->append(button->text());
//    }

//    foreach(MyPushButton *button, PowerBtn_l)
//    {
//        Power_strl_source->append(button->text());
//    }

//    QStringList TimeSetData_list = Table_data("TimeSetData");
//    if(TimeSetData_list.isEmpty())
//    {
//        init_TimeSetData();
//        TimeSetData_list = Table_data("TimeSetData");
//    }

//    for(int i = 0; i < TimeSetData_list.size() / 6; i++)//行
//    {
//        CheckBox_l.at(i)->setCheckState(TimeSetData_list.at( i * 6 + 1) == "1" ? Qt::Checked : Qt::Unchecked);
//        StartTime_l.at(i)->setText(TimeSetData_list.at(i * 6 + 2));
//        EndTime_l.at(i)->setText(TimeSetData_list.at(i * 6 + 3));
//        ComboBox_l.at(i)->setCurrentIndex(TimeSetData_list.at( i * 6 + 4) == "0" ? 0 : 1);//charge : dicharge
//        PowerBtn_l.at(i)->setText(QString::number(TimeSetData_list.at( i * 6 + 5).toFloat(&ok) * 0.1));
//    }
//    foreach(QCheckBox *Checkbox, CheckBox_l)
//    {
//        Enable_strl_source->append( Checkbox->checkState() == Qt::Checked ? "1" : "0");
//    }

//    foreach(MyPushButton *button, StartTime_l)
//    {
//        Start_strl_source->append(button->text());
//    }
//    foreach(MyPushButton *button, EndTime_l)
//    {
//        End_strl_source->append(button->text());
//    }

//    foreach(QComboBox *box, ComboBox_l)
//    {
//        Chioce_strl_source->append( QString::number( box->currentIndex() ));
//    }

//    foreach(MyPushButton *button, PowerBtn_l)
//    {
//        Power_strl_source->append(button->text());
//    }
}
/******************************************************************************
 * 实时数据——模拟量
 *
 *
 *
 *
 *
 * ***************************************************************************/
void MEGAWin::RTData_Anologe()
{
    ui->RTDataModel_tableWidget->clearContents();//防止内存泄漏
//    ModuleData_Tab();
//    if(ui->UI_SystemParameter_Tab->item(1, 5)->text() != Machine_MEGA_TS)
//    {
//        ui->RTDataModel_tableWidget->setItem(0, 1, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.GridVolt.u16Line_ab * 0.1)+"V"));           //电网电压AB
//        ui->RTDataModel_tableWidget->setItem(1, 1, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.GridVolt.u16Line_bc * 0.1)+"V"));           //电网电压BC
//        ui->RTDataModel_tableWidget->setItem(2, 1, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.GridVolt.u16Line_ca * 0.1)+"V"));           //电网电压CA
//        ui->RTDataModel_tableWidget->setItem(3, 1, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.GridCurr.u16Phase_a * 0.1)+"A"));    //输出电流A
//        ui->RTDataModel_tableWidget->setItem(4, 1, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.GridCurr.u16Phase_b * 0.1)+"A"));    //输出电流B
//        ui->RTDataModel_tableWidget->setItem(5, 1, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.GridCurr.u16Phase_c * 0.1)+"A"));    //输出电流C
//        ui->RTDataModel_tableWidget->setItem(6, 1, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.GridActPwr.u16Self * 0.1) +"kW"));               //有功功率
//        ui->RTDataModel_tableWidget->setItem(7, 1, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.GridReactPwr.u16Self * 0.1) +"kVar"));             //无功功率
//        ui->RTDataModel_tableWidget->setItem(8, 1, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.GridApparentPwr.u16Self * 0.1) +"kVA"));          //视在功率
//        ui->RTDataModel_tableWidget->setItem(9, 1, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.GridFactor.u16Self * 0.01)));                    //输出功率因素

//        ui->RTDataModel_tableWidget->setItem(0, 3, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.PCSVoltage.u16Line_ab * 0.1)+"V"));                 //AB相逆变电压
//        ui->RTDataModel_tableWidget->setItem(1, 3, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.PCSVoltage.u16Line_bc * 0.1)+"V"));                 //BC相逆变电压
//        ui->RTDataModel_tableWidget->setItem(2, 3, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.PCSVoltage.u16Line_ca * 0.1)+"V"));                 //CA相逆变电压
//        ui->RTDataModel_tableWidget->setItem(3, 3, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.PCSCurrent.u16Phase_a * 0.1) +"A"));         //A相逆变电感电流
//        ui->RTDataModel_tableWidget->setItem(4, 3, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.PCSCurrent.u16Phase_b * 0.1) +"A"));         //B相逆变电感电流
//        ui->RTDataModel_tableWidget->setItem(5, 3, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.PCSCurrent.u16Phase_c * 0.1) +"A"));         //C相逆变电感电流
//        ui->RTDataModel_tableWidget->setItem(6, 3, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.PCSActivePower.u16Self * 0.1) +"kW"));              //逆变有功功率
//        ui->RTDataModel_tableWidget->setItem(7, 3, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.PCSReactivePower.u16Self * 0.1) +"kVar"));     //逆变无功功率
//        ui->RTDataModel_tableWidget->setItem(8, 3, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.PCSAparentPower.u16Self * 0.1) +"kVA"));      //逆变视在功率
////        ui->RTDataModel_tableWidget->setItem(9, 3, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.PCSFactor * 0.01)));                        //逆变功率因数

//        ui->RTDataModel_tableWidget->setItem(0, 5, new QTableWidgetItem(QString::number(((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.InputVolt.u16MOD1) * 0.1)+"V"));                 //电池电压
//        ui->RTDataModel_tableWidget->setItem(1, 5, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.InputCurr.u16MOD1 * 0.1)+"A"));          //电池电流
//        ui->RTDataModel_tableWidget->setItem(2, 5, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.InputPower.u16MOD1 * 0.1)+"kW"));                     //电池功率
//        ui->RTDataModel_tableWidget->setItem(3, 5, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.DCBus.u16Comb * 0.1) +"V"));                 //总母线电压
//        ui->RTDataModel_tableWidget->setItem(4, 5, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.u16IGBTTemp.u16MOD1) +"℃"));                //IGBT温度
////        ui->RTDataModel_tableWidget->setItem(5, 5, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.u16InductTemp) +"℃"));              //电感温度
//        ui->RTDataModel_tableWidget->setItem(5, 5, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.u16EnvTemp.u16Self) +"℃"));                         //环境温度
//        ui->RTDataModel_tableWidget->setItem(6, 5, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.OutFreq.u16Self * 0.01)+"Hz"));              //电网频率
//    }
//    else
//    {
//        ui->Converter_Tab->setItem(0, 1, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.PCSVoltage.u16Line_ab * 0.1)+"V"));          //PCS voltage(AB)
//        ui->Converter_Tab->setItem(1, 1, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.PCSVoltage.u16Line_bc * 0.1)+"V"));          //PCS voltage(BC)
//        ui->Converter_Tab->setItem(2, 1, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.PCSVoltage.u16Line_ca * 0.1)+"V"));          //PCS voltage(CA)
//        ui->Converter_Tab->setItem(3, 1, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.PCSCurrent.u16Phase_a * 0.1)+"A"));          //PCS current(A)
//        ui->Converter_Tab->setItem(4, 1, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.PCSCurrent.u16Phase_b * 0.1)+"A"));          //PCS current(B)
//        ui->Converter_Tab->setItem(5, 1, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.PCSCurrent.u16Phase_c * 0.1)+"A"));          //PCS current(C)
//        ui->Converter_Tab->setItem(6, 1, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.PCSActivePower.u16Self * 0.1)+"kW"));        //PCS active power
//        ui->Converter_Tab->setItem(7, 1, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.PCSReactivePower.u16Self * 0.1)+"kVar"));      //PCS reactive power
//        ui->Converter_Tab->setItem(8, 1, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.PCSAparentPower.u16Self * 0.1)+"kVA"));      //PCS apparent power
//    //    ui->Converter_Tab->setItem(9, 1, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.u16PCSFrequency * 0.01)+"Hz"));               //PCS frequency
//        ui->Converter_Tab->setItem(9, 1, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.PCSFactor.u16Self * 0.01)));                  //PCS power factor

//        ui->Converter_Tab->setItem(0, 3, new QTableWidgetItem(QString::number(((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.InputVolt.u16MOD1) * 0.1)+"V"));                 //Battery voltage
//        ui->Converter_Tab->setItem(1, 3, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.InputCurr.u16MOD1 * 0.1)+"A"));                 //Battery current
//        ui->Converter_Tab->setItem(2, 3, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.InputPower.u16MOD1 * 0.1)+"kW"));               //Battery power
//        ui->Converter_Tab->setItem(3, 3, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.DCBus.u16Comb * 0.1)+"V"));                  //Bus voltage
//        ui->Converter_Tab->setItem(4, 3, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.u16IGBTTemp.u16MOD1)+"℃"));           //IGBT temperature
////        ui->Converter_Tab->setItem(5, 3, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.u16InductTemp)+"℃"));         //Inductunce temperature
////        ui->Converter_Tab->setItem(6, 3, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.u16DiodeTemp)+"℃"));          //Diode temperature
//        ui->Converter_Tab->setItem(5, 3, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.u16EnvTemp.u16Self)+"℃"));                    //Environment temperature

//        ui->Grid_Tab->setItem(0, 1, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.GridVolt.u16Line_ab * 0.1)+"V"));          //Gird voltage(AB)
//        ui->Grid_Tab->setItem(1, 1, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.GridVolt.u16Line_bc * 0.1)+"V"));          //Gird voltage(BC)
//        ui->Grid_Tab->setItem(2, 1, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.GridVolt.u16Line_ca * 0.1)+"V"));          //Gird voltage(CA)
//        ui->Grid_Tab->setItem(3, 1, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.GridCurr.u16Phase_a * 0.1)+"A"));          //Gird current(A)
//        ui->Grid_Tab->setItem(4, 1, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.GridCurr.u16Phase_b * 0.1)+"A"));          //Gird current(B)
//        ui->Grid_Tab->setItem(5, 1, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.GridCurr.u16Phase_c * 0.1)+"A"));          //Gird current(C)
//        ui->Grid_Tab->setItem(6, 1, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.GridActPwr.u16Self * 0.1)+"kW"));               //Gird active power
//        ui->Grid_Tab->setItem(7, 1, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.GridReactPwr.u16Self * 0.1)+"kVar"));          //Gird reactive power
//        ui->Grid_Tab->setItem(8, 1, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.GridApparentPwr.u16Self * 0.1)+"kVA"));               //Gird power factor
//        ui->Grid_Tab->setItem(9, 1, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.OutFreq.u16Self * 0.01)+"Hz"));                 //Gird frequency
//        ui->Grid_Tab->setItem(10, 1, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.GridFactor.u16Self * 0.01)));               //Gird power factor


//        ui->Load_Tab->setItem(0, 1, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.LoadVoltage.u16Line_ab * 0.1)+"V"));          //Load voltage(AB)
//        ui->Load_Tab->setItem(1, 1, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.LoadVoltage.u16Line_bc * 0.1)+"V"));          //Load voltage(BC)
//        ui->Load_Tab->setItem(2, 1, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.LoadVoltage.u16Line_ca * 0.1)+"V"));          //Load voltage(CA)
//        ui->Load_Tab->setItem(3, 1, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.LoadCurrent.u16Phase_a * 0.1)+"A"));          //Load current(A)
//        ui->Load_Tab->setItem(4, 1, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.LoadCurrent.u16Phase_b * 0.1)+"A"));          //Load current(B)
//        ui->Load_Tab->setItem(5, 1, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.LoadCurrent.u16Phase_c * 0.1)+"A"));          //Load current(C)
//        ui->Load_Tab->setItem(6, 1, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.LoadActivepower.u16Self * 0.1)+"kW"));        //Load active power
//        ui->Load_Tab->setItem(7, 1, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.LoadReactivepower.u16Self * 0.1)+"kVar"));      //Load reactive power
//        ui->Load_Tab->setItem(8, 1, new QTableWidgetItem(QString::number((INT16)m_ptModInfoEntry->InvInfo.AnlogInfo.LoadAparentpower.u16Self * 0.1)+"kVA"));       //Load apparent power
//        ui->Load_Tab->setItem(9, 1, new QTableWidgetItem(QString::number(m_ptModInfoEntry->InvInfo.AnlogInfo.LoadFactor.u16Self * 0.01)));             //Load power factor

    //    }
}
/******************************************************************************
 * 实时数据——状态量
 *
 *
 *
 *
 *
 * ***************************************************************************/
void MEGAWin::RTData_Status()
{
    ui->RTState_MEGA_Tab->clearContents();//防止内存泄漏
    ModuleState_Tab();
//    if(m_DspSetData.u16UpsType != Machine_MEGA_TS)
//    {
//        //直流输入空开1状态  直流输入空开2状态 直流接触状态 输出接触器状态 输出空开状态 旁路接触器状态 旁路空开状态
//        if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucDCBreaker1 == 0xE0)//DC Breaker
//            ui->RTState_MEGA_Tab->setItem(0, 1, new QTableWidgetItem(QString(tr("Break"))));
//        else
//            ui->RTState_MEGA_Tab->setItem(0, 1, new QTableWidgetItem(QString(tr("Close"))));

//        if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucDCKM == 0xE0)//DC KM
//            ui->RTState_MEGA_Tab->setItem(1, 1, new QTableWidgetItem(QString(tr("Break"))));
//        else //if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucPVbrk == 0xE1)
//            ui->RTState_MEGA_Tab->setItem(1, 1, new QTableWidgetItem(QString(tr("Close"))));

//        if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucGridKM == 0xE0)//Grid KM
//        {
//            ui->RTState_MEGA_Tab->setItem(2, 1, new QTableWidgetItem(QString(tr("Break"))));
//        }
//        else
//        {
////            if((localSoftstart != 0) || (remoteSoftstart != 0))
////            {
////                DIDO* IO = new DIDO();
////                IO->ControlDiDo(0, 0);
////                delete IO;
////                localSoftstart = 0;
////                remoteSoftstart = 0;
////            }
//            ui->RTState_MEGA_Tab->setItem(2, 1, new QTableWidgetItem(QString(tr("Close"))));
//        }


//        if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucGridBrk == 0xE0)//Grid Breaker
//        {
//            ui->RTState_MEGA_Tab->setItem(3, 1, new QTableWidgetItem(QString(tr("Break"))));
//        }
//        else
//        {
//            ui->RTState_MEGA_Tab->setItem(3, 1, new QTableWidgetItem(QString(tr("Close"))));
//        }

//        if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucMaintenanceBypassBrk == 0xE0)//
//        {
//            ui->RTState_MEGA_Tab->setItem(4, 1, new QTableWidgetItem(QString(tr("Break"))));
//        }
//        else
//        {
//            ui->RTState_MEGA_Tab->setItem(4, 1, new QTableWidgetItem(QString(tr("Close"))));
//        }

//        //逆变器开机容许 直流软启动状态 逆变器状态 无功调节方式 休眠模式 紧急关机提示
//        if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucStartupEna == 0xE0)//逆变器开机容许 0:不允许  E1:允许
//            ui->RTState_MEGA_Tab->setItem(0, 3, new QTableWidgetItem(QString(tr("Disable"))));
//        else //if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucStartupEna == 0xE1)
//            ui->RTState_MEGA_Tab->setItem(0, 3, new QTableWidgetItem(QString(tr("Enable"))));

//        if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucDCSoftup == 0xE1)//直流软启动状态 E1: 软启中 E2:软启完成  else: 未启动
//        {
//            ui->RTState_MEGA_Tab->setItem(1, 3, new QTableWidgetItem(QString(tr("Soft starting"))));
//        }
//        else if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucDCSoftup == 0xE2)
//        {
//            ui->RTState_MEGA_Tab->setItem(1, 3, new QTableWidgetItem(QString(tr("complete"))));
//        }
//        else
//        {
//            ui->RTState_MEGA_Tab->setItem(1, 3, new QTableWidgetItem(QString(tr("Not starting"))));
//        }
//        if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucState2 == 0xE0)
//        {
//            if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucState == 0xE0)//逆变器状态E0:关闭 E1:软启动 E2:并网充电 E3：并网放电 E4:离网放电 E5：降额并网
//            {
//                ui->RTState_MEGA_Tab->setItem(2, 3, new QTableWidgetItem(QString(tr("Converter turn off"))));
//                ui->Inverter_state_lab->setText(combox_MachineNumber->currentText() + " " + QString(tr("Converter turn off")));
//                m_ptMonInfoEntry->PCSStatus.PCSStatus = PCS_OFF;
//            }
//            else if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucState == 0xE1)
//            {
//                ui->RTState_MEGA_Tab->setItem(2, 3, new QTableWidgetItem(QString(tr("Soft start"))));
//                ui->Inverter_state_lab->setText(combox_MachineNumber->currentText() + " " + QString(tr("Converter Soft start")));
//                m_ptMonInfoEntry->PCSStatus.PCSStatus = PCS_ON;
//            }
//            else if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucState == 0xE2)
//            {
//                ui->RTState_MEGA_Tab->setItem(2, 3, new QTableWidgetItem(QString(tr("Grid-ON Charge"))));
//                ui->Inverter_state_lab->setText(combox_MachineNumber->currentText() + " " + QString(tr("Converter Grid-ON Charge")));
//                m_ptMonInfoEntry->PCSStatus.PCSStatus = PCS_ON;
//            }
//            else if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucState == 0xE3)
//            {
//                ui->RTState_MEGA_Tab->setItem(2, 3, new QTableWidgetItem(QString(tr("Grid-ON Discharge"))));
//                ui->Inverter_state_lab->setText(combox_MachineNumber->currentText() + " " + QString(tr("Converter Grid-ON Discharge")));
//                m_ptMonInfoEntry->PCSStatus.PCSStatus = PCS_ON;
//            }
//            else if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucState == 0xE4)
//            {
//                ui->RTState_MEGA_Tab->setItem(2, 3, new QTableWidgetItem(QString(tr("Grid-OFF Discharge"))));
//                ui->Inverter_state_lab->setText(combox_MachineNumber->currentText() + " " + QString(tr("Converter Grid-OFF Discharge")));
//                m_ptMonInfoEntry->PCSStatus.PCSStatus = PCS_ON;
//            }
//            else if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucState == 0xE5)
//            {
//                ui->RTState_MEGA_Tab->setItem(2, 3, new QTableWidgetItem(QString(tr("Drop and Connected"))));
//                ui->Inverter_state_lab->setText(combox_MachineNumber->currentText() + " " + QString(tr("Converter Drop and Connected")));
//                m_ptMonInfoEntry->PCSStatus.PCSStatus = PCS_ON;
//            }
//            else if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucState == 0xE6)
//            {
//                ui->RTState_MEGA_Tab->setItem(2, 3, new QTableWidgetItem(QString(tr("Standby"))));
//                ui->Inverter_state_lab->setText(combox_MachineNumber->currentText() + " " + QString(tr("Converter standby")));
//                m_ptMonInfoEntry->PCSStatus.PCSStatus = PCS_STANDBY;
//            }
//            else if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucState == 0xE7)
//            {
//                ui->RTState_MEGA_Tab->setItem(2, 3, new QTableWidgetItem(QString(tr("Grid-OFF Charge"))));
//                ui->Inverter_state_lab->setText(combox_MachineNumber->currentText() + " " + QString(tr("Converter Grid-OFF Charge")));
//                m_ptMonInfoEntry->PCSStatus.PCSStatus = PCS_ON;
//            }
//            else
//            {
//                ui->RTState_MEGA_Tab->setItem(2, 3, new QTableWidgetItem(QString(tr("OFF"))));
//                ui->Inverter_state_lab->setText(combox_MachineNumber->currentText() + " " + QString(tr("Converter turn off")));
//                m_ptMonInfoEntry->PCSStatus.PCSStatus = PCS_OFF;
//            }
//        }
//        else
//        {
//            if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucState2 == 0xE1)
//            {
//                ui->RTState_MEGA_Tab->setItem(2, 3, new QTableWidgetItem(QString(tr("Constant voltage discharge"))));
//                ui->Inverter_state_lab->setText(combox_MachineNumber->currentText() + " " + QString(tr("Converter constant voltage discharge")));
//                m_ptMonInfoEntry->PCSStatus.PCSStatus = PCS_ON;
//            }
//            else if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucState2 == 0xE2)
//            {
//                ui->RTState_MEGA_Tab->setItem(2, 3, new QTableWidgetItem(QString(tr("Constant voltage charge"))));
//                ui->Inverter_state_lab->setText(combox_MachineNumber->currentText() + " " + QString(tr("Converter constant voltage charge")));
//                m_ptMonInfoEntry->PCSStatus.PCSStatus = PCS_ON;
//            }
//            else
//            {

//            }

//        }
//        if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucQMODE == 0xE0)//无功调节方式	E0:无 E1:功率因数调节 E2:无功功率调节 E3:夜间SVG模式
//            ui->RTState_MEGA_Tab->setItem(3, 3, new QTableWidgetItem(QString(tr("Disable"))));
//        else if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucQMODE == 0xE1)
//            ui->RTState_MEGA_Tab->setItem(3, 3, new QTableWidgetItem(QString(tr("Pf regulation"))));
//        else if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucQMODE == 0xE2)
//            ui->RTState_MEGA_Tab->setItem(3, 3, new QTableWidgetItem(QString(tr("Q regulation"))));
//        else //if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucQMODE == 0xE4)
//            ui->RTState_MEGA_Tab->setItem(3, 3, new QTableWidgetItem(QString(tr("SVG"))));

//        if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucSleep == 0xE0)//休眠	E0:未休眠 	E1:休眠
//            ui->RTState_MEGA_Tab->setItem(4, 3, new QTableWidgetItem(QString(tr("No dromancy"))));
//        else //if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucSleep == 0xE1)
//            ui->RTState_MEGA_Tab->setItem(4, 3, new QTableWidgetItem(QString(tr("Dromant"))));

//        if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucLVRTEvent == 0xE0)//低电压穿越提示  E0:无  E1:有
//            ui->RTState_MEGA_Tab->setItem(5, 3, new QTableWidgetItem(QString(tr("Non"))));
//        else //if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucLVRTEvent == 0xE1)
//            ui->RTState_MEGA_Tab->setItem(5, 3, new QTableWidgetItem(QString(tr("LVRT"))));


//        if(m_ptMonInfoEntry->tMonSynthState.Word2_U.tWord2Bits.bDO1 == DryEnable)
//            ui->RTState_MEGA_Tab->setItem(0, 5, new QTableWidgetItem(QString(tr("Enable"))));
//        else
//            ui->RTState_MEGA_Tab->setItem(0, 5, new QTableWidgetItem(QString(tr("Disable"))));
//        if(m_ptMonInfoEntry->tMonSynthState.Word2_U.tWord2Bits.bDO2 == DryEnable)
//            ui->RTState_MEGA_Tab->setItem(1, 5, new QTableWidgetItem(QString(tr("Enable"))));
//        else
//            ui->RTState_MEGA_Tab->setItem(1, 5, new QTableWidgetItem(QString(tr("Disable"))));
//        if(m_ptMonInfoEntry->tMonSynthState.Word2_U.tWord2Bits.bDO3 == DryEnable)
//            ui->RTState_MEGA_Tab->setItem(2, 5, new QTableWidgetItem(QString(tr("Enable"))));
//        else
//            ui->RTState_MEGA_Tab->setItem(2, 5, new QTableWidgetItem(QString(tr("Disable"))));
//        if(m_ptMonInfoEntry->tMonSynthState.Word2_U.tWord2Bits.bDI1 == DryEnable)
//            ui->RTState_MEGA_Tab->setItem(3, 5, new QTableWidgetItem(QString(tr("Enable"))));
//        else
//            ui->RTState_MEGA_Tab->setItem(3, 5, new QTableWidgetItem(QString(tr("Disable"))));
//        if(m_ptMonInfoEntry->tMonSynthState.Word2_U.tWord2Bits.bDI2 == DryEnable)
//            ui->RTState_MEGA_Tab->setItem(4, 5, new QTableWidgetItem(QString(tr("Enable"))));
//        else
//            ui->RTState_MEGA_Tab->setItem(4, 5, new QTableWidgetItem(QString(tr("Disable"))));
//        if(m_ptMonInfoEntry->tMonSynthState.Word2_U.tWord2Bits.bDI3 == DryEnable)
//            ui->RTState_MEGA_Tab->setItem(5, 5, new QTableWidgetItem(QString(tr("Enable"))));
//        else
//            ui->RTState_MEGA_Tab->setItem(5, 5, new QTableWidgetItem(QString(tr("Disable"))));
//        if(m_ptMonInfoEntry->tMonSynthState.Word2_U.tWord2Bits.bDI4 == DryEnable)
//            ui->RTState_MEGA_Tab->setItem(6, 5, new QTableWidgetItem(QString(tr("Enable"))));
//        else
//            ui->RTState_MEGA_Tab->setItem(6, 5, new QTableWidgetItem(QString(tr("Disable"))));
//        if(m_ptMonInfoEntry->tMonSynthState.Word2_U.tWord2Bits.bDI5 == DryEnable)
//            ui->RTState_MEGA_Tab->setItem(7, 5, new QTableWidgetItem(QString(tr("Enable"))));
//        else
//            ui->RTState_MEGA_Tab->setItem(7, 5, new QTableWidgetItem(QString(tr("Disable"))));
//        if(m_ptMonInfoEntry->tMonSynthState.Word2_U.tWord2Bits.bDI6 == DryEnable)
//            ui->RTState_MEGA_Tab->setItem(8, 5, new QTableWidgetItem(QString(tr("Enable"))));
//        else
//            ui->RTState_MEGA_Tab->setItem(8, 5, new QTableWidgetItem(QString(tr("Disable"))));
//    }
//    else
//    {
//        //直流输入空开1状态  直流输入空开2状态 直流接触状态 输出接触器状态 输出空开状态 旁路接触器状态 旁路空开状态
//        if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucDCBreaker1 == 0xE0)//DC breaker
//        {
//            ui->RTState_Bypass_Tab->setItem(0, 1, new QTableWidgetItem(QString(tr("Break"))));
//        }
//        else
//        {
//            ui->RTState_Bypass_Tab->setItem(0, 1, new QTableWidgetItem(QString(tr("Close"))));
//        }

//        if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucDCKM == 0xE0)//DC KM
//        {
//            ui->RTState_Bypass_Tab->setItem(1, 1, new QTableWidgetItem(QString(tr("Break"))));
//        }
//        else
//        {
//            ui->RTState_Bypass_Tab->setItem(1, 1,new QTableWidgetItem(QString(tr("Close"))));
//        }

//        if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucACOutKM == 0xE0)//Out KM
//        {
//            ui->RTState_Bypass_Tab->setItem(2, 1, new QTableWidgetItem(QString(tr("Break"))));
//        }
//        else
//        {
//            ui->RTState_Bypass_Tab->setItem(2, 1, new QTableWidgetItem(QString(tr("Close"))));
//        }

//        if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucACOutBrk == 0xE0)// Out Breaker
//        {
//            ui->RTState_Bypass_Tab->setItem(3, 1, new QTableWidgetItem(QString(tr("Break"))));
//        }
//        else
//        {
//            ui->RTState_Bypass_Tab->setItem(3, 1, new QTableWidgetItem(QString(tr("Close"))));
//        }

//        if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucGridKM == 0xE0)//Grid KM
//        {
//            ui->RTState_Bypass_Tab->setItem(4, 1, new QTableWidgetItem(QString(tr("Break"))));
//        }
//        else //if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucOutBrkState == 0xE1)
//        {
//            ui->RTState_Bypass_Tab->setItem(4, 1, new QTableWidgetItem(QString(tr("Close"))));
//        }

//        if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucGridBrk == 0xE0)// Grid Breaker
//        {
//            ui->RTState_Bypass_Tab->setItem(5, 1, new QTableWidgetItem(QString(tr("Break"))));
//        }
//        else
//        {
//            ui->RTState_Bypass_Tab->setItem(5, 1, new QTableWidgetItem(QString(tr("Close"))));
//        }

//        if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucMaintenanceBypassBrk == 0xE0)//
//        {
//            ui->RTState_Bypass_Tab->setItem(6, 1, new QTableWidgetItem(QString(tr("Break"))));
//        }
//        else
//        {
//            ui->RTState_Bypass_Tab->setItem(6, 1, new QTableWidgetItem(QString(tr("Close"))));
//        }



//        //逆变器开机容许 直流软启动状态 逆变器状态 无功调节方式 休眠模式 紧急关机提示

//        if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucStartupEna == 0xE0)//逆变器开机容许 0:不允许  E1:允许
//        {
//            ui->RTState_Bypass_Tab->setItem(0, 3,new QTableWidgetItem(QString(tr("Disable"))));
//        }
//        else //if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucStartupEna == 0xE1)
//        {
//            ui->RTState_Bypass_Tab->setItem(0, 3, new QTableWidgetItem(QString(tr("Enable"))));
//        }

//        if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucDCSoftup == 0xE1)//直流软启动状态 E1: 软启中 E2:软启完成  else: 未启动
//        {
//            ui->RTState_Bypass_Tab->setItem(1, 3, new QTableWidgetItem(QString(tr("Soft starting"))));
//        }
//        else if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucDCSoftup == 0xE2)
//        {
//            ui->RTState_Bypass_Tab->setItem(1, 3, new QTableWidgetItem(QString(tr("complete"))));
//        }
//        else
//            ui->RTState_Bypass_Tab->setItem(1, 3, new QTableWidgetItem(QString(tr("Not starting"))));

//        if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucState2 == 0xE0)
//        {
//            if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucState == 0xE0)//逆变器状态E0:关闭 E1:软启动 E2:并网充电 E3：并网放电 E4:离网放电 E5：降额并网
//            {
//                ui->RTState_Bypass_Tab->setItem(2, 3, new QTableWidgetItem(QString(tr("OFF"))));
//                ui->Inverter_state_lab->setText(combox_MachineNumber->currentText() + " " + QString(tr("Converter turn off")));
//                m_ptMonInfoEntry->PCSStatus.PCSStatus = PCS_OFF;
//            }
//            else if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucState == 0xE1)
//            {
//                ui->RTState_Bypass_Tab->setItem(2, 3, new QTableWidgetItem(QString(tr("Soft start"))));
//                ui->Inverter_state_lab->setText(combox_MachineNumber->currentText() + " " + QString(tr("Converter Soft start")));
//                m_ptMonInfoEntry->PCSStatus.PCSStatus = PCS_ON;
//            }
//            else if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucState == 0xE2)
//            {
//                ui->RTState_Bypass_Tab->setItem(2, 3, new QTableWidgetItem(QString(tr("Grid-ON Charge"))));
//                ui->Inverter_state_lab->setText(combox_MachineNumber->currentText() + QString(tr("Converter Grid-ON Charge")));
//                m_ptMonInfoEntry->PCSStatus.PCSStatus = PCS_ON;
//            }
//            else if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucState == 0xE3)
//            {
//                ui->RTState_Bypass_Tab->setItem(2, 3, new QTableWidgetItem(QString(tr("Grid-ON Discharge"))));
//                ui->Inverter_state_lab->setText(combox_MachineNumber->currentText() + " " + QString(tr("Converter Grid-ON Discharge")));
//                m_ptMonInfoEntry->PCSStatus.PCSStatus = PCS_ON;
//            }
//            else if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucState == 0xE4)
//            {
//                ui->RTState_Bypass_Tab->setItem(2, 3, new QTableWidgetItem(QString(tr("Grid-OFF Discharge"))));
//                ui->Inverter_state_lab->setText(combox_MachineNumber->currentText() + " " + QString(tr("Converter Grid-OFF Discharge")));
//                m_ptMonInfoEntry->PCSStatus.PCSStatus = PCS_ON;
//            }
//            else if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucState == 0xE5)
//            {
//                ui->RTState_Bypass_Tab->setItem(2, 3, new QTableWidgetItem(QString(tr("Drop and Connected"))));
//                ui->Inverter_state_lab->setText(combox_MachineNumber->currentText() + " " + QString(tr("Converter Drop and Connected")));
//                m_ptMonInfoEntry->PCSStatus.PCSStatus = PCS_ON;
//            }
//            else if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucState == 0xE6)
//            {
//                ui->RTState_Bypass_Tab->setItem(2, 3, new QTableWidgetItem(QString(tr("Standby"))));
//                ui->Inverter_state_lab->setText(combox_MachineNumber->currentText() + " " + QString(tr("Converter standby")));
//                m_ptMonInfoEntry->PCSStatus.PCSStatus = PCS_STANDBY;
//            }
//            else if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucState == 0xE7)
//            {
//                ui->RTState_Bypass_Tab->setItem(2, 3, new QTableWidgetItem(QString(tr("Grid-OFF Charge"))));
//                ui->Inverter_state_lab->setText(combox_MachineNumber->currentText() + " " + QString(tr("Converter Grid-OFF Charge")));
//                m_ptMonInfoEntry->PCSStatus.PCSStatus = PCS_ON;
//            }
//            else
//            {
//                ui->RTState_Bypass_Tab->setItem(2, 3, new QTableWidgetItem(QString(tr("OFF"))));
//                ui->Inverter_state_lab->setText(combox_MachineNumber->currentText() + " " + QString(tr("Converter turn off")));
//                m_ptMonInfoEntry->PCSStatus.PCSStatus = PCS_OFF;
//            }
//        }
//        else
//        {
//            if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucState2 == 0xE1)
//            {
//                ui->RTState_MEGA_Tab->setItem(2, 3, new QTableWidgetItem(QString(tr("Constant voltage discharge"))));
//                ui->Inverter_state_lab->setText(combox_MachineNumber->currentText() + " " + QString(tr("Converter constant voltage discharge")));
//                m_ptMonInfoEntry->PCSStatus.PCSStatus = PCS_ON;
//            }
//            else if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucState2 == 0xE2)
//            {
//                ui->RTState_MEGA_Tab->setItem(2, 3, new QTableWidgetItem(QString(tr("Constant voltage charge"))));
//                ui->Inverter_state_lab->setText(combox_MachineNumber->currentText() + " " + QString(tr("Converter constant voltage charge")));
//                m_ptMonInfoEntry->PCSStatus.PCSStatus = PCS_ON;
//            }
//            else
//            {

//            }
//        }
//        if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucQMODE == 0xE0)//无功调节方式	E0:无 E1:功率因数调节 E2:无功功率调节 E3:夜间SVG模式
//        {
//            ui->RTState_Bypass_Tab->setItem(3, 3, new QTableWidgetItem(QString(tr("Disable"))));
//        }
//        else if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucQMODE == 0xE1)
//        {
//            ui->RTState_Bypass_Tab->setItem(3, 3, new QTableWidgetItem(QString(tr("Pf regulation"))));
//        }
//        else if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucQMODE == 0xE2)
//        {
//            ui->RTState_Bypass_Tab->setItem(3, 3, new QTableWidgetItem(QString(tr("Q regulation"))));
//        }
//        else //if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucQMODE == 0xE3)
//        {
//            ui->RTState_Bypass_Tab->setItem(3, 3, new QTableWidgetItem(QString(tr("SVG"))));
//        }

//        if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucSleep == 0xE0)//休眠	E0:未休眠 	E1:休眠
//        {
//            ui->RTState_Bypass_Tab->setItem(4, 3, new QTableWidgetItem(QString(tr("No dromancy"))));
//        }
//        else if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucSleep == 0xE1)
//        {
//            ui->RTState_Bypass_Tab->setItem(4, 3, new QTableWidgetItem(QString(tr("Dromant"))));
//        }

//        if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucLVRTEvent == 0xE0)//低电压穿越提示  E0:无  E1:有
//        {
//            ui->RTState_Bypass_Tab->setItem(5, 3, new QTableWidgetItem(QString(tr("Non"))));
//        }
//        else //if(m_ptModSynthesisEntry->InvInfo.SwInfo.ucLVRTEvent == 0xE1)
//        {
//            ui->RTState_Bypass_Tab->setItem(5, 3, new QTableWidgetItem(QString(tr("LVRT"))));
//        }

//        if(m_ptMonInfoEntry->tMonSynthState.Word2_U.tWord2Bits.bDO1 == DryEnable)
//            ui->RTState_Bypass_Tab->setItem(0, 5, new QTableWidgetItem(QString(tr("Enable"))));
//        else
//            ui->RTState_Bypass_Tab->setItem(0, 5, new QTableWidgetItem(QString(tr("Disable"))));
//        if(m_ptMonInfoEntry->tMonSynthState.Word2_U.tWord2Bits.bDO2 == DryEnable)
//            ui->RTState_Bypass_Tab->setItem(1, 5, new QTableWidgetItem(QString(tr("Enable"))));
//        else
//            ui->RTState_Bypass_Tab->setItem(1, 5, new QTableWidgetItem(QString(tr("Disable"))));
//        if(m_ptMonInfoEntry->tMonSynthState.Word2_U.tWord2Bits.bDO3 == DryEnable)
//            ui->RTState_Bypass_Tab->setItem(2, 5, new QTableWidgetItem(QString(tr("Enable"))));
//        else
//            ui->RTState_Bypass_Tab->setItem(2, 5, new QTableWidgetItem(QString(tr("Disable"))));
//        if(m_ptMonInfoEntry->tMonSynthState.Word2_U.tWord2Bits.bDI1 == DryEnable)
//            ui->RTState_Bypass_Tab->setItem(3, 5, new QTableWidgetItem(QString(tr("Enable"))));
//        else
//            ui->RTState_Bypass_Tab->setItem(3, 5, new QTableWidgetItem(QString(tr("Disable"))));
//        if(m_ptMonInfoEntry->tMonSynthState.Word2_U.tWord2Bits.bDI2 == DryEnable)
//            ui->RTState_Bypass_Tab->setItem(4, 5, new QTableWidgetItem(QString(tr("Enable"))));
//        else
//            ui->RTState_Bypass_Tab->setItem(4, 5, new QTableWidgetItem(QString(tr("Disable"))));
//        if(m_ptMonInfoEntry->tMonSynthState.Word2_U.tWord2Bits.bDI3 == DryEnable)
//            ui->RTState_Bypass_Tab->setItem(5, 5, new QTableWidgetItem(QString(tr("Enable"))));
//        else
//            ui->RTState_Bypass_Tab->setItem(5, 5, new QTableWidgetItem(QString(tr("Disable"))));
//        if(m_ptMonInfoEntry->tMonSynthState.Word2_U.tWord2Bits.bDI4 == DryEnable)
//            ui->RTState_Bypass_Tab->setItem(6, 5, new QTableWidgetItem(QString(tr("Enable"))));
//        else
//            ui->RTState_Bypass_Tab->setItem(6, 5, new QTableWidgetItem(QString(tr("Disable"))));
//        if(m_ptMonInfoEntry->tMonSynthState.Word2_U.tWord2Bits.bDI5 == DryEnable)
//            ui->RTState_Bypass_Tab->setItem(7, 5, new QTableWidgetItem(QString(tr("Enable"))));
//        else
//            ui->RTState_Bypass_Tab->setItem(7, 5, new QTableWidgetItem(QString(tr("Disable"))));
//        if(m_ptMonInfoEntry->tMonSynthState.Word2_U.tWord2Bits.bDI6 == DryEnable)
//            ui->RTState_Bypass_Tab->setItem(8, 5, new QTableWidgetItem(QString(tr("Enable"))));
//        else
//            ui->RTState_Bypass_Tab->setItem(8, 5, new QTableWidgetItem(QString(tr("Disable"))));
//    }

}
/*************************************************************************
 * 实时状态数据更新函数
 *
 *
 *
 *
 *
 ************************************************************************/
void MEGAWin::RTDataDisplay()
{
    //当前页处于主页面或者运行状态页面，且实时界面处于实时数据界面的时候，刷新数据
//    if((m_UIPage.m_first == HOST_PAGE) || (m_UIPage.m_second == RTAnaloge_PAGE) || (m_UIPage.m_first == HOST_BYPASS_PAGE))
//    {
        RTData_Anologe();
        //    }
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

//    QChar data[12];
//    QChar SNdata[12];
    QString STR_PRO;
    QString STR_DSP;
    QString STR_CPLD;
    QString SNCODE;

//    for(int i = 0; i < 12; i++)
//    {
//        data[i] = m_ptModSynthesisEntry->InvInfo.ucSysCANVersion[i];
//        STR_PRO.append(data[i]);
//        data[i] = m_ptModSynthesisEntry->InvInfo.ucDspFWVersion[i];
//        STR_DSP.append(data[i]);
//        data[i] = m_ptModSynthesisEntry->InvInfo.ucCpldVersion[i];
//        STR_CPLD.append(data[i]);
//        SNdata[i] = m_SysBasicSetData.ucUpsSN[i];
//        SNCODE.append(SNdata[i]);
//    }

////    ui->EquipmentInfor_tableWidget->setItem(0, 1, new QTableWidgetItem(QString::fromLocal8Bit((const char*)m_SysBasicSetData.ucUpsName, 10)));
////    ui->EquipmentInfor_tableWidget->item(0, 1)->setTextAlignment(Qt::AlignCenter);
//    if(m_SysMonSetData.u16LOGO == LOGO_MEGA)
//    {
//        ui->EquipmentInfor_tableWidget->setItem(0, 1, new QTableWidgetItem(QString(tr("MEGAREVO"))));
//        ui->EquipmentInfor_tableWidget->item(0, 1)->setTextAlignment(Qt::AlignCenter);
//    }
//    else
    {
        ui->EquipmentInfor_tableWidget->setItem(0, 1, new QTableWidgetItem(QString(tr("PCS"))));
        ui->EquipmentInfor_tableWidget->item(0, 1)->setTextAlignment(Qt::AlignCenter);
    }


    ui->EquipmentInfor_tableWidget->setItem(1, 1, new QTableWidgetItem("V103B500D004"));//QString::fromLocal8Bit((const char*)m_SysBasicSetData.ucMonitorVersion, 16)
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
////            ui->stackedWidget->setCurrentWidget(ui->System_page);
////            ui->System_tabWidget->setCurrentWidget(ui->ParameterSet_page);

//        combox_bps1_str = combox_bps1->currentText();
//        combox_bps2_str = combox_bps2->currentText();
//        combox_Can1_str = combox_Can1->currentText();
//        combox_Can2_str = combox_Can2->currentText();
//        combox_GFU_str = combox_GFU->currentText();
//        combox_GFD_str = combox_GFD->currentText();
//        combox_VPU_str = combox_VPU->currentText();
//        combox_VPD_str = combox_VPD->currentText();
//        combox_RUN_str = combox_RUN->currentText();
//        combox_BMSCommtype_str = combox_BMSCommtype->currentText();
//        combox_machinetype_str = combox_machinetype->currentText();
//        combox_batterytype_str = combox_batterytype->currentText();

//        combox_bps1_index = combox_bps1->currentIndex();
//        combox_bps2_index = combox_bps2->currentIndex();
//        combox_Can1_index = combox_Can1->currentIndex();
//        combox_Can2_index = combox_Can2->currentIndex();
//        combox_GFU_index = combox_GFU->currentIndex();
//        combox_GFD_index = combox_GFD->currentIndex();
//        combox_VPU_index = combox_VPU->currentIndex();
//        combox_VPD_index = combox_VPD->currentIndex();
//        combox_RUN_index = combox_RUN->currentIndex();

//        active_power_str = Grid_Power_btn->text(); //有功功率百分比
//        combox_ui_ChargeDischar_str = combox_ui_ChargeDischar->currentText();
//        combox_ui_OnOffGrid_str = combox_ui_OnOff_Grid->currentText();
//        combox_ui_ChargeDischar_index = combox_ui_ChargeDischar->currentIndex();
//        combox_ui_OnOffGrid_index = combox_ui_OnOff_Grid->currentIndex();

//        combox_BMSCommtype_index = combox_BMSCommtype->currentIndex();
//        combox_machinetype_index = combox_machinetype->currentIndex();
//        combox_batterytype_index = combox_batterytype->currentIndex();
//        ModuleNumber_str = Number_btn->text();
//        PwrChangeRateLmt_str = PwrChangeRateLmt->text();
//        address_str = address_btn->text();
}
/**************************************************
初始化变量（system_Page）
**************************************************/
void MEGAWin::VariableInit()
{
//    Sclick = 0;
//    picture_fla_1 = 0;
//    USB_flag = 0;
//    umount_flag = 0;
//    root = USER;//0：超级权限 1：用户权限
//    report_flag = 0;
//    m_HistoryPage = 0;
//    Set_flag = false;

//    ui_Power_ctl << tr("Standby") << tr("CP_P") << tr("CP_N&P") << tr("CC") << tr("CV");
//    ui_SysVltInv << "1 : 1" << "60:400" << "100:400" << "200:400" << "270:400" << "315:400"<< "315:480";
//    ui_RunMod <<  tr("Normal mode") << tr("Enable");
//    ui_GridMode << tr("Countercurrent") << tr("Non countercurrent");
//    ui_EnableLVRT << tr("prohibit") << tr("Enable") ;
//    ui_EMSCommType << tr("RS485") << tr("CAN") << tr("Ethernet")<< tr("Non");

//    ui_CapType <<"30" << "50" << "100" << "150"<< "200"<< "250" << "500" << "630";
////    ui_OutFreq << tr("50Hz") << tr("60Hz");
//    ui_QPowerMode << tr("Non adjustable") << tr("Pf") << tr("Q");

//    ui_ChargeDischar << tr("Charge") << tr("Discharge");
//    ui_OnOff_Grid << tr("Off") << tr("On") << tr("automatic");
//    combox_Battery << tr("Non") << tr("Lithium") << tr("LeadAcid");
//    if(m_SysMonSetData.u16LOGO == LOGO_MEGA)
//        combox_Machine << tr("MEGA ") << tr("MEGA -T") << tr("MEGA -TS") << tr("MEGA -TS-T");
//    else
//        combox_Machine << tr("PCS ") << tr("PCS -T") << tr("PCS -TS") << tr("PCS -TS-T");

//    combox_Control << tr("CAN") << tr("RS485") << tr("Ethernet") << tr("Non");
//    combox_Runmode << tr("Manual") << tr("Peak valley") << tr("UPS") << tr("Prevent countercurrnet");
//    combox_CM << tr("Local") << tr("Remote");
//    combox_Volt_down << "-10" << "-15" << "-20" << "-30";
//    combox_Volt_up << "+10" << "+15" << "+20" << "+30";
//    combox_limite_down  << "-0.5" << "-1" << "-2" << "-3";
//    combox_limite_up  << "0.2" << "0.5" << "1" << "3";
//    can_bps << "100" << "125" << "250" << "500" << "800";
//    combox_bps << "1200" << "2400" << "4800" << "9600" << "19200" << "38400";
//    combox_InsulationDetectionEN << tr("Disable") << tr("Enable");
//    comobx_Language <<tr("Chinese") << tr("English");
//    sounds_choice << tr("Allow") << tr("forbid");
//    combox_Para << tr("Disable") << tr("Enable");
//    combox_MNumber << tr("Master_00") << tr("Slave_01") << tr("Slave_02") << tr("Slave_03") << tr("Slave_04") << tr("Slave_05") << tr("Slave_06") << tr("Slave_07") << tr("Slave_08");
//    combox_NCNO << tr("N_O") << tr("N_C");
//    combox_Action << tr("Prompt") << tr("Standby") << tr("Shut down") << tr("Full standby") << tr("Empty standby") << tr("Failure standby") << tr("Grid signal") << tr("ATS signal");
//    combox_BMS_Action << tr("No action") << tr("Power down") << tr("Standby") << tr("Shut down");
//    combox_BMS_PROTOCOL_list << tr("Auto") << tr("MEGA")<< tr("LISHEN")<< tr("PENGHUI")<< tr("GAOTE")<< tr("XIENENG")<< tr("LANLI")<< tr("SHENLAN")<< tr("PAINENG")
//                        << tr("NINGDESHIDAI")<< tr("SUOYING")<< tr("XINGWANGDA")<< tr("KUBO")<< tr("GAOTE_V2") << tr("TOGOOD") << tr("GROUP_STANDARD")<< tr("WOBO")
//                        << tr("KGOOER")<< tr("LIDE") << tr("PAINENG_L") << tr("WEILAN") << tr("ALPHA") << tr("TUOPU")<< tr("JIEHUI")<< tr("JDI")<< tr("ECUBE");


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

    /*功能设置*/
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

    /*系统参数*/
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
                                   "电网扩容使能,可供选择为允许(Allow)、禁止(forbid)\nEnable the power network expansion. The options are Allow(Allow) and forbid(forbid).");
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

    /*外设*/
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

    DI_1_Action = new Specification(DI_1_Action_explain, ui->ExternalDevice_tW, 0, 1, \
                                   "Enable", "DI_1_Action", \
                                   "输入干接点1，发生NO关机时执行的动作,可选功能为提示、待机、关机、充满待机、放空待机、故障待机、电网信号\n");
    DI_1_Action->add_Specifition();
//    Specification *DI_1_Action;
//    Specification *DI_2_Action;
//    Specification *DI_3_Action;
//    Specification *DI_4_Action;
//    Specification *DI_5_Action;
//    Specification *DI_6_Action;
//    Specification *DO_1_Action;
//    Specification *DO_2_Action;
//    Specification *DO_3_Action;
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

//    connect(Constant_power_explain,SIGNAL(clicked(bool)), this, SLOT(Constant_power_explain_clicked()));//恒功率
//    connect(Phase_C_power_btn ,SIGNAL(clicked(bool)), this, SLOT(Constant_power_explain_clicked()));//C相功率
    connect(AdvancedSetup_btn,SIGNAL(clicked(bool)), this, SLOT(AdvancedSetup_btn_clicked()));//高级设置

    connect(ui->Bypass_Batt_btn, SIGNAL(clicked()), this, SLOT(on_Batt_btn_released()));    //主页电池按钮跳转电池信息
    connect(ui->Bypass_Running_btn, SIGNAL(clicked()), this, SLOT(on_Running_btn_clicked()));   //主页变流器按钮跳转变流器实时数据
    connect(ui->Bypass_Grid_btn, SIGNAL(clicked()), this, SLOT(on_Grid_clicked()));    //主页电网按钮跳转电网实时数据
    connect(ui->Bypass_Load_Btn, SIGNAL(clicked()), this, SLOT(on_Load_clicked()));    //主页负载按钮跳转负载实时数据

    //关联实时数据点击槽函数
//    connect(pButtonGroup, SIGNAL(buttonClicked(int)), this, SLOT(slot_btnGroupClicked(int)));
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


        //绘制button
        ToSetButton();


}
/******************************************************************************
 * 模块实时状态表初始化
 *
 *
 *
 *
 *
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
//        ui->RTState_Bypass_Tab->horizontalHeader()->setStretchLastSection(5);
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
/*        if(m_DspSetData.u16UpsType != Machine_MEGA_TS)
        {
            ui->stackedWidget->setCurrentWidget(ui->Host_Page);
            ui->RTD_PCS_StackedWidget->setCurrentWidget(ui->RTD_Bypass_N_page);
            ui->RTState_stackedWidget->setCurrentWidget(ui->RTState_Bypass_N_page);
            m_UIPage.m_first = HOST_PAGE;
        }
        else
        {*/
            ui->stackedWidget->setCurrentWidget(ui->Bypass_page);
            ui->RTD_PCS_StackedWidget->setCurrentWidget(ui->RTD_Bypass_Y_page);
            ui->RTState_stackedWidget->setCurrentWidget(ui->RTState_Bypass_Y_page);
//            m_UIPage.m_first = HOST_BYPASS_PAGE;
//        }

//        if(m_DspSetData.u16BatteryType == Battery_Li)
            ui->BAT_stackedWidget->setCurrentWidget(ui->BAT_Lithium_page);
/*        else if(m_DspSetData.u16BatteryType == Battery_lead)
            ui->BAT_stackedWidget->setCurrentWidget(ui->BAT_Lead_page);
        else
            ui->BAT_stackedWidget->setCurrentWidget(ui->BAT_No_page);


        m_UIPage.m_second = 0 + m_UIPage.m_first * 10;*/
        break;
    case RTDATAPAGE:

//        if(m_DspSetData.u16UpsType != Machine_MEGA_TS)
//        {
//            ui->RTD_PCS_StackedWidget->setCurrentWidget(ui->RTD_Bypass_N_page);
//            ui->RTState_stackedWidget->setCurrentWidget(ui->RTState_Bypass_N_page);
//        }
//        else
//        {
            ui->RTD_PCS_StackedWidget->setCurrentWidget(ui->RTD_Bypass_Y_page);
            ui->RTState_stackedWidget->setCurrentWidget(ui->RTState_Bypass_Y_page);
//        }

//        if(m_DspSetData.u16BatteryType == Battery_Li)
            ui->BAT_stackedWidget->setCurrentWidget(ui->BAT_Lithium_page);
//        else if(m_DspSetData.u16BatteryType == Battery_lead)
//            ui->BAT_stackedWidget->setCurrentWidget(ui->BAT_Lead_page);
//        else
//            ui->BAT_stackedWidget->setCurrentWidget(ui->BAT_No_page);

        ui->stackedWidget->setCurrentWidget(ui->Status_page);
        ui->Run_tabWidget->setCurrentIndex(0);
//        m_UIPage.m_first = RUN_PAGE;
//        m_UIPage.m_second = ui->Run_tabWidget->currentIndex() + m_UIPage.m_first * 10;
        break;
    case RECORDPAGE:
        ui->stackedWidget->setCurrentWidget(ui->Record_page);
        ui->Record_tabWidget->setCurrentWidget(ui->DataReport_page);
        ui->Report_tab->setCurrentWidget(ui->Report_tabPage_T);
//        m_UIPage.m_first = RECORD_PAGE;
//        m_UIPage.m_second = ui->Record_tabWidget->currentIndex() + m_UIPage.m_first * 10;
        //ui->History_dateEdit->setDate(QDateTime::currentDateTime().date());
        ui->dateEdit->setDate(QDateTime::currentDateTime().date());


        break;
    case SYSTEMPAGE:
//        if(PasswordCheck())
//        {
            ui->stackedWidget->setCurrentWidget(ui->System_page);
//            if(m_DspSetData.u16BatteryType == Battery_Li)
//            {
                ui->BatterSet_stackedWidget->setCurrentWidget(ui->Lithium_stackedWidgetPage);
//            }
//            else if(m_DspSetData.u16BatteryType == Battery_lead)
//            {
//                ui->BatterSet_stackedWidget->setCurrentWidget(ui->Lead_stackedWidgetPage);
//                BatterySetting_tbnt_released();
//            }
//            else
//            {
//                ui->BatterSet_stackedWidget->setCurrentWidget(ui->NOBAT_stackedWidgetPage);
//            }

            ui->System_tabWidget->setCurrentIndex(0);
//            m_UIPage.m_first = SYSTEM_PAGE;
//            m_UIPage.m_second = ui->System_tabWidget->currentIndex() + m_UIPage.m_first * 10;

//            PasswordLimit();

//        }
        break;
    case MACHINECLOSE:
        {
//            int ret;
//            if((m_SysMonSetData.u16ControlMode == SEARCH_REMOTE))
//            {

//            }
//            else
//            {
//                MsgBox *msgBox = new MsgBox(3, tr("Are you sure close Converter?"));
//                ret = msgBox->exec();
//                if(ret == QDialog::Accepted)
//                {
//                    manualflag = false;
//                    SendCANMsg(0x02,0x12,0x3F); //关闭逆变器
//                    m_ptMonInfoEntry->State.SynthesisState.ucMonOnOffState = MON_ON_OFF_OFF;
//                }
//                delete msgBox;
//            }

        }

        break;
    case MACHINESTANDBY:
        {
//            int ret;
//            if((m_SysMonSetData.u16ControlMode == SEARCH_REMOTE))
//            {

//            }
//            else
//            {
//                MsgBox *msgBox = new MsgBox(3, tr("Are you sure standby Converter?"));
//                ret = msgBox->exec();
//                if(ret == QDialog::Accepted)
//                {
//                    manualflag = false;
//                    SendCANMsg(0x02,0x14,0x3F);
//                }
//                delete msgBox;
//            }

        }
        break;
    case MACHINEOPEN:
        {
//            int ret;
//            INT16 BMS_rest;
//            BMS_rest = TurnON_Status_check(m_ptMonInfoEntry->PCSStatus.BMSStatus);
//            if((m_SysMonSetData.u16ControlMode == SEARCH_REMOTE))
//            {

//            }
//            else
//            {
//                MsgBox *msgBox = new MsgBox(3, tr("Are you sure open Converter?"));
//                ret = msgBox->exec();
//                if(ret == QDialog::Accepted)
//                {
//                    if(m_ptMonInfoEntry->PCSStatus.DryStatusCook == DI_Prompt
//                        || m_ptMonInfoEntry->PCSStatus.DryStatusCook == DI_GridSignal)
//                    {
//                        if(m_DspSetData.u16RunMod == WORK_NORMAL)
//                        {
//                            if(BMS_rest >= 0)
//                            {
//                                manualflag = true;
//                                SendCANMsg(0x02,0x11,0x3F); //打开逆变器
//                                m_ptMonInfoEntry->State.SynthesisState.ucMonOnOffState = MON_ON_OFF_ON;
//                            }
//                            else
//                            {
//                                BMSTurnON_Error(BMS_rest);
//                            }
//                        }
//                        else
//                        {
//                            if(m_ptMonInfoEntry->PCSStatus.AutoRunEnable == AUTORUNENABLE)
//                            {
//                                manualflag = true;
//                                SendCANMsg(0x02,0x11,0x3F); //打开逆变器
//                                m_ptMonInfoEntry->State.SynthesisState.ucMonOnOffState = MON_ON_OFF_ON;
//                            }
//                            else
//                            {
//                                manualflag = true;
//                                m_ptMonInfoEntry->State.SynthesisState.ucMonOnOffState = MON_ON_OFF_ON;
//                                BootPrompt();
//                            }
//                        }

//                    }
//                    else
//                    {
//                        DryTurnON_Error(m_ptMonInfoEntry->PCSStatus.DryStatusCook);
//                    }

//                }
//                delete msgBox;
//            }
        }
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

//    numkeyboard = new NumKeyboard(this);
//    net = new net_infor(this);
//    ui->net_infor_scrollArea->setWidget(net);
//    CopyFileWindow = NULL;
//    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
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
//    if(m_DspSetData.u16UpsType != Machine_MEGA_TS)
//    {
//        ui->RTD_PCS_StackedWidget->setCurrentWidget(ui->RTD_Bypass_N_page);
//    }
//    else
//    {
        ui->RTD_PCS_StackedWidget->setCurrentWidget(ui->RTD_Bypass_Y_page);
        ui->Bypass_Tab->setCurrentWidget(ui->Bypass_Converter_page);
//    }

//    if(m_DspSetData.u16BatteryType == Battery_Li)
//        ui->BAT_stackedWidget->setCurrentWidget(ui->BAT_Lithium_page);
//    else if(m_DspSetData.u16BatteryType == Battery_lead)
//        ui->BAT_stackedWidget->setCurrentWidget(ui->BAT_Lead_page);
//    else
        //        ui->BAT_stackedWidget->setCurrentWidget(ui->BAT_No_page);
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
//    if(m_DspSetData.u16BatteryType == Battery_Li)
//    {
        ui->BAT_stackedWidget->setCurrentWidget(ui->BAT_Lithium_page);
//    }
//    else if(m_DspSetData.u16BatteryType == Battery_lead)
//    {
//        ui->BAT_stackedWidget->setCurrentWidget(ui->BAT_Lead_page);
//    }
//    else
//    {
//        ui->BAT_stackedWidget->setCurrentWidget(ui->BAT_No_page);
        //    }
}

void MEGAWin::on_Batt_btn_released()    //显示电池信息
{
    ui->stackedWidget->setCurrentWidget(ui->Status_page);
    ui->Run_tabWidget->setCurrentWidget(ui->BatteryData_page);
//    if(m_DspSetData.u16BatteryType == Battery_Li)
//    {
        ui->BAT_stackedWidget->setCurrentWidget(ui->BAT_Lithium_page);
//    }
//    else if(m_DspSetData.u16BatteryType == Battery_lead)
//    {
//        ui->BAT_stackedWidget->setCurrentWidget(ui->BAT_Lead_page);
//    }
//    else
//    {
//        ui->BAT_stackedWidget->setCurrentWidget(ui->BAT_No_page);
//    }
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
//    if(set)
//        delete set;

//    set = new TimeDialog();

//    set->setWindowModality(Qt::NonModal);
//    set->show();
}

void MEGAWin::on_Run_tabWidget_tabBarClicked(int index) //实时数据界面选项卡点击响应
{
//    qDebug("on_Run_tabWidget_tabBarClicked%d\n", index);
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
//    QString STR;
}

void MEGAWin::ToSetButton()
{
//    QPushButton * btn_name1[] ={PCS_vol_AB_btn,PCS_vol_BC_btn,PCS_vol_CA_btn,PCS_cur_A_btn,PCS_cur_B_btn, PCS_cur_C_btn,\
//                              PCS_act_P_btn,PCS_rea_P_btn,PCS_par_P_btn,PCS_Pf_btn,\
//                              PCS_Bat_vol_btn,PCS_Bat_cur_btn,PCS_Bat_P_btn,PCS_Bus_vol_btn,PCS_IGBT_T_btn,PCS_Env_T_btn,\
//                              Grid_vol_AB_btn,Grid_vol_BC_btn,Grid_vol_CA_btn,Grid_cur_A_btn,Grid_cur_B_btn, Grid_cur_C_btn,\
//                              Grid_act_P_btn,Grid_rea_P_btn,Grid_app_P_btn,Grid_fre_btn,Grid_Pf_btn,\
//                              Load_vol_AB_btn,Load_vol_BC_btn,Load_vol_CA_btn,Load_cur_A_btn,Load_cur_B_btn, Load_cur_C_btn,\
//                              Load_act_P_btn,Load_rea_P_btn,Load_app_P_btn,Load_fre_btn,Load_Pf_btn};

//    QString data[] ={"400V","401V","402V","403V","404V","405V","400V","400V","400V","400V","400V","400V"\
//                    ,"400V","400V","400V","400V","400V","400V","400V","400V","400V","400V","400V","400V"\
//                    ,"400V","400V","400V","400V","400V","400V","400V","400V","400V","400V","400V","400V"\
//                    ,"400V","400V"};

//    QPushButton * btn_name2[] ={};

//    for (int i=0;i<sizeof(btn_name1)/sizeof(btn_name1[0]);i++)
//    {
//        PCS_pairList.append(qMakePair(btn_name[i],i));

//        if(i<=9){
//            PCS_C_data[i] = new Specification(btn_name1[i],  ui->Converter_Tab, 5, 4, "5", "Phase_B_power", "This is Phase_B_power");
//            btn_name1[i]->setText(data[i].toUtf8());
//            ui->Converter_Tab->setCellWidget(i,1,(QWidget *)btn_name1[i]);
//            pButtonGroup->addButton(btn_name1[i], i);
//        }
//        else if (i<=15) {
//            btn_name1[i]->setText(data[i].toUtf8());
//            ui->Converter_Tab->setCellWidget(i%10,3,(QWidget *)btn_name1[i]);
//            pButtonGroup->addButton(btn_name1[i], i);
//        }
//        else if (i<=26) {
//            btn_name1[i]->setText(data[i].toUtf8());
//            ui->Grid_Tab->setCellWidget(i%16,1,(QWidget *)btn_name1[i]);
//            pButtonGroup->addButton(btn_name1[i], i);
//        }
//        else if (i<=36) {
//            btn_name1[i]->setText(data[i]);
//            ui->Load_Tab->setCellWidget(i%27,1,(QWidget *)btn_name1[i]);
//            pButtonGroup->addButton(btn_name1[i], i);
//        }
//    }

//    for (int i=1;i<=24;i++)
//    {
//        QString bat_btn_name="pushButton_%1" ;
//        bat_btn_name = bat_btn_name.arg(i);
//        pButtonGroup->addButton(btn_name1[i], i);
//    }
//    for (QPair<QPushButton *, QString> pair : PCS_pairList) {
//        qDebug() << "Key: " << pair.first; // 获取第一个值
//        qDebug() << "Value: " << pair.second; // 获取第二个值

//        pair.first->setText(tr("%1").append(pair.second));
//        ui->Converter_Tab->setCellWidget(0,1,(QWidget *)pair.first);
//    }
}


//void MEGAWin::Constant_power_explain_clicked()  //功率说明
//{
////    QMessageBox::information(this, "Constant power", "You can modify the power of the converter by modifying the value", QMessageBox::Ok);
//    QMessageBox::about(this, "Constant power", "You can modify the power of the converter by modifying the value");

////    QMessageBox msgBox;
////    msgBox.setText("Constant_power_explain_clicked");
//    //    msgBox.exec();
//}

//void MEGAWin::Phase_C_power_btn_clicked()
//{
//    QMessageBox::about(this, "Phase Cpower", "C-phase power");
//}

//void MEGAWin::slot_btnGroupClicked(int nid)
//{
//    hand_name.prepend("Phase Cpower");
//    btn_explain.prepend("C-phase power 0");

////    qDebug() << hand_name.size() <<nid;

//    QMessageBox::about(this, "Phase Cpower", "C-phase power 1");

//}

void MEGAWin::on_System_tabWidget_currentChanged(int index)
{

//    m_UIPage.m_first = SYSTEM_PAGE;
//    m_UIPage.m_second = index + m_UIPage.m_first * 10;
    GeneralParam_tbnt_released();
//    if(m_UIPage.m_second == SAuto_PAGE)
//    {
//        TimeSet_tbnt_released();
//    }
//    if(m_UIPage.m_second == SInfor_PAGE)
//    {
        Information_tbnt_released();
//    }
}
