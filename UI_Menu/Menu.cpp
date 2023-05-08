/*=================================================================================*
*
*                  ___====-_  _-====___
*            _--^^^#####//      \\#####^^^--_
*         _-^##########// (    ) \\##########^-_
*        -############//  |\^^/|  \\############-
*      _/############//   (@::@)   \\############\_
*     /#############((     \\//     ))#############\
*    -###############\\    (oo)    //###############-
*   -#################\\  / VV \  //#################-
*  -###################\\/      \//###################-
* _#/|##########/\######(   /\   )######/\##########|\#_
* |/ |#/\#/\#/\/  \#/\##\  |  |  /##/\#/  \/\#/\#/\#| \|
* `  |/  V  V  `   V  \#\| |  | |/#/  V   '  V  V  \|  '
*    `   `  `      `   / | |  | | \   '      '  '   '
*                     (  | |  | |  )
*                    __\ | |  | | /__
*                   (vvv(VVV)(VVV)vvv)
*
*
*
*	PRODUCT  : MEGA-PCS
*	FILENAME : Energy.cpp
*	PURPOSE	:  电能管理模块
*
*  HISTORY :
*		DATE            VERSION        AUTHOR            NOTE
*	2019-05-29			V1.0		   Laoss			created
*
*	NOTE    :
*=================================================================================*/

#include "Menu.h"
#include "ui_Menu.h"


Menu::Menu(QWidget *parent)  :
    QDialog(parent,Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::FramelessWindowHint),//QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    this->setGeometry(0, 43, 250, 383);
    ui->Host_bt->installEventFilter(this);//事件过滤器
    ui->RTDATA_bt->installEventFilter(this);
    ui->Record_bt->installEventFilter(this);
    ui->System_bt->installEventFilter(this);
    ui->Open_bt->installEventFilter(this);
    ui->Standby_bt->installEventFilter(this);
//    ui->Close_bt->installEventFilter(this);
    installEventFilter(this);
}

Menu::~Menu()
{
    delete ui;
}

bool Menu::eventFilter(QObject *o, QEvent *e)//接受或拒绝拦截到的事件，返回false继续处理，返回true结束处理
{
    if (e->type() == QEvent::ActivationChange)
    {
        if(QApplication::activeWindow() != this)
        {
            if(!this->isHidden())
            {
                this->hide();
            }
        }
    }
    return QWidget::eventFilter(o,e);
}

void Menu::focusOutEvent(QFocusEvent *e)
{
    if(!this->isHidden())
    {
       this->hide();
    }
    Q_UNUSED(e);
}

void Menu::on_Host_bt_clicked()
{
    emit Sent(HOSTPAGE);
    if(!this->isHidden())
    {
        this->hide();
    }
}

void Menu::on_RTDATA_bt_clicked()
{
    emit Sent(RTDATAPAGE);
    if(!this->isHidden())
    {
        this->hide();
    }
}

void Menu::on_Record_bt_clicked()
{
    emit Sent(RECORDPAGE);
    if(!this->isHidden())
    {
        this->hide();
    }
}

void Menu::on_System_bt_clicked()
{
    emit Sent(SYSTEMPAGE);
    if(!this->isHidden())
    {
        this->hide();
    }
}

void Menu::on_Open_bt_clicked()
{
    emit Sent(MACHINEOPEN);
    //emit Sent(MACHINESWITCH);
    if(!this->isHidden())
    {
        this->hide();
    }
}

void Menu::on_Standby_bt_clicked()
{
    emit Sent(MACHINESTANDBY);
    if(!this->isHidden())
    {
        this->hide();
    }
}

void Menu::on_Close_bt_clicked()
{
    emit Sent(MACHINECLOSE);
    if(!this->isHidden())
    {
        this->hide();
    }
}


/******************************
 * 重写鼠标事件
 * 实现点击后有声光
 *
 *
 ******************************/
void Menu::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
            //Control(IOCTL_BUZZER_ON);
    }

}
void Menu::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
            //Control(IOCTL_BUZZER_OFF);
    }
}
