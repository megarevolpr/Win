#ifndef FAULTTABLEINTERFACE_H
#define FAULTTABLEINTERFACE_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <qdebug.h>
#include <QTextStream>//文本流
#include <QIODevice>//I/O设备接口类

namespace Ui {
class FaultTableInterface;
}

class FaultTableInterface : public QMainWindow
{
    Q_OBJECT

public:
    void RTAlarm();
    void To_excel_read();



    explicit FaultTableInterface(QWidget *parent = nullptr);




    ~FaultTableInterface();

private:

    virtual void resizeEvent(QResizeEvent *event)override;//调整控件大小
    Ui::FaultTableInterface *ui;
};

#endif // FAULTTABLEINTERFACE_H
