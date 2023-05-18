#ifndef SPECIFICATION_H
#define SPECIFICATION_H

#include <QDialog>
#include "database.h"


class Specification : public QDialog
{
    Q_OBJECT

public:
    explicit Specification(QWidget *parent,QPushButton *button, QTableWidget *tableWidget,
                            int r, int col, QString val, QString title, QString text);
    ~Specification();

    void add_Specifition();

private slots:
    void explain_btn_clicked();

private:
    TAB_SPECIFITION tab;
};

#endif // SPECIFICATION_H
