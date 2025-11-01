#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("Error.txt", "w", stderr);
	#endif

	int t = 1;
	cin >> t;  // Read the number of test cases

	while (t--) {
		ll n, k;
		cin >> n >> k;  // Read the number of elements and operations

		vector<ll> v(n);  // Initialize a vector to store the elements
		for (auto &it : v) cin >> it;  // Read the elements into the vector

		sort(v.begin(), v.end());  // Sort the vector in non-decreasing order

		vector<ll> pre(n);  // Initialize a prefix sum array
		pre[0] = v[0];  // Set the first element of the prefix sum array
		for (int i = 1; i < n; i++) {  // Compute the prefix sums
			pre[i] = v[i] + pre[i - 1];
		}

		ll ans = 0;  // Initialize the maximum sum
		for (int first = 0; first <= k; first++) {  // Iterate over possible numbers of first operations
			int second = k - first;  // Calculate the number of second operations
			int left = 2 * first;  // Calculate the number of elements removed by first operations
			int right = n - second - 1;  // Calculate the index of the last element not removed by second operations
			ll sum = pre[right] - (left == 0 ? 0 : pre[left - 1]);  // Calculate the sum of remaining elements
			ans = max(ans, sum);  // Update the maximum sum
		}

		cout << ans << endl;  // Output the maximum possible sum

		// Time Complexity (TC): O(nlogn)
		// Space Complexity (SC): O(n)
	}

	return 0;
}
