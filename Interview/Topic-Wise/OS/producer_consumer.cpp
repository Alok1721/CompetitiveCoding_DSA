#include <thread>
#include <mutex>
#include<condition_variable>
#include <queue>
#include <chrono>
#include <iostream>
using namespace std;

queue<int> buffer;
const unsigned int maxSize=5;
mutex mtx;
condition_variable cv_producer, cv_consumer;


void producer(int id)
{
    int item=0;
    while(true)
    {
        unique_lock<mutex>lock(mtx);
        // cv_producer.wait(lock,[](){return buffer.size()<maxSize;});
        item++;
        buffer.push(item);
        cout<<"Producer "<<id<<" produced item "<<item<<endl;
        lock.unlock();
        // cv_consumer.notify_one();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void consumer(int id)
{
    while(true)
    {
        unique_lock<mutex>lock(mtx);
        // cv_consumer.wait(lock,[](){return !buffer.empty();});
        int item=buffer.front();
        buffer.pop();
        cout<<"Consumer "<<id<<" Consumed item "<<item<<endl;
        lock.unlock();
        // cv_producer.notify_one();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int main()
{
    thread c1(consumer,1);
    thread c2(consumer,2);
    thread p1(producer,1);
    thread p2(producer,2);
    p1.join();
    p2.join();
    c1.join();
    c2.join();
    return 0;
}

