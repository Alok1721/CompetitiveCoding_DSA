#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M; 
    vector<int> employees(N);
    for (int i = 0; i < N; i++) {
        cin >> employees[i];
    }
    
    vector<int> existing_stations(M);
    for (int i = 0; i < M; i++) {
        cin >> existing_stations[i];
    }

    vector<int> buildings(N);
    for (int i = 0; i < N; i++) {
        buildings[i] = i * 100;
    }
    auto calculateEmployees = [&](double pos) -> int {
        int total = 0;
        
        for (int i = 0; i < N; i++) {
            double distToBuilding = abs(pos - buildings[i]);
        
            bool canServe = true;
            for (int j = 0; j < M; j++) {
                double distExisting = abs(buildings[i] - existing_stations[j]);
                if (distToBuilding >= distExisting) {
                    canServe = false;
                    break;
                }
            }
            
            if (canServe) {
                total += employees[i];
            }
        }
        
        return total;
    };
    
    int maxEmployees = 0;
    set<double> criticalPoints;
    for (int i = 0; i < N; i++) {
        criticalPoints.insert(buildings[i]);
    }
    
    for (int i = 0; i < M; i++) {
        criticalPoints.insert(existing_stations[i]);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            double midpoint = (buildings[i] + existing_stations[j]) / 2.0;
            criticalPoints.insert(midpoint);
            if (buildings[i] < existing_stations[j]) {
                criticalPoints.insert(midpoint - 0.1);
            } else {
                criticalPoints.insert(midpoint + 0.1);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        criticalPoints.insert(buildings[i] - 0.1);
        criticalPoints.insert(buildings[i] + 0.1);
    }
    
    for (int i = 0; i < M; i++) {
        criticalPoints.insert(existing_stations[i] - 0.1);
        criticalPoints.insert(existing_stations[i] + 0.1);
    }
    
    for (double pos : criticalPoints) {
        if (pos >= 0 && pos <= (N-1) * 100) { 
            maxEmployees = max(maxEmployees, calculateEmployees(pos));
        }
    }
    
    for (double pos = 0; pos <= (N-1) * 100; pos += 0.5) {
        maxEmployees = max(maxEmployees, calculateEmployees(pos));
    }
    
    cout << maxEmployees << endl;
    
    return 0;
}