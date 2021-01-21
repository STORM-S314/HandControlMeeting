import cv2 as cv
import numpy as np
import Pretreat as pre
import classifier as cf
from sklearn.svm import SVC
from sklearn.model_selection import GridSearchCV
import matplotlib.pyplot as plt
import joblib
#手势识别训练模型路径
model_path = "./model/"
#设置字体
font = cv.FONT_HERSHEY_SIMPLEX
#ROI大小
width, height = 300, 300
#ROI起始位置
x0 ,y0 = 300, 100
#开启摄像头
cap = cv.VideoCapture(0)

#如果以当前文件为主函数运行
if __name__=="__main__":
    while True:
        #读取摄像头内容
        ret, frame = cap.read()
        #翻转 >0沿y轴翻转,0沿x轴翻转,<0沿x,y同时翻转
        frame = cv.flip(frame,1)
        #绘制矩形框
        frame = cv.rectangle(frame,(x0,y0),(x0+width,y0+height),(0,255,255))
        #显示原图
        cv.imshow('frame', frame)
        #获取ROI区域
        roi = frame[y0:y0+height, x0:x0+width]
        #图像预处理
        res = pre.preTreat(frame,roi)
        cv.imshow("fourierDescriptor",res[0])
        #窗口名字,回调函数指针
        #cv.setMouseCallback('After',printHSV)
        #opencv等待用户触发事件，等待时间为2ms
        key = cv.waitKey(2) & 0xFF
        #按键判断并进行一定的调整
        #按'j''l''u''j'分别将选框左移，右移，上移，下移
        if key == ord('i'):
            y0 += 5
        elif key == ord('k'):
            y0 -= 5
        elif key == ord('l'):
            x0 += 5
        elif key == ord('j'):
            x0 -= 5
        #如果用户在这个时间内按下ESC，ASCII码
        #为27，则跳出循环
        elif key == 27:
            break
        #按p进入预测
        elif key == ord('p'):
            descriptor_in_use = abs(res[1])
            fd_test = np.zeros((1,31))
            temp = descriptor_in_use[0]
            for k in range(1,len(descriptor_in_use)):
                fd_test[0,k-1] = int(100*descriptor_in_use[k]/temp)
            clf = joblib.load(model_path + "svm_efd_" + "train_model.m")
            test_svm = clf.predict(fd_test)
            print(test_svm[0])
    #关闭摄像头
    cap.release()
    #关闭所有窗口
    cv.destroyAllWindows()

#鼠标移动显示坐标位置的HSV颜色通道信息
#event是CV_EVENT_*变量之一
#x和y是鼠标指针在图像坐标系的坐标（不是窗口坐标系）
#flag是CV_EVENT_FLAG的组合
#param是用户定义的传递到setMouseCallback函数用的参数
def printHSV(event, x, y, flag, param):
    if event == cv.EVENT_MOUSEMOVE:
        print(roi[x,y])