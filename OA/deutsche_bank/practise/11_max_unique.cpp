#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

string getWordWithMostUniqueLetters(vector<string>& words) {
    string result = "";
    int maxUnique = -1;

    for (string& word : words) {
        unordered_set<char> uniqueChars(word.begin(), word.end());
        int count = uniqueChars.size();

        if (count > maxUnique) {
            maxUnique = count;
            result = word;
        } else if (count == maxUnique && word < result) {
            result = word;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    cout << getWordWithMostUniqueLetters(words) << endl;
    return 0;
}
