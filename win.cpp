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
    combox_ui_GridMode =   new QComboBox();             //并网方式
    combox_ui_GridMode->setView(new QListView());

    combox_ui_ChargeDischar =   new QComboBox();        //充放电设置
    combox_ui_ChargeDischar->setView(new QListView());

    combox_RUN  =   new QComboBox();                    //运行模式
    combox_RUN->setView(new QListView());

    combox_ControlMode  =   new QComboBox();            //控制模式
    combox_ControlMode->setView(new QListView());       //控制模式列表

    combox_ui_OnOff_Grid =   new QComboBox();           //并离网设置
    combox_ui_OnOff_Grid->setView(new QListView());     //并离网列表设置

    combox_MachineNumber = new QComboBox();             //设备号
    combox_MachineNumber->setView(new QListView());

    combox_Parallel = new QComboBox();                  //并机
    combox_Parallel->setView(new QListView());

    combox_UnbalancePowerEnable = new QComboBox();      //功率不平衡使能
    combox_UnbalancePowerEnable->setView(new QListView());

    AdvancedSetup_btn = new QPushButton;
    Constant_power_explain = new QPushButton;
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
 * @brief SystemSettingPage init
 * #attribute   Fuction
 * @param non       @see  non
 * @param Non         @see Non
 *
 * @return Non
 *     -<em>false</em> fail
 *     -<em>true</em> succeed
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
//    EquipmentInfor_tab();
    /*铅酸电池设置表*/
    BatterySet_tab();
    /*自动运行时间设置表*/
    //    RunTimeSet_tab();
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
//    ui->System_Tab->horizontalHeader()->setStretchLastSection(3);


    //并离网
    combox_ui_OnOff_Grid->setStyleSheet("QComboBox QAbstractItemView::item{height: 30}");
    combox_ui_OnOff_Grid->addItems(ui_OnOff_Grid);
//    combox_ui_OnOff_Grid->setCurrentIndex(ui_sysDspSetData.u16OnOffGrid - 1);
    combox_ui_OnOffGrid_str = combox_ui_OnOff_Grid->currentText();
    combox_ui_OnOffGrid_index = combox_ui_OnOff_Grid->currentIndex();

    //充放电
    combox_ui_ChargeDischar->setStyleSheet("QComboBox QAbstractItemView::item{height: 30}");
    combox_ui_ChargeDischar->addItems(ui_ChargeDischar);
//    combox_ui_ChargeDischar->setCurrentIndex(ui_sysDspSetData.u16ChargeOrDischarge - 1);
    combox_ui_ChargeDischar_str = combox_ui_ChargeDischar->currentText();
    combox_ui_ChargeDischar_index = combox_ui_ChargeDischar->currentIndex();

    //运行方式
    combox_RUN->setStyleSheet("QComboBox QAbstractItemView::item{height: 30}");
    combox_RUN->addItems(combox_Runmode);
//    combox_RUN->setCurrentIndex(ui_sysDspSetData.u16RunMod);//默认手动控制
    combox_RUN_str = combox_RUN->currentText();
    combox_RUN_index = combox_RUN->currentIndex();

    //控制模式
    combox_ControlMode->setStyleSheet("QComboBox QAbstractItemView::item{height: 30}");
    combox_ControlMode->addItems(combox_CM);
//    combox_ControlMode->setCurrentIndex(ui_sysMonSetData.u16ControlMode);
    combox_ControlMode_str = combox_ControlMode->currentText();
    combox_ControlMode_index = combox_ControlMode->currentIndex();

    combox_MachineNumber->setStyleSheet("QComboBox QAbstractItemView::item{height: 30}");
    combox_MachineNumber->addItems(combox_MNumber);
//    combox_MachineNumber->setCurrentIndex(ui_sysDspSetData.u16MachineNumber);
    MachineNumber_str = combox_MachineNumber->currentText();
    combox_MachineNumber_index = combox_MachineNumber->currentIndex();

    combox_Parallel->setStyleSheet("QComboBox QAbstractItemView::item{height: 30}");
    combox_Parallel->addItems(combox_Para);
