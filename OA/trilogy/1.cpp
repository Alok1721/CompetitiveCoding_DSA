#include <string>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

struct RollingHash {
    long long p1 = 31, m1 = 1e9 + 7;
    long long p2 = 37, m2 = 1e9 + 9;
    vector<long long> p_pow1, p_pow2;
    vector<long long> h1, h2;
    int n;

    RollingHash(const string& s) {
        n = s.length();
        p_pow1.resize(n + 1);
        p_pow2.resize(n + 1);
        h1.resize(n + 1, 0);
        h2.resize(n + 1, 0);

        p_pow1[0] = 1;
        p_pow2[0] = 1;
        for (int i = 1; i <= n; i++) {
            p_pow1[i] = (p_pow1[i - 1] * p1) % m1;
            p_pow2[i] = (p_pow2[i - 1] * p2) % m2;
        }

        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * p1 + s[i]) % m1;
            h2[i + 1] = (h2[i] * p2 + s[i]) % m2;
        }
    }

    pair<long long, long long> get_hash(int i, int len) {
        if (len == 0) return {0, 0};
        long long hash1 = (h1[i + len] - (h1[i] * p_pow1[len]) % m1 + m1) % m1;
        long long hash2 = (h2[i + len] - (h2[i] * p_pow2[len]) % m2 + m2) % m2;
        return {hash1, hash2};
    }
};

int solution(string s, int k) {
    int n = s.length();
    if (n <= k) {
        return 0;
    }

    RollingHash rh(s);
    long long unordered_count = 0;

    map<pair<long long, long long>, vector<int>> prefix_groups;
    if (k > 0) {
        for (int i = 0; i <= n - k; ++i) {
            prefix_groups[rh.get_hash(i, k)].push_back(i);
        }
    } else {
        vector<int> all_indices;
        for(int i = 0; i < n; ++i) all_indices.push_back(i);
        prefix_groups[{0,0}] = all_indices;
    }


    for (auto const& [hash_val, indices] : prefix_groups) {
        if (indices.size() < 2) continue;

        for (size_t i = 0; i < indices.size(); ++i) {
            for (size_t j = i + 1; j < indices.size(); ++j) {
                int idx1 = indices[i];
                int idx2 = indices[j];

                if (idx1 + k >= n || idx2 + k >= n) continue;

                if (s[idx1 + k] != s[idx2 + k]) {
                    int max_lcp_len = n - max(idx1, idx2) - k - 1;
                    int low = 0, high = max_lcp_len, lcp = 0;
                    
                    while (low <= high) {
                        int mid = low + (high - low) / 2;
                        if (mid == 0) {
                           low = mid + 1;
                           continue;
                        }
                        if (rh.get_hash(idx1 + k + 1, mid) == rh.get_hash(idx2 + k + 1, mid)) {
                            lcp = mid;
                            low = mid + 1;
                        } else {
                            high = mid - 1;
                        }
                    }
                    unordered_count += (lcp + 1);
                }
            }
        }
    }

    return unordered_count * 2;
}