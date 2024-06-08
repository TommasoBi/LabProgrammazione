#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <vector>
#include <memory>
#include "Transaction.h"
#include "TransactionFileManager.h"

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
};

#endif // BANKACCOUNT_H


