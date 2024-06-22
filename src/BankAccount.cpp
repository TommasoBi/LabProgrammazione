#include "BankAccount.h"
#include "Income.h"
#include "Expense.h"
#include <iostream>
#include <fstream>
#include <iomanip>


BankAccount::BankAccount() : balance(0.0) {}

void BankAccount::updateBalance() {
    balance = 0.0;
    for (const auto& transaction : transactions) {
        if (transaction->getType() == "Income") {
            balance += transaction->getAmount();
        } else if (transaction->getType() == "Expense") {
            balance -= transaction->getAmount();
        }
    }
}

void BankAccount::addTransaction(const std::shared_ptr<Transaction>& transaction) {
    if (transaction->getAmount() == 0) {
        throw NullTransactionException();
    }

    transactions.push_back(transaction);
    updateBalance();
}

void BankAccount::removeTransaction(size_t index) {
    if (index < 1 || index > transactions.size()) {
        throw std::out_of_range("Invalid transaction index");
    }

    auto transaction = transactions[index - 1];
    if (transaction->getType() == "Income") {
        balance -= transaction->getAmount();
    } else if (transaction->getType() == "Expense") {
        balance += transaction->getAmount();
    }

    transactions.erase(transactions.begin() + (index - 1));
    updateBalance();
}

void BankAccount::updateTransaction(size_t index, const std::shared_ptr<Transaction>& newTransaction) {
    if (index < 1 || index > transactions.size()) {
        throw std::out_of_range("Invalid transaction index");
    }

    auto oldTransaction = transactions[index - 1];
    if (oldTransaction->getType() == "Income") {
        balance -= oldTransaction->getAmount();
    } else if (oldTransaction->getType() == "Expense") {
        balance += oldTransaction->getAmount();
    }

    if (newTransaction->getAmount() == 0) {
        throw NullTransactionException();
    }

    transactions[index - 1] = newTransaction;
    updateBalance();
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

void BankAccount::load(const std::string& filename) {
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
    updateBalance();
    file.close();
}

void BankAccount::save(const std::string& filename) const {
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



