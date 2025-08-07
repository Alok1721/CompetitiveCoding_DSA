
#include <iostream>
#include <vector>

const long long MOD = 1000000007;

int main() {
    long long A, B, C;
    // Input
    std::cin >> A >> B >> C;
    
    // dp[i] stores the number of cells born on day i
    std::vector<long long> dp(A + 1, 0);
    // prefix[i] stores the sum of dp[1] to dp[i]
    std::vector<long long> prefix(A + 1, 0);
    
    // Day 1: One cell is born
    dp[1] = 1;
    prefix[1] = 1;
    
    // Compute number of cells born each day
    for (long long i = 2; i <= A; i++) {
        // Cells born on day i come from cells born on days j where i-C < j <= i-B
        long long start = i - C > 0 ? i - C : 0; // Ensure start is non-negative
        long long end = i - B > 0 ? i - B : 0;   // Ensure end is non-negative
        
        if (end >= 1 && start < end) {
            dp[i] = (prefix[end] - (start > 0 ? prefix[start] : 0) + MOD) % MOD;
        }
        // Update prefix sum
        prefix[i] = (prefix[i - 1] + dp[i]) % MOD;
    }
    
    // Count living cells on day A
    long long result = 0;
    // Cells born from day max(1, A-C+1) to day A are alive
    long long start = A - C + 1 > 1 ? A - C + 1 : 1;
    if (start <= A) {
        result = (prefix[A] - (start > 1 ? prefix[start - 1] : 0) + MOD) % MOD;
    }
    
    // Output the result
    std::cout << result << std::endl;
    
    return 0;
}