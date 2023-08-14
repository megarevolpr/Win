#ifndef FAULTTABLEINTERFACE_H
#define FAULTTABLEINTERFACE_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <qdebug.h>
#include <QTextStream>//文本流
#include <QIODevice>//I/O设备接口类
#include <QTableWidget>



namespace Ui {
class FaultTableInterface;
}

class FaultTableInterface : public QMainWindow
{
    Q_OBJECT

public:
    void RTAlarm(QString path,QTableWidget *myTable);
    void To_excel_read(QString path,QTableWidget *tablewidget);
    void ToSwarch(QTableWidget *tablewidget);
//    void TableSiz();



    explicit FaultTableInterface(QWidget *parent = nullptr,int LanguageType=0);



    int Language=0;
    ~FaultTableInterface();

private slots:
    void on_Search_btn_clicked();

//    void on_pushButton_clicked();

private:

    virtual void resizeEvent(QResizeEvent *event)override;//调整控件大小
    Ui::FaultTableInterface *ui;
};

#endif // FAULTTABLEINTERFACE_H
