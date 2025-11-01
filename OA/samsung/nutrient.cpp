#include <bits/stdc++.h>
using namespace std;

struct Nutrient {
    int p, f, c;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;
        vector<Nutrient> ingredients(k);

        for (int i = 0; i < k; i++) {
            cin >> ingredients[i].p >> ingredients[i].f >> ingredients[i].c;
        }

        vector<Nutrient> targets(3);
        for (int i = 0; i < 3; i++) {
            cin >> targets[i].p >> targets[i].f >> targets[i].c;
        }

        int totalComb = 1 << k;

        for (auto &target : targets) {
            vector<int> best;
            int minCount = INT_MAX;

            for (int mask = 1; mask < totalComb; mask++) {
                int tp = 0, tf = 0, tc = 0;
                vector<int> used;

                for (int j = 0; j < k; j++) {
                    if (mask & (1 << j)) {
                        tp += ingredients[j].p;
                        tf += ingredients[j].f;
                        tc += ingredients[j].c;
                        used.push_back(j + 1); // 1-based indexing
                    }
                }

                if (tp == target.p && tf == target.f && tc == target.c) {
                    if ((int)used.size() < minCount ||
                        ((int)used.size() == minCount && used < best)) {
                        best = used;
                        minCount = used.size();
                    }
                }
            }

            if (best.empty()) {
                cout << "-1\n"; // if no combination matches
            } else {
                for (int i = 0; i < (int)best.size(); i++) {
                    cout << best[i] << (i + 1 == (int)best.size() ? '\n' : ' ');
                }
            }
        }
    }
    return 0;
}
