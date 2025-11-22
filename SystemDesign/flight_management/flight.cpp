#include <bits/stdc++.h>
#include <atomic>
#include <mutex>
using namespace std;


/*
 * Complete the 'TrafficLight' class below.
 *
 * You only need to implement the constructor and the carArrived method.
 * Do NOT add any extra includes or functions.
 */

class TrafficLight {
private:
    // TODO: Add your member variables here (mutex, atomic, etc.)
    mutex mtx;
    int greenRoad = 1; // 1 for Road A, 2 for Road B

public:
    TrafficLight() {
        // Initially Road A (roadId = 1) has green light
        // Write initialization code here if needed

    }

    void carArrived(
        int carId,                  // ID of the car
        int roadId,                 // 1 = Road A, 2 = RoadId B
        int direction,              // 1-4, you can ignore it
        function<void()> turnGreen, // Callback to turn light green for this road
        function<void()> crossCar   // Callback to let this car cross
    ) {
        // ←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←
        //   WRITE YOUR CODE ONLY INSIDE THIS FUNCTION
        // ←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←
        lock_guard<mutex> lk(mtx);
        if(greenRoad != roadId) {
            turnGreen();
            greenRoad = roadId;
        }
        crossCar();
        
        
        // ←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←
        //   END OF YOUR CODE
        // ←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←
    }
};

// ====================================================================
// ================= DO NOT MODIFY ANYTHING BELOW THIS LINE ===========
// ====================================================================

class ThreadPool {
public:
    ThreadPool(int n) { /* implementation hidden */ }
    void execute(function<void()> task) { /* hidden */ }
    void wait() { /* hidden */ }
    ~ThreadPool() { /* hidden */ }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    TrafficLight trafficLight;

    int n;
    cin >> n;                          // number of cars
    vector<vector<int>> arrivals(n, vector<int>(3));
    
    for (int i = 0; i < n; i++) {
        cin >> arrivals[i][0] >> arrivals[i][1] >> arrivals[i][2];
        // format: arrival_time carId roadId
    }

    atomic<int> greenChanges = 0;
    mutex coutMutex;

    ThreadPool pool(10);

    auto start = chrono::high_resolution_clock::now();

    for (auto& arr : arrivals) {
        int delayMs = arr[0];
        int carId = arr[1];
        int roadId = arr[2];

        this_thread::sleep_until(start + chrono::milliseconds(delayMs));

        pool.execute([&, carId, roadId]() {
            trafficLight.carArrived(
                carId,
                roadId,
                1,  // direction doesn't matter
                [&greenChanges]() {
                    greenChanges++;
                    // System calls turnGreen for this road
                },
                [carId, roadId, &coutMutex]() {
                    lock_guard<mutex> lk(coutMutex);
                    cout << carId << endl;   // prints car crossing order
                }
            );
        });
    }

    pool.wait();

    cout << "GREEN_CHANGES:" << greenChanges.load() << endl;
    return 0;
}