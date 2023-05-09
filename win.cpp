#include "win.h"
#include "ui_win.h"
#include <QMenu>
#include <QTime>
#include <QDate>
#include <QDateTime>
#include <QTimer>
#include <qlistview.h>
#include "UI_Menu/Menu.h"


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
}

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
//    BatterySet_tab();
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
    ui->System_Tab->setCellWidget(0,1, (QWidget *)combox_ui_OnOff_Grid);        //并离网
    ui->System_Tab->setCellWidget(2,1, (QWidget *)combox_ui_ChargeDischar);     //充放电设置
    ui->System_Tab->setCellWidget(3,1, (QWidget *)combox_RUN);                  //运行模式

    ui->System_Tab->setCellWidget(0,4, (QWidget *)combox_ControlMode);          //控制模式
    ui->System_Tab->setCellWidget(1,4, (QWidget *)combox_MachineNumber);        //设备号
    ui->System_Tab->setCellWidget(2,4, (QWidget *)combox_Parallel);             //并机
    ui->System_Tab->setCellWidget(3,4, (QWidget *)combox_UnbalancePowerEnable); //功率不平衡使能
    ui->System_Tab->setCellWidget(7,4, (QWidget *)AdvancedSetup_btn);          //高级设置
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

    //系统设置
//    connect(combox_ui_GridMode, SIGNAL(currentIndexChanged(int)), this, SLOT(combox_ui_GridMode_change()));

    connect(combox_ui_OnOff_Grid, SIGNAL(currentIndexChanged(int)), this, SLOT(combox_ui_OnOff_Grid_change()));//并离网

    connect(combox_ControlMode, SIGNAL(currentIndexChanged(int)), this, SLOT(combox_ControlMode_change()));//控制模式
    connect(AdvancedSetup_btn,SIGNAL(clicked(bool)), this, SLOT(AdvancedSetup_btn_clicked()));//高级设置


    connect(ui->Bypass_Batt_btn, SIGNAL(clicked()), this, SLOT(on_Batt_btn_released()));    //主页电池按钮跳转电池信息
    connect(ui->Bypass_Running_btn, SIGNAL(clicked()), this, SLOT(on_Running_btn_clicked()));   //主页变流器按钮跳转变流器实时数据
    connect(ui->Bypass_Grid_btn, SIGNAL(clicked()), this, SLOT(on_Grid_clicked()));    //主页电网按钮跳转电网实时数据
    connect(ui->Bypass_Load_Btn, SIGNAL(clicked()), this, SLOT(on_Load_clicked()));    //主页负载按钮跳转负载实时数据

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
//    RunStatePage();
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
