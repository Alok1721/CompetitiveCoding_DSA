
/* 
--------------------------------------------------------------------------------------------
💡 Logic

Compare adjacent elements and swap them if they’re in the wrong order.
After each pass, the largest element “bubbles up” to its correct position at the end.
--------------------------------------------------------------------------------------------
⏱️ Complexity

| Case    | Complexity                         | Situation                                            |
| ------- | ---------------------------------- | ---------------------------------------------------- |
| Best    | **O(n)**                           | Array already sorted — no swaps happen in first pass |
| Average | **O(n²)**                          | Random order elements — about half need swapping     |
| Worst   | **O(n²)**                          | Array sorted in reverse order — every element swaps  |
| Space   | **O(1)**                           | In-place                                             |
| Stable  | ✅ Yes (equal elements not swapped) |                                                      |

--------------------------------------------------------------------------------------------

💬 Interview Qs

(1) Why does bubble sort stop early if no swaps occur?
👉 Because it means the array is already sorted — no need for further passes.

(2) Is it stable?
👉 Yes, because equal elements never get swapped.

(3) Can it be used for large datasets?
👉 No, because it’s too slow (O(n²)).
--------------------------------------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int>&nums)
{
    int n=nums.size();
    for(int i=0;i<n-1;i++)
    {
        bool isSwapped=false;
        for(int j=0;j<n-i-1;j++)
        {   
            if(nums[j]>nums[j+1])
            {
                isSwapped=true;
                swap(nums[j+1],nums[j]);
            }

        }
        if(!isSwapped)break;
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
    bubbleSort(nums);
    for(auto num:nums)
    {
        cout<<num<< " ";
    }
    cout<<endl;

    return 0;
}