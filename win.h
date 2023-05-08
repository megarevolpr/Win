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
    ~MEGAWin();

private slots:
//    void combox_OutPower_change();
//    void PasswordLimit();
    void My_menuAction(int Index);
    void on_UI_MenuBtn_clicked();

private:
    Ui::MEGAWin *ui;
};

#endif // MEGAWIN_H
