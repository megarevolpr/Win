#ifndef MEGAWIN_H
#define MEGAWIN_H

#include <QWidget>
#include <QComboBox>
#include <QPair>
#include <QList>
#include <QStandardItemModel>
#include <QTranslator>
#include <QFile>
#include <QTextStream>
#include <qdebug.h>
#include <QTextStream>//文本流
#include <QIODevice>//I/O设备接口类

#include "upgradetools.h"
#include "GridExpansion.h"
#include "FaultTableInterface.h"
#include "SpecificationData/specificationdata.h"

//当前登录角色
#define Login_User                    0
#define Login_Maintain                1
#define Login_Root                    2
#define Login_None                    3

//菜单
#define USER_LOGIN          0   //登录页面
#define HOSTPAGE            1   //主页
#define RTDATAPAGE          2   //实时数据页
#define RECORDPAGE          3   //历史记录页
#define SYSTEMPAGE          4   //系统设置页
#define MACHINECLOSE        5   //关机
#define MACHINESTANDBY      6   //待机
#define MACHINEOPEN         7   //开机
#define SYSTEMINFORMATION   8   //系统信息

//工作模式
#define Mode_MANUAL                 0
#define Mode_PeakValley             1
#define Mode_UPS                    2
#define Mode_TransientExpansion     3
#define Mode_SteadyStateExpansion   4
#define ADVANCED_SETTING            5//高级设置

//系统基础设置 页码
#define SystemTotal_PAGE        3//基础设置页数
#define ParamSet_NUM            0
#define Lithium_PAGE_NUM        1
#define Lead_PAGE_NUM           2
#define MixedMode_PAGE_NUM      3

//系统高级设置 页码
#define AdvancedTotal_PAGE      8//高级设置页数
#define Advanced_PAGE1_NUM      4
#define Advanced_PAGE2_NUM      5
#define Advanced_PAGE3_NUM      6
#define Device_PAGE_NUM         7
#define BMSProtect_PAGE_NUM     8
#define Debug_PAGE_NUM          9
#define PortMessage_PAGE_NUM    10
#define MonitorDeb_PAGE_NUM     11


namespace Ui {
class MEGAWin;
}

class MEGAWin : public QWidget
{
    Q_OBJECT

public:
    explicit MEGAWin(QWidget *parent = nullptr);
    ~MEGAWin();
    void LCDSetting();//定时器设置
    void LoadLanguageInit();//语言初始化
    void LinkRelationship();//函数关联
    void MemoryAllocation();//初始化内存空间

    void TableInitialization();//表格初始化
    void PCS_DataTableInit();//实时数据-表格初始化
    void PCS_StateTableInit();//实时状态-表格初始化
    void History();//历史记录-表格初始化
    void OperationLog();//操作日志-表格初始化
    void WorkingModeInit();//工作模式-表格初始化
    void TimePeriodInit();//时间段-表格初始化
    void AdvancedSetInit();//高级设置-表格初始化

    void SetControlToTable();//设置控件到表格
    void SetConverterDataToTable(QTableWidget *myTable);//变流器-控件到表格
    void SetGridDataToTable(QTableWidget *myTable);//电网-控件到表格
    void SetLoadDataToTable(QTableWidget *myTable);//负载-控件到表格
    void SetPCS_StateToTable(QTableWidget *myTable);//PCS状态-控件到表格
    void SetHistororyRecordToTable(QTableWidget *myTable);//历史记录-控件到表格
    void SetOpeationLogToTable(QTableWidget *myTable);//操作日志-控件到表格
    void SetBasicParameterToTable(QTableWidget *myTable);//设置基础参数-控件到表格
    void SetBasicParameterUPSToTable(QTableWidget *myTable);//设置基础参数UPS-控件到表格
    void SetBasicParameterExpansionToTable(QTableWidget *myTable);//设置基础参数稳态扩容-控件到表格
    void SetLithiumToTable(QTableWidget *myTable);//设置锂电池页-控件到表格
    void SetLead_acidToTable(QTableWidget *myTable);//设置铅酸电池页-控件到表格
    void SetMixedTime_TabToTable(QTableWidget *myTable);//设置时间段运行页-控件到表格
    void SetAdvancedSetup1ToTable(QTableWidget *myTable);//设置高级设置页1-控件到表格
    void SetAdvancedSetup2ToTable(QTableWidget *myTable);//设置高级设置页2-控件到表格
    void SetAdvancedSetup3ToTable(QTableWidget *myTable);//设置高级设置页3-控件到表格
    void Device_TabToTable(QTableWidget *myTable);//设置高级设置外设页-控件到表格
    void BMSProtectToTable(QTableWidget *myTable); //设置BMS保护页-控件到表格
    void PCS_Debugg(QTableWidget *myTable); //设置高级设置调试页-控件到表格

