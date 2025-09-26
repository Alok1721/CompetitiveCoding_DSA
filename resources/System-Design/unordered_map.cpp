#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

class MyUnorderedMap {
    static const int BUCKET_COUNT = 10; // fixed number of buckets for simplicity
    vector<list<pair<string, int>>> table;

    // simple hash function
    int hash(string key) {
        int h = 0;
        for (char c : key) h = (h * 31 + c) % BUCKET_COUNT;
        return h;
    }

public:
    MyUnorderedMap() {
        table.resize(BUCKET_COUNT);
    }

    void insert(string key, int value) {
        int idx = hash(key);
        // check if key already exists → update
        for (auto &p : table[idx]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        // otherwise insert new
        table[idx].push_back({key, value});
    }

    bool find(string key, int &value) {
        int idx = hash(key);
        for (auto &p : table[idx]) {
            if (p.first == key) {
                value = p.second;
                return true;
            }
        }
        return false;
    }

    void erase(string key) {
        int idx = hash(key);
        for (auto it = table[idx].begin(); it != table[idx].end(); ++it) {
            if (it->first == key) {
                table[idx].erase(it);
                return;
            }
        }
    }

    void print() {
        for (int i = 0; i < BUCKET_COUNT; i++) {
            cout << i << " : ";
            for (auto &p : table[i]) {
                cout << "(" << p.first << "," << p.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    MyUnorderedMap mp;
    mp.insert("apple", 10);
    mp.insert("banana", 20);
    mp.insert("orange", 30);
    mp.insert("banana", 25); // update

    mp.print();

    int val;
    if (mp.find("banana", val)) cout << "banana = " << val << endl;
    else cout << "banana not found\n";

    mp.erase("apple");
    mp.print();
}
