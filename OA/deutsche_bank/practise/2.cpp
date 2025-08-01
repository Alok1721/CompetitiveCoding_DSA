#include <iostream>
#include <vector>
using namespace std;

string escalator_loop(int N, vector<int>& next_floor) {
    vector<int> visited(N, -1); // -1: unvisited, otherwise: step number when visited
    
    for (int start = 0; start < N; start++) {
        if (visited[start] != -1) continue; // Already processed
        
        int current = start;
        int step = 0;
        
        // Follow the path until we reach an exit (-1) or detect a cycle
        while (current != -1) {
            if (visited[current] != -1) {
                // We've seen this node before in this path - it's the start of the loop
                return "Loop Detected at Floor " + to_string(current);
            }
            
            visited[current] = step++;
            current = next_floor[current];
        }
    }
    
    return "No Loop Detected";
}

int main() {
    int N;
    cout << "Enter number of floors: ";
    cin >> N;
    
    vector<int> next_floor(N);
    cout << "Enter next floor for each floor (use -1 for exit): ";
    for (int i = 0; i < N; i++) {
        cin >> next_floor[i];
    }
    
    string result = escalator_loop(N, next_floor);
    cout << result << endl;

    
    return 0;
}