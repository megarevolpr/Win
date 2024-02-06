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

#include "Menu.h"
#include "Specification/Specification.h"
#include "upgradetools.h"
#include "GridExpansion.h"
#include "FaultTableInterface.h"

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

    void PCS_DataTableInit();//实时数据-表格初始化
    void PCS_StateTableInit();//实时状态-表格初始化
    void History();//历史记录-表格初始化
    void OperationLog();//操作日志-表格初始化
    void WorkingModeInit();//工作模式-表格初始化


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

    unsigned char Account_Type;//当前登录角色 -- 上电默认未登录
    QButtonGroup *Menu_Group;//菜单控件组
    QButtonGroup *SystemMode_Group;//工作模式控件组
    QButtonGroup *ExitReturn_Group;//返回按钮控件组
    QButtonGroup *HomeClick_Group;//主页点击控件组

};


#endif // MEGAWIN_H
