/* 
⏱️ Time Complexity Analysis
Case	Explanation	Time Complexity
------------------------------------------------------------------------------------
Best Case	Even if array is already sorted, heapify is still required	O(n log n)
Average Case	Each element insertion/extraction takes log n	O(n log n)
Worst Case	Same as average (no case-dependent degradation)	O(n log n)

Heapify single call: O(log n)
Building heap: O(n)
Extracting elements: n × O(log n) = O(n log n)
-----------------------------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>&nums,int n,int node)
{
    int largest=node;
    int leftNode=2*node+1;
    int rightNode=2*node+2;
    if(leftNode<n && nums[leftNode]>nums[largest])
    {
        largest=leftNode;
    }
    if(rightNode<n && nums[rightNode]>nums[largest])
    {
        largest=rightNode;
    }
    if(largest!=node)
    {
        swap(nums[largest],nums[node]);
        heapify(nums,n,largest);
    }
}

void heapSort(vector<int>&nums)
{
    int n=nums.size();
    for(int i=n-1;i>=0;i--)
    {
        heapify(nums,n,i);//satifying the property where ith node is greater than its both left, right nodes
    }
    for(int i=n-1;i>=0;i--)
    {
        swap(nums[i],nums[0]);
        heapify(nums,i,0);//affected node is 0, because we sending the largest element to last of array
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
    heapSort(nums);
    for(auto it:nums)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}