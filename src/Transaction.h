#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <chrono>
#include <string>
#include <sstream>

class Transaction {
protected:
    double amount;
    std::chrono::system_clock::time_point date;
    std::string description;

public:
    Transaction(double amount, const std::string& dateStr, const std::string& description);
    virtual ~Transaction() = default;

    double getAmount() const;
    std::string getDate() const;
    std::string getDescription() const;

    virtual std::string getType() const = 0; // Metodo puro virtuale per ottenere il tipo di transazione
};

#endif // TRANSACTION_H

