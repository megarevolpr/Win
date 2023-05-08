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
#include "numkeyboard.h"
#include "ui_numkeyboard.h"
#include "ui_mywidget.h"
#include "mywidget.h"
#define First 0
#define other 1

extern BUZZER m_buzzer;

NumKeyboard::NumKeyboard(QWidget *parent) :
    QDialog(parent,Qt::WindowTitleHint | Qt::CustomizeWindowHint),//QDialog(parent),
    ui(new Ui::NumKeyboard)
{
    ui->setupUi(this);
//    Qt::WindowFlags flags = Qt::Dialog;
//    flags |= Qt::WindowCloseButtonHint;
//    setWindowFlags(flags);

//    setWindowFlags(Qt::WindowTitleHint | Qt::CustomizeWindowHint);
//    setWindowFlags(Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);

    flag_key = First;

//    ui->lineEdit->setEchoMode(QLineEdit::Password);
    this->setWindowTitle(tr("NumberKeyBoard"));
    strContent = "";
    ui->lineEdit->setText(strContent);
    ui->lineEdit->setFocus();

//    ui->lineEdit->installEventFilter(this);
//    ui->backspaceButton->installEventFilter(this);
//    ui->cancelButton->installEventFilter(this);
//    ui->dotButton->installEventFilter(this);
////    ui->leftButton->installEventFilter(this);
//    ui->num0Button->installEventFilter(this);
//    ui->num1Button->installEventFilter(this);
//    ui->num2Button->installEventFilter(this);
//    ui->num3Button->installEventFilter(this);
//    ui->num4Button->installEventFilter(this);
//    ui->num5Button->installEventFilter(this);
//    ui->num6Button->installEventFilter(this);
//    ui->num7Button->installEventFilter(this);
//    ui->num8Button->installEventFilter(this);
//    ui->num9Button->installEventFilter(this);
//    ui->numAButton->installEventFilter(this);
//    ui->numBButton->installEventFilter(this);
//    ui->numCButton->installEventFilter(this);
//    ui->numDButton->installEventFilter(this);
//    ui->numEButton->installEventFilter(this);
//    ui->numFButton->installEventFilter(this);
//    ui->cancelButton_2->installEventFilter(this);
//    ui->okButton->installEventFilter(this);
//    ui->rightButton->installEventFilter(this);
//    ui->signButton->installEventFilter(this);
}

NumKeyboard::~NumKeyboard()
{
    delete ui;
}

bool NumKeyboard::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
    {
        usleep(150000L);
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            if (obj == ui->lineEdit)
            {
                if(keyEvent->key() >= 0x20 && keyEvent->key()<= 0x0ff)  //屏蔽所有按键输入
                    return true;
                else
                    return false;
            }
            else
            {
                return false;
            }
        }
    }
//    else if(event->type() == QEvent::MouseButtonPress)
//    {
//        m_buzzer.Control(IOCTL_BUZZER_ON);
//    }
//    else if(event->type() == QEvent::MouseButtonRelease)
//    {
//        m_buzzer.Control(IOCTL_BUZZER_OFF);
//    }
    // standard event processing
    return QObject::eventFilter(obj, event);
}



//***********************按键*****************************//
void NumKeyboard::on_num1Button_clicked()       //1
{
    if(flag_key == First)
    {
        ui->lineEdit->setCursorPosition(0);
        strContent = "";
        flag_key = other;
    }
    int idx = ui->lineEdit->cursorPosition();
//    if(strContent.left(idx) == "0")
//    {
//        ui->lineEdit->setCursorPosition(idx);
//        ui->lineEdit->setFocus();
//        return;
//    }
    strContent.insert(idx, '1');
    ui->lineEdit->setText(strContent);
    ui->lineEdit->setCursorPosition(idx+1);
    ui->lineEdit->setFocus();
}

void NumKeyboard::on_num2Button_clicked()       //2
{
    if(flag_key == First)
    {
        ui->lineEdit->setCursorPosition(0);
        strContent = "";
        flag_key = other;
    }
    int idx = ui->lineEdit->cursorPosition();
//    if(strContent.left(idx) == "0")
//    {
//        ui->lineEdit->setCursorPosition(idx);
//        ui->lineEdit->setFocus();
//        return;
//    }
    strContent.insert(idx, '2');
    ui->lineEdit->setText(strContent);
    ui->lineEdit->setCursorPosition(idx+1);
    ui->lineEdit->setFocus();
}

