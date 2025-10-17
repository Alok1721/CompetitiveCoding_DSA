#include <bits/stdc++.h>
using namespace std;

int selectBestDriverBlock(int groupSize, std::vector<int>& availability) {
    if (groupSize == 0) return 0;
    
    int n = availability.size();
    if (groupSize > n) return 0;
    
    int maxMin = 0;
    
    // Iterate through all possible contiguous blocks of size groupSize
    for (int i = 0; i <= n - groupSize; ++i) {
        int minAvailability = availability[i];
        // Find the minimum availability in the current block
        for (int j = i; j < i + groupSize; ++j) {
            minAvailability = std::min(minAvailability, availability[j]);
        }
        // Update the maximum of minimum availabilities
        maxMin = std::max(maxMin, minAvailability);
    }
    
    return maxMin;
}

int main() {
    int nDrivers, groupSize;
    cin >> groupSize >> nDrivers;

    vector<int> availability(nDrivers);
    for (int i = 0; i < nDrivers; ++i)
        cin >> availability[i];

    cout << selectBestDriverBlock(groupSize, availability) << endl;
    return 0;
}
