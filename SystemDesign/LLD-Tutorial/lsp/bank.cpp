#include<bits/stdc++.h>
using namespace std;
class DepositAccount
{
    public:
    virtual void deposit(double amount)=0;
};
class WithdrawableAccount:public DepositAccount
{
    public:
    virtual void withdraw(double amount)=0;
};

class SavingAccount:public WithdrawableAccount
{
    public:
    double balance;
    void deposit(double amount)
    {
        balance+=amount;
    }
    void withdraw(double amount)
    {
        if(balance<amount)
        {
            throw "Insufficient balance";
        }
        balance-=amount;
    }
};

class CurrentAccount:public WithdrawableAccount
{
    public:
    double balance;
    void deposit(double amount)
    {
        balance+=amount;
    }
    void withdraw(double amount)
    {
        if(balance<amount)
        {
            throw "Insufficient balance";
        }
        balance-=amount;
    }
};

class FixedDepositAccount:public DepositAccount
{
    public:
    double balance;
    void deposit(double amount)
    {
        balance+=amount;
    }
};

class BankClient
{
    public:
    vector<WithdrawableAccount*>withdrawableAccounts;
    vector<DepositAccount*>depositAccounts;
    BankClient(vector<WithdrawableAccount*>withdrawableAccounts,vector<DepositAccount*>depositAccounts)
    {
        this->withdrawableAccounts=withdrawableAccounts;
        this->depositAccounts=depositAccounts;
    }
    void processTransactions()
    {
        for(auto account:withdrawableAccounts)
        {
            account->deposit(200);
            account->withdraw(100);
        }
        for(auto account:depositAccounts)
        {
            account->deposit(100);
        }
    }
};


int main()
{
    vector<WithdrawableAccount*>withdrawableAccounts;
    vector<DepositAccount*>depositAccounts;
    withdrawableAccounts.push_back(new SavingAccount());
    withdrawableAccounts.push_back(new CurrentAccount());
    depositAccounts.push_back(new FixedDepositAccount());
    
    BankClient *client(withdrawableAccounts,depositAccounts);
    client->processTransactions();
    return 0;
}