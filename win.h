#ifndef MEGAWIN_H
#define MEGAWIN_H

#include <QWidget>
#include <QComboBox>
#include <QPair>
#include <QList>
#include <QStandardItemModel>
#include <QTranslator>
#include "Menu.h"
#include "Specification/Specification.h"




#define CTL_STANDBY         0
#define CTL_CP_P            1
#define CTL_CP_NP           2
#define CTL_CC              3
#define CTL_CV              4





namespace Ui {
class MEGAWin;
}

class MEGAWin : public QWidget
{
    Q_OBJECT

public:
    explicit MEGAWin(QWidget *parent = nullptr);
    ~MEGAWin();

        Menu *m_menu;

        /***************************系统设置****************************/
        QPushButton *Grid_connected_mode_explain;//并网方式说明
        Specification *Grid_connected_mode;

        QPushButton *Constant_power_explain;     //功率说明
        Specification *Constant_power;

        QPushButton *Charging_and_discharging_explain;  //充放电说明
        Specification *Charging_and_discharging;

        QPushButton *Work_mode_explain;  //工作模式说明
        Specification *Work_mode;

        QPushButton *Output_power_factor_explain;    //输出功率因素说明
        Specification *Output_power_factor;

        QPushButton *Output_reactive_power_explain;  //输出无功功率说明
        Specification *Output_reactive_power;

        QPushButton *Constant_current_explain;  //恒流说明
        Specification *Constant_current;

        QPushButton *Constant_voltage_explain; //恒压说明
        Specification *Constant_voltage;

        QPushButton *Control_mode_explain;  //控制模式说明
        Specification *Control_mode;

        QPushButton *Machine_number_explain;    //设备号说明
        Specification *Machine_number;

        QPushButton *Parallel_explain;  //并机说明
        Specification *Parallel;

        QPushButton *Unbalance_power_enable_explain;    //功率不平衡使能说明
        Specification *Unbalance_power_enable;

        QPushButton *Phase_A_power_explain;      //A相功率说明
        Specification *Phase_A_power;

        QPushButton *Phase_B_power_explain;      //B相功率说明
        Specification *Phase_B_power;

        QPushButton *Phase_C_power_explain;      //C相功率说明
        Specification *Phase_C_power;
        /***************************电池设置****************************/
        QPushButton *DOD_OnGrid_explain;
        QPushButton *DOD_OffGrid_explain;
        QPushButton *Charge_Vol_Up_Limit_explain;
        QPushButton *Disc_Vol_lower_Limit_explain;
        QPushButton *Charge_Cur_Limit_explain;
        QPushButton *Gen_turn_off_SOC_explain;    //柴发关闭SOC
        QPushButton *Gen_turn_on_SOC_explain;     //柴发开启SOC
        QPushButton *Gen_charge_SOC_explain;      //柴发充电SOC
        QPushButton *Grid_charge_SOC_explain;     //电网充电SOC
        QPushButton *Grid_capacity_explain;       //电网容量
        QPushButton *Turn_on_SOC_explain;
        QPushButton *Turn_off_SOC_explain;
        QPushButton *Turn_on_cell_vol_explain;
        QPushButton *Turn_off_cell_vol_explain;
        QPushButton *Turn_on_total_vol_explain;
        QPushButton *Turn_off_total_vol_explain;
        QPushButton *UPS_charge_power_explain;
        QPushButton *Monthly_cycle_time_explain;

