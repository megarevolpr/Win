#include "Specification.h"
#include <QWidget>
#include <QMessageBox>
#include <win.h>

Specification::Specification(QPushButton *button, QTableWidget *tableWidget,
                             int r, int col, QString val, QString title, QString text)
{
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

void Specification::add_Specifition()
{
    tab.explain_btn->setText(tab.value);
    tab.target_tab->setCellWidget(tab.row, tab.column, (QWidget *)tab.explain_btn);
}

void Specification::explain_btn_clicked()
{
    QMessageBox::question(this , tab.explain_title, tab.specification_text, "OK");
}

