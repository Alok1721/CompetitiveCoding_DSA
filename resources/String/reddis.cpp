#include<bits/stdc++.h>

using namespace std;

class Reddish
{
    private: 
        unordered_map<string,string> memory;
        list<string> lru;  // To maintain the order of key access (MRU at front, LRU at back)
        unordered_map<string, list<string>::iterator> keyItr; // To store iterator for O(1) access
        int capacity;
    public:
        Reddish(int capacity)
        {
            this->capacity = capacity;
        }
        
        void set(string key, string value)
        {
            // If key already exists, update its value and move it to front
            if(memory.find(key) != memory.end()) {
                // Remove from current position in list
                lru.erase(keyItr[key]);
            }
            // If cache is full, remove LRU item
            else if(memory.size() >= capacity) {
                string lruKey = lru.back();
                lru.pop_back();
                memory.erase(lruKey);
                keyItr.erase(lruKey);
            }
            
            // Add/update key
            memory[key] = value;
            lru.push_front(key);
            keyItr[key] = lru.begin();
        }
        
        string get(string key)
        {
            if(memory.find(key) == memory.end()) return "";
            
            // Move the accessed key to front (MRU position)
            lru.erase(keyItr[key]);
            lru.push_front(key);
            keyItr[key] = lru.begin();
            
            return memory[key];
        }
};

int main()
{
    Reddish cache(2);
    cache.set("name","Alok");
    cout << cache.get("name") << endl;   // Alok
    cache.set("age","20");
    cout << cache.get("age") << endl;    // 20
    cache.set("city","Delhi");          // Evicts "name" as it was LRU
    cout << cache.get("city") << endl;   // Delhi
    cout << cache.get("name") << endl;   // "" (not found, was evicted)
    cout << cache.get("age") << endl;    // 20
    
    return 0;
}
