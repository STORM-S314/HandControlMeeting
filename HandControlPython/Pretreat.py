import cv2 as cv
import numpy as np
import fourierDescriptor as fd
def preTreat(frame,roi):
    #肤色提取算法
    res = skinMask(roi)
    #肤色提取结果
    cv.imshow("skinMask",res)
    #设置卷积核
    kernel = cv.getStructuringElement(cv.MORPH_RECT,(4,4))
    #腐蚀膨胀
    res = cv.morphologyEx(res,cv.MORPH_OPEN,kernel)
    #傅里叶描述子
    ret, fourier_result = fd.fourierDesciptor(res)

    return ret, fourier_result
#使用YCrCb颜色空间的Cr分量和Otsu法阈值分割算法
def skinMask(roi):
    #转换至YCrCb空间
    YCrCb = cv.cvtColor(roi,cv.COLOR_BGR2YCR_CB)
    #拆分出Y,Cr,Cb值
    (y,cr,cb) = cv.split(YCrCb)
    #高斯滤波
    cr = cv.GaussianBlur(cr,(7,7),0)
    #Otsu自适应二值化
    #threshold返回两个返回值,第二个是二值化的图像
    _,skin = cv.threshold(cr,0,255,cv.THRESH_BINARY+cv.THRESH_OTSU)
    #覆盖合并,对每个像素值二进制与,提取图像精确的边界
    res = cv.bitwise_and(roi,roi,mask = skin)
    return res