import cv2 as cv
import numpy as np
import Pretreat as pre
#ROI大小
width, height = 300, 300
#ROI起始位置
x0 ,y0 = 0, 0
#开启摄像头
cap = cv.VideoCapture(0)
#鼠标移动显示坐标位置的HSV颜色通道信息
def printHSV(event, x, y, flag, param):
    if event == cv.EVENT_MOUSEMOVE:
        print(dst[x,y])

while True:
    ret, frame = cap.read()
    #翻转 >0沿y轴翻转,0沿x轴翻转,<0沿x,y同时翻转
    frame = cv.flip(frame,1)
    #绘制矩形框,最后一个为线条粗细
    frame = cv.rectangle(frame.copy(),(x0,y0),(width,height),(0,255,255),3)

    ROI = frame[x0 : width, y0 : height]
    #对ROI区域进行处理
    dst = pre.preTreat(ROI)
    #显示原图
    cv.imshow('After', dst)
    #显示处理过的图
    cv.imshow('frame', ROI)
    
    cv.setMouseCallback('After',printHSV)

    #opencv等待用户触发事件，等待时间为2ms，如果用户在这个时间内按下ESC，ASCII码
    #为27，则跳出循环
    if cv.waitKey(2) == 27:
        break;


cap.release()
cv.destroyAllWindows()