class KMP {
    public:
        // Build the LPS (Longest Prefix Suffix) array
        vector<int> buildLPS(const string& pattern) {
            int n = pattern.size();
            vector<int> lps(n, 0);
            int len = 0;
            for (int i = 1; i < n; ++i) {
                while (len > 0 && pattern[i] != pattern[len])
                    len = lps[len - 1];
                if (pattern[i] == pattern[len])
                    len++;
                lps[i] = len;
            }
            return lps;
        }
    
        // Returns true if pattern exists in text
        bool contains(const string& text, const string& pattern) {
            int n = text.size(), m = pattern.size();
            if (m == 0) return true;
            vector<int> lps = buildLPS(pattern);
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
    