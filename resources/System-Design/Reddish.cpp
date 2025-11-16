#include <iostream>
#include <unordered_map>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

class Reddish {
private:
    unordered_map<string, string> store;             // key -> value
    unordered_map<string, steady_clock::time_point> expiry; // key -> expiry time

    bool isExpired(const string &key) {
        auto it = expiry.find(key);
        if (it != expiry.end()) {
            if (steady_clock::now() > it->second) {
                store.erase(key);
                expiry.erase(key);
                return true;
            }
        }
        return false;
    }

public:
    void set(const string &key, const string &value, int ttlSeconds = 0) {
        store[key] = value;
        if (ttlSeconds > 0) {
            expiry[key] = steady_clock::now() + seconds(ttlSeconds);
        } else {
            expiry.erase(key);
        }
    }

    string get(const string &key) {
        if (store.find(key) == store.end()) return "NULL";
        if (isExpired(key)) return "NULL";
        return store[key];
    }

    void del(const string &key) {
        store.erase(key);
        expiry.erase(key);
    }

    void keys() {
        cout << "Keys: ";
        for (auto it = store.begin(); it != store.end(); ) {
            if (isExpired(it->first)) {
                it = store.erase(it);
            } else {
                cout << it->first << " ";
                ++it;
            }
        }
        cout << endl;
    }
};

int main() {
    Reddish db;
    db.set("company", "Samsung");
    db.set("session", "active", 2);  // expires after 2 seconds

    cout << "company: " << db.get("company") << endl;
    cout << "session: " << db.get("session") << endl;

    this_thread::sleep_for(chrono::seconds(3));  // wait 3 seconds

    cout << "After 3 seconds..." << endl;
    cout << "session: " << db.get("session") << endl;
    db.keys();

    return 0;
}
