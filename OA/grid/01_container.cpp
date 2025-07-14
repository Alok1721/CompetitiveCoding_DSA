#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> container;

void solve(vector<int>& weights, int target) {
    sort(weights.rbegin(), weights.rend());

    vector<pair<int, vector<int>>> trucks; // {remaining_capacity, packages}
    
    for (auto w : weights) {
        bool isLoaded = false;
        
        for (auto& truck : trucks) { // FIXED: use reference
            if (truck.first >= w) {
                truck.second.push_back(w);
                truck.first -= w; // You forgot to update remaining capacity!
                isLoaded = true;
                break;
            }
        }

        if (!isLoaded) {
            trucks.push_back({target - w, {w}});
        }
    }

    for (auto& it : trucks) {
        container.push_back(it.second);
    }
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        container.clear(); // Clear previous test case result

        int n;
        cin >> n;
        vector<int> weights(n);
        for (int i = 0; i < n; i++) {
            cin >> weights[i];
        }
        int target;
        cin >> target;
        
        solve(weights, target);

        // Pretty print the result
        cout << "{";
        for (int i = 0; i < container.size(); i++) {
            cout << "{";
            for (int j = 0; j < container[i].size(); j++) {
                cout << container[i][j];
                if (j != container[i].size() - 1) cout << ",";
            }
            cout << "}";
            if (i != container.size() - 1) cout << ",";
        }
        cout << "}" << endl;
    }
    return 0;
}