void NumKeyboard::on_num3Button_clicked()       //3
{
    if(flag_key == First)
    {
        ui->lineEdit->setCursorPosition(0);
        strContent = "";
        flag_key = other;
    }
    int idx = ui->lineEdit->cursorPosition();
//    if(strContent.left(idx) == "0")
//    {
//        ui->lineEdit->setCursorPosition(idx);
//        ui->lineEdit->setFocus();
//        return;
//    }
    strContent.insert(idx, '3');
    ui->lineEdit->setText(strContent);
    ui->lineEdit->setCursorPosition(idx+1);
    ui->lineEdit->setFocus();
}

void NumKeyboard::on_num4Button_clicked()       //4
{
    if(flag_key == First)
    {
        ui->lineEdit->setCursorPosition(0);
        strContent = "";
        flag_key = other;
    }
    int idx = ui->lineEdit->cursorPosition();
//    if(strContent.left(idx) == "0")
//    {
//        ui->lineEdit->setCursorPosition(idx);
//        ui->lineEdit->setFocus();
//        return;
//    }
    strContent.insert(idx, '4');
    ui->lineEdit->setText(strContent);
    ui->lineEdit->setCursorPosition(idx+1);
    ui->lineEdit->setFocus();
}

void NumKeyboard::on_num5Button_clicked()       //5
{
    if(flag_key == First)
    {
        ui->lineEdit->setCursorPosition(0);
        strContent = "";
        flag_key = other;
    }
    int idx = ui->lineEdit->cursorPosition();
//    if(strContent.left(idx) == "0")
//    {
//        ui->lineEdit->setCursorPosition(idx);
//        ui->lineEdit->setFocus();
//        return;
//    }
    strContent.insert(idx, '5');
    ui->lineEdit->setText(strContent);
    ui->lineEdit->setCursorPosition(idx+1);
    ui->lineEdit->setFocus();
}

void NumKeyboard::on_num6Button_clicked()       //6
{
    if(flag_key == First)
    {
        ui->lineEdit->setCursorPosition(0);
        strContent = "";
        flag_key = other;
    }
    int idx = ui->lineEdit->cursorPosition();
//    if(strContent.left(idx) == "0")
//    {
//        ui->lineEdit->setCursorPosition(idx);
//        ui->lineEdit->setFocus();
//        return;
//    }
    strContent.insert(idx, '6');
    ui->lineEdit->setText(strContent);
    ui->lineEdit->setCursorPosition(idx+1);
    ui->lineEdit->setFocus();
}

void NumKeyboard::on_num7Button_clicked()       //7
{
    if(flag_key == First)
    {
        ui->lineEdit->setCursorPosition(0);
        strContent = "";
        flag_key = other;
    }
    int idx = ui->lineEdit->cursorPosition();
//    if(strContent.left(idx) == "0")
//    {
//        ui->lineEdit->setCursorPosition(idx);
//        ui->lineEdit->setFocus();
//        return;
//    }
    strContent.insert(idx, '7');
    ui->lineEdit->setText(strContent);
    ui->lineEdit->setCursorPosition(idx+1);
    ui->lineEdit->setFocus();
}

void NumKeyboard::on_num8Button_clicked()       //8
{
    if(flag_key == First)
    {
        ui->lineEdit->setCursorPosition(0);
        strContent = "";
        flag_key = other;
    }
    int idx = ui->lineEdit->cursorPosition();
//    if(strContent.left(idx) == "0")
//    {
//        ui->lineEdit->setCursorPosition(idx);
//        ui->lineEdit->setFocus();
//        return;
//    }
    strContent.insert(idx, '8');
    ui->lineEdit->setText(strContent);
    ui->lineEdit->setCursorPosition(idx+1);
    ui->lineEdit->setFocus();
}

