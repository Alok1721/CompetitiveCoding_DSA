#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:
    // Push element onto stack
    void push(int x) {
        // Step 1: push to q2
        q2.push(x);

        // Step 2: move everything from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 3: swap q1 and q2
        swap(q1, q2);
    }

    // Remove top element
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        q1.pop();
    }

    // Get top element
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return q1.front();
    }

    // Check if stack is empty
    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl; // 30
    st.pop();

    cout << "Top: " << st.top() << endl; // 20
    st.pop();

    cout << "Top: " << st.top() << endl; // 10
    st.pop();

    st.pop(); // Stack is empty!
    return 0;
}
