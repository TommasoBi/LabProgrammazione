cmake_minimum_required(VERSION 3.28)
project(LabProg)

set(CMAKE_CXX_STANDARD 17)

add_executable(LabProg main.cpp
        Transaction.cpp
        Transaction.h
        Income.cpp
        Income.h
        Expense.cpp
        Expense.h
        BankAccount.cpp
        BankAccount.h
        TransactionFileManager.cpp
        TransactionFileManager.h)
