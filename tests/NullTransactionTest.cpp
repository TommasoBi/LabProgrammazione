#include <gtest/gtest.h>
#include "../src/BankAccount.h"
#include "../src/Income.h"

TEST(BankAccountTest, ThrowsOnNullTransaction) {
BankAccount account;
auto nullTransaction = std::make_shared<Income>(0.0, "2024-07-03", "Null Transaction");

EXPECT_THROW(account.addTransaction(nullTransaction), BankAccount::NullTransactionException);
}

TEST(BankAccountTest, DoesNotThrowOnValidTransaction) {
BankAccount account;
auto validTransaction = std::make_shared<Income>(100.0, "2024-07-03", "Valid Transaction");

EXPECT_NO_THROW(account.addTransaction(validTransaction));
EXPECT_EQ(account.getBalance(), 100.0);
}
