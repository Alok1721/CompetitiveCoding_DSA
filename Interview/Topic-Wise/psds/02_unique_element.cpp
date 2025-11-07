#include<bits/stdc++.h>
using namespace std;
void findUniqueElements(vector<char>& v, vector<char>& result) {
    unordered_map<char,int>freq;
    int left=0;
    int right=0;
    for (right=0;right<v.size();right++) {
        char c=v[right];
        freq[c]++;
        while(freq[v[right]]>1)
        {
            freq[v[left]]--;
            left++;
        }
        if(left<=right)
        {
            result.push_back(v[left]);
        }
        else
        {
            result.push_back('0');
        }
    }

}

int main()
{
    
        int n;
        cin >> n;
        vector<char> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];

        vector<char> result;
        findUniqueElements(v, result);

        for(int i=0;i<result.size();i++)
        {
            cout<<result[i]<<" ";
        }
    
    return 0;
}