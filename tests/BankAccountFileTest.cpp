#include <gtest/gtest.h>
#include "../src/BankAccount.h"
#include "../src/Income.h"
#include "../src/Expense.h"

/* Questi test verificano il corretto funzionamento delle funzioni loadTransactionsFromFile
e saveTransactionsToFile della classe BankAccount,
garantendo che le transazioni vengano caricate correttamente da un file esistente
e che il corretto errore venga gestito nel caso in cui il file non esista */
TEST(BankAccountTest, LoadAndSaveTransactionsFromFile) {
BankAccount account;
account.addTransaction(std::make_shared<Income>(100.0, "2024-06-08", "Salary"));
account.addTransaction(std::make_shared<Expense>(50.0, "2024-06-09", "Groceries"));
account.addTransaction(std::make_shared<Income>(150.0, "2024-06-10", "Freelance"));

std::string filename = "transactions.txt";
account.saveTransactionsToFile(filename);

BankAccount newAccount;
newAccount.loadTransactionsFromFile(filename);

// Verifica che il saldo del nuovo conto sia uguale al saldo originale
EXPECT_EQ(account.getBalance(), newAccount.getBalance());
}

TEST(BankAccountTest, LoadNonExistingFile) {
BankAccount account;
std::string filename = "non_existing_file.txt";
ASSERT_THROW(account.loadTransactionsFromFile(filename), std::runtime_error);
}
