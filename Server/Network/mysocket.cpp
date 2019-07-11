#include "mysocket.h"

MySocket::MySocket(QObject *parent) : QTcpSocket(parent)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(readDataSlot()));
    connect(this, SIGNAL(disconnected()), this, SLOT(disConnectSlot()));
}

void MySocket::readDataSlot()
{
    QByteArray data;
    while (this->bytesAvailable()) {
        data.append(this->readAll()); // 只是读取缓冲区里的所有。
    }
    qDebug() << "new data:" << data;
}

void MySocket::disConnectSlot()
{
    qDebug() << "discnnected: " << this->peerAddress().toString();
    // 1. 解绑
    this->disconnect();
    // 2. 释放socket
    this->deleteLater();


}
