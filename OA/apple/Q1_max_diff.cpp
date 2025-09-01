#include<bits/stdc++.h>
using namespace std;

int maxDifference(std::vector<int>& arr) {
    if (arr.size() < 2) return -1; // Need at least 2 elements for a difference
    
    int min_so_far = arr[0]; // Track minimum element seen so far
    int max_diff = -1;       // Track maximum difference
    
    // Start from second element
    for (size_t i = 1; i < arr.size(); ++i) {
        // If current element is greater than min_so_far, check difference
        if (arr[i] > min_so_far) {
            int current_diff = arr[i] - min_so_far;
            max_diff = std::max(max_diff, current_diff);
        }
        // Update minimum element seen so far
        min_so_far = std::min(min_so_far, arr[i]);
    }
    
    // Return -1 if max_diff is still -1 or 0 (flat or no valid pair)
    return (max_diff <= 0) ? -1 : max_diff;
}
int main() {
    vector<int> arr = {3, 6, 10, 1, 4, 6, 5};
    cout << maxDifference(arr) << endl;
    return 0;
}
