
import _thread
from time import sleep, ctime

def loop0():
    print("start loop0 at : %s" % ctime())
    sleep(4)
    print("loop 0 done at: %s" % ctime())

def loop1():
    print("start loop1 at : %s" % ctime())
    sleep(2)
    print("loop1 done at: %s" % ctime())




def main():
    print("starting at: %s" % ctime())
    _thread.start_new_thread(loop0, ())
    _thread.start_new_thread(loop1, ())
    sleep(6)  # main thread waits for 2 new threads!!!!
    print("All done at: %s" % ctime())


if __name__ == '__main__':
    main()
