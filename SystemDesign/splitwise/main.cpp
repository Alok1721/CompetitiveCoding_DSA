#include <bits/stdc++.h>
using namespace std;

class Splitwise {
public:
    unordered_map<string,int> userBalances;

    void addExpense(string paidBy, int amount, vector<string> involvedUsers) {
        int share = amount / involvedUsers.size();

        for (auto &user : involvedUsers) {
            if (user == paidBy) continue;

            userBalances[paidBy] += share;
            userBalances[user]  -= share;
        }
    }

    // Return user with maximum credit
    string findCredit() {
        string maxUser = "";
        int maxBal = INT_MIN;

        for (auto &p : userBalances) {
            if (p.second > maxBal) {
                maxBal = p.second;
                maxUser = p.first;
            }
        }
        return maxUser;
    }

    // Return user with maximum debit
    string findDebit() {
        string minUser = "";
        int minBal = INT_MAX;

        for (auto &p : userBalances) {
            if (p.second < minBal) {
                minBal = p.second;
                minUser = p.first;
            }
        }
        return minUser;
    }

    void showBalances() {
        string credit = findCredit();
        string debit  = findDebit();

        if (userBalances[credit] == 0 && userBalances[debit] == 0) {
            cout << "All balances are settled" << endl;
            return;
        }

        int amount = min(userBalances[credit], -userBalances[debit]);

        cout << debit << " pays " << amount << " to " << credit << endl;

        userBalances[credit] -= amount;
        userBalances[debit]  += amount;

        showBalances();
    }
};

int main() {
    Splitwise sw;

    sw.addExpense("Alice", 120, {"Alice","Bob","Charlie"});
    sw.addExpense("Bob", 60, {"Bob","Charlie"});
    sw.addExpense("Bob", 60, {"Bob","Alice"});

    sw.showBalances();

    return 0;
}
