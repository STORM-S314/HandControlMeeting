import cv2 as cv
import numpy as np

def preTreat(origin):

    #高斯滤波
    gaussBlur = cv.GaussianBlur(origin,(3,3),0)

    #肤色检测 二值化
    #HSV上下限
    lowerHSVHand = np.array([100,0,100])
    upperHSVHand = np.array([180,50,255])
    #转换图像
    hsvHand = cv.cvtColor(gaussBlur,cv.COLOR_BGR2HSV)
    #设置掩膜
    mask = cv.inRange(hsvHand,lowerHSVHand,upperHSVHand)
    #覆盖合并
    dst = cv.bitwise_and(gaussBlur,gaussBlur,mask = mask)

    #设置卷积核
    kernel = cv.getStructuringElement(cv.MORPH_RECT,(3,3))
    #腐蚀膨胀
    dst = cv.morphologyEx(dst,cv.MORPH_OPEN,kernel)

    #寻找边界
    edge = cv.Canny(dst,50,200)

    #寻找和提取轮廓
    allContour = cv.findContours(edge,cv.RETR_TREE,cv.CHAIN_APPROX_NONE)

    contour = allContour[1]
    #绘制黑色背景
    backgroundBlack = np.ones(dst.shape,np.uint8)
    #绘制白色轮廓
    cv.drawContours(backgroundBlack,contour.reshape(-1,1,2),-1,(255,255,255),1)
    return backgroundBlack