void NumKeyboard::on_num9Button_clicked()       //9
{
    if(flag_key == First)
    {
        ui->lineEdit->setCursorPosition(0);
        strContent = "";
        flag_key = other;
    }
    int idx = ui->lineEdit->cursorPosition();
//    if(strContent.left(idx) == "0")
//    {
//        ui->lineEdit->setCursorPosition(idx);
//        ui->lineEdit->setFocus();
//        return;
//    }
    strContent.insert(idx, '9');
    ui->lineEdit->setText(strContent);
    ui->lineEdit->setCursorPosition(idx+1);
    ui->lineEdit->setFocus();
}

void NumKeyboard::on_dotButton_clicked()        //.
{
    if(flag_key == First)
    {
        ui->lineEdit->setCursorPosition(0);
        strContent = "";
        flag_key = other;
    }
    int idx = ui->lineEdit->cursorPosition();

    if(idx==0 || strContent.contains('.'))
    {
        ui->lineEdit->setCursorPosition(idx);
        ui->lineEdit->setFocus();
        return;
    }

    strContent.insert(idx, '.');
    ui->lineEdit->setText(strContent);
    ui->lineEdit->setCursorPosition(idx+1);
    ui->lineEdit->setFocus();
}

void NumKeyboard::on_cancelButton_2_clicked() // :
{
    if(flag_key == First)
    {
        ui->lineEdit->setCursorPosition(0);
        strContent = "";
        flag_key = other;
    }
    int idx = ui->lineEdit->cursorPosition();
//    if(strContent.left(idx) == "0")
//    {
//        ui->lineEdit->setCursorPosition(idx);
//        ui->lineEdit->setFocus();
//        return;
//    }
    strContent.insert(idx, ':');
    ui->lineEdit->setText(strContent);
    ui->lineEdit->setCursorPosition(idx+1);
    ui->lineEdit->setFocus();
}

void NumKeyboard::on_num0Button_clicked()       //0
{
    if(flag_key == First)
    {
        ui->lineEdit->setCursorPosition(0);
        strContent = "";
        flag_key = other;
    }
    int idx = ui->lineEdit->cursorPosition();
//    if(strContent.left(idx) == "0" || (idx==0 &&strContent!=""))
//    {
//        ui->lineEdit->setCursorPosition(idx);
//        ui->lineEdit->setFocus();
//        return;
//    }
    strContent.insert(idx, '0');
    ui->lineEdit->setText(strContent);
    ui->lineEdit->setCursorPosition(idx+1);
    ui->lineEdit->setFocus();
}

//void NumKeyboard::on_numAButton_clicked()   //     A
//{
//    if(flag_key == First)
//    {
//        ui->lineEdit->setCursorPosition(0);
//        strContent = "";
//        flag_key = other;
//    }
//    int idx = ui->lineEdit->cursorPosition();
//    strContent.insert(idx, 'A');
//    ui->lineEdit->setText(strContent);
//    ui->lineEdit->setCursorPosition(idx+1);
//    ui->lineEdit->setFocus();
//}

//void NumKeyboard::on_numBButton_clicked()//     B
//{
//    if(flag_key == First)
//    {
//        ui->lineEdit->setCursorPosition(0);
//        strContent = "";
//        flag_key = other;
//    }
//    int idx = ui->lineEdit->cursorPosition();
//    strContent.insert(idx, 'B');
//    ui->lineEdit->setText(strContent);
//    ui->lineEdit->setCursorPosition(idx+1);
//    ui->lineEdit->setFocus();
//}

//void NumKeyboard::on_numCButton_clicked()// c
//{
//    if(flag_key == First)
//    {
//        ui->lineEdit->setCursorPosition(0);
//        strContent = "";
//        flag_key = other;
//    }
//    int idx = ui->lineEdit->cursorPosition();
//    strContent.insert(idx, 'C');
//    ui->lineEdit->setText(strContent);
//    ui->lineEdit->setCursorPosition(idx+1);
//    ui->lineEdit->setFocus();
//}

//void NumKeyboard::on_numDButton_clicked()//D
//{
//    if(flag_key == First)
//    {
//        ui->lineEdit->setCursorPosition(0);
//        strContent = "";
//        flag_key = other;
//    }
//    int idx = ui->lineEdit->cursorPosition();
//    strContent.insert(idx, 'D');
//    ui->lineEdit->setText(strContent);
//    ui->lineEdit->setCursorPosition(idx+1);
//    ui->lineEdit->setFocus();
//}

