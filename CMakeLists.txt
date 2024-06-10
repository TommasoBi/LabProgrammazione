cmake_minimum_required(VERSION 3.10)
project(LabProg)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(src)

# Add the source files
add_library(asprog_lib
        src/BankAccount.cpp
        src/Transaction.cpp
        src/Income.cpp
        src/Expense.cpp
        src/TransactionFileManager.cpp
)

# Add the main executable
add_executable(LabProg src/main.cpp)
target_link_libraries(LabProg asprog_lib)


# Add the test directory
add_subdirectory(tests/googletest)


