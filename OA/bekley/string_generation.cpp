#include<bits/stdc++.h>
using namespace std;

string findNewString(string &s1,string &s2)
{
    int l1=s1.size();
    int l2=s2.size();
    string s(l1+l2-1,'A');//it will length of l1+l2-1;
    int i=0,j=0;
    // Process 'T' constraints
    for (int i = 0; i < l2; i++) {
        if (s2[i] == 'T') {
            for (int k = 0; k < l1; k++) {
                if (s[i + k] != 'A' && s[i + k] != s1[k]) {
                    return "-1"; // conflict
                }
                s[i + k] = s1[k];
            }
        }
    }


    // Check 'F' constraints
    for (int i = 0; i < l2; i++) {
        if (s2[i] == 'F') {
            if (s.substr(i, l1) == s1) return "-1";
        }
    }
    return s;
}

int main(){
 
    string s1;
    string s2;
    cin>>s1>>s2;
    cout<<findNewString(s1,s2);

    return 0;
}