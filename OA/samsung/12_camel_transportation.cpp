#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int minCostToTransport(vector<int>& cost) {
    sort(cost.begin(), cost.end());
    int total = 0;
    int n = cost.size();

    while (n > 3) {
        int option1 = cost[1] + cost[0] + cost[n - 1] + cost[1];
        int option2 = cost[n - 1] + cost[0] + cost[n - 2] + cost[0];
        total += min(option1, option2);
        n -= 2;  // two camels moved
    }

    if (n == 3)
        total += cost[0] + cost[1] + cost[2];
    else if (n == 2)
        total += cost[1];
    else if (n == 1)
        total += cost[0];

    return total;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> cost(n);
        for (int i = 0; i < n; i++) cin >> cost[i];
        cout << minCostToTransport(cost) << endl;
    }
    return 0;
}
