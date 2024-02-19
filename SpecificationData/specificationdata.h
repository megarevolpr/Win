#ifndef SPECIFICATIONDATA_H
#define SPECIFICATIONDATA_H

#include <QPushButton>
#include <QTableWidget>
#include <QString>
#include <QWidget>
#include <QMap>
#include <QMessageBox>
#include <stdio.h>
#include <QDialog>
#include <QObject>
#include <QList>
#include <QDebug>


class SpecificationData: public QDialog
{
    Q_OBJECT

public:
    explicit SpecificationData(QWidget *parent);
    void add_SpecificationData(QPushButton *button, QTableWidget *tableWidget,
                           int row, int column, QString value, QString title, QString text);
    ~SpecificationData();


QWidget *mainparent;
private:
    QList<QMetaObject::Connection > *MyConnection;
    QMap<QPushButton*, QString> specificationMap;
    QFont *font;
};

#endif // SPECIFICATIONDATA_H
