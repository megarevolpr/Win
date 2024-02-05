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
//    connect(ui->ChangeLanguage_btn, SIGNAL(clicked(bool)), this, SLOT(ChangeLanguage_btn_clicked()));//切换语言点击槽
}
/*内存空间初始化*/
void MEGAWin::MemoryAllocation()
{
    Mode_Str.clear();
    Mode_title_Str.clear();
    Mode_Str<<tr("Manual")<<tr("Peak Valley")<<tr("UPS")<<tr("Transient Expansion")<<tr("Steady-State Expansion")<<tr("Advanced Settings");
    Mode_title_Str<<tr("DC/AC Parameters")<<tr("DC/DC Parameters")<<tr("Lithium Battery Setting Parameters")<<tr("Lead-acid Battery Setting Parameters")<<tr("Time Period Setting")<<tr("Function Sentting 1")<<tr("Function Sentting 2")\
                 <<tr("System Senttings")<<tr("Device")<<tr("DC/AC Debug")<<tr("DC/DC Debug")<<tr("Port data");

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

    ExitReturn_Group = new QButtonGroup();
    ExitReturn_Group->addButton(ui->IntrBack_bt,0);
    ExitReturn_Group->addButton(ui->Save_bt,1);
    ExitReturn_Group->addButton(ui->Exit_bt,2);
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
/******根据菜单索引打开相应的界面******/
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




/*菜单点击*/
void MEGAWin::on_UI_MenuBtn_clicked()
{
    ui->UI_stackedWidget->setCurrentWidget(ui->Menu_page);
}
/*主页电池点击*/
void MEGAWin::on_Bypass_Batt_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Status_page);
    ui->Run_tabWidget->setCurrentWidget(ui->RT_Data_page);
    ui->BAT_stackedWidget->setCurrentWidget(ui->BAT_Lithium_page);
}
/*主页PCS点击*/
void MEGAWin::on_Bypass_Running_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Status_page);
    ui->Run_tabWidget->setCurrentWidget(ui->RT_Data_page);
    ui->Bypass_Tab_2->setCurrentWidget(ui->Bypass_Converter_page_2);
}
/*主页电网点击*/
void MEGAWin::on_Bypass_Grid_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Status_page);
    ui->Run_tabWidget->setCurrentWidget(ui->RT_Data_page);
    ui->Bypass_Tab_2->setCurrentWidget(ui->Bypass_Grid_page_2);
}
/*主页负载点击*/
void MEGAWin::on_Bypass_Load_Btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Status_page);
    ui->Run_tabWidget->setCurrentWidget(ui->RT_Data_page);
    ui->Bypass_Tab_2->setCurrentWidget(ui->Bypass_Load_page_2);
}
/*下一页*/
void MEGAWin::on_SetNext_bt_clicked()
{
    if( CurrentCheckMode != 5 )
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
        ui->PageInfo_lb->setText(Mode_title_Str.at(System_Current_Page));
        ui->setpage_stackedWidget->setCurrentIndex( System_Current_Page );//根据页面索引号切换页面
    }
    else if( CurrentCheckMode == 5 )
    {
        Advanced_Current_Page++;
        if( Advanced_Current_Page > MonitorDeb_PAGE_NUM  )
        {
            Advanced_Current_Page = Advanced_PAGE1_NUM;
        }
        ui->SetPageNum_lb->setText( QString("%1/%2").arg(Advanced_Current_Page-4).arg(AdvancedTotal_PAGE) );
        ui->PageInfo_lb->setText(Mode_title_Str.at(Advanced_Current_Page));
        ui->setpage_stackedWidget->setCurrentIndex( Advanced_Current_Page );
    }
}

/*上一页*/
void MEGAWin::on_SetPrevious_bt_clicked()
{
    if( CurrentCheckMode != 5 )
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
        ui->PageInfo_lb->setText(Mode_title_Str.at(System_Current_Page));
        ui->setpage_stackedWidget->setCurrentIndex( System_Current_Page );
    }
    else if( CurrentCheckMode == 5 )
    {
        Advanced_Current_Page--;
        if( Advanced_Current_Page < Advanced_PAGE1_NUM  )
        {
            Advanced_Current_Page = MonitorDeb_PAGE_NUM;
        }
        ui->SetPageNum_lb->setText( QString("%1/%2").arg(Advanced_Current_Page-4).arg(AdvancedTotal_PAGE) );
        ui->PageInfo_lb->setText(Mode_title_Str.at(Advanced_Current_Page));
        ui->setpage_stackedWidget->setCurrentIndex( Advanced_Current_Page );
    }
}
