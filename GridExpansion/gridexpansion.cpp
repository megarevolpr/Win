#include "gridexpansion.h"
#include "ui_gridexpansion.h"

GridExpansion::GridExpansion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GridExpansion)
{
    ui->setupUi(this);

    setWindowState(Qt::WindowMaximized); // 最大化



    Generator_Charging = new QPushButton;
    Charging_SOC_of_Grid = new QPushButton;
    Charging_Stop_SOC = new QPushButton;
    Discharging_Stop_SOC = new QPushButton;
    Grid_Capacity = new QPushButton;

    InitializeTable();
}

GridExpansion::~GridExpansion()
{
    delete ui;
}

void GridExpansion::InitializeTable()
{
    ui->tableWidget->verticalHeader()->setVisible(false);//设置垂直头不可见
    ui->tableWidget->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->tableWidget->setShowGrid(true);//设置显示格子
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
    ui->tableWidget->setStyleSheet("selection-background-color:lightblue;");
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    QStringList StateList_Bypass;
    StateList_Bypass << tr("Name") << tr("Value")<< tr("Unit");
    ui->tableWidget->setHorizontalHeaderLabels(StateList_Bypass);


    for(int i=0;i<5;i++)
    {
        ui->tableWidget->setRowHeight(i,50);
    }
    QString str = tr("0");

    Generator_Charging_explain = new Specification(this,Generator_Charging, ui->tableWidget, 0, 1, \
                                    str, tr("Charging SOC of Diesel Generator"), \
                                    tr("Charging SOC of Diesel Generator: In grid expansion mode, when a diesel generator is connected, the battery SOC will charge when it is below this SOC."));
    Generator_Charging_explain->add_Specification();
    Charging_SOC_of_Grid_explain = new Specification(this,Charging_SOC_of_Grid, ui->tableWidget, 1, 1, \
                                    str, tr("Charging SOC of Grid"), \
                                    tr("Charging SOC of Grid: In grid expansion mode, when there is no diesel generator connected, the battery SOC will charge when it is below this SOC."));
    Charging_SOC_of_Grid_explain->add_Specification();
    Charging_Stop_SOC_explain = new Specification(this,Charging_Stop_SOC, ui->tableWidget, 2, 1, \
                                    str, tr("Charging Stop SOC"), \
                                    tr("Charging Stop SOC: In grid expansion mode, when the battery is charging, it will stop charging when the battery SOC is greater than this SOC."));
    Charging_Stop_SOC_explain->add_Specification();
    Discharging_Stop_SOC_explain = new Specification(this,Discharging_Stop_SOC, ui->tableWidget, 3, 1, \
                                    str, tr("Discharging Stop SOC"), \
                                    tr("Discharging Stop SOC: In grid expansion mode, the battery will stop discharging when the battery SOC is below this SOC."));
    Discharging_Stop_SOC_explain->add_Specification();
    Grid_Capacity_explain = new Specification(this,Grid_Capacity, ui->tableWidget, 4, 1, \
                                    str, tr("Grid Capacity"), \
                                    tr("Grid Capacity: The maximum power capacity connected to the grid in grid expansion mode."));
    Grid_Capacity_explain->add_Specification();
}

