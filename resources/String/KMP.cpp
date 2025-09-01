class KMP {
    public:
        // Build the LPS (Longest Prefix Suffix) array
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
        
    
        // Returns true if pattern exists in text
        bool contains(const string& text, const string& pattern) {
            int n = text.size(), m = pattern.size();
            if (m == 0) return true;
            vector<int> lps = computeLPS(pattern);
            int i = 0, j = 0;
            while (i < n) {
                if (text[i] == pattern[j]) {
                    i++; j++;
                    if (j == m) return true; // Found match
                } else {
                    if (j != 0) {
                        j = lps[j - 1];
                    } else {
                        i++;
                    }
                }
            }
            return false; // No match found
        }
    };
    