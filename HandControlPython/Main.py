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


    if cv.waitKey(2) == 27:
        break;


cap.release()
cv.destroyAllWindows()