#include<bits/stdc++.h>
using namespace std;

int largestDividingK(vector<int>& nums, int k) {
    int n = nums.size();
    
    // Count frequency of each number
    unordered_map<int, int> freq;
    for(int num : nums) {
        if(num > 0) freq[num]++;
    }
    
    // Map to store count of numbers divisible by each divisor
    unordered_map<int, int> divisorCount;
    
    // For each unique number, find all its divisors
    for(auto& p : freq) {
        int num = p.first;
        int count = p.second;
        
        // Find all divisors of num
        for(int i = 1; i * i <= num; i++) {
            if(num % i == 0) {
                divisorCount[i] += count;
                if(i != num / i) {
                    divisorCount[num / i] += count;
                }
            }
        }
    }
    
    int result = 0;
    
    // Find the largest divisor that divides at least k numbers
    for(auto& p : divisorCount) {
        int divisor = p.first;
        int count = p.second;
        
        if(count >= k && divisor <= 1000000000) {
            result = max(result, divisor);
        }
    }
    
    return result;
}

int main()
  {  int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<largestDividingK(arr,k);
    return 0;
}