        Specification *DOD_OnGrid;
        Specification *DOD_OffGrid;
        Specification *Charge_Vol_Up_Limit;
        Specification *Disc_Vol_lower_Limit;
        Specification *Charge_Cur_Limit;
        Specification *Gen_turn_off_SOC;    //柴发关闭SOC
        Specification *Gen_turn_on_SOC;     //柴发开启SOC
        Specification *Gen_charge_SOC;      //柴发充电SOC
        Specification *Grid_charge_SOC;     //电网充电SOC
        Specification *Grid_capacity;       //电网容量
        Specification *Turn_on_SOC;
        Specification *Turn_off_SOC;
        Specification *Turn_on_cell_vol;
        Specification *Turn_off_cell_vol;
        Specification *Turn_on_total_vol;
        Specification *Turn_off_total_vol;
        Specification *UPS_charge_power;
        Specification *Monthly_cycle_time;
        /***************************自动运行**************************/
        //选择
        QPushButton *Check1_explain,*Check2_explain,*Check3_explain,*Check4_explain,*Check5_explain, \
                    *Check6_explain,*Check7_explain,*Check8_explain,*Check9_explain,*Check10_explain, \
                    *Check11_explain,*Check12_explain,*Check13_explain,*Check14_explain,*Check15_explain, \
                    *Check16_explain,*Check17_explain,*Check18_explain,*Check19_explain,*Check20_explain;
        Specification *Check1,*Check2,*Check3,*Check4,*Check5,*Check6,*Check7,*Check8,*Check9,*Check10, \
                      *Check11,*Check12,*Check13,*Check14,*Check15,*Check16,*Check17,*Check18,*Check19,*Check20;
        //开始时间
        QPushButton *Start_T1_explain,*Start_T2_explain,*Start_T3_explain,*Start_T4_explain,*Start_T5_explain, \
                    *Start_T6_explain,*Start_T7_explain,*Start_T8_explain,*Start_T9_explain,*Start_T10_explain, \
                    *Start_T11_explain,*Start_T12_explain,*Start_T13_explain,*Start_T14_explain,*Start_T15_explain, \
                    *Start_T16_explain,*Start_T17_explain,*Start_T18_explain,*Start_T19_explain,*Start_T20_explain;
        Specification *Start_T1,*Start_T2,*Start_T3,*Start_T4,*Start_T5,*Start_T6,*Start_T7,*Start_T8,*Start_T9,*Start_T10, \
                      *Start_T11,*Start_T12,*Start_T13,*Start_T14,*Start_T15,*Start_T16,*Start_T17,*Start_T18,*Start_T19,*Start_T20;
        //结束时间
        QPushButton *End_T1_explain,*End_T2_explain,*End_T3_explain,*End_T4_explain,*End_T5_explain, \
                    *End_T6_explain,*End_T7_explain,*End_T8_explain,*End_T9_explain,*End_T10_explain, \
                    *End_T11_explain,*End_T12_explain,*End_T13_explain,*End_T14_explain,*End_T15_explain, \
                    *End_T16_explain,*End_T17_explain,*End_T18_explain,*End_T19_explain,*End_T20_explain;
        Specification *End_T1,*End_T2,*End_T3,*End_T4,*End_T5,*End_T6,*End_T7,*End_T8,*End_T9,*End_T10, \
                      *End_T11,*End_T12,*End_T13,*End_T14,*End_T15,*End_T16,*End_T17,*End_T18,*End_T19,*End_T20;
        //状态
        QPushButton *State1_explain,*State2_explain,*State3_explain,*State4_explain,*State5_explain, \
                    *State6_explain,*State7_explain,*State8_explain,*State9_explain,*State10_explain, \
                    *State11_explain,*State12_explain,*State13_explain,*State14_explain,*State15_explain, \
                    *State16_explain,*State17_explain,*State18_explain,*State19_explain,*State20_explain;
        Specification *State1,*State2,*State3,*State4,*State5,*State6,*State7,*State8,*State9,*State10, \
                      *State11,*State12,*State13,*State14,*State15,*State16,*State17,*State18,*State19,*State20;
        //功率
        QPushButton *Power1_explain,*Power2_explain,*Power3_explain,*Power4_explain,*Power5_explain, \
                    *Power6_explain,*Power7_explain,*Power8_explain,*Power9_explain,*Power10_explain, \
                    *Power11_explain,*Power12_explain,*Power13_explain,*Power14_explain,*Power15_explain,\
                    *Power16_explain,*Power17_explain,*Power18_explain,*Power19_explain,*Power20_explain;
        Specification *Power1,*Power2,*Power3,*Power4,*Power5,*Power6,*Power7,*Power8,*Power9,*Power10, \
                      *Power11,*Power12,*Power13,*Power14,*Power15,*Power16,*Power17,*Power18,*Power19,*Power20;
        /***************************功能设置**************************/
        QPushButton *Battery_type_explain;
        QPushButton *BMS_Comm_type_explain;
        QPushButton *Power_control_type_explain;
        QPushButton *EMS_Comm_type_explain;
        QPushButton *Output_power_limit_explain;
        QPushButton *BAT_protocol_explain;
        QPushButton *Power_Delta_explain;
        QPushButton *Charge_power_limit_explain;
        QPushButton *Discharge_power_limit_explain;
        QPushButton *Charge_Vol_upper_Limit_delta_explain;
        QPushButton *Discharge_Vol_lower_Limit_delta_explain;
        QPushButton *Host_Address_explain;
        QPushButton *serial_port_1_explain;
        QPushButton *serial_port_2_explain;
        QPushButton *serial_port_3_explain;
        QPushButton *serial_port_4_explain;
        QPushButton *serial_port_5_explain;
        QPushButton *Can_port_1_explain;
        QPushButton *Can_port_2_explain;
        QPushButton *ProtocolVersion_explain;
        QPushButton *UserPassPort_explain;
        QPushButton *RootPassport_explain;
        QPushButton *Language_explain;
        QPushButton *System_upgrade_explain;
        QPushButton *Sounds_explain;

