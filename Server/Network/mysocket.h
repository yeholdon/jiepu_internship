#ifndef MYSOCKET_H
#define MYSOCKET_H
/*自定义套接字*/
#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QHostAddress>

class MySocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit MySocket(QObject *parent = nullptr);

signals:

public slots:
    void readDataSlot();
    void disConnectSlot();
};

#endif // MYSOCKET_H
