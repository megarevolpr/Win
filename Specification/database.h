#ifndef DATABASE_H
#define DATABASE_H

#include <QPushButton>
#include <QTableWidget>
#include <QString>

typedef struct{
    QPushButton *explain_btn;
    QTableWidget *target_tab;
    int row;
    int column;
    QString value;
    QString explain_title;
    QString specification_text;
}TAB_SPECIFITION;


typedef struct {
    QString Alarm_name;
    QString Alarm_level;
    QString Trigger_condition;
    QString Response_action;
    QString Whether_to_reset_automatically_and_reset_time;
}RTALARM_DATA;

#endif // SPECIFICATION_H
