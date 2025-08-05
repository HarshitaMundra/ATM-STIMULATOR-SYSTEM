#include "account.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<Account> accounts;
    accounts.push_back(Account("123456", "1234", 10000));
    accounts.push_back(Account("654321", "4321", 5000));

    string accNum, pin;
    cout << "Enter Account Number: ";
    cin >> accNum;
    cout << "Enter PIN: ";
    cin >> pin;

    Account* user = nullptr;
    for (auto& acc : accounts) {
        if (acc.getAccNumber() == accNum && acc.verify(pin)) {
            user = &acc;
            break;
        }
    }

    if (!user) {
        cout << "Invalid account number or PIN.\n";
        return 0;
    }

    int choice;
    do {
        cout << "\n--- ATM Menu ---\n";
        cout << "1. Balance Inquiry\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Mini Statement\n";
        cout << "5. Change PIN\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                user->showBalance();
                break;
            case 2: {
                double amount;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                user->deposit(amount);
                break;
            }
            case 3: {
                double amount;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                user->withdraw(amount);
                break;
            }
            case 4:
                user->miniStatement();
                break;
            case 5: {
                string oldPIN, newPIN;
                cout << "Enter current PIN: ";
                cin >> oldPIN;
                cout << "Enter new PIN: ";
                cin >> newPIN;
                user->changePIN(oldPIN, newPIN);
                break;
            }
            case 6:
                cout << "Thank you for using the ATM.\n";
                break;
            default:
                cout << "Invalid option.\n";
        }
    } while (choice != 6);

    return 0;
}
