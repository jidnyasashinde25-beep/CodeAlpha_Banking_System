#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount
{
public:
    string name;
    int accountNumber;
    float balance;

    void createAccount()
    {
        cout << "\nEnter Account Holder Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cout << "Enter Initial Balance: ";
        cin >> balance;

        ofstream file("accounts.txt", ios::app);
        file << accountNumber << " " << name << " " << balance << endl;
        file.close();

        cout << "\nAccount Created Successfully!\n";
    }

    void deposit()
    {
        float amount;

        cout << "\nEnter Deposit Amount: ";
        cin >> amount;

        balance += amount;

        cout << "Amount Deposited Successfully!\n";
        cout << "Updated Balance: ₹" << balance << endl;
    }

    void withdraw()
    {
        float amount;

        cout << "\nEnter Withdrawal Amount: ";
        cin >> amount;

        if (amount > balance)
        {
            cout << "Insufficient Balance!\n";
        }
        else
        {
            balance -= amount;
            cout << "Withdrawal Successful!\n";
            cout << "Remaining Balance: ₹" << balance << endl;
        }
    }

    void checkBalance()
    {
        cout << "\nCurrent Balance: ₹" << balance << endl;
    }
};

int main()
{
    BankAccount account;
    int choice;

    do
    {
        cout << "\n====== BANKING SYSTEM ======\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            account.createAccount();
            break;

        case 2:
            account.deposit();
            break;

        case 3:
            account.withdraw();
            break;

        case 4:
            account.checkBalance();
            break;

        case 5:
            cout << "\nThank You for Using Banking System!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