        Specification *Battery_type;
        Specification *BMS_Comm_type;
        Specification *Power_control_type;
        Specification *EMS_Comm_type;
        Specification *Output_power_limit;
        Specification *BAT_protocol;
        Specification *Power_Delta;
        Specification *Charge_power_limit;
        Specification *Discharge_power_limit;
        Specification *Charge_Vol_upper_Limit_delta;
        Specification *Discharge_Vol_lower_Limit_delta;
        Specification *Host_Address;
        Specification *serial_port_1;
        Specification *serial_port_2;
        Specification *serial_port_3;
        Specification *serial_port_4;
        Specification *serial_port_5;
        Specification *Can_port_1;
        Specification *Can_port_2;
        Specification *ProtocolVersion;
        Specification *UserPassPort;
        Specification *RootPassport;
        Specification *Language;
        Specification *System_upgrade;
        Specification *Sounds;

        /***************************系统信息**************************/
        QPushButton *Manufacturer_name_explain;
        QPushButton *MonitoringVersion_explain;
        QPushButton *SysProtocol_Version_explain;
        QPushButton *ConverterVersion_explain;
        QPushButton *CPLD_Version_explain;
        QPushButton *SN_explain;

        Specification *Manufacturer_name;
        Specification *MonitoringVersion;
        Specification *SysProtocol_Version;
        Specification *ConverterVersion;
        Specification *CPLD_Version;
        Specification *SN;
        /***************************系统参数**************************/
        QPushButton *Change_rate_of_power_explain;
        QPushButton *Grid_frequency_upper_limit_explain;
        QPushButton *Grid_frequency_lower_limit_explain;
        QPushButton *Vol_protection_upper_limit_explain;
        QPushButton *Vol_protection_lower_limit_explain;
        QPushButton *HVRT_enable_explain;
        QPushButton *LVRT_enable_explain;
        QPushButton *AFD_enable_explain;
        QPushButton *Insulation_detection_enable_explain;
        QPushButton *PrimaryFreq_enable_explain;
        QPushButton *Inertia_enable_explain;
        QPushButton *CV_parallel_explain;
        QPushButton *Machine_type_explain;
        QPushButton *Machine_capacity_explain;
        QPushButton *Output_Fre_grade_explain;
        QPushButton *Output_vol_level_explain;
        QPushButton *Converter_side_vol_level_explain;
        QPushButton *Output_reactive_power_mode_explain;
        QPushButton *Grid_connected_mode_of_Inv_explain;
        QPushButton *Primary_FM_dead_zone_explain;
        QPushButton *PFM_coeff_explain;
        QPushButton *Grid_recover_time_explain;
        QPushButton *DynamicCap_explain;
        QPushButton *Module_Number_explain;
        QPushButton *Restore_factory_explain;
        QPushButton *Clear_Data_explain;

