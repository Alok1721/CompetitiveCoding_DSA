class Solution {
  public:
    int maxCount(string &s,int k)
    {
        unordered_map<char,int>mp;
        int i=0,j=0;
        int n=s.size();
        int result=-1;
        while(j<n)
        {
            mp[s[j]]++;
            while(mp.size()>k && i<=j)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            
            if(mp.size()==k)result=max(result,j-i+1);
            j++;
            
        }
        return result;
    }
  
    int longestKSubstr(string &s, int k) {
        // code here
        return maxCount(s,k);
    }
};