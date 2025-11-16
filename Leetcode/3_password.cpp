/* **Q4) DistinctPasswords**
***
if you observe then whereever same character is present that will not participate in the pairs (Trick):count all pairs and 
subtract that will not participate in the new string formation and also add +1 because original string is also one of the answer.
***
```
Learning:
1) ways to find number of pairs : n*(n-1)/2
2) counting number of duplicates pairs : duplicated+=freq[idx]*(freq[idx]-1)/2;
``` */



#include<bits/stdc++.h>
using namespace std;
int countDistinctPasswords(string &s)
{
    int n=s.size();
    int totalPairs=n*(n-1)/2;
    int duplicates=0;
    vector<int> freq(26,0);
    for(char &ch:s)
        freq[ch-'a']++;
    for(int &count:freq)
        duplicates+=count*(count-1)/2;
    
    return totalPairs-duplicates+1;
}

int main()
{

    string s;
    cin>>s;
    cout<<countDistinctPasswords(s)<<endl;


    return 0;
}