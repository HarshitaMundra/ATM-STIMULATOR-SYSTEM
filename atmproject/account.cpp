#include "account.h"
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

Account::Account(string acc, string p, double bal) {
    accNumber = acc;
    pin = p;
    balance = bal;
    dailyWithdrawals = 0;
}

string Account::getCurrentTime() {
    time_t now = time(0);
    char* dt = ctime(&now);
    return string(dt);
}

string Account::getAccNumber() {
    return accNumber;
}

bool Account::verify(string enteredPIN) {
    return pin == enteredPIN;
}

void Account::showBalance() {
    cout << "Current Balance: Rs. " << balance << endl;
}

void Account::deposit(double amount) {
    if (amount <= 0) {
        cout << "Invalid deposit amount.\n";
        return;
    }
    balance += amount;
    transactions.push_back({"Deposit", amount, getCurrentTime()});
    logTransaction("Deposit", amount);
    cout << "Deposit successful!\n";
}

void Account::withdraw(double amount) {
    if (dailyWithdrawals >= MAX_WITHDRAWALS) {
        cout << "Daily withdrawal limit reached.\n";
        return;
    }
    if (amount <= 0 || amount > balance) {
        cout << "Invalid or insufficient balance.\n";
        return;
    }
    balance -= amount;
    dailyWithdrawals++;
    transactions.push_back({"Withdraw", amount, getCurrentTime()});
    logTransaction("Withdraw", amount);
    cout << "Withdrawal successful!\n";
}

void Account::miniStatement() {
    cout << "\n--- Last 5 Transactions ---\n";
    int count = 0;
    for (int i = transactions.size() - 1; i >= 0 && count < 5; i--, count++) {
        cout << transactions[i].date << " | " << transactions[i].type << " | Rs. " << transactions[i].amount << "\n";
    }
    if (transactions.empty())
        cout << "No transactions yet.\n";
}

void Account::changePIN(string oldPIN, string newPIN) {
    if (verify(oldPIN)) {
        pin = newPIN;
        cout << "PIN changed successfully.\n";
    } else {
        cout << "Incorrect current PIN.\n";
    }
}

void Account::logTransaction(string type, double amount) {
    ofstream file("transactions.txt", ios::app);
    file << accNumber << "," << type << "," << amount << "," << getCurrentTime();
    file.close();
}
