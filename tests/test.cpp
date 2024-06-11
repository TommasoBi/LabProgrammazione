#include <gtest/gtest.h>
#include "../src/BankAccount.h"
#include "../src/Income.h"
#include "../src/Expense.h"
#include "../src/TransactionFileManager.h"

/* Questo test verifica che, quando viene creato un nuovo oggetto BankAccount,
il saldo iniziale sia zero.
Si aspetta quindi che il metodo getBalance() restituisca 0.0.*/
TEST(BankAccountTest, InitialBalanceIsZero) {
BankAccount account;
EXPECT_EQ(account.getBalance(), 0.0);
}
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

/*Questi test verificano il corretto funzionamento delle funzioni loadTransactionsFromFile
e saveTransactionsToFile della classe BankAccount,
 garantendo che le transazioni vengano caricate correttamente da un file esistente
 e che il corretto errore venga gestito nel caso in cui il file non esista*/

TEST(BankAccountTest, LoadAndSaveTransactionsFromFile) {
    // Creare un oggetto BankAccount con alcune transazioni
    BankAccount account;
    account.addTransaction(std::make_shared<Income>(100.0, "2024-06-08", "Salary"));
    account.addTransaction(std::make_shared<Expense>(50.0, "2024-06-09", "Groceries"));
    account.addTransaction(std::make_shared<Income>(150.0, "2024-06-10", "Freelance"));

    // Salvare le transazioni su un file temporaneo
    std::string filename = "transactions.txt";
    account.saveTransactionsToFile(filename);

    // Creare un nuovo oggetto BankAccount e caricare le transazioni dal file
    BankAccount newAccount;
    newAccount.loadTransactionsFromFile(filename);

    // Verificare che il saldo del nuovo conto sia uguale al saldo originale
    EXPECT_EQ(account.getBalance(), newAccount.getBalance());
}

TEST(BankAccountTest, LoadNonExistingFile) {
    // Creare un oggetto BankAccount e provare a caricare le transazioni da un file inesistente
    BankAccount account;
    std::string filename = "non_existing_file.txt";
    ASSERT_THROW(account.loadTransactionsFromFile(filename), std::runtime_error);
}
