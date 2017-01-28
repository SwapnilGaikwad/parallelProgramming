#!/usr/bin/python

import threading
import time

def print_message(threadId):
    time.sleep(0.01 * threadId)
    print "Hello from thread ", threadId


threadList = []
for i in range(0, 4):
    t = threading.Thread(target=print_message(i))
    t.start()
    threadList.append(t)

for t in threadList:
    t.join()
