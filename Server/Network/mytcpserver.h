#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
/*自定义服务类*/
#include <QObject>
#include <QTcpServer>
#include "mysocket.h"

class MyTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    MyTcpServer(QObject *parent = nullptr);
protected:
    void incomingConnection(qintptr handle);
};

#endif // MYTCPSERVER_H
