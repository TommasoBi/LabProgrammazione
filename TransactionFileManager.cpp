#include "TransactionFileManager.h"
#include "Income.h"
#include "Expense.h"
#include <fstream>
#include <iostream>

std::vector<std::shared_ptr<Transaction>> TransactionFileManager::loadTransactions(const std::string& filename) {
    std::vector<std::shared_ptr<Transaction>> transactions;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return transactions;
    }

    std::string type, date, description;
    double amount;
    while (file >> type >> amount >> date >> std::ws) {
        std::getline(file, description);
        if (type == "Income") {
            transactions.push_back(std::make_shared<Income>(amount, date, description));
        } else if (type == "Expense") {
            transactions.push_back(std::make_shared<Expense>(amount, date, description));
        }
    }

    file.close();
    return transactions;
}

void TransactionFileManager::saveTransactions(const std::string& filename, const std::vector<std::shared_ptr<Transaction>>& transactions) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    for (const auto& transaction : transactions) {
        file << transaction->getType() << " "
             << transaction->getAmount() << " "
             << transaction->getDate() << " "
             << transaction->getDescription() << std::endl;
    }

    file.close();
}


