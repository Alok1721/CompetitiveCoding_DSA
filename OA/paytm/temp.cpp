#include <bits/stdc++.h>
using namespace std;

int maximizeTransactions(vector<int> &transaction) {
    long long balance = 0;
    int count = 0;
    priority_queue<int> negatives; // max-heap but we store negative values as positive

    for (int t : transaction) {
        if (t >= 0) {
            balance += t;
            count++;
        } else {
            if (balance + t >= 0) {
                balance += t;
                count++;
                negatives.push(-t); // store as positive
            } else if (!negatives.empty() && negatives.top() > -t) {
                balance += negatives.top(); // remove worst negative
                negatives.pop();
                balance += t;
                negatives.push(-t);
            }
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> transaction(n);
    for (int i = 0; i < n; i++) cin >> transaction[i];

    cout << maximizeTransactions(transaction) << endl;
    return 0;
}
