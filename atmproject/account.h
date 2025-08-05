
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

using namespace std;

struct Transaction {
    string type;
    double amount;
    string date;
};

class Account {
private:
    string accNumber;
    string pin;
    double balance;
    int dailyWithdrawals;
    vector<Transaction> transactions;
    const int MAX_WITHDRAWALS = 3;

public:
    Account(string acc, string p, double bal);
    string getAccNumber();
    bool verify(string enteredPIN);
    void showBalance();
    void deposit(double amount);
    void withdraw(double amount);
    void miniStatement();
    void changePIN(string oldPIN, string newPIN);

private:
    string getCurrentTime();
    void logTransaction(string type, double amount);
};

#endif
