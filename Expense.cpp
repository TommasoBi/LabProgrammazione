#include "Expense.h"

Expense::Expense(double amount, const std::string& date, const std::string& description)
        : Transaction(amount, date, description) {}

std::string Expense::getType() const {
    return "Expense";
}