        Specification *Change_rate_of_power;
        Specification *Grid_frequency_upper_limit;
        Specification *Grid_frequency_lower_limit;
        Specification *Vol_protection_upper_limit;
        Specification *Vol_protection_lower_limit;
        Specification *HVRT_enable;
        Specification *LVRT_enable;
        Specification *AFD_enable;
        Specification *Insulation_detection_enable;
        Specification *PrimaryFreq_enable;
        Specification *Inertia_enable;
        Specification *CV_parallel;
        Specification *Machine_type;
        Specification *Machine_capacity;
        Specification *Output_Fre_grade;
        Specification *Output_vol_level;
        Specification *Converter_side_vol_level;
        Specification *Output_reactive_power_mode;
        Specification *Grid_connected_mode_of_Inv;
        Specification *Primary_FM_dead_zone;
        Specification *PFM_coeff;
        Specification *Grid_recover_time;
        Specification *DynamicCap;
        Specification *Module_Number;
        Specification *Restore_factory;
        Specification *Clear_Data;
        /***************************外设**************************/
        QPushButton *DI_1_Enable_explain;
        QPushButton *DI_2_Enable_explain;
        QPushButton *DI_3_Enable_explain;
        QPushButton *DI_4_Enable_explain;
        QPushButton *DI_5_Enable_explain;
        QPushButton *DI_6_Enable_explain;
        QPushButton *DO_1_Enable_explain;
        QPushButton *DO_2_Enable_explain;
        QPushButton *DO_3_Enable_explain;
        QPushButton *DI_1_NC_O_explain;
        QPushButton *DI_2_NC_O_explain;
        QPushButton *DI_3_NC_O_explain;
        QPushButton *DI_4_NC_O_explain;
        QPushButton *DI_5_NC_O_explain;
        QPushButton *DI_6_NC_O_explain;
        QPushButton *DO_1_NC_O_explain;
        QPushButton *DO_2_NC_O_explain;
        QPushButton *DO_3_NC_O_explain;
        QPushButton *DI_1_Action_explain;
        QPushButton *DI_2_Action_explain;
        QPushButton *DI_3_Action_explain;
        QPushButton *DI_4_Action_explain;
        QPushButton *DI_5_Action_explain;
        QPushButton *DI_6_Action_explain;
        QPushButton *DO_1_Action_explain;
        QPushButton *DO_2_Action_explain;
        QPushButton *DO_3_Action_explain;

        Specification *DI_1_Enable;
        Specification *DI_2_Enable;
        Specification *DI_3_Enable;
        Specification *DI_4_Enable;
        Specification *DI_5_Enable;
        Specification *DI_6_Enable;
        Specification *DO_1_Enable;
        Specification *DO_2_Enable;
        Specification *DO_3_Enable;
        Specification *DI_1_NC_O;
        Specification *DI_2_NC_O;
        Specification *DI_3_NC_O;
        Specification *DI_4_NC_O;
        Specification *DI_5_NC_O;
        Specification *DI_6_NC_O;
        Specification *DO_1_NC_O;
        Specification *DO_2_NC_O;
        Specification *DO_3_NC_O;
        Specification *DI_1_Action;
        Specification *DI_2_Action;
        Specification *DI_3_Action;
        Specification *DI_4_Action;
        Specification *DI_5_Action;
        Specification *DI_6_Action;
        Specification *DO_1_Action;
        Specification *DO_2_Action;
        Specification *DO_3_Action;
        /***************************BMS保护**************************/
        QPushButton *DOD_Action_explain;
        QPushButton *Prohibit_charging_Action_explain;
        QPushButton *Prohibit_discharging_Action_explain;
        QPushButton *BMS_warning_Action_explain;
        QPushButton *BMS_alarm_Action_explain;
        QPushButton *BMS_fualt_Action_explain;
        QPushButton *BMS_warning_CP_explain;
        QPushButton *BMS_alarm_CP_explain;
        QPushButton *BMS_fualt_CP_explain;
        QPushButton *BMS_warning_DP_explain;
        QPushButton *BMS_alarm_DP_explain;
        QPushButton *BMS_fualt_DP_explain;

        Specification *DOD_Action;
        Specification *Prohibit_charging_Action;
        Specification *Prohibit_discharging_Action;
        Specification *BMS_warning_Action;
        Specification *BMS_alarm_Action;
        Specification *BMS_fualt_Action;
        Specification *BMS_warning_CP;
        Specification *BMS_alarm_CP;
        Specification *BMS_fualt_CP;
        Specification *BMS_warning_DP;
        Specification *BMS_alarm_DP;
        Specification *BMS_fualt_DP;
        /***************************调试**************************/
        QPushButton *Debug_variable_1_explain;
        QPushButton *Debug_variable_2_explain;
        QPushButton *Debug_variable_3_explain;
        QPushButton *Debug_variable_1_addr_explain;
        QPushButton *Debug_variable_2_addr_explain;
        QPushButton *Debug_variable_3_addr_explain;
        QPushButton *Debug_memery_var_1_explain;
        QPushButton *Debug_memery_var_2_explain;
        QPushButton *Debug_memery_var_3_explain;
        QPushButton *Input_Vol_revise_explain;
        QPushButton *Input_Cur_revise_explain;

