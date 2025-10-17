#include<bits/stdc++.h>
using namespace std;
int fountainIndex(int water[], int cost[], int n) {
    int totalWater = 0, totalCost = 0;
    int start = 0, balance = 0;

    for(int i = 0; i < n; i++) {
        totalWater += water[i];
        totalCost += cost[i];
        balance += water[i] - cost[i];

        if(balance < 0) {
            // Can't start from current start, try next
            start = i + 1;
            balance = 0;
        }
    }

    if(totalWater < totalCost)
        return -1; // impossible to complete
    return start;
}
int main()
{
    
}