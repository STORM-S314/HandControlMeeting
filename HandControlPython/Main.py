import cv2 as cv
import numpy as np
import Pretreat as pre

width, height = 300, 300
x0 ,y0 = 0, 0

cap = cv.VideoCapture(0)

def printHSV(event, x, y, flag, param):
    if event == cv.EVENT_MOUSEMOVE:
        print(dst[x,y])

while True:
    ret, frame = cap.read()
    frame = cv.flip(frame,1)
    frame = cv.rectangle(frame.copy(),(x0,y0),(width,height),(0,255,255),3)
    ROI = frame[x0 : width, y0 : height]

    dst = pre.preTreat(ROI)

    cv.imshow('After', dst)
    cv.imshow('frame', ROI)
    cv.setMouseCallback('After',printHSV)

    #opencv等待用户触发事件，等待时间为2ms，如果用户在这个时间内按下ESC，ASCII码
    #为27，则跳出循环
    if cv.waitKey(2) == 27:
        break;


cap.release()
cv.destroyAllWindows()