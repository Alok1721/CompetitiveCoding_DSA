#include<bits/stdc++.h>
using namespace std;

void generatePowerSet(vector<int>& v, int index, vector<int>& current, vector<vector<int>>& result) {
    if (index == v.size()) {
        result.push_back(current);
        return;
    }
    
    // Exclude the current element
    generatePowerSet(v, index + 1, current, result);
    
    // Include the current element
    current.push_back(v[index]);
    generatePowerSet(v, index + 1, current, result);
    
    // Backtrack to remove the last added element
    current.pop_back();
}


int main ()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    

    vector<vector<int>> result;
    vector<int>current;

    generatePowerSet(v, 0, current, result);
    sort(result.begin(), result.end(), [](const vector<int>& a, const vector<int>& b) {
        return a.size() < b.size() || (a.size() == b.size() && a < b);
    });
    cout<<"{";
    for(int i=0;i<result.size();i++)
    {
        cout<<"{";
        for(int j=0;j<result[i].size();j++)
        {
            cout<<result[i][j];
            if(j<result[i].size()-1)
            {
                cout<<",";
            }
        }
        cout<<"}"<<",";
    }
    cout<<"}"<<endl;
    
    return 0;

}