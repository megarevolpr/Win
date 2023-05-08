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
#ifndef KEYBOARD_HEX_H
#define KEYBOARD_HEX_H

#include <QDialog>
#include <QtDebug>
#include <QKeyEvent>
#include <QEvent>
#include "led_ctrl.h"

namespace Ui {
class Keyboard_Hex;
}

class Keyboard_Hex : public QDialog
{
    Q_OBJECT

public:
    explicit Keyboard_Hex(QWidget *parent = 0);
    ~Keyboard_Hex();
    bool valid;

    void setText(QString str);
    QString getText();

protected:
//    void changeEvent(QEvent *e);
//    void keyPressEvent(QKeyEvent *e);
    bool eventFilter(QObject *obj, QEvent *event);
signals:

private slots:
    void on_num1Button_clicked();
    void on_num2Button_clicked();
    void on_num3Button_clicked();
    void on_num4Button_clicked();
    void on_num5Button_clicked();
    void on_num6Button_clicked();
    void on_num7Button_clicked();
    void on_num8Button_clicked();
    void on_num9Button_clicked();
    void on_dotButton_clicked();
    void on_num0Button_clicked();
    void on_signButton_clicked();
//    void on_leftButton_clicked();
//    void on_rightButton_clicked();
    void on_backspaceButton_clicked();
    void on_cancelButton_clicked();
    void on_okButton_clicked();

    void on_cancelButton_2_clicked();

    void on_numAButton_clicked();

    void on_numBButton_clicked();

    void on_numCButton_clicked();

    void on_numDButton_clicked();

    void on_numEButton_clicked();

    void on_numFButton_clicked();

private:
    Ui::Keyboard_Hex *ui;
    QString strContent;
    int flag_key;
};

#endif // KEYBOARD_HEX_H
