#ifndef MEGAWIN_H
#define MEGAWIN_H

#include <QWidget>
#include "Menu.h"
#include <QComboBox>

//QComboBox * combox_OutPower;
//QComboBox *combox_ui_ChargeDischar;


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

        QString combox_ui_GridMode_str;
        QComboBox *combox_ui_GridMode;
        QString combox_ui_OnOffGrid_str;
        QStringList ui_OnOff_Grid;
        short combox_ui_OnOffGrid_index;

        Menu *m_menu;

        void GeneralParam_tbnt_released();//一般参数槽
        QComboBox *combox_ui_OnOff_Grid;//并离网
        QPushButton *AdvancedSetup_btn;//高级设置

    ~MEGAWin();

private slots:
//    void combox_OutPower_change();
//    void PasswordLimit();
    void My_menuAction(int Index);
//    bool PasswordCheck();
    void SystemParam_tbnt_released();
    void AdvancedSetup_btn_clicked();
    void LinkRelationship();
    void MemoryAllocation();
    void UIPageInit();//初始化界面
    void combox_ui_GridMode_change();
    void UserParam_tab();//一般设置表初始化
    void SystemSettingPage();//系统设置界面
    void combox_ui_OnOff_Grid_change();//并离网
    void VariableInit();//初始化变量（system_Page）

    void on_UI_MenuBtn_clicked();//转到槽
    void on_UI_Complete_Btn_clicked();
private:
    Ui::MEGAWin *ui;
};

#endif // MEGAWIN_H
