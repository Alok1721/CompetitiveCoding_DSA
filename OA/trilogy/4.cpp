#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> crypt) {
    // collect all unique letters
    set<char> letters;
    for (auto &w : crypt) for (char c : w) letters.insert(c);
    vector<char> chars(letters.begin(), letters.end());

    if (chars.size() > 10) return 0; // impossible if >10 unique letters

    int ans = 0;
    vector<int> digits(10);
    iota(digits.begin(), digits.end(), 0);

    // try all permutations of digits assigned to letters
    do {
        unordered_map<char,int> mp;
        for (int i = 0; i < (int)chars.size(); i++) {
            mp[chars[i]] = digits[i];
        }

        auto toNumber = [&](string s) {
            if (s.size() > 1 && mp[s[0]] == 0) return -1LL; // leading zero
            long long val = 0;
            for (char c : s) val = val * 10 + mp[c];
            return val;
        };

        long long w1 = toNumber(crypt[0]);
        long long w2 = toNumber(crypt[1]);
        long long w3 = toNumber(crypt[2]);

        if (w1 == -1 || w2 == -1 || w3 == -1) continue;
        if (w1 + w2 == w3) ans++;

    } while (next_permutation(digits.begin(), digits.end()));

    return ans;
}

int main() {
    vector<string> crypt1 = {"SEND", "MORE", "MONEY"};
    cout << solution(crypt1) << endl; // 1

    vector<string> crypt2 = {"GREEN", "BLUE", "BLACK"};
    cout << solution(crypt2) << endl; // 12
    return 0;
}
