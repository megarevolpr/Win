#include "faulttableinterface.h"
#include "ui_faulttableinterface.h"

FaultTableInterface::FaultTableInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FaultTableInterface)
{
    ui->setupUi(this);
    RTAlarm();
//    FaultTableInterface::excel_read(ui->tableWidget);

}

FaultTableInterface::~FaultTableInterface()
{
    delete ui;
}

void FaultTableInterface::RTAlarm()
{
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setRowCount(28);
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->verticalHeader()->setVisible(false);//设置垂直头不可见
    ui->tableWidget->setFrameShape(QFrame::NoFrame);//设置无边框
    ui->tableWidget->setShowGrid(true);//设置显示格子
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
    ui->tableWidget->setStyleSheet("selection-background-color:lightblue;");

    ui->tableWidget->setColumnWidth(0,110);
    ui->tableWidget->setColumnWidth(1,85);
    ui->tableWidget->setColumnWidth(2,305);
    ui->tableWidget->setColumnWidth(3,200);
    ui->tableWidget->setColumnWidth(4,250);

    QStringList RTAlarm_Title;
    RTAlarm_Title << tr("Alarm name") << tr("Alarm leve")<< tr("Trigger condition") \
                    << tr("Response action")<< tr("Whether to reset\nautomatically and reset time");
    ui->tableWidget->setHorizontalHeaderLabels(RTAlarm_Title);

//    PCS_Alarm_information_table();  //展示PCS故障信息表
    To_excel_read();
}

//从excel快速读取至tabel表
void FaultTableInterface::To_excel_read()
{
    QFile file("../test.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream f_put(&file);
        f_put.setCodec("UTF-8");

        int row = 0;
        ui->tableWidget->setColumnCount(5);

        while (!f_put.atEnd())
        {
            QStringList word;
            for (int i = 0; i < 6; ++i)
            {
                QString entire = f_put.readLine().trimmed();
                if(i==5)
                {

                }
                else
                {
                    word << entire;
                }
            }

            if (word.size() == 5)
            {
                ui->tableWidget->insertRow(row);
                for (int i = 0; i < 5; ++i)
                {
                    QTableWidgetItem* item = new QTableWidgetItem(word[i]);
                    ui->tableWidget->setItem(row, i, item);
                }
                ui->tableWidget->setRowHeight(row, 100);
                ++row;
            }
        }

        ui->tableWidget->setRowCount(row);
        file.close();
    }
}
//调整控件大小
void FaultTableInterface::resizeEvent(QResizeEvent *event)
{
    int x = this->frameGeometry().width(); //获取ui形成窗口宽度
    int y = this->frameGeometry().height();//获取窗口高度

    ui->tableWidget->setColumnWidth(0,x*0.2);//450\650\150
    ui->tableWidget->setColumnWidth(1,x*0.2);
    ui->tableWidget->setColumnWidth(2,x*0.2);
    ui->tableWidget->setColumnWidth(3,x*0.2);
    ui->tableWidget->setColumnWidth(4,x*0.2);
}
