#ifndef DATABASE_H
#define DATABASE_H

#include <QPushButton>
#include <QTableWidget>
#include <QString>

typedef struct{
    QWidget *parent;
    QPushButton *explain_btn;
    QTableWidget *target_tab;
    int row;
    int column;
    QString value;
    QString explain_title;
    QString specification_text;
}TAB_SPECIFITION;



#endif // SPECIFICATION_H
