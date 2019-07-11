#include "demo.h"
#include "ui_demo.h"

Demo::Demo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Demo)
{
    ui->setupUi(this);
}

Demo::~Demo()
{
    delete ui;
}

void Demo::on_sendbtn_clicked()
{
    QString text = ui->lineEdit->text();
    QByteArray data = text.toUtf8();
    if(Network::getNetPtr()->sendNetData(data)) {
        qDebug() << "sent";
    }
    qDebug() << "pushbutton"<< "send" << text;
}
