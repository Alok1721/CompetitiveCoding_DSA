#include <bits/stdc++.h>
using namespace std;

string reverseString(string s) {
    // Step 1: reverse entire string
    string temp = s;
    reverse(temp.begin(), temp.end());

    // Step 2: split reversed string into words
    vector<string> words;
    stringstream ss(temp);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }

    // Step 3: rebuild result preserving spaces
    string result;
    int idx = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] != ' ') {
            result += words[idx];
            i += words[idx].size() - 1; // skip over the word length
            idx++;
        } else {
            result += " ";
        }
    }

    // Step 4: add word count
    result += " " + to_string(words.size());

    return result;
}

int main() {
    string line, s;
    // Read multiple lines
    while (getline(cin, line)) {
        if (!s.empty()) s += " ";
        s += line;
    }

    string ans = reverseString(s);
    cout << ans << endl;

    return 0;
}
