#ifndef INCOME_H
#define INCOME_H

#include "Transaction.h"

class Income : public Transaction {
public:
    Income(double amount, const std::string& date, const std::string& description);
    std::string getType() const override; // Override del metodo getType
};

#endif // INCOME_H

