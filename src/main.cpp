#include <iostream>
#include <memory>
#include <limits>
#include "BankAccount.h"
#include "Income.h"
#include "Expense.h"

void showMenu() {
    std::cout << "----------------------------------\n";
    std::cout << "1. Add Income\n";
    std::cout << "2. Add Expense\n";
    std::cout << "3. Show Balance\n";
    std::cout << "4. Show Transactions\n";
    std::cout << "5. Remove Transaction\n";
    std::cout << "6. Update Transaction\n";
    std::cout << "7. Search Transactions by Date\n";
    std::cout << "8. Load Transactions from File\n";
    std::cout << "9. Save Transactions to File\n";
    std::cout << "10. Exit\n";
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
                size_t index;
                std::cout << "Enter the transaction index to remove (starting from 1): ";
                std::cin >> index;
                account.removeTransaction(index);
                break;
            }
            case 6: {
                size_t index;
                double amount;
                std::string date, description, type;
                std::cout << "Enter the transaction index to update (starting from 1): ";
                std::cin >> index;
                std::cout << "Enter new type (Income/Expense): ";
                std::cin >> type;
                std::cout << "Enter new amount: ";
                std::cin >> amount;
                std::cout << "Enter new date (YYYY-MM-DD): ";
                std::cin >> date;
                std::cout << "Enter new description: ";
                std::cin.ignore();
                std::getline(std::cin, description);

                if (type == "Income") {
                    account.updateTransaction(index, std::make_shared<Income>(amount, date, description));
                } else if (type == "Expense") {
                    account.updateTransaction(index, std::make_shared<Expense>(amount, date, description));
                } else {
                    std::cerr << "Invalid transaction type." << std::endl;
                }
                break;
            }
            case 7: {
                std::string date;
                std::cout << "Enter date to search (YYYY-MM-DD): ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, date);
                auto results = account.searchTransactionsByDate(date);
                if (results.empty()) {
                    std::cout << "No transactions found for date: " << date << std::endl;
                } else {
                    std::cout << "Transactions for date " << date << ":" << std::endl;
                    for (const auto& transaction : results) {
                        std::cout << transaction->getType() << ": "
                                  << transaction->getAmount() << " on "
                                  << transaction->getDate() << " - "
                                  << transaction->getDescription() << std::endl;
                    }
                }
                break;
            }
            case 8: {
                account.load(filename);
                break;
            }
            case 9: {
                account.save(filename);
                break;
            }
            case 10: {
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
