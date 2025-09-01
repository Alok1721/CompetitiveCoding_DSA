#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int a, int b, vector<int> c) {
    long long river_width = a;
    long long max_jump = b;
    int num_platforms = c.size();

    long long total_platform_size = 0;
    for (int platform_size : c) {
        total_platform_size += platform_size;
    }

    long long total_gap_size = river_width - total_platform_size;
    long long num_gaps = num_platforms + 1;
    long long max_single_gap = max_jump - 1;

    if (total_gap_size > num_gaps * max_single_gap) {
        return {-1};
    }

    vector<long long> gaps(num_gaps);
    long long remaining_gap_size = total_gap_size;

    for (int i = 0; i < num_gaps; ++i) {
        long long gap_val = min(remaining_gap_size, max_single_gap);
        gaps[i] = gap_val;
        remaining_gap_size -= gap_val;
    }

    vector<int> result(river_width, 0);
    long long current_pos = 0;

    for (int i = 0; i < num_platforms; ++i) {
        current_pos += gaps[i];
        for (int j = 0; j < c[i]; ++j) {
            if (current_pos + j < river_width) {
                result[current_pos + j] = i + 1;
            }
        }
        current_pos += c[i];
    }

    return result;
}

int main() {
    int a;
    cin >> a; // number of platforms
    int b;
    cin >> b; // max jump
    int n;
    cin>>n;
    vector<int> C(n);
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }
    auto result = solution(a, b, C);
    for (const auto& step : result) {
        cout << step << " ";
    }
    cout << endl;
    return 0;
}
