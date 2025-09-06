#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1); // dp[i] = LIS ending at index i
    int lis = 1;

    **for (int i = 1; i < n; i++) {**
        \*\*for (int j = 0; j < i; j++) {\*\*

            \*\*if (nums\\\[i] > nums\\\[j]) {\*\*



                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        lis = max(lis, dp[i]);
    }
    return lis;
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: "
         << lengthOfLIS(nums) << endl;
    return 0;
}