//    combox_Parallel->setCurrentIndex(ui_sysDspSetData.u16EnableParallel);
    combox_Parallel_str = combox_Parallel->currentText();
    combox_Parallel_index = combox_Parallel->currentIndex();

    combox_UnbalancePowerEnable->setStyleSheet("QComboBox QAbstractItemView::item{height: 30}");
    combox_UnbalancePowerEnable->addItems(combox_Para);
//    combox_UnbalancePowerEnable->setCurrentIndex(ui_sysDspSetData.u16UnbalancePowerEnable);
    combox_UnbalancePowerEnable_str = combox_UnbalancePowerEnable->currentText();
    combox_UnbalancePowerEnable_index = combox_UnbalancePowerEnable->currentIndex();

    AdvancedSetup_btn->setText(tr("Advance setting"));
    Constant_power_explain->setText(tr("0"));

    ui->System_Tab->setCellWidget(0,1, (QWidget *)combox_ui_OnOff_Grid);        //并离网
    ui->System_Tab->setCellWidget(2,1, (QWidget *)combox_ui_ChargeDischar);     //充放电设置
    ui->System_Tab->setCellWidget(3,1, (QWidget *)combox_RUN);                  //运行模式

    ui->System_Tab->setCellWidget(0,4, (QWidget *)combox_ControlMode);          //控制模式
    ui->System_Tab->setCellWidget(1,4, (QWidget *)combox_MachineNumber);        //设备号
    ui->System_Tab->setCellWidget(2,4, (QWidget *)combox_Parallel);             //并机
    ui->System_Tab->setCellWidget(3,4, (QWidget *)combox_UnbalancePowerEnable); //功率不平衡使能

    ui->System_Tab->setCellWidget(7,4, (QWidget *)AdvancedSetup_btn);          //高级设置
    ui->System_Tab->setCellWidget(1,1, (QWidget *)Constant_power_explain);
}
/******************************************************************************
 * 电池设置表初始化
 *
 *
 *
 *
 *
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
    ModuleData_Tab();
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

    ui_ChargeDischar << tr("Charge") << tr("Discharge");
    ui_OnOff_Grid << tr("Off") << tr("On") << tr("automatic");
//    combox_Battery << tr("Non") << tr("Lithium") << tr("LeadAcid");
//    if(m_SysMonSetData.u16LOGO == LOGO_MEGA)
//        combox_Machine << tr("MEGA ") << tr("MEGA -T") << tr("MEGA -TS") << tr("MEGA -TS-T");
//    else
//        combox_Machine << tr("PCS ") << tr("PCS -T") << tr("PCS -TS") << tr("PCS -TS-T");

//    combox_Control << tr("CAN") << tr("RS485") << tr("Ethernet") << tr("Non");
    combox_Runmode << tr("Manual") << tr("Peak valley") << tr("UPS") << tr("Prevent countercurrnet");
    combox_CM << tr("Local") << tr("Remote");
//    combox_Volt_down << "-10" << "-15" << "-20" << "-30";
//    combox_Volt_up << "+10" << "+15" << "+20" << "+30";
//    combox_limite_down  << "-0.5" << "-1" << "-2" << "-3";
//    combox_limite_up  << "0.2" << "0.5" << "1" << "3";
//    can_bps << "100" << "125" << "250" << "500" << "800";
//    combox_bps << "1200" << "2400" << "4800" << "9600" << "19200" << "38400";
//    combox_InsulationDetectionEN << tr("Disable") << tr("Enable");
//    comobx_Language <<tr("Chinese") << tr("English");
//    sounds_choice << tr("Allow") << tr("forbid");
    combox_Para << tr("Disable") << tr("Enable");
    combox_MNumber << tr("Master_00") << tr("Slave_01") << tr("Slave_02") << tr("Slave_03") << tr("Slave_04") << tr("Slave_05") << tr("Slave_06") << tr("Slave_07") << tr("Slave_08");
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
//    if(PasswordCheck())
//    {
//        PasswordLimit();
//        ui->UI_stackedWidget->setCurrentWidget(ui->BasicSet_page);

//        combox_ui_QPowerMode_index = combox_ui_QPowerMode->currentIndex();
//        combox_HVRTEnable_index = combox_HVRTEnable->currentIndex();
//        combox_ui_CapType_index = combox_ui_CapType->currentIndex();
//        combox_ui_EnableLVRT_index = combox_ui_EnableLVRT->currentIndex();
//        combox_EMS_CommType_index   =   combox_EMS_CommType->currentIndex();
//        Primary_FM_DZ_str = Primary_FM_DZ->text();
//        PFM_Coeff_str =  Primary_FM_DZ->text();
//        GridRecoverTime_str =  GridRecoverTime->text();

//        combox_ui_RunMod_index = combox_ui_RunMod->currentIndex();
////        combox_ui_SysVltGrade_index = combox_ui_SysVltGrade->currentIndex();
//        PowerCtlType_index = combox_OutPower->currentIndex();
//        combox_ui_Turns_ratio_index = combox_ui_Turns_ratio->currentIndex();
//        InsulationDetectionEN_index = InsulationDetectionEN->currentIndex();
//        CV_ParallelEN_index = CV_ParallelEN->currentIndex();
//        DynamicCapEN_index = DynamicCapEN->currentIndex();

//        combox_ui_QPowerMode_str = combox_ui_QPowerMode->currentText();
//        combox_ui_OutFreq_str = combox_ui_OutFreq->text();
//        combox_ui_CapType_str = combox_ui_CapType->currentText();
//        combox_ui_EnableLVRT_str = combox_ui_EnableLVRT->currentText();
//        combox_EMS_CommType_str =   combox_EMS_CommType->currentText();
        combox_ui_GridMode_str = combox_ui_GridMode->currentText();
//        combox_ui_RunMod_str = combox_ui_RunMod->currentText();
//        combox_ui_SysVltGrade_str = combox_ui_SysVltGrade->text();//->currentText();
//        combox_ui_OutPower_str = combox_OutPower->currentText();

//        PowerFactor_str = OutputPowerFactor->text();//输出功率因数
//        OutputReactivePower_str = OutputReactivePower->text();//输出无功功率
//        ConstantCurrent_str = ConstantCurrent->text();
//        ConstantVoltage_str = ConstantVoltage->text();
//        combox_IsolatedIsland_index = combox_IsolatedIsland->currentIndex();
//        MachineNumber_str = combox_MachineNumber->currentText();
//        CV_ParallelEN_str = CV_ParallelEN->currentText();
//        DynamicCapEN_str  = DynamicCapEN->currentText();


//        timer2->start();//2018/11/21
//    }
//    else
//    {
//        ui->stackedWidget->setCurrentWidget(ui->System_page);
//    }

}

/***************************************************************
 *高级设置按钮点击功能
 ***************************************************************/
