#include <iomanip>
#include <ctime>
#include <iostream>
#include "Transaction.h"

Transaction::Transaction(double amount, const std::string& dateStr, const std::string& description)
        : amount(amount), description(description) {
    std::istringstream dateStream(dateStr);
    std::tm tm = {};
    dateStream >> std::get_time(&tm, "%Y-%m-%d");
    date = std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getDate() const {
    std::time_t t = std::chrono::system_clock::to_time_t(date);
    std::tm tm = *std::localtime(&t);
    char buf[20];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d", &tm);
    return std::string(buf);
}

std::string Transaction::getDescription() const {
    return description;
}

