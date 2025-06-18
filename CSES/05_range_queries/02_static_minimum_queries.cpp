
#include <bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;
const int INF = 1e9+7;
const int MAXN = 2e5+5;
int seg[4*MAXN];

//build the segment tree
void build(vector<int>&arr,int index,int l,int r)
{
    if(l==r){
        seg[index]=arr[l];
        return;
    }

    int mid=(l+r)/2;
    build(arr,2*index,l,mid);
    build(arr,2*index+1,mid+1,r);
    seg[index]=min(seg[2*index],seg[2*index+1]);
}

//query minimum in range [l,r]
int query(int index,int l,int r,int ql,int qr)
{
    if(ql>r || qr<l) return INF; //out of range
    if(ql<=l && qr>=r) return seg[index]; //completely inside range

    int mid=(l+r)/2;
    int left=query(2*index,l,mid,ql,qr);
    int right=query(2*index+1,mid+1,r,ql,qr);
    return min(left,right);
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build(arr, 1, 0, n - 1); // Build the segment tree
    while(q--) {
        int l, r;
        cin >> l >> r; // 0-based indexing
        cout << query(1, 0, n - 1, l, r) << endl; // Query the minimum in range [l, r]
    }
    return 0;
}