#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <vector>
#include <memory>
#include "Transaction.h"

class BankAccount {
private:
    double balance;
    std::vector<std::shared_ptr<Transaction>> transactions;

public:
    BankAccount();
    void addTransaction(const std::shared_ptr<Transaction>& transaction);
    double getBalance() const;
    void printTransactions() const;

    void loadTransactionsFromFile(const std::string& filename);
    void saveTransactionsToFile(const std::string& filename) const;

    class NullTransactionException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Invalid transaction: amount cannot be 0";
        }
    };
};

#endif // BANKACCOUNT_H


