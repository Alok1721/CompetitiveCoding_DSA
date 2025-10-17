 vector<int> computeLPS(const string &pat) {
        int n = pat.size();
        vector<int> lps(n, 0);
        int len = 0;  // length of previous longest prefix suffix
        int i = 1;
    
        while (i < n) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len > 0) {
                    len = lps[len-1]; // fallback
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
     
     string longestCommonPrefixSubstring(string &s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());

        string l = s + "#" + rev_s; // separator
        int n = l.size();

        vector<int> lps=computeLPS(l);
        
        // return the longest palindromic prefix
        return s.substr(0, lps.back());
    }