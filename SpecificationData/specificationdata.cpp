#include "specificationdata.h"
#include <QWidget>
#include <QMessageBox>

SpecificationData::SpecificationData(QWidget *parent)
{
    mainparent = parent;
    MyConnection = new QList<QMetaObject::Connection>;
    font = new QFont("Courier New", -1, QFont::Bold);
}

void SpecificationData::add_SpecificationData(QPushButton *button, QTableWidget *tableWidget, int row, int column, QString value, QString title, QString text)
{
    button->setText(value);
//    button->setFont(*font);
    tableWidget->setCellWidget(row, column, (QWidget *)button);

    // 将对话框内容作为值存储在 QMap 中
    QString specificationValue = QString("%1#newline#%2").arg(title, text);

    //添加悬浮解释
    button->setToolTip(title);

    // 插入键值对到 QMap 中
    specificationMap.insert(button, specificationValue);

    QWidget *temp_parent = mainparent;
    // 关联按钮的点击信号与槽函数
    QMetaObject::Connection new_connection = connect(button, &QPushButton::clicked,
            [temp_parent, button, this]()
    {
        QString specificationValue = specificationMap.value(button);
        int index = specificationValue.indexOf("#newline#"); // 获取第一个换行符的索引位置
        specificationValue.replace("#newline#", "    ");
        QString title = specificationValue.left(index); // 获取索引位置之前的部分作为标题
        QString text = specificationValue.mid(index + 1);
        QMessageBox::question(temp_parent,title , text, tr("OK"));
    }
    );
    MyConnection->append(new_connection);
}

SpecificationData::~SpecificationData()
{
    // 在析构函数中释放所有连接
    // 枚举链表MyConnection中的各个连接对象，并赋值给 MyConnection
    for (QMetaObject::Connection connection : *MyConnection)
    {
        QObject::disconnect(connection);
    }
    // 删除链表对象
    delete MyConnection;
}