    SpecificationData *ButtonToTable;//设置控件到表格
    /************************实时数据******************************/
    //变流器
    QPushButton *PCS_vol_AB_explain;
    QPushButton *PCS_vol_BC_explain;
    QPushButton *PCS_vol_CA_explain;
    QPushButton *PCS_cur_A_explain;
    QPushButton *PCS_cur_B_explain;
    QPushButton *PCS_cur_C_explain;
    QPushButton *PCS_active_power_explain;
    QPushButton *PCS_reactive_power_explain;
    QPushButton *PCS_apparent_power_explain;
    QPushButton *PCS_power_factor_explain;
    QPushButton *Batter_vol_explain;
    QPushButton *Batter_cur_explain;
    QPushButton *Batter_power_explain;
    QPushButton *Bus_vol_explain;
    QPushButton *PCS_IGBT_T_explain;
    QPushButton *PCS_Env_T_explain;
    //电网
    QPushButton *Grid_vol_AB_explain;
    QPushButton *Grid_vol_BC_explain;
    QPushButton *Grid_vol_CA_explain;
    QPushButton *Grid_cur_A_explain;
    QPushButton *Grid_cur_B_explain;
    QPushButton *Grid_cur_C_explain;
    QPushButton *Grid_active_power_explain;
    QPushButton *Grid_reactive_power_explain;
    QPushButton *Grid_apparent_power_explain;
    QPushButton *Grid_Frequency_explain;
    QPushButton *Grid_power_factor_explain;
    //负载
    QPushButton *Load_vol_AB_explain;
    QPushButton *Load_vol_BC_explain;
    QPushButton *Load_vol_CA_explain;
    QPushButton *Load_cur_A_explain;
    QPushButton *Load_cur_B_explain;
    QPushButton *Load_cur_C_explain;
    QPushButton *Load_active_power_explain;
    QPushButton *Load_reactive_power_explain;
    QPushButton *Load_apparent_power_explain;
    QPushButton *Load_power_factor_explain;
    /**************************PCS状态*********************/
    QPushButton *DC_input_Breaker_explain;      //直流输入断路器
    QPushButton *DC_Cont_explain;               //直流输入器
    QPushButton *Output_Cont_explain;           //输出接触器
    QPushButton *Output_Breaker_explain;        //输出断路器
    QPushButton *Grid_Cont_explain;             //电网接触器
    QPushButton *Grid_Breaker_explain;          //电网断路器
    QPushButton *MB_Breaker_explain;            //维修旁路
    QPushButton *converter_available_explain;   //变流器使能
    QPushButton *DC_Soft_start_explain;         //直流软启动
    QPushButton *converter_status_explain;      //变流器状态
    QPushButton *Reactive_P_Regulation_explain; //无功调节方式
    QPushButton *LVRT_explain;                  //
    QPushButton *ForcedCharg_explain;           //强充
    QPushButton *Generator_signal_explain;      //柴发信号
    QPushButton *Reserve_explain;               //保留位
    QPushButton *Reserve2_explain;              //保留位
    QPushButton *EPO_Cont_signal1_explain;      //EPO节点信号
    QPushButton *EPO_Cont_signal2_explain;      //EPO节点信号
    QPushButton *Access_signal_explain;         //门禁信号
    QPushButton *Full_P_signal_explain;         //满功率信号
    QPushButton *Smoke_alarm_signal_explain;    //烟感信号
    QPushButton *Hight_temp_signal_explain;     //高温信号
    /**********************历史记录*************************/
    QPushButton *Grade_explain;
    QPushButton *Grade2_explain;
    QPushButton *Grade3_explain;
    QPushButton *Grade4_explain;
    QPushButton *Grade5_explain;
    QPushButton *Grade6_explain;
    QPushButton *Grade7_explain;
    QPushButton *Grade8_explain;
    QPushButton *Grade9_explain;
    QPushButton *Grade10_explain;
    QPushButton *Grade11_explain;
    QPushButton *Grade12_explain;
    QPushButton *Grade13_explain;
    QPushButton *Grade14_explain;
    QPushButton *Grade15_explain;
    QPushButton *StartTime_explain;
    QPushButton *StartTime2_explain;
    QPushButton *StartTime3_explain;
    QPushButton *StartTime4_explain;
    QPushButton *StartTime5_explain;
    QPushButton *StartTime6_explain;
    QPushButton *StartTime7_explain;
    QPushButton *StartTime8_explain;
    QPushButton *StartTime9_explain;
    QPushButton *StartTime10_explain;
    QPushButton *StartTime11_explain;
    QPushButton *StartTime12_explain;
    QPushButton *StartTime13_explain;
    QPushButton *StartTime14_explain;
    QPushButton *StartTime15_explain;
    QPushButton *EndTime_explain;
    QPushButton *EndTime2_explain;
    QPushButton *EndTime3_explain;
    QPushButton *EndTime4_explain;
    QPushButton *EndTime5_explain;
    QPushButton *EndTime6_explain;
    QPushButton *EndTime7_explain;
    QPushButton *EndTime8_explain;
    QPushButton *EndTime9_explain;
    QPushButton *EndTime10_explain;
    QPushButton *EndTime11_explain;
    QPushButton *EndTime12_explain;
    QPushButton *EndTime13_explain;
    QPushButton *EndTime14_explain;
    QPushButton *EndTime15_explain;
    QPushButton *Describe_explain;
    QPushButton *Describe2_explain;
    QPushButton *Describe3_explain;
    QPushButton *Describe4_explain;
    QPushButton *Describe5_explain;
    QPushButton *Describe6_explain;
    QPushButton *Describe7_explain;
    QPushButton *Describe8_explain;
    QPushButton *Describe9_explain;
    QPushButton *Describe10_explain;
    QPushButton *Describe11_explain;
    QPushButton *Describe12_explain;
    QPushButton *Describe13_explain;
    QPushButton *Describe14_explain;
    QPushButton *Describe15_explain;
    /**********************操作日志*************************/
    QPushButton *ModificationTime_explain;
    QPushButton *ModificationTime2_explain;
    QPushButton *ModificationTime3_explain;
    QPushButton *ModificationTime4_explain;
    QPushButton *ModificationTime5_explain;
    QPushButton *ModificationTime6_explain;
    QPushButton *ModificationTime9_explain;
    QPushButton *ModificationTime11_explain;
    QPushButton *ModificationTime12_explain;
    QPushButton *EventRecord_explain;
    QPushButton *EventRecord2_explain;
    QPushButton *EventRecord3_explain;
    QPushButton *EventRecord4_explain;
    QPushButton *EventRecord5_explain;
    QPushButton *EventRecord6_explain;
    QPushButton *EventRecord9_explain;
    QPushButton *EventRecord11_explain;
    QPushButton *EventRecord12_explain;
    /**********************基础参数设置*************************/
    QPushButton *Grid_connected_mode_explain; //并网方式
    QPushButton *Constant_power_explain;      //恒功率
    QPushButton *EMS_Comm_type_explain;       //EMS通讯方式
    QPushButton *EMS_CAN_Protocol_explain;    //EMS CAN 协议
    QPushButton *Control_mode_explain;        //控制模式
    QPushButton *Battery_type_explain;        //电池类型
    QPushButton *BMS_Comm_type_explain;       //电池通信方式
    QPushButton *BAT_manufacturers_explain;   //电池协议

