/*
1638. Count Substrings That Differ by One Character
Solved
1745
Medium
Topics
premium lock icon
Companies
Hint
Given two strings s and t, find the number of ways you can choose a non-empty substring of s and replace a single character by a different character such that the resulting substring is a substring of t. In other words, find the number of substrings in s that differ from some substring in t by exactly one character.

For example, the underlined substrings in "computer" and "computation" only differ by the 'e'/'a', so this is a valid way.

Return the number of substrings that satisfy the condition above.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "aba", t = "baba"
Output: 6
Explanation: The following are the pairs of substrings from s and t that differ by exactly 1 character:
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
The underlined portions are the substrings that are chosen from s and t.
​​Example 2:
Input: s = "ab", t = "bb"
Output: 3
Explanation: The following are the pairs of substrings from s and t that differ by 1 character:
("ab", "bb")
("ab", "bb")
("ab", "bb")
​​​​The underlined portions are the substrings that are chosen from s and t.
 

*/

class Solution {
public:
    int countSubstrings(string s, string t) {
        int count=0;
        int n=s.size();
        int m=t.size();
        for(int i=0;i<n;i++)//for s
        {
            for(int j=0;j<m;j++)//for t
            {int diff=0;
            for(int k=0;i+k<n && j+k<m;k++)//for incrementing k for checking the substring
            {
                if(s[i+k]!=t[j+k])diff++;
                if(diff>1)break;
                if(diff==1)count++;
            }}

        }
        return count;
    }
};