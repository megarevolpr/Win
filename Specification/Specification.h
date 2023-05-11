#ifndef SPECIFICATION_H
#define SPECIFICATION_H

#include <QDialog>
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

class Specification : public QDialog
{
    Q_OBJECT

public:
    explicit Specification(QPushButton *button, QTableWidget *tableWidget,
                            int r, int col, QString val, QString title, QString text);
    ~Specification();

    void add_Specifition();

private slots:
    void explain_btn_clicked();

private:
    TAB_SPECIFITION tab;
};

#endif // SPECIFICATION_H
