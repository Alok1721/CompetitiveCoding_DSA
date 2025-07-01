#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <unordered_map>

std::unordered_map<int, int> hashTable;
std::mutex mtx;

void insertIntoHash(int start, int end) {
    for (int i = start; i <= end; i++) {
        std::lock_guard<std::mutex> lock(mtx);  // auto-lock & unlock
        hashTable[i] = i * i;
    }
}

int main() {
    int numThreads = 4;
    int range = 100;

    std::vector<std::thread> threads;

    for (int i = 0; i < numThreads; i++) {
        int start = i * (range / numThreads) + 1;
        int end = (i + 1) * (range / numThreads);
        threads.emplace_back(insertIntoHash, start, end);
    }

    for (auto& t : threads) {
        t.join();
    }

    // Show some values
    for (int i = 1; i <= 10; i++) {
        std::cout << i << " => " << hashTable[i] << "\n";
    }

    return 0;
}
