#!/usr/bin/python

import thread
import time

def print_message(threadId):
    time.sleep(0.05 * threadId)
    print "Hello from thread ", threadId

for i in range(0, 4):
    try:
       thread.start_new_thread(print_message, (i,))
    except:
        print "Unable to start a thread, id - ", i

time.sleep(.5)
