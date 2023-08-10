#include "win.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MEGAWin w;

    QFont font("宋体", 12); // 创建一个宋体字体，字号为12
    QApplication::setFont(font); // 设置应用程序的全局字体为宋体

    w.show();

    return a.exec();
}