        QPushButton *Voltage_1_5_revise_explain;
        QPushButton *Bus_Vol_revise_explain;
        QPushButton *Grid_A_AB_Vol_revise_explain;
        QPushButton *Grid_B_BC_Vol_revise_explain;
        QPushButton *Grid_C_CA_Vol_revise_explain;
        QPushButton *Output_A_Cur_revise_explain;
        QPushButton *Output_B_Cur_revise_explain;
        QPushButton *Output_C_Cur_revise_explain;
        QPushButton *INV_A_Vol_revise_explain;
        QPushButton *INV_B_Vol_revise_explain;
        QPushButton *INV_C_Vol_revise_explain;

        QPushButton *INV_A_ind_Cur_revise_explain;
        QPushButton *INV_B_ind_Cur_revise_explain;
        QPushButton *INV_C_ind_Cur_revise_explain;
        QPushButton *INV_On_off_flag_explain;
        QPushButton *Logic_state_explain;
        QPushButton *INV_flag_explain;
        QPushButton *Grid_flag_explain;
        QPushButton *Grid_protect_flag_explain;
        QPushButton *Bat_flag_explain;
        QPushButton *DC_bus_flag_explain;
        QPushButton *INT_main_flag_explain;
        QPushButton *parallel_signal_explain;

        Specification *Debug_variable_1;
        Specification *Debug_variable_2;
        Specification *Debug_variable_3;
        Specification *Debug_variable_1_addr;
        Specification *Debug_variable_2_addr;
        Specification *Debug_variable_3_addr;
        Specification *Debug_memery_var_1;
        Specification *Debug_memery_var_2;
        Specification *Debug_memery_var_3;
        Specification *Input_Vol_revise;
        Specification *Input_Cur_revise;

        Specification *Voltage_1_5_revise;
        Specification *Bus_Vol_revise;
        Specification *Grid_A_AB_Vol_revise;
        Specification *Grid_B_BC_Vol_revise;
        Specification *Grid_C_CA_Vol_revise;
        Specification *Output_A_Cur_revise;
        Specification *Output_B_Cur_revise;
        Specification *Output_C_Cur_revise;
        Specification *INV_A_Vol_revise;
        Specification *INV_B_Vol_revise;
        Specification *INV_C_Vol_revise;

        Specification *INV_A_ind_Cur_revise;
        Specification *INV_B_ind_Cur_revise;
        Specification *INV_C_ind_Cur_revise;
        Specification *INV_On_off_flag;
        Specification *Logic_state;
        Specification *INV_flag;
        Specification *Grid_flag;
        Specification *Grid_protect_flag;
        Specification *Bat_flag;
        Specification *DC_bus_flag;
        Specification *INT_main_flag;
        Specification *parallel_signal;

        QPushButton *AdvancedSetup_btn;//高级设置入口

        /********************实时数据**************************/
        //变流器
        QPushButton *PCS_vol_AB_explain;
        QPushButton *PCS_vol_BC_explain;
        QPushButton *PCS_vol_CA_explain;
        QPushButton *PCS_cur_A_explain;
        QPushButton *PCS_cur_B_explain;
        QPushButton *PCS_cur_C_explain;
        QPushButton *PCS_act_P_explain;     //有功功率
        QPushButton *PCS_rea_P_explain;     //无功功率
        QPushButton *PCS_par_P_explain;     //视在功率
        QPushButton *PCS_Pf_explain;        //功率因数
        QPushButton *PCS_Bat_vol_explain;   //电池电压
        QPushButton *PCS_Bat_cur_explain;   //电池电流
        QPushButton *PCS_Bat_P_explain;     //电池功率
        QPushButton *PCS_Bus_vol_explain;   //母线电压
        QPushButton *PCS_IGBT_T_explain;    //IGBT温度
        QPushButton *PCS_Env_T_explain;     //环境温度
        //电网
        QPushButton *Grid_vol_AB_explain;     //
        QPushButton *Grid_vol_BC_explain;
        QPushButton *Grid_vol_CA_explain;
        QPushButton *Grid_cur_A_explain;
        QPushButton *Grid_cur_B_explain;
        QPushButton *Grid_cur_C_explain;
        QPushButton *Grid_act_P_explain;     //有功功率
        QPushButton *Grid_rea_P_explain;     //无功功率
        QPushButton *Grid_app_P_explain;     //视在功率
        QPushButton *Grid_fre_explain;
        QPushButton *Grid_Pf_explain;
        //负载
        QPushButton *Load_vol_AB_explain;     //
        QPushButton *Load_vol_BC_explain;
        QPushButton *Load_vol_CA_explain;
        QPushButton *Load_cur_A_explain;
        QPushButton *Load_cur_B_explain;
        QPushButton *Load_cur_C_explain;
        QPushButton *Load_act_P_explain;     //有功功率
        QPushButton *Load_rea_P_explain;     //无功功率
        QPushButton *Load_app_P_explain;     //视在功率
        QPushButton *Load_Pf_explain;

