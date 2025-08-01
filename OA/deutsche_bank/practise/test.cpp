#include <iostream>
#include <vector>
using namespace std;

string escalator_loop(int N, vector<int>& next_floor) {
    if (N <= 0) return "No Loop Detected";

    for (int i = 0; i < N; i++) {
        if (next_floor[i] == -1) continue;  // Skip exit floors

        // Floyd's Tortoise and Hare
        int slow = i, fast = i;

        // Phase 1: Find meeting point
        do {
            slow = next_floor[slow];
            if (slow == -1) break;

            fast = next_floor[fast];
            if (fast == -1) break;
            fast = next_floor[fast];
            if (fast == -1) break;
        } while (slow != fast);

        // Phase 2: Find cycle start
        if (slow != -1 && slow == fast) {
            slow = i;
            while (slow != fast) {
                slow = next_floor[slow];
                fast = next_floor[fast];
            }
            return "Loop Detected at Floor " + to_string(slow);
        }
    }
    return "No Loop Detected";
}

int main() {
    int N;
    cin >> N;
    vector<int> next_floor(N);
    for (int i = 0; i < N; i++) {
        cin >> next_floor[i];
    }
    cout << escalator_loop(N, next_floor) << endl;
    return 0;
}