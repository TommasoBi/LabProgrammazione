#ifndef TRANSACTIONFILEMANAGER_H
#define TRANSACTIONFILEMANAGER_H

#include <string>
#include <vector>
#include <memory>
#include "Transaction.h"

class TransactionFileManager {
public:
    static std::vector<std::shared_ptr<Transaction>> loadTransactions(const std::string& filename);
    static void saveTransactions(const std::string& filename, const std::vector<std::shared_ptr<Transaction>>& transactions);
};

#endif // TRANSACTIONFILEMANAGER_H