//void NumKeyboard::on_numEButton_clicked()//E
//{
//    if(flag_key == First)
//    {
//        ui->lineEdit->setCursorPosition(0);
//        strContent = "";
//        flag_key = other;
//    }
//    int idx = ui->lineEdit->cursorPosition();
//    strContent.insert(idx, 'E');
//    ui->lineEdit->setText(strContent);
//    ui->lineEdit->setCursorPosition(idx+1);
//    ui->lineEdit->setFocus();
//}

//void NumKeyboard::on_numFButton_clicked()//F
//{
//    if(flag_key == First)
//    {
//        ui->lineEdit->setCursorPosition(0);
//        strContent = "";
//        flag_key = other;
//    }
//    int idx = ui->lineEdit->cursorPosition();
//    strContent.insert(idx, 'F');
//    ui->lineEdit->setText(strContent);
//    ui->lineEdit->setCursorPosition(idx+1);
//    ui->lineEdit->setFocus();
//}

void NumKeyboard::on_signButton_clicked()       //+/-
{
    if(flag_key == First)
    {
        ui->lineEdit->setCursorPosition(0);
        strContent = "";
        flag_key = other;
    }
    int idx = ui->lineEdit->cursorPosition();
//    if(strContent.left(1) == "-")
//    {
//        strContent.remove(0, 1);
//        ui->lineEdit->setText(strContent);
//        ui->lineEdit->setCursorPosition(idx-1);
//        ui->lineEdit->setFocus();
//    }
//    else
//    {
//        if(strContent=="0" || strContent=="")
//        {
//            ui->lineEdit->setCursorPosition(idx);
//            ui->lineEdit->setFocus();
//        }
//        else
//        {
            strContent.insert(0, '-');
            ui->lineEdit->setText(strContent);
            ui->lineEdit->setCursorPosition(idx+1);
            ui->lineEdit->setFocus();
//        }
//    }
}

//void NumKeyboard::on_leftButton_clicked()       //left
//{
//    int idx = ui->lineEdit->cursorPosition();
//    if(idx == 0)
//    {
//        ui->lineEdit->setCursorPosition(idx);
//        ui->lineEdit->setFocus();
//        return;
//    }
//    ui->lineEdit->setCursorPosition(idx-1);
//    ui->lineEdit->setFocus();
//}

//void NumKeyboard::on_rightButton_clicked()      //right
//{
//    int idx = ui->lineEdit->cursorPosition();
//    if(idx == strContent.length())
//    {
//        ui->lineEdit->setCursorPosition(idx);
//        ui->lineEdit->setFocus();
//        return;
//    }
//    ui->lineEdit->setCursorPosition(idx+1);
//    ui->lineEdit->setFocus();
//}

void NumKeyboard::on_backspaceButton_clicked()      //backspace
{
    flag_key = other;
    int idx = ui->lineEdit->cursorPosition();
    if(idx == 0)
    {
        ui->lineEdit->setCursorPosition(idx);
        ui->lineEdit->setFocus();
        return;
    }
    strContent.remove(idx - 1, 1);
    ui->lineEdit->setText(strContent);
    ui->lineEdit->setCursorPosition(idx - 1);
    ui->lineEdit->setFocus();
}

void NumKeyboard::on_cancelButton_clicked()     //cancel
{
    ui->lineEdit->clear();    
    valid = false;
    flag_key = First;
    this->close();
}

void NumKeyboard::on_okButton_clicked()         //ok
{  
    valid = true;
    flag_key = First;
    ui->lineEdit->clear();
    this->close();
}

void NumKeyboard::setText(QString str)      //设置文本内容
{
    strContent = str;
    ui->lineEdit->setText(strContent);
    ui->lineEdit->setFocus();
}

QString NumKeyboard::getText()              //获取内容
{
    return strContent;
}

//void NumKeyboard::keyPressEvent(QKeyEvent *e)
//{
//    if(e->type() == QKeyEvent::Close)
//        this->close();
//}
