#include "bootanimation.h"
#include <QPainter.h>
#include <QMouseEvent>
BootAnimation::BootAnimation(QWidget *parent):
    QWidget(parent), _text("BootAnimation"), _center(30,30), _radius(20)
{
    initForm();
}
BootAnimation::BootAnimation(const QString text, QPoint center,int radius, QWidget* parent):
    QWidget(parent), _text(text), _center(center), _radius(radius)
{
    initForm();
}

void BootAnimation::initForm()
{
    _pressed = false;
    beginPos = this ->pos();
    //无边框
    this ->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowSystemMenuHint|Qt::WindowMaximizeButtonHint
                          |Qt::WindowStaysOnTopHint);
    /*窗口整体透明，但窗口内容不透明*/
    this ->setAttribute(Qt::WA_TranslucentBackground,true);
}

void BootAnimation::paintEvent(QPaintEvent *)
{
    QPainter p(this);//将当前窗体作为画布
    if(_pressed)
        p.setBrush(Qt::yellow);//粉刷为黄色
    else
        p.setBrush(QColor(255,255,255,10));
    p.setPen(Qt::NoPen);//没有线条
    //画圆形
    p.drawEllipse(_center,_radius,_radius);
    //添加文本
    QPen pen = QPen(Qt::black);
    p.setPen(pen);
    p.drawText(QRect(_center.x()-_radius,_center.x()-_radius,2*_radius,2*_radius), _text, QTextOption(Qt::AlignCenter));//文本居中：QTextOption(Qt::AlignCenter)
}
void BootAnimation::mousePressEvent(QMouseEvent *e)
{
   if(isContains(e->pos()))
    {
        _pressed = true;
        beginPos = e->pos();//鼠标相对窗体的位置
        update();//触发窗体重绘
    }

}

void BootAnimation::mouseReleaseEvent(QMouseEvent *e)
{
    _pressed = false;
    update();//触发窗体重绘

    if(isContains(e->pos()))//当鼠标点击按钮
        emit clicked();//发送点击信号

}

void BootAnimation::mouseMoveEvent(QMouseEvent *e)       //--鼠标移动事件
{
    if (_pressed)
    {//当前鼠标相对窗体的位置-刚按下左键时的相对位置=鼠标移动的大小
         this->move(e->pos() - beginPos + this->pos());
         //           鼠标移动的大小+窗体原来的位置=窗体移动后的位置
    }
}


bool BootAnimation::isContains(QPoint p)
{
    return (_center.x()-_radius < p.x()
            && _center.x()+_radius > p.x()
            && _center.y()-_radius < p.y()
            && _center.y()+_radius > p.y());
}
