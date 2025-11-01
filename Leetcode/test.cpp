#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int travenior = n;
        long long base = 0;
        for (int i = 0; i < n; ++i) {
            base += abs(nums1[i] - nums2[i]);
        }
        int min_ops = INT_MAX;
        int u = nums2[n];
        for (int k = 0; k < n; ++k) {
            int s = nums1[k];
            int t = nums2[k];
            vector<int> points = {s, t, u};
            sort(points.begin(), points.end());
            int med = points[1];
            int cost = abs(s - med) + abs(t - med) + abs(u - med);
            int orig = abs(s - t);
            int add = cost - orig;
            int total = 1 + base + add;
            if (total < min_ops) {
                min_ops = total;
            }
        }
        return min_ops;
    }
};

int main()
{
    vector<int> nums1 = {1,3,6};
    vector<int> nums2 = {2,4,5,3};
    Solution s1;
    cout<<s1.minimumOperations(nums1,nums2);
    return 0;
}