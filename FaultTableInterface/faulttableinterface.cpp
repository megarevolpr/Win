#include "faulttableinterface.h"
#include "ui_faulttableinterface.h"

FaultTableInterface::FaultTableInterface(QWidget *parent,int LanguageType) :
    QMainWindow(parent),
    ui(new Ui::FaultTableInterface)
{
    ui->setupUi(this);
    setWindowState(Qt::WindowMaximized); // 最大化
    Language = LanguageType;

    if(Language == 0)
    {
        RTAlarm(QString(":/Fault_Description/DCAC_Fault_Ch.txt"),ui->tableWidget);
        RTAlarm(QString(":/Fault_Description/DCDC_Fault_Ch.txt"),ui->tableWidget_2);
    }
    else {
        RTAlarm(QString(":/Fault_Description/DCAC_Fault.txt"),ui->tableWidget);
        RTAlarm(QString(":/Fault_Description/DCDC_Fault.txt"),ui->tableWidget_2);
    }

    connect(ui->search_le,SIGNAL(editingFinished()), this, SLOT(on_Search_btn_clicked()));//搜索栏关联搜索槽，使LineEdit失去焦点或回车键回车也生效
//    FaultTableInterface::excel_read(ui->tableWidget);

}

FaultTableInterface::~FaultTableInterface()
{
    delete ui;
}
//表格初始化
void FaultTableInterface::RTAlarm(QString path,QTableWidget *myTable)
{
    myTable->setColumnCount(5);
//    myTable->setRowCount(28);
    myTable->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    myTable->verticalHeader()->setVisible(false);//设置垂直头不可见
    myTable->setFrameShape(QFrame::NoFrame);//设置无边框
    myTable->setShowGrid(true);//设置显示格子
    myTable->setSelectionBehavior(QAbstractItemView::SelectItems);//每次选择一行
    myTable->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
    myTable->setStyleSheet("selection-background-color:lightblue;");

    myTable->setColumnWidth(0,110);
    myTable->setColumnWidth(1,85);
    myTable->setColumnWidth(2,305);
    myTable->setColumnWidth(3,200);
    myTable->setColumnWidth(4,250);

    QStringList RTAlarm_Title;
    RTAlarm_Title << tr("Alarm name") << tr("Alarm leve")<< tr("Trigger condition") \
                    << tr("Response action")<< tr("Whether to reset\nautomatically and reset time");
    myTable->setHorizontalHeaderLabels(RTAlarm_Title);

//    PCS_Alarm_information_table();  //展示PCS故障信息表
    To_excel_read(path,myTable);
}

//从excel快速读取至tabel表
void FaultTableInterface::To_excel_read(QString path,QTableWidget *myTable)
{
//    QString path=(":/Fault_Description/DCAC_Fault.txt");
    QFile file(path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream f_put(&file);
        f_put.setCodec("UTF-8");

        int row = 0;
        myTable->setColumnCount(5);

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
                myTable->insertRow(row);//将空行加入到对应的行中
                for (int i = 0; i < 5; ++i)
                {
                    QTableWidgetItem* item = new QTableWidgetItem(word[i]);
                    myTable->setItem(row, i, item);
                    item->setTextAlignment(Qt::AlignCenter);//设置为中间对齐
                }
                myTable->setRowHeight(row, 100);
                ++row;
            }
        }
        myTable->setRowCount(row);
        file.close();
    }
}

void FaultTableInterface::ToSwarch(QTableWidget *myTable)
{
    QString search = ui->search_le->text();
    int row=myTable->rowCount();

    if (search == "")   //判断搜索框是否是空，如果是空就显示所有行
    {
        for(int i=0; i<row; i++)
        {
            myTable->setRowHidden(i,false);
        }
    }
    else
    {
        //通过你输入的和表格里面所有内容进行比对，找到符合条件的索引
        QList <QTableWidgetItem *> item = myTable->findItems(ui->search_le->text(), Qt::MatchContains);

        for(int i=0; i<row; i++)
        {
            myTable->setRowHidden(i,true);//然后把所有行都隐藏
        }

        if(!item.empty())   //判断符合条件索引是不是空
        {
            //恢复对应的行
            for(int i=0; i<item.count(); i++)
            {
                myTable->setRowHidden(item.at(i)->row(),false);//恢复对应的行
            }
        }
    }
}

//void FaultTableInterface::TableSiz()
//{
//    int x = this->frameGeometry().width(); //获取ui形成窗口宽度
//    int y = this->frameGeometry().height();//获取窗口高度

//    ui->tableWidget->setColumnWidth(0,(x-5)*0.2);//450\650\150
//    ui->tableWidget->setColumnWidth(1,(x-5)*0.1);
//    ui->tableWidget->setColumnWidth(2,(x-5)*0.2);
//    ui->tableWidget->setColumnWidth(3,(x-5)*0.2);
//    ui->tableWidget->setColumnWidth(4,(x-5)*0.2);

//    ui->tableWidget_2->setColumnWidth(0,(x-5)*0.2);//450\650\150
//    ui->tableWidget_2->setColumnWidth(1,(x-5)*0.1);
//    ui->tableWidget_2->setColumnWidth(2,(x-5)*0.2);
//    ui->tableWidget_2->setColumnWidth(3,(x-5)*0.2);
//    ui->tableWidget_2->setColumnWidth(4,(x-5)*0.2);
//}

void FaultTableInterface::on_Search_btn_clicked()
{
    ToSwarch(ui->tableWidget);
    ToSwarch(ui->tableWidget_2);
}
//调整控件大小
void FaultTableInterface::resizeEvent(QResizeEvent *event)
{
    int x = this->frameGeometry().width(); //获取ui形成窗口宽度
    int y = this->frameGeometry().height();//获取窗口高度

    ui->tableWidget->setColumnWidth(0,(x-5)*0.2);//450\650\150
    ui->tableWidget->setColumnWidth(1,(x-5)*0.15);
    ui->tableWidget->setColumnWidth(2,(x-5)*0.2);
    ui->tableWidget->setColumnWidth(3,(x-5)*0.2);
    ui->tableWidget->setColumnWidth(4,(x-5)*0.2);

    ui->tableWidget_2->setColumnWidth(0,(x-5)*0.2);//450\650\150
    ui->tableWidget_2->setColumnWidth(1,(x-5)*0.15);
    ui->tableWidget_2->setColumnWidth(2,(x-5)*0.2);
    ui->tableWidget_2->setColumnWidth(3,(x-5)*0.2);
    ui->tableWidget_2->setColumnWidth(4,(x-5)*0.2);
}


//void FaultTableInterface::on_pushButton_clicked()
//{
//    if(Language == 0)
//    {
//        Language = 1;

//        RTAlarm(QString(":/Fault_Description/DCAC_Fault.txt"),ui->tableWidget);
//        RTAlarm(QString(":/Fault_Description/DCDC_Fault.txt"),ui->tableWidget_2);
//    }
//    else {
//        Language = 0;
//        RTAlarm(QString(":/Fault_Description/DCAC_Fault_Ch.txt"),ui->tableWidget);
//        RTAlarm(QString(":/Fault_Description/DCDC_Fault_Ch.txt"),ui->tableWidget_2);
//    }
//    TableSiz();
//}
