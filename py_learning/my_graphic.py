
import time
from graphics import *

win = GraphWin()

time.sleep(10)
leftEye = Circle(Point(80, 50), 5)
leftEye.setFill("yellow")
leftEye.setOutline('red')

rightEye = leftEye  # this is not a copy action, rightEye is a reference of leftEye
time.sleep(3)
rightEye.move(20, 0) # both 2 eyes are moving

time.sleep(10)

win.close()