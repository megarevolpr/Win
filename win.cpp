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


    AdvancedSetup_btn->setText(tr("Advance setting"));
    ui->System_Tab->setCellWidget(7,4, (QWidget *)AdvancedSetup_btn);          //高级设置


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
    ui->Time_tableWidget->setColumnWidth(0,50);
    ui->Time_tableWidget->setColumnWidth(1,180);
    ui->Time_tableWidget->setColumnWidth(2,180);
    ui->Time_tableWidget->setColumnWidth(3,130);
    ui->Time_tableWidget->horizontalHeader()->setStretchLastSection(4);

    QStringList choice;
    choice <<tr("charge") << tr("discharge") << tr("Automatic");

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

    /*功能设置*/
    Battery_type = new Specification(Battery_type_explain, ui->UI_Parameter_Tab, 0, 1, \
                                     "Lithium", "Battery_type", \
                                     "根据实际情况选择电池类型，有锂电和铅酸两种类型可供选择\nChoose the battery type according to the actual situation, there are two types of lithium and lead acid to choose from");
    Battery_type->add_Specifition();
    BMS_Comm_type = new Specification(BMS_Comm_type_explain, ui->UI_Parameter_Tab, 1, 1, \
                                      "CAN", "BMS_Comm_type", \
                                      "设置与电池之间的通信方式，可根据情况选择RS485或CAN通信\nSet the communication mode between the battery, RS485 or CAN communication can be selected according to the situation");
    BMS_Comm_type->add_Specifition();
    Power_control_type = new Specification(Power_control_type_explain, ui->UI_Parameter_Tab, 2, 1,\
                                           "CP_N&&P" , "Power_control_type", \
                                           "设置控制功率的方式，有恒压、恒流、恒功率\nSet the control power mode, constant voltage, constant current, constant power");
    Power_control_type->add_Specifition();
    EMS_Comm_type = new Specification(EMS_Comm_type_explain, ui->UI_Parameter_Tab, 3, 1, \
                                      "RS485", "EMS_Comm_type", \
                                      "设置EMS的通信方式，有RS485， CAN通信，以太网三种方式");
    EMS_Comm_type->add_Specifition();
    Output_power_limit = new Specification(Output_power_limit_explain, ui->UI_Parameter_Tab, 4, 1,\
                                           "100", "Output_power_limit", \
                                           "设置允许输出的功率最大值");
    Output_power_limit->add_Specifition();
    BAT_manufacturers = new Specification(BAT_manufacturers_explain, ui->UI_Parameter_Tab, 5, 1, \
                                          "GAOTE", "BAT_manufacturers", \
                                          "电池厂家");
    BAT_manufacturers->add_Specifition();
    Power_Delta = new Specification(Power_Delta_explain, ui->UI_Parameter_Tab, 6, 1, \
                                    "10", "Power_Delta", \
                                    "This is Phase_B_power");
    Power_Delta->add_Specifition();
    Charge_power_limit = new Specification(Charge_power_limit_explain, ui->UI_Parameter_Tab, 7, 1, \
                                           "100", "Charge_power_limit",\
                                           "This is Phase_B_power");
    Charge_power_limit->add_Specifition();
    Discharge_power_limit = new Specification(Discharge_power_limit_explain, ui->UI_Parameter_Tab, 8, 1, \
                                              "100", "Charge_power_limit", \
                                              "This is Phase_B_power");
    Discharge_power_limit->add_Specifition();
    Charge_Vol_upper_Limit_delta = new Specification(Charge_Vol_upper_Limit_delta_explain, ui->UI_Parameter_Tab, 9, 1, \
                                                     "10", "Charge_Vol_upper_Limit_delta", \
                                                     "This is Phase_B_power");
    Charge_Vol_upper_Limit_delta->add_Specifition();
    Discharge_Vol_lower_Limit_delta = new Specification(Discharge_Vol_lower_Limit_delta_explain, ui->UI_Parameter_Tab, 10, 1,\
                                                        "10", "Discharge_Vol_lower_Limit_delta", \
                                                        "This is Phase_B_power");
    Discharge_Vol_lower_Limit_delta->add_Specifition();
    Host_Address = new Specification(Host_Address_explain, ui->UI_Parameter_Tab, 0, 4,\
                                     "20", "Host_Address", \
                                     "This is Phase_B_power");
    Host_Address->add_Specifition();
    serial_port_1 = new Specification(serial_port_1_explain, ui->UI_Parameter_Tab, 1, 4, \
                                      "9600", "serial_port_1", "This is Phase_B_power");
    serial_port_1->add_Specifition();
    serial_port_2 = new Specification(serial_port_2_explain, ui->UI_Parameter_Tab, 2, 4, \
                                      "9600", "serial_port_2", \
                                      "This is Phase_B_power");
    serial_port_2->add_Specifition();
    serial_port_3 = new Specification(serial_port_3_explain, ui->UI_Parameter_Tab, 3, 4, \
                                      "9600", "serial_port_3", \
                                      "This is Phase_B_power");
    serial_port_3->add_Specifition();
    serial_port_4 = new Specification(serial_port_4_explain, ui->UI_Parameter_Tab, 4, 4, \
                                      "9600", "serial_port_4", \
                                      "This is Phase_B_power");
    serial_port_4->add_Specifition();
    serial_port_5 = new Specification(serial_port_5_explain, ui->UI_Parameter_Tab, 5, 4, \
                                      "9600", "serial_port_5", \
                                      "This is Phase_B_power");
    serial_port_5->add_Specifition();

    Can_port_1 = new Specification(Can_port_1_explain, ui->UI_Parameter_Tab, 6, 4, \
                                   "500", "Can_port_1", \
                                   "This is Phase_B_power");
    Can_port_1->add_Specifition();
    Can_port_2 = new Specification(Can_port_2_explain, ui->UI_Parameter_Tab, 7, 4, \
                                   "250", "Can_port_2", \
                                   "This is Phase_B_power");
    Can_port_2->add_Specifition();
    ProtocolVersion = new Specification(ProtocolVersion_explain, ui->UI_Parameter_Tab, 0, 7, \
                                        "ProtocolVersion", "serial_port_5", \
                                        "This is Phase_B_power");
    ProtocolVersion->add_Specifition();
    UserPassPort = new Specification(UserPassPort_explain, ui->UI_Parameter_Tab, 1, 7, \
                                     "123456", "UserPassPort", \
                                     "This is Phase_B_power");
    UserPassPort->add_Specifition();
    RootPassport = new Specification(RootPassport_explain, ui->UI_Parameter_Tab, 2, 7,\
                                     "888888", "RootPassport", \
                                     "This is Phase_B_power");
    RootPassport->add_Specifition();
    Language = new Specification(Language_explain, ui->UI_Parameter_Tab, 3, 7, \
                                 "English", "Language", \
                                 "This is Phase_B_power");
    Language->add_Specifition();
    System_upgrade = new Specification(System_upgrade_explain, ui->UI_Parameter_Tab, 4, 7, \
                                       "upgrade", "System_upgrade", \
                                       "This is Phase_B_power");
    System_upgrade->add_Specifition();
    Sounds = new Specification(Sounds_explain, ui->UI_Parameter_Tab, 5, 7, \
                               "Allow", "Sounds", \
                               "This is Phase_B_power");
    Sounds->add_Specifition();
    DryContact = new Specification(DryContact_explain, ui->UI_Parameter_Tab, 6, 7, \
                                   "forbid", "DryContact", \
                                   "This is Phase_B_power");
    DryContact->add_Specifition();

    /*系统参数*/
    Change_rate_of_power = new Specification(Change_rate_of_power_explain, ui->UI_SystemParameter_Tab, 0, 1, \
                                             "20", "Change_rate_of_power", \
                                             "根据实际情况选择电池类型，有锂电和铅酸两种类型可供选择\nChoose the battery type according to the actual situation, there are two types of lithium and lead acid to choose from");
    Change_rate_of_power->add_Specifition();
    Grid_frequency_upper_limit = new Specification(Grid_frequency_upper_limit_explain, ui->UI_SystemParameter_Tab, 1, 1, \
                                                   "3", "Grid_frequency_upper_limit", \
                                                   "电网频率变化范围上限");
    Grid_frequency_upper_limit->add_Specifition();
    Grid_frequency_lower_limit = new Specification(Grid_frequency_lower_limit_explain, ui->UI_SystemParameter_Tab, 2, 1, \
                                                   "-3", "Grid_frequency_lower_limit", \
                                                   "电网频率变化范围下限");
    Grid_frequency_lower_limit->add_Specifition();
    Vol_protection_upper_limit = new Specification(Vol_protection_upper_limit_explain, ui->UI_SystemParameter_Tab, 3, 1, \
                                                   "+15", "Vol_protection_upper_limit", \
                                                   "电压保护范围上限");
    Vol_protection_upper_limit->add_Specifition();
    Vol_protection_lower_limit = new Specification(Vol_protection_lower_limit_explain, ui->UI_SystemParameter_Tab, 4, 1, \
                                                   "-15", "Vol_protection_lower_limit", \
                                                   "电压保护范围下限");
    Vol_protection_lower_limit->add_Specifition();
    HVRT_enable = new Specification(HVRT_enable_explain, ui->UI_SystemParameter_Tab, 5, 1, \
                                                    "prohibit", "HVRT_enable", \
                                                    "设置波特率。默认9600");
    HVRT_enable->add_Specifition();
    LVRT_enable = new Specification(LVRT_enable_explain, ui->UI_SystemParameter_Tab, 6, 1, \
                                    "prohibit", "LVRT_enable", \
                                    "This is Phase_B_power");
    LVRT_enable->add_Specifition();
    AFD_enable = new Specification(AFD_enable_explain, ui->UI_SystemParameter_Tab, 7, 1, \
                                   "prohibit", "AFD_enable", \
                                   "This is Phase_B_power");
    AFD_enable->add_Specifition();
    Insulation_detection_enable = new Specification(Insulation_detection_enable_explain, ui->UI_SystemParameter_Tab, 8, 1, \
                                                    "prohibit", "Insulation_detection_enable", \
                                                    "This is Phase_B_power");
    Insulation_detection_enable->add_Specifition();
    PrimaryFreq_enable = new Specification(PrimaryFreq_enable_explain, ui->UI_SystemParameter_Tab, 9, 1, \
                                           "prohibit", "PrimaryFreq_enable", \
                                           "This is Phase_B_power");
    PrimaryFreq_enable->add_Specifition();
    Inertia_enable = new Specification(Inertia_enable_explain, ui->UI_SystemParameter_Tab, 10, 1, \
                                       "prohibit", "Inertia_enable", \
                                       "This is Phase_B_power");
    Inertia_enable->add_Specifition();

    CV_parallel = new Specification(CV_parallel_explain, ui->UI_SystemParameter_Tab, 11, 1, \
                                    "prohibit", "CV_parallel", \
                                    "This is Phase_B_power");
    CV_parallel->add_Specifition();

    Machine_type = new Specification(Machine_type_explain, ui->UI_SystemParameter_Tab, 0, 4, \
                                     "9600", "serial_port_2", \
                                     "This is Phase_B_power");
    Machine_type->add_Specifition();
    Machine_capacity = new Specification(Machine_capacity_explain, ui->UI_SystemParameter_Tab, 1, 4, \
                                     "9600", "serial_port_2", \
                                     "This is Phase_B_power");
    Machine_capacity->add_Specifition();
    Output_Fre_grade = new Specification(Output_Fre_grade_explain, ui->UI_SystemParameter_Tab, 2, 4, \
                                         "9600", "serial_port_3", \
                                         "This is Phase_B_power");
    Output_Fre_grade->add_Specifition();
    Output_vol_level = new Specification(Output_vol_level_explain, ui->UI_SystemParameter_Tab, 3, 4, \
                                         "9600", "serial_port_3", \
                                         "This is Phase_B_power");
    Output_vol_level->add_Specifition();
    Converter_side_vol_level = new Specification(Converter_side_vol_level_explain, ui->UI_SystemParameter_Tab, 4, 4, \
                                         "9600", "serial_port_3", \
                                         "This is Phase_B_power");
    Converter_side_vol_level->add_Specifition();
    Output_reactive_power_mode = new Specification(Output_reactive_power_mode_explain, ui->UI_SystemParameter_Tab, 5, 4, \
                                         "9600", "serial_port_3", \
                                         "This is Phase_B_power");
    Output_reactive_power_mode->add_Specifition();
    Grid_connected_mode_of_Inv = new Specification(Grid_connected_mode_of_Inv_explain, ui->UI_SystemParameter_Tab, 6, 4, \
                                                   "9600", "serial_port_4", \
                                                   "This is Phase_B_power");
    Grid_connected_mode_of_Inv->add_Specifition();
    Primary_FM_dead_zone = new Specification(Primary_FM_dead_zone_explain, ui->UI_SystemParameter_Tab, 7, 4, \
                                             "9600", "serial_port_5", \
                                             "This is Phase_B_power");
    Primary_FM_dead_zone->add_Specifition();
    PFM_coeff = new Specification(PFM_coeff_explain, ui->UI_SystemParameter_Tab, 8, 4, \
                                  "9600", "serial_port_5", \
                                  "This is Phase_B_power");
    PFM_coeff->add_Specifition();
    Grid_recover_time = new Specification(Grid_recover_time_explain, ui->UI_SystemParameter_Tab, 9, 4, \
                                          "9600", "serial_port_5", \
                                          "This is Phase_B_power");
    Grid_recover_time->add_Specifition();
    DynamicCap = new Specification(DynamicCap_explain, ui->UI_SystemParameter_Tab, 10, 4, \
                                   "9600", "serial_port_5", \
                                   "This is Phase_B_power");
    DynamicCap->add_Specifition();

    Module_Number = new Specification(Module_Number_explain, ui->UI_SystemParameter_Tab, 0, 7, \
                                      "9600", "serial_port_5", \
                                      "This is Phase_B_power");
    Module_Number->add_Specifition();
    Restore_factory = new Specification(Restore_factory_explain, ui->UI_SystemParameter_Tab,1, 7, \
                                        "9600", "serial_port_5", \
                                        "This is Phase_B_power");
    Restore_factory->add_Specifition();
    Clear_Data = new Specification(Clear_Data_explain, ui->UI_SystemParameter_Tab, 2, 7, \
                                   "9600", "serial_port_5", \
                                   "This is Phase_B_power");
    Clear_Data->add_Specifition();

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
