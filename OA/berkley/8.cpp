#include <iostream>
#include <vector>
using namespace std;

vector<int> commonFootSteps(int fatherPos, int martinPos, int velFather, int steps) {
    vector<int> answer(2, 0); // answer[0] = max count, answer[1] = best velocity for Martin
    vector<int> distances(steps + 1);

    // Calculate father's relative position to Martin for each step
    for (int i = 0; i <= steps; i++) {
        distances[i] = fatherPos + velFather * i - martinPos;
    }

    // Check each possible starting step
    for (int i = 0; i <= steps; i++) {
        if (distances[i] <= 0) continue; // Martin must run forward

        int v2 = distances[i]; // Martin's speed candidate
        int count = 0;

        // Count how many times Martin's step lands on father's footsteps
        for (int j = i; j <= steps; j++) {
            if (distances[j] % v2 == 0) count++;
        }

        // Update if we found a better or equal count (priority to latest v2 in ties)
        if (answer[0] <= count) {
            answer[0] = count;
            answer[1] = v2;
        }
    }

    return answer;
}

int main() {
    int x1, x2, v, n;
    cin >> x1 >> x2 >> v >> n;

    vector<int> result = commonFootSteps(x1, x2, v, n);
    for (int val : result) cout << val << " ";
    return 0;
}
