#include <iostream>
#include <memory>
#include "BankAccount.h"
#include "Income.h"
#include "Expense.h"

void showMenu() {
    std::cout << "----------------------------------\n";
    std::cout << "1. Add Income\n";
    std::cout << "2. Add Expense\n";
    std::cout << "3. Show Balance\n";
    std::cout << "4. Show Transactions\n";
    std::cout << "5. Load Transactions from File\n";
    std::cout << "6. Save Transactions to File\n";
    std::cout << "7. Exit\n";
    std::cout << "----------------------------------\n";
    std::cout << "Choose an option: ";
}

int main() {
    BankAccount account;
    int choice;
    bool running = true;
    std::string filename = "transactions.txt";

    while (running) {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                double amount;
                std::string date, description;
                std::cout << "Enter amount: ";
                std::cin >> amount;
                std::cout << "Enter date (YYYY-MM-DD): ";
                std::cin >> date;
                std::cout << "Enter description: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                account.addTransaction(std::make_shared<Income>(amount, date, description));
                break;
            }
            case 2: {
                double amount;
                std::string date, description;
                std::cout << "Enter amount: ";
                std::cin >> amount;
                std::cout << "Enter date (YYYY-MM-DD): ";
                std::cin >> date;
                std::cout << "Enter description: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                account.addTransaction(std::make_shared<Expense>(amount, date, description));
                break;
            }
            case 3: {
                std::cout << "Current balance: " << account.getBalance() << std::endl;
                break;
            }
            case 4: {
                account.printTransactions();
                break;
            }
            case 5: {
                account.loadTransactionsFromFile(filename);
                break;
            }
            case 6: {
                account.saveTransactionsToFile(filename);
                break;
            }
            case 7: {
                running = false;
                break;
            }
            default: {
                std::cout << "Invalid option. Please try again." << std::endl;
                break;
            }
        }
    }

    return 0;
}
