#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode*next;
    ListNode(int x):val(x),next(NULL){};
};

class MyStack{
    ListNode*head;
    public:
        MyStack():head(NULL){};
        void push(int x)//at new element at front
        {
            ListNode*newNode=new ListNode(x);
            newNode->next=head;
            head=newNode;
        }
        void pop()//remove element from front
        {
            if(empty())
            {
                cout<<"Stack is empty\n";
                return;
            }
            if(head)
            {
                ListNode*node=head;
                head=head->next;
                delete node;
            }
            
        }
        int top()
        {
            if(empty())
            {
                cout<<"Stack is empty\n";
                return -1;
            }
            return head->val;
        }
        bool empty()
        {
            return head==NULL;
        }
};



int main()
{
    MyStack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    return 0;
}