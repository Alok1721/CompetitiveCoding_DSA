#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

int bagsSum(int target, int nbags, int n, int *V) {
    std::unordered_map<std::string, int> memo;
    
    // Helper function for recursive calls
    auto countWays = [&](int index, int remainingWeight, int remainingSacks, auto&& self) -> int {
        if (remainingWeight == 0 && remainingSacks == 0) return 1;
        if (index == n || remainingWeight < 0 || remainingSacks == 0) return 0;

        std::string key = std::to_string(index) + "," + 
                         std::to_string(remainingWeight) + "," + 
                         std::to_string(remainingSacks);
        if (memo.find(key) != memo.end()) return memo[key];

        // Exclude current weight
        int exclude = self(index + 1, remainingWeight, remainingSacks, self);

        // Include current weight
        int include = self(index + 1, remainingWeight - V[index], remainingSacks - 1, self);

        int totalWays = exclude + include;
        memo[key] = totalWays;
        return totalWays;
    };

    return countWays(0, target, nbags, countWays);
}

int main() {
    int W, N, X;
    // Read standardized weight
    std::cin >> W;
    // Read number of bags and number of sacks
    std::cin >> N >> X;
    // Read weights of sacks
    std::vector<int> weights(X);
    for (int i = 0; i < X; ++i) {
        std::cin >> weights[i];
    }

    // Call bagsSum with the input
    int result = bagsSum(W, N, X, weights.data());
    
    // Output the result
    std::cout << result << std::endl;

    return 0;
}