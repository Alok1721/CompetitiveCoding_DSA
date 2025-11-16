/* 
💡 Logic

Pick one element at a time and insert it into its correct position in the already sorted part (like sorting playing cards in your hand).

⏱️ Time & Space Complexity
| Case    | Complexity | Situation                                              |
| ------- | ---------- | ------------------------------------------------------ |
| Best    | **O(n)**   | Already sorted array — only one comparison per element |
| Average | **O(n²)**  | Random order — roughly n²/4 shifts                     |
| Worst   | **O(n²)**  | Reverse sorted — each element shifted n times          |
| Space   | **O(1)**   | In-place                                               |
| Stable  | ✅ Yes      |                                                        |

💬 Interview Qs

(1) Why is insertion sort good for nearly sorted arrays?
👉 Because it moves elements only a few times, giving O(n) behavior.

(2) Is insertion sort recursive?
👉 Usually iterative, but can be implemented recursively too.

(3) Where is insertion sort used in real life?
👉 In small arrays or hybrid algorithms (like TimSort used in Python/Java).

*/

#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>&nums)
{
    int n=nums.size();
    for(int i=1;i<n;i++)
    {
        int key=nums[i];
        int j=i-1;
        while(j>=0 && nums[j]>key)
        {
            nums[j+1]=nums[j];
            j--;
        }
        nums[j+1]=key;
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
    insertionSort(nums);
    for(auto num:nums)
    {
        cout<<num<<" "; 
    }
    cout<<endl;

    return 0;
}