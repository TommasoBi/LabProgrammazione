#include "Transaction.h"

Transaction::Transaction(double amount, const std::string& date, const std::string& description)
        : amount(amount), date(date), description(description) {}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getDate() const {
    return date;
}

std::string Transaction::getDescription() const {
    return description;
}

