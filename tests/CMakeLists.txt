# tests/CMakeLists.txt

# Include GoogleTest
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Add the test executable
add_executable(runTests test_main.cpp)

target_link_libraries(runTests gtest gtest_main asprog_lib)

add_test(NAME runTests COMMAND runTests)




