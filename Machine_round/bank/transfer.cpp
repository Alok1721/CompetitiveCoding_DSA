#include<bits/stdc++.h>
using namespace std;
class Account
{
    public:
    int balance;
    Account(int balance)
    {
        this->balance=balance;
    }

};

class Bank
{
    public:
    map<int,Account*> accounts;
    int accountNumber=0;
    void addAccount(Account *account)
    {
        accounts[accountNumber]=account;
        accountNumber++;
    }
    void transfer(int from, int to, int amount)
    {
        if(accounts.find(from)==accounts.end() || accounts.find(to)==accounts.end())
        {
            cout<<"Invalid account number"<<endl;
            return;
        }
        if(accounts[from]->balance<amount)
        {
            cout<<"Insufficient balance"<<endl;
            return;
        }
        depositAmount(to,amount);
        withdrawAmount(from,amount);
    }
    void getBalance(int accountNumber)
    {
        if(accounts.find(accountNumber)==accounts.end())
        {
            cout<<"Invalid account number"<<endl;
            return;
        }
        cout<<accounts[accountNumber]->balance<<endl;
    }
    void removeAccount(int accountNumber)
    {
        if(accounts.find(accountNumber)==accounts.end())
        {
            cout<<"Invalid account number"<<endl;
            return;
        }
        accounts.erase(accountNumber);
    }
    void depositAmount(int accountNumber, int amount)
    {
        accounts[accountNumber]->balance+=amount;
    }
    void withdrawAmount(int accountNumber, int amount)
    {
        if(accounts[accountNumber]->balance<amount)
        {
            cout<<"Insufficient balance"<<endl;
            return;
        }
        accounts[accountNumber]->balance-=amount;
    }

};


int main()
{
    Bank *bank=new Bank();
    bank->addAccount(new Account(1000));
    bank->addAccount(new Account(2000));
    bank->transfer(0,1,500);
    bank->getBalance(0);
    bank->getBalance(1);
    bank->removeAccount(0);
    bank->getBalance(0);
    bank->getBalance(1);
    return 0;
}