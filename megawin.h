#ifndef MEGAWIN_H
#define MEGAWIN_H

#include <QWidget>

namespace Ui {
class MEGAWin;
}

class MEGAWin : public QWidget
{
    Q_OBJECT

public:
    explicit MEGAWin(QWidget *parent = nullptr);
    ~MEGAWin();

private:
    Ui::MEGAWin *ui;
};

#endif // MEGAWIN_H
