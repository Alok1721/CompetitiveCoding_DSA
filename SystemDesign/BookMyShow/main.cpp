#include <bits/stdc++.h>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

vector<mutex> mtxs(100);   // max 100 seats

enum SeatStatus { AVAILABLE, HELD, BOOKED };

class Show {
public:
    vector<SeatStatus> seats;

    Show(int n) {
        seats.resize(n, AVAILABLE);
    }

    void displaySeats() {
        cout << "Seat Status: ";
        for (int i = 0; i < seats.size(); i++)
            cout << "[" << i << ":" << seats[i] << "] ";
        cout << endl;
    }

    bool holdSeat(vector<int> seatNumbers) {
        sort(seatNumbers.begin(), seatNumbers.end()); // avoid deadlock

        vector<unique_lock<mutex>> locks;
        locks.reserve(seatNumbers.size());

        for (int seat : seatNumbers)
            locks.emplace_back(mtxs[seat]);

        // Check if available
        for (int seat : seatNumbers) {
            if (seats[seat] != AVAILABLE) {
                cout << "Seat " << seat << " cannot be held\n";
                return false;
            }
        }

        // Hold seats
        for (int seat : seatNumbers)
            seats[seat] = HELD;

        cout << "Seats held: ";
        for (int s : seatNumbers) cout << s << " ";
        cout << endl;

        return true;
    }

    bool bookSeat(vector<int> seatNumbers) {
        sort(seatNumbers.begin(), seatNumbers.end());

        vector<unique_lock<mutex>> locks;
        locks.reserve(seatNumbers.size());

        for (int seat : seatNumbers)
            locks.emplace_back(mtxs[seat]);

        // Check if still held
        for (int seat : seatNumbers) {
            if (seats[seat] != HELD) {
                cout << "Seat " << seat << " cannot be booked\n";
                return false;
            }
        }

        // Book seats
        for (int seat : seatNumbers)
            seats[seat] = BOOKED;

        cout << "Seats booked: ";
        for (int s : seatNumbers) cout << s << " ";
        cout << endl;

        return true;
    }

    void releaseSeat(vector<int> seatNumbers) {
        sort(seatNumbers.begin(), seatNumbers.end());

        vector<unique_lock<mutex>> locks;
        locks.reserve(seatNumbers.size());

        for (int seat : seatNumbers)
            locks.emplace_back(mtxs[seat]);

        for (int seat : seatNumbers) {
            if (seats[seat] == HELD)
                seats[seat] = AVAILABLE;
        }

        cout << "Seats released: ";
        for (int s : seatNumbers) cout << s << " ";
        cout << endl;
    }
};

void processBooking(Show* show, vector<int> seats) {
    if (!show->holdSeat(seats)) {
        cout << "Hold failed.\n";
        return;
    }

    this_thread::sleep_for(chrono::seconds(2)); // simulate payment

    if (!show->bookSeat(seats))
        show->releaseSeat(seats);

    cout << "Process Finished.\n";
}

int main() {
    Show show(10);
    show.displaySeats();
    cout << endl;

    thread t1(processBooking, &show, vector<int>{2, 3, 4});
    thread t2(processBooking, &show, vector<int>{6, 7, 8});
    thread t3(processBooking, &show, vector<int>{3, 4, 5});

    t1.join();
    t2.join();
    t3.join();

    show.displaySeats();
    return 0;
}
