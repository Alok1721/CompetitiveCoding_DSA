#include <bits/stdc++.h>
using namespace std;

/* ==================== 1. Pleasant Melody ==================== */
string findLongestPleasantMelody(string &melody) {
    int n = melody.size();
    if (n == 0) return "";
    
    int maxLen = 0;
    int bestStart = 0;
    
    int i = 0;
    while (i < n) {
        int start = i;
        // extend as long as no 3 consecutive same chars
        while (i < n) {
            // check last 3 chars
            if (i >= start + 2 &&
                melody[i] == melody[i-1] && 
                melody[i] == melody[i-2]) {
                break;
            }
            i++;
        }
        // [start, i) is valid
        int len = i - start;
        if (len > maxLen) {
            maxLen = len;
            bestStart = start;
        }
        // if we broke because of 3 same, skip the third one
        if (i < n && i >= start + 2 &&
            melody[i] == melody[i-1] && melody[i] == melody[i-2]) {
            i = i - 1; // start next from the second of the three
        }
    }
    return melody.substr(bestStart, maxLen);
}

/* ==================== 2. Box Packing Optimization ==================== */
int minTotalShippingCost(vector<vector<int>>& items, int boxCapacity) {
    int totalCost = 0;
    int currLen = 0;
    int currMaxSec = 0;
    
    for (auto& item : items) {
        int len = item[0];
        int sec = item[1];
        
        // If adding this item exceeds capacity, seal current box
        if (currLen + len > boxCapacity) {
            if (currLen > 0) {
                totalCost += currMaxSec;
            }
            currLen = 0;
            currMaxSec = 0;
        }
        // Add current item (either to new or existing box)
        currLen += len;
        currMaxSec = max(currMaxSec, sec);
    }
    // Don't forget the last box
    if (currLen > 0) {
        totalCost += currMaxSec;
    }
    return totalCost;
}

/* ==================== 3. Minimum Jumps Using Teleportation ==================== */
vector<int> findMinimumSteps(int n, vector<int>& arr) {
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    
    // Precompute primes (simple sieve up to 1e5+10 is enough)
    const int MAXV = 100010;
    vector<bool> isPrime(MAXV, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < MAXV; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < MAXV; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    // For each prime position, collect positions divisible by arr[i]
    vector<vector<int>> teleport(n);
    for (int i = 0; i < n; i++) {
        if (arr[i] < MAXV && isPrime[arr[i]]) {
            for (int j = 0; j < n; j++) {
                if (arr[j] % arr[i] == 0) {
                    teleport[i].push_back(j);
                }
            }
        }
    }
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        
        // Normal moves
        if (u - 1 >= 0 && dist[u - 1] == -1) {
            dist[u - 1] = dist[u] + 1;
            q.push(u - 1);
        }
        if (u + 1 < n && dist[u + 1] == -1) {
            dist[u + 1] = dist[u] + 1;
            q.push(u + 1);
        }
        
        // Teleport moves
        if (arr[u] < MAXV && isPrime[arr[u]]) {
            for (int v : teleport[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    return dist;
}

/* ==================== 4. Minimum Operations To Satisfy OR ==================== */
int findMinimumOperations(vector<long long>& arr, long long k) {
    // Find the bit position of k (k is power of 2)
    int targetBit = 0;
    long long temp = k;
    while (temp > 1) {
        temp >>= 1;
        targetBit++;
    }
    
    int minOps = 30; // sufficient since arr[i] <= 1e9 < 2^30
    
    for (long long x : arr) {
        if (x == 0) continue;
        long long val = x;
        int ops = 0;
        // Shift left until the targetBit is set
        while ((val >> targetBit) == 0) {
            val <<= 1;
            ops++;
        }
        minOps = min(minOps, ops);
    }
    return minOps;
}

/* ============================== MAIN ============================== */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // === Test Problem 1 ===
    cout << "=== Problem 1: Pleasant Melody ===\n";
    string s1 = "aaaabbb";
    cout << s1 << " -> " << findLongestPleasantMelody(s1) << "\n"; // aabb
    
    string s2 = "ababab";
    cout << s2 << " -> " << findLongestPleasantMelody(s2) << "\n"; // ababab
    
    string s3 = "aaabaa";
    cout << s3 << " -> " << findLongestPleasantMelody(s3) << "\n"; // aaab or aabaa → aaab (first)
    
    // === Test Problem 2 ===
    cout << "\n=== Problem 2: Box Packing ===\n";
    vector<vector<int>> items = {{1,1},{2,3},{2,6},{2,5}};
    int cap = 5;
    cout << minTotalShippingCost(items, cap) << "\n"; // Expected: 9 (3+6)
    
    // === Test Problem 3 ===
    cout << "\n=== Problem 3: Minimum Steps ===\n";
    int n1 = 4;
    vector<int> arr1 = {1,2,4,6};
    auto res1 = findMinimumSteps(n1, arr1);
    for (int x : res1) cout << x << " ";
    cout << "\n"; // 0 1 2 2
    
    int n2 = 5;
    vector<int> arr2 = {2,3,4,7,9};
    auto res2 = findMinimumSteps(n2, arr2);
    for (int x : res2) cout << x << " ";
    cout << "\n"; // 0 1 1 2 2
    
    // === Test Problem 4 ===
    cout << "\n=== Problem 4: Min Operations for OR ===\n";
    vector<long long> arr4 = {5,1,2};
    long long k = 8;
    cout << findMinimumOperations(arr4, k) << "\n"; // 1 (2*2*2 = 8)
    
    return 0;
}