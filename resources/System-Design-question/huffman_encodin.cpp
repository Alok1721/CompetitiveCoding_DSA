#include <bits/stdc++.h>
using namespace std;

// Node of Huffman Tree (Trie Node)
struct TrieNode {
    char ch;          // character
    int freq;         // frequency
    TrieNode *left;   // represents '0'
    TrieNode *right;  // represents '1'

    TrieNode(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Comparator for priority queue
struct compare {
    bool operator()(TrieNode* l, TrieNode* r) {
        return l->freq > r->freq; // min-heap
    }
};

// Generate Huffman Codes by traversing Trie
void generateCodes(TrieNode* root, string code, unordered_map<char, string> &huffmanCode) {
    if (!root) return;

    // Leaf node
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = code;
    }

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// Huffman Encoding using Trie
void HuffmanEncoding(string text) {
    // 1. Frequency map
    unordered_map<char, int> freq;
    for (char ch : text) freq[ch]++;

    // 2. Min-heap priority queue
    priority_queue<TrieNode*, vector<TrieNode*>, compare> pq;
    for (auto p : freq) {
        pq.push(new TrieNode(p.first, p.second));
    }

    // 3. Build Huffman Trie
    while (pq.size() > 1) {
        TrieNode* left = pq.top(); pq.pop();
        TrieNode* right = pq.top(); pq.pop();

        TrieNode* merged = new TrieNode('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    TrieNode* root = pq.top();

    // 4. Generate codes from Trie
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    // 5. Print codes
    cout << "Huffman Codes:\n";
    for (auto p : huffmanCode) {
        cout << p.first << " : " << p.second << "\n";
    }

    // 6. Encode text
    string encoded = "";
    for (char ch : text) encoded += huffmanCode[ch];

    cout << "\nOriginal Text: " << text;
    cout << "\nEncoded Text : " << encoded;
    cout << "\nOriginal Size: " << text.size() * 8 << " bits";
    cout << "\nCompressed Size: " << encoded.size() << " bits\n";
}

// Driver
int main() {
    string text = "AAAAAABBCD";
    HuffmanEncoding(text);
    return 0;
}
