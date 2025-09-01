#include<bits/stdc++.h>
using namespace std;

int minCharactersToAdd(string word) {
    // Use a vector to store frequency of characters (assuming lowercase letters)
    vector<int> freq(26, 0);
    
    // Count frequency of each character
    for (char c : word) {
        freq[c - 'a']++;
    }
    
    // Count characters with odd frequency
    int oddCount = 0;
    for (int f : freq) {
        if (f % 2 != 0) {
            oddCount++;
        }
    }
    
    // Return the number of odd frequencies (characters to add)
    if(oddCount <= 1){
		return 0;
	} else {
		return oddCount-1;
	}
}

int main()
{
    string word = "apple";
    cout << minCharactersToAdd(word) << endl;
    return 0;
}