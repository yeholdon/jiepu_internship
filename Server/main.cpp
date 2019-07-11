#include <QCoreApplication>
#include "Network/mysocket.h"
#include "Network/mytcpserver.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyTcpServer server;
    return a.exec();
}
