#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
protected:
    double amount;
    std::string date;
    std::string description;

public:
    Transaction(double amount, const std::string& date, const std::string& description);
    virtual ~Transaction() = default;

    double getAmount() const;
    std::string getDate() const;
    std::string getDescription() const;

    virtual std::string getType() const = 0; // Metodo puro virtuale per ottenere il tipo di transazione
};

#endif // TRANSACTION_H

