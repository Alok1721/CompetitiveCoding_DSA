#include <bits/stdc++.h>
using namespace std;

int countDistinctCharacters(const string& s) {
    unordered_set<char> distinctChars(s.begin(), s.end());
    return distinctChars.size();
}


int findDistinctSplit(string s, long long n)
{

    unordered_set<char> st;
    vector<int> prefixCount(n+1,0);
    vector<int> suffixCount(n+1,0);
    int distinctCount = 0;
    for(long long i = 1; i <= n; i++) {
        st.insert(s[i-1]);
        prefixCount[i] = st.size();
    }
    st.clear();
    for(int i = n; i >= 1; i--) {
        st.insert(s[i-1]);
        suffixCount[i] = st.size();
    }
    for(int i = 0; i < n; i++) {
        distinctCount = max(distinctCount, prefixCount[i] + suffixCount[i+1]);
    }

    return distinctCount;
}


int main()
{
    long long t;
    cin>> t;
    while(t--)
    {
        long long n;
        cin>>n;
        string s;
        cin>>s;
        cout<<findDistinctSplit(s, n) << endl;
       
    }
    return 0;
}