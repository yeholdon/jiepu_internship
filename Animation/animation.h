#ifndef ANIMATION_H
#define ANIMATION_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QLabel> // 作为小车图片的载体
#include <QPropertyAnimation> // 一个动画只能
#include <QAnimationGroup> // 用于包含一组动画的一个复杂动画的设置，
#include <QSequentialAnimationGroup> // 设置连续动画组用于，包含一连串动画的一个复杂动画的设置， 还有同时播放的动画组
#include <QTimer> // 定时器
#include <QHash>
#include <QDebug> // 在标准输出，输出调试信息
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QResizeEvent>

#include "mylabel.h" // 自定义的，不区分大小写

/**
 * @brief The Animation class
 * 动画组的各个动画中间对动画对象属性重新设置（转弯）的实现。
 * 使用定时器得到简单动画
 */


class Animation : public QWidget
{
    Q_OBJECT

public:
    Animation(QWidget *parent = 0);
    ~Animation();

    void initAll();
    void initTimer();
    void initAnimation();
    void setAnimationGroup(const QVector<QPropertyAnimation *> &vec);
    void initMap();
    void initButtonGroup();
    void initLayout();

public slots:
    void timerSlot();
    void btnGroupSlot(int );
protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
private:
    MyLabel *car_label;  // 因为自带的QLabel里没有旋转的功能，派生一个，添加
    QTimer *timer;
    QPropertyAnimation *anima1;
    QPropertyAnimation *anima2;
    QPropertyAnimation *anima3;
    QPropertyAnimation *anima4;
    QSequentialAnimationGroup *seq_group;
    QMap<QPropertyAnimation *, int> map; // 24个总共才几百个字节，可以直接实例化为对象
    QHBoxLayout *h1, *h2, *h3;
    QVBoxLayout *v1, *v2, *v3;
    QButtonGroup *btn_group;
};

#endif // ANIMATION_H
