#ifndef EXPENSE_H
#define EXPENSE_H

#include "Transaction.h"

class Expense : public Transaction {
public:
    Expense(double amount, const std::string& date, const std::string& description);
    std::string getType() const override; // Override del metodo getType
};

#endif // EXPENSE_H

