cmake_minimum_required(VERSION 3.10)
project(LabProg)

set(CMAKE_CXX_STANDARD 17)

# Include FetchContent module
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
        DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_MakeAvailable(googletest)

# Aggiungi i file sorgente del progetto
set(SOURCES
        src/main.cpp
        src/BankAccount.cpp
        src/Income.cpp
        src/Expense.cpp
        src/Transaction.cpp
)

# Aggiungi l'eseguibile principale
add_executable(LabProg ${SOURCES})

# Add the test executable
add_executable(LabProgtest
        tests/BankAccountBalanceTest.cpp
        tests/BankAccountTransactionTest.cpp
        tests/BankAccountFileTest.cpp
        src/BankAccount.cpp
        src/Income.cpp
        src/Expense.cpp
        src/Transaction.cpp
)

# Link GoogleTest to the test executable
target_link_libraries(LabProgtest gtest gtest_main)


