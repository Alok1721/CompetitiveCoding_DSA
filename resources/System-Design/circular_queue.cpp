#include<bits/stdc++.h>
using namespace std;
const int siz=5;
class CircularQueue
{
    vector<int>nums;
    int rear=-1;
    int front=-1;
    public:
    CircularQueue()
    {
        nums.resize(siz);
    }

    void insert()
    {
        cout<<"enter data to enter"<<endl;
        int data;
        cin>>data;
        if(isFull())
        {
            cout<<"Queue is full"<<endl;
            return;
        }
        if(isEmpty())
        {
            rear=front=0;
        }
        else{

            rear=(rear+1)%siz;
        }
        nums[rear]=data;
        return;
    }

    void remove()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
            return ;
        }  
        if(front==rear)
        {
            rear=front=-1;
        }else
        {
            front=(front+1)%siz;
        }
        return ;
    }
    void checkQueue()
    {
        if(isEmpty())
        {
            cout<<"Queue is emplty"<<endl;
            return;
        }
        int i=front;
        while(true)
        {
            cout<<nums[i]<<" ";
            if(i==rear)break;
            i=(i+1)%siz;
        }
        return ;
    }
    bool isFull()
    {
        return front==(rear+1)%siz;
    }
    bool isEmpty()
    {
        return front==-1 && rear==-1;
    }

};


int main()
{
    CircularQueue cq;
    while(true)
    {cout<<"\n select option to complete operation:\n 1) enter data \n 2) delete data \n 3) check empty \n 4) check queue \n 5) Exit"<<endl;
    int option;
    cin>>option;
    switch(option)
    {
        case 1: cq.insert();
            break;
        case 2: cq.remove();
            break;
        case 3: cq.isEmpty();
            break;
        case 4: cq.checkQueue();
            break;
        default: break;
    }}
    return 0;
}