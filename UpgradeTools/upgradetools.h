#ifndef UPGRADETOOLS_H
#define UPGRADETOOLS_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QButtonGroup>
#include <QMessageBox>

namespace Ui {
class UpgradeTools;
}

class UpgradeTools : public QMainWindow
{
    Q_OBJECT

public:
    explicit UpgradeTools(QWidget *parent = nullptr);


    ~UpgradeTools();

private slots:
    void UpgradeButton_clicked(int nid);

private:
    Ui::UpgradeTools *ui;

    QButtonGroup *pButton_Upgrade;
    void Init_MemorySpace();

    void setAppSize(int remainH);
//    virtual void resizeEvent(QResizeEvent *event)overr   ide;//调整控件大小
};

#endif // UPGRADETOOLS_H
