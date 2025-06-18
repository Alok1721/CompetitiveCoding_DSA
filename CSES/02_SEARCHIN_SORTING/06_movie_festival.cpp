#include <bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;



int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        movies[i] = {end, start}; // Store as (end time, start time)
    }
    sort(movies.begin(), movies.end()); // Sort by end time
    int count = 0;
    int last_end_time = 0; // Track the end time of the last selected movie
    for (const auto& movie : movies) {
        if (movie.second >= last_end_time) { // If the start time is after or equal to the last end time
            count++;
            last_end_time = movie.first; // Update the last end time to the current movie's end time
        }
    }
    cout << count << endl; // Output the maximum number of movies that can be watched
    return 0;
}