        Specification *PCS_vol_AB;
        Specification *PCS_vol_BC;
        Specification *PCS_vol_CA;
        Specification *PCS_cur_A;
        Specification *PCS_cur_B;
        Specification *PCS_cur_C;
        Specification *PCS_act_P;     //有功功率
        Specification *PCS_rea_P;     //无功功率
        Specification *PCS_par_P;     //视在功率
        Specification *PCS_Pf;        //功率因数
        Specification *PCS_Bat_vol;   //电池电压
        Specification *PCS_Bat_cur;   //电池电流
        Specification *PCS_Bat_P;     //电池功率
        Specification *PCS_Bus_vol;   //母线电压
        Specification *PCS_IGBT_T;    //IGBT温度
        Specification *PCS_Env_T;     //环境温度

        Specification *Grid_vol_AB;     //
        Specification *Grid_vol_BC;
        Specification *Grid_vol_CA;
        Specification *Grid_cur_A;
        Specification *Grid_cur_B;
        Specification *Grid_cur_C;
        Specification *Grid_act_P;     //有功功率
        Specification *Grid_rea_P;     //无功功率
        Specification *Grid_app_P;     //视在功率
        Specification *Grid_fre;
        Specification *Grid_Pf;

        Specification *Load_vol_AB;     //
        Specification *Load_vol_BC;
        Specification *Load_vol_CA;
        Specification *Load_cur_A;
        Specification *Load_cur_B;
        Specification *Load_cur_C;
        Specification *Load_act_P;     //有功功率
        Specification *Load_rea_P;     //无功功率
        Specification *Load_app_P;     //视在功率
        Specification *Load_Pf;
        /********************PCS状态**************************/
        QPushButton *DC_input_Breaker_explain;//直流输入断路器
        QPushButton *DC_Cont_explain;         //直流输入器
        QPushButton *Output_Cont_explain;     //输出接触器
        QPushButton *Output_Breaker_explain;  //输出断路器
        QPushButton *Grid_Cont_explain;       //电网接触器
        QPushButton *Grid_Breaker_explain;    //电网断路器
        QPushButton *MB_Breaker_explain;      //维修旁路
        QPushButton *converter_available_explain;//变流器使能
        QPushButton *DC_Soft_start_explain;         //直流软启动
        QPushButton *converter_status_explain;     //变流器状态
        QPushButton *Reactive_P_Regulation_explain;  //无功调节方式
        QPushButton *LVRT_explain;            //
        QPushButton *Generator_signal_explain;//柴发信号
        QPushButton *Reserve_explain;         //保留位
        QPushButton *Reserve2_explain;     //保留位
        QPushButton *EPO_Cont_signal1_explain;  //EPO节点信号
        QPushButton *EPO_Cont_signal2_explain;       //EPO节点信号
        QPushButton *Access_signal_explain;    //门禁信号
        QPushButton *Full_P_signal_explain;    //满功率信号
        QPushButton *Smoke_alarm_signal_explain;    //烟感信号
        QPushButton *Hight_temp_signal_explain;    //高温信号

