#include <bits/stdc++.h>
using namespace std;

// Trie Node structure
struct TrieNode {
    vector<string> suggestions; // Stores up to 3 lexicographically smallest products
    map<char, TrieNode*> children; // Map to child nodes
    TrieNode() {
        suggestions.reserve(3); // Reserve space for up to 3 suggestions
    }
};

// Trie class
class Trie {
private:
    TrieNode* root;

    // Insert a product into the Trie and update suggestions
    void insert(const string& product) {
        TrieNode* node = root;
        for (char c : product) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            // Add product to suggestions, maintaining at most 3
            node->suggestions.push_back(product);
            sort(node->suggestions.begin(), node->suggestions.end());
            if (node->suggestions.size() > 3) {
                node->suggestions.pop_back(); // Keep only top 3
            }
        }
    }

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a product into the Trie
    void addProduct(const string& product) {
        insert(product);
    }

    // Get suggestions for a given prefix
    vector<string> getSuggestions(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->children.count(c)) {
                return {}; // Prefix not found, return empty
            }
            node = node->children[c];
        }
        return node->suggestions; // Return precomputed suggestions
    }

    // Clean up memory (optional, for completeness)
    ~Trie() {
        function<void(TrieNode*)> deleteTrie = [&](TrieNode* node) {
            for (auto& [c, child] : node->children) {
                deleteTrie(child);
            }
            delete node;
        };
        deleteTrie(root);
    }
};

// Function to get product suggestions for each prefix
vector<vector<string>> getProductSuggestions(vector<string> products, string search) {
    Trie trie;
    // Insert all products into the Trie
    for (const string& product : products) {
        trie.addProduct(product);
    }

    vector<vector<string>> result;
    string prefix = "";
    // Get suggestions for each prefix of the search string
    for (char c : search) {
        prefix += c;
        result.push_back(trie.getSuggestions(prefix));
    }

    return result;
}

// Driver code for testing
int main() {
    int n;
    cout << "Enter number of products: ";
    cin >> n;
    vector<string> products(n);
    cout << "Enter product names:\n";
    for (int i = 0; i < n; ++i) {
        cin >> products[i];
    }

    string search;
    cout << "Enter search string: ";
    cin >> search;

    vector<vector<string>> suggestions = getProductSuggestions(products, search);

    cout << "\nProduct suggestions for each prefix:\n";
    for (int i = 0; i < suggestions.size(); ++i) {
        cout << "Prefix \"" << search.substr(0, i + 1) << "\": ";
        for (const string& s : suggestions[i]) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}