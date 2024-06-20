#include <gtest/gtest.h>
#include "../src/BankAccount.h"

/* Questo test verifica che, quando viene creato un nuovo oggetto BankAccount,
il saldo iniziale sia zero.
Si aspetta quindi che il metodo getBalance() restituisca 0.0.*/
TEST(BankAccountTest, InitialBalanceIsZero) {
BankAccount account;
EXPECT_EQ(account.getBalance(), 0.0);
}
