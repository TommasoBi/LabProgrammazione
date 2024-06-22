#include <gtest/gtest.h>
#include "../src/BankAccount.h"
#include "../src/Income.h"
#include "../src/Expense.h"

TEST(BankAccountTest, SearchTransactionsByDate) {
BankAccount account;
account.addTransaction(std::make_shared<Income>(100.0, "2024-06-08", "Salary"));
account.addTransaction(std::make_shared<Expense>(50.0, "2024-06-09", "Groceries"));
account.addTransaction(std::make_shared<Income>(150.0, "2024-06-10", "Freelance"));

std::string dateToSearch = "2024-06-09";
auto results = account.searchTransactionsByDate(dateToSearch);

ASSERT_EQ(results.size(), 1);
EXPECT_EQ(results[0]->getType(), "Expense");
EXPECT_EQ(results[0]->getAmount(), 50.0);
EXPECT_EQ(results[0]->getDate(), dateToSearch);
EXPECT_EQ(results[0]->getDescription(), "Groceries");
}