        Specification *DC_input_Breaker;//直流输入断路器
        Specification *DC_Cont;         //直流输入器
        Specification *Output_Cont;     //输出接触器
        Specification *Output_Breaker;  //输出断路器
        Specification *Grid_Cont;       //电网接触器
        Specification *Grid_Breaker;    //电网断路器
        Specification *MB_Breaker;      //维修旁路
        Specification *converter_available;//变流器使能
        Specification *DC_Soft_start;         //直流软启动
        Specification *converter_status;     //变流器状态
        Specification *Reactive_P_Regulation;  //无功调节方式
        Specification *Sleep_mode;       //睡眠模式
        Specification *LVRT;            //
        Specification *Generator_signal;//柴发信号
        Specification *Reserve;         //保留位
        Specification *Reserve2;     //保留位
        Specification *EPO_Cont_signal1;  //EPO节点信号
        Specification *EPO_Cont_signal2;       //EPO节点信号
        Specification *Access_signal;    //门禁信号
        Specification *Full_P_signal;    //满功率信号
        Specification *Smoke_alarm_signal;    //烟感信号
        Specification *Hight_temp_signal;    //高温信号
        /**********************历史记录*************************/
        QPushButton *Grade_explain;
        QPushButton *Grade2_explain;
        QPushButton *Grade3_explain;
        QPushButton *Grade4_explain;
        QPushButton *Grade5_explain;
        QPushButton *Grade6_explain;
        QPushButton *Grade7_explain;
        QPushButton *Grade8_explain;
        QPushButton *StartTime_explain;
        QPushButton *StartTime2_explain;
        QPushButton *StartTime3_explain;
        QPushButton *StartTime4_explain;
        QPushButton *StartTime5_explain;
        QPushButton *StartTime6_explain;
        QPushButton *StartTime7_explain;
        QPushButton *StartTime8_explain;
        QPushButton *EndTime_explain;
        QPushButton *EndTime2_explain;
        QPushButton *EndTime3_explain;
        QPushButton *EndTime4_explain;
        QPushButton *EndTime5_explain;
        QPushButton *EndTime6_explain;
        QPushButton *EndTime7_explain;
        QPushButton *EndTime8_explain;
        QPushButton *Describe_explain;
        QPushButton *Describe2_explain;
        QPushButton *Describe3_explain;
        QPushButton *Describe4_explain;
        QPushButton *Describe5_explain;
        QPushButton *Describe6_explain;
        QPushButton *Describe7_explain;
        QPushButton *Describe8_explain;
        Specification *Grade;
        Specification *Grade2;
        Specification *Grade3;
        Specification *Grade4;
        Specification *Grade5;
        Specification *Grade6;
        Specification *Grade7;
        Specification *Grade8;
        Specification *StartTime;
        Specification *StartTime2;
        Specification *StartTime3;
        Specification *StartTime4;
        Specification *StartTime5;
        Specification *StartTime6;
        Specification *StartTime7;
        Specification *StartTime8;
        Specification *EndTime;
        Specification *EndTime2;
        Specification *EndTime3;
        Specification *EndTime4;
        Specification *EndTime5;
        Specification *EndTime6;
        Specification *EndTime7;
        Specification *EndTime8;
        Specification *Describe;
        Specification *Describe2;
        Specification *Describe3;
        Specification *Describe4;
        Specification *Describe5;
        Specification *Describe6;
        Specification *Describe7;
        Specification *Describe8;
        /**********************操作日志*************************/
        QPushButton *ModificationTime_explain;
        QPushButton *ModificationTime2_explain;
        QPushButton *ModificationTime3_explain;
        QPushButton *ModificationTime4_explain;
        QPushButton *ModificationTime5_explain;
        QPushButton *ModificationTime6_explain;
        QPushButton *ModificationTime7_explain;
        QPushButton *ModificationTime8_explain;
        QPushButton *ModificationTime9_explain;
        QPushButton *ModificationTime10_explain;
        QPushButton *ModificationTime11_explain;
        QPushButton *ModificationTime12_explain;
        QPushButton *EventRecord_explain;
        QPushButton *EventRecord2_explain;
        QPushButton *EventRecord3_explain;
        QPushButton *EventRecord4_explain;
        QPushButton *EventRecord5_explain;
        QPushButton *EventRecord6_explain;
        QPushButton *EventRecord7_explain;
        QPushButton *EventRecord8_explain;
        QPushButton *EventRecord9_explain;
        QPushButton *EventRecord10_explain;
        QPushButton *EventRecord11_explain;
        QPushButton *EventRecord12_explain;

        Specification *ModificationTime;
        Specification *ModificationTime2;
        Specification *ModificationTime3;
        Specification *ModificationTime4;
        Specification *ModificationTime5;
        Specification *ModificationTime6;
        Specification *ModificationTime7;
        Specification *ModificationTime8;
        Specification *ModificationTime9;
        Specification *ModificationTime10;
        Specification *ModificationTime11;
        Specification *ModificationTime12;
        Specification *EventRecord;
        Specification *EventRecord2;
        Specification *EventRecord3;
        Specification *EventRecord4;
        Specification *EventRecord5;
        Specification *EventRecord6;
        Specification *EventRecord7;
        Specification *EventRecord8;
        Specification *EventRecord9;
        Specification *EventRecord10;
        Specification *EventRecord11;
        Specification *EventRecord12;


