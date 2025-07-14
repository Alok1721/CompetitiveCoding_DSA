#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#include <queue>
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

int maxMedicalCenters(int n, vector<int>& locations) {
    // Fix: priority_queue of pairs
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < n; ++i) {
        pq.push({locations[i], i});
    }

    // Example of using top() and popping
    while (!pq.empty()) {
        pair<int, int> curr = pq.top();
        pq.pop();
        int location = curr.first;
        int index = curr.second;
        cout << "Location: " << location << ", Index: " << index << endl;
    }

    return 0;
}


int main() {
    int numCity;
    cin >> numCity;

    vector<int> locations(numCity);
    for (int i = 0; i < numCity; ++i) {
        cin >> locations[i];
    }

    cout << maxMedicalCenters(numCity, locations) << endl;

    return 0;
}