    QPushButton *Grid_connected_mode1_explain;//并网方式--UPS
    QPushButton *Constant_power1_explain;     //恒功率
    QPushButton *EMS_Comm_type1_explain;      //EMS通讯方式
    QPushButton *EMS_CAN_Protocol1_explain;   //EMS CAN 协议
    QPushButton *Control_mode1_explain;       //控制模式
    QPushButton *Battery_type1_explain;       //电池类型
    QPushButton *BMS_Comm_type1_explain;      //电池通信方式
    QPushButton *BAT_manufacturers1_explain;  //电池协议

    QPushButton *Grid_connected_mode2_explain; //并网方式-稳态扩容
    QPushButton *Constant_power2_explain;      //恒功率
    QPushButton *EMS_Comm_type2_explain;       //EMS通讯方式
    QPushButton *EMS_CAN_Protocol2_explain;    //EMS CAN 协议
    QPushButton *Control_mode2_explain;        //控制模式
    QPushButton *Battery_type2_explain;        //电池类型
    QPushButton *BMS_Comm_type2_explain;       //电池通信方式
    QPushButton *BAT_manufacturers2_explain;   //电池协议
    //UPS
    QPushButton *StartSOC_explain;            //启动SOC
    QPushButton *StopSOC_explain;             //停止SOC
    QPushButton *StartCellVol_explain;        //启动单体电压
    QPushButton *StopCellVol_explain;         //停止单体电压
    QPushButton *StartTotalVol_explain;       //启动总压
    QPushButton *StopTotalVol_explain;        //停止总压
    QPushButton *BackupChargingPower_explain; //后备充电功率
    QPushButton *MonthlyCycleDate_explain;    //月循环日期
    //稳态扩容
    QPushButton *DG_Charge_SOC_explain;       //柴发充电SOC
    QPushButton *Grid_Charge_SOC_explain;     //电网充电SOC
    QPushButton *Grid_Capacity_explain;       //电网容量
    QPushButton *Charge_Stop_SOC_explain;     //充电SOC说明
    QPushButton *Disharge_Stop_SOC_explain;   //放电SOC说明
    /***************************电池设置-锂电****************************/
    QPushButton *DOD_OnGrid_explain;                //并网DOD说明
    QPushButton *DOD_OffGrid_explain;               //离网DOD说明
    QPushButton *Charge_Volt_Upper_Limit_explain;   //充电电压上限说明
    QPushButton *Charge_Volt_upper_Limit_delta_explain; //充电电压上限回差说明
    QPushButton *Disc_Volt_lower_Limit_explain;     //放电电压限制说明
    QPushButton *Discharge_Volt_upper_Limit_delta_explain; //放电电压下限回差说明
    QPushButton *Charge_Current_Limit_explain;      //充电电流限制说明
    QPushButton *Discharge_Current_Limit_explain;   //放电电流限制说明
    QPushButton *Gen_turn_off_SOC_explain;          //柴发关闭SOC说明
    QPushButton *Gen_turn_on_SOC_explain;           //柴发开启SOC说明
    QPushButton *ForceCharge_start_explain;         //强充开启说明
    QPushButton *ForceCharge_top_explain;           //强充结束说明
    /***************************电池设置-铅酸****************************/
    QPushButton *Capacity_explain;
    QPushButton *Cell_number_2V_explain;
    QPushButton *Bat_float_vol_explain;
    QPushButton *Bat_filling_vol_explain;
    QPushButton *Charge_limiting_value_explain;
    QPushButton *Discharge_limiting_value_explain;
    QPushButton *Generator_turn_off_SOC_B1_explain;
    QPushButton *Generator_turn_on_SOC_A1_explain;
    QPushButton *Grid_off_EOD_explain;
    QPushButton *Grid_on_EOD_explain;
    QPushButton *Uniform_To_Flushing_current_explain;
    QPushButton *Flushing_To_Uniform_current_explain;
    /***************************自动运行**************************/
    //选择
    QPushButton *Check1_explain,*Check2_explain,*Check3_explain,*Check4_explain,*Check5_explain;
    QPushButton *Check6_explain,*Check7_explain,*Check8_explain,*Check9_explain,*Check10_explain;
    QPushButton *Check11_explain,*Check12_explain,*Check13_explain,*Check14_explain,*Check15_explain;
    QPushButton *Check16_explain,*Check17_explain,*Check18_explain,*Check19_explain,*Check20_explain;
    //开始时间
    QPushButton *Start_T1_explain,*Start_T2_explain,*Start_T3_explain,*Start_T4_explain,*Start_T5_explain;
    QPushButton *Start_T6_explain,*Start_T7_explain,*Start_T8_explain,*Start_T9_explain,*Start_T10_explain;
    QPushButton *Start_T11_explain,*Start_T12_explain,*Start_T13_explain,*Start_T14_explain,*Start_T15_explain;
    QPushButton *Start_T16_explain,*Start_T17_explain,*Start_T18_explain,*Start_T19_explain,*Start_T20_explain;
    //结束时间
    QPushButton *End_T1_explain,*End_T2_explain,*End_T3_explain,*End_T4_explain,*End_T5_explain;
    QPushButton *End_T6_explain,*End_T7_explain,*End_T8_explain,*End_T9_explain,*End_T10_explain;
    QPushButton *End_T11_explain,*End_T12_explain,*End_T13_explain,*End_T14_explain,*End_T15_explain;
    QPushButton *End_T16_explain,*End_T17_explain,*End_T18_explain,*End_T19_explain,*End_T20_explain;
    //状态
    QPushButton *State1_explain,*State2_explain,*State3_explain,*State4_explain,*State5_explain;
    QPushButton *State6_explain,*State7_explain,*State8_explain,*State9_explain,*State10_explain;
    QPushButton *State11_explain,*State12_explain,*State13_explain,*State14_explain,*State15_explain;
    QPushButton *State16_explain,*State17_explain,*State18_explain,*State19_explain,*State20_explain;
    //功率
    QPushButton *Power1_explain,*Power2_explain,*Power3_explain,*Power4_explain,*Power5_explain;
    QPushButton *Power6_explain,*Power7_explain,*Power8_explain,*Power9_explain,*Power10_explain;
    QPushButton *Power11_explain,*Power12_explain,*Power13_explain,*Power14_explain,*Power15_explain;
    QPushButton *Power16_explain,*Power17_explain,*Power18_explain,*Power19_explain,*Power20_explain;
    /*************************功能设置1*************************/
    QPushButton *Power_control_type_explain;    //功率控制类型说明
    QPushButton *Output_reactive_power_mode_explain;  //输出无功方式说明
    QPushButton *Output_reactive_power_explain;  //输出无功功率说明
    QPushButton *Output_power_factor_explain;    //输出功率因素说明
    QPushButton *Constant_voltage_explain; //恒压说明
    QPushButton *Constant_current_explain;  //恒流说明
    QPushButton *Output_power_limit_explain;    //输出功率上限说明
    QPushButton *Machine_number_explain;    //设备号说明
    QPushButton *Parallel_explain;  //并机说明
    QPushButton *Host_Address_explain;  //主机地址说明
    QPushButton *ModbusDeviationAddress_explain;  //Modbus偏移地址说明
    QPushButton *serial_port_2_explain; //串口2说明
    QPushButton *serial_port_3_explain; //串口3说明
    QPushButton *serial_port_4_explain; //串口4说明
    QPushButton *serial_port_5_explain; //串口5说明
    QPushButton *serial_port_6_explain; //串口6说明
    QPushButton *Can_port_1_explain;    //CAN1说明
    QPushButton *Can_port_2_explain;    //CAN2说明
    QPushButton *Language_explain;  //语言说明
    QPushButton *Sounds_explain;    //声音说明
    QPushButton *MeterModel_explain;                //电表型号
    QPushButton *AntiBackflowPowerTolerance_explain;//防逆流功率容差
    QPushButton *BmsComFaultTime_explain;   //BMS通信故障判定时间
    QPushButton *EMSComFaultModel_explain;  //EMS通信故障判定时间
    QPushButton *System_upgrade_explain;    //系统升级说明
    QPushButton *Clear_Data_explain;  //清除数据说明
    QPushButton *Restore_factory_explain;  //恢复出厂说明
    /*************************功能设置2*************************/
    QPushButton *ChargingPowerLimit_explain;//充电功率限制
    QPushButton *DischargingPowerLimit_explain;//放电功率限制
    QPushButton *UserPassPort_explain;  //用户密码说明
    QPushButton *RootPassport_explain;  //超级权限说明
    QPushButton *BackupSetParameters_explain;//备份设置参数
    QPushButton *RestoreBackupSetParameters_explain;//恢复备份设置参数
    /***************************系统参数**************************/
    QPushButton *Change_rate_of_power_explain;  //功率变化率说明
    QPushButton *Grid_frequency_upper_limit_explain;  //电网频率变化范围上限说明
    QPushButton *Grid_frequency_lower_limit_explain;  //电网频率变化范围下限说明
    QPushButton *Vol_protection_upper_limit_explain;  //电压保护范围上限说明
    QPushButton *Vol_protection_lower_limit_explain;  //电压保护范围下限说明
    QPushButton *HVRT_enable_explain;  //高穿使能说明
    QPushButton *LVRT_enable_explain;  //低穿使能说明
    QPushButton *Machine_type_explain;  //机器型号说明
    QPushButton *Machine_capacity_explain;  //机器容量说明
    QPushButton *Output_Fre_grade_explain;  //输出频率等级说明
    QPushButton *Output_vol_level_explain;  //输出电压等级说明
    QPushButton *Converter_side_vol_level_explain;  //逆变电压等级说明(变比)
    QPushButton *Grid_connected_mode_of_Inv_explain;  //逆变器并网方式说明(变流器防逆流)
    QPushButton *PrimaryFrequencyModulationDeadZone_explain;//一次调频死区
    QPushButton *ActiveFrequencyModulationCoefficient_explain;//有功调频系数
    QPushButton *PowerGridRecoveryTime_explain;//电网恢复时间
    QPushButton *Insulation_detection_enable_explain;  //绝缘监测使能说明
    QPushButton *Inertia_enable_explain;  //转动惯量使能说明
    QPushButton *CV_parallel_explain;  //恒压并机说明
    QPushButton *AFD_enable_explain;  //孤岛使能说明
    QPushButton *PrimaryFreq_enable_explain;  //一次调频使能说明
private:


private slots:
//    void updateTimeOut();
    void onTimerOut();  //时间显示
    void My_menuAction(int Index);//菜单选择
    void WordingMode(int Index);//模式切换说明
    void Return(int Index);//返回退出键
    void Account_Change( uint8_t Account_Type );//切换登录信息
    void Home_Click(int Index);//主页控件点击

