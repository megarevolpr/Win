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
    PCS_DataTableInit();
    PCS_StateTableInit();
    History();//历史记录
    OperationLog();//操作日志
    WorkingModeInit();
    LinkRelationship(); //函数关联

}

MEGAWin::~MEGAWin()
{
    delete ui;
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
    //Manual\nParameters Setting,Peak Valley\nParameters Setting,UPS Parameters Setting,Steady State Expansion\nParameters Setting,Transient Expansion\nParameters Setting
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
        else {
            ui->SetPageNum_lb->setText( QString("%1/%2").arg(System_Current_Page).arg(SystemTotal_PAGE) );
        }
        if(System_Current_Page == ParamSet_NUM)
            ui->PageInfo_lb->setText(QString("%1\n%2").arg(Mode_Str.at(CurrentCheckMode)).arg(Mode_title_Str.at(System_Current_Page)));
        else
            ui->PageInfo_lb->setText(Mode_title_Str.at(System_Current_Page));
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
            ui->PageInfo_lb->setText(QString("%1\n%2").arg(Mode_Str.at(CurrentCheckMode)).arg(Mode_title_Str.at(System_Current_Page)));
        else
            ui->PageInfo_lb->setText(Mode_title_Str.at(System_Current_Page));
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
/*实时数据-电网*/
void MEGAWin::on_SGrid_btn_2_clicked()
{
    ui->Bypass_Tab_2->setCurrentWidget(ui->Bypass_Grid_page_2);
}
/*实时数据-变流器*/
void MEGAWin::on_SConverter_btn_2_clicked()
{
    ui->Bypass_Tab_2->setCurrentWidget(ui->Bypass_Converter_page_2);
}
/*实时数据-负载*/
void MEGAWin::on_SLoad_btn_2_clicked()
{
    ui->Bypass_Tab_2->setCurrentWidget(ui->Bypass_Load_page_2);
}
