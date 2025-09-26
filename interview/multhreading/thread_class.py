#!threading implementation using thread class

import threading
import time

class MyThread(threading.Thread):
    def __init__(self,params):
        threading.Thread.__init__(self)
        self.params=params
    def run(self):
        print(f"Thread {self.params} starting")
        time.sleep(2)
        print(f"Thread {self.params} finishing")
        
if __name__=="__main__":
    threads=[]
    for i in range(10):
        thread=MyThread(i)
        threads.append(thread)
        thread.start()
    for thread in threads:
        thread.join()
    print("All threads finished")
