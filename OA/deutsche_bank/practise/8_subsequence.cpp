// C++ program to find Lexicographically smallest 
// K-length subsequence from a given string
#include <bits/stdc++.h>
using namespace std;
int given_b;
// Recursive function to generate all subsequences of length k
void generateSub(string s, int i, int k, string curr, 
vector<string>& result,int count_b) {
    int n = s.length();
    
    // If we've reached end of string and string 
    // is of length k.
    if (i == n) {
        if (curr.length() == k){ 
            if(count_b>=given_b)
            result.push_back(curr);}
        return;
    }
    
    // Include curr character
    generateSub(s, i + 1, k, curr + s[i], result,s[i]=='b'?count_b+1:count_b);
    
    // Exclude curr character
    generateSub(s, i + 1, k, curr, result,count_b);
}

string lexSmallest(string s, int k) {
    int n = s.length();
    
    vector<string> subsequences;
    generateSub(s, 0, k, "", subsequences,0);
    
    // Sort all subsequences lexicographically
    sort(subsequences.begin(), subsequences.end());
    
    // Return the lexicographically smallest subsequence
    return subsequences[0];
}

int main() {
    int n,k,z;
    cin>>n>>k>>z;
    given_b=z;
    string s;
    cin>>s;
    cout << lexSmallest(s, k);
    
    return 0;
}