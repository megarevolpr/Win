#include "win.h"
#include "ui_win.h"

MEGAWin::MEGAWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MEGAWin)
{
    ui->setupUi(this);
}

MEGAWin::~MEGAWin()
{
    delete ui;
}
