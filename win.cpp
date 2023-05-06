#include "megawin.h"
#include "ui_megawin.h"

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
