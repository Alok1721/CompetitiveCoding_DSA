#include <iostream>
#include <vector>
using namespace std;

int getNumberOfBlocks(const vector<int>& arr) {
    int n=arr.size(),p=0,i;
    vector<int>pos(n);

    // for loop for saving the positions of all 1s
    for (i = 0; i < n; i++) {
        if (arr[i] == 1) {
            pos[p] = i + 1;
            p++;
        }
    }

    // If array contains only 0s
    if (p == 0)
        return 0;

    int ways = 1;
    for (i = 0; i < p - 1; i++) {
        ways *= pos[i + 1] - pos[i];
    }

    // Return the total ways
    return ways;

   
}

int main() {
    // vector<int> arr = {1, 1, 1, 1, 1, 1, 1, 1};
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    cout << "Number of One blocks: " << getNumberOfBlocks(arr) << endl;

    return 0;
}
