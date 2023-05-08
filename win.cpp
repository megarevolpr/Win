#include "win.h"
#include "ui_win.h"
#include <QMenu>
#include <qlistview.h>
#include "UI_Menu/Menu.h"



/************************初始化内存空间********************************/
void MEGAWin::MemoryAllocation()
{
    //创建下拉框
    combox_ui_GridMode =   new QComboBox();                 //并网方式
    combox_ui_GridMode->setView(new QListView());


    AdvancedSetup_btn = new QPushButton;
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

    AdvancedSetup_btn->setText(tr("Advance setting"));

    ui->System_Tab->setCellWidget(7,4, (QWidget *)AdvancedSetup_btn);
}

void MEGAWin::combox_ui_GridMode_change()//逆变器并网方式
{
//    QString STR;

//    if(m_ptModInfoEntry->InvInfo.WarnInfo.ucInvComFault == SYS_CAN_COMM_OK)
//    {
//        if(update_sql_field("sysDspSetData", "u16GridMode", combox_ui_GridMode->currentIndex()) == 0)
//        {
//            m_DspSetData.u16GridMode = combox_ui_GridMode->currentIndex();
//            m_pGblData->SetSetPara(SYS_DSP_SET_PARA, &m_DspSetData);
//            SendCANMsg(0x01,0x04,0x3F);
//            sql_InsertLogData("Grid connected mode of Inv", combox_ui_GridMode_str, combox_ui_GridMode->currentText());
//        }
//        else
//        {
//            STR = tr("Setup failed");
//            SettingDialog(STR); //设置信息提示框
//            combox_ui_GridMode->setCurrentIndex(combox_ui_GridMode_index);
//        }
//         combox_ui_GridMode_str = combox_ui_GridMode->currentText();
//    }
//    else
//    {
//        STR = tr("Set Fault, Can error");
//        SettingDialog(STR); //设置信息提示框
//        combox_ui_GridMode->setCurrentIndex(combox_ui_GridMode_index);
//    }

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
 * @brief AdvancedSetup button clicked function
 * #attribute   Slots
 * @param non       @see  non
 * @param Non         @see Non
 *
 * @return Non
 *     -<em>false</em> fail
 *     -<em>true</em> succeed
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
    //系统设置
//    connect(combox_ui_QPowerMode, SIGNAL(currentIndexChanged(int)), this, SLOT(combox_ui_QPowerMode_change()));
    connect(combox_ui_GridMode, SIGNAL(currentIndexChanged(int)), this, SLOT(combox_ui_GridMode_change()));
    connect(AdvancedSetup_btn,SIGNAL(clicked(bool)), this, SLOT(AdvancedSetup_btn_clicked()));
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


MEGAWin::MEGAWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MEGAWin)
{
    ui->setupUi(this);
    ui->UI_stackedWidget->setCurrentWidget(ui->UI_page );//开机后进入主页面
    ui->stackedWidget->setCurrentWidget(ui->Bypass_page);
    ui->RTD_PCS_StackedWidget->setCurrentWidget(ui->RTD_Bypass_Y_page);
    ui->RTState_stackedWidget->setCurrentWidget(ui->RTState_Bypass_Y_page);
    MemoryAllocation();
    UIPageInit();//初始化界面
//    this->mapFromGlobal(QPoint(0,0));
    m_menu = new Menu(this);
    connect(m_menu, SIGNAL(Sent(int)), this, SLOT(My_menuAction(int)));



}

MEGAWin::~MEGAWin()
{
    delete ui;
}

/************************初始化界面********************************/
void MEGAWin::UIPageInit()
{
//    NotifyLogo();
//    FirstPage();
//    RunStatePage();
//    HistoryPage();
    SystemSettingPage();
//    LCDSetting();
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
