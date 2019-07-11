#ifndef DEMO_H
#define DEMO_H

#include <QWidget>
#include "Network/network.h" // 添加网络接口类
#include <QDebug>
namespace Ui {
class Demo;
}

class Demo : public QWidget
{
    Q_OBJECT

public:
    explicit Demo(QWidget *parent = 0);
    ~Demo();

private slots:
    void on_sendbtn_clicked();

private:
    Ui::Demo *ui;
};

#endif // DEMO_H
