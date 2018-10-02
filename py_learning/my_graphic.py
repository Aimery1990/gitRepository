
import time
from graphics import *

win = GraphWin()

time.sleep(2)
leftEye = Circle(Point(80, 50), 5)
leftEye.setFill("yellow")
leftEye.setOutline('red')
leftEye.draw(win)

rightEye = leftEye  # this is not a copy action, rightEye is a reference of leftEye
#rightEye.draw(win)
time.sleep(3)
rightEye.move(20, 0) # both 2 eyes are moving

rightEye2 = leftEye.clone()
rightEye2.draw(win)
rightEye2.move(-20, 0)


time.sleep(3)

win.close()
