
import threading
from time import sleep, ctime

loops = (4, 2)

class MyThread(threading.Thread):
    def __init__(self, func, args, name=""):
        threading.Thread.__init__(self)
        self.func = func
        self.args = args
        self.name = name

    def get_result(self):
        return self.res

    def run(self):
        print("start run %s at %s" % (self.name, ctime()))
        self.res = self.func(*self.args)
        print("finish run %s at %s" % (self.name, ctime()))


def loop(nloop, nsec):
    print("start loop %d, at %s" % (nloop, ctime()))
    sleep(nsec)
    print("loop %d done at %s" % (nloop, ctime()))


def main():
    print("starting at %s" % (ctime()))
    threads = []
    nloops = range(len(loops))

    for i in nloops:
        t = MyThread(loop, (i, loops[i]), loop.__name__)
        threads.append(t)

    for i in nloops:
        threads[i].start()

    for i in nloops:
        threads[i].join()

    print("All Done at %s" % ctime())


if __name__ == "__main__":
    main()