//加载图像
void GridExpansion::on_openImageBtn()
{
     //设置label为居中显式
     ui->label->setAlignment(Qt::AlignCenter);
     //读取并显示图像
     QImage image("D:/Desktop/WORD/MEGA_code/MEGAWin/Win/UI/电网扩容逻辑图.png");
     image = image.scaled(ui->label->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
     srcImage = QPixmap::fromImage(image);
     //重绘
     ui->label->setPixmap(srcImage);
}

//恢复原图
void GridExpansion::on_resetImageBtn()
{
   ratio = 1;//恢复原始比例
   //重绘
   ui->label->setPixmap(srcImage);
}
//鼠标按键事件
void GridExpansion::mousePressEvent(QMouseEvent *event)
{
    QRect paint = ui->scrollArea->geometry();//记录scrollArea的区域
    if (event->button() == Qt::LeftButton && paint.contains(event->pos()))//如果按的是鼠标左键且在scorllArea范围内
    {
        mousePress = true;
        this->setCursor(Qt::OpenHandCursor);//改变鼠标样式为手
        preDot = event->pos();//记录起点
    }
}
//鼠标移动事件
void GridExpansion::mouseMoveEvent(QMouseEvent *event)
{
    if (mousePress)
    {
        int x = this->frameGeometry().width()-130;
        int y = this->frameGeometry().height();

        //记录scorllArea的横纵滚动条
        QScrollBar *tmph = ui->scrollArea->horizontalScrollBar();
        QScrollBar *tmpv = ui->scrollArea->verticalScrollBar();
        //记录鼠标横纵偏移量
        offset.setX(event->x() - preDot.x());
        offset.setY(event->y() - preDot.y());

        //判断鼠标往哪边移动的，进度条就往哪边动，abs为求绝对值函数

        if (offset.x() > 0 && offset.x() > abs(offset.y()))
        {
            tmph->setValue(tmph->value() - x*0.007);
        }
        else if (offset.x() < 0 && abs(offset.x()) > abs(offset.y()))
        {
            tmph->setValue(tmph->value() + x*0.007);
        }
        else if (offset.y() > 0 && offset.y() > abs(offset.x()))
        {
            tmpv->setValue(tmpv->value() - y*0.007);
        }
        else if (offset.y() < 0 && abs(offset.y()) > abs(offset.x()))
        {
            tmpv->setValue(tmpv->value() + y*0.007);
        }
    }
}
//鼠标松开事件
void GridExpansion::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)//如果松开鼠标左键
        {
            mousePress = false;
            this->setCursor(Qt::ArrowCursor);//恢复鼠标样式为箭头
        }
}

//滚轮事件
void GridExpansion::wheelEvent(QWheelEvent *event)
{
    if (event->modifiers() == Qt::ControlModifier)
    {
        if(event->delta()>0)
        {
           ratio = ratio*1.05;//在当前的比例基础上乘以1.2

        }
        else if(event->delta()<0)
        {
                ratio = ratio*0.95;//在当前的比例基础上乘以0.9
        }
        else
        {
            //不移动鼠标滚轮，什么都不做
            ratio = ratio*1;//在当前的比例不变
        }
         int w = ratio*srcImage.width(); //显示宽度
         int h = ratio*srcImage.height(); //显示高度
         changeImage = srcImage.scaled(w,h); //图像缩放到指定高度和宽度，保持长宽比例
         ui->label->setPixmap(changeImage);

         event->accept();
    }
    //当滚轮远离使用者时：
}
//检测Ctrl键松开情况
void GridExpansion::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Control)
    {
        // Ctrl键被松开
        // 执行app()函数
        on_openImageBtn();//重新加载图片，使其更加清晰
        event->accept();
    }
}
//表格宽度随窗口大小变化
void GridExpansion::resizeEvent(QResizeEvent *event)
{
    int x = this->frameGeometry().width(); //获取ui形成窗口宽度
    int y = this->frameGeometry().height();//获取窗口高度

    ui->tableWidget->setColumnWidth(0,(x/2)*0.4);
    ui->tableWidget->setColumnWidth(1,(x/2)*0.3);
    ui->tableWidget->setColumnWidth(2,(x/2)*0.2);

}
//点击table头 加载图片
void GridExpansion::on_tabWidget_currentChanged(int index)
{
    if(index==1)
    {
        on_openImageBtn();
        normal = srcImage;
    }
    else {

    }
}
//重新加载恢复到标准大小
void GridExpansion::on_pushButton_clicked()
{
    int x = this->frameGeometry().width(); //获取ui形成窗口宽度
    int y = this->frameGeometry().height();//获取窗口高度

    changeImage = srcImage.scaled(x-150,y-20); //图像缩放到指定高度和宽度，保持长宽比例
    ui->label->setPixmap(changeImage);


}

void GridExpansion::on_pushButton_2_clicked()
{
    this->hide();
}
