#ifndef GRIDEXPANSION_H
#define GRIDEXPANSION_H

#include <QMainWindow>
#include <QWheelEvent>
#include <QShortcut>
#include <QScrollBar>
#include <QPainter>
#include <qdebug.h>

namespace Ui {
class GridExpansion;
}

class GridExpansion : public QMainWindow
{
    Q_OBJECT

//槽函数
private slots:
    void  on_openImageBtn();
    void  on_resetImageBtn();


//事件类函数

    void on_tabWidget_currentChanged(int index);

protected:
   virtual void wheelEvent(QWheelEvent *event) override;    //滚轮事件
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) ;
    void keyReleaseEvent(QKeyEvent *event) override;

    virtual void resizeEvent(QResizeEvent *event)override;//调整控件大小

    void InitializeTable();


public:
    //上述所有的事件只是为了更改如下的变量
    QPixmap srcImage,changeImage;   //原始图像以及缩放后的图像
    float ratio = 1.0;      //缩放的比例

public:
    explicit GridExpansion(QWidget *parent = nullptr);
    ~GridExpansion();

private:
    QPoint preDot,offset;
    bool mousePress = false;//鼠标按压状态

    Ui::GridExpansion *ui;
};

#endif // GRIDEXPANSION_H
