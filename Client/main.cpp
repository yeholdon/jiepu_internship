#include <QApplication>
#include "window/demo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 启动初始化
    Network::getNetPtr()->initNetwork();
    // 启动界面
    Demo demo;
    demo.show();
    return a.exec();
}
