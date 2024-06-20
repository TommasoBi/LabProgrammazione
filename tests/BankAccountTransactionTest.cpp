#include <gtest/gtest.h>
#include "../src/BankAccount.h"
#include "../src/Income.h"
#include "../src/Expense.h"

/* Questo test verifica che l'aggiunta di un reddito al conto aumenti correttamente il saldo.
Viene creato un nuovo conto, aggiunto un reddito di 100.0 con data
e descrizione specificate e quindi si verifica che il saldo sia aumentato a 100.0.*/
TEST(BankAccountTest, AddIncomeIncreasesBalance) {
BankAccount account;
account.addTransaction(std::make_shared<Income>(100.0, "2024-06-08", "Salary"));
EXPECT_EQ(account.getBalance(), 100.0);
}

/*Questo test verifica che l'aggiunta di una spesa al conto diminuisca correttamente il saldo.
Viene creato un nuovo conto, aggiunto un reddito di 100.0 e successivamente una spesa di 50.0
con data e descrizione specificate. Infine, si verifica che il saldo sia diminuito a 50.0.*/
TEST(BankAccountTest, AddExpenseDecreasesBalance) {
BankAccount account;
account.addTransaction(std::make_shared<Income>(100.0, "2024-06-08", "Salary"));
account.addTransaction(std::make_shared<Expense>(50.0, "2024-06-09", "Groceries"));
EXPECT_EQ(account.getBalance(), 50.0);
}
