#include <gtest/gtest.h>
#include "../src/BankAccount.h"
#include "../src/Income.h"
#include "../src/Expense.h"

TEST(BankAccountTest, InitialBalanceIsZero) {
BankAccount account;
EXPECT_EQ(account.getBalance(), 0.0);
}

TEST(BankAccountTest, AddIncomeIncreasesBalance) {
BankAccount account;
account.addTransaction(std::make_shared<Income>(100.0, "2024-06-08", "Salary"));
EXPECT_EQ(account.getBalance(), 100.0);
}

TEST(BankAccountTest, AddExpenseDecreasesBalance) {
BankAccount account;
account.addTransaction(std::make_shared<Income>(100.0, "2024-06-08", "Salary"));
account.addTransaction(std::make_shared<Expense>(50.0, "2024-06-09", "Groceries"));
EXPECT_EQ(account.getBalance(), 50.0);
}
