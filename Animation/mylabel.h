#ifndef MYLABEL_H
#define MYLABEL_H
/* 自定义标签类 */
#include <QWidget>
#include <QLabel>
#include <QPainter>
#include <QMap> // 元素过多会很慢，换用hashtable
#include <QHash>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);
    void setRotate(int rotate);
    void setTurn(int deg);
protected:
    void paintEvent(QPaintEvent *);
private:
    int rotate_deg;

signals:

public slots:
};

#endif // MYLABEL_H
