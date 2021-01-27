#ifndef BOOTANIMATION_H
#define BOOTANIMATION_H
#include <QWidget>

class BootAnimation : public QWidget
{
    Q_OBJECT//使用信号与槽需要的宏

public:
    //避免歧义
    explicit BootAnimation(QWidget *parent = 0);
    BootAnimation(const QString text, QPoint center, int radius, QWidget* parent = 0);

    void paintEvent(QPaintEvent *);//绘图事件，调用update()时触发
    void mousePressEvent(QMouseEvent *e);//鼠标按下事件
    void mouseReleaseEvent(QMouseEvent *e);//鼠标释放事件
    void mouseMoveEvent(QMouseEvent *e);//鼠标移动事件

    bool isContains(QPoint p);//判断鼠标是否在图形范围之内
    void initForm();//初始化窗体

    bool _pressed;//左键单击变色控制
signals:
    void clicked();//点击信号
public slots:
private:
    QString _text;//控件显示文本
    QPoint _center;//圆心位置坐标
    QPoint beginPos;//圆形起始坐标
    int _radius;//圆形半径
};
#endif // BOOTANIMATION_H
