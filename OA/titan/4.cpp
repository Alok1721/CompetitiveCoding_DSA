#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int k1, k2, k3;
    cin >> k1 >> k2 >> k3;
    int n = k1 + k2 + k3;
    
    vector<int> who(n + 1, -1);
    for (int i = 0; i < k1; i++) {
        int x;
        cin >> x;
        who[x] = 0;  // 0 for Eren
    }
    for (int i = 0; i < k2; i++) {
        int x;
        cin >> x;
        who[x] = 1;  // 1 for Armin
    }
    for (int i = 0; i < k3; i++) {
        int x;
        cin >> x;
        who[x] = 2;  // 2 for Mikasa
    }
    
    vector<int> preE(n + 1, 0), preA(n + 1, 0), preM(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        preE[i] = preE[i - 1] + (who[i] == 0);
        preA[i] = preA[i - 1] + (who[i] == 1);
        preM[i] = preM[i - 1] + (who[i] == 2);
    }
    
    vector<int> X(n + 1), Y(n + 1);
    for (int i = 0; i <= n; i++) {
        X[i] = preE[i] - preA[i];
        Y[i] = preA[i] - preM[i];
    }
    
    int maxX = INT_MIN;
    int global_max = INT_MIN;
    for (int b = 0; b <= n; b++) {
        maxX = max(maxX, X[b]);
        int curr = maxX + Y[b];
        global_max = max(global_max, curr);
    }
    
    int max_correct = global_max + k3;
    int min_moves = n - max_correct;
    cout << min_moves << endl;
    
    return 0;
}