    void on_UI_MenuBtn_clicked();

    void on_SetNext_bt_clicked();

    void on_SetPrevious_bt_clicked();

    void on_ToLogin_bt_clicked();

    void on_Cancel_bt_clicked();

    void on_SGrid_btn_2_clicked();

    void on_SConverter_btn_2_clicked();

    void on_SLoad_btn_2_clicked();

private:
    Ui::MEGAWin *ui;
    QTimer *timer;
    QTimer *Update_RTData_timer;
    QTime *current_time;
    int LanguageType;   //当前语言
    QTranslator *translator;    //翻译
    int CurrentCheckMode;//当前模式
    int System_Current_Page; //系统当前页
    int Advanced_Current_Page;//高级设置当前页

    QStringList Mode_Str;//模式文本显示列表
    QStringList Mode_title_Str;//当前页面文本显示列表
    QList<QPushButton*>  *TimePeriodButtonList;

    unsigned char Account_Type;//当前登录角色 -- 上电默认未登录
    QButtonGroup *Menu_Group;//菜单控件组
    QButtonGroup *SystemMode_Group;//工作模式控件组
    QButtonGroup *ExitReturn_Group;//返回按钮控件组
    QButtonGroup *HomeClick_Group;//主页点击控件组

};


#endif // MEGAWIN_H
