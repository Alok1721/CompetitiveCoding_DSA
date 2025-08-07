#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of steps: ";
    cin >> n;

    vector<int> A(n), B(n);
    cout << "Enter book IDs: ";
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    cout << "Enter changes in copies: ";
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }

    unordered_map<int, int> bookCount;  // bookId -> count
    vector<int> result(n);

    for (int i = 0; i < n; ++i) {
        int bookId = A[i];
        int change = B[i];

        // Update book count
        bookCount[bookId] += change;

        // Remove book if count becomes 0 or negative
        if (bookCount[bookId] <= 0) {
            bookCount.erase(bookId);
        }

        // Find maximum count among all books
        int maxCount = 0;
        for (const auto& pair : bookCount) {
            maxCount = max(maxCount, pair.second);
        }

        result[i] = maxCount;
    }

    cout << "Result: ";
    for (int i = 0; i < n; i++) {
        cout << result[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;

    return 0;
}