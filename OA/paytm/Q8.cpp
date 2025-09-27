#include<bits/stdc++.h>
using namespace std;
string findLargestUniqueS(string &s)
{
    int n=s.length();
    unordered_map<char,int>freq;
    stack<char>st;//maintain the monotonic stack(decreasing order) if freq[ch]>0
    set<char>visited; //track char already in stack

    for(auto ch:s)
    {
        freq[ch]++;//help to track chances that ch will come later or not
    }

    for(int i=0;i<n;i++)
    {
        char ch=s[i];
        freq[ch]--;
        if(visited.count(ch))//donot include if already in stack
        {
            continue;
        }
        while(!st.empty() && st.top()<ch &&freq[st.top()]>0)
        {
            visited.erase(st.top());
            st.pop();
        }
        st.push(ch);
        visited.insert(ch);
    }
    string ans="";
    while(!st.empty())
    {
        ans=st.top()+ans;
        st.pop();
    }
    return ans;
}

int main()
{
    string s;
    cin>>s;
    cout<<findLargestUniqueS(s);
    
    return 0;
}