void MEGAWin::AdvancedSetup_btn_clicked()
{
//    Sclick = 0;
//    if(PasswordCheck() && root == SUPER)
//    {
        ui->UI_stackedWidget->setCurrentWidget(ui->BasicSet_page);
        SystemParam_tbnt_released();
//    }
}

/***************************************************************
 * @brief Connected relation function 连通关系函数
 ***************************************************************/
void MEGAWin::LinkRelationship()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerOut()));

    connect(Update_RTData_timer, SIGNAL(timeout()), this, SLOT(updateTimeOut()));

    //系统设置
//    connect(combox_ui_GridMode, SIGNAL(currentIndexChanged(int)), this, SLOT(combox_ui_GridMode_change()));

    connect(combox_ui_OnOff_Grid, SIGNAL(currentIndexChanged(int)), this, SLOT(combox_ui_OnOff_Grid_change()));//并离网

    connect(combox_ControlMode, SIGNAL(currentIndexChanged(int)), this, SLOT(combox_ControlMode_change()));//控制模式
    connect(AdvancedSetup_btn,SIGNAL(clicked(bool)), this, SLOT(AdvancedSetup_btn_clicked()));//高级设置
    connect(Constant_power_explain,SIGNAL(clicked(bool)), this, SLOT(Constant_power_explain_clicked()));//高级设置


    connect(ui->Bypass_Batt_btn, SIGNAL(clicked()), this, SLOT(on_Batt_btn_released()));    //主页电池按钮跳转电池信息
    connect(ui->Bypass_Running_btn, SIGNAL(clicked()), this, SLOT(on_Running_btn_clicked()));   //主页变流器按钮跳转变流器实时数据
    connect(ui->Bypass_Grid_btn, SIGNAL(clicked()), this, SLOT(on_Grid_clicked()));    //主页电网按钮跳转电网实时数据
    connect(ui->Bypass_Load_Btn, SIGNAL(clicked()), this, SLOT(on_Load_clicked()));    //主页负载按钮跳转负载实时数据

}
/******************************************************************************
 * 模块实时数据表初始化
 *
 *
 *
 *
 *
 * ***************************************************************************/
