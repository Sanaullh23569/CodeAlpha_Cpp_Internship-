#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Transaction class to record transaction type and amount
class Transaction {
public:
    string type;
    double amount;

    Transaction(string t, double a) : type(t), amount(a) {}
};

// Account class to manage balance and history
class Account {
private:
    double balance;
    vector<Transaction> history;

public:
    Account() : balance(0.0) {}

    void deposit(double amount) {
        balance += amount;
        history.emplace_back("Deposit", amount);
        cout << "Amount Deposited: " << amount << "\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance!\n";
        } else {
            balance -= amount;
            history.emplace_back("Withdraw", amount);
            cout << "Amount Withdrawn: " << amount << "\n";
        }
    }

    void transfer(Account& to, double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance for Transfer!\n";
        } else {
            balance -= amount;
            to.balance += amount;
            history.emplace_back("Transfer Sent", amount);
            to.history.emplace_back("Transfer Received", amount);
            cout << "Amount Transferred: " << amount << "\n";
        }
    }

    void showBalance() const {
        cout << "Current Balance: " << balance << "\n";
    }

    void showHistory() const {
        if (history.empty()) {
            cout << "No transactions yet.\n";
            return;
        }
        cout << "Transaction History:\n";
        for (const auto& t : history) {
            cout << t.type << " - " << t.amount << "\n";
        }
    }
};

// Customer class with name and account
class Customer {
public:
    string name;
    Account account;

    Customer(string n) : name(n) {}
};

// Bank System to manage all customers
class BankingSystem {
private:
    vector<Customer> customers;

    int findCustomerIndex(const string& name) {
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i].name == name) return i;
        }
        return -1;
    }

public:
    void createCustomer() {
        string name;
        cout << "Enter new customer name: ";
        cin >> name;
        if (findCustomerIndex(name) != -1) {
            cout << "Customer already exists!\n";
            return;
        }
        customers.emplace_back(name);
        cout << "Customer " << name << " created successfully!\n";
    }

    void depositToCustomer() {
        string name;
        double amount;
        cout << "Enter customer name: ";
        cin >> name;
        int index = findCustomerIndex(name);
        if (index == -1) {
            cout << "Customer not found!\n";
            return;
        }
        cout << "Enter amount to deposit: ";
        cin >> amount;
        customers[index].account.deposit(amount);
    }

    void withdrawFromCustomer() {
        string name;
        double amount;
        cout << "Enter customer name: ";
        cin >> name;
        int index = findCustomerIndex(name);
        if (index == -1) {
            cout << "Customer not found!\n";
            return;
        }
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        customers[index].account.withdraw(amount);
    }

    void transferBetweenCustomers() {
        string sender, receiver;
        double amount;
        cout << "Enter sender name: ";
        cin >> sender;
        cout << "Enter receiver name: ";
        cin >> receiver;

        int senderIndex = findCustomerIndex(sender);
        int receiverIndex = findCustomerIndex(receiver);

        if (senderIndex == -1 || receiverIndex == -1) {
            cout << "Sender or receiver not found!\n";
            return;
        }

        cout << "Enter amount to transfer: ";
        cin >> amount;
        customers[senderIndex].account.transfer(customers[receiverIndex].account, amount);
    }

    void showCustomerDetails() {
        string name;
        cout << "Enter customer name: ";
        cin >> name;
        int index = findCustomerIndex(name);
        if (index == -1) {
            cout << "Customer not found!\n";
            return;
        }
        cout << "\n--- Account Details for " << name << " ---\n";
        customers[index].account.showBalance();
        customers[index].account.showHistory();
    }

    void listAllCustomers() const {
        if (customers.empty()) {
            cout << "No customers registered yet.\n";
            return;
        }
        cout << "List of Customers:\n";
        for (const auto& c : customers) {
            cout << "- " << c.name << "\n";
        }
    }
};

// Main program
int main() {
    BankingSystem bank;
    int choice;

    do {
        cout << "\n===== Banking System Menu =====\n";
        cout << "1. Create Customer\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Transfer\n";
        cout << "5. Show Customer Details\n";
        cout << "6. List All Customers\n";
        cout << "7. Exit\n";
        cout << "Choose option: ";
        cin >> choice;

        switch (choice) {
            case 1: bank.createCustomer(); break;
            case 2: bank.depositToCustomer(); break;
            case 3: bank.withdrawFromCustomer(); break;
            case 4: bank.transferBetweenCustomers(); break;
            case 5: bank.showCustomerDetails(); break;
            case 6: bank.listAllCustomers(); break;
            case 7: cout << "Exiting... Thank you!\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
