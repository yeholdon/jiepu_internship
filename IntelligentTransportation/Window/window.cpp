#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    QGraphicsOpacityEffect *opacityEffect=new QGraphicsOpacityEffect;
    ui->label->setGraphicsEffect(opacityEffect);
    opacityEffect->setOpacity(0.7);
}

Window::~Window()
{
    delete ui;
}

void Window::on_tabWidget_tabBarClicked(int index)
{

}
