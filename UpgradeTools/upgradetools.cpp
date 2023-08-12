#include "upgradetools.h"
#include "ui_upgradetools.h"

UpgradeTools::UpgradeTools(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UpgradeTools)
{
    ui->setupUi(this);
    ui->tabWidget->removeTab(0);//将索引号为0的MPS从菜单移除
    Init_MemorySpace();

}


UpgradeTools::~UpgradeTools()
{
    delete ui;
}
//初始化内存空间
void UpgradeTools::Init_MemorySpace()
{
    pButton_Upgrade = new QButtonGroup();
    pButton_Upgrade->addButton(ui->DCDC_btn,0);
    pButton_Upgrade->addButton(ui->DCAC_btn,1);
    pButton_Upgrade->addButton(ui->Monitor_btn,2);
    pButton_Upgrade->addButton(ui->Backup_btn,3);
    pButton_Upgrade->addButton(ui->Restore_btn,4);
    pButton_Upgrade->addButton(ui->Apply_btn,5);
    pButton_Upgrade->addButton(ui->BaudRate_btn,6);
    pButton_Upgrade->addButton(ui->Monitor_btn_2,7);
    pButton_Upgrade->addButton(ui->Backup_btn_2,8);
    pButton_Upgrade->addButton(ui->Restore_btn_2,9);
    pButton_Upgrade->addButton(ui->PCS_btn,10);
    pButton_Upgrade->addButton(ui->Apply_btn_2,11);
    pButton_Upgrade->addButton(ui->Monitor_hex_btn,12);
    pButton_Upgrade->addButton(ui->DSP_hex_btn,13);

    connect(pButton_Upgrade, SIGNAL(buttonClicked(int)), this,SLOT(UpgradeButton_clicked(int)));//电池数据
}
void UpgradeTools::setAppSize(int remainH)
{
    //首先获取屏幕尺寸信息
    QDesktopWidget *deskTopWidget = QApplication::desktop();
    QRect deskRect = deskTopWidget->availableGeometry();

    //设置程序尺寸(我的界面需要适应高度)
//    int titleBarH = style()->pixelMetric(QStyle::PM_TitleBarHeight); 	// 获取标题栏高度(WIndow自带)
    int titleBarH = 0;
    int appH = deskRect.height() - remainH - titleBarH;
    int appW = appH*this->width() / this->height();	//根据软件的宽高比例
    this->setFixedSize(appW, appH);  		//注意：此处设置的高度是不包含标题栏
    setGeometry((deskRect.width() - appW) / 2, remainH / 2 + titleBarH, appW, appH);	//设置程序窗体在桌面的显示位置
}
void UpgradeTools::UpgradeButton_clicked(int nid)
{
    switch (nid) {
    case 0:
        QMessageBox::question(this, tr("DCDC Upgrade")\
                              ,tr("DCDC Upgrade: Insert a u disk and check for the presence of the DCDC upgrade program 'DCDC_Update.hex'. Click on DCDC, and then upgrade the corresponding DCDC module according to the selected module number above.\
                                \n(Note: Before upgrading the DCDC, ensure that the ship mode switch on the DCDC module is set to the OFF position.)"), tr("OK"));
        break;//
    case 1:
        QMessageBox::question(this, tr("DCAC Upgrade")\
                              ,tr("DCAC Upgrade: Insert the u disk and check if there is a DCAC upgrade program called 'DCAC_Update.hex'. Click to upgrade the DCAC.\
                                \n(Note: Press the EPO button before upgrading.)"), tr("OK"));
        break;//。
    case 2:
        QMessageBox::question(this, tr("Monitor")\
                              ,tr("After inserting the u disk and checking that there is a Monitor upgrade program 'Monitor.hex', click to upgrade the monitor program."), tr("OK"));
        break;//在插入U盘并检查到有监控升级程序Monitor.hex后，点击将升级监控程序。
    case 3:
        QMessageBox::question(this, tr("Backup")\
                              ,tr("Backup: Click to backup the current program files."), tr("OK"));
        break;//点击将对升级程序进行备份。
    case 4:
        QMessageBox::question(this, tr("Restore")\
                              ,tr("Restore: Restore to the most recent backup program files."), tr("OK"));
        break;//点击将恢复到已经备份好程序
    case 5:
        {
            int reply = QMessageBox::question(this, tr("Apply and restart")\
                                  ,tr("Click to restart."), tr("Previous Page"),tr("OK"));
            if(reply == 0)
            {
                this->hide();
            }
        }
        break;//点击后将进行重启
    case 6:
        QMessageBox::question(this, tr("Baud Rate")\
                              ,tr("Baud Rate: Default is 500k and cannot be modified."), tr("OK"));
        break;//
    case 7:
        QMessageBox::question(this, tr("Monitor")\
                              ,tr("After inserting the u disk and checking that there is a Monitor upgrade program 'Monitor.hex', click to upgrade the monitor program."), tr("OK"));
        break;
    case 8:
        QMessageBox::question(this, tr("Backup")\
                              ,tr("Backup: Click to backup the current program files."), tr("OK"));
        break;
    case 9:
        QMessageBox::question(this, tr("Restore")\
                              ,tr("Restore: Restore to the most recent backup program files."), tr("OK"));
        break;
    case 10:
        QMessageBox::question(this, tr("DSP Upgrade")\
                              ,tr("DSP Upgrade: Insert the u disk and check if there is a DSP upgrade program called 'DSPUpdate.hex'. Click to upgrade the DSP.\
                                \n(Note: Press the EPO button before upgrading.))"), tr("OK"));
        break;//
    case 11:
        {
            int reply = QMessageBox::question(this, tr("Restart")\
                                  ,tr("Click to restart."), tr("Previous Page"),tr("OK"));
            if(reply == 0)
            {
                this->hide();
            }
        }
        break;
    case 12:
        QMessageBox::question(this, tr("Monitor.hex")\
                              ,tr("This is the name of the monitoring upgrade program."), tr("OK"));
        break;//这是监控升级程序名称。
    case 13:
        QMessageBox::question(this, tr("DSPUpdate.hex")\
                              ,tr("This is the DSP upgrade program name."), tr("OK"));
        break;//这是DSP升级程序名称。
    default:
        break;
    }
}
