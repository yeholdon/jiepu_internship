#include <QCoreApplication>
#include "Network/mysocket.h"
#include "Network/mytcpserver.h"
#include "Database/database.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyTcpServer server;

    Database db;
    db.initDatabase();

    return a.exec();
}
