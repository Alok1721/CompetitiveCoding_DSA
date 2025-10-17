#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> km, cost;
vector<vector<int>> memo;

int dfs(int index, int remainingBudget) {
    if (remainingBudget == 0) return 0; // No budget left
    if (index == n) return 0;           // No more packages

    if (memo[index][remainingBudget] != -1)
        return memo[index][remainingBudget];

    int take = 0;
    if (remainingBudget >= cost[index]) {
        // Take this package (unbounded, so stay at same index)
        take = km[index] + dfs(index, remainingBudget - cost[index]);
    }
    // Skip this package
    int skip = dfs(index + 1, remainingBudget);

    return memo[index][remainingBudget] = max(take, skip);
}

int maximizeRideCredits(int budget, vector<int>& packageKilometers, vector<int>& packageCosts) {
    n = packageKilometers.size();
    km = packageKilometers;
    cost = packageCosts;
    memo.assign(n, vector<int>(budget + 1, -1));
    return dfs(0, budget);
}

int main() {
    int budget = 4;
    vector<int> packageKilometers = {10};
    vector<int> packageCosts = {2};

    cout << maximizeRideCredits(budget, packageKilometers, packageCosts) << endl; // Output: 40
    return 0;
}
