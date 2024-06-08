cmake_minimum_required(VERSION 3.28)
project(LabProg)

set(CMAKE_CXX_STANDARD 17)

add_executable(LabProg src/main.cpp
        src/Transaction.cpp
        src/Transaction.h
        src/Income.cpp
        src/Income.h
        src/Expense.cpp
        src/Expense.h
        src/BankAccount.cpp
        src/BankAccount.h
        src/TransactionFileManager.cpp
        src/TransactionFileManager.h)
