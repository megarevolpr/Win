#include "Specification.h"
#include <QWidget>
#include <QMessageBox>
#include <win.h>

Specification::Specification(QWidget *parent,QPushButton *button, QTableWidget *tableWidget,
                             int r, int col, QString val, QString title, QString text)
{
    tab.parent = parent;
    tab.explain_btn = button;
    tab.target_tab = tableWidget;
    tab.row = r;
    tab.column = col;
    tab.value = val;
    tab.explain_title = title;
    tab.specification_text = text;

    connect(tab.explain_btn,SIGNAL(clicked(bool)), this, SLOT(explain_btn_clicked()));
}

Specification::~Specification()
{
    disconnect(tab.explain_btn,SIGNAL(clicked(bool)), this, SLOT(explain_btn_clicked()));
}

/*****************添加说明*****************/
void Specification::add_Specification()
{
    tab.explain_btn->setText(tab.value);
    tab.target_tab->setCellWidget(tab.row, tab.column, (QWidget *)tab.explain_btn);
}

void Specification::explain_btn_clicked()
{
    QMessageBox::question(tab.parent , tab.explain_title, tab.specification_text, "OK");
}

