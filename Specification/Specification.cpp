#include "Specification.h"
#include <QWidget>
#include <QMessageBox>

Specification::Specification(QPushButton *explain_btn, QTableWidget *target_tab,
                                int row, int column, QString value, QString title, QString text)
{
    target_tab->setCellWidget(row, column, (QWidget *)(explain_btn));

    connect(explain_btn,SIGNAL(clicked(bool)), this, SLOT(explain_btn_clicked()));

    explain_btn->setText(value);
    explain_title = title;
    specification_text = text;
}

Specification::~Specification()
{
//    disconnect(explain_btn,SIGNAL(clicked(bool)), this, SLOT(explain_btn_clicked()));
}

void Specification::explain_btn_clicked()
{
    QMessageBox::about(this, explain_title, specification_text);
}

