#ifndef GRIDEXPANSION_H
#define GRIDEXPANSION_H

#include <QMainWindow>
#include <QWheelEvent>
#include <QShortcut>
#include <QScrollBar>
#include <QPainter>
#include <qdebug.h>
#include <QtMath>

#include "Specification/Specification.h"
namespace Ui {
class GridExpansion;
}

class GridExpansion : public QMainWindow
{
    Q_OBJECT

//槽函数
private slots:
    void  on_openImageBtn();


//事件类函数

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

protected:
   virtual void wheelEvent(QWheelEvent *event) override;    //滚轮事件
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) ;
    void keyReleaseEvent(QKeyEvent *event) override;

    virtual void resizeEvent(QResizeEvent *event)override;//调整控件大小

    void InitializeTable();


public:
    QPushButton *Generator_Charging;
    QPushButton *Charging_SOC_of_Grid;
    QPushButton *Charging_Stop_SOC;
    QPushButton *Discharging_Stop_SOC;
    QPushButton *Grid_Capacity;

    Specification *Generator_Charging_explain;
    Specification *Charging_SOC_of_Grid_explain;
    Specification *Charging_Stop_SOC_explain;
    Specification *Discharging_Stop_SOC_explain;
    Specification *Grid_Capacity_explain;

    //上述所有的事件只是为了更改如下的变量
    QPixmap srcImage,changeImage,normal;   //原始图像以及缩放后的图像
    float ratio = 1.0;      //缩放的比例
    float ratio_t;

    int Language;

public:
    explicit GridExpansion(QWidget *parent = nullptr,int LanguageType=0);
    ~GridExpansion();

private:
    QPoint preDot,offset;
    bool mousePress = false;//鼠标按压状态

    Ui::GridExpansion *ui;
};

#endif // GRIDEXPANSION_H
