#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> s1, s2;

public:
    void push(int x) {
        // always push into s1
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            // move elements from s1 -> s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        int val = s2.top();
        s2.pop();
        return val;
    }

    int front() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.front() << endl; // 10
    cout << q.pop() << endl;   // 10
    cout << q.pop() << endl;   // 20

    q.push(40);
    cout << q.front() << endl; // 30
    cout << q.pop() << endl;   // 30
    cout << q.pop() << endl;   // 40

    cout << (q.empty() ? "Empty" : "Not Empty") << endl; // Empty
}
