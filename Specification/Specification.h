#ifndef SPECIFICATION_H
#define SPECIFICATION_H

#include <QDialog>
#include <QPushButton>
#include <QTableWidget>
#include <QString>


class Specification : public QDialog
{
    Q_OBJECT

public:
    explicit Specification(QPushButton *explain_btn, QTableWidget *target_tab,
                            int row, int column, QString value, QString title, QString text);
    ~Specification();
protected:

private slots:
    void explain_btn_clicked();

signals:


private:
    QString explain_title;
    QString specification_text;
};

#endif // SPECIFICATION_H