void MEGAWin::ModuleData_Tab()
{
//    if(ui->UI_SystemParameter_Tab->item(1, 5)->text() != Machine_MEGA_TS)
//    {
//        //设置表格背景颜色
//        QPalette pal;
//        pal.setColor(QPalette::Base, QColor(255, 0, 0));
//        pal.setColor(QPalette::AlternateBase, QColor(100, 149, 237));
//        ui->RTDataModel_tableWidget->setPalette(pal);
//        ui->RTDataModel_tableWidget->setAlternatingRowColors(true);

//        ui->RTDataModel_tableWidget->clearContents();
//        ui->RTDataModel_tableWidget->setColumnCount(6);
//        ui->RTDataModel_tableWidget->setRowCount(12);
//        QStringList List1;
//        List1 << tr("Name") << tr("Value") << tr("Name") << tr("Value") << tr("Name") << tr("Value");
//        ui->RTDataModel_tableWidget->setHorizontalHeaderLabels(List1);

//        ui->RTDataModel_tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
//        ui->RTDataModel_tableWidget->verticalHeader()->setVisible(false);//设置垂直头不可见
//        ui->RTDataModel_tableWidget->setFrameShape(QFrame::NoFrame);//设置无边框
//        ui->RTDataModel_tableWidget->setShowGrid(true);//设置不显示格子
//        ui->RTDataModel_tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
//        ui->RTDataModel_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
//        ui->RTDataModel_tableWidget->setStyleSheet("selection-background-color:lightblue;");

//        ui->RTDataModel_tableWidget->setColumnWidth(0,150);
//        ui->RTDataModel_tableWidget->setColumnWidth(1,100);
//        ui->RTDataModel_tableWidget->setColumnWidth(2,150);
//        ui->RTDataModel_tableWidget->setColumnWidth(3,100);
//        ui->RTDataModel_tableWidget->setColumnWidth(4,150);
//    //    ui->RTDataModel1_tableWidget->setColumnWidth(3,100);
//        ui->RTDataModel_tableWidget->horizontalHeader()->setStretchLastSection(5);

//        QStringList ModuleName;//离网//<< tr("Inductance Temp.")
//        ModuleName << tr("Lin-Vol(AB)") << tr("Lin-Vol(BC)") << tr("Lin-Vol(CA)")
//                   << tr("Output Cur.(A)") << tr("Output Cur.(B)")<< tr("Output Cur.(C)")
//                   << tr("Active Power") << tr("Reactive Power") << tr("Parent Power")
//                   << tr("Output Pf") << tr("-")<< tr("-")

//                   << tr("Inv. Vol(AB)")<< tr("Inv. Vol(BC)") << tr("Inv. Vol(CA)")
//                   << tr("Inv. Cur(AB)")<< tr("Inv. Cur(BC)") << tr("Inv. Cur(CA)")
//                   << tr("Inv.Active P.") << tr("Inv. Reactive P.")<< tr("Inv. Parent P.")
//                   << tr("-") << tr("-")<< tr("-")

//                   << tr("Bat Vol.") << tr("Bat Cur.") << tr("Bat Power")<< tr("Bus Vol.")
//                   << tr("IGBT Temp.") << tr("Env. Temp.")
//                   << tr("Grid frequency") << tr("-") << tr("-")
//                   << tr("-") << tr("-")<< tr("-");

//        QStringList ModuleName_1;//并网// << tr("Inductance Temp.")
//        ModuleName_1 << tr("Grid Vol.(AB)") << tr("Grid Vol.(BC)") << tr("Grid Vol.(CA)")
//                   << tr("Grid Cur.(A)") << tr("Grid Cur.(B)")<< tr("Grid Cur.(C)")
//                   << tr("Grid Active P.") << tr("Grid Reactive P.") << tr("Grid Parent P.")
//                   << tr("Grid Pf") << tr("-")<< tr("-")

//                   << tr("Inv. Vol(AB)")<< tr("Inv. Vol(BC)") << tr("Inv. Vol(CA)")
//                   << tr("Inv. Cur(AB)")<< tr("Inv. Cur(BC)") << tr("Inv. Cur(CA)")
//                   << tr("Inv.Active P.") << tr("Inv. Reactive P.")<< tr("Inv. Parent P.")
//                   << tr("-") << tr("-")<< tr("-")

//                   << tr("Bat Vol.") << tr("Bat Cur.") << tr("Bat P")<< tr("Bus Vol.")
//                   << tr("IGBT Temp.")<< tr("Env. Temp.") << tr("Grid Frequency")
//                   << tr("-") << tr("-")
//                   << tr("-") << tr("-")<< tr("-");

//        for(int i = 0; i < 3; i++)
//        {
//            for(int j = 0; j < 12; j++)
//            {
//                if(0 == i)
//                {
//                    if(m_DspSetData.u16OnOffGrid == 1)
//                    {
//                        ui->RTDataModel_tableWidget->setItem(j, i, new QTableWidgetItem(ModuleName.at(j)));
//                        ui->RTDataModel_tableWidget->item(j, i)->setTextAlignment(Qt::AlignCenter);
//                    }
//                    else
//                    {
//                        ui->RTDataModel_tableWidget->setItem(j, i, new QTableWidgetItem(ModuleName_1.at(j)));
//                        ui->RTDataModel_tableWidget->item(j, i)->setTextAlignment(Qt::AlignCenter);
//                    }
//                }
//                else if(1 == i)
//                {
//                    int a = 12 + j;
//                    if(a < ModuleName.size())
//                    {
//                        if(m_DspSetData.u16OnOffGrid == 1)
//                        {
//                            ui->RTDataModel_tableWidget->setItem(j, (i + 1), new QTableWidgetItem(ModuleName.at(a)));
//                            ui->RTDataModel_tableWidget->item(j, (i + 1))->setTextAlignment(Qt::AlignCenter);
//                        }
//                        else
//                        {
//                            ui->RTDataModel_tableWidget->setItem(j, (i + 1), new QTableWidgetItem(ModuleName_1.at(a)));
//                            ui->RTDataModel_tableWidget->item(j, (i + 1))->setTextAlignment(Qt::AlignCenter);
//                        }
//                    }
//                }
//                else
//                {
//                    int a = 24 + j;
//                    if(a < ModuleName.size())
//                    {
//                        if(m_DspSetData.u16OnOffGrid == 1)
//                        {
//                            ui->RTDataModel_tableWidget->setItem(j, (i + 2), new QTableWidgetItem(ModuleName.at(a)));
//                            ui->RTDataModel_tableWidget->item(j, (i + 2))->setTextAlignment(Qt::AlignCenter);
//                        }
//                        else
//                        {
//                            ui->RTDataModel_tableWidget->setItem(j, (i + 2), new QTableWidgetItem(ModuleName_1.at(a)));
//                            ui->RTDataModel_tableWidget->item(j, (i + 2))->setTextAlignment(Qt::AlignCenter);
//                        }

//                    }
//                }

//            }
//    //    ui->RTDataModel_tableWidget->resizeColumnsToContents();
//        }
//    }
//    else
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
//    if(m_DspSetData.u16UpsType != Machine_MEGA_TS)
//    {
//        QStringList StateName_2;// << tr("DC input breaker 2")
//#ifdef Machine_V2
//        StateName_2 << tr("DC input breaker") << tr("DC contactor")
//                    << tr("Maintenance Bypass breaker") << tr("Grid breaker") << tr("Maintenance Bypass breaker");
//#else
//        if(m_DspSetData.u16UpsType == Machine_MEGA_TS_T)
//        {
//            StateName_2 << tr("DC input breaker") << tr("DC contactor")
//                        << tr("Output contactor") << tr("Output breaker") << tr("Maintenance Bypass breaker");
//        }
//        else
//        {
//            StateName_2 << tr("DC input breaker") << tr("DC contactor")
//                        << tr("Grid contactor") << tr("Grid breaker") << tr("Maintenance Bypass breaker");//  << tr("ModeLock") << tr("Bypass contactor") << tr("Bypass breaker");
//        }

//#endif
//        QStringList StateName_3;
//         StateName_3 << tr("Converter available") << tr("DC Soft start")
//                    << tr("Converter status") << tr("Reactive power Regulation")
//                    << tr("Sleep mode") << tr("LVRT");
//         QStringList StateName_4;
//          StateName_4 << tr("Generator signal") << tr("Reserve")
//                     << tr("Reserve") << tr("EPO contact signal 1")
//                     << tr("EPO contact signal 2") << tr("Access control signal")<< tr("Full power signal") << tr("Smoke alarm signal")<< tr("Hight temp. signal");
//        ui->RTState_MEGA_Tab->clearContents();
//        ui->RTState_MEGA_Tab->setColumnCount(6);
//        ui->RTState_MEGA_Tab->setRowCount(9);
//        ui->RTState_MEGA_Tab->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
//        ui->RTState_MEGA_Tab->verticalHeader()->setVisible(false);//设置垂直头不可见
//        ui->RTState_MEGA_Tab->setFrameShape(QFrame::NoFrame);//设置无边框
//        ui->RTState_MEGA_Tab->setShowGrid(true);//设置显示格子
//        ui->RTState_MEGA_Tab->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
//        ui->RTState_MEGA_Tab->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
//        ui->RTState_MEGA_Tab->setStyleSheet("selection-background-color:lightblue;");
//        QStringList StateList_2;
//        StateList_2 << tr("Name") << tr("Value")<< tr("Name") << tr("Value");
//        ui->RTState_MEGA_Tab->setHorizontalHeaderLabels(StateList_2);
//        ui->RTState_MEGA_Tab->setColumnWidth(0,150);
//        ui->RTState_MEGA_Tab->setColumnWidth(1,100);
//        ui->RTState_MEGA_Tab->setColumnWidth(2,150);
//        ui->RTState_MEGA_Tab->setColumnWidth(3,100);
//        ui->RTState_MEGA_Tab->setColumnWidth(4,150);
//        ui->RTState_MEGA_Tab->horizontalHeader()->setStretchLastSection(5);
//        for(int i = 0; i < StateName_2.size(); i++)
//        {
//            ui->RTState_MEGA_Tab->setItem(i, 0, new QTableWidgetItem(StateName_2.at(i)));
//        }
//        for(int j = 0; j < StateName_3.size(); j++)
//        {
//            ui->RTState_MEGA_Tab->setItem(j, 2, new QTableWidgetItem(StateName_3.at(j)));
//        }
//        for(int k = 0; k < StateName_4.size(); k++)
//        {
//            ui->RTState_MEGA_Tab->setItem(k, 4, new QTableWidgetItem(StateName_4.at(k)));
//        }
//        ui->RTState_MEGA_Tab->resizeRowsToContents();
//    }
//    else
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

void MEGAWin::Constant_power_explain_clicked()  //功率说明
{
//    QMessageBox::information(this, "Constant power", "You can modify the power of the converter by modifying the value", QMessageBox::Ok);
    QMessageBox::about(this, "Constant power", "You can modify the power of the converter by modifying the value");

//    QMessageBox msgBox;
//    msgBox.setText("Constant_power_explain_clicked");
//    msgBox.exec();
}
