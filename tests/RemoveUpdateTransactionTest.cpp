#include <gtest/gtest.h>
#include "../src/BankAccount.h"
#include "../src/Income.h"
#include "../src/Expense.h"

TEST(BankAccountTest, RemoveTransactionSuccess) {
    BankAccount account;
    account.addTransaction(std::make_shared<Income>(100.0, "2024-06-08", "Salary"));
    account.addTransaction(std::make_shared<Expense>(50.0, "2024-06-09", "Groceries"));
    account.addTransaction(std::make_shared<Income>(150.0, "2024-06-10", "Freelance"));

    double initialBalance = account.getBalance();
    account.removeTransaction(2); // Remove "Groceries" expense

    EXPECT_EQ(account.getBalance(), initialBalance + 50.0);
    EXPECT_EQ(account.searchTransactionsByDate("2024-06-09").size(), 0); // Ensure transaction is removed
}

TEST(BankAccountTest, RemoveTransactionOutOfRange) {
    BankAccount account;
    account.addTransaction(std::make_shared<Income>(100.0, "2024-06-08", "Salary"));
    account.addTransaction(std::make_shared<Expense>(50.0, "2024-06-09", "Groceries"));

    EXPECT_THROW(account.removeTransaction(3), std::out_of_range);
    EXPECT_THROW(account.removeTransaction(0), std::out_of_range);
}

TEST(BankAccountTest, UpdateTransactionSuccess) {
    BankAccount account;
    account.addTransaction(std::make_shared<Income>(100.0, "2024-06-08", "Salary"));
    account.addTransaction(std::make_shared<Expense>(50.0, "2024-06-09", "Groceries"));
    account.addTransaction(std::make_shared<Income>(150.0, "2024-06-10", "Freelance"));

    double initialBalance = account.getBalance();
    auto newTransaction = std::make_shared<Expense>(30.0, "2024-06-09", "Updated Groceries");

    account.updateTransaction(2, newTransaction); // Update the "Groceries" expense

    EXPECT_EQ(account.getBalance(), initialBalance + 20.0); // Difference is 50 - 30 = 20
    auto updatedTransaction = account.searchTransactionsByDate("2024-06-09")[0];
    EXPECT_EQ(updatedTransaction->getAmount(), 30.0);
    EXPECT_EQ(updatedTransaction->getDescription(), "Updated Groceries");
}

TEST(BankAccountTest, UpdateTransactionOutOfRange) {
    BankAccount account;
    account.addTransaction(std::make_shared<Income>(100.0, "2024-06-08", "Salary"));
    account.addTransaction(std::make_shared<Expense>(50.0, "2024-06-09", "Groceries"));

    auto newTransaction = std::make_shared<Expense>(30.0, "2024-06-09", "Updated Groceries");

    EXPECT_THROW(account.updateTransaction(3, newTransaction), std::out_of_range);
    EXPECT_THROW(account.updateTransaction(0, newTransaction), std::out_of_range);
}

TEST(BankAccountTest, UpdateTransactionWithNullAmount) {
    BankAccount account;
    account.addTransaction(std::make_shared<Income>(100.0, "2024-06-08", "Salary"));
    account.addTransaction(std::make_shared<Expense>(50.0, "2024-06-09", "Groceries"));

    auto nullTransaction = std::make_shared<Income>(0.0, "2024-06-09", "Null Transaction");

    EXPECT_THROW(account.updateTransaction(2, nullTransaction), BankAccount::NullTransactionException);
}
