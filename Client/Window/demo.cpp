#include "demo.h"
#include "ui_demo.h"

Demo::Demo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Demo)
{
    ui->setupUi(this);
    // 前端实例化时，绑定信号与槽。
    connect(Network::getNetPtr(), SIGNAL(SendDataToWindow(QJsonObject)), this, SLOT(receiveNetDataSlot(QJsonObject)));
    // 回车发送
    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(on_sendbtn_clicked()));
}

Demo::~Demo()
{
    delete ui;
}

void Demo::on_sendbtn_clicked()
{
    QString text = ui->lineEdit->text();
    QByteArray data = Protocol::packData(0, "text", text);//发之前先打包
    if(Network::getNetPtr()->sendNetData(data)) {
        ui->lineEdit->clear();
        ui->textBrowser->append("我:" + text);
    }
    else{
        QMessageBox::information(this, "提示", "网络未连接！");// 写了this就会阻塞主进程，直到关闭这个提示框
    }
    qDebug() << "pushbutton"<< "send" << text;
}

void Demo::receiveNetDataSlot(const QJsonObject &json)
{
    int type = json.value("type").toInt();
    if(type == 0) {
        // 群发消息
        QString ip = json.value("ip").toString();
        QString text = json.value("text").toString();
        ui->textBrowser->append(ip + " : " + text);
    }
}
