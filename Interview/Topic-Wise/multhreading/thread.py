import threading
import time

def thread_function(name):
    print(f"Thread {name} starting")
    time.sleep(2)
    print(f"Thread {name} finishing")

def __main__():
    threads=[]
    for i in range(10):
        thread=threading.Thread(target=thread_function,args=(i,))
        threads.append(thread)
        thread.start()
    for thread in threads:
        thread.join()
        print("All threads finished")

if __name__=="__main__":
    __main__()
