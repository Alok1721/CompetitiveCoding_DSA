#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int i = 0, hikes = 0;

        while (i <= n - k) {
            // Check if we can start a hike from index i
            bool canHike = true;
            for (int j = 0; j < k; j++) {
                if (a[i + j] == 1) {
                    canHike = false;
                    break;
                }
            }

            if (canHike) {
                hikes++;
                i += k + 1; // Skip k days of hike + 1 day of rest
            } else {
                i++;
            }
        }

        cout << hikes << '\n';
    }
    return 0;
}
