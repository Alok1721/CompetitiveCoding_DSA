#include<bits/stdc++.h>
using namespace std;

class Splitwise
{
   private:
    // balance[a][b] = amount a owes b
    unordered_map<string, unordered_map<string, double>> balance;

public:
    void addExpense(string paidBy, double amount, vector<string> users) {
        int n = users.size();
        double share = amount / n;

        for (string &user : users) {
            if (user == paidBy) continue;
            balance[user][paidBy] += share;
            balance[paidBy][user] -= share;
        }
    }

    void showBalances() {
        bool empty = true;

        for (auto &u1 : balance) {
            for (auto &u2 : u1.second) {
                double amt = u2.second;
                if (amt > 0.0) {
                    empty = false;
                    cout << u1.first << " owes " << u2.first << ": " << amt << "\n";
                }
            }
        }

        if (empty) cout << "No balances\n";
    }
};

int main()
{
    Splitwise sw;
    sw.addExpense("Alice",120,{"Alice","Bob","Charlie"});
    sw.addExpense("Bob",60,{"Bob","Charlie"});
    sw.addExpense("Bob",60,{"Bob","Alice"});
    sw.showBalances();
    return 0;
}