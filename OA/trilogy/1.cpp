#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> minimumSwaps(int A, vector<int>& B, int C) {
    vector<vector<int>> result;
    vector<int> position(A + 1);
    
    // Store the indices of the numbers in B 
    for (int i = 0; i < A; ++i) {
        position[B[i]] = i;
    }

    vector<bool> visited(A + 1, false);
    int totalSwaps = 0;

    // Find all cycles
    for (int i = 1; i <= A; ++i) {
        if (!visited[i]) {
            int cycleSize = 0;
            int current = i;
            vector<int> cycle;
            // Traverse through the cycle
            while (!visited[current]) {
                visited[current] = true;
                cycle.push_back(current);
                current = B[position[current]];
                cycleSize++;
            }
            // Each cycle of length k needs (k-1) swaps
            totalSwaps += (cycleSize - 1);
            for (int j = 0; j < cycle.size() - 1; ++j) {
                result.push_back({cycle[j], cycle[j + 1]});
            }
        }
    }

    // If the total number of swaps needed is more than C, return [-1, -1]
    if (totalSwaps > C) {
        return {{-1, -1}};
    }

    // Add dummy swaps if we have less swaps than C
    while (totalSwaps < C) {
        // Perform dummy swaps in a lexicographically small way
        if (result.size() > 0) {
            // Get last swap and swap them back
            auto lastSwap = result.back();
            result.push_back({lastSwap[0], lastSwap[0]}); // Dummy swap on the same index
            totalSwaps++;
        } else {
            // No swaps mean we can't perform more, hence break
            break;
        }
    }

    if(totalSwaps != C) {
        return {{-1, -1}}; // If we still don’t have exactly C swaps
    }

    // Return the result
    return result;
}

int main() {
    int A ;
    cin>>A;
    vector<int> B(A);
    for(int i=0;i<A;i++){
        cin>>B[i];
    }
    int C;
    cin>>C;
    auto result = minimumSwaps(A, B, C);
    for (const auto& swap : result) {
        cout << swap[0] << " " << swap[1] << endl;
    }
    return 0;
}