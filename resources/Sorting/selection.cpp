/* 
💡 Logic

Find the smallest element and put it at the start; repeat for the rest.
Minimizes swaps (each element swapped once at most).

⏱️ Time & Space Complexity
| Case    | Complexity                           | Situation                                |
| ------- | ------------------------------------ | ---------------------------------------- |
| Best    | **O(n²)**                            | Even if sorted, still compares all pairs |
| Average | **O(n²)**                            | Random order                             |
| Worst   | **O(n²)**                            | Reverse order — no shortcut              |
| Space   | **O(1)**                             | In-place                                 |
| Stable  | ❌ No (swap can reorder equal values) |                                          |


💬 Interview Qs

(1) Why minimal swaps?
👉 Because each iteration only does 1 swap.

(2) Stable or not?
👉 Not stable, since swapping can disturb order of equal elements.

(3) When is it used?
👉 When swap cost is high but comparisons are cheap.

*/

#include<bits/stdc++.h>
using namespace std;
void selectionSort(vector<int>&nums)
{
    int n=nums.size();
    for(int i=0;i<n-1;i++)
    {
        int minIdx=i;
        for(int j=i+1;j<n;j++)
        {
            if(nums[j]<nums[minIdx])
            {
                minIdx=j;
            }
        }
        if(minIdx!=i)
        {
            swap(nums[i],nums[minIdx]);
        }
    }
    
}


int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    selectionSort(nums);
    for(auto num:nums)
    {
        cout<<num<<" ";
    }
    cout<<endl;

    return 0;
}