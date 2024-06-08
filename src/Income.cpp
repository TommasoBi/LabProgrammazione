#include "Income.h"

Income::Income(double amount, const std::string& date, const std::string& description)
        : Transaction(amount, date, description) {}

std::string Income::getType() const {
    return "Income";
}
