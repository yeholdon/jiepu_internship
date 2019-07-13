#include "animation.h"

Animation::Animation(QWidget *parent)
    : QWidget(parent)
{
    this->resize(1024, 768);
    car_label = new MyLabel(this);
    car_label->setGeometry(20, 0, 100, 100);
//    car_label->setRotate(180);
//    car_label->setStyleSheet("border-image:url(:/image/car.png)");
    initButtonGroup();
    initLayout();

}

Animation::~Animation()
{
    delete anima1;
    delete anima2;
}

void Animation::initAll()
{
    initTimer();
    initAnimation();
    initMap();
//    setAnimationGroup();
}

void Animation::initTimer()
{
    timer = new QTimer(this);
    timer->setTimerType(Qt::PreciseTimer);
    // 绑定信号与槽,信号和槽都是比较特殊的函数.
    connect(timer, SIGNAL(timeout()), this, SLOT(timerSlot()));
}

void Animation::initAnimation()
{
    //“pos”代表发生动画的属性为位置
    anima1 = new QPropertyAnimation(car_label, "pos");
    // 起始位置
    anima1->setStartValue(btn_group->button(0)->pos());
    // 终止位置
    anima1->setEndValue(btn_group->button(1)->pos());
    // 设置动画持续时间, 单位为ms
    anima1->setDuration(3000);
//    anima1->start();

    anima2 = new QPropertyAnimation(car_label, "pos");
    anima2->setStartValue(anima1->endValue());
    anima2->setEndValue(btn_group->button(4)->pos());
    anima2->setDuration(3000);
//    anima2->start();

    anima3 = new QPropertyAnimation(car_label, "pos");
    anima3->setStartValue(anima2->endValue());
    anima3->setEndValue(btn_group->button(7)->pos());
    anima3->setDuration(3000);

    anima4 = new QPropertyAnimation(car_label, "pos");
    anima4->setStartValue(anima3->endValue());
    anima4->setEndValue(QPoint(900, 680));
    anima4->setDuration(3000);

}

void Animation::setAnimationGroup(const QVector<QPropertyAnimation *> &vec)
{
    // 动画原理是开辟了一个新的线程
    seq_group = new QSequentialAnimationGroup;
    for(int i = 0; i < vec.size(); i++) {
        seq_group->addAnimation(vec.at(i));
    }

    seq_group->start();
    timer->start(100);
}

void Animation::initMap()
{
    map.insert(anima1, 180);
    map.insert(anima2, 270);
    map.insert(anima3, 270);
    map.insert(anima4, 180);
}

void Animation::initButtonGroup()
{
    btn_group = new QButtonGroup(this);
    for(int i = 0; i < 9; i++) {
        QPushButton *btn = new QPushButton(this);
        btn_group->addButton(btn, i);
        btn->setStyleSheet("QPushButton{background:transparent;}"
                           "QPushButton:pressed{background:#FF00FF;}");
        btn->setFlat(true); // 设置按钮不按下时为透明的
    }
    connect(btn_group, SIGNAL(buttonClicked(int)), this, SLOT(btnGroupSlot(int)));
}

void Animation::initLayout()
{
    h1 = new QHBoxLayout;
    h1->addWidget(btn_group->button(0));
    h1->addStretch(); // 弹簧效果
    h1->addWidget(btn_group->button(1));
    h1->addStretch();
    h1->addWidget(btn_group->button(2));

    h2 = new QHBoxLayout;
    h2->addWidget(btn_group->button(3));
    h2->addStretch(); // 弹簧效果
    h2->addWidget(btn_group->button(4));
    h2->addStretch();
    h2->addWidget(btn_group->button(5));

    h3 = new QHBoxLayout;
    h3->addWidget(btn_group->button(6));
    h3->addStretch(); // 弹簧效果
    h3->addWidget(btn_group->button(7));
    h3->addStretch();
    h3->addWidget(btn_group->button(8));

    v1 = new QVBoxLayout;
    v1->setMargin(0);
    v1->addLayout(h1); // 往大的布局管理器里添加小布局
    v1->addStretch();
    v1->addLayout(h2);
    v1->addStretch();
    v1->addLayout(h3);

    this->setLayout(v1);
}

void Animation::timerSlot()
{
    if(seq_group->state() != QAnimationGroup::Stopped) { // 动画结束了就不再设旋转状态
        // 1. 和当前正在执行的动画有关，即当前所处的路段有关。
        int rotate = map.value((QPropertyAnimation*)seq_group->currentAnimation());
        // 2.
        car_label->setRotate(rotate);
    }
    else
    {
        timer->stop();
        timer->deleteLater();// Qt帮你在适当的时候释放内存，建议用这种，因为有时候逻辑上可以delete,但是实际该对象还在完成工作
    }

}

void Animation::btnGroupSlot(int i)
{
    // 规划路径的算法
    qDebug() << i;
}

void Animation::paintEvent(QPaintEvent *event)
{
    // 告知编译器，将不使用这个参数，编译器就不会报警告
    Q_UNUSED(event);
    QPainter p(this);
    QRect target(0, 0, this->width(), this->height());
    p.drawImage(target, QImage(":/image/map.png"));

}

// 页面大小改变事件
void Animation::resizeEvent(QResizeEvent *event)
{
    for(int i = 0; i < 9; i++) {
        btn_group->button(i)->setFixedSize(width() / 9, height() / 9);
    }
}
