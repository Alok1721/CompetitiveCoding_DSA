#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int collectingCoins(vector<int>& A, vector<int>& B, vector<int>& C) {
    int N = A.size();
    int M = B.size();
    
    // Create pairs of (monster_power, coins) and sort by coins in descending order
    vector<pair<int, int>> monsters; // {coins, power}
    for (int i = 0; i < M; i++) {
        monsters.push_back({C[i], B[i]});
    }
    
    // Sort by coins in descending order (greedy: prioritize high-value monsters)
    sort(monsters.begin(), monsters.end(), greater<pair<int, int>>());
    
    // Use multiset to track available monsters by power
    multiset<int> availableMonsters;
    for (int i = 0; i < M; i++) {
        availableMonsters.insert(monsters[i].second); // insert power
    }
    
    int totalCoins = 0;
    
    // For each hero, find the best monster they can defeat
    for (int i = 0; i < N; i++) {
        int heroPower = A[i];
        
        // Find the strongest monster this hero can defeat
        auto it = availableMonsters.upper_bound(heroPower);
        
        if (it != availableMonsters.begin()) {
            --it; // Move to the largest monster power <= heroPower
            int monsterPower = *it;
            
            // Find corresponding coins for this monster
            for (int j = 0; j < M; j++) {
                if (monsters[j].second == monsterPower) {
                    totalCoins += monsters[j].first;
                    availableMonsters.erase(it);
                    
                    // Remove this monster from our list
                    monsters.erase(monsters.begin() + j);
                    M--;
                    break;
                }
            }
        }
    }
    
    return totalCoins;
}

int main() {
    // Test case
    int a,b,c;
    cin>>a>>b>>c;

    vector<int> A(a);
    vector<int> B (b);  
    vector<int> C (c);   // Coins from monsters
    for(int i=0;i<a;i++)
    {
        cin>>A[i];
    }
    for(int i=0;i<b;i++)
    {
        cin>>B[i];
    }
    for(int i=0;i<c;i++)
    {
        cin>>C[i];
    }
    int result = collectingCoins(A, B, C);
    cout << "Maximum coins collected: " << result << endl; 
    return 0;
}