        void UIPageInit();//初始化界面
        void LoadLanguageInit();//初始化语言

        void MemoryAllocation();

        void FirstPage();
        void RunStatePage();

        void SystemSettingPage();//系统设置界面
        void RecordPage();//记录页面

        void LCDSetting();  //LCD标签初始化和定时器设置

        void LinkRelationship();

        void ModuleState_Tab();//实时状态表初始化
        void UserParam_tab();//一般设置表初始化
        void History_tab();//历史记录设置表初始化
        void OperationLog_tab();//操作日志表初始化

        void EquipmentInfor_tab();//设备信息表初始化
        void BatterySet_tab();//电池设置表初始化
        void RunTimeSet_tab();//系统自动运行表初始化


        void PCS_Data_Tab();//PCS数据表
        void Grid_Data_Tab();//电网数据表
        void Load_Data_Tab();//负载数据表
        void RTData_Anologe();//实时模拟量数据
        void RTData_Status();//实时状态量数据
private:
        void History();//历史记录
        void OperationLog();//操作日志
        void RTAlarm(); //告警信息绘表
        void PCS_Data();//PCS数据 绘制button
        void Grid_Data();//电网数据 绘制button
        void Load_Data();//负载数据 绘制button
        void PCS_State();//PCS状态 绘制button
        void ParameterSet();//系统设置 绘制button
        void BetterySetup();//电池设置 绘制button
        void AutoOperation();//自动运行 绘制button
        void SystemMessages();//系统信息 绘制button

        void FunctionSet();//功能设置 绘制button
        void SystemParameter();//系统参数 绘制button
        void Peripheral();//外设 绘制button
        void BMS_Protect();//BMS保护 绘制button
        void Debugg();//调试 绘制button

        void RTDataDisplay();
        void Information_tbnt_released(); //系统信息槽
        void GeneralParam_tbnt_released();  //一般参数槽
        void PCS_Alarm_information_table();  //PCS故障信息表

        void Change_Language(); //切换语言

private slots:
    void onTimerOut();
    void updateTimeOut(); //Fun(Time)
    void My_menuAction(int Index);
    void SystemParam_tbnt_released();

    void on_UI_MenuBtn_clicked();//转到槽
    void on_UI_Complete_Btn_clicked();//退出高级设置

    void on_Running_btn_clicked();//跳转变流器实时数据
    void on_Grid_clicked();//跳转电网实时数据
    void on_Load_clicked();//跳转负载实时数据

    void on_Batt_btn_released();//跳转到电池信息
    void on_Alarm_btn_clicker();//跳转实时告警页面

    void on_SConverter_btn_clicked();//显示变流器实时数据

    void on_SGrid_btn_clicked();//显示电网实时数据

    void on_SLoad_btn_clicked();//显示负载实时数据

    void on_Run_tabWidget_tabBarClicked(int index); //实时数据界面选项卡点击响应

    void AdvancedSetup_btn_clicked();//高级

    void BatteryData_clicked(int nid);//电池数据
    void Data_report_clicked(int nid);//数据报表
    void SystemlnformationVer_clicked(int nid);//系统信息
    void MonitorDebug_clicked(int nid);//监控调试
    void on_radio_static_clicked();

    void on_radio_dhcp_clicked();

    void on_radio_test_data_btn_clicked();

    void on_TimeSeting_btn_clicked();//修改时间

    void on_ChangeLanguage_btn_clicked();

    void on_ChangeLanguage_btn_1_clicked();

    void on_search_btn_clicked();

private:
    Ui::MEGAWin *ui;
    QTimer *timer;
    QTimer *Update_RTData_timer;
    QTime *current_time;
    QButtonGroup *pButton_History;
    QButtonGroup *pButton_BatteryData;
    QButtonGroup *pButton_Version;
    QButtonGroup *pButton_MonitorDebug;
    bool ASKey;//高级设置钥匙
    bool IPShow;//IP地址显示标志位
    QTranslator *translator;
    int LanguageType;
};


#endif // MEGAWIN_H
