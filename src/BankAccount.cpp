#include "BankAccount.h"
#include "Income.h"
#include "Expense.h"
#include <iostream>
#include <fstream>
#include <iomanip>


BankAccount::BankAccount() : balance(0.0) {}

void BankAccount::addTransaction(const std::shared_ptr<Transaction>& transaction) {
    transactions.push_back(transaction);
    if (transaction->getType() == "Income") {
        balance += transaction->getAmount();
    } else if (transaction->getType() == "Expense") {
        balance -= transaction->getAmount();
    }
}

double BankAccount::getBalance() const {
    return balance;
}

void BankAccount::printTransactions() const {
    for (const auto& transaction : transactions) {
        std::cout << transaction->getType() << ": "
                  << transaction->getAmount() << " on "
                  << transaction->getDate() << " - "
                  << transaction->getDescription() << std::endl;
    }
}

void BankAccount::loadTransactionsFromFile(const std::string& filename) {
    transactions.clear();
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    std::string type, date, description;
    double amount;
    while (file >> type >> amount >> date >> std::ws) {
        std::getline(file, description);
        if (type == "Income") {
            transactions.push_back(std::make_shared<Income>(amount, date, description));
            balance += amount;
        } else if (type == "Expense") {
            transactions.push_back(std::make_shared<Expense>(amount, date, description));
            balance -= amount;
        }
    }

    file.close();
}

void BankAccount::saveTransactionsToFile(const std::string& filename) const {
    std::ofstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    for (const auto& transaction : transactions) {
        file << transaction->getType() << " "
             << transaction->getAmount() << " "
             << transaction->getDate() << " "
             << transaction->getDescription() << std::endl;
    }

    file.close();
}



