#include "mytcpserver.h"

MyTcpServer::MyTcpServer(QObject *parent) : QTcpServer(parent)
{
    this->listen(QHostAddress::AnyIPv4, 10001);
}

// 当新客户端连接服务器以后，该函数会自动触发
void MyTcpServer::incomingConnection(qintptr handle)
{
    // 1. 构造套接字对象
    MySocket *socket = new MySocket(this);
    // 2. 设置套接字描述符
    socket->setSocketDescriptor(handle);
//    qDebug() << "discnnected: " << this->peerAddress().toString();
}
