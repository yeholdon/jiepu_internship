#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent) : QLabel(parent), rotate_deg(180)
{

}

void MyLabel::setRotate(int rotate)
{
    this->rotate_deg = rotate;
}

void MyLabel::setTurn(int deg)
{
    this->rotate_deg += deg;
}

void MyLabel::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    // 1. 设置旋转轴,进行坐标偏移,偏移painter的参考坐标原点
    p.translate(this->width()/2, this->height()/2);
    // 2. 旋转
    p.rotate(rotate_deg);
    // 处理完再复原
    p.translate(-this->width()/2, -this->height()/2);
    //3.
    QRect target(0, 0, 100, 100);
    //4.
    p.drawImage(target, QImage(":/image/car.png"));

}
