#include "BankAccount.h"
#include "Income.h"
#include "Expense.h"
#include <iostream>

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
    transactions = TransactionFileManager::loadTransactions(filename);
    balance = 0.0;
    for (const auto& transaction : transactions) {
        if (transaction->getType() == "Income") {
            balance += transaction->getAmount();
        } else if (transaction->getType() == "Expense") {
            balance -= transaction->getAmount();
        }
    }
}

void BankAccount::saveTransactionsToFile(const std::string& filename) const {
    TransactionFileManager::saveTransactions(filename, transactions);
}



